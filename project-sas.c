#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

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

// store a random ID
char generatedID[29];

// convirt string to lower case
void toLowerCase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}
void printstudents(student arr[], int num)
{
    system(CLEAR);
    for (int i = 0; i < num; i++)
    {
        printf("the  student %d id: is  %s\n", i, arr[i].Id);
        printf("the student %d name is %s %s\n", i, arr[i].FirstName, arr[i].LastName);
        printf("the student  %d date of birth is %s\n", i, arr[i].dathOfBearth);
        printf("the student %d department is %s\n", i, arr[i].department);
        printf("the student %d point is %d\n", i, arr[i].point);
    }
}

// select a random charecter for the ID
char random_char(int index)
{
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    return charset[index];
}

// genirate a random ID
void genirateID()
{
    srand(time(NULL));
    int i, index;
    for (i = 0; i < 16; i++)
    {
        index = rand() % 62;
        generatedID[i] = random_char(index);
    }
    generatedID[16] = '\0';
}

// sort the the array with selection sort

void selectioSortpoint(student arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;

        // Find the student with the minimum points in the unsorted part
        for (j = i + 1; j < n; j++)
        {
            if (arr[j].point < arr[min_idx].point)
            {
                min_idx = j;
            }
        }

        // If a smaller point is found, swap the entire student records
        if (min_idx != i)
        {
            // Swap the entire structure between arr[i] and arr[min_idx]
            student temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void selectioSort(student arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        // Find the minimum FirstName in the remaining unsorted part of the array
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j].FirstName, arr[min_idx].FirstName) < 0)
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            student temp = arr[i]; // Temporary struct to hold the current student
            arr[i] = arr[min_idx]; // Swap arr[i] with arr[min_idx]
            arr[min_idx] = temp;   // Place the original student in the min_idx position
        }
    }
}

void add_student(student arr[], int index, char departments[])
{
    int choice, n;
    system(CLEAR);
    printf("do you want to add student or mutiple studens\n 1.single student \n 2.multiple students");

    while (scanf("%d", &choice) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        system(CLEAR);
        scanf("%d", choice);
    }
    switch (choice)
    {
        // add only one student
    case 1:
        printf("what is the student first name:");
        while (scanf(" %[^\n]s", arr[index].FirstName) != 1)
        {
            getchar();
            printf("invalid first name\n");
            scanf(" %[^\n]s", arr[index].FirstName);
            toLowerCase(arr[index].FirstName);
        }
        toLowerCase(arr[index].FirstName);
        getchar();
        sleep(1);
        printf("what is the student last name:");
        while (scanf(" %[^\n]s", arr[index].LastName) != 1)
        {
            getchar();
            printf("invalid last name \n");
            printf("reenter the last name \n");
            scanf(" %[^\n]s", arr[index].LastName);
            toLowerCase(arr[index].LastName);
        }
        toLowerCase(arr[index].LastName);
        getchar();
        sleep(1);
        printf("what is the student date of birth:");
        while (scanf(" %[^\n]s", arr[index].dathOfBearth) != 1)
        {
            getchar();
            printf("invalid input\n");
            scanf(" %[^\n]s", arr[index].dathOfBearth);
            toLowerCase(arr[index].dathOfBearth);
        }
        toLowerCase(arr[index].dathOfBearth);
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
        while (scanf("%d", &choice) != 1 || choice <= 1 || choice >= 8)
        {
            printf("invalid choice\n");
            printf("reenter the choice\n");
            scanf("%d", &choice);
        }
        strcpy(arr[index].department, departments[choice]);
        printf("printf  what is the student point:\n");
        while (scanf("%d", arr[index].point) != 1)
        {
            printf("invalid input\n");
            scanf("%d", &arr[index].point);
        }
        strcpy(arr[index].Id, generatedID);
        ++index;
        printf("you have added a student to the list do you want to contenu:1.contenu \n 2.stop ");
        scanf("%s", &choice);
        if (choice != 1)
        {
            exit(0);
        }
        break;
        // add more than one student
    case 2:
        int counter = 0;
        printf("how may do you want to add");

        while (scanf("%d", &n) != 1)
        {
            printf("invalid input\n");
            scanf("%d", &n);
        }
        for (int i = index; i < index + n; i++)
        {
            system(CLEAR);
            printf("what is the student first name: number %d", counter);
            while (scanf(" %[^\n]s", arr[i].FirstName) != 1)
            {
                getchar();
                printf("invalid first name\n");
                scanf(" %[^\n]s", arr[i].FirstName);
                toLowerCase(arr[index].FirstName);
            }
            toLowerCase(arr[index].FirstName);
            getchar();
            sleep(1);
            printf("what is the student last name: number %d", counter);

            while (scanf(" %[^\n]s", arr[i].LastName) != 1)
            {
                getchar();
                printf("invalid last name \n");
                printf("reenter the last name \n");
                scanf(" %[^\n]s", arr[i].LastName);
                toLowerCase(arr[index].LastName);
            }
            toLowerCase(arr[index].LastName);
            getchar();
            sleep(1);
            printf("what is the student date of birth: number %d", counter);

            while (scanf(" %[^\n]s", arr[i].dathOfBearth) != 1)
            {
                getchar();
                printf("invalid input\n");
                scanf(" %[^\n]s", arr[i].dathOfBearth);
                toLowerCase(arr[index].dathOfBearth);
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
            while (scanf("%d", &choice) != 1 || choice <= 1 || choice >= 8)
            {
                printf("invalid choice\n");
                printf("reenter the choice\n");
                scanf("%d", &choice);
            }
            strcpy(arr[i].department, departments[choice]);
            printf("printf  what is the student point:number %d,counter \n");

            while (scanf("%d", arr[i].point) != 1)
            {
                printf("invalid input\n");
                scanf("%d", &arr[i].point);
            }
            ++counter;
            strcpy(arr[i].Id, generatedID);
        }
        printf("all of the students wher added\n");
        printf("do you whant to continu\n");
        printf("all the sudents to the list do you want to contenu:1.contenu \n 2.stop ");
        scanf("%s", &choice);
        if (choice != 1)
        {
            exit(0);
        }
        break;
    }
}
void searchStudent(student arr[], int index, char name[])
{
    int left = 0, right, mid, size = index - 1, choice;
    printstudents(arr, index);

    while (left <= right)
    {
        mid = (left + right) / 2;
        int compair = strcmp(arr[mid].FirstName, name);
        if (compair == 0)
        {
            system(CLEAR);
            printf("we have founde the student");
            printf("student ID is : %s", arr[mid].Id);
            printf("student first name:%s\n", arr[mid].FirstName);
            printf("student last name:%s\n", arr[mid].LastName);
            printf("student department:%s\n", arr[mid].department);
            printf("student point:%d\n", arr[mid].point);
            printf("do  you whant to search another student:1.continue 2.stop");
            while (scanf("%d", &choice) != 1 || choice != 1, choice != 2)
            {
                system(CLEAR);
                printf("you have entere a wrong choice . please enter 1 or 2\n");
                scanf("%d", &choice);
            }
        }
        else if (compair < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}

int main()
{
    student students[MAX_students];
    char departments[] = {"Computer Science", "Mathematics", "Physics", "Chemistry", "Biology", "Economics", "Psychology", "Engineering"};
    int choice, point, index = 0;

    char name[MAX_CHAR];

    while (1)
    {
        system(CLEAR);
        printf("what do you  want to do?\n");
        printf("1. add student\n");
        printf("2. search student\n");
        printf("3. edit student\n");
        printf("4. delete a student\n");
        printf("5. general averag\n");
        printf("6. Statistics\n");
        printf("7. exit\n");
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
            add_student(students, index, departments);
            break;
        case 2:
            printstudents(students, index);
            printf("who is the student that you'r looking for ?\n");
            while (scanf(" %[^\n]s", &name) != 1)
            {
                getchar();
                printf("invalid input\n");
                scanf(" %[^\n]s", &name);
            }
            getchar();
            searchStudent(students, index, name);
            break;
        }
    }
}