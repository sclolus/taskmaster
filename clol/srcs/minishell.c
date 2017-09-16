/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <sclolus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 01:21:08 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/20 06:17:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "../../socket/includes/ft_socket.h"
#include "get_next_line.h"

char		**ft_get_env_value(char **env, char *variable)
{
	char		**path;
	char		*tmp;
	uint32_t	len;
	uint32_t	variable_len;
	char		*var;

	path = NULL;
	tmp = NULL;
	variable_len = ft_strlen(variable);
	if (!(var = ft_find_env((char const**)env, variable)))
		return (NULL);
	if (!(path = ft_strsplit(var, ':')))
		exit(EXIT_FAILURE);
	if (!(tmp = ft_strdup(*path)))
		exit(EXIT_FAILURE);
	len = ft_strlen(tmp) - variable_len - 1;
	ft_strncpy(*path, tmp + variable_len + 1, len + 1);
	free(tmp);
	return (path);
}


void		ft_main_cleanup(t_shenv *shenv)
{
	ft_free_t_shenv(shenv);
	ft_free_t_shell();
	ft_exit_shell(0);
}

static void	ft_clean_loop(char **line)
{
	if ((*ft_get_line_attributes()).multiple_lines)
	{
		free(*line);
		*line = NULL;
	}
}

static void	ft_main_loop(char **line, t_shenv *shenv, t_connection *connection)
{
	while (42)
	{
		ft_set_and_put_prompt(NORMAL_PROMPT);
		ft_termget_complete_line(line, shenv);
		ft_write_socket(*line, connection->fd);
		ft_clean_loop(line);
	}
}

int			main(int argc,  char **argv, char **env)
{
	char		*line;
	t_shenv		*shenv;
	int		socketfd;
	t_connection	connection;

	if (argc != 3)
	    return(-1);
	line = NULL;
	ft_init_shell();
	shenv = ft_init_shenv(ft_get_env_count(env), env);
	*ft_get_shenv() = shenv;
	ft_putchar('\n');
	socketfd = ft_create_socket(PF_INET, SOCK_STREAM, 0);
	connection.fd = socketfd;
	inet_pton(PF_INET, argv[1], &connection.addr.sin_addr);
	connection.addr.sin_port = htons(ft_atoi(argv[2]));
	if (-1 == connect(connection.fd, (const struct sockaddr*)&(connection.addr), sizeof(connection.addr)))
	{
	    perror("connect");
	    return(-1);
	}
	printf("connected\n");
	ft_watch_socket(connection.fd, READ_SET);
	ft_main_loop(&line, shenv, &connection);
	ft_main_cleanup(shenv);
	return (0);
}
