#include <stdio.h>
#include "ft_printf.h"

int main (int argc, char **argv)
{
    printf   ("Hello This is a test for-%20s printf!\n", NULL);

    ft_printf("Hello This is a test for-%s printf!\n", "sss");
    return (0);
}