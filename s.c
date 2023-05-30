#include <stdio.h>
#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



int main(){
    struct contact Contacts[100];
    int num = 0;
    char name[50];
    int x;
    while(1){
        printmenu();
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_contact(Contacts, &num);
                break;
            case 2:
                list_contacts(Contacts, num);
                break;
            case 3:
                printf("Enter Name: ");
                scanf("%s", &name);
                x = search_contact(Contacts, num, name);
                if(x != -1)
                    printf("Contact Exists\n");
                else
                    printf("Contact Doesn't Exist\n");
                break;
            case 4:
                printf("Enter Name: ");
                scanf("%s", &name);
                print_contact_details(Contacts, num, name);
                break;
            case 5:
                printf("Enter Name: ");
                scanf("%s", &name);
                remove_contact(Contacts, &num, name);
                break;
            case 6:
                printf("Enter Name: ");
                scanf("%s", &name);
                update_contact(Contacts, num, name);
                break;
            default:
                exit(1);
        }
        getchar();
        getchar();
        system("clear");
    }

    return 0;
}