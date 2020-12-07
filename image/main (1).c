#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t,i,T;
    char a[50];
    scanf ("%d",&T);
    getchar();
    for (t = 1; t <= T; t++)
    {
        //gets(a);
        scanf ("%s", &a);
        if ((a[0] == '_' || a[0] >= 'A') && (a[0] <= 'Z' || a[0] >= 'a') && (a[0] <= 'z'))
            for (i = 1; i < strlen(a); i++)
            {
              if((a[i] == '_')||(a[i] >= '0' && a[i] <= '9')||(a[i] >= 'A' && a[i] <= 'Z')||(a[i] >= 'a' && a[i] <= 'z'))
              {
                  continue;
              }
              else
                {
                   break;
                   printf ("no\n");
                }
                if (i + 1 == strlen(a))
                    printf ("yes\n");
            }
        else printf ("no\n");

    }
    return 0;
}
