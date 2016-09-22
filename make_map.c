/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:47:31 by qho               #+#    #+#             */
/*   Updated: 2016/08/03 19:53:03 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		find_height(char *str)
{
	int k;
	int i;

	k = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			k++;
		i++;
	}
	return (k);
}

int		ft_getint(char c, t_legend *legend)
{
	int ans;

	if (c == legend->empty)
		ans = 1;
	if (c == legend->obst)
		ans = 0;
	return (ans);
}

int		**makemap(char *grid, t_legend *legend)
{
	int		i;
	int		j;
	int		k;
	int		**map;

	i = 0;
	k = 0;
	map = (int**)malloc(sizeof(int*) * legend->lines);
	while (i < legend->lines)
	{
		j = 0;
		map[i] = (int*)malloc(sizeof(int) * legend->width);
		while (j < legend->width)
		{
			map[i][j] = ft_getint(grid[k], legend);
			if (grid[k + 1] != '\n')
				k++;
			else
				k += 2;
			j++;
		}
		i++;
	}
	free(grid);
	return (map);
}
