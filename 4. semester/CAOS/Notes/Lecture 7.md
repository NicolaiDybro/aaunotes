# Pipelining: Den Grundlæggende Parallelisme

- **Idé:** Del en instruktionsudførelse op i flere sekventielle trin (faser). Forskellige instruktioner kan være i forskellige trin samtidigt.
- **Formål:** Øger gennemløbet (throughput) af instruktioner. Du får flere instruktioner færdige per tidsenhed.
- **Hvordan virker det:** Hvert trin udfører en del af arbejdet, og resultatet gives videre til næste trin. Forestil dig en samlebåndslinje.
- **Fordele:** Dramatisk forbedring i Giga-Instruktioner Per Sekund (GIPS) sammenlignet med en ikke-pipelinet processor, selvom den enkelte instruktions latenstid (den tid det tager for _én_ instruktion at gennemløbe pipelinen) kan være den samme eller lidt længere.
- **Ulemper/Udfordringer (Hazards):**
    - **Data Hazards:** En instruktion har brug for et resultat fra en tidligere instruktion, der endnu ikke er færdig i pipelinen. Kræver "stalling" (ventetid) eller "forwarding" (videresendelse af resultater direkte).
    - **Structural Hazards:** To instruktioner forsøger at bruge den samme hardware-ressource samtidigt.
    - **Control Hazards (Branch Hazards):** Usikkerhed om udfaldet af betingede spring (if/else, løkker). Processoren skal gætte eller vente, hvilket kan tømme pipelinen.
- **Løsning på Hazards:** Branch Prediction (gætter på spring), Speculative Execution (udfører instruktioner baseret på gæt), Data Forwarding, Register Renaming (undgår falske dataafhængigheder).

---

#  Instruktionsniveau-Parallelisme (ILP)

- **Definition:** Muligheden for at udføre flere instruktioner samtidigt inden for en enkelt clock-cyklus.
- **Processortyper der udnytter ILP:**
    - **Superscalar Processorer:** Moderne processorer, der dynamisk kan udføre flere uafhængige instruktioner i samme clock-cyklus ved hjælp af flere eksekveringsenheder (f.eks. flere ALU'er, load/store enheder).
    - **Out-of-Order Execution:** Processoren omarrangerer instruktioner dynamisk for at maksimere udnyttelsen af eksekveringsenhederne og undgå stalls, så længe det ikke ændrer programmets korrekte output.
    - **VLIW (Very Long Instruction Word):** Compileren grupperer statisk uafhængige instruktioner i ét "langt" instruktionsord, som processoren så udfører parallelt. Kræver mere intelligent compiler, men simplere hardware.
- **Hovedkilder til ILP:**
    - Pipelining
    - Multiple eksekveringsenheder
    - Out-of-order execution
    - Register Renaming (undgår falske afhængigheder)
    - Branch Prediction

---

# Compileroptimeringer: Hvad compileren kan gøre

Compileren analyserer koden og omskriver den til en mere effektiv form, uden at ændre programmets logik.

- **Løkke-invariante kodebevægelser (Loop-Invariant Code Motion):** Flytter beregninger, der giver samme resultat i hver iteration af en løkke, ud _før_ løkken. Sparer gentagne beregninger.
- **Styrkereduktion (Strength Reduction):** Erstatter "dyre" operationer (f.eks. multiplikation eller division) med "billigere" (f.eks. addition, subtraktion, bit-shift) hvor muligt.
- **Fjernelse af fælles subudtryk (Common Subexpression Elimination):** Hvis det samme udtryk beregnes flere gange, gemmes resultatet og genbruges.
- **Død kode eliminering (Dead Code Elimination):** Fjerner kode, der aldrig vil blive udført, eller hvis resultater ikke bruges andre steder.
- **Funktionsinlineing (Inlining):** Erstatter et funktionskald med selve funktionskroppen. Eliminerer kald-overhead (stack-setup, returadresse) og muliggør yderligere optimeringer på den udvidede kode.
- **Løkkeudrulning (Loop Unrolling):** Gentager løkkens krop flere gange inde i løkken og reducerer antallet af løkke-iterationer. Minimerer overhead fra løkkebetingelse og tæller, og kan øge ILP ved at give processoren flere instruktioner at arbejde med samtidigt.
- **Instruktionsplanlægning (Instruction Scheduling):** Omarrangerer instruktioner for at minimere stalls i pipelinen og bedre udnytte parallelle eksekveringsenheder.
- **Registerallokering:** Tildeler ofte brugte variabler til CPU-registre i stedet for at gemme dem i hukommelsen, da registre er langt hurtigere at tilgå.

---

# Compilerens Begrænsninger: Hvad compileren _ikke_ kan gøre (eller har svært ved)

- **Pointer Aliasing (Alpaka Problemet):** Compileren kan ikke altid med sikkerhed afgøre, om to forskellige pointere peger på det samme hukommelsessted. Dette forhindrer aggressive optimeringer, da compileren skal antage "worst-case" for at bevare korrekthed.
- **Funktionssideeffekter:** Hvis en funktion ændrer en global variabel, udfører I/O, eller har andre ikke-lokale effekter, kan compileren ikke frit omarrangere eller eliminere dens kald.
- **Dynamiske Afhængigheder:** Compileren arbejder på statisk kode. Information, der kun er kendt under kørsel (f.eks. inputværdier, adresser dynamisk allokeret hukommelse), begrænser compilerens muligheder for at forudsige adfærd.
- **Algoritmedesign:** En compiler kan **ikke** ændre et dårligt algoritmes asymptotiske kompleksitet (dens "Big-O"). En O(N2) algoritme vil altid være langsommere end en O(NlogN) for store N, uanset compileroptimeringer. Den kan kun optimere konstante faktorer.
- **Heuristikker:** Optimering er et svært (NP-hardt) problem. Compilere bruger heuristikker, som ikke altid finder den absolut bedste løsning.

---

# Performance Måling: Mål, Før Du Optimerer!#

- **Hvorfor måle?** "If it ain't measured, don't fix it!" – Måling er essentielt for at identificere faktiske flaskehalse og bevise effekten af optimeringer.
- **Vigtige overvejelser ved måling:**
    - **Korrekte Tidsmål:** Brug højopløsnings timere (nanosekunder). Vær opmærksom på forskel mellem _real-tid_ (væg-ur), _CPU-tid_ (faktisk CPU-tid brugt af dit program), og _CPE_ (Cycles Per Element, nyttig for løkker).
    - **Forstyrrelser:** Minimer indflydelse fra OS, netværk, virtuel hukommelse, andre applikationer. Sæt CPU'en til "high performance mode" på bærbare.
    - **Måle-kodens indflydelse:** Selve koden til at måle kan påvirke programmet. Undgå f.eks. dyre I/O operationer som `printf` i den kritiske kode.
    - **Cache "Warm-up":** Kør koden et par gange før den egentlige måling, for at fylde CPU-cachen. Mål aldrig kun den første kørsel, da den kan være langsommere.
    - **Statistik:** Indsaml mange målinger. Brug gennemsnit, median, varians, min og max for at få et robust billede af performancen og identificere outliers.
- **Anbefalede målemetoder:**
    - `rdtsc` (read time stamp register): Meget præcis for mikro-benchmarks, men kan være problematisk på ældre/forskellige multicore systemer (hvis ikke synkroniseret).
    - `clock_gettime()`: Mere generel og portabel, giver høj opløsning.
    - **Måleloop:** Gentag den kode, der skal måles, mange gange i en løkke og gem tiderne for statistisk analyse.