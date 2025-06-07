# Operativsystemets Rolle

- **Abstraktion og Virtualisering:** OS'et skjuler kompleksiteten af den underliggende hardware og skaber en illusion af en "bedre" eller mere brugervenlig maskine. Det virtualiserer ressourcer:
    - **CPU:** Via processer og multi-programmering.
    - **Primær Hukommelse:** Via virtuel hukommelse.
    - **Sekundær Hukommelse/Diske:** Via filer og filsystemer.
- **Ressourcestyring:** OS'et er ansvarligt for at styre og dele computerens ressourcer (CPU, hukommelse, I/O-enheder) sikkert, retfærdigt (eller prioriteret) mellem forskellige programmer og brugere.
- **Brugervenlighed:** Gør det nemt at afvikle programmer og tilbyder en ensartet måde at tilgå ydre enheder.
- **Sikkerhed og Korrekthed:** Sikrer, at systemet kører korrekt og stabilt, og at programmer ikke forstyrrer hinanden.

---

# Kernen af OS'et: Central Funktionalitet

Et operativsystem består af mange komponenter, der arbejder sammen:

- **Process Manager:** Styrer oprettelse, afvikling, suspension, genoptagelse og terminering af processer. Ansvarlig for ressourceallokering til processer.
- **Thread Manager:** Håndterer tråde (threads) inden for en proces. Tråde er lettere end processer og deler samme hukommelsesrum.
- **Memory Manager:** Styrer primær hukommelse (RAM), allokerer plads til programmer og håndterer virtuel hukommelse.
- **File System Manager:** Administrerer filer og mapper på sekundær lagring.
- **I/O Manager:** Håndterer kommunikation med input/output-enheder (tastatur, mus, skærm, disk, netværk).
- **Communication Manager:** Håndterer inter-process kommunikation (IPC) og netværkskommunikation.
- **Scheduler (Planlægger):** Bestemmer, hvilken proces eller tråd der skal køre på CPU'en, og hvor længe.
- **Supervisor (Hardware Abstraction Layer):** Det laveste lag i OS'et, der interagerer direkte med hardware. Håndterer interrupts og exceptions.

---

# Undtagelser (Exceptions): Hvordan OS'et Reagerer på Begivenheder

En undtagelse er en form for kontrolflow-ændring, der opstår som respons på en begivenhed i systemet. Disse begivenheder kan være både software- og hardware-relaterede. Når en undtagelse opstår, afbryder CPU'en det normale programflow og overfører kontrollen til operativsystemets "exception handler" (undtagelseshåndterer).

- **Typer af Undtagelser:**
    - **Asynkrone Undtagelser (Interrupts):** Kommer fra ydre enheder (hardware) på uforudsigelige tidspunkter, uafhængigt af det program, der kører.
        - **Eksempler:** Disk-I/O færdig, netværkspakke modtaget, timer-udløb.
        - **Formål:** Giver OS'et besked om, at en hændelse er indtruffet, og ofte bruges til at implementere tidsdeling (preemption) af CPU'en.
    - **Synkrone Undtagelser (Traps/Faults/Aborts):** Direkte resultat af at udføre en instruktion. De er synkrone med programmet.
        - **Typer af Synkrone Undtagelser:**
            - **Trap:** Bevidst instruktion, der kalder OS'et (f.eks. et systemkald). Kontrol gives tilbage til _næste_ instruktion efter trap'en.
                - **Eksempler:** Læse fra fil, allokere hukommelse, oprette en ny proces. Programmer bruger systemkald til at anmode OS'et om tjenester.
            - **Fault:** En fejl, der _potentielt_ kan rettes. OS'et forsøger at rette fejlen og genstarter instruktionen, der forårsagede den.
                - **Eksempler:** Page Fault (data er ikke i RAM, men på disk), beskyttelsesfejl (forsøg på at tilgå ulovlig hukommelse, men kan skyldes at data ikke er mappet endnu).
            - **Abort:** En fatal, uigendrivelig fejl, der normalt får programmet til at afslutte.
                - **Eksempler:** Division med nul, ugyldig instruktion, hardwarefejl.

---

# Processer: Program i Udvikling

En proces er en instans af et program, der er under udførelse. Det er OS'ets abstraktion af en kørende program.

- **Vigtige Egenskaber ved en Proces:**
    - **Uafhængighed:** Hver proces har sit eget isolerede virtuelle adresserum, hvilket betyder, at den ikke direkte kan påvirke andre processers hukommelse. Dette giver sikkerhed og stabilitet.
    - **Private Ressourcer:** Hver proces har sin egen private kopi af CPU-registre, programtæller (PC), stack, og et virtuelt adresserum.
    - **OS-Ressourcer:** OS'et allokerer ressourcer (fil-håndtag, netværksforbindelser) til processen.
- **Proces Kontekst (Process Context):** Den fulde tilstand af en proces, som CPU'en og OS'et har brug for for at genoptage udførelsen af processen. Dette inkluderer:
    - Programtæller (PC).
    - Hele indholdet af CPU-registre.
    - Bruger-stack.
    - Status for virtuelt adresserum (f.eks. page table).
    - OS-kernestack (bruges af OS-koden for denne proces).
    - Information om åbne filer, pending signals osv.
- **Kontekstskift (Context Switch):** Den proces, hvor OS'et gemmer konteksten af den nuværende proces og genindlæser konteksten af en anden proces.
    - **Hvornår sker det:** Når OS'et beslutter at skifte CPU'en fra én proces til en anden (f.eks. pga. tidsdeling, I/O-ventetid, eller at en proces afslutter).
    - **Omkostning:** Kontekstskift er en dyr operation, da det involverer at gemme og indlæse mange registerværdier og manipulere med side-tabeller for virtuel hukommelse. OS'et forsøger at minimere antallet af kontekstskift.

---

# Proces Tilstande (States)

En proces gennemgår forskellige tilstande i løbet af sin levetid:

- **New (Ny):** Processen er lige blevet oprettet.
- **Ready (Klar):** Processen er klar til at køre og venter på at få tildelt CPU-tid.
- **Running (Kørende):** Processen udfører instruktioner på CPU'en.
- **Waiting/Blocked (Ventende/Blokeret):** Processen venter på en begivenhed (f.eks. I/O-afslutning, en ressource bliver ledig, et signal fra en anden proces). Den kan ikke køre, før begivenheden indtræffer.
- **Terminated (Afsluttet):** Processen er færdig med at udføre eller er blevet afsluttet.

---

# Multi-Tasking og Scheduling (Planlægning)

Multi-tasking handler om at give illusionen af, at flere programmer kører samtidigt. Dette opnås ved at OS'et hurtigt skifter mellem processer.

- **Scheduler (Planlæggeren):** Den del af OS'et, der bestemmer, hvilken proces der skal køre hvornår, og hvor længe. Målet er at maksimere CPU-udnyttelse og minimere ventetider.
- **Typer af Scheduling:**
    - **Preemptive Scheduling:** OS'et kan afbryde (preempt) en kørende proces og give CPU'en til en anden, selvom den første proces ikke er færdig eller frivilligt har opgivet CPU'en. Dette er standard for moderne OS'er og nødvendigt for tidsdeling og fairness.
    - **Non-Preemptive Scheduling (Cooperative Scheduling):** En proces kører, indtil den frivilligt opgiver CPU'en (f.eks. ved at afslutte, eller ved at udføre et I/O-kald, der blokerer den). Giver ringere respons og fairness.
- **Scheduleringsalgoritmer:**
    - **First-Come, First-Served (FCFS):** Processer kører i den rækkefølge, de ankommer. Simpel, men kan have lang gennemsnitlig ventetid (især hvis et langt job ankommer først).
    - **Shortest Job First (SJF):** Processen med den korteste forventede køretid får CPU'en først. Optimal for gennemsnitlig ventetid, men kræver kendskab til fremtidig køretid, hvilket sjældent er muligt.
    - **Round Robin (RR):** Hver proces tildeles et fast "tidskvantum" (time slice). Når kvantummet udløber, skiftes der til næste proces i en cirkulær kø. God til interaktive systemer, da det giver hurtig respons, men kan have høj kontekstskift-overhead hvis tidskvantum er for lille.
    - **Prioritetsbaseret Scheduling:** Processer tildeles en prioritet. Højere prioritet jobs kører før lavere prioritet jobs.
        - **Statisk Prioritet:** Prioriteten er fastsat ved start. Kan føre til "starvation", hvor lavprioritetsjob aldrig kører.
        - **Dynamisk Prioritet:** Prioriteten justeres undervejs af OS'et (f.eks. interaktive jobs får højere prioritet; jobs, der venter længe, får deres prioritet øget for at undgå starvation).
    - **Multilevel Feedback Queue:** En kombination af prioritets- og Round Robin-scheduling. Processer starter i en høj-prioritetskø med små tidskvantum. Hvis de ikke bliver færdige, flyttes de ned til en lavere prioriteret kø med større tidskvantum. Giver god respons til korte interaktive jobs og god gennemløb for lange jobs.