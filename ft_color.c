/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:47:53 by marmand           #+#    #+#             */
/*   Updated: 2022/01/04 16:19:10 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_change_color(t_map *map)
{
	if (map->_color_shift >= 100000)
		map->_color_shift = 1;
	if (map->_color_shift <= 0)
		map->_color_shift = 1;
	map->_color_shift *= 2;
	return ;
}
