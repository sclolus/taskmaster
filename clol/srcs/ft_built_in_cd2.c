/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_cd2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 19:07:47 by aalves            #+#    #+#             */
/*   Updated: 2017/04/29 05:50:57 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int32_t		rst_tstring(t_string *str)
{
	if (!str->string)
	{
		str->string = ft_strnew(MAX_PATH_NAME);
		str->capacity = MAX_PATH_NAME;
	}
	ft_bzero(str->string, MAX_PATH_NAME);
	str->len = 0;
	str->offset = 0;
	return (1);
}

int32_t		ft_get_pwd(t_string *curpath, t_shenv *shenv)
{
	char	**pwd;

	if ((pwd = ft_find_var(shenv, "PWD")))
	{
		ft_t_string_concat(curpath, *pwd + 4);
		return (1);
	}
	else
		return (0);
}

int32_t		ft_create_path(t_string *dst, char *path, char *op)
{
	uint64_t	is_data;

	is_data = dst->len;
	dst->offset = 0;
	ft_t_string_insert(dst, path);
	if (path[ft_strlen(path) - 1] != '/')
		ft_t_string_insert(dst, "/");
	if (!is_data)
		ft_t_string_concat(dst, op);
	return (1);
}

char		ft_cdpath_search(t_string *curpath, char *op, t_shenv *shenv)
{
	char		**cdpath;
	char		*path;
	char		*end;
	size_t		len;
	DIR			*dir;

	if (!(cdpath = ft_find_var(shenv, "CDPATH")))
		return (0);
	path = ft_strchr(*cdpath, '=') + 1;
	while (path && *path)
	{
		end = ft_strchr(path, ':');
		len = end ? end - path : ft_strlen(path);
		if (!len && (len = 2))
			ft_t_string_concat(curpath, "./");
		else
			ft_memcpy(curpath->string, path, len);
		curpath->string[len] = (curpath->string[len - 1] == '/') ? '\0' : '/';
		ft_t_string_concat(curpath, op);
		if ((dir = opendir(curpath->string)) && closedir(dir))
			return (1);
		rst_tstring(curpath);
		path = (end) ? end + 1 : NULL;
	}
	return (0);
}

int32_t		ft_cd_set_oldpath(t_shenv *shenv)
{
	char		**oldpwd;
	char		tmp[MAX_PATH_NAME + 10];
	char		cwd[MAX_PATH_NAME];

	if (!(oldpwd = ft_find_var(shenv, "OLDPWD")))
		ft_putchar('\n');
	else
	{
		if (!getcwd(cwd, MAX_PATH_NAME))
			return (ft_error(1, (char*[]){"cd: Unable to get CWD"}, -1));
		if (chdir(*oldpwd + 7) == -1)
			return (ft_error(3, (char*[]){"cd: "
					, (*oldpwd + 7), ": No such file or directory"}, -1));
			ft_putendl(*oldpwd + 7);
		ft_modify_var(shenv, *oldpwd + 3);
		ft_strcpy(tmp, "OLDPWD=");
		ft_strcpy(tmp + 7, cwd);
		ft_modify_var(shenv, tmp);
	}
	return (0);
}
