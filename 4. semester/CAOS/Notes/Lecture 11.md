# Multi-Process vs. Multi-threading

- **Traditionel Multi-programmering (Multi-Process):**
    
    - **Koncept:** Et antal uafhængige processer skiftes til at afvikle på CPU'en. OS'et foretager kontekstskift mellem dem.
    - **Isolation:** Hver proces har sit eget, separate, isolerede virtuelle adresserum (kode, data, heap, stack, registre). En proces's fejl påvirker sjældent andre processer.
    - **Kommunikation:** Kommunikation mellem processer (Inter-Process Communication - IPC) er relativt kompliceret (f.eks. pipes, shared memory, message queues).
    - **Fordele:** Robusthed, sikkerhed.
    - **Ulemper:** Høje omkostninger ved kontekstskift, IPC er langsom.
- **Multi-threading (Moderne Parallelitet):**
    
    - **Koncept:** En enkelt proces kan indeholde adskillige "tråde" (execution threads), der alle kører inden for det samme virtuelle adresserum.
    - **Delte Ressourcer:** Trådene i en proces _deler_ det meste af processens ressourcer: kode, data, heap, åbne filer, osv.
    - **Private Ressourcer (pr. tråd):** Hver tråd har sin egen private stack (til lokale variabler og funktionskald) og sit eget sæt CPU-registre.
    - **Fordele:**
        - **Bedre udnyttelse af flerkernet CPU'er:** Kan opnå ægte parallelisme.
        - **Reduceret kontekstskift-overhead:** Tråde er "lettere" end processer; kontekstskift mellem tråde i samme proces er hurtigere, da adresserummet ikke behøver at blive skiftet (f.eks. ingen TLB flush).
        - **Nemmere resourcedeling:** Tråde deler data direkte, hvilket forenkler kommunikation og reducerer kopiering.
        - **Forbedret respons:** Kan udføre I/O-operationer i baggrunden, mens brugerfladen forbliver responsiv.
    - **Ulemper:**
        - **Kompleksitet:** Sværere at programmere korrekt på grund af delte ressourcer og behov for synkronisering.
        - **Fejl er farlige:** En fejl i én tråd kan korrumpere hele processens delte data og potentielt crashe hele applikationen.
        - **Race Conditions og Deadlocks:** Nye typer af fejl, der opstår på grund af konkurrerende adgang til delte ressourcer.

---

# Hvorfor Multi-threading?

- **Flerkerne-processorer:** De fleste moderne CPU'er har flere kerner. For at udnytte disse kerner effektivt og opnå ægte parallelisme, skal programmer skrive trådet.
- **Forbedret respons for interaktive applikationer:** Kan f.eks. udføre tunge beregninger i en baggrundstråd, mens brugergrænsefladen forbliver responsiv i en anden tråd.
- **Reduceret latenstid:** For visse opgaver kan opdeling af arbejdet i tråde reducere den samlede tid, det tager at fuldføre en opgave.
- **Modellering af virkeligheden:** Mange problemer (f.eks. servere, simuleringer) har iboende parallelisme, som kan modelleres med tråde.

---

# Grundlæggende Trådskabelse (Posix Threads - Pthreads)

- **`pthread_create()`:** Opretter en ny tråd. Tager typisk en pointer til en funktion, der skal udføres af den nye tråd, og et argument til denne funktion.
- **`pthread_join()`:** Får den kaldende tråd til at vente, indtil en specificeret tråd er færdig med at udføre. Vigtigt for at sikre, at ressourcer frigives korrekt, og at hovedtråden kan hente resultater fra børnetråde.
- **Tråde er "peers":** Når en tråd er oprettet, har den ikke et "parent/child" forhold som processer i klassisk forstand; alle tråde i en proces er lige.

---

# Udfordringer med Concurrency: Race Conditions

En **race condition** opstår, når resultatet af et program afhænger af den relative udførelsesrækkefølge af handlinger i flere tråde, og denne rækkefølge ikke er deterministisk (forudsigelig).

- **Definition:** Flere tråde tilgår et delt ressource (f.eks. en global variabel) samtidigt, og mindst én af disse adgange er en skrivning. Den endelige værdi af ressourcen afhænger af, hvilken tråd der tilgår den sidst.
- **Eksempel: Inkremetering af en delt tæller:** `counter++` ser ud som én operation, men er typisk:
    
    1. Læs `counter` fra hukommelsen til et register.
    2. Inkremeter registeret.
    3. Skriv registerværdien tilbage til `counter` i hukommelsen.
    
    - Hvis to tråde udfører dette samtidigt, kan de læse den samme gamle værdi, inkremetere den, og begge skrive deres (forkerte) resultat tilbage, hvilket fører til tabte opdateringer.
- **Løsning: Synkronisering (Kritiske Sektioner):** En kritisk sektion er et kodeområde, der tilgår en delt ressource, og som skal udføres atomisk (uden afbrydelser fra andre tråde, der tilgår samme ressource). Kun én tråd må være i en kritisk sektion ad gangen.
    - **Låse (Locks / Mutexes):** Den mest almindelige mekanisme til at beskytte kritiske sektioner.
        - **`pthread_mutex_init()`:** Initialiserer en mutex (Mutual Exclusion object).
        - **`pthread_mutex_lock()`:** Forsøger at opnå låsen. Hvis låsen er optaget, blokerer tråden, indtil den kan opnå låsen.
        - **`pthread_mutex_unlock()`:** Frigiver låsen.
        - **Regel:** Hver delt ressource, der kan føre til en race condition, skal beskyttes af sin egen mutex. Alle adgange til den ressource skal omsluttes af `lock()` og `unlock()`.

---

# Granularitet af Låse

Valget af, hvor bredt (groft) eller snævert (fint) låse skal anvendes, er vigtigt for performance.

- **Grovkornet låsning (Coarse-grained locking):**
    - **Idé:** Brug én enkelt lås til at beskytte en stor del af et datastruktur eller en hel applikation.
    - **Fordele:** Enkel at implementere, mindre risiko for race conditions.
    - **Ulemper:** Begrænser parallelitet markant. Hvis én tråd holder låsen, kan ingen andre tråde, der bruger den lås, køre parallelt, selvom de arbejder på uafhængige dele af data. Kan føre til flaskehalse og dårlig skalering på flerkernede systemer.
- **Finkornet låsning (Fine-grained locking):**
    - **Idé:** Brug mange små låse, hvor hver lås beskytter en meget lille del af en datastruktur.
    - **Fordele:** Maksimal parallelitet, da flere tråde kan arbejde på forskellige (ubeskadede) dele af datastrukturen samtidigt. Skalerer bedre med stigende antal kerner.
    - **Ulemper:** Meget sværere at implementere korrekt. Øget risiko for deadlocks (se næste punkt) og mere overhead fra låseadministration. Svært at sikre, at alle adgange til en delt ressource er korrekt beskyttet.
- **Eksempel: Concurrent Hash-tabel:**
    - En dårlig, grovkornet løsning ville være at have én lås for hele hash-tabellen. Alle inserts, lookups, deletes ville være sekventielle.
    - En god, finkornet løsning ville være at have en lås per "bucket" (den del af tabellen, hvor elementer med samme hash-værdi lander). Dette tillader parallelle operationer på forskellige buckets.

---

# Deadlocks: Når alle venter på alle

En **deadlock** opstår, når to eller flere tråde er blokeret permanent, hver især ventende på en ressource, som holdes af en anden blokeret tråd. Ingen af dem kan fortsætte, og hele systemet kan gå i stå.

- **Betingelser for Deadlock (Coffman-betingelserne):** Alle fire betingelser skal være opfyldt for, at en deadlock kan opstå:
    1. **Gensidig Udelukkelse (Mutual Exclusion):** Ressourcerne skal være ikke-delebare; kun én tråd kan holde en ressource ad gangen (f.eks. en lås).
    2. **Hold og Vent (Hold and Wait):** En tråd holder mindst én ressource og venter på at erhverve yderligere ressourcer, som holdes af andre tråde.
    3. **Ingen Preemption (No Preemption):** Ressourcer kan ikke fratages en tråd, der holder dem. De skal frigives frivilligt.
    4. **Cirkulær Ventetid (Circular Wait):** Der eksisterer en cyklisk kæde af to eller flere tråde, hvor hver tråd venter på en ressource, som holdes af den næste tråd i kæden.
- **Eksempel på Deadlock:**
    - Tråd 1 låser Lås A, derefter forsøger at låse Lås B.
    - Tråd 2 låser Lås B, derefter forsøger at låse Lås A.
    - Hvis dette sker samtidigt, kan Tråd 1 holde Lås A og vente på Lås B, mens Tråd 2 holder Lås B og venter på Lås A. Begge er blokeret permanent.
- **Løsninger (for at forebygge):**
    - **Forhindre Cirkulær Ventetid:** Den mest praktiske tilgang. Etabler en global, fast rækkefølge for erhvervelse af låse. Hvis tråde altid erhverver låse i den samme faste rækkefølge, kan en cirkulær ventetid ikke opstå.
    - **Andre strategier (mindre praktiske i almindelig programmering):**
        - **Erhverv alle låse på én gang:** En tråd erhverver alle de låse, den har brug for, atomisk. Hvis den ikke kan få dem alle, frigiver den alle og prøver igen. (Forhindrer "Hold and Wait").
        - **Tillad Preemption:** OS'et kan fratage ressourcer fra en blokeret tråd (svært at implementere generelt for låse).