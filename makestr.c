/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 19:40:14 by vtenigin          #+#    #+#             */
/*   Updated: 2016/08/03 20:36:01 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		file_size(char *file)
{
	int		fd;
	char	buffer;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &buffer, 1))
		i++;
	close(fd);
	return (i);
}

void	makestr(char *str, char *file)
{
	int		fd;
	char	buffer;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &buffer, 1))
	{
		str[i] = buffer;
		i++;
	}
	str[i] = '\0';
	close(fd);
}

int		linelen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char	*makeinfo(char *str, int len)
{
	int		i;
	char	*info;

	i = 0;
	info = (char*)malloc(sizeof(char) * len + 1);
	while (str[i] != '\n')
	{
		info[i] = str[i];
		i++;
	}
	info[i] = '\0';
	return (info);
}
