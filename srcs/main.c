/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:54:15 by timatias          #+#    #+#             */
/*   Updated: 2024/08/08 04:08:39 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>

#define LARGURA 960
#define ALTURA 580

void	frases(void);
int		eventos(int keyCodigo, t_dados *dados);
int		mouse_eventos(int botao, int x, int y, t_dados *dados);
int		eventos2(int keyCodigo2, t_dados *dados2);
int		mouse_eventos2(int botao2, int x2, int y2, t_dados *dados2);

static int	initialize_data(t_dados *d)
{
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
		return (1);
	d->win_ptr = mlx_new_window(d->mlx_ptr, 960, 800, "Fractol 42_Luanda");
	if (d->win_ptr == NULL)
	{
		free(d->win_ptr);
		return (1);
	}
	d->img_ptr = mlx_new_image(d->mlx_ptr, LARGURA * 2, ALTURA * 2);
	if (d->img_ptr == NULL)
	{
		free(d->img_ptr);
		return (1);
	}
	d->addr = mlx_get_data_addr(d->img_ptr, &d->pixel, &d->tam, &d->endian);
	d->zoom = 1.1;
	d->desliza_x = 1.0;
	d->desliza_y = 1.0;
	d->cor_fracts = 2;
	return (0);
}

static int	handle_args(int ac, char *av[], t_dados *dados)
{
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
	{
		draw_mandelbrot(dados);
		mlx_hook(dados->win_ptr, 2, 1L, eventos, dados);
		mlx_mouse_hook(dados->win_ptr, mouse_eventos, dados);
	}
	else if (!(ft_atodbl(av[2]) || ft_atodbl(av[3])))
			frases();
	else if (ac == 4 && (ft_strcmp(av[1], "julia") == 0))
	{
		dados->x = ft_atodbl(av[2]);
		dados->y = ft_atodbl(av[3]);
		draw_julia(dados);
		mlx_hook(dados->win_ptr, 2, 1L, eventos2, dados);
		mlx_mouse_hook(dados->win_ptr, mouse_eventos2, dados);
	}
	else
	{
		frases();
		return (1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_dados	dds;

	if (initialize_data(&dds) != 0)
		return (1);
	if (handle_args(ac, av, &dds) != 0)
		return (1);
	mlx_hook(dds.win_ptr, 17, 0, fechar_janela, &dds);
	mlx_put_image_to_window(dds.mlx_ptr, dds.win_ptr, dds.img_ptr, 1, 1);
	mlx_loop(dds.mlx_ptr);
	return (0);
}

void	frases(void)
{
	write(1, "\n\nTipo de Fractol Invalido\n", 26);
	write(1, "\nEscolha um dos fractais validos", 33);
	write(1, "\nConjunto Julia :\t./fractol julia ", 35);
	write(1, "<\"Suas cordenadas x-real y-imaginario\"", 39);
	write(1, ">\nConjunto Mandelbrot :\t./fractol mandelbrot\0", 46);
}
