#include <stdio.h>
#include "ft_printf.h"

int main (int argc, char **argv)
{
    int a = printf   ("Hello This is a test for %02X printf!\n", "ff");
    int b = ft_printf("Hello This is a test for %02X printf!\n", "ff");
    printf("diffs rets |%d|%d|",a,b);
    return (0);
}