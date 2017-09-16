#include "ft_socket"
#include "minishell.h"

void	ft_update_read_on_socket(t_string *buf)
{
    static char buffer[1024];
    ssize_t	ret;
    int		socket;

    socket = ft_socket_to_read();
    res = tgetstr("cr", NULL);
    while ((ret = read(socket, buffer, 1024)))
	write(1, buffer, ret);
    write(1, "\n", 1);
    ft_tercaps_putstr(buf, NULL);
    g_read_on_socket = 0;
}
