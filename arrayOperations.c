#include<stdio.h>
#include<string.h>
int find(int arr[], int *n, int val);
void insertAtAnyPosition(int arr[], int *n, int size, int value, int pos);
void deleteAtAnyPosition(int arr[], int *n, int pos);

void insertElementLast(int arr[], int *n, int value, int size )
{
    
    if(*n>= size )
    {
        printf("array size is full \n");
        return;
    }
    arr[*n] = value;
    *n=*n+1;

}

void insertAtAnyPosition(int arr[], int *n, int size, int value, int pos)
{
    if(*n >= size )
    {
        printf("array size is full \n");
        return;
    }

    for(int i=(*n)-1;i>=pos;i--)
    {
        arr[i+1] = arr[i];
    }
    arr[pos] = value;
    *n= *n+1;

}

void deleteAtLast(int arr[], int *n)
{
    if (*n<0)
    {
        printf("there is no elements to delete \n");

    }

    arr[*n-1]= 0;
    *n = *n-1;
}




void display(int arr[], int *n)
{
    printf("\n");
    for(int i=0;i<*n;i++)
    {
        printf("%d ", arr[i]);
    }
}

void deleteAtAnyPosition(int arr[], int *n, int pos)
{
    if (*n<0)
    {
        printf("there is no elements to delete \n");

    }
    int i=0;
    for( i= pos;i<*n-1;i++)
    {
        arr[i] = arr[i+1];
    }
    arr[i] =0;
    *n = *n-1;

}
void deleteValue(int arr[], int *n, int val )
{
    int res= find(arr, n, val);
    if(res ==-1)
    {
        printf("there is no element like %d in array\n", val);
        return;
    }
    deleteAtAnyPosition(arr, n,res);
}


int find(int arr[], int *n, int val)
{
    for(int i=0;i<*n;i++)
    {
        if ((arr[i] == val))
        {
           return i;
        }
        

    }
    return -1;
}

int av(int arr[] , int st, int n)
{
  
   
    if(st == n-1)
    {
        return arr[st];

    }
   
   
    return  (arr[st] + av(arr,st+1,n));
   

 
    
}
double arrayAverage(int arr[], int len) 
{
    printf("len : %d\n", len);
    return av(arr,0, len)/(double)len;
}
int main()
{
    int arr[10]  = {100,99,98,97,96};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("length :%d \n", len);
    int n=5;
    int val=90;
    
     insertElementLast(arr, &n, 80, len);
     display(arr, &n);
       insertElementLast(arr, &n, 70, len);
     display(arr, &n);
     insertAtAnyPosition(arr, &n,  len, 2,2);
       
     display(arr, &n);
insertAtAnyPosition(arr, &n,  len, 1,1);
       
     display(arr, &n);
     insertAtAnyPosition(arr, &n,  len, 0,0);
       
     display(arr, &n);
        deleteAtLast(arr, &n);
        display(arr, &n);
        deleteAtAnyPosition(arr, &n,0);
        display(arr, &n);
        deleteAtAnyPosition(arr, &n,2);
        display(arr, &n);
        deleteAtAnyPosition(arr, &n,3);
        display(arr, &n);
        deleteValue(arr, &n, 97);
        display(arr, &n);
         insertElementLast(arr, &n, 80, len);
     display(arr, &n);
     deleteValue(arr, &n, 80);
        display(arr, &n);
        printf("length :%d \n", len);
        printf("\n%f average ", arrayAverage(arr,n));
        
    
}