# Bit-shifting (Skiftning)

Bit-shifting er en operation, hvor alle bit i et tal flyttes enten til venstre eller højre i en binær repræsentation.

## Typer af bit-shift

### Venstreskift (`<<`)

- Flytter alle bit til venstre og fylder de tomme pladser med nuller.
- Multiplicerer tallet med 2 for hver skiftning.
- Eksempel:
  
  ```c
  5 << 1  // 5 (0101) bliver til 10 (1010)
  ```

### Højreskift (`>>`)
- Flytter alle bit til højre.
- **Arithmetisk højreskift** (beholder fortegnet) fylder de tomme pladser med kopi af fortegnsbitten (MSB).
- **Logisk højreskift** fylder altid nuller i de tomme pladser.
- Højreskift dividerer typisk tallet med 2 pr. skift.
- Eksempel:
  
  ```c
  8 >> 1  // 8 (1000) bliver til 4 (0100)
  ```

## Anvendelser af bit-shifting
- Hurtig multiplikation/division med 2
- Maskering af bit
- Manipulation af flags i systemprogrammering
- Effektiv kodning af algoritmer

Bit-shifting er særligt nyttigt i systemprogrammering, embedded systemer og optimeret kode.

## Eksempel på praktisk anvendelse
### Kontrollere om et tal er lige eller ulige
Bit-shifting kan bruges til hurtigt at kontrollere, om et tal er lige eller ulige ved at se på den mindst signifikante bit.

```c
#include <stdio.h>

void check_even_or_odd(int num) {
    if (num & 1) {
        printf("%d er ulige\n", num);
    } else {
        printf("%d er lige\n", num);
    }
}

int main() {
    check_even_or_odd(10); // Udskriver: 10 er lige
    check_even_or_odd(7);  // Udskriver: 7 er ulige
    return 0;
}
```

### Opgaveeksempler
#### Opgave 1: Manuel bit-shifting
Givet tallet `13` (binært `1101`), skift det én gang til venstre. Hvad bliver resultatet i binær og decimal?

**Løsning:**
- `1101` bliver til `11010` (decimal: `26`).

#### Opgave 2: Manuel højreskift
Givet tallet `40` (binært `101000`), skift det to gange til højre. Hvad bliver resultatet i binær og decimal?

**Løsning:**
- `101000` → `001010` → `000101` (decimal: `10`).

#### Opgave 3: Multiplikation med 8 ved bit-shifting
Givet et heltal `n`, beregn `n * 8` ved at bruge bit-shifting. Skriv resultatet for `n = 3` og `n = 7`.

**Løsning:**
- `n << 3` (skifter 3 gange til venstre, da `2^3 = 8`)
- `3 << 3` → `24`
- `7 << 3` → `56`

Disse øvelser hjælper med at forstå, hvordan bit-skiftning kan bruges til hurtige beregninger!





# Floating-Point (Flydende Komma Tal)

Flydende kommatal bruges til at repræsentere reelle tal i computere ved hjælp af en tilnærmelse. De er nyttige, når heltal ikke er tilstrækkelige.

## IEEE 754 Standard
Den mest anvendte standard for flydende kommatal er **IEEE 754**, som definerer formater som:
- **32-bit (single precision)**
- **64-bit (double precision)**

### Struktur af et flydende kommatal
Et flydende kommatal består af:
1. **Fortegn-bit (1 bit):** Angiver positiv (0) eller negativ (1).
2. **Eksponent (8 bit i single, 11 bit i double):** Angiver skalering af tallet.
3. **Mantisse (23 bit i single, 52 bit i double):** Indeholder selve tallets præcision.

Forholdet kan udtrykkes som:
```
Værdi = (-1)^fortegn × 1.mantisse × 2^(eksponent - bias)
```
Hvor **bias** er 127 for single precision og 1023 for double precision.

## Designkriterier og begrænsninger
- Flydende kommatal er nyttige i videnskabelige beregninger og simuleringer.
- **IKKE** velegnet til finansielle beregninger (kr./øre), da de ikke er præcise nok.
- Kan håndtere meget store og meget små tal, men med begrænset præcision.
- Hardware skal kunne håndtere flydende komma effektivt.

## Præcision og afrundingsfejl
- Flydende kommatal kan ikke altid repræsentere tal præcist, hvilket fører til afrundingsfejl.
- Eksempel: `0.1` kan ikke repræsenteres nøjagtigt i binær, hvilket kan føre til akkumulerede fejl i beregninger.
- Afrunding følger typisk "nærmeste-lige" metode, hvor værdier afrundes til nærmeste lige tal.

## Specielle værdier
IEEE 754 definerer også særlige værdier:
- **±0** (positiv og negativ nul)
- **±∞** (positiv og negativ uendelighed)
- **NaN** (Not a Number, bruges til ugyldige operationer som `0/0`).
- **Denormaliserede tal**, der bruges til at repræsentere meget små tal med reduceret præcision.

## Matematiske egenskaber og begrænsninger
- Addition og multiplikation er **ikke** altid associative eller distributive.
  - `(3.14 + 1e10) - 1e10 != 3.14 + (1e10 - 1e10)`
- Overløb kan resultere i **∞**.
- Afrundingsfejl kan akkumuleres og føre til upræcise resultater over tid.






| Operator | Symbol | Navn            | Forklaring                                       | Eksempel (bitvis på 1 og 0) | Resultat                    |
| -------- | ------ | --------------- | ------------------------------------------------ | --------------------------- | --------------------------- |
| AND      | `&`    | Bitvis OG       | Giver 1 kun hvis begge bits er 1                 | 1 & 1                       | 1                           |
|          |        |                 |                                                  | 1 & 0                       | 0                           |
| OR       | `\|`   | Bitvis ELLER    | Giver 1 hvis mindst én af bits er 1              | 1 \| 0                      | 1                           |
|          |        |                 |                                                  | 0 \| 0                      | 0                           |
| XOR      | `^`    | Eksklusiv ELLER | Giver 1 kun hvis bits er forskellige             | 1 ^ 0                       | 1                           |
|          |        |                 |                                                  | 1 ^ 1                       | 0                           |
| NOT      | `~`    | Bitvis IKKE     | Inverterer alle bits (0 bliver 1, og 1 bliver 0) | ~1                          | 0 (men husk: to-komplement) |
| NAND     | -      | IKKE OG         | Inverteret AND: Giver 0 kun hvis begge er 1      | NOT(1 & 1)                  | 0                           |
| NOR      | -      | IKKE ELLER      | Inverteret OR: Giver 1 kun hvis begge er 0       | NOT(1 \| 0)                 | 0                           |






## Eksempler og opgaver
### Eksempel: Binære brøker
Binære tal kan repræsentere nogle rationelle tal præcist, men ikke alle:
- `5.75` i binær er `101.11`
- `1/3` i binær er `0.0101010101...` (uendeligt gentaget mønster)

### Opgave 1: Konvertering til flydende kommatal
Givet tallet `5.75`, find dets IEEE 754 single precision-repræsentation.

**Løsning:**
4. `5.75` i binær er `101.11`.
5. Normaliser til `1.0111 × 2^2`.
6. Eksponentfelt = `2 + 127 = 129` → `10000001`.
7. Mantisse = `01110000000000000000000`.
8. Fortegn-bit = `0`.
9. Samlet repræsentation: `0 10000001 01110000000000000000000`.

### Opgave 2: Præcisionsproblem
Hvorfor giver `0.1 + 0.2` ofte ikke præcist `0.3` i en computer?

**Løsning:**
- `0.1` og `0.2` har uendelige binære repræsentationer.
- De afrundes i hukommelsen, hvilket fører til en lille fejl.
- Derfor kan `0.1 + 0.2` give `0.30000000000000004` i stedet for præcist `0.3`.

### Opgave 3: Overløbsfejl i praksis
Hvad sker der, hvis vi konverterer et 64-bit floating-point tal til et 16-bit signed integer?

**Hint:**
- Dette skete med **Ariane 5**, hvor en fejl i konverteringen førte til et raketnedbrud til en værdi af 500 millioner euro!

Flydende kommatal er vigtige for numeriske beregninger, men kræver forståelse af præcision og fejl!




