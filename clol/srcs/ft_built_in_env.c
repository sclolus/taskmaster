/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <sclolus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 06:54:33 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/12 04:26:01 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static uint32_t			ft_count_values(char **argv)
{
	uint32_t	i;
	uint32_t	count;

	i = 1;
	count = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], '='))
			count++;
		i++;
	}
	return (count);
}

static int32_t			ft_get_flag(char *flag)
{
	static const char	flags[] = "i";
	static char			buf[] = "--";
	uint32_t			ret;
	uint32_t			i;
	char				tmp;

	i = 1;
	tmp = 0;
	if (*flag != '-')
		return (0);
	while (flag[i])
	{
		if ((ret = ft_strchr_index((char*)flags, flag[i])) < 1)
			tmp |= 1 << ret;
		else
		{
			buf[1] = flag[i];
			ft_error(3, (char*[]){"env: ", buf, ": invalid option"}, 0);
			return (ft_error(1, (char*[]){"usage: env \
[-i] [name=value ...] [utility [argument ...]]"}, -1));
		}
		i++;
	}
	return (tmp);
}

static void				ft_normilol(t_shenv *shenv, t_shenv *exec_env)
{
	shenv->env = ft_get_env(shenv);
	exec_env->env = ft_get_env(exec_env);
	setpgid(0, getpid());
	ft_unset_term();
	ft_unset_insert();
	tcsetpgrp(g_shell->terminal, getpid());
}

static int32_t			ft_lisibilitay(char **argv, uint32_t *argc,
					t_shenv *shenv, t_shenv **exec_env)
{
	int32_t		flag;

	flag = 0;
	if ((flag = ft_get_flag(argv[1])) == -1)
		exit(EXIT_FAILURE);
	*argc = ft_count_values(argv + flag);
	if (flag == 1)
		*exec_env = ft_create_new_shenv(argv + 1, *argc);
	else
		*exec_env = ft_modify_env(argv, *argc
		, ft_init_shenv(shenv->env->variable_count, shenv->env->env));
	if (!argv[*argc + flag + 1] && !(ft_built_in_print_env(*exec_env)))
		exit(EXIT_SUCCESS);
	return (flag);
}

int32_t					ft_built_in_env(char **argv, t_shenv *shenv)
{
	int32_t		flag;
	uint32_t	argc;
	int32_t		ret;
	pid_t		pid;
	t_shenv		*exec_env;

	if (!argv[1])
		return (ft_built_in_print_env(shenv));
	if ((pid = fork()) == -1)
		ft_error_exit(1, (char*[]){"env: Fork() failed"}, 1);
	if (pid)
	{
		waitpid(pid, &ret, 0);
		ft_put_shell_in_foreground();
		return (POSIX_EXIT_STATUS(ret));
	}
	else
	{
		exec_env = NULL;
		flag = ft_lisibilitay(argv, &argc, shenv, &exec_env);
		ft_normilol(shenv, exec_env);
		ft_built_in_exec_env_cmd(argv + argc + 1 + flag, shenv, exec_env);
	}
	return (0);
}
