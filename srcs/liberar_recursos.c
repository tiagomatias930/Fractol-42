/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberar_recursos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:00:00 by timatias          #+#    #+#             */
/*   Updated: 2024/07/28 08:58:49 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

void	liberar_recursos(t_dados *dados)
{
	if (dados->img_ptr != NULL)
		mlx_destroy_image(dados->mlx_ptr, dados->img_ptr);
	if (dados->win_ptr != NULL)
		mlx_destroy_window(dados->mlx_ptr, dados->win_ptr);
	if (dados->mlx_ptr != NULL)
		free(dados->mlx_ptr);
}
