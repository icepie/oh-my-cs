#include "test.h"

void PrintSort(int array[], int len)
{

    for (int i = 0; i < len; i++)
    {
        printf("%d\n", array[i]);
    }
}

void BubbleSort(int array[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (array[j] < array[j + 1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
