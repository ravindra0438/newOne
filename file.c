#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *ptr = fopen("fathr.txt","r");
   char arr[100];
    while(fgets(arr, 100, ptr))
    {
    
      
        printf("%s\n", arr);
        

    }
    fclose(ptr);

    FILE *ptr1= fopen("father.txt", "a");
    fprintf(ptr1, "\n am facing some issues in my body Nanna , keep with me and support our family......\n");
    return 0;
}