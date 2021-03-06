#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *Node;

Node getNode(){
    Node x;
    x = (Node)malloc(sizeof(struct node));
    if(x == NULL){
        printf("Memory Full\n");
        exit(0);
    }
    return x;
}

Node insert(int data, Node root){
    Node temp,cur,prev;
    char direction[10];
    int i;
    temp=getNode();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    return temp;
    printf("give direction to insert\n");
    scanf("%s",direction);
    prev=NULL;
    cur=root;
    for(i=0;i<strlen(direction)&&cur!=NULL;i++)
    {
    prev=cur;
    if(direction[i]=='l')
    cur=cur->left;
    else
    cur=cur->right;
    }
    if(cur!=NULL||i!=strlen(direction))
    {
    printf("insertion not possible\n");
    free(temp);
    return(root);
    }
    if(cur==NULL)
    {
    if(direction[i-1]=='l')
    prev->left=temp;
    else
    prev->right=temp;
    }
    return(root);

}

void preorder(Node root){
    if(root != NULL){
        printf("the item is %d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node root){
    if(root!=NULL){
        inorder(root->left);
        printf("the item is%d\n",root->data);
        inorder(root->right);
    }
}
void postorder(Node root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("the item is%d\n",root->data);
    }
}

void display(Node root, int i){
    int j;
    if(root != NULL){
        display(root->right, i+1);
        for(j=1;j<=i;j++){
            printf("  ");
        }
        printf("%d\n", root->data);
        display(root->left, i+1);
    }
}

void main(){
    Node root = NULL;
    int choice,i,item,flag = 1;
    while(flag == 1){
        printf("1. insert\n2. preorder\n3. inorder\n4. postorder\n5. display\n");
        printf("Enter the choice: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the item: \n");
                    scanf("%d", &item);
                    root = insert(item,root);
                    break;
            case 2: if(root == NULL){
                        printf("Tree is empty\n");
                    }else{
                        printf("Given Tree: \n");
                        display(root,1);
                        printf("Preorder Traversal: \n");
                        preorder(root);     
                    }
                    break;
            case 3: if(root == NULL){
                        printf("Tree is empty\n");
                    }else{
                        printf("Given Tree: \n");
                        display(root,1);
                        printf("Inorder Traversal: \n");
                        inorder(root);     
                    }
                    break;
            case 4: if(root == NULL){
                        printf("Tree is empty\n");
                    }else{
                        printf("Given Tree: \n");
                        display(root,1);
                        printf("postorder Traversal: \n");
                        postorder(root);     
                    }
                    break;
            case 5: display(root, 1);
                    break;
            default: exit(0);                                              
        }
    }

}