#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
int check() {
    if (head == NULL){
        printf("THE LIST IS EMPTY: ENTER SOME ELEMENTS.");
        return 1;
    }
    else {
        return 0;
    }
}

void display(){
    check();
    struct node *block = head;
    printf("\n{");

    while(block != NULL) {
        printf("%d ->",block->data);
        block = block -> link;
    }
    printf("END");
    printf("}");
}

void insertStart(){
    int data;
    printf("ENTER DATA: THIS DATA WILL BE INSERTED AT THE START OF THE LIST: ");
    struct node *block = (struct node*)malloc(sizeof(struct node));
    if(scanf("%d",&data) != 1){
        printf("INVALID INPUT...");
        exit(1);
    }
    block->data = data;
    block->link = head;
    head = block;
}

void insertEnd() {

    int data;
    struct node *block = (struct node*)malloc(sizeof(struct node));
    printf("ENTER DATA: THIS DATA WILL BE INSERTED AT THE END OF THE LIST: ");
    if(scanf("%d",&block->data) != 1){
        printf("INVALID INPUT...");
        exit(1);
    }
    struct node *temp = head;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = block;
}

int length(){
    int len=0;
    struct node *block = head;
    while(block != NULL){
        len++;
        block = block->link;
    }
    return len;
}

void insertPosition(){
    int pos;
    int data;
    int len = length();
    printf("ENTER POSITION WHERE THE NEW NODE IS TO BE INSERTED: ");
    if(scanf("%d",&pos) != 1){
        printf("INVALID INPUT...");
        exit(1);
    }
    while (pos > len){
        printf("POSITION OUT OF BOUNDS, RETRY... \n");
        printf("ENTER POSITION WHERE THE NEW NODE IS TO BE INSERTED: ");
        scanf("%d",&pos);
    }
    struct node *thenewnode;
    thenewnode = malloc(sizeof(struct node));
    printf("ENTER THE DATA THAT IS TO BE INSERTED INTO THE NODE: ");
    if(scanf("%d",&thenewnode->data) != 1){
        printf("INVALID INPUT...");
        exit(1);
    }

    struct node *previous = head;
    for(int i = 0; i < pos; i++){
        if(previous->link != NULL){
            previous = previous->link;
        }
    }

    thenewnode->link = previous->link;
    previous->link = thenewnode;
}

void del(){
    head = head->link;
}

void delEnd(){
    struct node *block = head;
    while(block->link != NULL){
        block = block->link;
        block->link = NULL;
    }
}

void delNode(){
    int key;
    printf("ENTER THE NODE THAT HAS TO BE DELETED: ");
    if(scanf("%d",&key) != 1){
        printf("INVALID INPUT...");
        exit(1);
    }
    struct node *temp=head, *prev;
    if(temp !=NULL && temp->data == key){
        head = temp->link;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->link;
    }
    prev->link = temp->link;

}

void searchEl() {
    int data;
    printf("\n ENTER THE DATA TO SEARCH IN LIST: ");
    if(scanf("%d",&data) != 1){
        printf("INVALID INPUT...");
        exit(1);
    }
    struct node *temp = head;
    while (temp != NULL){
        if (temp->data == data){
            printf(" [+] DATA FOUND.. ");
            break;
        }
        else {
        printf(" [-] 404 :( ");
        }
        temp=temp->link;
    }
}

int main() {
    int choice;
    int option;
    while(1){
        printf("\n1: Create a Linked List: ");
        printf("\n2: View Created List: ");
        printf("\n3: Display size of the List: ");
        printf("\n4: Delete a node: ");
        printf("\n5: Search an element: ");
        printf("\n[+] Select Option: ");
        scanf("%d",&choice);
        if (choice == 1){
            printf("WHERE WOULD YOU LIKE TO INSERT THE NEW NODE? : \n 1: START \n 2: IN BETWEEN \n 3: AT THE END \n");
            scanf("%d",&option);
            if (option == 1){
                insertStart();
            }
            else if (option == 2){
                if (check()){
                    main();
                }
                else {
                    insertPosition();
                }
            }
            else if (option == 3){
                if (check()){
                    main();
                }
                else{
                    insertEnd();
                }
            }
            else {
                printf("[!] WRONG OPTION SElECTED :( ");
            }
        }
        else if (choice == 2){
            display();
        }
        else if (choice == 3){
            printf("%d", length());
        }
        else if (choice == 4){
            if (check()){
                main();
            }
            else {
                printf("FROM WHERE WOULD YOU LIKE TO DELETE THE NODE?: \n1: START \n2: END \n3: A SPECIFIC NODE \n");
                scanf("%d",&option);
                if (option == 1){
                    del();
                }
                else if (option == 2){
                    delEnd();
                }
                else if (option == 3){
                    delNode();
                }
                else {
                    printf("[!] WRONG OPTION SELECTED :(");
                }
            }
        }
        else if (choice == 5){
            searchEl();
        }
        else {
            printf("[!] Invalid Input...");
        }
    }
    return 0;
}