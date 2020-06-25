#include "bm.h"
int main()
{
    int a,b;
    printf("Please enter the weight(KG):\n");
    scanf("%d",&a);
    printf("Please enter height(CM):\n");
    scanf("%d",&b);
    printf("BMI:%0.2f\n",bmi(a,b));
}