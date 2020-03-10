#include <stdio.h>
#include "ft_printf.h"

int main (int argc, char **argv)
{
    char *p = "aaaa";

    int a = printf   ("Hello This is a test for -%20p- printf!\n", p);
    int b = ft_printf("Hello This is a test for -%20p- printf!\n", p);
    printf("difference in returns:  |%d|%d|\n", a, b);
    return (0);
}