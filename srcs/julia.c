/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:55:06 by timatias          #+#    #+#             */
/*   Updated: 2024/07/30 17:42:45 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

#define LARGURA 950
#define ALTURA 800

double	valor_x(int x, double d_x, double zoom);
double	valor_y(int y, double d_y, double zoom);
int		matjulia(double x, double y, double c_re, double c_im);

void	draw_julia(t_dados *dds)
{
	t_coordenar	c;
	int			x;
	int			y;
	int			i;
	int			limite_inteiro;

	c.c_re = dds->x;
	c.c_im = dds->y;
	limite_inteiro = 100;
	y = 0;
	while (y < ALTURA)
	{
		x = 0;
		while (x < LARGURA)
		{
			c.z_re = valor_x(x, dds->desliza_x, dds->zoom);
			c.z_im = valor_y(y, dds->desliza_y, dds->zoom);
			i = matjulia(c.z_re, c.z_im, c.c_re, c.c_im);
			c.cor = cor_map(i, limite_inteiro, dds->cor_fracts);
			*(int *)(dds->addr + (y * dds->tam + x * (dds->pixel / 8))) = c.cor;
			x++;
		}
		y++;
	}
}

double	valor_x(int x, double d_x, double zoom)
{
	return ((x - LARGURA / 2.0 + d_x) * 4.0 / (LARGURA * zoom));
}

double	valor_y(int y, double d_y, double zoom)
{
	return ((y - ALTURA / 2.0 + d_y) * 4.0 / (ALTURA * zoom));
}

int	matjulia(double x, double y, double c_re, double c_im)
{
	int		i;
	int		limite;
	double	res_x;
	double	res_y;

	i = 0;
	limite = 100;
	while (i < limite)
	{
		res_x = x * x;
		res_y = y * y;
		if (res_x + res_y > 4.0)
			break ;
		y = 2.0 * x * y + c_im;
		x = res_x - res_y + c_re;
		i++;
	}
	return (i);
}
