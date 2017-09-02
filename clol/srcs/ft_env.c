/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 23:23:12 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/10 22:04:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_find_env(char const **env, char const *variable)
{
	uint32_t	i;

	i = 0;
	while (variable[i] && variable[i] != '=')
		i++;
	while (*env)
	{
		if (!ft_strncmp(variable, *env, i))
			return ((char*)*env);
		else
			env++;
	}
	return (NULL);
}

uint32_t	ft_get_env_count(char **env)
{
	uint32_t	i;

	if (!env)
		return (0);
	i = 0;
	while (env[i])
		i++;
	return (i);
}

void		ft_free_t_env(t_env *env)
{
	uint32_t	i;

	i = 0;
	if (!env)
		return ;
	while (i < env->variable_count)
	{
		free(env->env[i]);
		i++;
	}
	free(env->env);
	free(env);
}

void		ft_free_t_shenv(t_shenv *shenv)
{
	uint32_t	i;

	i = 0;
	while (i < shenv->count)
	{
		free(shenv->var[i]);
		i++;
	}
	free(shenv->var);
	ft_free_t_env(shenv->env);
	free(shenv->attr);
	free(shenv);
}

t_env		*ft_get_env(t_shenv *shenv)
{
	uint32_t	i;
	uint32_t	u;
	uint32_t	count;
	char		**env;
	t_env		*environ;

	count = ft_shenv_get_env_count(shenv);
	if (!(environ = (t_env*)malloc(sizeof(t_env)))
		|| !(env = (char**)ft_memalloc(sizeof(char*) * (count + 1))))
		exit(EXIT_FAILURE);
	i = 0;
	u = 0;
	while (i < shenv->count)
	{
		if (shenv->attr[i] && ft_strchr(shenv->var[i], '='))
			if (!(env[u++] = ft_strdup(shenv->var[i])))
				exit(EXIT_FAILURE);
		i++;
	}
	environ->variable_count = count;
	environ->env = env;
	return (environ);
}
