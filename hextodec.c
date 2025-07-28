#include <stdio.h>
#include <math.h>

int hexToDecimal(const char hex[]) {
    int length = 0;
    while (hex[length] != '\0') {
        length++;
    }

    int decimal = 0;
    int base = 0;

    for (int i = length - 1; i >= 0; i--) {
        char digit = hex[i];
        int value;

        if (digit >= '0' && digit <= '9') {
            value = digit - '0';
        } else if (digit >= 'A' && digit <= 'F') {
            value = digit - 'A' + 10;
        } else if (digit >= 'a' && digit <= 'f') {
            value = digit - 'a' + 10;
        } else {
            printf("Invalid hexadecimal digit: %c\n", digit);
            return -1;
        }

        decimal += value * pow(16, base);
        base++;
    }

    return decimal;
}

void decimalToHex(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }

    char hexDigits[20];  
    int index = 0;

    while (decimal > 0) {
        int remainder = decimal % 16;

        if (remainder < 10)
            hexDigits[index] = '0' + remainder;
        else
            hexDigits[index] = 'A' + (remainder - 10);

        index++;
        decimal /= 16;
    }

    
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexDigits[i]);
    }
}

int main() {
    char hex[20];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    int result = hexToDecimal(hex);

    
        printf("Decimal equivalent: %d\n", result);
        printf("Converted back to Hex: ");
        decimalToHex(result);
        printf("\n");
    

    return 0;
}
