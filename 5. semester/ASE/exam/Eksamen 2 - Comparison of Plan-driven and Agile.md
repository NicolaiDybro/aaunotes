1. **Hvad er forskellen?** Plan-driven (f.eks. Waterfall) forsøger at forudsige det endelige resultat og lægge en fast plan for at nå dertil. Agile forventer forandring og bruger hyppige inspektioner og tilpasninger for at skabe mest mulig værdi løbende.
    
2. **Böehm og Turners primære faktorer for Agile:**
    
    - **Application:** Små projekter, hurtige ændringer, turbulente omgivelser.
        
    - **Management:** Kunden er "on-site", kvalitetskontrol er kvalitativ, og man stoler på "tavs viden" (tacit knowledge).
        
    - **Technical:** Prioriterede uformelle krav (User Stories) og simpelt design.
        
    - **People:** Kræver dygtige udviklere (Cockburn L2/L3), der kan arbejde autonomt.
        
3. **Hvad betyder de 5 akser i Home Ground-værktøjet?** Værktøjet bruges til at vælge metode baseret på:
    
    - **Personnel:** Udviklernes erfaringsniveau.
        
    - **Criticality:** Konsekvensen ved fejl (tab af liv vs. tab af komfort).
        
    - **Size:** Antal personer i projektet.
        
    - **Culture:** Præferencen for orden (plan-driven) eller kaos/frihed (agile).
        
    - **Dynamism:** Hvor ofte kravene ændrer sig.
        
4. **Hvorfor ændrer krav sig?** På grund af ændringer i forretningen (markedet), ny teknologi, eller fordi kunden lærer mere om deres egne behov, når de ser de første iterationer af produktet.
    
5. **CI vs. Prototyper:****Continuous Integration (CI)** sørger for, at man altid har et kørbart, leveringsklart produkt. En **prototype** er derimod noget, man typisk "smider væk" (discard), efter man har lært det, man skulle bruge den til.
    
6. **XP-praksisser:** Customer on site, Pair programming, Planning game, Test-Driven Development (TDD), Continuous Integration, Sustainable pace.
    
7. **Roller (Scrum vs. Plan-driven):**
    
    - **Scrum:** Kun tre roller: Product Owner, Scrum Master og Teamet.
        
    - **Plan-driven:** Mange specialiserede roller (Project Managers, Business Analysts, Testers, Architect osv.).
        
8. **Scrum-praksisser:** Sprint Planning, Daily Scrum, Sprint Review, Sprint Retrospective og Backlog Refinement.
    
9. **Artefakter (Agile vs. Plan-driven):**
    
    - **Agile:** Product/Sprint Burndown charts, Scrum board, Product Backlog.
        
    - **Plan-driven:** Projektplan, Gantt-kort, kravspecifikationer (SRS).
        
10. **Plan-driven modstykker (Tankesæt):** Forudsige hvad der skal leveres, planlægge arbejdet, udføre planen ("work the plan"), og dele viden via dokumentation fremfor dialog.
    

---

### **Eksamensoplæg: Plan-driven vs. Agile – Valget af strategi (5 minutter)**

#### **1. Problemet: Usikkerhed og forandring**

- **Problemet:** Traditionel softwareudvikling (Plan-driven) antager, at vi kan kende alle behov i starten. Men virkeligheden er ofte præget af "turbulens" – markeder flytter sig, og teknik fejler.
    
- **Konsekvens:** Hvis vi bruger en plan-drevet model i et dynamisk miljø, ender vi med at levere et produkt, der overholder planen, men som ingen vil have.
    

#### **2. Agile som svar på turbulens**

- **Filosofi:** I stedet for at bekæmpe forandring, byder vi den velkommen.
    
- **Værktøjer:** Scrum og XP (Extreme Programming).
    
- **XP-eksempel:** **Pair Programming** og **TDD** (Test-Driven Development) løser problemet med lav kodekvalitet og videntab, da to hoveder altid ser på koden.
    

#### **3. Hvornår skal vi vælge hvad? (Boehm's Home Grounds)**

- Det er en fejl at tro, at Agile altid er bedst. Vi skal analysere vores **"Home Ground"**:
    
    - **Criticality:** Hvis vi bygger software til en flyvemaskine, har vi brug for den orden og dokumentation, plan-driven giver.
        
    - **Dynamism:** Hvis vi bygger en web-app, hvor kravene skifter hver uge, er Agile overlegen.
        
- **Pointen:** Valget af metode er en ingeniørmæssig beslutning baseret på fakta (de 5 akser), ikke personlig holdning.
    

#### **4. Tekniske løsninger: CI og Værdi**

- **Continuous Integration (CI):** Løser problemet med "integration hell" ved altid at have et produkt, der er klar til brug.
    
- **Hurtig feedback:** I Agile får kunden værdi hver 2.-4. uge (Sprint Review), hvilket minimerer risikoen for at bygge det forkerte.
    

#### **5. Afslutning: Fra Dokumentation til Dialog**

- Den største forskel ligger i, hvordan vi deler viden. Plan-driven bruger dokumenter; Agile bruger **interactions** (Daily Scrum, Pair Programming).
    
- **Konklusion:** Succes afhænger af at matche procesmodellen med projektets omgivelser. En "mis-match" er en af de største risici i software engineering.