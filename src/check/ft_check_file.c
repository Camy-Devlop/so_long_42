/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:38:54 by isadbaib          #+#    #+#             */
/*   Updated: 2025/02/25 12:02:42 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static bool	ft_file_check_type(char *name_file)
{
	int	len;

	if (!name_file)
		return (false);
	len = ft_strlen(name_file);
	if (len <= 4)
		return (false);
	if (ft_strcmp(&name_file[len - 4], TYPE_FILE))
		return (false);
	return (true);
}

static bool	ft_file_exist(const char *name_file)
{
	int		fd;
	bool	res;

	res = true;
	fd = open(name_file, O_RDONLY);
	if (fd <= 0)
		return (false);
	close(fd);
	return res;
}

static bool ft_file_access_read(char *name_file)
{
	
	int		fd;
	bool	res;

	res = true;
	fd = open(name_file, O_RDONLY);
	if (fd <= 0)
		return (false);
	if (ft_goto_end_file(fd)== -1)
		return (close(fd),false);
	close(fd);
	return res;
}
bool	ft_file_check(char *name_file)
{
	if (!ft_file_check_type(name_file))
		return (ft_err_file(0), false);
	if (!ft_file_exist(name_file))
		return (ft_err_file(1), false);
	if (!ft_file_access_read(name_file))
		return (ft_err_file(2), false);
	return (true);
}
