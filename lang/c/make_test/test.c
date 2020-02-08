#include "test.h"

int main(void)
{
    int a[] = {1, 33, 55, 34, 45, 56, 65};

    int len = sizeof(a) / sizeof(a[0]);

    printf("排序前:\n");

    PrintSort(a, len);

    printf("排序后:\n");

    BubbleSort(a, len);
    PrintSort(a, len);

    return 0;
}
