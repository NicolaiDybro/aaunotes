1. Hvordan kan kvalitet defineres?
    
    Kvalitet kan defineres som overensstemmelsen mellem brugerens forventning og den faktiske oplevelse af produktet. Materialet nævner også definitioner som "Excellence", "Værdi for pengene" og "Fitness for purpose".
    
2. Hvordan sikres kvalitet (Quality Assurance)?
    
    Det gøres ved at planlægge, hvordan og hvornår man udfører verificering og validering gennem hele udviklingsprocessen. Det handler om at have en systematisk tilgang til at forebygge og finde fejl.
    
3. **Hvad er Verificering og Validering?**
    
    - **Verificering (VER):** Bygger vi systemet rigtigt? (Overholder vi specifikationerne/kravene?).
        
    - **Validering (VAL):** Bygger vi det rigtige system? (Er det brugbart og skaber det værdi for kunden – "fit for use"?).
        
4. Hvilke teknikker bruges typisk til V&V?
    
    Test bruges ofte til verificering (tjek af kode mod krav), mens reviews, prototyper og evalueringer med brugere bruges til validering.
    
5. **Hvad er forskellen på review og test?**
    
    - **Review:** Er en **statisk** proces (man læser kode/dokumenter uden at køre programmet). Fejl fundet her påvirker ikke hinanden.
        
    - **Test:** Er en **dynamisk** proces (programmet køres). Her kan én fejl skjule andre fejl eller skabe bivirkninger (side-effects).
        
6. Hvorfor kan vi ikke få alle kvalitetsattributter?
    
    Fordi der er nødvendige "trade-offs". For eksempel kan høj effektivitet (performance) kræve kompleks kode, hvilket går ud over genbrugelighed (reusability) eller læsbarhed.
    
7. Hvad er V-modellen?
    
    En model der viser sammenhængen mellem udviklingsfaser og testniveauer: a) Accepttest, b) Systemtest, c) Systemintegrationstest, d) Sub-systemintegrationstest, og e) Enhedstest (unit test).

8. Hvad er den agile test-kvadrant?
    
    En kategorisering af testtyper langs to akser: Teknologi-orienteret vs. Forretnings-orienteret, og Støt teamet vs. Kritik af produktet. Det hjælper teamet med at sikre, at de får testet hele vejen rundt (både unit tests og brugertests).
    
9. **Hvilke agile praksisser støtter V&V?**
    
    - **Generelt:** Definition of Done (DoD), Sprint Review, "Never break the build", og en kultur med fælles ansvar for kvalitet.
        
    - **XP-specifikt:** Customer on-site (validering) og Pair Programming (løbende review/verificering).
        

---

### **Eksamensoplæg: Quality Management (5 minutter)**

#### **1. Introduktion: Hvad er kvalitet?**

- **Definition:** Kvalitet er ikke entydigt. Det kan være "Excellence" (fejlfrit), "Værdi" (pris vs. ydelse) eller "Fitness for use" (brugeren kan faktisk bruge det).
    
- **Process Theory:** En softwareprodukt kan kun blive så godt som den proces, det er skabt igennem. Forbedrer vi processen, forbedrer vi kvaliteten.
    

#### **2. Verificering vs. Validering (V&V)**

- **Verificering (VER):** "Bygger vi produktet rigtigt?" – Fokus på specifikationer og teknisk korrekthed.
    
- **Validering (VAL):** "Bygger vi det rigtige produkt?" – Fokus på om kunden får løst sit problem.
    
- **V-modellen:** Den klassiske måde at se testniveauer på, hvor hvert udviklingstrin har et modsvarende testtrin (f.eks. Krav $\leftrightarrow$ Accepttest).
    

#### **3. Test-strategier og Teknikker**

- **Statisk vs. Dynamisk:** Review (læse kode/dokumenter) vs. Test (køre koden).
    
- **Agile Testing Quadrants:**
    
    - _Kvadrant 1 & 2 (Støt teamet):_ Unit tests og funktionelle tests (Automatisering).
        
    - _Kvadrant 3 & 4 (Kritik af produktet):_ Exploratory testing og performance tests.
        
- **Trade-offs:** Vi kan ikke optimere alt. Man skal vælge mellem f.eks. sikkerhed vs. brugervenlighed eller hastighed vs. vedligeholdelse.
    

#### **4. Agile Praksisser og Kvalitetskultur**

- **Definition of Done (DoD):** Vores fælles tjekliste for, hvornår en opgave er "god nok" til at blive leveret.
    
- **XP (eXtreme Programming):**
    
    - _Pair Programming:_ To personer ved én skærm = 100% løbende review af koden.
        
    - _Customer on-site:_ Sikrer den hurtigste validering af krav.
        
- **Refactoring:** At forbedre koden uden at ændre dens opførsel (fjerne "bad smells").
    

#### **5. Afslutning: Kvalitet som fælles ansvar**

- Kvalitet er ikke noget, en "testerne" gør til sidst. I agile teams er det en del af kulturen.
    
- **Automatisering:** "Check before check-in" og "Never break the build" sikrer, at vi opretholder en høj baseline af kvalitet gennem hele forløbet.