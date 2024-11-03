#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SHIFT 3
#define MAX_TEXT_LENGTH 100

void encrypt(char *plaintext, int k, char *ciphertext) {
    int i = 0;
    while (plaintext[i] != '\0') {
        char c = plaintext[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base - k + 26) % 26 + base;
        }
        ciphertext[i] = c;
        i++;
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, int k, char *plaintext) {
    int i = 0;
    while (ciphertext[i] != '\0') {
        char c = ciphertext[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + k + 26) % 26 + base;
        }
        plaintext[i] = c;
        i++;
    }
    plaintext[i] = '\0';
}

void encryptToFile(const char *filename, int shift) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    FILE *outfile = fopen("encrypted.txt", "w");
    if (outfile == NULL) {
        printf("Error opening file for writing.\n");
        fclose(file);
        return;
    }

    char plaintext[MAX_TEXT_LENGTH];
    while (fgets(plaintext, sizeof(plaintext), file) != NULL) {
        char ciphertext[MAX_TEXT_LENGTH];
        encrypt(plaintext, shift, ciphertext);
        fprintf(outfile, "%s", ciphertext);
    }

    fclose(file);
    fclose(outfile);
    printf("Data encrypted and saved to encrypted.txt\n");
}

void decryptFromFile(const char *filename, int shift) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char ciphertext[MAX_TEXT_LENGTH];
    while (fgets(ciphertext, sizeof(ciphertext), file) != NULL) {
        char plaintext[MAX_TEXT_LENGTH];
        decrypt(ciphertext, shift, plaintext);
        printf("Decrypted data from the file: %s\n", plaintext);
    }

    fclose(file);
}

int main() {
    char option, method;
    char text[MAX_TEXT_LENGTH];
    char encrypted[MAX_TEXT_LENGTH];
    char decrypted[MAX_TEXT_LENGTH];
    int shift = SHIFT;

    printf("Welcome to the Caesar Cipher Program!\n");
    printf("Do you want to perform (E)ncryption or (D)ecryption? ");
    scanf(" %c", &option);

    if (option == 'E' || option == 'e') {
        printf("Do you want to encrypt data from a (F)ile or enter a (S)tring? ");
        scanf(" %c", &method);

        if (method == 'F' || method == 'f') {
            char filename[50];
            printf("Enter the filename to encrypt: ");
            scanf("%s", filename);
            encryptToFile(filename, shift);
        } else if (method == 'S' || method == 's') {
            printf("Please enter the string to encrypt: ");
            scanf(" %[^\n]", text);
            encrypt(text, shift, encrypted);
            printf("Encrypted string: %s\n", encrypted);
        } else {
            printf("Invalid option.\n");
        }
    } else if (option == 'D' || option == 'd') {
        printf("Do you want to decrypt data from a (F)ile or enter a (S)tring? ");
        scanf(" %c", &method);

        if (method == 'F' || method == 'f') {
            char filename[50];
            printf("Enter the filename to decrypt: ");
            scanf("%s", filename);
            decryptFromFile(filename, shift);
        } else if (method == 'S' || method == 's') {
            printf("Please enter the string to decrypt: ");
            scanf(" %[^\n]", text);
            decrypt(text, shift, decrypted);
            printf("Decrypted string: %s\n", decrypted);
        } else {
            printf("Invalid option.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
