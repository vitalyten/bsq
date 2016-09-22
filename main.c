/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 12:54:48 by qho               #+#    #+#             */
/*   Updated: 2016/08/03 20:55:46 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	freearr(int **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_stdin_grid(void)
{
	int		fd;
	char	buffer;

	fd = open("stdin_grid", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	while (read(0, &buffer, 1))
		write(fd, &buffer, 1);
	close(fd);
}

int		bsq(char *name)
{
	char		*fstr;
	char		*info;
	char		*grid;
	t_legend	*legend;

	legend = (t_legend*)malloc(sizeof(t_legend));
	legend->size = file_size(name);
	fstr = (char*)malloc(sizeof(char) * legend->size + 1);
	makestr(fstr, name);
	legend->isize = linelen(fstr);
	info = makeinfo(fstr, legend->isize);
	grid = makegrid(fstr, legend->isize + 1, legend->size);
	free(fstr);
	interpret(info, legend);
	legend->max = 0;
	legend->width = linelen(grid);
	if (linecheck(0, legend->width, grid) || ft_valid(legend, grid))
	{
		ft_putstr("map error\n");
		return (-1);
	}
	findmax(legend, grid);
	return (0);
}

int		main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	if (argc > 1)
		while (i < argc)
		{
			if (i > 1)
				ft_putchar('\n');
			if (((fd = open(argv[i], O_RDONLY)) == -1))
				ft_putstr("map error\n");
			else
			{
				close(fd);
				bsq(argv[i]);
			}
			i++;
		}
	else
	{
		ft_stdin_grid();
		bsq("stdin_grid");
	}
	return (0);
}
