/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:56:38 by marmand           #+#    #+#             */
/*   Updated: 2022/01/04 17:01:58 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit(t_map *map)
{
	ft_clear_map(map);
	exit(0);
	return (0);
}

int	ft_zoom(int button, int x, int y, t_map *map)
{
	if (button == MOUSE_UP || button == MOUSE_DOWN)
	{
		if (button == MOUSE_UP)
		{
			map->_x += ((-(WINDOW_SIZE / 2) + x)) / 2 / map->scale;
			map->_y += ((WINDOW_SIZE / 2) - y) / 2 / map->scale;
			map->scale *= 1.1;
		}
		else
		{
			map->_x -= (-(WINDOW_SIZE / 2) + x) / 2 / map->scale;
			map->_y -= ((WINDOW_SIZE / 2) - y) / 2 / map->scale;
			map->scale *= 0.9;
		}
		ft_render_map(map);
	}
	return (0);
}

void	ft_move(int key, t_map *map)
{
	if (key == ARROW_UP)
		map->_y += 50 / map->scale;
	else if (key == ARROW_DOWN)
		map->_y -= 50 / map->scale;
	else if (key == ARROW_LEFT)
		map->_x -= 50 / map->scale;
	else if (key == ARROW_RIGHT)
		map->_x += 50 / map->scale;
}

int	key_actions(int key, t_map *map)
{
	if (key == MAINP_ESC)
		ft_exit(map);
	else if (key == ARROW_UP || key == ARROW_DOWN)
		ft_move(key, map);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT)
		ft_move(key, map);
	else if (key == MAINP_SPACE)
		ft_change_color(map);
	ft_render_map(map);
	return (0);
}
