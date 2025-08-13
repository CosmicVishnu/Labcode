#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*top=NULL;

void push(int value){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data=value;
    NewNode->next=top;
    top=NewNode;
}
int pop(){
    if (top==NULL){
        printf("stack is empty\n");
        return -1;
    }
    struct Node*temp=top;
    int PoppedValue=temp->data;
    top=top->next;
    free(temp);
    return PoppedValue;
}

int peek(){
    if (top==NULL){
        printf("Stack is Empty\n");
        return -1;
    }else{
        return top->data;
    }
}

void PrintStack(){
    if (top==NULL){
        printf("stack is empty\n");
        return;
    }
    struct Node*current=top;
    printf("stack:\n");
    while(current!=NULL){
        printf("%d\t",current->data);
        current=current->next;
    }
    printf("\n");
}

int main(){
    int choice,value;
    while(1){
        printf("1. Push Element\n2. Pop Element\n3. Peek\n4. Display stack\n5. Exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            {
                printf("enter value to add\n");
                scanf("%d",&value);
                push(value);
                break;
            }
            case 2:
            {
                printf("%d\n",pop());
                break;
            }
            case 3:
            {
                printf("%d\n",peek());
                break;
            }
            case 4:
            PrintStack();
            break;
            
            case 5:
            exit(0);
            
            default:
            printf("invalid choice\n");
            break;
        }
    }
    return 0;
}
