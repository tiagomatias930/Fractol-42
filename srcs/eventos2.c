/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventos2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:06:25 by timatias          #+#    #+#             */
/*   Updated: 2024/07/31 16:46:15 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../minilibx-linux/mlx.h"

#define MOVER 50

int	eventos2(int keyCodigo2, t_dados *dds2)
{
	if (keyCodigo2 == 65307)
		exit(0);
	if (keyCodigo2 == 65364)
		dds2->desliza_y -= MOVER / dds2->zoom;
	if (keyCodigo2 == 65362)
		dds2->desliza_y += MOVER / dds2->zoom;
	if (keyCodigo2 == 65363)
		dds2->desliza_x -= MOVER / dds2->zoom;
	if (keyCodigo2 == 65361)
		dds2->desliza_x += MOVER / dds2->zoom;
	if (keyCodigo2 == 99)
		dds2->cor_fracts = (dds2->cor_fracts + 1) % NUM_COR;
	draw_julia(dds2);
	mlx_put_image_to_window(dds2->mlx_ptr, dds2->win_ptr, dds2->img_ptr, 1, 1);
	return (0);
}

int	mouse_eventos2(int botao2, int x2, int y2, t_dados *dds)
{
	(void)x2;
	(void)y2;
	if (botao2 == 4)
	{
		dds->zoom *= 1.2;
		draw_julia(dds);
		mlx_put_image_to_window(dds->mlx_ptr, dds->win_ptr, dds->img_ptr, 1, 1);
	}
	if (botao2 == 5)
	{
		dds->zoom /= 1.2;
		draw_julia(dds);
		mlx_put_image_to_window(dds->mlx_ptr, dds->win_ptr, dds->img_ptr, 2, 2);
	}
	return (0);
}
