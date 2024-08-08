/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:32:04 by timatias          #+#    #+#             */
/*   Updated: 2024/07/31 11:26:20 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	cor1(int cor, double timatias)
{
	cor = (int)(9 * (1 - timatias) * timatias * timatias * timatias * 255);
	cor = (cor << 16) + (cor << 6) * cor;
	return (cor);
}

int	cor2(int cor, double ti)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - ti) * ti * ti * ti * 255);
	g = (int)(12 * (1 - ti) * (1 - ti) * ti * ti * 255);
	b = (int)(6.5 * (1 - ti) * (1 - ti) * (1 - ti) * ti * 255);
	cor = (r << 16) + (g << 2) + b;
	return (cor);
}

int	cor3(int cor, double ti)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - ti) * ti * ti * ti * 255);
	g = (int)(15 * (1 - ti) * (1 - ti) * ti * ti * 255);
	b = (int)(8.5 * (1 - ti) * (1 - ti) * (1 - ti) * ti * 255);
	cor = (r << 16) + (g << 8) + b;
	return (cor);
}

/*int	cor4(int cor, double ti)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - ti) * ti * ti * ti * 255);
	g = (int)(11 * (1 - ti) * (1 - ti) * ti * ti * 255);
	b = (int)(9.5 * (1 - ti) * (1 - ti) * (1 - ti) * ti * 255);
	cor = (r << 16) + (g << 2) + b;
	return (cor);
}*/

int	cor5(int cor, double ti)
{
	int	r;
	int	g;
	int	b;

	r = (int)(16 * (1 - ti) * ti * ti * ti * 255);
	g = (int)(10 * (1 - ti) * (1 - ti) * ti * ti * 255);
	b = (int)(9.5 * (1 - ti) * (1 - ti) * (1 - ti) * ti * 255);
	cor = (r << 16) + (g << 4) + b;
	return (cor);
}

int	cor_map(int i, int limite_interacao, int cor_fractais)
{
	double	t;
	int		cor;

	cor = 0;
	t = (double)i / (double)limite_interacao;
	if (cor_fractais == 1)
		cor = cor1(cor * 4, t);
	else if (cor_fractais == 2)
		cor = cor2(cor, t);
	else if (cor_fractais == 3)
		cor = cor3(cor, t);
	else if (cor_fractais == 4)
		cor = cor5(cor * 4, t);
	else
		cor = cor2(cor * 2, t);
	return (cor);
}
