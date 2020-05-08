#include <stdio.h>
#include "libftprintf.h"

int main (int argc, char **argv)
{
    char *p = "aaaa";

    char *s = "hey \n there is a newline";
    
    int a = printf   ("aa%-caaa %c  %c\n", 'w', 'o', 'p');
    int b = ft_printf("aa%-caaa %c  %c\n", 'w', 'o', 'p');
    printf("difference in returns:  |%d|%d|\n", a, b);
    return (0);
}
