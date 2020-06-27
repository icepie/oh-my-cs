#include <stdio.h>

#define PAUSE {printf("Press Enter key to continue..."); fgetc(stdin);}

int main()
{
    PAUSE
    return 0;
}