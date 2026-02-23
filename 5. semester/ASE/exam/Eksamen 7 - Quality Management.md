# Eksamen 7 - Quality Management

## Hvad er Kvalitet?

### Definition
> Quality er en reflection af én eller flere personers vurdering af korrespondance mellem deres **forventninger** og **oplevelse** af et produkt eller service

### 4 Perspektiver på Kvalitet
1. **Excellence** - "The best"
2. **Value** - "Worth the price"
3. **Conformance to specifications** - "Meets requirements"
4. **Meeting/exceeding expectations** - "Better than expected"

## 3 Typer af Kvalitet

### 1. Product Quality
- Selve software produktets kvalitet
- Funktionalitet
- Performance
- Reliability
- Osv.

### 2. Process Quality
- Kvaliteten af udviklings processen
- Hvordan kode er lavet
- Reviews, testing practices
- Development standards

### 3. Expectations Quality
- Match mellem forventninger og realitet
- Stakeholder alignment
- Communication quality

**Key Insight:**
> A software product can only be as good as the process through which it is produced

## Software Quality Attributes

### Functional Requirements
- **Beskriver:** Hvad systemet skal gøre
- **Dokumenteret i:**
  - Waterfall: Requirement Specification
  - Agile: Product Backlog, User Stories

### Non-Functional Requirements (Quality Attributes)

**Kategori eksempler (Sommerville):**
- **Safety** - Sikker at bruge
- **Security** - Beskyttet mod angreb
- **Reliability** - Virker konsistent
- **Resilience** - Kan håndtere fejl
- **Robustness** - Håndterer uventede inputs
- **Usability** - Let at bruge
- **Learnability** - Let at lære
- **Understandability** - Let at forstå
- **Portability** - Kan køre på flere platforme
- **Efficiency** - Bruger resourcer godt
- **Testability** - Let at teste
- **Adaptability** - Let at ændre
- **Modularity** - Opdelt i moduler
- **Maintainability** - Let at vedligeholde
- **Flexibility** - Kan tilpasses
- **Reusability** - Komponenter kan genbruges
- **Interoperability** - Arbejder sammen med andre systemer
- **Complexity** - Lav kompleksitet

### Trade-offs Er Nødvendige

**Positive vs Negative Influence:**
- Usability ↔ Security (lettere login vs sikker login)
- Efficiency ↔ Maintainability (optimized code vs readable code)
- Reusability ↔ Efficiency (generic vs specialized)
- Portability ↔ Efficiency (cross-platform vs platform-specific)

**Du kan ikke have alle!**
- Prioriter de vigtigste attributes
- Find balance
- Document trade-offs

## Quality Management Aktiviteter

### Quality Assurance (QA)
**Hvad:** Definition af processer og standarder der leder til høj kvalitet
**Fokus:** Prevention - undgå dårlig kvalitet
**Aktiviteter:**
- Definér development processes
- Etablér coding standards
- Etablér review processes
- Definér test strategies
- Training og education

### Quality Control (QC)
**Hvad:** Application af quality processes til at finde produkter med lav kvalitet
**Fokus:** Detection - find dårlig kvalitet
**Aktiviteter:**
- Udførelse af reviews
- Udførelse af tests
- Inspections
- Measurements
- Monitoring

**Quality Management = QA + QC**

## Cost of Quality

### Cost Categories

#### Preventive Costs (Proaktiv)
- Better planning (af review, test, etc.)
- Measurable quality factors definition
- Education og training af developers
- Process improvement
- Tool investment

#### Monitoring Costs (Detektiv)
- Evaluation, peer review, code inspection
- Testing (alle niveauer)
- Quality metrics collection
- Audits

#### Cost of Correction (Reaktiv)
- Bug fixes
- Rework
- Customer support
- Lost customers
- Reputation damage

### Cost of Quality Over Time

```
Cost
  ↑
  │     ╱────────────── Total (low quality mgmt)
  │    ╱
  │   ╱        ────────── Total (high quality mgmt)
  │  ╱    ────
  │ ╱────
  └──────────────────────→ Time
  Low quality → High quality
```

**Observation:**
- Low quality management: Billigt initialt, dyrt over tid
- High quality management: Initialt investment, billigere over tid
- Balance er key - 100% defect-free er for dyrt

## Verification vs Validation

### Verification
> "Are we building the system right?"

**Focus:** Conformance to **specification**
- Er alle requirements implementeret?
- Følger vi design?
- Er koden correct?

**Teknikker:**
- Reviews (design, code)
- Testing (unit, integration)
- Static analysis

### Validation
> "Are we building the right system?"

**Focus:** **Fit for use** - kundens forventninger
- Er systemet nyttigt?
- Opfylder det brugerens behov?
- Giver det værdi?

**Teknikker:**
- Prototype evaluation med users
- User Acceptance Testing (UAT)
- Beta testing
- A/B testing
- Usability testing

**Regel:**
- **Validation** kræver user participation (kun de ved om det er "fit for use")
- **Verification** fokuserer på spec compliance

## Review vs Test

### Review (Static)
**Karakteristika:**
- Ingen execution af kode
- Manual inspection
- Kan finde mange typer fejl tidligt
- Errors er **independent** - ingen interaktion mellem fundne fejl

**Typer:**
- Code review
- Design review
- Documentation review
- Peer review
- Formal inspection

**Fordele:**
- Find errors early (billigt)
- Knowledge sharing
- Learning opportunity

### Test (Dynamic)
**Karakteristika:**
- Execution af kode
- Automated eller manual
- Finder runtime errors
- Efter første bug kan andre bugs være **side-effects**

**Typer:**
- Unit testing
- Integration testing
- System testing
- Acceptance testing

**Udfordring:**
- Kan være svært at isolere root cause
- Test interference

**Konklusion:** Reviews og testing er **komplementære** - brug begge!

## V-Model

```
Requirements ←──────────→ Acceptance Testing
      ↓                         ↑
System Design ←──────────→ System Testing
      ↓                         ↑
Architecture ←────────────→ Integration Testing
      ↓                         ↑
Detailed Design ←─────────→ Unit Testing
      ↓                         ↑
      Implementation
```

**Key Points:**
- Hver development fase har tilsvarende test niveau
- Test planlægges tidligt
- Plan-driven approach
- Typer af tests:
  - **Unit Testing:** Test individuelle komponenter
  - **Integration Testing:** Test komponent interfaces
  - **System Testing:** Test hele systemet
  - **Acceptance Testing:** Validér med customer

## Agile Testing Quadrant (Brian Marick / Lisa Crispin)

```
        Supporting the Team | Critique Product
        ─────────────────────────────────────
Business │   Q2            │    Q3
Facing   │   Story Tests   │   Exploratory
         │   Prototypes    │   Usability
         │   Examples      │   UAT
        ─────────────────────────────────────
Technology│   Q1            │    Q4
Facing   │   Unit Tests    │   Performance
         │   Component     │   Load
         │   Tests         │   Security
```

### Quadrant 1 (Q1): Technology Facing + Support Team
- Unit tests
- Component tests
- Automated
- Test-Driven Development

### Quadrant 2 (Q2): Business Facing + Support Team
- Story tests (acceptance tests)
- Examples
- Prototypes
- Functional tests

### Quadrant 3 (Q3): Business Facing + Critique Product
- Exploratory testing
- Usability testing
- UAT
- Alpha/Beta testing

### Quadrant 4 (Q4): Technology Facing + Critique Product
- Performance testing
- Load testing
- Security testing
- "ility" testing

## Agile Quality Practices

### 1. Definition of Done (DoD)
**Hvad:** Team agreement om hvornår task er complete
**Eksempel:**
- Code written
- Code reviewed
- Unit tests written og passing
- Integration tests passing
- Documentation updated
- Deployed to test environment
- Accepted by PO

### 2. Sprint Review
**Kvalitet Fokus:**
- PO og stakeholders validerer sprint delivery
- Feedback på om det møder forventninger
- Validation af product

### 3. Check Before Check-in
**Praksis:**
- Developers organiser egen code review før check-in
- Pair programming
- Code må ikke bare pushes

### 4. Never Break the Build
**Regel:**
- Test dine ændringer mod hele systemet før check-in
- Continuous Integration hjælper
- Broken build stoppes alt

### 5. Fix Problems When You See Them
**Praksis:**
- Hvis du finder problem i andres kode, fix det
- Boy Scout Rule: "Leave code better than you found it"
- Collective ownership

### 6. Quality Culture
**Key:**
- Alle team members er ansvarlige for quality
- Ikke kun QA's job
- Built into workflow

### 7. XP Practices for Quality
- **Pair Programming:** Kontinuerlig code review
- **TDD:** Built-in testing
- **Continuous Integration:** Konstant validation
- **On-site Customer:** Kontinuerlig validation
- **Refactoring:** Konstant forbedring

## Test-Driven Development (TDD)

### Red-Green-Refactor Cycle
1. **🔴 Red:** Write failing test
2. **🟢 Green:** Write simplest code to pass
3. **🔵 Refactor:** Clean up code
4. **Repeat**

### Fordele af TDD
- **Code coverage:** Hver segment har mindst én test
- **Regression testing:** Test suite udvikles incrementally
- **Simplified debugging:** Når test fejler, ved du hvor problemet er
- **System documentation:** Tests beskriver hvad koden skal gøre
- **Better design:** Forces modularity

## Refactoring

### Hvad er Refactoring?
> Changing internal structure uden at ændre external behavior

**Formål:**
- Improve code quality
- Reduce complexity
- Improve readability
- Maintain maintainability

### Hvornår Refactor?
- Clean before adding new functionality
- Når du ser "bad smells"
- Efter TDD green phase
- During code review

### Refactoring Requires
- **God test suite** - safety net
- **Small changes** - methodical approach
- **Design patterns** - know them
- **Run tests** hver gang - find regression tidligt

### Martin Fowler's Advice
- Make changes small og methodical
- Follow design patterns
- Have test suites ready
- Run tests efter hver refactoring

### Code Smells (Lacerda et al. 2020)
**Eksempler:**
- Long method
- Large class
- Duplicate code
- Dead code
- God class (knows/does too much)
- Feature envy
- Data clumps

### Argumenter MOD Refactoring
1. "Refactoring reflects poor analysis/design - do it right first time"
2. "Refactoring is expensive - all documentation must be altered"
3. "Refactoring introduces new errors in unpredictable places"
4. "Refactoring threatens architectural integrity"
5. "Customers expect new functionality, won't pay for rework"
6. "Refactoring doesn't extend value - if it ain't broke don't fix it"

**Rebuttal:**
- Perfect design up-front er umuligt
- Refactoring reducer future costs
- God test suite mitigerer error risk
- Refactoring kan forbedre architecture
- Technical debt har real cost
- Prevention of future problems har value

## Process Improvement for Quality

### Principle
> You can only improve quality if you improve the process

- Repeating same process → same quality level
- Sources af bad quality → input til process improvement
- Measure, analyze, improve (continuous cycle)

### Process Maturity (CMMI relation)
Higher process maturity → Higher product quality

---

## Eksamensnoter - Vigtige Spørgsmål

1. **Hvordan defineres quality?** - Correspondence mellem expectation og experience
2. **Hvordan assures quality?** - Plan hvordan og hvornår V&V
3. **Hvad er Verification og Validation?** - VER: compliant to spec, VAL: fit for use
4. **Teknikker til V&V?** - Test (verification), Review/Evaluation (validation)
5. **Forskel mellem review og test?** - Review static/independent errors, Test dynamic/side-effects
6. **Hvorfor ikke alle quality attributes?** - Tradeoffs nødvendige
7. **Hvad er V-model?** - Relationship mellem test niveauer og development activities
8. **Agile testing quadrant?** - 2D kategorisering: Tech/Business facing × Support/Critique
9. **Agile practices for V&V?** - DoD, Sprint Review, Check before check-in, Never break build, Fix when see, Quality culture, XP practices

## Fremlæggelsesstruktur (5 min)

1. **Intro** (20 sek) - Hvad er quality? 3 typer, quality attributes
2. **QA vs QC** (40 sek) - Prevention vs Detection, Cost of quality
3. **Verification vs Validation** (40 sek) - Building right vs right system
4. **V-Model** (40 sek) - Test niveauer mapped til development
5. **Agile Testing Quadrant** (50 sek) - 4 quadrants med eksempler
6. **Agile Quality Practices** (1 min) - DoD, quality culture, TDD
7. **Refactoring** (30 sek) - Hvad, hvornår, fordele
8. **Afrunding** (10 sek) - Quality through process improvement
