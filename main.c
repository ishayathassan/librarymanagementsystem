/*  FOR ADMIN ACCESS ENTER admin (all lowercase) AS USERNAME & PASSWORD

    To VIEW BOOKS you have to add some books first. Log In as admin and add books

    To VIEW STUDENTS there must be accounts created fist

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Structures
struct Book
{
    char name[80];
    char author[50];
    int book_code;
};
struct Student
{
    char name[30];
    char username[9];
    char password[7];
    int id;
};

// Global Variables
int bookCount = 0;
int studentCount = 0;
int isLogged = 0;
int isAdmin = 0;

// functions
int landPage();
void signUp(struct Student *students);
void logIn(struct Student *students);
void studentHome(struct Book *books);
void adminHome(struct Book *books, struct Student *students);
void addBook(struct Book *books);
void viewBook(struct Book *books);
void searchBook(struct Book *books);
void deleteBook(struct Book *books);
void viewStudent(struct Student *students);
void searchStudent(struct Student *students);
void deleteStudent(struct Student *students);

int genRand(struct Book *books)
{

    for (int i = 0; i < 1; i++)
    {
        int num = (rand() % 9999999 - 100000 + 1) + 100000;
        for (int i = 0; i < bookCount; i++)
        {
            if ((books + i)->book_code == num)
            {
                genRand(books);
            }
        }
        return num;
    }
}

int main()
{

    struct Book books[100];
    struct Student students[100];

    int choice;

    choice = landPage();
    while (choice != 0)
    {

        if (choice == 1)
        {
            signUp(students);
        }
        else if (choice == 2)
        {
            logIn(students);

            while (isLogged != 0)
            {
                studentHome(books);
            }

            while (isAdmin != 0)
            {
                adminHome(books, students);
            }
        }
        choice = landPage();
    }

    return 0;
}

int landPage()
{
    int op;
    printf("\n\n-------------------------------------------\n");
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");

    printf("WELCOME TO UIU LIBRARY MANAGEMENT SYSTEM\n");
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n\n\n");

    printf("To access information you need to login first\n\n");
    printf("1: Sign Up\n");
    printf("2: Login\n");
    printf("0: Exit\n\n");

    printf("Choose:  ");
    scanf("%d", &op);
    printf("\n\n");
    return op;
}
void signUp(struct Student *students)
{
    getchar();
    printf("-------------------------------------------\n\n");
    printf("-------------------------------------------\n\n");
    printf("-------------------------------------------\n\n");
    printf("-------------------------------------------\n\n");
    printf("-------------------------------------------\n\n\n");

    printf("ENTER STUDENT ID (NUMBER ONLY): ");
    scanf("%d", &(students + studentCount)->id);
    getchar();
    printf("\nENTER YOUR NAME: ");
    gets((students + studentCount)->name);
    printf("\nENTER YOUR USERNAME (MAX 8 CHARACTER): ");
    gets((students + studentCount)->username);
    printf("\nENTER YOUR PASSWORD (MAX 6 CHARACTER): ");
    gets((students + studentCount)->password);

    printf("\n-------------------------------------------\n");
    printf("-------------------------------------------\n");
    printf("Account Created Successfully!\n");
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");

    studentCount++;
}
void logIn(struct Student *students)
{
    char username[9], password[7];
    getchar();
    printf("Enter your username: ");
    gets(username);
    printf("Enter your password: ");
    gets(password);
    printf("\n-------------------------------------------\n");
    printf("-------------------------------------------\n");

    if (!(strcmp(username, "admin") || strcmp(password, "admin")))
    {
        isAdmin = 1;
        printf("ADMIN ACCESS SUCCESFUL\n");
    }
    else
    {
        for (int i = 0; i < studentCount; i++)
        {
            if (!(strcmp(username, (students + i)->username) || strcmp(password, (students + i)->password)))
            {
                isLogged = 1;
                printf("LOGGED IN\n");
                break;
            }
        }
        if (isLogged == 0)
        {
            printf("UNSUCCESSFUL\n");
        }
    }
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
}
void studentHome(struct Book *books)
{
    int op;
    printf("\nWELCOME!!\n\n");
    printf("What do you want to do?\n");
    printf("1: Search Books\n");
    printf("2: View All Books\n");
    printf("0: Log Out\n");
    printf("Choose: ");
    scanf("%d", &op);
    if (op == 1)
    {
        searchBook(books);
    }
    else if (op == 2)
    {
        viewBook(books);
    }
    else if (op == 0)
    {
        isLogged = 0;
    }
}
void adminHome(struct Book *books, struct Student *students)
{
    int op;
    printf("\nWELCOME ADMIN\n\n\n");
    printf("What do you want to do?\n\n");
    printf("1: Add Books\n");
    printf("2: View All Books\n");
    printf("3: Search Books\n");
    printf("4: Delete Books\n");
    printf("5: View All Students\n");
    printf("6: Search Students\n");
    printf("7: Delete students\n");
    printf("0: Log Out\n");
    printf("\nChoose: ");
    scanf("%d", &op);
    if (op == 1)
    {
        addBook(books);
    }
    else if (op == 2)
    {
        viewBook(books);
    }
    else if (op == 3)
    {
        searchBook(books);
    }
    else if (op == 4)
    {
        deleteBook(books);
    }
    else if (op == 5)
    {
        viewStudent(students);
    }
    else if (op == 6)
    {
        searchStudent(students);
    }
    else if (op == 7)
    {
        deleteStudent(students);
    }
    else if (op == 0)
    {
        isAdmin = 0;
    }
}

void addBook(struct Book *books)
{
    getchar();
    printf("\nEnter Name of Book: ");
    gets((books + bookCount)->name);
    printf("\nEnter Name of Author: ");
    gets((books + bookCount)->author);
    // (books + bookCount)->book_code = bookCount + 1;

    srand(time(0));
    (books + bookCount)->book_code = genRand(books);

    printf("\n-------------------------------------------\n");
    printf("BOOK ADDED SUCCESSFULLY!\n");
    printf("-------------------------------------------\n");

    bookCount++;
}

void viewBook(struct Book *books)
{
    printf("\n-------------------------------------------\n");
    printf("-------------------------------------------\n\n");

    if (bookCount == 0)
    {
        printf("Database is Empty. Add Some Books First!\n");
    }
    else
    {
        for (int i = 0; i < bookCount; i++)
        {
            printf("\n-------------------------------------------\n");
            printf("Book Code: %d\n", (books + i)->book_code);
            printf("Name of Book: %s\n", (books + i)->name);
            printf("Name of Author: %s\n", (books + i)->author);
            printf("-------------------------------------------\n");
        }
    }

    printf("\n-------------------------------------------\n");
    printf("-------------------------------------------\n");
}
void searchBook(struct Book *books)
{
    char book[80];
    int flag = 1;
    getchar();
    printf("\nEnter the book name: ");
    gets(book);
    printf("\n-------------------------------------------\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < bookCount; i++)
    {
        if (!strcmp((books + i)->name, book))
        {
            printf("Book Code: %d\n", (books + i)->book_code);
            printf("Name: %s\n", (books + i)->name);
            printf("Author: %s\n", (books + i)->author);
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Book Not Found!\n");
    }
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
}
void deleteBook(struct Book *books)
{

    int bookCode, flag = 1;
    viewBook(books);
    printf("Enter Book Code: ");
    scanf("%d", &bookCode);
    printf("\n-------------------------------------------\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < bookCount; i++)
    {
        if ((books + i)->book_code == bookCode)
        {
            flag = 0;

            for (int j = i; j < bookCount - 1; j++)
            {
                books[j] = books[j + 1];
            }
        }
    }
    if (flag == 1)
    {
        printf("Invalid ID\n");
    }
    else
    {
        printf("Deletation Successful!\n");
        bookCount--;
    }
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
}
void viewStudent(struct Student *students)
{
    printf("\n-------------------------------------------\n");
    printf("-------------------------------------------\n");
    if (studentCount == 0)
    {
        printf("NO USER FOUND!\n");
    }
    else
    {
        for (int i = 0; i < studentCount; i++)
        {
            printf("Id: %d\n", (students + i)->id);
            printf("Name: %s\n", (students + i)->name);
            printf("Username: %s\n", (students + i)->username);
            printf("-------------------------------------------\n");
        }
    }
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
}
void searchStudent(struct Student *students)
{
    char username[9];
    int flag = 1;
    getchar();
    printf("Enter student username: ");
    gets(username);
    printf("\n-------------------------------------------\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < studentCount; i++)
    {
        if (!strcmp((students + i)->username, username))
        {
            printf("Student Id: %d\n", (students + i)->id);
            printf("Name: %s\n", (students + i)->username);
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Student Not Found!\n");
    }
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
}
void deleteStudent(struct Student *students)
{
    int studentId, flag = 1;
    viewStudent(students);
    printf("Enter student Id: ");
    scanf("%d", &studentId);

    printf("\n-------------------------------------------\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < studentCount; i++)
    {
        if ((students + i)->id == studentId)
        {
            flag = 0;

            for (int j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }
        }
    }
    if (flag == 1)
    {
        printf("Invalid ID\n");
    }
    else
    {
        printf("Deletation Successful!\n");
        studentCount--;
    }
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
}
