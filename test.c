#include <stdio.h>
#include "libftprintf.h"

int main (int argc, char **argv)
{
    char *p = "aaaa";

    char *s = "hey \n there is a newline";
    
    int a = printf   ("p:%09s$\n", "012345", 'o', 'p');
    int b = ft_printf("f:%09s$\n", "012345", 'o', 'p');
    printf("difference in returns:  |%d|%d|\n", a, b);
    return (0);
}
