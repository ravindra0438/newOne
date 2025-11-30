#include<stdlib.h>
#include<stdio.h>
struct TNode{
    int data;
    struct TNode *left;
    struct TNode *right;
};
struct Tree{
    struct TNode *root;
};
struct Node {
    struct TNode *data;
    struct Node *next;
};
struct QNode{
    struct Node *front;
    struct Node *rear;
};


struct QNode * createQNode()
{
    struct QNode *q= (struct QNode *)malloc(sizeof(struct QNode));
    if(q== NULL)
    {
        return NULL;
    }
    q->front=NULL;
    q->rear=NULL;
    return q;
}


struct Tree * createTree()
{
    struct Tree *t=(struct Tree *)malloc(sizeof(struct Tree));
    if(t== NULL)
    {
        return NULL;
    }
    t->root=NULL;
    return t;
}

struct Node * createNode()
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode !=NULL)

        newNode->next=NULL;
    return newNode;
}

void enqueue(struct QNode *q, struct TNode *t)
{
    if(q==NULL || t == NULL)
    {
        printf("queue is NULL || tree is null\n");
        return;
    }
    struct Node *newNode = createNode();
    newNode->data=t;
   
    if(q->rear == NULL)
    {
        q->rear= newNode;
        q->front=newNode;
        return;
    }
    q->rear->next=newNode;
    q->rear=newNode;
    
}

struct TNode* dequeue(struct QNode *q)
{
    if(q==NULL|| q->front == NULL)
    {
        printf("queue is empty\n");
        return NULL;
    }

    struct TNode *data=q->front->data;
    struct Node *toDelete= q->front;

    if(q->front == q->rear)
    {
        q->front = q->rear= NULL;
    }
    else
    {
    
    q->front= q->front->next;
    }
    
    free(toDelete);
    toDelete=NULL;
    return data;
}

struct TNode * createTnode(int data)
{
    struct TNode *tn= (struct TNode *)malloc(sizeof(struct TNode));
    if(tn!=NULL)
    {
    tn->left=NULL;
    tn->right=NULL;
    tn->data=data;
    }
    return tn;
    

}

int isEmpty(struct QNode *q)
{
    return q->front == NULL;
}

struct TNode * insertInBinaryTree(struct TNode *root, int data)
{
    if(root == NULL)
    {
        return createTnode(data);
    }
    if(root->data == data)
    {
        return root;
    }
    if(root->data >  data)
    {
        root->left= insertInBinaryTree(root->left,data);
    }
    else
    {
        root->right=insertInBinaryTree(root->right, data);
    }
    return root;
}

void InOrder(struct TNode *root)
{
    if(root==NULL)
    {
        return;
    }

    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);

}
struct TNode * minimumNode(struct TNode *root)
{
    if(root !=NULL && root->left !=NULL)
    {
        return minimumNode(root->left);
    }
    return root;
}
struct TNode * deleteNode (struct TNode *root, int value)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->data > value)
    {
        root->left=deleteNode(root->left, value);
    }
    else if(root->data < value)
    {
        root->right=deleteNode(root->right, value);
    }
    else
    {
        if((root->left == NULL) )
        {
            struct TNode *temp=root->right;
            free(root);
            return temp;
        }
        else if( (root->right == NULL))
        {
            struct TNode *temp=root->left;
            free(root);
            return temp;
        }
        else{
            struct TNode *todelete= minimumNode(root->right);
            root->data= todelete->data;
            root->right= deleteNode(root->right, todelete->data);
        }
    }
    return root;
}
int max=0;
int getHeight(struct TNode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftHeight= getHeight(root->left);
    int rightHeight= getHeight(root->right);
    if((leftHeight+rightHeight+1)> max)
    {
        max = leftHeight+rightHeight+1;
    }
    return (1+ ((leftHeight> rightHeight)?leftHeight:rightHeight));
}

int diameter(struct TNode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    max =0;
    getHeight(root);
    return max;
    
    
}
    int main()
{
    struct Tree *t=createTree();
    t->root=insertInBinaryTree(t->root, 50);
    t->root=insertInBinaryTree(t->root, 40);
    t->root=insertInBinaryTree(t->root, 100);
      t->root=insertInBinaryTree(t->root, 30);
      t->root=insertInBinaryTree(t->root, 45);
    InOrder(t->root);
    printf("height of a tree  ==> %d\n", getHeight(t->root));
    printf("Diameter of a tree is %d \n", diameter(t->root));
    t->root=deleteNode(t->root, 40);
    printf("\n");
    InOrder(t->root);

    
}