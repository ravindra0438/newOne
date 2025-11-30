#include<stdio.h>
void printSnakePattern(int n, int m, int arr[m][n]);
int main()
{
     int arr[4][4] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    printSnakePattern(4,4,arr);
    int array[2][3] = {{1, 2, 3}, {4, 5, 6}};
printf("\n%d", (*(*(array+1)+2)));

}
void printSnakePattern(int n, int m, int arr[m][n])
{

    for(int i=0;i<n;i++)
    {
        if(i%2 ==0)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ", arr[i][j]);
            }
        }
        else
        {
            for(int j=n-1;j>=0;j--)
            {
                printf("%d ", arr[i][j]);

            }
        }
    }
}


