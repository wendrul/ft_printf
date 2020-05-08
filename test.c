#include <stdio.h>
#include "libftprintf.h"

int main (int argc, char **argv)
{
    char *p = "aaaa";

    int a = printf   ("%c%c%c%c%c%c%c\n", 'p', 0, 'c', 'd', 'e', 'f', 'g');
    int b = ft_printf("%c%c%c%c%c%c%c\n", 'f', 0, 'c', 'd', 'e', 'f', 'g');
    printf("difference in returns:  |%d|%d|\n", a, b);
    return (0);
}
