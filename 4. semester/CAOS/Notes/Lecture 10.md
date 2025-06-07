# Virtuel Hukommelse (VM): Kernen i Abstraktionen

Virtuel hukommelse er et abstraktionslag leveret af operativsystemet (OS) og CPU'en. Den giver hver proces illusionen af at have en stor, privat, ubrudt hukommelse, selvom den fysiske hukommelse er delt og fragmenteret.

- **Virtualisering af hukommelsen:** VM fungerer som en cache mellem den _fysiske_ hukommelse (RAM) og den _sekundære_ hukommelse (harddisk eller SSD).
- **Fordele ved Virtuel Hukommelse:**
    - **Simplicitet for programmøren:** Programmører behøver ikke bekymre sig om, hvor data fysisk er lagret i RAM, eller om der er nok fysisk hukommelse. De arbejder med virtuelle adresser.
    - **Sikkerhed og Beskyttelse:** Hver proces har sit eget adresserum, som er isoleret fra andre. En proces kan ikke direkte tilgå en anden proces's hukommelse (uden eksplicit deling via OS'et). Dette forhindrer buggy eller ondsindet kode i at korrumpere andre programmer eller OS'et.
    - **Effektiv Ressourceudnyttelse:**
        - **Hukommelseshåndtering:** OS'et kan allokere og frigøre hukommelse dynamisk.
        - **Deling af kode og data:** Flere processer kan dele den samme fysiske kopi af kode (f.eks. biblioteker) eller data ved at mappe den samme fysiske side til forskellige virtuelle adresser.
        - **Lazy Loading:** Programkode og data indlæses kun fra disk, når det faktisk er nødvendigt. Dette reducerer programstarttid og hukommelsesforbrug.
    - **Fleksibilitet (Sparse Adresserum):** Et program kan have et stort virtuelt adresserum med "huller", hvor der ikke er allokeret fysisk hukommelse. Dette er nyttigt for f.eks. dynamisk allokeret hukommelse, der kun vokser, når der er behov for det.

---

# Sideinddeling (Paging): Grundlaget for VM

Virtuel hukommelse er organiseret i faste størrelsesblokke kaldet **sider (pages)**. Den fysiske hukommelse er opdelt i tilsvarende blokke kaldet **siderammer (page frames)**.

- **Virtuelle adresser:** De adresser, som programmer bruger. Består af et **virtuelt sidenummer (VPN)** og en **offset (page offset)** inden for siden.
- **Fysiske adresser:** De faktiske adresser i RAM. Består af et **fysisk rammenummer (PPN)** og den samme **offset (page offset)**.
- **Adresseoversættelse:** Kernen i virtuel hukommelse. CPU'en oversætter konstant virtuelle adresser til fysiske adresser. Denne proces styres af hardware (Memory Management Unit - MMU) og OS'et.
    - **Page Table (Sidetabel):** En datastruktur (typisk en array eller et træ) der gemmes i RAM, og som indeholder oversættelser fra virtuelle sidenumre til fysiske rammenumre. Hver proces har sin egen page table.
    - **Page Table Entry (PTE):** Hver indgang i page table indeholder:
        - **Valid Bit:** Angiver om siden er gyldig (dvs. mapt til en fysisk ramme). Hvis ikke, betyder det enten en ulovlig adresse eller en "page fault".
        - **Page Frame Number (PFN):** Den fysiske ramme, som den virtuelle side er mappet til.
        - **Permitteringsbits:** Styrer adgangsrettigheder (læs, skriv, udfør). Bruges til hukommelsesbeskyttelse.
        - **Dirty Bit:** Angiver om siden er blevet modificeret, siden den blev indlæst fra disk. Vigtigt for at vide, om den skal skrives tilbage til disk, når den smides ud af RAM.
        - **Accessed Bit:** Angiver om siden er blevet tilgået for nylig. Bruges af erstatningsalgoritmer (f.eks. LRU).

---

# TLB (Translation Lookaside Buffer): Hastighed i Adresseoversættelsen

Adresseoversættelse via page table i RAM er langsomt, da det kræver mindst én (ofte flere) hukommelsesadgange for hver CPU-hukommelsesadgang. For at fremskynde dette bruges en **Translation Lookaside Buffer (TLB)**.

- **TLB er en cache:** TLB'en er en lille, hurtig hardware-cache, der gemmer de senest brugte virtuelle-til-fysiske adresseoversættelser (PTE'er).
- **TLB Hit:** Hvis en virtuel adresseoversættelse findes i TLB'en, kan den fysiske adresse findes meget hurtigt.
- **TLB Miss:** Hvis oversættelsen ikke er i TLB'en, skal CPU'en udføre et langsommere opslag i page table i RAM. Efter opslaget opdateres TLB'en med den nye oversættelse.
- **TLB Flush:** Når OS'et skifter kontekst til en ny proces, skal TLB'en tømmes (flushes) for at undgå, at den nye proces bruger forældede oversættelser fra den tidligere proces. Dette bidrager til omkostningerne ved et kontekstskift.

---

# Page Faults: Når data ikke er i RAM

En **page fault** er en type "fault" undtagelse, der opstår, når CPU'en forsøger at tilgå en virtuel adresse, men den tilsvarende virtuelle side ikke er til stede i fysisk hukommelse (RAM).

- **Processen ved en Page Fault:**
    1. CPU'en forsøger at tilgå en virtuel adresse.
    2. MMU'en tjekker TLB'en og derefter page table.
    3. Valid-bit'en i PTE'en er ikke sat, hvilket indikerer, at siden ikke er i RAM.
    4. CPU'en genererer en page fault undtagelse.
    5. OS'ets page fault handler overtager:
        - Den finder den ønskede side på disken (eller initialiserer den, hvis den er en del af programmets bss-sektion f.eks.).
        - Den vælger en ledig sideramme i RAM (eller vælger en side at "smide ud" (evict) ved hjælp af en erstatningsalgoritme som LRU, FIFO, etc., og skriver den eventuelt tilbage til disk, hvis den er "dirty").
        - Den indlæser den ønskede side fra disk til den valgte sideramme i RAM.
        - Den opdaterer page table entry (PTE) for den virtuelle side, så den nu peger på den nye fysiske ramme og sætter valid-bit'en.
        - Den opdaterer TLB'en (eller flusher den).
        - Den returnerer kontrollen til det program, der forårsagede page fault'en, og genudfører den instruktion, der udløste fejlen.
- **Vigtigheden:** Page faults er grundlæggende for VM's evne til at cache data fra disk til RAM. De er dyre, men nødvendige.

---

# Dynamisk Hukommelsesallokering (`malloc` og `mmap`)

- **`malloc` (Memory Allocate):** Standardbiblioteksfunktion til dynamisk allokering af hukommelse i C/C++.
    - `malloc` anmoder typisk OS'et om et stort blok af virtuel hukommelse fra OS'et (via systemkald som `sbrk` eller `mmap`).
    - Derefter administrerer `malloc`-biblioteket denne store blok internt og giver små bidder til programmet efter behov. Det holder styr på frie og optagne blokke.
    - Når `free()` kaldes, frigives hukommelsen tilbage til `malloc`-biblioteket, som så kan genbruge den eller eventuelt frigive den tilbage til OS'et.
- **`mmap` (Memory Map):** Et systemkald, der direkte interagerer med OS'et for at mappe filer eller anonym hukommelse ind i en proces's virtuelle adresserum.
    - **Fil-mapping:** Bruges til at mappe en fil direkte ind i processens hukommelsesrum. Adgang til filen sker derefter via pointere i hukommelsen, og ændringer kan skrives tilbage til filen. Effektiv til store filer.
    - **Anonym mapping:** Bruges til at allokere store blokke af virtuel hukommelse, der ikke er associeret med en fil (f.eks. heap'en til `malloc`).
    - Giver mere finkornet kontrol over hukommelsesmapping end `malloc`.