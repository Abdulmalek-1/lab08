#include <stdio.h>
#include <stdlib.h>

void conversion(char binary[], char hexa[]) {
    int first_half = (binary[3] - '0') * 8 + (binary[2] - '0') * 4 +
                     (binary[1] - '0') * 2 + (binary[0] - '0');
    if (first_half < 10) 
        hexa[0] = first_half + '0';
    else 
        hexa[0] = first_half - 10 + 'A';

    int second_half = (binary[7] - '0') * 8 + (binary[6] - '0') * 4 +
                      (binary[5] - '0') * 2 + (binary[4] - '0');
    if (second_half < 10) 
        hexa[1] = second_half + '0';
    else 
        hexa[1] = second_half - 10 + 'A';

    hexa[2] = '\0'; 
}

void Bin2Hexa() {
    FILE* ptr1 = fopen("/home/it/chip_design/CommonCore/ProblemSolving/lab08/task3/bitstream.bit", "r");
    if (!ptr1) {
        printf("Error: file did not open!\n");
        exit(1);
    }
    
    FILE* ptr2 = fopen("/home/it/chip_design/CommonCore/ProblemSolving/lab08/task3/bitstream.hex", "w");
    if (!ptr2) {
        printf("Error: output file did not open!\n");
        fclose(ptr1);
        exit(1);
    }
    
    char binary[8];
    char hexa[3];
    int count = 0;
    int i = 0;
    char temp;

    while ((temp = fgetc(ptr1)) != EOF) {
        if(temp != '\n'){
            binary[i++] = temp;
            count++;

            if (count == 8) {
                conversion(binary, hexa);
                fprintf(ptr2, "%s\n", hexa);
                count = 0;
                i = 0;
            }
        }
    }
    if(count != 0){
        while(i < 8){
            binary[i++] = '0';
        }
        conversion(binary, hexa);
        fprintf(ptr2, "%s\n", hexa);
    }
    fclose(ptr1);
    fclose(ptr2);
}

int main() {
    Bin2Hexa();
    return 0;
}
