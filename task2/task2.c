#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int CountWords(FILE* ptr){
    ptr = fopen("task2test.txt", "r");
    if (!ptr) {
        printf("Error: file did not open!\n");
        exit(1);
    }
    int word = 0;
    int flag = 1;
    char temp;
    while ((temp = fgetc(ptr)) != EOF) {
        if (isspace(temp)) {
            if (flag) {
                word++;
                flag = 0;
            }
        } else {
            flag = 1;
        }
    }

    if (flag) {
        word++;
    }
    fclose(ptr);
    return word;
}

int CountLines(FILE* ptr){
    ptr = fopen("task2test.txt", "r");
    if (!ptr) {
        printf("Error: file did not open!\n");
        exit(1);
    }
    int line = 0;
    char temp;
    while ((temp = fgetc(ptr)) != EOF) {
        if (temp == '\n') {
            line++;
        }
    }
    fclose(ptr);
    return line;
}

int CountCharacters(FILE* ptr){
    ptr = fopen("task2test.txt", "r");
    if (!ptr) {
        printf("Error: file did not open!\n");
        exit(1);
    }
    int character = 0;
    char temp;
    while ((temp = fgetc(ptr)) != EOF) {
        character++;
    }
    fclose(ptr);
    return character;
}

int main(){
    FILE *ptr = fopen("task2test.txt", "r");
    if (!ptr) {
        printf("Error: file did not open!\n");
        exit(1);
    }
    printf("Lines: %d\n", CountLines(ptr));
    printf("Characters: %d\n", CountCharacters(ptr));
    printf("Words: %d\n", CountWords(ptr));

    fclose(ptr);
    return 0;
}
