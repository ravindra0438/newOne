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
	    printf("queue is null\n)";
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

struct TNode * createTnode()
{
    struct TNode *tn= (struct TNode *)malloc(sizeof(struct TNode));
    if(tn!=NULL)
    {
    tn->left=NULL;
    tn->right=NULL;
    }
    return tn;
    

}

int isEmpty(struct QNode *q)
{
    return q->front == NULL;
}
void insertInTree(struct Tree *t, int data)
{
    if(t==NULL)
    {
        printf("tree is NULL\n");
        return;
    }
    struct TNode *tn= createTnode();
    if(tn==NULL)
    {
        printf("memory allocation fails\n");
        return;
    }
    tn->data=data;
    if(t->root == NULL)
    {
        t->root=tn;
        return;
    }
    struct QNode *q= createQNode();
    if(q== NULL)
    {
        printf("queue is NULL\n");
        return;
    }
    enqueue(q,t->root);
    while(!isEmpty(q))
    {
        struct TNode *temp=dequeue(q);
        if(temp->left == NULL)
        {
            temp->left=tn;
            
            break;
        }
        else if(temp->right ==NULL)
        {
            temp->right=tn;
          
          break;
        }
        else
        {
            enqueue(q,temp->left);
            enqueue(q, temp->right);
        }
       


        }
        free(q);
        

}
struct TNode* getDeepestNode(struct TNode *root)
{
    if(root == NULL)
    {
        printf("root is null\n");
        return NULL;

    }
    struct QNode *q= createQNode();
    if(q==NULL)
    {
        printf("Memory allocation fails for queue\n");
        return NULL;
    }
    struct TNode *lastNode=NULL;
    enqueue(q,root);
    while(!isEmpty(q))
    {
        lastNode= dequeue(q);
        if(lastNode->left!=NULL)
        {
            enqueue(q,lastNode->left);
        }
        if(lastNode->right!=NULL)
        {
            enqueue(q,lastNode->right);
        }
        
    }
    free(q);
    return lastNode;
    
}

void deleteLastNode (struct TNode *root, struct TNode *toDelete)
{

    if(root== NULL)
    {
        printf("tree is NULL\n");
        return;
    }
    struct QNode *q= createQNode();
    if(q==NULL)
    {
        printf("memory allocation is fails\n");
        return;
    }
    enqueue(q, root);
    while(!isEmpty(q))
    {
        struct TNode *temp= dequeue(q);
        if(temp->left == toDelete)
        {
            temp->left=NULL;
            break;
        }
        else if(temp->right ==toDelete)
        {
            temp->right =NULL;
            break;
        }
        else{
            if(temp->left !=NULL)
                enqueue(q,temp->left);
            if(temp->right !=NULL)
             enqueue(q,temp->right);
        }
    }
    free(q);
    
  
}
void deleteNode (struct Tree *t,int value)
{
    if(t==NULL ||t->root== NULL)
    {
        printf("tree is NULL\n");
        return;
    }
    
    if(t->root->left == NULL && t->root->right ==NULL && t->root->data ==value)
    {
        printf("\n%d deleted \n", value);
        free(t->root);
        t->root=NULL;
        return;
    }
    struct QNode *q= createQNode();
    if(q==NULL)
    {
        printf("memory allocation is fails\n");
        return;
    }
    enqueue(q, t->root);
    int flag=0;
    while(!isEmpty(q))
    {
        struct TNode *tn=dequeue(q);
        if(tn->data == value)
        {
            struct TNode *lastNode= getDeepestNode(t->root);
            if(lastNode == NULL)
            {
                printf("lastNode is NULL\n");
                return;
            }
            tn->data= lastNode->data;
            deleteLastNode(t->root,lastNode);
            flag=1;
            free(lastNode);
            lastNode=NULL;
            break;

        }
        else 
        {
            if(tn->left !=NULL)
                 enqueue(q,tn->left);
            if(tn->right !=NULL)
        {
            enqueue(q,tn->right);
        }
        }
        
    }

    if(flag==1)
    {
        printf("\n%d is deleted \n", value);
    }
    else{
        printf("\n%d is not found\n", value);
    }
    free(q);

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
int main()
{
    struct Tree *t = createTree();
    insertInTree(t, 10);
    
    InOrder(t->root);
    deleteNode(t, 10);
    InOrder(t->root);
}

