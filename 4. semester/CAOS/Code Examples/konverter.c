//
// Created by Nicolai Dybro Jensen on 08/06/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int binaryToDecimal(const char* bin) {
    int decimal = 0;
    while (*bin) {
        decimal = decimal * 2 + (*bin++ - '0');
    }
    return decimal;
}


void decimalToBinary(int n, char* out) {
    int i = 0;
    char temp[64];

    do {
        temp[i++] = (n % 2) + '0';
        n /= 2;
    } while (n > 0);

    for (int j = 0; j < i; j++) {
        out[j] = temp[i - j - 1];
    }
    out[i] = '\0';
}

int hexToDecimal(const char* hex) {
    return (int)strtol(hex, NULL, 16);
}

void decimalToHex(int n, char* out) {
    sprintf(out, "%X", n);
}

void binaryToHex(const char* bin, char* out) {
    int dec = binaryToDecimal(bin);
    decimalToHex(dec, out);
}

void hexToBinary(const char* hex, char* out) {
    int dec = hexToDecimal(hex);
    decimalToBinary(dec, out);
}

void showMenu() {
    printf("\nKonverteringsprogram:\n");
    printf("1. Decimal → Binær og Hex\n");
    printf("2. Binær → Decimal og Hex\n");
    printf("3. Hex → Decimal og Binær\n");
    printf("0. Afslut\n");
    printf("Vælg: ");
}

int main() {
    int valg;
    char input[65], bin[65], hex[65];
    int dec;

    while (1) {
        showMenu();
        scanf("%d", &valg);
        getchar();

        switch (valg) {
            case 1:
                printf("Indtast decimal: ");
                scanf("%d", &dec);
                decimalToBinary(dec, bin);
                decimalToHex(dec, hex);
                printf("Binær: %s\n", bin);
                printf("Hex: %s\n", hex);
                break;
            case 2:
                printf("Indtast binær: ");
                scanf("%64s", input);
                dec = binaryToDecimal(input);
                decimalToHex(dec, hex);
                printf("Decimal: %d\n", dec);
                printf("Hex: %s\n", hex);
                break;
            case 3:
                printf("Indtast hex (uden 0x): ");
                scanf("%64s", input);
                dec = hexToDecimal(input);
                decimalToBinary(dec, bin);
                printf("Decimal: %d\n", dec);
                printf("Binær: %s\n", bin);
                break;
            case 0:
                printf("Farvel!\n");
                return 0;
            default:
                printf("Ugyldigt valg.\n");
        }
    }
}
