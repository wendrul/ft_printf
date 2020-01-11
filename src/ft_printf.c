#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    va_list     ap;

    va_start(ap, format);
    return (ft_fd_printf(1, format, ap));
}

int     ft_dprintf(int fd, const char *format, ...)
{
    va_list     ap;

    va_start(ap, format);
    return (ft_fd_printf(fd, format, ap));
}

int     ft_sprintf(char *str, const char *format, ...)
{
    va_list     ap;

    va_start(ap, format);
    str[0] = '\0';
    return (read_format(-1, str, format, ap));
}

int     ft_fd_printf(int fd, const char *format, va_list ap)
{
    char        print_buf[FT_PRINTF_BUFF_SIZE + 1];

    print_buf[0] = '\0';
    print_buf[FT_PRINTF_BUFF_SIZE] = '\0';
    return (read_format(fd, print_buf, format, ap));
}