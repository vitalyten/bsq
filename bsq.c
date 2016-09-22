/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 13:16:05 by vtenigin          #+#    #+#             */
/*   Updated: 2016/08/03 19:54:32 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**alloc_res(int **arr, int col, int row)
{
	int **res;
	int	i;

	res = (int**)malloc(sizeof(int*) * row);
	i = 0;
	while (i < row)
	{
		res[i] = (int*)malloc(sizeof(int) * col);
		i++;
	}
	i = 0;
	while (i < row)
	{
		res[i][0] = arr[i][0];
		i++;
	}
	i = 0;
	while (i < col)
	{
		res[0][i] = arr[0][i];
		i++;
	}
	return (res);
}

void	oneline(int **arr, int **res, int col, int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (arr[i][j] == 1)
				res[i][j] = 1;
			else
				res[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	maxarr(int **arr, int **res, int col, int row)
{
	int	i;
	int	j;
	int	t;

	if (row == 1)
		oneline(arr, res, col, row);
	i = 1;
	while (i < row)
	{
		j = 1;
		while (j < col)
		{
			if (arr[i][j] == 1)
			{
				t = f_min(res[i - 1][j], res[i - 1][j - 1], res[i][j - 1]);
				res[i][j] = t + 1;
			}
			else
				res[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	getmax(int **map, int **res, t_legend *legend)
{
	int i;
	int j;

	i = 0;
	while (i < legend->lines)
	{
		j = 0;
		while (j < legend->width)
		{
			if (res[i][j] > legend->max)
			{
				legend->max = res[i][j];
				legend->x = i;
				legend->y = j;
			}
			j++;
		}
		i++;
	}
	print_result(map, legend);
	freearr(res, legend->lines);
}

void	findmax(t_legend *legend, char *grid)
{
	int **map;
	int **res;

	map = makemap(grid, legend);
	res = alloc_res(map, legend->width, legend->lines);
	maxarr(map, res, legend->width, legend->lines);
	getmax(map, res, legend);
}
