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
#define MAX_students 255
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

// minor functions

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
void genirateID()
{
    int i, index;
    for (i = 0; i < GENERATED_ID_LENGTH; i++)
    {
        index = rand() % 62;
        generatedID[i] = random_char(index);
    }
    generatedID[GENERATED_ID_LENGTH] = '\0'; // Null-terminate the string
}

// sort the the array with selection sort higher to lower

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
void showDepStudent(student arr[], int index, char dep[])
{
    int found = 0, choice;
    for (int i = 0; i < index; i++)
    {
        if (strcmp(arr[i].department, dep) == 0)
        {
            printf("the student ID is %s\n", arr[i].Id);
            printf("the  student name is %s %s\n", arr[i].FirstName, arr[i].LastName);
            printf("the  student name is %s\n", arr[i].dateOfBirth);
            printf("the student point is %d\n", arr[i].point);
        }
    }
    if (found == 0)
    {
        printf("No students found in the %s department.\n", dep);
    }
    printf("Do you want to contenu? 1. Continue 2. Stop\n");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        system(CLEAR);
        printf("You have entered a wrong choice. Please enter 1 or 2\n");
        scanf("%d", &choice);
    }

    if (choice != 1)
    {
        exit(0);
    }
}
// reversed sort lower  to higher

void selectioSortpointReversed(student arr[], int n)
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
// sorting  by name from A-z

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
// reverse sorting by name Z-a

void selectioSortReversed(student arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j].FirstName, arr[min_idx].FirstName) > 0)
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

// real function

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
            printf("Enter the student's first name Student #%d (DD/MM/YYYY): ", counter + 1);
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
            strcpy(arr[i].Id, generatedID);

            counter++;
        }
        (*index) += n;
        printf("All students were successfully added!\n");
        break;
    }
    }
}
// search for the student  with the given ID & name & department

void searchStudent(student arr[], int index, char name[], int choice)
{
    selectioSort(arr, index);
    int left = 0, right = index - 1, mid, compair;
    char searchId[MAX_CHAR];

    printstudents(arr, index);

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

    if (choice != 1)
    {
        exit(0);
    }
}

// function for avrege point for each department
void geniralavrege(student arr[], int index, int numberOfDeps)
{
    system(CLEAR);
    char departments[][30] = {"Computer Science", "Mathematics", "Physics", "Chemistry", "Biology", "Economics", "Psychology", "Engineering"};
    int choice;

    // Loop through each department
    for (int i = 0; i < numberOfDeps; i++)
    {
        int sum = 0;
        int count = 0;
        for (int j = 0; j < index; j++)
        {
            if (strcmp(arr[j].department, departments[i]) == 0)
            {
                sum += arr[j].point;
                count++;
            }
        }
        if (count > 0)
        {
            printf("The average points of the %s department is: %.2f\n", departments[i], (float)sum / count);
        }
        else
        {
            // If no students were found in the department
            printf("No students in the %s department.\n", departments[i]);
        }
    }
    printf("Do you want to contenu? 1. Continue 2. Stop\n");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        system(CLEAR);
        printf("You have entered a wrong choice. Please enter 1 or 2\n");
    }

    if (choice != 1)
    {
        exit(0);
    }
}

// edit or delete function
void editDelete(student arr[], int *index, int choice, char name[])
{
    system(CLEAR);
    int numchouse;
    char temp[MAX_CHAR];
    // Array of department strings to map the choice to department name
    char departments[][30] = {
        "Computer Science", "Mathematics", "Physics",
        "Chemistry", "Biology", "Economics",
        "Psychology", "Engineering"};

    printf("Do you want to use Name or ID? \n1. Name \n2. ID\n");
    while (scanf("%d", &numchouse) != 1 || (numchouse != 1 && numchouse != 2))
    {
        system(CLEAR);
        printf("Invalid choice. Please enter 1 (Name) or 2 (ID).\n");
        while (getchar() != '\n')
            ;
    }

    printf("Do you want to edit or delete the student?\n1. Edit \n2. Delete\n");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        system(CLEAR);
        printf("Invalid input. Please enter 1 (Edit) or 2 (Delete).\n");
        while (getchar() != '\n')
            ;
    }
    // I've used if else here instead of switch becouse it was to harde for me to folow with nisted so I used if else

    if (numchouse == 1)
    {
        printf("Enter the name of the student you want to edit or delete:\n");
        while (scanf(" %[^\n]s", temp) != 1)
        {
            system(CLEAR);
            printf("Invalid input. Please enter a valid name.\n");
        }

        for (int i = 0; i < *index; i++)
        {
            if (strcmp(arr[i].FirstName, temp) == 0)
            {
                if (choice == 1)
                { // Edit
                    printf("Editing student...\n");

                    printf("Enter the new first name: ");
                    while (scanf(" %[^\n]s", arr[i].FirstName) != 1)
                    {
                        system(CLEAR);
                        printf("Invalid input. Please enter a valid first name.\n");
                    }

                    printf("Enter the new last name: ");
                    while (scanf(" %[^\n]s", arr[i].LastName) != 1)
                    {
                        system(CLEAR);
                        printf("Invalid input. Please enter a valid last name.\n");
                    }

                    printf("Select the new department:\n");
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
                        while (getchar() != '\n')
                            ; // clear input buffer
                    }
                    strcpy(arr[i].department, departments[choice - 1]);

                    printf("Enter the new point (0-20): ");
                    while (scanf("%d", &arr[i].point) != 1 || arr[i].point < 0 || arr[i].point > 20)
                    {
                        printf("Invalid point. Please re-enter a valid point (0-20).\n");
                        while (getchar() != '\n')
                            ; // clear input buffer
                    }

                    printf("Student edited successfully!\n");
                    break;
                }
                else if (choice == 2)
                { // Delete
                    for (int j = i; j < *index - 1; j++)
                    {
                        arr[j] = arr[j + 1]; // Shift the elements to
                    }
                    (*index)--; // Decrease the number of students
                    printf("Student deleted successfully!\n");
                    break;
                }
            }
        }
    }
    else if (numchouse == 2)
    {
        printf("Enter the student ID you want to edit or delete:\n");
        while (scanf(" %[^\n]s", temp) != 1)
        {
            system(CLEAR);
            printf("Invalid input. Please enter a valid ID.\n");
        }

        for (int i = 0; i < *index; i++)
        {
            if (strcmp(arr[i].Id, temp) == 0)
            {
                if (choice == 1)
                { // Edit
                    printf("Editing student...\n");

                    printf("Enter the new first name: ");
                    while (scanf(" %[^\n]s", arr[i].FirstName) != 1)
                    {
                        system(CLEAR);
                        printf("Invalid input. Please enter a valid first name.\n");
                    }

                    printf("Enter the new last name: ");
                    while (scanf(" %[^\n]s", arr[i].LastName) != 1)
                    {
                        system(CLEAR);
                        printf("Invalid input. Please enter a valid last name.\n");
                    }

                    printf("Select the new department:\n");
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
                        while (getchar() != '\n')
                            ; // clear input buffer
                    }

                    char departments[][30] = {
                        "Computer Science", "Mathematics", "Physics",
                        "Chemistry", "Biology", "Economics",
                        "Psychology", "Engineering"};
                    strcpy(arr[i].department, departments[choice - 1]);

                    printf("Enter the new point (0-20): ");
                    while (scanf("%d", &arr[i].point) != 1 || arr[i].point < 0 || arr[i].point > 20)
                    {
                        printf("Invalid point. Please re-enter a valid point (0-20).\n");
                        while (getchar() != '\n')
                            ; // clear input buffer
                    }

                    printf("Student edited successfully!\n");
                    break;
                }
                else if (choice == 2)
                { // Delete
                    for (int j = i; j < *index - 1; j++)
                    {
                        arr[j] = arr[j + 1]; // Shift the elements to the left
                    }
                    (*index)--; // Decrease the number of students
                    printf("Student deleted successfully!\n");
                    break;
                }
            }
        }
    }
    printf("Do you want to continue? 1. Yes 2. No\n");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        system(CLEAR);
        printf("Invalid choice. Please enter 1 to continue or 2 to exit.\n");
        while (getchar() != '\n')
            ; // clear input buffer
    }

    if (choice == 2)
    {
        exit(0);
    }
}
// the function that show the Statistics
void Statistics(student arr[], int index, int num)
{
    system(CLEAR);
    int choice;
    char departments[][30] = {"Computer Science", "Mathematics", "Physics", "Chemistry", "Biology", "Economics", "Psychology", "Engineering"};
    int depnum = 8;
    switch (num)
    {
    case 1:
        printf("you have %d students\n", index);
        printf("Do you want to contenu? 1. Continue 2. Stop\n");
        while (scanf("%d", &choice) != 1)
        {
            system(CLEAR);
            printf("You have entered a wrong choice. Please enter 1 or 2\n");
            scanf("%d", &choice);
        }
        // now it's workes
        if (choice != 1)
        {
            exit(0);
        }
        else
        {
            break;
            ;
        }
        break;
    case 2:
        printf("the number in each department is :\n");
        for (int i = 0; i < 8; i++)
        {
            int counter = 0;
            for (int j = 0; j < index; j++)
            {
                if (strcmp(departments[i], arr[j].department) == 0)
                {
                    counter++;
                }
            }
            printf(" the number of students in %s department is : %d\n", departments[i], counter);
        }
        printf("Do you want to contenu? 1. Continue 2. Stop\n");
        while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
        {
            system(CLEAR);
            printf("You have entered a wrong choice. Please enter 1 or 2\n");
            scanf("%d", &choice);
        }
        if (choice != 1)
        {
            exit(0);
        }
        break;
    case 3:
        system(CLEAR);
    int choice;
    char departments[][30] = {"Computer Science", "Mathematics", "Physics", "Chemistry", "Biology", "Economics", "Psychology", "Engineering"};
    int depnum = 8;

    switch (num)
    {
    case 3:
        system(CLEAR);
        // Assuming `selectioSortpoint` sorts students by points in descending order
        selectioSortpoint(arr, index);  // This should sort the entire array

        printf("Top 3 students in each department are:\n");
        for (int i = 0; i < depnum; i++)
        {
            printf("Department: %s\n", departments[i]);
            int count = 0;

            // Loop through students to print top 3 in the current department
            for (int j = 0; j < index; j++)
            {
                if (strcmp(arr[j].department, departments[i]) == 0)
                {
                    if (count < 3)  // Only print the top 3 students
                    {
                        printf("The student number %d in the department %s is %s %s\n", count + 1, departments[i], arr[j].FirstName, arr[j].LastName);
                        count++;
                    }
                }
            }
            if (count == 0) {
                printf("No students found in this department.\n");
            }
            printf("############################################\n");
        }

        printf("Do you want to continue? 1. Continue 2. Stop\n");
        while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
        {
            system(CLEAR);
            printf("You have entered a wrong choice. Please enter 1 or 2\n");
            // Clear input buffer
            while (getchar() != '\n');
        }

        if (choice != 1)
        {
            exit(0);
        }
        break;
    case 4:
        system(CLEAR);
        printf("Successful and failed students in each department:\n");
        for (int i = 0; i < depnum; i++)
        {
            printf("Department: %s\n", departments[i]);
            printf("Successful students (>= 10 points):\n");
            int successCount = 0, failCount = 0;

            for (int j = 0; j < index; j++)
            {
                if (strcmp(arr[j].department, departments[i]) == 0)
                {
                    if (arr[j].point >= 10)
                    {
                        printf("%s %s\n", arr[j].FirstName, arr[j].LastName);
                        successCount++;
                    }
                }
            }

            if (successCount == 0)
            {
                printf("No successful students in this department.\n");
            }

            printf("\nFailed students (< 10 points):\n");
            for (int j = 0; j < index; j++)
            {
                if (strcmp(arr[j].department, departments[i]) == 0)
                {
                    if (arr[j].point < 10)
                    {
                        printf("%s %s\n", arr[j].FirstName, arr[j].LastName);
                        failCount++;
                    }
                }
            }
            if (failCount == 0)
            {
                printf("No failed students in this department.\n");
            }
            printf("############################################\n");
        }
        break;
    }
}
// add 10 students in the bigening of the program
void addSampleStudents(student arr[], int *index)
{
    // String arrays for predefined student data
    char ids[10][5] = {"S001", "S002", "S003", "S004", "S005", "S006", "S007", "S008", "S009", "S010"};

    char firstNames[10][10] = {"John", "Jane", "Alice", "Bob", "Charlie", "David", "Eva", "Fay", "George", "Hannah"};

    char lastNames[10][10] = {"Doe", "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore"};

    char departments[10][20] = {"Computer Science", "Mathematics", "Physics", "Chemistry", "Biology", "Economics", "Psychology", "Engineering", "Mathematics", "Physics"};

    char dob[10][11] = {"2000-01-01", "2000-02-01", "2000-03-01", "2000-04-01", "2000-05-01", "2000-06-01", "2000-07-01", "2000-08-01", "2000-09-01", "2000-10-01"};

    int points[10] = {12, 15, 10, 18, 14, 13, 17, 16, 19, 20};

    for (int i = 0; i < 10; i++)
    {
        strcpy(arr[*index].Id, ids[i]);
        strcpy(arr[*index].FirstName, firstNames[i]);
        strcpy(arr[*index].LastName, lastNames[i]);
        strcpy(arr[*index].department, departments[i]);
        strcpy(arr[*index].dateOfBirth, dob[i]);
        arr[*index].point = points[i];
        (*index)++;
    }
}

int main()
{
    student students[MAX_students];
    char departments[][30] = {"Computer Science", "Mathematics", "Physics", "Chemistry", "Biology", "Economics", "Psychology", "Engineering"};
    int depcount = 8;
    int choice, point, index = 0;
    char name[MAX_CHAR];

    // char name[MAX_CHAR]; I don't know when or why I used this variable , but it's not used anywhere in the code

    addSampleStudents(students, &index);

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
            printf("3. edit student\n");
            printf("4. delete a student\n");
            printf("5. general averag\n");
            printf("6. Statistics\n");
            printf("7. exit\n");
            scanf("%d", &choice);
        }
        // indentation is the worst it makes  the code look like a mess
        switch (choice)
        {
        case 1:
            add_student(students, &index);
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
                showDepStudent(students, index, name);
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

            if (choice != 1)
            {
                exit(0);
            }

            break;
        case 4:
            printf("Do you want to edit or delete student? 1. edit 2. delete\n");
            while (scanf("%d", &choice) != 1 || (choice != 1 || choice != 2))
            {
                system(CLEAR);
                printf("You have entered a wrong choice. Please enter 1 or 2\n");
            }
            printf("what is the name that you want toedit or delete student? 1. edit 2. delete\n");
            while (scanf(" %[^\n]s", &name) != 1)
            {
                system(CLEAR);
                printf("You have entered a wrong choice. Please enter 1 or 2\n");
            }
            editDelete(students, &index, choice, name);

            break;
        case 5:
            geniralavrege(students, index, depcount);
            printf("Do you want to contenu? 1. Continue 2. Stop\n");
            while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
            {
                system(CLEAR);
                printf("You have entered a wrong choice. Please enter 1 or 2\n");
                scanf("%d", &choice);
            }

            if (choice != 1)
            {
                exit(0);
            }
            break;
        case 6:
            system(CLEAR);
            printf("1. the total number of students enrolled.\n");
            printf("2. View the number of students in each department.\n");
            printf("3. Show the 3 students with the best grades.\n");
            printf("4. Show the number of successful students in each department.\n");
            while (scanf("%d", &choice) != 1)
            {
                printf("invalide choice\n");
            }
            Statistics(students, index, choice);

            // return 0;  wasted 6 hours becose  of this line
            break;
        case 7:
            system(CLEAR);
            printf("thank you for using our application\n");
            return 0;
            break;
        }
    }
}
