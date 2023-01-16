#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct phNum
{
    char name[30];
    char lastName[30];
    long phone;
};

typedef struct phNum PhNum;

PhNum phList[5] = {};

void addData(PhNum user, int index)
{
    phList[index] = user;
}

int cmp(const void *a, const void *b)
{
    const PhNum *p1 = (PhNum*)a;
    const PhNum *p2 = (PhNum*)b;

    return strcmp(p2->lastName, p1->lastName);
}
void showData()
{
    qsort(phList, 5, sizeof(*phList), cmp);
    for (int i = 0; i < 5; i++)
    {
        if (!(strcmp(phList[i].name, "empty") == 0 && phList[i].phone == 0 && phList[i].lastName == 0))
        {
            printf("%d : %s | %s | %ld\n", i + 1, phList[i].name, phList[i].lastName, phList[i].phone);
        }
        else if (strcmp(phList[i].name, "empty"))
        {
            printf("%d : empty | %s | %ld\n", i + 1, phList[i].lastName, phList[i].phone);
        }
    }
}
void searna()
{
    printf("Enter the name you want to search: ");
    char name[30];
    scanf("%s", name);
    int index = 1;
    bool said = false;
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(phList[i].name, name) == 0)
        {
            printf("%d : %s | %s | %ld\n", index, phList[i].name, phList[i].lastName, phList[i].phone);
            index++;
            said = true;
        }
        else if (i == 4 && said != true)
        {
            printf("that name does not exist in this phone book\n");
        }
    }
}
void searla()
{
    printf("Enter the last name you want to search: ");
    char lname[30];
    scanf("%s", lname);
    int index = 1;
    bool said = false;
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(phList[i].lastName, lname) == 0)
        {
            printf("%d : %s | %s | %ld\n", index, phList[i].name, phList[i].lastName, phList[i].phone);
            index++;
            said = true;
        }
        else if (i == 4 && said != true)
        {
            printf("that last name does not exist in this phone book\n");
        }
    }
}

void deleteData()
{
    showData();
    int delnum;
    printf("Enter the number behind the one you want to delete : ");
    scanf("%d", &delnum);
    delnum -= 1;
    strcpy(phList[delnum].name, "empty");
    strcpy(phList[delnum].lastName, "empty");
    phList[delnum].phone = 0;
}
int editData()
{
    showData();
    int ednum;
    printf("Enter the number behind the one you want to edit : ");
    scanf("%d", &ednum);
    getchar();
    ednum -= 1;
    char choice[30];
    char name[30];
    char lastName[30];
    long phone;
    printf("Enter the parameter to edit(name|lname|phone|all):  ");
    scanf(" %s", choice);
        PhNum user;
    if (strcmp(choice, "all") == 0)
    {
        printf("Enter Your Name:\n");
        scanf(" %s", name);
        printf("Enter Your Last Name:\n");
        scanf(" %s", lastName);
        printf("Enter your Phone Number:\n");
        scanf(" %ld", &phone);
        user.phone = phone;
        strcpy(user.name, name);
        strcpy(user.lastName, lastName);
    }
    else if (strcmp(choice, "name") == 0)
    {
        printf("Enter Your Name:\n");
        scanf(" %s", name);
        strcpy(user.name, name);
        user.phone = phList[ednum].phone;
        strcpy(user.lastName, phList[ednum].lastName);
    }
    else if (strcmp(choice, "lname") == 0)
    {
        printf("Enter Your Last Name:\n");
        scanf(" %s", lastName);
        strcpy(user.name, phList[ednum].name);
        user.phone = phList[ednum].phone;
        strcpy(user.lastName, lastName);
    }
    else if (strcmp(choice, "phone") == 0)
    {
        printf("Enter your Phone Number:\n");
        scanf(" %ld", &phone);
        user.phone = phone;
        strcpy(user.lastName, phList[ednum].lastName);
        strcpy(user.name, phList[ednum].name);
    }
    else {
        return 1;
    }
    phList[ednum] = user;
    return 0;
}
int main()
{
    for (int j = 0; j < 5; j++)
    {
        strcpy(phList[j].name, "empty");
        strcpy(phList[j].lastName, "empty");
    }
    system("clear");
    int option;
    int index = 0;
    while (option != 7)
    {
        system("clear");

        printf("Select an option:\n1.Add Data\n2.Remove Data\n3.Edit Data\n4.Find Data By Name\n5.Find Data By Last Name\n6.Show the Users List\n7.Leave\n");
        printf("Enter Your Option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            if (index > 4)
            {
                printf("the list is full\n");
                break;
            }
            char name[30];
            char lastName[30];
            long phone;
            printf("Enter Your Name:\n");
            scanf(" %s", name);
            printf("Enter Your Last Name:\n");
            scanf(" %s", lastName);
            printf("Enter your Phone Number:\n");
            scanf(" %ld", &phone);
            PhNum user;
            user.phone = phone;
            strcpy(user.name, name);
            strcpy(user.lastName, lastName);
            addData(user, index);
            index++;
            break;
        }
        case 2:
            deleteData();
            break;
        case 3:
            editData();
            break;
        case 4:
            searna();
            printf("Press Enter to Continue\n");
            getchar();
            getchar();
            break;
        case 6:
        {
            showData();
            printf("Press Enter to Continue\n");
            getchar();
            getchar();
            break;
        }
        case 5:
            searla();
            printf("Press Enter to Continue\n");
            getchar();
            getchar();
            break;
            break;
        case 7:
            system("clear");
            break;
        default:
        {
            printf("invalid code\n");
            break;
        }
        }
    }
}