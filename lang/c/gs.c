#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void sum1()
{

    int s = 1;
    int e = 100;
    int sum1 = 0;

    while (s <= e)
    {
        sum1 = sum1 + s;
        s = s + 1;
    }

    printf("The sum1 is %d\n", sum1);
}

void sum2()
{

    int sum2 = 0;

    for (int i = 1; i <= 100; i++)
    {
        sum2 = sum2 + i;
    }

    printf("The sum2 is %d\n", sum2);
}

void test()
{
    int a[10];

    for (int i = 0; i <= 9; i++)
    {
        a[i] = i + 1;
        printf("%d", a[i]);
        printf("\n");
    }
    printf("%lu\n", sizeof(a));
}

//冒泡排序
void BubbleSort()
{
    int a[10] = {1, -9, 23, 78, 4, 5, 6, 0, 9};
    //数组元素的个数=总大小/某个元素的大小
    int n = sizeof(a) / sizeof(a[0]);

    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1 - i; i++)
        {
            if (a[i] < a[i + 1])
            {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    printf("The test number is %d\n", n);

 /*

    int b[10];
    int tmp = a[0];

    for (int i = 0 ; i < 10; i++)
    {
        tmp=(tmp < a[i] ? a[i] : tmp) ;
    }
    


    printf("The sum1 is %d\n",tmp);
*/
}

void random1 ()
{
    srand((unsigned int)time(0));
    int i = 0;
    int tmp = 0;

    for ( i = 0; i < 10; i++)
    {
        tmp = rand();
        printf("%d\n",tmp);
    }
    

}

int main(void)

{
    //    sum1();
    //    sum2();
    //    test();
    // BubbleSort();
    random1();
    return 0;
}