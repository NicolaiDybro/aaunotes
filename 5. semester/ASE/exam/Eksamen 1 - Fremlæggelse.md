1. **Hvad er Software Engineering (SE) et svar på?** SE er et svar på den stigende **kompleksitet** i software og den høje fejlrate i projekter. Det handler om at gå fra "tilfældig kodning" til en disciplineret, ingeniørmæssig tilgang for at sikre pålidelighed og økonomi.
    
2. **Hvad er de generiske proces-aktiviteter?**
    
    - **Specifikation:** Hvad skal systemet kunne?
        
    - **Design & Implementering:** Hvordan bygger vi det, og selve kodningen.
        
    - **Validering:** Tjek om det er det, kunden vil have.
        
    - **Evolution:** Ændringer og vedligeholdelse efter release.
        
3. **Hvad er en software-procesmodel?** En abstrakt repræsentation af en softwareproces. Det er et sæt af relaterede aktiviteter, der fører til et færdigt softwareprodukt.
    
4. **Karakteristika ved Waterfall-modellen?** En lineær model hvor aktiviteterne følger hinanden i faste faser. Der er formelle overleveringer (dokumentation) og milepæle mellem hver fase. Man går først videre, når den forrige fase er 100% færdig.
    

![Billede af the Waterfall model software development](https://encrypted-tbn2.gstatic.com/licensed-image?q=tbn:ANd9GcQIhYx_jfiIwWP35_LgzL-qavQ3uBgj06xHA7ez7Sw6cIXfS194E-qtk-IswNiVxenvX1HtA5zR4WLpIiDRgDQlBumFziU6D2rKmzMycnZ1nRkAzfg)

Shutterstock

Udforsk

5. **Karakteristika ved den inkrementelle/iterative model?** Man opdeler ("slicer") det store projekt i mindre bidder. Man udvikler en del af gangen, hvilket gør det muligt at lære og justere undervejs.
    
6. **Hvornår skal man bruge Waterfall?** Ved projekter med ekstremt lave tolerancegrader for fejl: Embedded systems (hardware/software kobling), livskritiske systemer (medicinsk udstyr/fly) eller meget store systemer, hvor mange teams skal koordinere præcist efter en fast plan.
    
7. **Hvordan vælger man mellem Waterfall og Inkrementel?** Ved at bruge **Boehm’s "Home Grounds"**. Man analyserer faktorer som: Er kravene stabile? Hvor stort er teamet? Er det kritisk software? Er kulturen til kaos eller orden?
    
8. **Hvordan fungerer den inkrementelle model (Plan-drevet vs. Iterativ)?** Den kan være begge dele. Man kan have en plan-drevet tilgang, hvor man på forhånd har planlagt, hvilke funktioner der kommer i hvilke inkrementer. Man kan også iterere _indeni_ hvert inkrement for at forfine designet.
    
9. **Fordele ved den inkrementelle/iterative model?**
    
    - Lavere omkostninger ved kravændringer.
        
    - Hurtigere feedback fra kunden.
        
    - Kunden får værdi tidligt (kan bruge de første funktioner, før hele systemet er færdigt).
        
10. **Ulemper?**
    
    - Processen er "usynlig" (svært for ledelsen at måle fremdrift uden tung dokumentation).
        
    - Systemets arkitektur (infrastruktur) kan blive dårligere (deteriorate) over tid, når man bliver ved med at "lappe" nye inkrementer på.
        

---

### **Eksamensoplæg: Software Process Models – Strategiske valg (5 minutter)**

#### **1. Problemet: "The Software Crisis" (Udfordringen)**

- **Problemet:** Software er komplekst, og krav ændrer sig næsten altid undervejs.
    
- **Hvorfor processer?** Hvis vi bare koder uden en model, mister vi kontrollen over tid, budget og kvalitet. En procesmodel er vores "køreplan" til at håndtere usikkerhed.
    

#### **2. Waterfall: Orden i kaos**

- **Beskrivelse:** En plan-drevet model hvor alt er defineret up-front.
    
- **Hvornår er det løsningen?** I situationer hvor vi _skal_ have ret første gang (f.eks. software til en pacemaker eller en satellit). Her er risikoen ved at fejle større end prisen for tung dokumentation.
    
- **Udfordringen:** Den er ufleksibel. Hvis kunden opdager en fejl i kravene halvvejs, er det ekstremt dyrt at gå tilbage.
    

#### **3. Inkrementel/Iterativ: Svaret på forandring**

- **Beskrivelse:** I stedet for én stor leverance til sidst, leverer vi i små bidder (inkrementer).
    
- **Værdien:** Det løser problemet med "forventningsafstemning". Kunden får værdi hurtigt, og vi kan bruge feedbacken til at rette kursen.
    
- **Balancen:** Man kan godt have en plan-drevet inkrementel model (hvor vi ved, hvad de næste 3 inkrementer er).
    

#### **4. Valget af model (Boehm’s Home Grounds)**

- **Analysen:** Vi vælger ikke model ud fra personlig smag, men ud fra projektets natur.
    
- **Parametre:**
    
    - _Stabilitet:_ Er kravene faste (Waterfall) eller flydende (Agile)?
        
    - _Kritikalitet:_ Dør der nogen, hvis det fejler (Waterfall)?
        
    - _Team:_ Har vi senior-udviklere, der trives med autonomi (Agile)?
        

#### **5. Afslutning: Ingen "Silver Bullet"**

- Ingen model er perfekt. Den inkrementelle model risikerer at ødelægge systemets struktur over tid (technical debt), mens Waterfall risikerer at levere det helt forkerte produkt for sent.
    
- **Konklusion:** En dygtig software engineer forstår at vælge den proces, der minimerer de største risici for det specifikke projekt.