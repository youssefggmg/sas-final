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
#define GENERATED_ID_LENGTH 25
typedef struct sas
{
    char Id[30];
    char FirstName[MAX_CHAR];
    char LastName[MAX_CHAR];
    char dateOfBirth[MAX_CHAR];
    char department[MAX_CHAR];
    int point;
} student;

// store a random ID
char generatedID[GENERATED_ID_LENGTH];

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
    printf("Student List:\n");
    printf("---------------\n");

    for (int i = 0; i < num; i++)
    {
        printf("Student #%d\n", i + 1); 
        printf("  ID:           %s\n", arr[i].Id);
        printf("  Name:         %s %s\n", arr[i].FirstName, arr[i].LastName);
        printf("  Date of Birth: %s\n", arr[i].dateOfBirth);
        printf("  Department:   %s\n", arr[i].department);
        printf("  Points:       %d\n", arr[i].point);
        printf("---------------\n");
    }
}

// select a random charecter for the ID
char random_char(int index)
{
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    return charset[index];
}

// genirate a random ID
void generateID()
{
    int i, index;
    for (i = 0; i < GENERATED_ID_LENGTH; i++)
    {
        index = rand() % 62;
        generatedID[i] = random_char(index);
    }
    generatedID[GENERATED_ID_LENGTH] = '\0'; // Null-terminate the string
}

// sort the the array with selection sort

void selectioSortpoint(student arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j].point < arr[min_idx].point)
            {
                min_idx = j;
            }
        }

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

        for (j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j].FirstName, arr[min_idx].FirstName) < 0)
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            student temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void add_student(student arr[], int *index)
{
    int choice, n;
    system(CLEAR);
    printf("Do you want to add a single student or multiple students?\n 1. Single student \n 2. Multiple students\n");

    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        printf("Invalid input. Please enter 1 or 2.\n");
        system(CLEAR);
        scanf("%d", &choice);
    }

    switch (choice)
    {
    case 1:
    { // Add only one student
        printf("Enter the student's first name: ");
        while (scanf(" %[^\n]s", arr[*index].FirstName) != 1)
        {
            getchar();
            printf("Invalid first name. Re-enter: ");
        }
        toLowerCase(arr[*index].FirstName);

        printf("Enter the student's last name: ");
        while (scanf(" %[^\n]s", arr[*index].LastName) != 1)
        {
            getchar();
            printf("Invalid last name. Re-enter: ");
        }
        toLowerCase(arr[*index].LastName);

        printf("Enter the student's date of birth (DD/MM/YYYY): ");
        while (scanf(" %[^\n]s", arr[*index].dateOfBirth) != 1)
        {
            getchar();
            printf("Invalid date of birth. Re-enter: ");
        }

        // Print department choices explicitly
        printf("What is the student's department:\n");
        printf("1. Computer Science\n");
        printf("2. Mathematics\n");
        printf("3. Physics\n");
        printf("4. Chemistry\n");
        printf("5. Biology\n");
        printf("6. Economics\n");
        printf("7. Psychology\n");
        printf("8. Engineering\n");

        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 8)
        {
            printf("Invalid choice. Re-enter the choice: ");
        }

        // Array of department strings to map the choice to department name
        char departments[][30] = {
            "Computer Science", "Mathematics", "Physics",
            "Chemistry", "Biology", "Economics",
            "Psychology", "Engineering"};

        strcpy(arr[*index].department, departments[choice - 1]);

        printf("Enter the student's points: ");
        while (scanf("%d", &arr[*index].point) != 1)
        {
            printf("Invalid input. Re-enter the points: ");
        }
        genirateID();
        strcpy(arr[*index].Id, generatedID);

        (*index)++; // Increment index after adding the student

        printf("You have successfully added the student!\n");
        break;
    }

    case 2:
    { // Add multiple students
        int counter = 0;
        printf("How many students do you want to add? ");
        while (scanf("%d", &n) != 1 || n <= 0)
        {
            printf("Invalid input. Re-enter: ");
        }

        for (int i = *index; i < *index + n; i++)
        {
            system(CLEAR);
            printf("Enter the student's first name (Student #%d): ", counter + 1);
            while (scanf(" %[^\n]s", arr[i].FirstName) != 1)
            {
                getchar();
                printf("Invalid first name. Re-enter: ");
            }
            toLowerCase(arr[i].FirstName);

            printf("Enter the student's last name (Student #%d): ", counter + 1);
            while (scanf(" %[^\n]s", arr[i].LastName) != 1)
            {
                getchar();
                printf("Invalid last name. Re-enter: ");
            }
            toLowerCase(arr[i].LastName);

            printf("Enter the student's date of birth (Student #%d): ", counter + 1);
            while (scanf(" %[^\n]s", arr[i].dateOfBirth) != 1)
            {
                getchar();
                printf("Invalid date of birth. Re-enter: ");
            }

            // Print department choices explicitly
            printf("What is the student's department (Student #%d):\n", counter + 1);
            printf("1. Computer Science\n");
            printf("2. Mathematics\n");
            printf("3. Physics\n");
            printf("4. Chemistry\n");
            printf("5. Biology\n");
            printf("6. Economics\n");
            printf("7. Psychology\n");
            printf("8. Engineering\n");

            while (scanf("%d", &choice) != 1 || choice < 1 || choice > 8)
            {
                printf("Invalid choice. Re-enter the choice: ");
            }

            // Array of department strings to map the choice to department name
            char departments[][30] = {
                "Computer Science", "Mathematics", "Physics",
                "Chemistry", "Biology", "Economics",
                "Psychology", "Engineering"};

            strcpy(arr[i].department, departments[choice - 1]);

            printf("Enter the student's points (Student #%d): ", counter + 1);
            while (scanf("%d", &arr[i].point) != 1)
            {
                printf("Invalid input. Re-enter: ");
            }

            // Generate a simple student ID
            genirateID();
            strcpy(arr[*index].Id, generatedID);

            counter++;
        }
        (*index) += n;
        printf("All students were successfully added!\n");
        break;
    }
    }
}
void searchStudent(student arr[], int index, char name[], int choice)
{
    int left = 0, right = index - 1, mid, compair;
    char searchId[MAX_CHAR];

    printstudents(arr, index); // Print all students (assuming this function exists)

    if (choice == 1) // Search by FirstName
    {
        while (left <= right)
        {
            mid = (left + right) / 2;
            compair = strcmp(arr[mid].FirstName, name);
            if (compair == 0)
            {
                system(CLEAR);
                printf("We have found the student:\n");
                printf("Student ID: %s\n", arr[mid].Id);
                printf("Student First Name: %s\n", arr[mid].FirstName);
                printf("Student Last Name: %s\n", arr[mid].LastName);
                printf("Student Department: %s\n", arr[mid].department);
                printf("Student Point: %d\n", arr[mid].point);
                break;
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
    else if (choice == 2) // Search by ID
    {
        printf("Enter the student ID to search: ");
        scanf("%s", searchId);

        left = 0;
        right = index;
        while (left <= right)
        {
            mid = (left + right) / 2;
            compair = strcmp(arr[mid].Id, searchId);
            if (compair == 0)
            {
                system(CLEAR);
                printf("We have found the student:\n");
                printf("Student ID: %s\n", arr[mid].Id);
                printf("Student First Name: %s\n", arr[mid].FirstName);
                printf("Student Last Name: %s\n", arr[mid].LastName);
                printf("Student Department: %s\n", arr[mid].department);
                printf("Student Point: %d\n", arr[mid].point);
                break;
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
    else if (choice == 3)
    {
        int studentnum = 0;
        for (int i = 0; i < index; i++)
        {
            compair = strcmp(arr[i].department, name);
            if (compair == 0)
            {
                printf("Student ID: %s\n", arr[i].Id);
                printf("Student First Name: %s\n", arr[i].FirstName);
                printf("Student Last Name: %s\n", arr[i].LastName);
                printf("Student Last Name: %s\n", arr[i].point);
                studentnum++;
            }
        }
        if (studentnum == 0)
        {
            printf("ther is no student in this department\n");
        }
    }

    // If student is not found
    if (left > right)
    {
        printf("Student not found.\n");
    }

    printf("Do you want to contenu? 1. Continue 2. Stop\n");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        system(CLEAR);
        printf("You have entered a wrong choice. Please enter 1 or 2\n");
        scanf("%d", &choice);
    }

    if (choice = !1)
    {
        exit(0);
    }
}

int main()
{
    student students[MAX_students];
    char departments[][30] = {"Computer Science", "Mathematics", "Physics", "Chemistry", "Biology", "Economics", "Psychology", "Engineering"};
    int choice, point, index = 0;

    char name[MAX_CHAR];
    char dep[MAX_CHAR] = "empty";

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
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 7)
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
        case 2:
            printf("do you wnat to  search by 1.name or 2. id 3.departement?\n");
            while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3)
            {
                system(CLEAR);
                printf("Invalid input. Please  1.name or 2. id.\n");
                scanf("%d", &choice);
            }
            switch (choice)
            {
            case 1:
                printstudents(students, index);
                printf("who is the student that you'r looking for by name ?\n");
                while (scanf(" %[^\n]s", &name) != 1)
                {
                    getchar();
                    printf("invalid input\n");
                    scanf(" %[^\n]s", &name);
                }
                getchar();
                searchStudent(students, index, name, choice);
                break;
            case 2:
                printstudents(students, index);
                printf("who is the student that you'r looking for by  id ?\n");

                while (scanf(" %[^\n]s", &name) != 1)
                {
                    getchar();
                    printf("invalid input\n");
                    scanf(" %[^\n]s", &name);
                }
                getchar();
                searchStudent(students, index, name, choice);
                break;
            case 3:
                printstudents(students, index);
                printf("what department are you looking for by department ?\n");
                while (scanf(" %[^\n]s", &name) != 1)
                {
                    getchar();
                    printf("invalid input\n");
                    scanf(" %[^\n]s", &name);
                }
                getchar();
                searchStudent(students, index, name, choice);
                break;
            }
            break;
        case 3:
            printf("this is the information of  all students\n");
            printstudents(students, index);
            printf("Do you want to contenu? 1. Continue 2. Stop\n");
            while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
            {
                system(CLEAR);
                printf("You have entered a wrong choice. Please enter 1 or 2\n");
                scanf("%d", &choice);
            }

            if (choice = !1)
            {
                exit(0);
            }

            break;
        case 4:

            break;
        }

        break;
    }
}
