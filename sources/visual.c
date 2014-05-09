/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 15:33:30 by npineau           #+#    #+#             */
/*   Updated: 2014/05/09 16:22:03 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "philo.h"

static void	*init_mlx(void)
{
	void	*mlx;

	mlx = malloc(3 * sizeof(void *));
	mlx[0] = mlx_init();
	mlx[1] = mlx_new_window(mlx[0], 1200, 1200, "Dining Philosophers");
	mlx[2] = mlx_new_image(mlx[0], 1200, 1200);
	return (mlx);
}

void		*visual(void *)
{
	void	*mlx;

	mlx
	return (NULL);
}
