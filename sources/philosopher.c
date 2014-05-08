/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 15:01:23 by npineau           #+#    #+#             */
/*   Updated: 2014/05/08 13:33:58 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "philo.h"

void	*philosopher(void *arg)
{
	int				id;
	static t_philo	*philo;

	id = (int)arg;
	if (id == -1)
	{
		philo = init_table();
		return ((void *)philo);
	}
	philo[id].sat = 1;
	usleep(id * 100);
	ft_putstr("\nPhilosopher #");
	ft_putnbr(id);
	ft_putendl(" successfully sat down.\n");
	eat(id, philo);
	return (NULL);
}
