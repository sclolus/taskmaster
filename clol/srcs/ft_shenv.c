/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <sclolus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 22:22:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/24 18:35:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int32_t	ft_unset_var(t_shenv *shenv, char *var)
{
	char	**tmp;
	char	**var_tmp;
	t_bool	*attr_tmp;

	if ((tmp = ft_find_var(shenv, var)))
	{
		if (!(var_tmp = (char**)ft_memalloc(sizeof(char*) * shenv->count))
		|| !(attr_tmp = (t_bool*)malloc(sizeof(t_bool) * (shenv->count - 1))))
			exit(EXIT_FAILURE);
		ft_memcpy(var_tmp, shenv->var, (tmp - shenv->var) * sizeof(char*));
		ft_memcpy(var_tmp + (tmp - shenv->var), tmp + 1, (shenv->count
									- (tmp - shenv->var)) * sizeof(char*));
		ft_memcpy(attr_tmp, shenv->attr, (tmp - shenv->var) * sizeof(t_bool));
		ft_memcpy(attr_tmp + (tmp - shenv->var), shenv->attr
					+ 1 + (tmp - shenv->var)
					, (shenv->count - (tmp - shenv->var) - 1) * sizeof(t_bool));
		free(*tmp);
		free(shenv->var);
		free(shenv->attr);
		shenv->attr = attr_tmp;
		shenv->var = var_tmp;
		shenv->count--;
		return (0);
	}
	return (EXIT_VAR_NOT_FOUND);
}

char	**ft_find_var(t_shenv *shenv, char *var)
{
	uint32_t	i;
	uint32_t	u;

	i = 0;
	u = 0;
	if (!shenv->var)
		return (NULL);
	while (var[i] && var[i] != '=')
		i++;
	while (shenv->var[u])
	{
		if (!ft_strncmp(var, shenv->var[u], i) && (shenv->var[u][i] == '='
												|| !(shenv->var[u][i])))
			return (shenv->var + u);
		else
			u++;
	}
	return (NULL);
}

void	ft_modify_var(t_shenv *shenv, char *var)
{
	char	**tmp;

	tmp = NULL;
	if (!shenv->var || !shenv->count)
	{
		if (!(shenv->var = (char**)ft_memalloc(sizeof(char*))))
			exit(EXIT_FAILURE);
		shenv->count = 0;
	}
	if ((tmp = ft_find_var(shenv, var)))
	{
		free(*tmp);
		if (!(*tmp = ft_strdup(var)))
			exit(EXIT_FAILURE);
	}
	else
		ft_add_var(shenv, var);
}

void	ft_add_var(t_shenv *shenv, char *var)
{
	char	**tmp;
	t_bool	*attr;

	if (!(tmp = (char**)malloc(sizeof(char*)
							* (shenv->count + 2))))
		exit(EXIT_FAILURE);
	tmp[shenv->count + 1] = NULL;
	ft_memcpy(tmp, shenv->var, sizeof(char**) * shenv->count);
	if (!(tmp[shenv->count] = ft_strnew(ft_strlen(var))))
		exit(EXIT_FAILURE);
	ft_strcpy(tmp[shenv->count], var);
	free(shenv->var);
	if (!(attr = ft_memalloc(sizeof(t_bool) * (shenv->count + 1))))
		exit(EXIT_FAILURE);
	ft_memcpy(attr, shenv->attr, (sizeof(t_bool) * (shenv->count)));
	free(shenv->attr);
	shenv->attr = attr;
	shenv->var = tmp;
	shenv->count++;
}

t_shenv	*ft_init_shenv(uint32_t argc, char **env)
{
	uint32_t	i;
	t_shenv		*shenv;

	if (!(shenv = (t_shenv*)ft_memalloc(sizeof(t_shenv))))
		exit(EXIT_FAILURE);
	if (!(env))
		return (shenv);
	i = 0;
	while (i < argc)
	{
		ft_modify_var(shenv, env[i]);
		ft_set_var_to_export(shenv, env[i++]);
	}
	return (shenv);
}
