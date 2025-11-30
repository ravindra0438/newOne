#include<stdio.h>

void helper(int arr[], int d, int n)
{
     int i=0;
     int temp = arr[0];
     for( i=0;i<n-1;i++)
    {
        arr[i] = arr[i+1];
    }
    arr[i]= temp;
    return ;
}
void leftRotate(int arr[], int d, int n) {
    // code here
   
   while(d>0)
   {
   helper(arr, d,n);
    d--;
   }
}

int main()
{
    
   char str1[] = "hello";
   char str2[] = "hello";

   if (str1 == str2)
      printf("Equal");
   else
      printf("Not Equal");

   return 0;

}