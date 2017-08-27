#include "ft_socket.h"

inline int	ft_create_socket(const int domain, const int type, const int protocol)
{
    int	socketfd;

	if (-1 == (socketfd = socket(domain, type, protocol)))
	    perror("ft_create_socket()");
	return (socketfd);
}
