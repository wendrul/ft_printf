#include "ft_printf.h"

int     read_format(int fd, char *buf, const char *format, va_list ap)
{
    int     cnt;
    int     i;
    int     j;

    cnt = 0;
    i = -1;
    j = -1;
    while (format[++i])
    {
        if (fd != -1 && j >= FT_PRINTF_BUFF_SIZE)
        {
            cnt += j;
            j = 0;
            ft_putstr_fd(buf, fd);
        }
        if (format[i] == '%')
            i += read_flags(&format[i], &j, buf, fd);
        else
            buf[++j] = format[i];
    }
    buf[j] = '\0';
    fd != -1 ? ft_putstr_fd(buf, fd): (void)fd ;
    return (cnt + j);
}
