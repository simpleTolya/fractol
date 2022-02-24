/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:49:41 by marmand           #+#    #+#             */
/*   Updated: 2022/01/04 17:47:23 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WINDOW_SIZE 1000
# define MAX_ITER_COUNT 150
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# define ARROW_LEFT		123
# define ARROW_RIGHT	124
# define ARROW_UP		126
# define ARROW_DOWN		125

# define MOUSE_UP		4
# define MOUSE_DOWN		5

# define MAINP_ESC		53
# define MAINP_SPACE	49

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 17
};

typedef struct s_mlximg
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlximg;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_mlximg	img;
}	t_mlx;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef int	(*t_fractal_iter)(t_complex, void *);

typedef struct s_map
{
	t_mlx			mlx;
	t_fractal_iter	func;
	void			*fractal_params;
	double			_x;
	double			_y;
	double			scale;
	int				_color_shift;
}	t_map;

void	ft_mlx_pixel_put(t_mlximg *data, int x, int y, int color);
int		ft_iter_mandelbrot(t_complex num, void *fractal_params);
int		ft_iter_julia(t_complex num, void *fractal_params);
int		ft_iter_my_fractal(t_complex num, void *fractal_params);
int		ft_get_color_from_iter(int iter_count, int _color_shift);
void	ft_change_color(t_map *mlx);
void	ft_move_y(t_map *map, int step);
void	ft_move_x(t_map *map, int step);
void	ft_render_map(t_map *map);

void	*ft_calloc(size_t count, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str, int *_res);
int		ft_julia_params(t_map *map, char *argv[],
			int numerator, int denumerator);
int		ft_init_fractol(t_map *map, int argc, char *argv[]);
t_map	*ft_init_map(int argc, char *argv[]);
int		*ft_clear_map(t_map *map);

int		ft_exit(t_map *map);
int		ft_zoom(int button, int x, int y, t_map *map);
int		key_actions(int key, t_map *map);
void	ft_move(int key, t_map *map);

#endif