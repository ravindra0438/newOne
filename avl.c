#include<stdlib.h>
#include<stdio.h>
struct TNode{
    int data;
    struct TNode *left;
    struct TNode *right;
    int height;
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
    tn->height= 1;
    }
    return tn;
    

}
int max(int a , int b)
{
    return (a>b)? a:b;
}
/* rotateRight() function is used to rotate to the right 
we have a nodes are in the left-left condition*/
struct TNode* rotateRight(struct TNode* unbalancedNode)
{
    if(unbalancedNode == NULL)
    {
        return unbalancedNode;
    }

    struct TNode *newRoot= unbalancedNode->left;
    struct TNode *temp= newRoot->right;
    newRoot->right= unbalancedNode;
    unbalancedNode->left =  temp;
    unbalancedNode->height = max(getHeight(unbalancedNode->left), getHeight(unbalancedNode->right)) +1;
    newRoot->height= max(getHeight(newRoot->left), getHeight(newRoot->right))+1;
    return newRoot;

}

struct TNode* rotateLeft (struct TNode *unbalancedNode)

{
    if(unbalancedNode == NULL)
    {
        return unbalancedNode;
    }
    struct TNode *newRoot= unbalancedNode->right;
    struct TNode *temp = newRoot->left;
    newRoot->left = unbalancedNode;
    unbalancedNode->right= temp;
    unbalancedNode->height = max(getHeight(unbalancedNode->left), getHeight(unbalancedNode->right)) +1;
    newRoot->height= max(getHeight(newRoot->left), getHeight(newRoot->right))+1;
    return newRoot;
}


int isEmpty(struct QNode *q)
{
    return q->front == NULL;
}

int getHeight (struct TNode *root)
{
    if(root ==NULL)
    {
        return 0;
    }
    return root->height;
}
int getBalanceFactor(struct TNode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return getHeight(root->left)-getHeight(root->right);
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

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if(balance > 1 && data < root->left->data)
    {
        return rotateRight(root);
    }
    if(balance > 1 && data > root->left->data)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if(balance < -1 && data > root->right->data)
    {
        return rotateLeft(root);
    }
    if(balance < -1 && data < root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
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

void preOrder(struct TNode *root)
{
    if(root == NULL)
    {
        return;
    }
    printf ("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
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
            root=NULL;
            return temp;
        }
        else if( (root->right == NULL))
        {
            struct TNode *temp=root->left;
            free(root);

            root=NULL;
            return temp;
        }
        else{
            struct TNode *todelete= minimumNode(root->right);
            root->data= todelete->data;
            root->right= deleteNode(root->right, todelete->data);
        }
    }
    if(root== NULL)
    {
        return root;
    }
    root->height= 1 + max(getHeight(root->left), getHeight(root->right));
    int balance= getBalanceFactor(root);
    if(balance> 1 && getBalanceFactor(root->left)>=0)
    {
        return rotateRight(root);
    }
     if(balance> 1 && getBalanceFactor(root->left)<0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
     if(balance< -1 && getBalanceFactor(root->right)<=0)
    {
        return rotateLeft(root);
    }
     if(balance< -1 && getBalanceFactor(root->right)>0)
    {
        root->right=rotateRight(root->right);
        return rotateLeft(root);
    }


    return root;
}

int main()
{
    struct Tree *t=createTree();
    t->root=insertInBinaryTree(t->root, 30);
    t->root=insertInBinaryTree(t->root, 25);
    t->root=insertInBinaryTree(t->root, 35);
    t->root=insertInBinaryTree(t->root, 20);
    t->root=insertInBinaryTree(t->root, 15);
    t->root=insertInBinaryTree(t->root, 5);
    t->root=insertInBinaryTree(t->root, 10);
    t->root=insertInBinaryTree(t->root, 50);
    t->root=insertInBinaryTree(t->root, 60);
    t->root=insertInBinaryTree(t->root, 70);
    t->root=insertInBinaryTree(t->root, 65);
      
    InOrder(t->root);
   
    printf("\n");
    preOrder(t->root);

    t->root= deleteNode(t->root, 70);
    t->root= deleteNode(t->root, 60);
    t->root= deleteNode(t->root, 35);
    t->root= deleteNode(t->root, 25);
    t->root= deleteNode(t->root, 30);
    t->root= deleteNode(t->root, 15);
    t->root= deleteNode(t->root, 5);
    t->root= deleteNode(t->root, 10);
     printf("\n");
    InOrder(t->root);
   
    printf("\n");
    preOrder(t->root);




    return 0;

}
