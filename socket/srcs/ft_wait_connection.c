#include "ft_socket.h"

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
