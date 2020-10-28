#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int f=0,r=-1,ch;
int item,q[10];

int isFull(){
    return (r==SIZE-1) ? 1 : 0;
}

int isEmpty(){
    return (f>r) ? 1 : 0;
}

void insertRear(){
    if(isFull()){
        printf("Queue Overflow\n");
        return;
    }
    r+=1;
    q[r] = item;
}

void insertFront(){
    if(f!=0){
        f+=1;
        q[f] = item;
        return;
    }else if(f==0 && r==-1){
        q[++r] = item;
        return;
    }else{
        printf("Insertion not possible\n");
    }
}

void deleteRear(){
    if(isEmpty()){
        printf("Queue is empty\n");
        f = 0;
        r = -1;
        return;
    }
    printf("Item deleted is %d\n",q[r--]);
}

void deleteFront(){
    if(isEmpty()){
        printf("Queue is empty\n");
        f=0;
        r=-1;
        return;
    }
    printf("Item deleted is %d",q[f++]);
}

void display(){
    int i;
    if(isEmpty()){
        printf("Queue is empty");
        return;
    }
    for(i=f;i<=r;i++){
        printf("%d ",q[i]);
    }
}


void main(){
    int flag = 1;

    while(flag == 1){
        printf("\n\n1.insert rear\n2.insert front\n3.delete rear\n4.delete front\n5.display\n6.exit\n");
	    printf("enter choice: ");
	    scanf("%d",&ch);
	    switch(ch){
            case 1: printf("\nenter the item: ");
                    scanf("%d",&item);
                    insertRear();
                    break;
            case 2: printf("\nenter the item: ");
                    scanf("%d",&item);
                    insertFront();
                    break;
            case 3: deleteRear();
                    break;
            case 4: deleteFront();
                    break;
            case 5: display();
                    break;
            default: exit(0);
        
        }
    }
}
