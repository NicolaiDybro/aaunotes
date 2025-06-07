# Hvorfor et Hukommelseshierarki?

- **Problemet:** CPU'er er ekstremt hurtige, men hovedhukommelsen (RAM) er relativt langsom. Hvis CPU'en konstant skal vente på data fra RAM, spilder den meget tid.
- **Løsningen:** Byg et hierarki af hukommelser, hvor de hurtigste og dyreste hukommelser er tættere på CPU'en og har mindre kapacitet, mens de langsommere og billigere hukommelser er længere væk og har større kapacitet.
- **Grundprincipper:**
    - **Lokalitet (Locality):** Fænomenet at programmer ofte genbruger data og instruktioner, de har tilgået for nylig, eller data og instruktioner, der ligger tæt på dem, de lige har tilgået. Dette er grundlaget for hierarkiet.
        - **Tidslig Lokalitet (Temporal Locality):** Hvis et dataelement er tilgået nu, er der stor sandsynlighed for, at det vil blive tilgået igen snart. (F.eks. løkkevariabler, ofte kaldte funktioner).
        - **Rumlig Lokalitet (Spatial Locality):** Hvis et dataelement er tilgået nu, er der stor sandsynlighed for, at dataelementer, der ligger tæt på i hukommelsen, vil blive tilgået snart. (F.eks. elementer i en array, instruktioner i sekventiel kode).
- **Formålet med hierarkiet:** At give illusionen af en stor, hurtig og billig hukommelse ved at flytte hyppigt anvendte data til de hurtigere niveauer.

---

# Typer af Hukommelse i Hierarkiet

Fra hurtigst/mindst til langsomst/størst/billigst:

- **Registrer (Registers):** Indbygget i CPU'en. Hurtigst, mindst, dyrest. Data her er øjeblikkeligt tilgængelige. Compileren forsøger at placere ofte brugte variabler her.
- **CPU-Caches (L1, L2, L3):** Små, hurtige hukommelser mellem CPU'en og hovedhukommelsen.
    - **L1 Cache:** Hurtigst, mindst (typisk KB-størrelse), tættest på CPU-kernen. Ofte opdelt i Data Cache (L1d) og Instruction Cache (L1i).
    - **L2 Cache:** Større end L1 (typisk MB-størrelse), lidt langsommere. Ofte delt mellem kerner.
    - **L3 Cache:** Størst af CPU-cachen (typisk mange MB), langsommere end L2. Ofte delt af alle kerner på en processor.
    - **Cache-linjer (Cache Lines):** Caches flytter data i faste blokke (typisk 64 bytes) ad gangen, ikke individuelle bytes. Dette udnytter rumlig lokalitet.
- **Hovedhukommelse (RAM):** Primær arbejdhukommelse. Større (GB-størrelse), men markant langsommere end caches.
- **Disk (SSD/HDD):** Sekundær lagring. Langsomst, størst (TB-størrelse), billigst. Bruges til vedvarende lagring og som udvidelse af RAM via virtuel hukommelse.

---

# Cache Principper og Terminologi

- **Cache Hit:** Data, CPU'en har brug for, findes i cachen. Meget hurtig adgang.
- **Cache Miss:** Data, CPU'en har brug for, findes _ikke_ i cachen. Processoren skal hente det fra et lavere (langsommere) niveau i hierarkiet. Dette er dyrt i tid.
- **Typer af Cache Misses:**
    - **Cold Miss (Compulsory Miss):** Første gang et dataelement tilgås, kan det naturligvis ikke være i cachen. Uundgåelig.
    - **Conflict Miss:** Flere dataelementer, der tilgås, mappes til den samme placering i cachen (f.eks. på grund af den måde data er organiseret i hukommelsen eller cachen er designet). Cachen er stor nok, men mappereglerne forhindrer samtidig lagring.
    - **Capacity Miss:** Cachen er simpelthen for lille til at indeholde alle de data, programmet arbejder på. Ældre data skal udskiftes for at give plads til nye.
- **Cache Organisation:**
    - **Direkte Mappet Cache:** Hver hukommelsesadresse har kun _én_ mulig placering i cachen. Simpel at implementere, men høj risiko for conflict misses.
    - **Fuldt Associativ Cache:** Et hukommelsesdata kan placeres _hvor som helst_ i cachen. Meget fleksibel, men dyr at implementere og langsom at søge i.
    - **Sæt-Associativ Cache:** En kombination. Hver hukommelsesadresse kan placeres i et _bestemt sæt_ af cache-linjer, men inden for det sæt kan den placeres frit. (f.eks. 2-vejs sæt-associativ: 2 mulige placeringer). Dette er den mest almindelige type i moderne CPU'er.

---

# Virtuel Hukommelse (Virtual Memory - VM)

- **Idé:** Et abstraktionslag over den fysiske hukommelse. Hvert program får sit eget private, isolerede "virtuelle adresserum".
- **Formål:**
    - **Isolation og Beskyttelse:** Et program kan ikke direkte tilgå et andet programs hukommelse. Forhindrer fejl i ét program i at ødelægge andre.
    - **Forenkling af Hukommelsesadministration:** Programmer ser en kontiguøs hukommelsesblok, selvom de fysiske adresser er fragmenterede.
    - **Effektiv Ressourceudnyttelse:** Lader flere processer dele fysisk hukommelse.
    - **Caching fra Disk til RAM:** Fungerer som en cache mellem den langsomme disk og den hurtigere RAM. Når en virtuel side efterspørges, men ikke er i RAM (en "page fault"), hentes den fra disken.
- **Sideinddeling (Paging):** Virtuel hukommelse er opdelt i faste størrelsesblokke kaldet "sider" (pages) (typisk 4KB). Fysisk hukommelse er opdelt i "siderammer" (page frames) af samme størrelse.
- **Adresseoversættelse:** CPU'en oversætter konstant virtuelle adresser til fysiske adresser ved hjælp af en "page table" (sidetabel), der typisk gemmes i RAM. For at fremskynde denne oversættelse bruges en hardware-cache kaldet **TLB (Translation Lookaside Buffer)**.
- **TLB (Translation Lookaside Buffer):** En lille, hurtig cache af de senest anvendte virtuelle-til-fysiske adresseoversættelser. Et TLB-hit betyder en hurtig oversættelse; et TLB-miss kræver en opslag i den langsommere page table i RAM.

---

# At Skrive Cache-venlig Kode

For at opnå god performance er det afgørende at designe din kode, så den udnytter lokalitet og minimerer cache misses.

- **Loop Order (Løkke-rækkefølge):** Dette er en af de største faktorer.
    - **Eksempel: Matrix-summering (som i slides):**
        - Hvis du summer række for række (`for i ... for j ... sum += a[i][j]`), vil elementerne `a[i][j]` og `a[i][j+1]` ligge tæt på hinanden i hukommelsen (rumlig lokalitet), hvilket giver mange cache hits.
        - Hvis du summer kolonne for kolonne (`for j ... for i ... sum += a[i][j]`), vil `a[i][j]` og `a[i+1][j]` ligge langt fra hinanden i hukommelsen for store matricer. Dette resulterer i mange cache misses, da hver adgang henter en ny cache-linje, der ikke genbruges effektivt.
    - **Regel:** Arranger dine løkker, så de tilgår data i den rækkefølge, de er lagret i hukommelsen (række-major for C/C++ arrays).
- **Blocking (Cache Blocking / Tiling):**
    - **Formål:** Optimerer tilgangen til store datastrukturer (f.eks. matrixmultiplikation), der er for store til at passe i cachen.
    - **Idé:** Del de store operationer op i mindre "blokke" eller "fliser", der passer ind i cachen. Udfør alle operationer på en blok, før du går videre til den næste.
    - **Eksempel: Matrixmultiplikation (`C = A * B`):** I stedet for at beregne hele `C[i][j]` ved at iterere over hele `k` for hver `i,j`, opdel matricerne i mindre `B x B` blokke. Beregn resultatet for en del-matrix af `C` ved at iterere over korresponderende blokke af `A` og `B`. Dette sikrer, at de nødvendige dele af `A`, `B`, og `C` passer i cachen, hvilket maksimerer genbrug af data i cachen.
- **Minimer genberegninger (Re-computation):** Nogle gange er det billigere at genberegne en værdi end at gemme den i hukommelsen og hente den igen, hvis hukommelsesadgangen er dyr og genberegningen er simpel.
- **Data Layout:** Design dine datastrukturer, så relaterede data er lagret tæt sammen i hukommelsen for at forbedre rumlig lokalite