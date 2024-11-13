#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    printf("1. Binary to Decimal\n2. Decimal to Binary\n3. Decimal to Octal\n4. Octal to Decimal\n5. Decimal to Hexadecimal\n6. Hexadecimal to Decimal\n");
    int choice, decimal;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int size;
        printf("Enter the size of the binary number: ");
        scanf("%d", &size);
        int binary[size];
        printf("Enter the binary number (space-separated digits): ");
        for (int i = 0; i < size; i++) {
            scanf("%d", &binary[i]);
        }
        int decimal = 0;
        for (int i = 0; i < size; i++) {
            if (binary[size - i - 1] == 1) {
                decimal += pow(2, i);
            }
        }
        printf("The decimal equivalent is: %d\n", decimal);
    } else if (choice == 2) {
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        int binary[100];
        int n = decimal;
        int counter = 0;
        while (n != 0) {
            binary[counter] = n % 2;
            counter++;
            n = n / 2;
        }
        printf("The binary equivalent is: ");
        for (int i = counter - 1; i >= 0; i--) {
            printf("%d", binary[i]);
        }
        printf("\n");
    } else if (choice == 3) {
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        int octal[100];
        int n = decimal;
        int counter = 0;
        while (n != 0) {
            octal[counter] = n % 8;
            counter++;
            n = n / 8;
        }
        printf("The octal equivalent is: ");
        for (int i = counter - 1; i >= 0; i--) {
            printf("%d", octal[i]);
        }
        printf("\n");
    } else if (choice == 4) {
        int size;
        printf("Enter the size of the octal number: ");
        scanf("%d", &size);
        int octal[size];
        printf("Enter the octal number (space-separated digits): ");
        for (int i = 0; i < size; i++) {
            scanf("%d", &octal[i]);
        }
        int decimal = 0;
        for (int i = 0; i < size; i++) {
            decimal += octal[size - i - 1] * pow(8, i);
        }
        printf("The decimal equivalent is: %d\n", decimal);
    } else if (choice == 5) {
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        char hexadecimal[100];
        int n = decimal;
        int counter = 0;
        while (n != 0) {
            int remainder = n % 16;
            if (remainder < 10) {
                hexadecimal[counter] = '0' + remainder;
            } else if (remainder == 10) {
                hexadecimal[counter] = 'A';
            } else if (remainder == 11) {
                hexadecimal[counter] = 'B';
            } else if (remainder == 12) {
                hexadecimal[counter] = 'C';
            } else if (remainder == 13) {
                hexadecimal[counter] = 'D';
            } else if (remainder == 14) {
                hexadecimal[counter] = 'E';
            } else if (remainder == 15) {
                hexadecimal[counter] = 'F';
            }
            counter++;
            n = n / 16;
        }
        printf("The hexadecimal equivalent is: ");
        for (int i = counter - 1; i >= 0; i--) {
            printf("%c", hexadecimal[i]);
        }
        printf("\n");
    } else if (choice == 6) {
        char hex[100];
        printf("Enter a hexadecimal number: ");
        scanf("%s", hex);
        int decimal = 0;
        int base = 1;
        for (int i = strlen(hex) - 1; i >= 0; i--) {
            if (hex[i] >= '0' && hex[i] <= '9') {
                decimal += (hex[i] - '0') * base;
            } else if (hex[i] >= 'a' && hex[i] <= 'f') {
                decimal += (hex[i] - 'a' + 10) * base;
            } else if (hex[i] >= 'A' && hex[i] <= 'F') {
                decimal += (hex[i] - 'A' + 10) * base;
            }
            base *= 16;
        }
        printf("The decimal equivalent is: %d\n", decimal);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
