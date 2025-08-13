#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*head=NULL;

void InsertEnd(int value){
    struct Node*NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=value;
    NewNode->next=NULL;

    if (head==NULL){
        head=NewNode;
    }else{
        struct Node*temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=NewNode;
    }
}

void InsertBeginning(int value){
    struct Node*NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=value;
    NewNode->next=head;
    head=NewNode;
}

void InsertAtPosition(int value,int position){
    struct Node*NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=value;
    NewNode->next=NULL;
    if (position==1){
        NewNode->next=head;
        head=NewNode;
        return;
    }
    struct Node*temp=head;
    for(int i=1;i<position-1;i++){
        if(temp==NULL){
            printf("invalid position\n");
            return;
        }
        temp=temp->next;
    }
    NewNode->next=temp->next;
    temp->next=NewNode;      
}

void DeleteAtBeginning(){
    if(head==NULL){
        printf("linked list is empty\n");
    }
    struct Node*temp=head;
    head=head->next;
    free(temp);
}

void DeleteAtEnd(){
    if (head==NULL){
        printf("linked list is empty\n");
    }
    if (head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void DeleteAtPosition(int position){
    if(position==1){
        struct Node*temp=head;
        head=head->next;
        free(temp);
        return;
    }

    struct Node* temp=head;
    for(int i=1;i<position-1;i++){
        if(temp==NULL){
            printf("invalid position\n");
        }
        temp=temp->next;
    }
    if(temp->next==NULL){
            printf("invalid position\n");
        }
    struct Node* DeleteNode=temp->next;
    temp->next=DeleteNode->next;
    free(DeleteNode);

}

void display(){
    if(head==NULL){
        printf("linked list is empty\n");
    }
    struct Node* temp=head;
    printf("linked list\n");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice,value,position;
    while(1){
        printf("1. insert at End\n2. Inster at Beginning\n3. Insert at given POsition\n4. Delete at Beginning\n5. Delete at End\n6. Delete at Given Position\n7. Display Linked List\n8. Exit");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            {
                printf("enter value to add\n");
                scanf("%d",&value);
                InsertEnd(value);
                break;
            }
            case 2:
            {
                printf("enter value to add\n");
                scanf("%d",&value);
                InsertBeginning(value);
                break;
            }
            case 3:
            {
                printf("enter value to add\n");
                scanf("%d",&value);
                printf("enter position\n");
                scanf("%d",&position);
                InsertAtPosition(value,position);
                break;
            }
            case 4:
            DeleteAtBeginning();
            break;
            
            case 5:
            DeleteAtEnd();
            break;
            
            case 6:
            {
            printf("enter position\n");
                scanf("%d",&position);
                DeleteAtPosition(position);
                break;
            } 

            case 7:
            display();
            break;

            case 8:
            exit(0);

            default:
            printf("invalid choice\n");
            break;
        }
    }
    return 0;
}