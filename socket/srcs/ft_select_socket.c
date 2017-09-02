#include "ft_socket.h"
#include <stdio.h>

t_sock_set	*ft_get_sock_set()
{
    static t_sock_set	sock_set;

    if (!sock_set.nfds)  //maybe check on all fields
    {
	sock_set.nfds = 1;
	FD_ZERO(&(sock_set.readfds));
	FD_ZERO(&(sock_set.writefds));
	FD_ZERO(&(sock_set.errorfds));
    }
    return (&sock_set);
}



void ft_watch_socket(int socketfd, int type)
{
    t_sock_set *sock_set;

    //type chooses fd_set
    if (type > 2)
	return ;
    sock_set = ft_get_sock_set();
    sock_set->nfds = (sock_set->nfds < socketfd + 1) ? socketfd + 1 : sock_set->nfds;
    if (type == 0)
	FD_SET(socketfd, &sock_set->readfds);
    else if (type == 1)
	FD_SET(socketfd, &sock_set->writefds);
    else
	FD_SET(socketfd, &sock_set->errorfds);
    printf("ici >> %d\n", sock_set->nfds);
}

void ft_unwatch_socket(int socketfd, int type)
{
    t_sock_set *sock_set;

    sock_set = ft_get_sock_set();
    if (type == 0)
	FD_CLR(socketfd, &sock_set->readfds);
    else if (type == 1)
	FD_CLR(socketfd, &sock_set->writefds);
    else
	FD_CLR(socketfd, &sock_set->errorfds);
}


//set a stack implementation to return all fds ?
int	ft_socket_to_read()
{
    int32_t	i;
    t_sock_set	*sock_set;
    struct timeval timeout;

    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    sock_set = ft_get_sock_set();
    if (-1 == select(sock_set->nfds, &sock_set->readfds, &sock_set->writefds, &sock_set->errorfds, &timeout))
    {
	perror("select");
	return (0);
    }
    i = 0;
    while (i < sock_set->nfds)
    {
	if (FD_ISSET(i, &sock_set->readfds)
	    || FD_ISSET(i, &sock_set->writefds)
	    || FD_ISSET(i, &sock_set->errorfds))
	    return (i);
	++i;
    }
    return (0);
}
