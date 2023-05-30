#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct contact
{
    char name[50];
    long int ph_no;
    char gender[8];
    char email[100];
};

void printmenu(){
    printf("1) Add Contact\n");
    printf("2) List Contacts\n");
    printf("3) Search For a Contact\n");
    printf("4) Print Contact Details\n");
    printf("5) Remove Contact\n");
    printf("6) Update Contact\n");
    printf("7) Exit\n");
}

void add_contact(struct contact Contacts[], int * sz){
    char name[50];
    long int ph_no;
    char gender[10];
    char email[100];
    printf("Enter Contact's Name: \n");
    scanf("%s", &name);
    printf("Enter Contact's Phone Number: \n");
    scanf("%ld", &ph_no);
    printf("Enter Contact's Gender: \n");
    scanf("%s", &gender);
    printf("Enter Contact's email: \n");
    scanf("%s", &email);
    strcpy(Contacts[*sz].name, name);
    Contacts[*sz].ph_no = ph_no;
    strcpy(Contacts[*sz].gender, gender);
    strcpy(Contacts[*sz].email, email);
    *sz = *sz + 1;
    printf("Contact Has Been Added Successfully\n");
}
void list_contacts(struct contact Contacts[], int  sz){
    for(int i = 0; i < sz; i++){
        printf("Name: %s\n", Contacts[i].name);
        printf("Phone Number: %ld\n", Contacts[i].ph_no);
        printf("Gender: %s\n", Contacts[i].gender);
        printf("email: %s\n", Contacts[i].email);
        printf("------------------------------------------------------------\n");
    }
}
int search_contact(struct contact Contacts[], int  sz, char name[]){
    for(int i = 0; i < sz; i++){
        if (strcmp(Contacts[i].name, name) == 0){
            return i;
            printf("%d", i);
        }
    }
    return -1;
}
void print_contact_details(struct contact Contacts[], int  sz, char name[]){
    int x = search_contact(Contacts, sz, name);
    if(x == -1){
        printf("Contact Doesn't Exist\n");
    }
    else{
        printf("Contact's Phone Number: %ld\n", Contacts[x].ph_no);
        printf("Contact's Gender: %s\n", Contacts[x].gender);
        printf("Contact's email: %s\n", Contacts[x].email);
    }
}
void remove_contact(struct contact Contacts[], int * sz, char name[]){
    int x = search_contact(Contacts, *sz, name);
    if(x == -1){
        printf("Contact Doesn't Exist\n");
    }
    else{
        for(int i = x + 1; i < *sz; i++){
            strcpy(Contacts[i - 1].name, Contacts[i].name);
            Contacts[i - 1].ph_no = Contacts[i].ph_no;
            strcpy(Contacts[i - 1].gender, Contacts[i].gender);
            strcpy(Contacts[i - 1].email, Contacts[i].email);
        }
        printf("Contact Deleted Successfully");
        *sz = *sz - 1;
    }
}
void update_contact(struct contact Contacts[], int  sz, char name[]){
    int x = search_contact(Contacts, sz, name);
    long int ph_no;
    char gender[10];
    char email[100];
    int choice;
    if(x == -1){
        printf("Contact Doesn't Exist\n");
    }
    else{
        printf("Choose What You Want To Update: \n");
        printf("1) Phone Number\n");
        printf("2) Gender\n");
        printf("3) email\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter New Phone Number: \n");
            scanf("%ld", &ph_no);
            Contacts[x].ph_no = ph_no;
            break;
        case 2:
            printf("Enter Gender: \n");
            scanf("%s", &gender);
            strcpy(Contacts[x].gender, gender);
            break;
        default:
            printf("Enter New email: \n");
            scanf("%s", &email);
            strcpy(Contacts[x].email, email);
            break;
        }
        printf("Contact Updated Successfully");
    }
}

