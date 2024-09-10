#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define MAX_CHAR 256
#define MAX_students 100000

typedef struct sas
{
    char Id[30];
    char FirstName[MAX_CHAR];
    char LastName[MAX_CHAR];
    char dathOfBearth[MAX_CHAR];
    char department[MAX_CHAR];
    int point;
} student;

void add_student(student arr[], int index)
{
    system(CLEAR);
    printf("what is the student first name:");
    while (scanf(" %[^\n]s", arr[index].FirstName) != 1)
    {
        getchar();
        printf("invalid first name\n");
        scanf(" %[^\n]s", arr[index].FirstName);
    }
    getchar();
    sleep(1);
    printf("what is the student last name:");
    while (scanf(" %[^\n]s", arr[index].LastName) != 1)
    {
        getchar();
        printf("invalid last name \n");
        printf("reenter the last name \n");
        scanf(" %[^\n]s", arr[index].LastName);
    }
    getchar();
    sleep(1);
    printf("what is the student date of birth:");
    while (scanf(" %[^\n]s", arr[index].dathOfBearth) != 1)
    {
        getchar();
        printf("invalid input\n");
        scanf(" %[^\n]s", arr[index].dathOfBearth);
    }
    getchar();
    sleep(1);
    printf("printf  what is the student department:\n");
    printf("1. Computer Science\n");
    printf("2. Mathematics\n");
    printf("3. Physics\n");
    printf("4. Chemistry\n");
    printf("5. Biology\n");
    printf("6. Economics\n");
    printf("7. Psychology\n");
    printf("8. Engineering\n");
    while (scanf("%d", arr[index].department) != 1)
    {
        getchar();
        printf("invalid department\n");
        printf("reenter the department \n");
        scanf("%d", arr[index].department);
    }
}

int main()
{
    student students[MAX_students];
    char departments[] = {"Computer Science", "Mathematics", "Physics", "Chemistry", "Biology", "Economics", "Psychology", "Engineering"};
    int choice, point, index = 0;

    char search[MAX_CHAR];

    while (1)
    {
        system(CLEAR);
        printf("what do you  want to do?\n");
        printf("1. add student\n");
        printf("2. search student\n");
        printf("3. students details\n");
        printf("4. general average\n");
        printf("5. Statistics\n");
        printf("6. exit\n");
        while (scanf("%d", &choice) != 1)
        {
            system(CLEAR);
            printf("Invalid input. Please enter a number.\n");
            printf("what do you  want to do?\n");
            printf("1. add student\n");
            printf("2. search student\n");
            printf("3. students details\n");
            printf("4. general average\n");
            printf("5. Statistics\n");
            printf("6. exit\n");
            scanf("%d", &choice);
        }
        switch (choice)
        {
        case 1:
            add_student(students, index);
            break;
        }
    }
}
