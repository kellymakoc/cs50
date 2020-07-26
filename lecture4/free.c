// http;//valgrind.org/docs/manual/quick-start.html#quick-start.prepare
#include <stdlib.h>

//free is a better version of malloc as malloc uses lots of bytes

void f(void)
{
    int *x = malloc(10 * sizeof(int));  //allocate the memory of the 10 integers
    x [9] = 0;
    free(x); // free the memory after using
}

int main (void)
{
    f();
    return 0;
}