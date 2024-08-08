/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:55:28 by timatias          #+#    #+#             */
/*   Updated: 2024/07/31 16:40:56 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../minilibx-linux/mlx.h"

#define MOVER 50

int	eventos(int keyCodigo, t_dados *dds)
{
	if (keyCodigo == 65307)
		exit(0);
	if (keyCodigo == 65364)
		dds->desliza_y -= MOVER / dds->zoom;
	if (keyCodigo == 65362)
		dds->desliza_y += MOVER / dds->zoom;
	if (keyCodigo == 65363)
		dds->desliza_x -= MOVER / dds->zoom;
	if (keyCodigo == 65361)
		dds->desliza_x += MOVER / dds->zoom;
	if (keyCodigo == 61)
		dds->zoom *= 1.2;
	if (keyCodigo == 45)
		dds->zoom /= 1.2;
	if (keyCodigo == 99)
		dds->cor_fracts = (dds->cor_fracts + 1) % NUM_COR;
	draw_mandelbrot(dds);
	mlx_put_image_to_window(dds->mlx_ptr, dds->win_ptr, dds->img_ptr, 1, 1);
	return (0);
}

int	mouse_eventos(int botao, int x, int y, t_dados *dds)
{
	(void)x;
	(void)y;
	if (botao == 4)
	{
		dds->zoom *= 1.1;
		draw_mandelbrot(dds);
		mlx_put_image_to_window(dds->mlx_ptr, dds->win_ptr, dds->img_ptr, 1, 1);
	}
	if (botao == 5)
	{
		dds->zoom /= 1.1;
		draw_mandelbrot(dds);
		mlx_put_image_to_window(dds->mlx_ptr, dds->win_ptr, dds->img_ptr, 2, 2);
	}
	return (0);
}
