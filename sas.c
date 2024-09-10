#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

typedef struct sas
{
    char Id[MAX_SIZE];
    char Firstname[MAX_SIZE];
    char Lastname[MAX_SIZE];
    char dateOfBearth[MAX_SIZE];
    char department[MAX_SIZE];
    int point;
} student;
void addStudent(student arr[],int index){
    printf("what is the name if the student ");
    scanf(" %[^\n]s",&arr[index].Firstname);
    printf("what is the lastname of the student ");
    scanf(" %[^\n]s",&arr[index].Lastname);
    printf("what is the date of birth of the student ");
    scanf(" %[^\n]s",&arr[index].dateOfBearth);

}

int main()
{
    student sas[MAX_SIZE];
    int choice,index=0;

    while (1)
    {
        CHOICE:
        system(CLEAR);
        printf("Enter your choice: \n1. Add Student \n2. Delete Student \n3. Update Student \n4. Display All Students \n5. Display Student by ID \6. Search Student by ID \n7. Exit\n");
        while (scanf("%d", &choice)!=1)
        {
            printf("invalid input. Please enter a number: ");
            scanf("%d", &choice);
        }
        
        switch (choice){
            case 1:
            addStudent(sas,index);
            break;
        }
    }
}
