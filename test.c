#include <stdio.h>
#include "libftprintf.h"

int main (int argc, char **argv)
{
    char *p = "aaaa";

    int a = printf   ("(null)", (char)0);
    int b = ft_printf("(null)", (char)0);
    printf("difference in returns:  |%d|%d|\n", a, b);
    return (0);
}