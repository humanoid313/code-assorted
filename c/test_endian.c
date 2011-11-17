#include <stdio.h>

int main (int argc, char *argv[])
{
    size_t sizeofInt = sizeof (int);
    int i;

    union
    {
        int x;
        char c[sizeof (int)];
    } original, swapped;

    original.x = 0x12345678;

    for (i = 0; i < sizeofInt; i++)
        swapped.c[sizeofInt - i - 1] = original.c[i];

    fprintf (stderr, "%x\n", swapped.x);

    return 0;
}
