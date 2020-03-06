#include <stdio.h>
#include "ft_printf.h"

int main (int argc, char **argv)
{
    printf   ("Hello This is a test for-%4097s printf!\n", "Hello");
    ft_printf("Hello This is a test for-%4097s printf!\n", "Hello");
    return (0);
}