#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
    int cols,rows;
    printf("Please Enter Number Of rows: ");
    scanf("%d",&rows);
    printf("Please Enter Number Of columns: ");
    scanf("%d",&cols);
    int matrix[rows][cols];
    int vector[cols];
    int result[rows];
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("Please Enter Element Of the Matrix %d %d \n",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    for(i=0;i<cols;i++)
    {
        printf("Please Enter Element Of the Vector %d \n",i);
        scanf("%d",&vector[i]);
    }
    printf("\n");
    #pragma omp parallel
    {
    #pragma omp for
    for(i=0;i<rows;i++)
    {
        printf("%d",omp_get_thread_num());
        printf(" took %d", i);
        for(j=0;j<cols;j++)
        {
            result[i]+=matrix[i][j]*vector[j];
        }
        printf("\n");
    }
   }
   /***end of parallel region***/
   for(i=0;i<rows;i++)
    {
        printf("%d\n",result[i]);
    }
    return 0;
}
