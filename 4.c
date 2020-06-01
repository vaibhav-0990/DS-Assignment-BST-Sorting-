#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
    char data [10] ;
    struct node* lc;
    struct node* rc;
}node;
node* root;
void inorder(node * root)//Inorder traversal of array
{
    if (!root)return;
    inorder(root->lc);
    printf ("%s ",root->data);
    inorder(root->rc);
}
node * insert(node* t,char * c)// the insert function , it inserts single element at appropriate position in a BST
{
    if (!t){.  // if we have found the position to be inserted 
        t=(node*)malloc(sizeof(node));
        strcpy(t->data,c);
        return t;
    }
    else if (strcmp(t->data,c)>0)//node to be inserted is lesser than current node
        t->lc=insert(t->lc,c);
    else if (strcmp(t->data,c)<0)//node to be inserted is greater than current node
        t->rc=insert(t->rc,c);
    return t;
}
int main()//driver function
{
    char str[6][10]={"Arthi", "Christy", "Dorothy", "Fraser", "Eliza","David"};//test cases
    int y=0;
    while(y<6){                         //inserting elements one by one
        root=insert(root,str[y]);
        y++;
    }
    inorder(root);
}
