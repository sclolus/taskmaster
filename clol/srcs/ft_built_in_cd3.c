/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_cd3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 02:06:47 by aalves            #+#    #+#             */
/*   Updated: 2017/05/12 10:44:52 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int32_t		ft_cd_set_env(char *cwd, t_shenv *shenv)
{
	char		tmp[MAX_PATH_NAME + 10];

	ft_strcpy(tmp, "OLDPWD=");
	ft_strcpy(tmp + 7, cwd);
	ft_modify_var(shenv, tmp);
	ft_bzero(tmp, sizeof(tmp));
	ft_strcpy(tmp, "PWD=");
	if (!getcwd(cwd, MAX_PATH_NAME))
		return (ft_error(1, (char*[]){"cd: Unable to get CWD"}, -1));
	ft_strcpy(tmp + 4, cwd);
	ft_modify_var(shenv, tmp);
	return (0);
}

static int32_t		lol(t_string *p, uint32_t size, uint32_t pos)
{
	ft_strcpy(p->string + p->offset - pos, p->string + p->offset + size);
	p->len -= size + pos;
	return (1);
}

static int32_t		do_str_shit(t_string *p)
{
	int64_t	i;

	i = 2;
	if (!ft_strncmp(p->string + p->offset, "./", 2) && lol(p, 2, 0))
		return (1);
	else if (!ft_strncmp(p->string + p->offset, "../", 3))
	{
		while (p->offset > i && p->string[p->offset - i] != '/')
			i++;
		if (p->offset < i && rst_tstring(p) && ft_t_string_concat(p, "/"))
			return (1);
		lol(p, 2, i);
		p->offset -= i;
		i = 2;
		return (1);
	}
	else if (!ft_strncmp(p->string + p->offset, "///", 3) && lol(p, 2, 0))
		return (1);
	else if (!ft_strncmp(p->string + p->offset, ".../", 4) && (p->offset += 4))
		return (1);
	return (0);
}

static int32_t		convert_path(t_string *p)
{
	if (p->string[ft_strlen(p->string) - 1] != '/')
		ft_t_string_concat(p, "/");
	p->offset = 0;
	while (p->string[p->offset])
	{
		if (!do_str_shit(p))
			p->offset++;
	}
	return (1);
}

int32_t				ft_check_chdir(t_string *curpath, char *arg, char *cwd
								, t_shenv *shenv)
{
	if (convert_path(curpath) && curpath->len > MAX_PATH_NAME)
	{
		return (ft_error(3, (char*[]){"cd: "
					, curpath->string, ": File name too long"}, -1));
	}
	if (!access(curpath->string, F_OK) && access(curpath->string, X_OK) == -1)
	{
		return (ft_error(3, (char*[]){"cd: "
					, arg, ": permission denied"}, -1));
	}
	if (chdir(curpath->string) == -1)
	{
		if (!ft_is_dir(curpath->string))
			return (ft_error(3, (char*[]){"cd: "
					, arg, ": Not a directory"}, -1));
			return (ft_error(3, (char*[]){"cd: "
					, arg, ": No such file or directory"}, -1));
	}
	return (ft_cd_set_env(cwd, shenv));
}
