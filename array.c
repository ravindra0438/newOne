#include<stdio.h>
int distinct(int arr[], int n) {

    // code here
    int count=0;
    int distinct =0;
    for (int i=0;i<n;i++)
    {  
        distinct =0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]== arr[j])
            {
                distinct++;
            }
        }
        if(distinct ==1)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int arr[4]= {1,2,3,4};
    
    printf("%d", distinct(arr,4));  
}