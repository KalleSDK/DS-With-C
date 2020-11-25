#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node *Node;

Node getNode(){
    Node x;
    x = (Node)malloc(sizeof(struct node));
    if(x == NULL){
        printf("mem full\n");
        exit(0);
    }
    return x;
}

void freeNode(Node x){
    free(x);
}

Node insertRear(Node first,int item){
    Node temp,current;
    temp = getNode();
    temp->data = item;
    temp->next = NULL;
    if(first == NULL){
        return temp;
    }
    current = first;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = temp;
    return first;
}

Node insertFront(Node first,int item){
    Node temp;
    temp = getNode();
    temp->data = item;
    temp->next = NULL;
    if(first == NULL){
        return temp;
    }
    temp->next = first;
    first = temp;
    return first;
}


Node deleteRear(Node first){
    Node current,previous;
    if(first == NULL){
        printf("List is empty cannot delete\n");
        return first;
    }
    if(first->next == NULL){
        printf("Item deleted is %d\n",first->data);
        free(first);
        return NULL;
    }
    previous = NULL;
    current = first;
    while(current->next != NULL){
        previous = current;
        current = current->next;
    }
    printf("item deleted at rear end is %d\n",current->data);
    free(current);
    previous->next = NULL;
    return first;
}

Node deleteFront(Node first){
    Node temp;
    if(first == NULL){
        printf("List is empty cannot delete\n");
        return first;
    }
    temp = first;
    temp = temp->next;
    printf("Item delted at front end is %d\n",first->data);
    free(first);
    return temp;
}

Node concat(Node first, Node second){
    Node cur;
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    cur = first;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = second;
    return first;
}
Node swap(Node a, Node b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void sort(Node first){
    int swapped, i;
    Node cur;

    if(first == NULL){
        printf("List is empty\n");
        return;
    }

    do{
        swapped = 0;
        cur = first;

        while(cur->next != NULL){
            if(cur->data > cur->next->data){
                swap(cur,cur->next);
                swapped = 1;
            }
            cur = cur->next;
        }
    }
    while(swapped);
}

Node reverse(Node first){
    Node cur,temp;
    cur = NULL;
    while(first!=NULL){
        temp = first;
        first = first->next;
        temp->next = cur;
        cur = temp;
    }
    return cur;
}

void display(Node first){
    Node temp;
    if(first == NULL){
        printf("List is empty cannot delete\n");
        return;
    }
    for(temp=first;temp!=NULL;temp = temp->next){
        printf("%d ",temp->data);
    }
    printf("\n");
}

void main(){
    int item,choice,flag = 1,n,i;
    Node first = NULL;
    Node a,b;    

    while(flag == 1){
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. reverse\n6.Concat\n7. Sort\n8. Display\n9. Exit\n");
        printf("\nEnter Your choice: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1: printf("Enter the item to be inserted at front: \n");
                    scanf("%d",&item);
                    first = insertFront(first,item);
                    break;
            case 2: printf("Enter the item to be inserted in the rear: \n");
                    scanf("%d",&item);
                    first = insertRear(first,item);
                    break;
            case 3: first = deleteFront(first);
                    break;
            case 4: first = deleteRear(first);
                    break;
            case 5: first = reverse(first);
                    display(first);
                    break;
            case 6: {
                printf("Enter number of node in List 1: \n");
                scanf("%d",&n);
                a = NULL;
                for(i=0;i<n;i++){
                    printf("Enter the item: \n");
                    scanf("%d",&item);
                    a = insertRear(a,item);
                }

                printf("Enter number of node in List 2: \n");
                scanf("%d",&n);
                b = NULL;
                for(i=0;i<n;i++){
                    printf("Enter the item: \n");
                    scanf("%d",&item);
                    b = insertRear(b,item);
                }

                a = concat(a,b);
                display(a);
                break;
            }
            case 7: sort(first);
                    display(first);
                    break;
            case 8: display(first);
                    break;
            case 9: exit(0);
                    break;
            default: printf("Enter correct option!\n");                            
        }
    }
}

