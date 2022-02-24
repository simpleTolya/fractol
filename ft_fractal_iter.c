/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_iter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:37:42 by marmand           #+#    #+#             */
/*   Updated: 2022/01/04 15:22:49 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_iter_mandelbrot(t_complex num, void *fractal_params)
{
	t_complex	z;
	t_complex	tmp;
	int			iter;

	(void) fractal_params;
	z.re = 0;
	z.im = 0;
	iter = 0;
	while (iter < MAX_ITER_COUNT && (z.re * z.re + z.im * z.im) < 4)
	{
		tmp.re = z.re * z.re - z.im * z.im;
		tmp.im = 2 * z.im * z.re;
		tmp.re += num.re;
		tmp.im += num.im;
		z = tmp;
		iter++;
	}
	return (iter);
}

int	ft_iter_julia(t_complex num, void *fractal_params)
{
	t_complex	z;
	t_complex	tmp;
	int			iter;

	z = num;
	iter = 0;
	while (iter < MAX_ITER_COUNT && (z.re * z.re + z.im * z.im) < 4)
	{
		tmp.re = z.re * z.re - z.im * z.im;
		tmp.im = 2 * z.im * z.re;
		tmp.re += ((t_complex *)fractal_params)->re;
		tmp.im += ((t_complex *)fractal_params)->im;
		z = tmp;
		iter++;
	}
	return (iter);
}

int	ft_iter_my_fractal(t_complex num, void *fractal_params)
{
	t_complex	z;
	t_complex	tmp;
	int			iter;

	(void) fractal_params;
	z.re = 0;
	z.im = 0;
	iter = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && iter < MAX_ITER_COUNT)
	{
		tmp.im = 2 * fabs(z.re * z.im);
		tmp.re = z.re * z.re - z.im * z.im;
		tmp.re += num.re;
		tmp.im += num.im;
		z = tmp;
		iter++;
	}
	return (iter);
}
