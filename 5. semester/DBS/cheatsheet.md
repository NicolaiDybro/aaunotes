
| Symbol | Navn (engelsk)         | Betydning                          | SQL-ækvivalent  |          |
| ------ | ---------------------- | ---------------------------------- | --------------- | -------- |
| σ      | Selection              | Vælger rækker ud fra en betingelse | WHERE           |          |
| π      | Projection             | Vælger kolonner                    | SELECT kolonner |          |
| γ      | Grouping / Aggregation | Gruppering og aggregatfunktioner   | GROUP BY        | for each |
| ⋈      | Join                   | Kombinerer tabeller                | JOIN ... ON     |          |
| ρ      | Renaming               | Omdøber relation/attributter       | AS              |          |

| Funktion | Navn | Hvad gør den? | Eksempel (intuition) |
|--------|------|---------------|----------------------|
| sum(x) | Sum | Lægger alle værdier sammen | sum(price) → total pris |
| max(x) | Maximum | Finder den største værdi | max(score) → højeste score |
| min(x) | Minimum | Finder den mindste værdi | min(age) → yngste alder |
| count(x) | Count | Tæller antal værdier (ikke-NULL) | count(patient_id) → antal patienter |
| count(*) | Count all | Tæller antal rækker | count(*) → antal tuples |
| avg(x) | Average | Finder gennemsnittet | avg(score) → gennemsnitlig score |

# vigtige kommandoer
`SELECT ln(2.0)` natural log of 2
`SELECT log(2.0, 64.0)` log base 2 of 64
`SELECT count(*)` antal rækker
`SELECT ceil(12094.0/64)`  korrekt beregning


12094 sider / 64 ≈ 189 runs 
3 / 63 = 1 run
I/O pr. pass = 2 × N
2 × 12094 = 24188
24188 × 3 = 72564

Cost = |Outer| + |Outer| × |Inner|


