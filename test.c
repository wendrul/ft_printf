#include <stdio.h>
#include "libftprintf.h"

int main (int argc, char **argv)
{
    char *p = "aaaa";

    char *s = "hey \n there is a newline";
    int a = printf   ("p-%c%c%c$\n", (char)9, (char)10, (char)10);
    int b = ft_printf("f-%c%c%c$\n", (char)9, (char)10, (char)10);
    //printf("difference in returns:  |%d|%d|\n", a, b);
    return (0);
}
