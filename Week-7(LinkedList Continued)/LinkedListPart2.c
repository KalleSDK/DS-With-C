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

Node orderList(Node first,int item){
    Node temp,prev,cur;
    temp = getNode();
    temp->data = item;
    temp->next = NULL;
    if(first == NULL){
        printf("in first if\n");
        return temp;
    }
    if(item < first->data){
        printf("second if");
        temp->next = first;
        return temp;
    }
    prev = NULL;
    cur = first;
    while(cur != NULL && item > cur->data){
        printf("in while");
        prev = cur;
        cur = cur->next;
    } 
    prev->next = temp;
    temp->next = cur;
    return first;
}
Node insertPosition(int item, int pos, Node first){
    Node temp,prev,cur;
    int count;
    temp = getNode();
    temp->data = item;
    temp->next = NULL;
    if(first == NULL && pos == 1){
        return temp;
    }
    if(first == NULL){
        printf("invalid position\n");
        return first;
    }
    if(pos == 1){
        temp->next = first;
        return temp;
    }

    count = 1;
    prev = NULL;
    cur = first;
    while(cur!=NULL && count != pos){
        prev = cur;
        cur = cur->next;
        count++;
    }
    if(count == pos){
        prev->next = temp;
        temp->next = cur;
        return first;
    }
    printf("invalid position\n");
    return first;
}

Node deletePosition(int pos,Node first){
    Node cur,prev;
    int count;
    if(first == NULL || pos <=0){
        printf("invalid position\n");
        return NULL;
    }
    if(pos == 1){
        cur = first;
        first = first->next;
        free(cur);
        return first;
    }
    prev = NULL;
    cur = first;
    count = 1;
    while(cur!=NULL){
        if(count == pos){
            break;
        }
        prev = cur;
        cur = cur->next;
        count++;
    }
    if(count !=pos){
        printf("invalid position\n");
        return first;
    }
    prev->next = cur->next;
    free(cur);
    return first;
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
    int item,choice,flag = 1,pos;
    Node first = NULL;

    while(flag == 1){
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Order List\n6. Display\n7. Insert at\n8. Delete at\n9. Exit");
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
            case 5: printf("Enter item which will be inserted in order(ascending): \n");
                    scanf("%d",&item);
                    first = orderList(first,item);
                    break;
            case 6: display(first);
                    break;
            case 7: printf("Enter item to be inserted: \n");
                    scanf("%d",&item);
                    printf("Enter position to be inserted: \n");
                    scanf("%d",&pos);
                    first = insertPosition(item,pos,first);
                    break;
            case 8: printf("Enter position to be deleted: \n");
                    scanf("%d",&pos);
                    first = deletePosition(pos,first);
                    break;
            case 9: exit(0);
                    break;

            default: printf("Enter correct option!\n");                            
        }
    }
}

