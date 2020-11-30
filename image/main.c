#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,n,T,a[100][100];
    scanf ("%d",&T);
    for (k = 1; k <= T; k++)
    {
     scanf ("%d",&n);
     a[1][1]=1;
     printf ("1\n");
     for ( i = 2; i <= n; i++)
     {
        for ( j = 1; j <= i; j++)
        {
            /*if ( j == 1 || j == i)
                printf("1");
       else */     a[i][j]=a[i-1][j-1]+a[i-1][j];
            printf ("%d ",a[i][j]);
        }
        printf ("\n");
     }
    }
    return 0;
}
