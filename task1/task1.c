#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
    
}Student;

void insert(Student std[], int n){
    for(int i = 0; i < n; i++){
        printf("Enter ID for student %d: ", i+1);
        scanf("%d", &std[i].id);
        getchar();
        printf("Enter name for student %d: ", i+1);
        scanf("%[^\n]s", std[i].name);
        getchar();
        printf("Enter GPA for student %d:  ", i+1);
        scanf("%f", &std[i].gpa);
    }
}
void display(Student std[], int n){
    printf("\nStudent Records:\n");
    for(int i = 0; i < n; i++){
        printf("ID: %d, Name: %s, GPA: %.2f\n", std[i].id, 
        std[i].name, std[i].gpa);
    }
}
int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    Student *std = (Student*)malloc(n * sizeof(Student));
    if(std != NULL){
	insert(std, n);
    	display(std, n);
    	free(std);
    }
    return 0;
}
