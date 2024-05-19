#include <stdio.h>
#include <stdlib.h>

int TestFunction()
{
   printf("Hello World\n");

   return 0;
}

int main(int argc, char *argv[])
{
    int ret = 0;

    ret = TestFunction();

    if (ret != 0)
    {
        printf ("Test failed: %d\n", ret);
    }

    return ret;
} 
