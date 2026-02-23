# Eksamen 5 - Product Planning and Refinement

## Project vs Product

| Aspekt           | Project                                    | Product                                                             |
| ---------------- | ------------------------------------------ | ------------------------------------------------------------------- |
| **Leverancer**   | Én gang (A → B)                            | Løbende (A → ∞)                                                     |
| **Fokus**        | Verification (alle krav implementeret)     | Validation (fit for use)                                            |
| **Aktiviteter**  | Primært Specification, Design, Development | Alle: Specification, Design, Development, **Validation, Evolution** |
| **Requirements** | Established up-front                       | Emergent, løbende opdateret                                         |
| **Planning**     | Detailed long-term                         | Shorter and rolling                                                 |
| **Changes**      | Dyre og undgås                             | Forventede og velkommen                                             |

## Requirements i Product Development

### Hvornår Etableres Requirements?
- **Project:** Up-front i requirements fase
- **Product:** Løbende gennem product lifetime

### Hvor Ofte Justeres Requirements?
- **Project:** Sjældent, med streng change control
- **Product:** Kontinuerligt, hver sprint/iteration

### Hvad Driver Changes?
- **Project:** Scope changes, discovered issues
- **Product:** Market feedback, user learning, competition, technology evolution

## 10 Principper for Agile Product Teams

1. **Product manager er product owner**
2. **Product planning er kortere og rolling**
3. **Design som del af backlog refinement**
4. **Design i små og uafhængige chunks**
5. **Erstat requirements docs med prototypes & user stories**
6. **Lad teamet chunke funktionalitet i sprints**
7. **Socialiser og kommunikér mellem team, PO og andre**
8. **Product increments releases til users når tilstrækkelig funktionalitet**
9. **Demo current state hver sprint**
10. **Træn folk i agile**

## Product Vision

### Hvad er Product Vision?
- High-level beskrivelse af produktets mål
- Guiding star for teamet
- Besvarer: Hvorfor bygger vi dette?

### Elevator Pitch Template
```
For <target customer/user>
who <statement of need>
the <product name>
is a <product category>
that provides these <key benefits>
unlike <primary competition>
our product <is different in these ways>
```

**Eksempel:**
```
For busy professionals
who need to track their expenses
the ExpenseTracker
is a mobile app
that provides automatic receipt scanning and categorization
unlike Quickbooks
our product focuses on simplicity and mobile-first experience
```

### Product Vision Karakteristika
- Kort og memorabel
- Inspirerende
- Shared understanding i teamet
- Stable (ændrer sig ikke ofte)

## Product Roadmap (Pichler)

### Hvad er en Roadmap?
- High-level plan for product evolution
- Viser timeline og major features/themes
- Strategisk dokument

### Elementer i Roadmap:
- **Timeline** - Tidshorisont (quarters, months)
- **Themes/Epics** - Større feature areas
- **Goals** - Hvad ønsker vi at opnå
- **Releases** - Planned release points

### Typer af Roadmaps:
1. **Timeline-based** - Bundet til datoer
2. **Theme-based** - Organiseret efter temaer
3. **Outcome-based** - Fokuseret på outcomes frem for features

### Roadmap er IKKE:
- En forpligtelse til specifikke features på specifikke datoer
- Detaljeret requirements document
- Uforanderlig

## User Stories

### Format
```
As a <type of user>
I can <immediate goal>
so that <reason>
```

**3 C's:**
- **Card** - Skrevet på kort
- **Conversation** - Placeholder for samtale
- **Confirmation** - Acceptance criteria på bagsiden

### INVEST Criteria
- **I**ndependent - Kan udvikles uafhængigt
- **N**egotiable - Ikke en kontrakt, åben for diskussion
- **V**aluable - Giver værdi til bruger
- **E**stimable - Kan estimeres
- **S**mall - Kan færdiggøres i én sprint
- **T**estable - Kan testes

### Story Splitting
Når stories er for store:
- Split by workflow steps
- Split by business rules
- Split by data variations
- Split by operations (CRUD)
- Spike for learning

## Personas (Roman Pichler)

### Hvad er en Persona?
- Fiktiv repræsentation af en user type
- Baseret på research og data
- Hjælper med empati og focus

### Persona Skal Indeholde:
1. **Navn og billede** - Gør det personligt
2. **Demografi** - Alder, job, etc.
3. **Adfærd og karakteristika** - Hvordan bruger de tech?
4. **Behov og mål** - Hvad vil de opnå?
5. **Frustrationer** - Pain points
6. **Kontekst** - Hvor og hvordan bruger de produktet?

### Brug af Personas:
- Reference i user stories: "As Sarah (the busy mom)..."
- Validering: "Would Sarah do this?"
- Prioritering: "Which persona benefits most?"

## Product Backlog

### Hvad er Product Backlog?
- Ordered liste af alt hvad der kunne være i produktet
- Single source of truth for requirements
- Living document

### Indhold:
- User stories
- Features
- Bug fixes
- Technical debt items
- Research spikes
- Enabling stories (infrastructure, etc.)

### Ordering Faktorer:
- Business value
- Risk
- Dependencies
- Learning value
- Effort

### Backlog Refinement (Grooming)
**Hvornår:** ~10% af teamets tid hver sprint
**Deltagere:** PO + Development Team
**Aktiviteter:**
- Tilføj detaljer til stories
- Estimering (Planning Poker)
- Opdeling af store items
- Reordering
- Sikre top items er "Ready"

### Definition of Ready (DoR)
Hvornår er en story klar til sprint?
- User story written
- Acceptance criteria defined
- Estimated
- Dependencies identified
- Small enough (fits in one sprint)
- Testable

## User Story Mapping (Jeff Patton)

### Hvad er Story Mapping?
- Visual teknik til at strukturere backlog
- 2D representation
- Horisontal: User journey
- Vertikal: Prioritering/releases

### Story Map Process:

#### 1. Frame
**The Big Story:**
- What are we building?
- Who is it for?
- Why are we building it?

#### 2. Map the Big Picture
**Backbone:**
- Identificer activities (store user mål)
- Identificer high-level tasks
- Sortér left-to-right i user journey

**Eksempel (Shopping app):**
```
Browse → Select → Purchase → Receive → Review
```

#### 3. Explore
**Breakdown:**
- Break hver task ned i subtasks
- Tilføj detaljer
- Stories hænger under tasks

#### 4. Slice Out Viable Releases
**Walking Skeleton:**
- Første release: Minimal viable product
- Tværgående slice gennem alle activities
- Named outcomes
- Success metrics

**Releases:**
- **Opening Game** - MVP, core value
- **Mid Game** - Competitive features
- **End Game** - Delight features

#### 5. Development Strategy
- Identificér technical enabling work
- Dependencies
- Risks

### Benefits af Story Mapping:
- Shared understanding
- Visualiserer "hele billedet"
- Hjælper med prioritering
- Identificerer gaps
- Release planning

## Sprint Planning

### Input:
- Product Backlog (prioriteret og refined)
- Team velocity
- Team capacity for sprint
- Definition of Done

### Output:
- Sprint Goal
- Sprint Backlog (selected items + plan)

### Forecast:
Baseret på velocity kan team forecaste:
- **Fixed scope:** "Hvornår er vi færdige?"
- **Fixed time:** "Hvor meget kan vi nå?"

## The Iron Triangle

**Trade-off mellem:**
- **Scope** - Features
- **Time** - Deadline
- **Resources** - Team size, budget

**I Agile:**
- Time og Resources er ofte fixed
- Scope er variable
- Quality er IKKE variable!

## Forecasting User Story Delivery

### Velocity-Based Forecasting
1. Mål historical velocity (story points per sprint)
2. Sum story points for remaining work
3. Beregn: Remaining points / Average velocity = Sprints left

### Monte Carlo Simulation
- Bruger historical velocity variation
- Giver sandsynlighedsfordeling for completion
- Mere realistisk end single number

### Cone of Uncertainty
- Estimates bliver mere præcise over tid
- Tidligt: ±4x
- Midtvejs: ±1.5x
- Sent: ±1.1x

## Product Planning Meetings

### Release Planning
**Hvornår:** Start af major release cycle
**Varighed:** 1-2 dage
**Deltagere:** Product team, stakeholders
**Output:** Release plan, roadmap update

### Backlog Refinement
**Hvornår:** Ongoing, ~10% af tid
**Varighed:** 1-2 timer per uge
**Deltagere:** PO + Team
**Output:** Refined stories, estimates

---

## Eksamensnoter - Vigtige Spørgsmål

1. **Requirements activities?** - Elicitation, Specification, Validation
2. **Steps i elicitation?** - Discovery, Classification, Categorization, Prioritization, Documentation
3. **Hvorfor er elicitation svært?** - Mange stakeholders, forskellige sprog, tacit knowledge
4. **Elicitation teknikker?** - Interview, Ethnography, Prototypes, Story mapping
5. **Hvordan dokumenteres requirements?** - Waterfall: Docs, Scrum: Product Backlog, XP: User stories
6. **Agile planning?** - Welcomes changes, prioritized backlog, continuous refinement
7. **Estimation metoder?** - Planning poker (experience), algorithmic models, velocity-based

## Fremlæggelsesstruktur (5 min)

1. **Intro** (20 sek) - Project vs Product forskellen
2. **Product Vision** (40 sek) - Elevator pitch, roadmap
3. **User Stories** (1 min) - Format, INVEST, personas
4. **Story Mapping** (1.5 min) - Process og benefits
5. **Product Backlog** (1 min) - Content, refinement, Definition of Ready
6. **Forecasting** (30 sek) - Velocity-based, iron triangle
7. **Afrunding** (10 sek) - Continuous planning er key
