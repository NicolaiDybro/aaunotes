# Eksamen 1 - Software Process Model (Waterfall / Incremental / Iterative)

## Hvad er en Software Process Model?
- En abstrakt repræsentation af en proces
- Beskriver processen fra et bestemt perspektiv
- Et sæt af relaterede aktiviteter som kræves for at udvikle et software system

## De 4 Fundamentale Aktiviteter
Alle software processer involverer:

1. **Specification** - Definerer hvad systemet skal gøre
   - Kunder og udviklere definerer krav og egenskaber

2. **Design and Implementation** - Definerer organisationen af systemet
   - Udviklere designer og programmerer softwaren

3. **Validation & Verification** - Checker at systemet gør hvad kunden ønsker
   - Integration og system testing
   - **Validation** = Fit for use (kundens forventninger)
   - **Verification** = Compliant to specification (opfylder kravene)

4. **Evolution** - Ændring af systemet når kundekrav ændrer sig
   - Produktet modificeres for at reflektere ændrede kunde- og markedskrav

## De 3 Hovedtyper af Process Models

### A. Waterfall Model (Plan-driven)
**Karakteristika:**
- Separate og distinkte faser
- Sekventiel flow: Specification → Design → Implementation → Test → Operations
- Handover af work products mellem faser
- Milepæle og relaterede work products bruges til at monitere fremskridt
- Ændringer er dyre når først implementering er startet

**Hvornår bruges Waterfall?**
- Embedded systems
- Life-critical systemer
- Meget store projekter
- Stabile krav der er velforstået
- Veldefineret løsning

**Fordele:**
- God dokumentation
- Klare milepæle
- Forudsigelig
- Nem at forstå og administrere

**Ulemper:**
- Infleksibel overfor ændringer
- Svært at reagere på nye krav
- Kunden ser intet før sent i projektet
- Høj risiko hvis krav er forkerte

### B. Incremental Development
**Karakteristika:**
- Specification, development og validation er interleaved (sammenflettet)
- Kan være plan-driven ELLER agile
- Systemet udvikles i increments (tilvækster)
- Hurtigere leverance af nyttig funktionalitet
- Tidlige increments fungerer som prototype for senere

**Fordele:**
- Lavere omkostninger ved kravændringer
- Lettere at få feedback
- Kunden får tidligere mulighed for at bruge dele af produktet
- Risikoreduktion gennem tidlig validering

**Ulemper:**
- Processen er mindre synlig (management udfordring)
- System struktur kan deteriorere når nye increments tilføjes
- Kræver refactoring

**Kan være iterativ:**
- Iteration = gentag og forbedr
- Du kan iterere inden for hvert increment

### C. Integration and Configuration (Reuse-oriented)
**Karakteristika:**
- Systemet samles fra eksisterende konfigurerbare komponenter
- COTS (Commercial Off-The-Shelf) komponenter
- Kan være plan-driven eller agile
- Hurtigere time-to-market

**Fordele:**
- Reducerede omkostninger
- Hurtigere leverance
- Bruger prøvet teknologi

**Ulemper:**
- Kompromis med krav
- Tab af kontrol over evolution
- Integration kan være kompleks

## 3 Ting vi ønsker var sande vs. Virkeligheden

**Vi ønsker:**
1. Kunden ved hvad han vil have
2. Udviklerne ved hvordan man bygger det
3. Intet ændrer sig undervejs

**Virkeligheden:**
1. Kunden opdager hvad han vil have
2. Udviklerne opdager hvordan man bygger det
3. Mange ting ændrer sig undervejs

## Håndtering af Ændringer

### I. System Prototyping
- Quick udvikling af en version eller del af systemet
- Checker kundens krav og design decisions feasibility
- Understøtter change anticipation

### II. Incremental Delivery
- System increments leveres til kunden for kommentarer
- Understøtter både change avoidance og change tolerance

## Process Improvement: Capability Maturity Levels

1. **Initial** - Essentially uncontrolled
2. **Repeatable** - Product management procedures defined
3. **Defined** - Process management procedures and strategies defined
4. **Managed** - Quality management strategies defined and used
5. **Optimizing** - Process improvement strategies defined and used

## Mixed Processes i Praksis
- De fleste store systemer bruger en kombination af alle modeller
- Forskellige dele kan bruge forskellige processer
- Hybrid tilgange er normen

---

## Eksamensnoter - Vigtige Spørgsmål

1. **Hvad er SE en reaktion på?** - Kompleksitet og fejl i software projekter
2. **Beskriv Waterfall karakteristika** - Sekventielle aktiviteter, handover, milepæle
3. **Hvornår bør man overveje Waterfall?** - Embedded, life-critical, meget store projekter
4. **Beskriv incremental/iterative model** - Slicing af den store plan i mindre slices
5. **Hvad er fordelene ved incremental?** - Billigere ændringer, lettere feedback, tidligere værdi
6. **Hvad er ulemperne?** - Usynlig proces, struktur deterioration
7. **Kan incremental være iterativ?** - Ja, man kan iterere inden for increments
8. **Kan incremental være plan-driven?** - Ja, man kan planlægge increments på forhånd
9. **Hvordan vælger jeg model?** - Brug Boehm's Home Ground analysis

## Fremlæggelsesstruktur (5 min)
1. **Intro** (30 sek) - Hvad er en process model?
2. **De 4 aktiviteter** (1 min) - Specification, Design, Validation & Verification (V&V), Evolution,
3. **Waterfall** (1.5 min) - Karakteristika, hvornår bruges, fordele/ulemper
4. **Incremental** (1.5 min) - Karakteristika, hvornår bruges, fordele/ulemper
5. **Sammenligning** (30 sek) - Hvornår bruges hvad?
6. **Afrunding** (10 sek) - Mixed processes i praksis

