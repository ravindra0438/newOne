#include<stdio.h>
void insertionSort(int arr[], int n);
int main()
{

    int arr[] = {13,46,24,52,20,9};
    insertionSort(arr,6);
    for(int i=0;i<6;i++)
    {
        printf("%d ", arr[i]);
    }

}

void insertionSort(int arr[], int n)
{


    for(int i=1;i<n;i++)
    {
        int j=i;

         while(j>0)
    {
        if(arr[j]< arr[j-1])
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1]= temp;
        }
        j--;

    }
    }
   
}