#include <stdlib.h>
#include <stdio.h>

int main()
{

    for (int i = 0; i < 5; i++)
    {
        for (int k = 5; k > i; k--)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}