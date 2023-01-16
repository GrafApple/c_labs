#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Friend 
{
    char surname[32];
    char name[32];
    char middle_name[32];
    char birthdate[32];
    char address[64];
    char phone[16];
} friends[100];
int friend_count = 0;

void print_friends() 
{
    printf("Friends\n");
    for (int i = 0; i < friend_count; i++) 
{
    printf("FIO: %s %s %s, Birthdate: %s, Street: %s,  Phone num: %s\n", friends[i].surname, friends[i].name, friends[i].middle_name, friends[i].birthdate, friends[i].address, friends[i].phone);
}
}

void add_friend() 
{
    printf("Enter friend's surname: ");
    scanf("%s", friends[friend_count].surname);
    printf("Enter friend's name: ");
    scanf("%s", friends[friend_count].name);
    printf("Enter friend's middle_name: ");
    scanf("%s", friends[friend_count].middle_name);
    printf("Enter friend's birthdate (dd.mm.yyyy): ");
    scanf("%s", friends[friend_count].birthdate);
    printf("Enter friend's street: ");
    scanf("%s", friends[friend_count].address);
    printf("Enter friends phone: ");
    scanf("%s", friends[friend_count].phone);
    friend_count++;
}

void delete_friend() 
{
    int index;
    printf("Enter index of friend to delete: ");
    scanf("%d", &index);
    index--;
    if (index < 0 || index >= friend_count) 
    {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < friend_count - 1; i++) 
    {
        friends[i] = friends[i + 1];
    }
    friend_count--;
}

void save_friends_to_file() 
{
    FILE *f = fopen("friends.txt", "w");
    for (int i = 0; i < friend_count; i++) 
    {
        fprintf(f, "%s %s %s %s %s %s\n", friends[i].surname, friends[i].name, friends[i].middle_name, friends[i].birthdate, friends[i].address, friends[i].phone);
    }
    fclose(f);
}

void load_friends_from_file() 
{
    FILE *f = fopen("friends.txt", "r");
    friend_count = 0;
    while (fscanf(f, "%s %s %s %s %s %s\n", friends[friend_count].surname, friends[friend_count].name, friends[friend_count].middle_name, friends[friend_count].birthdate, friends[friend_count].address, friends[friend_count].phone) != EOF) 
    {
    friend_count++;
    }
    fclose(f);
}

void get_friends_by_birthmonth() 
{
    int month;
    printf("Enter birth month: ");
    scanf("%d", &month);
    for (int i = 0; i < friend_count; i++)  
    {
        int fmonth;
        sscanf(friends[i].birthdate, "%*d.%d.%*d", &fmonth);
        if (fmonth == month) 
        {
            printf("%s %s %s %s %s %s\n", friends[i].surname, friends[i].name, friends[i].middle_name, friends[i].birthdate, friends[i].address, friends[i].phone);
        }
    }
}

int main() 
{
    load_friends_from_file();
    int choice;
    do 
    {
        printf("\n1. Print friends\n");
        printf("2. Add friend\n");
        printf("3. Delete friend\n");
        printf("4. Get friends by birth month\n");
        printf("5. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
            print_friends();
            break;
            case 2:
            add_friend();
            break;
            case 3:
            delete_friend();
            break;
            case 4:
            get_friends_by_birthmonth();
            break;
        }
    } while (choice != 5);
    save_friends_to_file();
    return 0;
}
