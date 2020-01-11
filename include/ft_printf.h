#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define FT_PRINTF_BUFF_SIZE 4096

int     ft_printf(const char *format, ...);
int     read_format(int fd, char *print_buf, const char *format, va_list ap);

#endif