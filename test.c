#include <stdio.h>
#include "libftprintf.h"

int main (int argc, char **argv)
{
    char *p = "aaaa";

    char *s = "hey \n there is a newline";
    
    int a = printf   ("p:%1.s$\n", "0123456789", 'o', 'p');
    int b = ft_printf("f:%1.s$\n", "0123456789", 'o', 'p');
    printf("difference in returns:  |%d|%d|\n", a, b);
    return (0);
}
