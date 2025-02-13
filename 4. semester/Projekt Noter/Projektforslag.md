
## Pipebaseret baseret domæne sprog til databehandling

Løsningen køres direkte på maskinekode, derfor meget effektivt sammenlignet med andre løsninger til databehandling.

Det er nemt og enkelt at finde ud af.

`read_csv("borger.csv")` 
`| filter(column="alder", operator=">", value=30)` 
`| sort(column="navn")` 
`| write_csv("resultat.csv")`


``call_api(url="https://api.com/data", method="GET")` 
`| filter(column="status", operator="==", value="aktiv")` 
`| sort(column="dato")` 
`| write_csv("api_data.csv")`

Alternativer:
Pandas
dplyr (R)
SQL
Rust, compiler til direkte maskienkode

PicLang

## Simpelt matematik program

Super simpelt matematik program, der skal køre meget hurtigt. Hurtigere end Rust og meget hurtigere end R



## Sprog til læring med hot-reload.

Et simpelt sprog, hvor man kan se ændringer med det samme og få feedback på ens fejl. Det skal køre hurtigt, da man hurtigt skal kunne lave ændringer uden at vente.


## Prototyping-sprog med fokus på funktionelle API'er



## Chatbot progammeringssprog

Skal bruges til at kunne skabe egen chatbot med hurtigt svar tilbage. 