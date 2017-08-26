#include "ft_socket.h"

inline int	ft_create_socket(const int domain, const int type, const int protocol)
{
    int	socketfd;

	if (-1 == (socketfd = socket(domain, type, protocol)))
	    perror("ft_create_socket()");
	return (socketfd);
}

inline int32_t	ft_wait_connection(const t_connection connection, const uint32_t max)
{
    if (-1 == (bind(connection.fd, (const struct sockaddr*)&(connection.addr)
					, sizeof(struct sockaddr))))
	{
		perror("ft_wait_connection.bind");
		return (-1);
	}
	if (-1 == (listen(connection.fd, max)))
	{
		perror("ft_wait_connection.listen");
		return (-1);
	}
	return (0);
}

inline ssize_t	ft_write_socket(const char *str, const int fd)
{
    return (write(fd, str, ft_strlen(str)));
}
