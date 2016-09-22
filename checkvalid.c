/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 09:13:42 by vtenigin          #+#    #+#             */
/*   Updated: 2016/08/03 21:16:24 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			f_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

int			ft_atoi(char *str)
{
	int i;
	int num;
	int sign;

	i = 0;
	num = 0;
	sign = 1;
	while (!(str[i] > 48 && str[i] < 58) && str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int			ft_valid(t_legend *l, char *str)
{
	int i;
	int n;
	int e;

	i = 0;
	n = 0;
	e = 0;
	if (l->obst == l->empty)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		if (str[i] != l->obst && str[i] != l->empty && str[i] != '\n')
			return (-1);
		if (str[i] == l->empty)
			e++;
		i++;
	}
	if (n == l->lines && e > 0)
		return (0);
	return (-1);
}

int			linecheck(int pos, int len, char *str)
{
	if (str[pos + len + 1] != '\0')
	{
		if (str[pos + len] == '\n')
			linecheck(pos + len, len, str);
		else
			return (-1);
	}
	return (0);
}

void		interpret(char *info, t_legend *legend)
{
	int			k;
	char		*lines;
	int			l;

	k = 0;
	legend->full = info[legend->isize - 1];
	legend->obst = info[legend->isize - 2];
	legend->empty = info[legend->isize - 3];
	lines = (char*)malloc(sizeof(char) * 11);
	while (k < (legend->isize - 3))
	{
		lines[k] = info[k];
		k++;
	}
	lines[k] = '\0';
	l = ft_atoi(lines);
	free(lines);
	legend->lines = l;
}
