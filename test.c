#include <stdio.h>
#include "libftprintf.h"

int main (int argc, char **argv)
{
    char *p = "aaaa";

    char *s = "hey \n there is a newline";
    int a = printf   ("-%c%c-", (char)10, (char)11);
    int b = ft_printf("-%c%c-", (char)10, (char)11);
    printf("difference in returns:  |%d|%d|\n", a, b);
    return (0);
}
