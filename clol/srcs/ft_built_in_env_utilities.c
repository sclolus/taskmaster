/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_env_utilities.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:06:24 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/10 22:24:38 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_env_put_error(char *file, char *msg, int exit_status)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	exit(exit_status);
}

t_shenv		*ft_modify_env(char **argv, uint32_t count, t_shenv *shenv)
{
	uint32_t	i;

	i = 1;
	if (!shenv)
		ft_error_exit(1
		, (char*[]){"malloc() failed to init subshell environnement"}, 1);
	while (i < count + 1)
	{
		ft_modify_var(shenv, argv[i]);
		ft_set_var_to_export(shenv, argv[i]);
		i++;
	}
	return (shenv);
}

t_shenv		*ft_create_new_shenv(char **argv
										, uint32_t count)
{
	uint32_t	i;
	t_shenv		*new_shenv;

	i = 1;
	if (!(new_shenv = (t_shenv*)ft_memalloc(sizeof(t_shenv))))
		exit(EXIT_FAILURE);
	while (i < count + 1)
	{
		ft_modify_var(new_shenv, argv[i]);
		ft_set_var_to_export(new_shenv, argv[i++]);
	}
	return (new_shenv);
}

void		ft_built_in_exec_env_cmd(char **argv
						, t_shenv *shenv, t_shenv *exec_env)
{
	char	*bin;
	char	*path;

	if (!(path = ft_find_command(argv[0], ft_get_env_value(shenv->env->env,
																"PATH"))))
	{
		if (ft_find_file(argv[0], shenv->env) > 0)
		{
			if (!ft_check_exec_perm(argv[0]))
				ft_error_exit(2, (char *[]){ERR_PERM_DENIED
							, argv[0]}, EXIT_NO_PERM);
			execve(argv[0], argv, exec_env->env->env);
			ft_error_exit(2, (char *[]){ERR_PERM_DENIED
						, argv[0]}, EXIT_NO_PERM);
		}
		ft_env_put_error(argv[0], "No such file or directory", 1);
	}
	if (!(path = ft_strjoin_f(path, "/", 0)))
		ft_error_exit(2, (char *[]){ERR_MALLOC, argv[0]}, EXIT_FAILURE);
	if (!(bin = ft_strjoin(path, argv[0])))
		ft_error_exit(2, (char *[]){ERR_MALLOC, bin}, EXIT_FAILURE);
	if (access(bin, X_OK))
		ft_error_exit(2, (char *[]){ERR_PERM_DENIED, bin}, EXIT_NO_PERM);
	execve(bin, argv, exec_env->env->env);
	ft_env_put_error(bin, ERR_PERM_DENIED, EXIT_NO_PERM);
}

int32_t		ft_built_in_print_env(t_shenv *shenv)
{
	uint32_t	i;

	i = 0;
	while (i < shenv->count)
	{
		if (shenv->attr[i])
			ft_putendl(shenv->var[i]);
		i++;
	}
	return (0);
}
