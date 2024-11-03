#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int bookID;
    char title[100];
    char author[50];
    int year;
    float price;
} Book;

Book *library = NULL;
int N = 0;

void loadBookData() {
    FILE *file = fopen("books.dat", "rb");
    if (file != NULL) {
        fread(&N, sizeof(int), 1, file);
        library = (Book*)malloc(N * sizeof(Book));
        fread(library, sizeof(Book), N, file);
        fclose(file);
        printf("Loaded %d books from books.dat\n", N);
    } else {
        printf("No existing data found.\n");
    }
}

void saveBookData() {
    FILE *file = fopen("books.dat", "wb");
    if (file != NULL) {
        fwrite(&N, sizeof(int), 1, file);
        fwrite(library, sizeof(Book), N, file);
        fclose(file);
        printf("Book data saved to books.dat\n");
    } else {
        printf("Error saving data.\n");
    }
}

void inputBookData() {
    library = (Book*)realloc(library, (N + 1) * sizeof(Book));
    Book newBook;
    printf("Enter book details:\n");
    printf("ID: ");
    scanf("%d", &newBook.bookID);
    printf("Title: ");
    getchar();
    fgets(newBook.title, 100, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';
    printf("Author: ");
    fgets(newBook.author, 50, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';
    printf("Year: ");
    scanf("%d", &newBook.year);
    printf("Price (SAR): ");
    scanf("%f", &newBook.price);
    library[N++] = newBook;
    saveBookData();
}

void displayBookData() {
    if (N == 0) {
        printf("No books in the library.\n");
        return;
    }
    for (int i = 0; i < N; i++) {
        printf("ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f SAR\n",
               library[i].bookID, library[i].title, library[i].author, library[i].year, library[i].price);
    }
}

void findBookByID() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < N; i++) {
        if (library[i].bookID == id) {
            printf("Book found:\n");
            printf("ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f SAR\n",
                   library[i].bookID, library[i].title, library[i].author, library[i].year, library[i].price);
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

void calculateTotalValue() {
    float total = 0;
    for (int i = 0; i < N; i++) {
        total += library[i].price;
    }
    printf("Total Value of Books: %.2f SAR\n", total);
}

int main() {
    int choice;
    loadBookData();
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for Book by ID\n");
        printf("4. Calculate Total Value of Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputBookData();
                break;
            case 2:
                displayBookData();
                break;
            case 3:
                findBookByID();
                break;
            case 4:
                calculateTotalValue();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    free(library);
    return 0;
}
