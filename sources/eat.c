/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 13:38:18 by npineau           #+#    #+#             */
/*   Updated: 2014/05/07 13:50:50 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philo.h"

void	eat(int	id)
{
	static int	nb[MAX_PHILO];
	int			i;

	if (id == -1)
	{
		i = 0;
		while (i < MAX_PHILO)
			ft_putnbr(nb[i++]);
	}
	else
		nb[id] = id;
}
