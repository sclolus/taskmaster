/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 21:12:16 by sclolus           #+#    #+#             */
/*   Updated: 2017/04/16 06:16:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		ft_set_export_flags(char *string)
{
	static const char	flags[] = "p";
	static char			buf[] = "--";
	uint32_t			ret;
	uint32_t			i;
	char				tmp;

	i = 1;
	tmp = 0;
	while (string[i])
	{
		if ((ret = ft_strchr_index((char*)flags, string[i])) < 1)
			tmp |= 1 << ret;
		else
		{
			buf[1] = string[i];
			ft_error(3, (char*[]){"export: ", buf, ": invalid option"}, 0);
			return (ft_error(1, (char*[]){"export: usage: export \
[name[=value] ...] or export -p"}, -1));
		}
		i++;
	}
	return (tmp);
}

static int32_t	ft_print_exported_var(t_shenv *shenv)
{
	uint32_t	i;
	uint32_t	count;

	i = 0;
	count = shenv->count;
	while (i < count)
	{
		if (ft_is_var_exported_index(shenv, i))
		{
			ft_static_put("export ", 7, 0);
			ft_static_put(shenv->var[i], ft_strlen(shenv->var[i]), 0);
			ft_static_put("\n", 1, 0);
		}
		i++;
	}
	ft_static_put(NULL, 0, STATIC_PUT_FLUSH);
	return (0);
}

int32_t			ft_built_in_export(char **argv, t_shenv *shenv)
{
	uint32_t	i;
	char		flag;

	i = 1;
	if (argv[1] && argv[1][0] == '-')
	{
		if ((flag = ft_set_export_flags(argv[1])) == -1)
			return (EXIT_FAILURE);
	}
	else
		flag = 0;
	if (flag || !argv[1])
		return (ft_print_exported_var(shenv));
	while (argv[i])
	{
		if (ft_strchr(argv[i], '=') || !ft_find_var(shenv, argv[i]))
			ft_modify_var(shenv, argv[i]);
		ft_set_var_to_export(shenv, argv[i]);
		i++;
	}
	return (0);
}
