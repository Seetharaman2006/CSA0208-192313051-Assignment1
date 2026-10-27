#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    int a = 5;
    int b = 8;

    printf("Square of %d = %d\n", a, SQUARE(a));
    printf("Maximum of %d and %d = %d\n", a, b, MAX(a, b));
    printf("Square of a + 1 = %d\n", SQUARE(a + 1));

    /* Avoid arguments such as i++ in macros that may evaluate them twice. */
    int i = 3;
    printf("Square of i = %d\n", SQUARE(i));
    i++;
    printf("i after increment = %d\n", i);

    return 0;
}
