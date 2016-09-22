/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 19:21:01 by vtenigin          #+#    #+#             */
/*   Updated: 2016/08/03 19:55:34 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_legend
{
	char		full;
	char		obst;
	char		empty;
	int			size;
	int			isize;
	int			lines;
	int			width;
	int			max;
	int			x;
	int			y;
}				t_legend;

int				ft_atoi(char *str);
int				linecheck(int pos, int len, char *str);
char			*makegrid(char *str, int ilen, int len);
char			*makeinfo(char *str, int len);
int				linelen(char *str);
int				find_height(char *str);
void			makestr(char *str, char *file);
int				file_size(char *file);
void			interpret(char *info, t_legend *legend);
int				**makemap(char *grid, t_legend *legend);
int				ft_getint(char c, t_legend *legend);
int				f_min(int a, int b, int c);
int				**alloc_res(int **arr, int col, int row);
void			maxarr(int **arr, int **res, int col, int row);
void			print_result(int **arr, t_legend *legend);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				**alloc_res(int **arr, int col, int row);
void			findmax(t_legend *legend, char *grid);
int				bsq(char *name);
void			ft_stdin_grid(void);
int				ft_valid(t_legend *l, char *str);
void			oneline(int **arr, int **res, int col, int row);
void			freearr(int **arr, int size);
void			getmax(int **map, int **res, t_legend *legend);

#endif
