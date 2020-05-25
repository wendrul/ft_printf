#include <stdio.h>
#include "libftprintf.h"

int main (int argc, char **argv)
{
    char *p = "aaaa";

    char *s = "hey \n there is a newline";
    
    int a = printf   ("p:%.0u$\n", 3, 'o', 'p');
    int b = ft_printf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", 12);
    printf("difference in returns:  |%d|%d|\n", a, b);
    return (0);
}
