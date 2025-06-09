

| Værktøj    | Eksempel              | Forklaring                                                                   |
| ---------- | --------------------- | ---------------------------------------------------------------------------- |
| `gcc`      | `gcc main.c -o main`  | Kompilerer C-kode til en eksekverbar binærfil.                               |
| `hexdump`  | `hexdump -C main`     | Viser indholdet af en fil i hexadecimal og ASCII for at analysere bytes.     |
| `gobjdump` | `gobjdump -d main`    | Disassemblerer en binær og viser assemblerkode for at analysere programflow. |
| `gnm`      | `gnm main`            | Viser symboltabellen (funktioner, globale variable, osv.) i en binær.        |
| `strings`  | `strings main`        | Udtrækker sekvenser af læsbar tekst fra en binærfil.                         |
| `make`     | `make`                | Automatiserer bygning af programmer ud fra en Makefile.                      |
| `ld`       | `ld -o main main.o`   | Linker objektfiler sammen til én eksekverbar fil.                            |
| `as`       | `as -o main.o main.s` | Assemblerer en `.s`-fil (assemblerkode) til en `.o`-fil (objektfil).         |
| `file`     | `file main`           | Viser hvilken type fil det er (tekst, binær, Mach-O, ELF, osv.).             |
| `lsof`     | `lsof -p 12345`       | Viser hvilke filer og netværksforbindelser en proces bruger.                 |
| `otool`    | `otool -tV main`      | macOS-specifikt: viser assemblerkode og sektioner fra Mach-O binærer.        |


Det her kan bruges til at simulere x86_64
clang -target x86_64-apple-macos -o program_x86 konverter.c
