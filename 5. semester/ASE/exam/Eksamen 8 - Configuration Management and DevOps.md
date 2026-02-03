1. **Hvad beskæftiger CM sig med?** Configuration Management (konfigurationsstyring) handler om de politikker, processer og værktøjer, man bruger til at styre software-systemer, der ændrer sig over tid.
    
2. **Hvad er hovedaktiviteterne i CM?** De fire nøgleaktiviteter er:
    
    - **Version Management:** Styring af forskellige versioner af kodefiler.
        
    - **System Building:** Samling af koden til et kørbart system.
        
    - **Change Management:** Styring af anmodninger om ændringer.
        
    - **Release Management:** Planlægning og styring af udgivelser til kunderne.
        
3. **Hvad er CM, branching og merging?** Det er teknikker til at understøtte builds og releases. **Branching** lader udviklere arbejde på en kopi af koden uden at forstyrre hovedlinjen. **Merging** er processen med at føre ændringer fra forskellige branches sammen igen.
    
4. **Hvad er en baseline?** En baseline er en komplet beskrivelse af en specifik release. Den gør det muligt at genskabe præcis den samme version af systemet i fremtiden. Den indeholder versioner af alle kildefiler, dokumentation og eksterne biblioteker, som de så ud på release-tidspunktet.
    
5. **Hvad indgår i en release?** En release indeholder alt, hvad systemet har brug for for at køre: Al kildekode, datafiler, konfigurationsfiler og dokumentation (f.eks. brugervejledninger).
    
6. **Hvad er DevOps, og hvordan defineres det?** DevOps er en praksis, der forbinder udvikling (_Development_) og drift (_Operations_). Det defineres ofte ved **"The Three Ways"**:
    
    - **Flow:** At få værdi hurtigt fra kode til drift.
        
    - **Feedback:** Hurtig viden om systemets tilstand retur til udviklerne.
        
    - **Continuous Learning:** En kultur for konstant læring og eksperimentering.
        
7. **Hvad er formålet med Continuous Integration (CI)?** Formålet er, at udviklere tjekker deres kode ind så ofte som muligt (mindst dagligt). Koden bliver derefter automatisk bygget og testet. Det sikrer, at fejl findes med det samme, og at koden altid kan integreres.
    
8. **Hvad er formålet med Continuous Delivery og Deployment?**
    
    - **Continuous Delivery (CD):** Sikrer at koden _altid_ er i en tilstand, hvor den sikkert kan deployes til produktion (manuel godkendelse før release).
        
    - **Continuous Deployment:** Her deployes koden automatisk til produktion, så snart den har bestået alle test. Det gør processen hurtigere og fjerner manuelle fejl.
        

---

### **Eksamensoplæg: Configuration Management & DevOps (5 minutter)**

#### **1. Introduktion: Hvorfor CM?**

- **Problemet:** Software ændrer sig konstant. Hvordan holder vi styr på, hvem der har ændret hvad, og hvilken version kunden har?
    
- **Definition:** CM er infrastrukturen, der gør det muligt at styre ændringer professionelt.
    

#### **2. CM Kernen: Versioner, Branches og Baselines**

- **Version Management:** Vi bruger branches (grene) til at udvikle nye funktioner isoleret.
    
- **Merging:** Udfordringen er at føre koden sammen igen uden konflikter.
    
- **Baselines:** "Et snapshot i tiden". Det er vigtigt for at kunne rulle tilbage eller rette fejl i en gammel version, som en kunde stadig bruger.
    

![Billede af software branching and merging](https://encrypted-tbn3.gstatic.com/licensed-image?q=tbn:ANd9GcTGhx_OTiF3Fw4m0QWlHiGHOOXjoFBIz7IGdsTSIqlUxBCocAAf_YEiTxH8UBf6Io1HJFW6lkkVXFC1p2Pp7zjlRemHY7uUB-VWwDlm-pWJ0B-Kgp4)

Getty Images

#### **3. Pipeline: Fra CI til CD**

- **Continuous Integration (CI):** "Check before check-in". Vi integrerer ofte for at undgå "Integration Hell". Automatiske test er fundamentet.
    
- **Continuous Delivery vs. Deployment:**
    
    - Delivery = Vi er _klar_ til at release når som helst.
        
    - Deployment = Vi releaser _automatisk_ (høj modenhed).
        

![Billede af CI/CD pipeline](https://encrypted-tbn0.gstatic.com/licensed-image?q=tbn:ANd9GcRVytgR0XpmQG-lJfvf74W3O5oMYxONYz7rwK00chhRa2BQTlOY_wvS-9KanGhwNtimk7mV3rrEwFnkyS9jUSEucTuOkBgjNOX_cf1xp4eu8d10Lcs)

Shutterstock

Udforsk

#### **4. DevOps: Kultur og "The Three Ways"**

- **The First Way (Flow):** Vi optimerer hele vejen fra idé til drift. Vi fjerner "waste" (Lean-principper).
    
- **The Second Way (Feedback):** Vi bruger monitorering og automatisk test til at vide, om koden virker med det samme.
    
- **The Third Way (Learning):** Vi tør fejle, fordi vores CM-system og pipeline gør det sikkert at rette fejl hurtigt.
    

#### **5. Afslutning: Sammenhængen med Agilitet**

- Uden stærk CM og DevOps kan man ikke være agil. Agilitet kræver, at vi kan reagere på ændringer hurtigt – og det kræver en automatiseret pipeline og fuld kontrol over vores konfigurationer.
    
- **Lean-princippet:** "Deliver fast" og "Build integrity in" (høj kvalitet i hver lille ændring).