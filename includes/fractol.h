/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:54:51 by timatias          #+#    #+#             */
/*   Updated: 2024/07/31 13:26:59 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define NUM_COR 5

typedef struct s_dados
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		pixel;
	int		tam;
	int		endian;
	double	zoom;
	double	desliza_x;
	double	desliza_y;
	double	x;
	double	y;
	int		cor_fracts;
}	t_dados;

typedef struct s_coordenar
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		cor;
}	t_coordenar;

void	draw_mandelbrot(t_dados *dados);
void	draw_julia(t_dados *dados);
int		cor_map(int i, int limite_inteiro, int cor_fractais);
int		fechar_janela(t_dados *dd);
int		ft_strcmp(char *s1, char *s2);
double	ft_atodbl(char *s);

#endif
