#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#define SIZE 3

int item,front=0,rear=-1,q[10];

void insertRear(){
    if(rear == SIZE-1){
        printf("Queue Overflow\n");
        return;
    }
    rear += 1;
    q[rear] = item;
}

int deleteFront(){
    if(front>rear){
        front = 0;
        rear = -1;
        return -1;
    }
    return q[front++];
}

void displayQueue(){
    int i;
    if(front>rear){
        printf("Queue is empty\n");
        return;
    }
    printf("Contents of Queue: \n");
    for(i=front;i<=rear;i++){
        printf("%d ",q[i]);
    }
}

void main(){
    int choice,flag=0;

    while(flag == 0){
        printf("\n1. Insert Rear\n2. Delete Front\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                printf("Item to be inserted: ");
                scanf("%d",&item);
                insertRear();
                break;
            }

            case 2:{
                item = deleteFront();
                if(item == -1){
                    printf("Queue is empty\n");
                }else{
                    printf("Item deleted = %d\n",item);
                }
                break;
            }

            case 3:{
                displayQueue();
                break;
            }
            default: exit(0);
        }
    }
}