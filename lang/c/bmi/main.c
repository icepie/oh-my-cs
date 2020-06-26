#include "bm.h"
int main()
{
    int a,b;
    // Define height and weight
    printf("Please enter the weight(KG):\n");
    scanf("%d",&a);
    // Get variable
    printf("Please enter height(CM):\n");
    scanf("%d",&b);
    // Get variable
    printf("BMI:%0.2f\n",bmi(a,b));
    // Using BMI functions
}