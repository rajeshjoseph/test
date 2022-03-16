#include <stdio.h>

int TestFunction()
{
    printf("Hello World!\n");
    return 0; 
}

int main(int argc, char *argv[])
{
    int ret = 0;

    ret = TestFunction();

    return ret;
}
