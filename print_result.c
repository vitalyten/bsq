/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 13:16:05 by vtenigin          #+#    #+#             */
/*   Updated: 2016/08/03 19:56:18 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_result(int **arr, t_legend *l)
{
	int i;
	int j;

	i = 0;
	while (i < l->lines)
	{
		j = 0;
		while (j < l->width)
		{
			if (arr[i][j] == 0)
				ft_putchar(l->obst);
			if (arr[i][j] == 1)
			{
				if (i <= l->x && i > (l->x - l->max) &&
					j <= l->y && j > (l->y - l->max))
					ft_putchar(l->full);
				else
					ft_putchar(l->empty);
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	freearr(arr, l->lines);
}

char	*makegrid(char *str, int ilen, int len)
{
	int		i;
	char	*grid;

	i = 0;
	grid = (char*)malloc(sizeof(char) * len - ilen + 1);
	while (i + ilen < len)
	{
		grid[i] = str[i + ilen];
		i++;
	}
	grid[i] = '\0';
	return (grid);
}
