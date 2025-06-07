# Synkronisering udover Mutexes

Mutexes (låse) er gode til at beskytte delte ressourcer mod race conditions. Men de er ikke nok, når tråde skal vente på, at specifikke _betingelser_ opfyldes, før de kan fortsætte. Her kommer betingelsesvariabler (condition variables) og semaforer ind.

---

# Betingelsesvariabler (Condition Variables)

En betingelsesvariabel bruges til at koordinere tråde baseret på en _betingelse_. En tråd, der venter på en betingelse, kan midlertidigt opgive CPU'en og frigive en mutex, indtil en anden tråd signalerer, at betingelsen er opfyldt.

- **Hvornår bruges de:** Når en tråd skal udføre en handling, men kun kan gøre det, hvis en bestemt betingelse er sand (f.eks. "køen er ikke tom", "buffelen er ikke fuld").
- **Grundlæggende koncept:** En betingelsesvariabel er altid forbundet med en mutex. Mutex'en bruges til at beskytte den delte data, som betingelsen afhænger af.
- **Pthreads-funktioner:**
    - `pthread_cond_init()`: Initialiserer en betingelsesvariabel.
    - `pthread_cond_wait(cond, mutex)`:
        
        1. Atomisk frigiver `mutex`'en.
        2. Blokerer tråden (lægger den i en "ventekø" for `cond`).
        3. Når tråden "vækkes" (signaleres), genoptager den udførelsen og genopnår automatisk `mutex`'en, før den fortsætter.
        
        - **Vigtigt:** En tråd, der kalder `wait()`, skal _altid_ gøre det inden for en løkke, der tjekker betingelsen (f.eks. `while (!betingelse) pthread_cond_wait(...)`). Dette håndterer "spurious wakeups" (ubegrundede vækkelser), hvor tråden vækkes, men betingelsen stadig ikke er sand.
    - `pthread_cond_signal(cond)`: Vækker _én_ af de tråde, der venter på `cond`. Hvis ingen venter, sker der intet.
    - `pthread_cond_broadcast(cond)`: Vækker _alle_ tråde, der venter på `cond`. Bruges, når mere end én tråd potentielt kan fortsætte.
- **Typisk brugsmønster:**
    - **Tråd A (producent):**
        1. Lås mutex.
        2. Modificer delt data (f.eks. tilføj et element til en buffer).
        3. Opdater betingelsen (f.eks. `buffer_count++`).
        4. Signalér (`pthread_cond_signal` eller `pthread_cond_broadcast`) at betingelsen kan være opfyldt.
        5. Frigør mutex.
    - **Tråd B (forbruger):**
        1. Lås mutex.
        2. **Mens (ikke betingelse)** (f.eks. `while (buffer_is_empty)`): Kald `pthread_cond_wait(cond, mutex)`.
        3. Modificer delt data (f.eks. fjern et element fra buffer).
        4. Frigør mutex.

---

# Semaforer

En semafor er en tæller, der bruges til at styre adgangen til en mængde ressourcer eller til at synkronisere hændelser.

- **Typer:**
    - **Binær Semafor (Mutex):** En semafor med en værdi på 0 eller 1. Fungerer som en mutex (lås): 0 = låst, 1 = ulåst.
    - **Tællende Semafor (Counting Semaphore):** Kan have en vilkårlig ikke-negativ heltalværdi. Bruges til at tælle tilgængelige ressourcer.
- **Atomiske Operationer:**
    - `sem_init(sem, pshared, value)`: Initialiserer semaforen med en start `value`.
    - `sem_wait(sem)` (også kaldet `P` eller `down`):
        1. Dekrementerer semaforens værdi.
        2. Hvis værdien bliver negativ, blokerer tråden, indtil værdien er positiv igen.
    - `sem_post(sem)` (også kaldet `V` eller `up`):
        1. Inkremeterer semaforens værdi.
        2. Hvis der er tråde blokeret på denne semafor, vækkes én af dem.
- **Anvendelser:**
    - **Gensidig udelukkelse:** (Binær semafor) Beskytter kritiske sektioner, ligesom en mutex.
    - **Ressource tælling:** Styrer adgang til et begrænset antal ressourcer (f.eks. maks. N samtidige databaseforbindelser).
    - **Synkronisering af rækkefølge:** En tråd venter på en semafor, der signaleres af en anden tråd, når en bestemt begivenhed har fundet sted.

---

# Klassiske Synkroniseringsproblemer

Disse problemer bruges ofte til at illustrere og teste synkroniseringsmekanismer.

- **Producent/Forbruger Problemet:**
    - **Beskrivelse:** En eller flere producenter genererer data og placerer det i en delt, begrænset buffer. En eller flere forbrugere tager data fra bufferen og behandler det.
    - **Synkroniseringsbehov:**
        - **Mutex:** Beskytter selve bufferen mod samtidige adgange (race conditions).
        - **Betingelsesvariabel (eller semafor): "Buffer ikke fuld":** Producenten venter, hvis bufferen er fuld. Forbrugeren signalerer, når et element er fjernet.
        - **Betingelsesvariabel (eller semafor): "Buffer ikke tom":** Forbrugeren venter, hvis bufferen er tom. Producenten signalerer, når et element er tilføjet.
    - **Løsning med Semaforer (eksempel):**
        - `empty` (semafor, initialiseret til bufferens størrelse): Tæller ledige pladser. Producent venter på den.
        - `full` (semafor, initialiseret til 0): Tæller optagede pladser. Forbruger venter på den.
        - `mutex` (binær semafor eller mutex): Beskytter adgang til den delte buffer.
- **Læser/Skriver Problemet:**
    - **Beskrivelse:** Flere læsere og flere skrivere deler en delt ressource. Læsere kan tilgå ressourcen samtidigt, men skrivere skal have eksklusiv adgang (ingen andre læsere eller skrivere må være til stede, mens en skriver arbejder).
    - **Synkroniseringsbehov:** Læsere skal kunne tilgå ressourcen parallelt, mens skrivere skal udelukke alle andre. Prioritet kan gives til læsere eller skrivere.
    - **Udfordringer:** Forhindre starvation (f.eks. hvis der konstant er læsere, kan en skriver aldrig få adgang).

---

# Deadlock Strategier: Forhindring, Undgåelse, Detektion

Deadlocks er et alvorligt problem i konkurrerende systemer. Der er forskellige strategier for at håndtere dem.

- **Forhindring (Prevention):** Design systemet, så mindst én af de fire Coffman-betingelser (Gensidig Udelukkelse, Hold og Vent, Ingen Preemption, Cirkulær Ventetid) aldrig kan opfyldes.
    - **Mest almindelige/praktiske metode:** Bryd den **Cirkulære Ventetid**. Implementer en global, fast rækkefølge for, hvordan låse erhverves. Hvis alle tråde altid låser A før B, og B før C, kan en cirkulær afhængighed ikke opstå.
    - **Andre præventioner (ofte upraktiske):**
        - Bryd "Gensidig Udelukkelse": Tillad flere processer adgang til ressourcer samtidig (sjældent muligt for ressourcer, der kræver atomisk adgang).
        - Bryd "Hold og Vent": Kræv, at en proces erhverver _alle_ sine ressourcer på én gang, eller at den frigiver alle sine nuværende ressourcer, før den anmoder om nye.
        - Bryd "Ingen Preemption": Tillad OS'et at fratage ressourcer fra en tråd, der venter (svært for låse).
- **Undgåelse (Avoidance):** OS'et tjekker for "sikre tilstande". Det tillader kun ressourceallokering, hvis det kan garanteres, at en deadlock ikke kan opstå (f.eks. Banker's Algoritme). Kræver forudgående viden om fremtidige ressourcebehov, hvilket sjældent er praktisk i generelle OS'er.
- **Detektion (Detection) og Genopretning (Recovery):**
    - **Idé:** Lad deadlocks opstå. OS'et kører en algoritme til at detektere, når en deadlock er indtruffet (f.eks. ved at lede efter cykler i en ressourceallokeringsgraf).
    - **Genopretning:**
        - **Dræb en af processerne:** Den mest almindelige (og brutale) metode. Ofte en "victim process" udpeges og dræbes, hvilket frigiver dens ressourcer. Kan efterlade systemet i en inkonsistent tilstand.
        - **Rollback:** Rul berørte processer tilbage til et tidligere "safe state" og genstart dem. Anvendes ofte i databaser (transaktioner).
    - **Fordele:** Enkel at implementere, hvis deadlocks er sjældne.
    - **Ulemper:** Kan være ineffektivt, hvis deadlocks sker ofte, og fører til spild af arbejde og datatab.

---

# De 9 Bud for Concurrency (Opsummering)

Disse er generelle retningslinjer for at skrive robust, trådsikker kode:

1. **Tråde er uforudsigelige:** Antag aldrig en specifik rækkefølge eller hastighed for trådudførelse. Resultater skal være korrekte, uanset skiftende tidsplanlægning.
2. **Beskyt delte ressourcer med gensidig udelukkelse (låse):** Brug mutexes, ikke "dovne" flagvariabler.
3. **Brug synkroniserings-primitiver korrekt:** Brug mutexes, betingelsesvariabler, semaforer – ikke simple `if` statements på delte flag for synkronisering.
4. **Antag ikke rækkefølge af vækkede tråde:** Når flere tråde venter på en betingelsesvariabel, er rækkefølgen, de vækkes i, ikke garanteret (selvom nogle OS'er har en form for fairness).
5. **Er biblioteket trådsikkert?** Vær opmærksom på, om de biblioteksfunktioner, du kalder, er trådsikre (thread-safe). Hvis ikke, skal du selv beskytte kaldene med låse.
6. **Skriv atomisk kode:** Del operationer op i så små, atomiske enheder som muligt, beskyttet af låse.
7. **Hold kritiske sektioner korte:** Minimer den tid, en lås holdes. Dette øger parallelitet og reducerer chancen for flaskehalse.
8. **Undgå deadlocks:** Design dit program til at forhindre deadlocks, især ved at etablere og følge en global låserækkefølge.
9. **Test aggressivt:** Concurrency-fejl er svære at reproducere. Brug stresstest, fuzzing og race condition detektionsværktøjer.