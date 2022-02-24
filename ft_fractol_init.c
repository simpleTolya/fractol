/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:23:59 by marmand           #+#    #+#             */
/*   Updated: 2022/01/04 18:15:49 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_map	*ft_init_map(int argc, char *argv[])
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (map == 0)
		return ((void *)ft_clear_map(map));
	if (ft_init_fractol(map, argc, argv))
		return ((void *)ft_clear_map(map));
	map->mlx.mlx = mlx_init();
	if (map->mlx.mlx == 0)
		return ((void *)ft_clear_map(map));
	map->mlx.mlx_win = mlx_new_window(map->mlx.mlx, WINDOW_SIZE,
			WINDOW_SIZE, "fractol");
	if (map->mlx.mlx_win == 0)
		return ((void *)ft_clear_map(map));
	map->mlx.img.img = mlx_new_image(map->mlx.mlx, WINDOW_SIZE, WINDOW_SIZE);
	if (map->mlx.img.img == 0)
		return ((void *)ft_clear_map(map));
	map->mlx.img.addr = mlx_get_data_addr(map->mlx.img.img,
			&map->mlx.img.bits_per_pixel, &map->mlx.img.line_length,
			&map->mlx.img.endian);
	map->scale = 200;
	map->_color_shift = 1;
	return (map);
}

int	ft_julia_params(t_map *map, char *argv[], int numerator, int denumerator)
{
	map->fractal_params = malloc(sizeof(t_complex));
	if (map->fractal_params == 0)
		return (-1);
	if (argv == 0)
	{
		((t_complex *)map->fractal_params)->re = -0.2;
		((t_complex *)map->fractal_params)->im = 0.75;
		return (0);
	}
	if (ft_atoi(argv[2], &numerator))
		return (-1);
	if (ft_atoi(argv[3], &denumerator))
		return (-1);
	if (denumerator == 0)
		return (-1);
	((t_complex *)map->fractal_params)->re = (double) numerator / denumerator;
	if (ft_atoi(argv[4], &numerator))
		return (-1);
	if (ft_atoi(argv[5], &denumerator))
		return (-1);
	if (denumerator == 0)
		return (-1);
	((t_complex *)map->fractal_params)->im = (double) numerator / denumerator;
	return (0);
}

int	ft_init_fractol(t_map *map, int argc, char *argv[])
{
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		map->func = ft_iter_mandelbrot;
	else if (argc >= 2 && ft_strcmp(argv[1], "julia") == 0)
	{
		map->func = ft_iter_julia;
		if (argc == 6)
			return (ft_julia_params(map, argv, 0, 0));
		else
			return (ft_julia_params(map, 0, 0, 0));
	}
	else if (argc == 2 && ft_strcmp(argv[1], "burning ship") == 0)
		map->func = ft_iter_my_fractal;
	else
	{
		write(1, "Run programm with argument: mandelbrot,", 39);
		return (write(1, " julia, burning ship\n", 21));
	}
	return (0);
}

int	*ft_clear_map(t_map *map)
{
	if (!map)
		return (0);
	if (map->mlx.mlx != NULL)
	{
		if (map->mlx.mlx_win)
			mlx_destroy_window(map->mlx.mlx, map->mlx.mlx_win);
		if (map->mlx.img.img)
			mlx_destroy_image(map->mlx.mlx, map->mlx.img.img);
	}
	if (map->func == ft_iter_julia)
		free(map->fractal_params);
	free(map);
	return (0);
}
