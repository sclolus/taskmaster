#include "ft_socket.h"

inline ssize_t	ft_write_socket(const char *str, const int fd)
{
    return (write(fd, str, ft_strlen(str)));
}
