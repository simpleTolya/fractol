/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:28:36 by marmand           #+#    #+#             */
/*   Updated: 2022/01/04 17:45:28 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_pixel_put(t_mlximg *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_get_color_from_iter(int iter_count, int _color_shift)
{
	if (iter_count == MAX_ITER_COUNT)
		return (0);
	return (_color_shift * ((iter_count + 10) * iter_count * 2 + 100));
}

void	ft_render_map(t_map *map)
{
	int			i;
	int			j;
	t_complex	tmp;

	i = 0;
	while (i < WINDOW_SIZE)
	{
		j = 0;
		while (j < WINDOW_SIZE)
		{
			tmp.re = ((double)(-(WINDOW_SIZE / 2) + i)) / map->scale + map->_x;
			tmp.im = ((double)((WINDOW_SIZE / 2) - j)) / map->scale + map->_y;
			ft_mlx_pixel_put(&(map->mlx.img), i, j,
				ft_get_color_from_iter(map->func(tmp,
						map->fractal_params),
					map->_color_shift));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win,
		map->mlx.img.img, 0, 0);
}

void	ft_init_actions(t_map *map)
{
	mlx_hook(map->mlx.mlx_win, ON_DESTROY, 0, ft_exit, map);
	mlx_hook(map->mlx.mlx_win, ON_KEYDOWN, 0, key_actions, map);
	mlx_hook(map->mlx.mlx_win, ON_MOUSEDOWN, 0, ft_zoom, map);
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	map = ft_init_map(argc, argv);
	if (map == NULL)
		return (1);
	ft_init_actions(map);
	ft_render_map(map);
	mlx_loop(map->mlx.mlx);
	return (0);
}
