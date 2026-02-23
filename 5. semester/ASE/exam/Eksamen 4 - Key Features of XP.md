1. **Hvad er eXtreme Programming (XP)?** XP er en agil udviklingsmetode, der er både inkrementel og iterativ. Den har et stærkt fokus på tæt samarbejde, hurtig levering af software og meget disciplinerede tekniske praksisser.
    
2. **Hvilke værdier er XP baseret på?** De fire kerneværdier er: **Kommunikation, Enkelhed (Simplicity), Feedback og Mod (Courage)**. Mod handler f.eks. om at turde slette dårlig kode eller ændre kurs, når man lærer noget nyt.
    
3. **Hvorfor er XP "ekstrem"?** Fordi den tager anerkendte gode praksisser og skruer dem op på 10. Hvis test er godt, så tester vi _hele tiden_. Hvis review er godt, så laver vi review _hele tiden_ (via Pair Programming).
    
4. **Nævn nogle af nøglepraksisserne i XP?**
    
    - **Tekniske:** Unit testing, TDD (Test-Driven Development), Continuous Integration og Refactoring.
        
    - **Samarbejde:** Pair Programming, Customer on-site og Planning Game.
        
5. **Hvad er en User Story?** En kort beskrivelse af en ønsket funktion. Den kaldes ofte "et løfte om en samtale" (a promise for a conversation). Det er ikke en detaljeret kravspecifikation, men et udgangspunkt for dialog.
    
6. **Hvad er formatet på en User Story?** Standardformatet er: _"Som en [rolle], vil jeg [handling], således at [værdi/formål]"_. Den skrives ofte på et fysisk kort, hvor acceptkriterier står på bagsiden.
    
7. **Hvordan beskriver XP systemets livscyklus?** Den består af faserne: **Exploration** (udforskning), **Planning**, **Iterations to first release**, **Production** og **Maintenance**.
    
8. **Hvad kaldes en iteration i XP?** Den kaldes slet og ret en **Iteration** (hvor Scrum kalder det et Sprint).
    
9. **Hvad er Test-Driven Development (TDD)?** En arbejdsproces i tre trin: 1. Skriv en test der fejler (Red), 2. Skriv den simpleste kode for at få testen til at bestå (Green), 3. Forbedr koden uden at ændre funktion (Refactor).
    
10. **Hvorfor er TDD godt?** Det skaber et sikkerhedsnet, så man ikke er bange for at ændre i koden. Det sænker omkostningerne ved fejl, da de findes med det samme, og det fører til mere læsbar og vedligeholdbar kode.
    

---

### **Eksamensoplæg: XP – Kvalitet gennem teknisk disciplin (5 minutter)**

#### **1. Problemet: Frygten for forandring og "Rigid kode"**

- **Problemet:** I mange projekter bliver koden over tid så kompleks og skrøbelig, at udviklere bliver bange for at ændre i den, fordi de frygter at ødelægge noget andet (side-effects).
    
- **Konsekvens:** Udviklingshastigheden falder, og antallet af fejl stiger ("Technical Debt").
    

#### **2. XP som løsningen: At tage det "ekstreme" valg**

- **Filosofien:** Kent Beck (grundlæggeren) sagde: Hvis en aktivitet er god, så gør den hele tiden.
    
- **Modgiften til fejl:** I stedet for at teste til sidst, bruger vi **TDD**. Det løser problemet med usynlige fejl, fordi vi har et automatiseret sikkerhedsnet fra dag ét.
    
- **Modgiften til videntab:** I stedet for at én person sidder med ansvaret for et modul, bruger vi **Pair Programming**. Det sikrer løbende review og videndeling.
    

#### **3. Kommunikation og User Stories**

- **Problemet med dokumentation:** Tykke kravspecifikationer bliver hurtigt forældede og bliver ofte misforstået.
    
- **XP-løsningen:** **User Stories** og **Customer on-site**. Ved at have kunden tæt på, minimerer vi risikoen for at bygge noget, der ikke skaber værdi (Validering). Vi erstatter lange dokumenter med dialog.
    

#### **4. Planlægning: The Planning Game**

- I XP planlægger vi i korte intervaller. Vi forsøger ikke at forudsige alt for de næste to år, men fokuserer på de næste par uger.
    
- **Simplicity:** Vi bygger kun det, der er brug for _nu_ (YAGNI - You Ain't Gonna Need It). Det holder systemet enkelt og nemt at vedligeholde.
    

#### **5. Afslutning: Disciplin giver frihed**

- Mange tror, at agile metoder som XP er "kaotiske", fordi der er mindre dokumentation. Men i virkeligheden kræver XP **højere disciplin** pga. TDD og Pair Programming.
    
- **Konklusion:** XP løser problemet med faldende kvalitet ved at gøre kvalitet til en integreret del af hvert eneste minut, vi koder. Det gør os i stand til at levere software, der er "fit for use" og teknisk sundt.