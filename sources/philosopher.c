/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 15:01:23 by npineau           #+#    #+#             */
/*   Updated: 2014/05/08 17:15:42 by npineau          ###   ########.fr       */
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
	while (philo[id].health > 0)
	{
		eat(id, philo, 0);
		rest(id, philo);
		if (pthread_mutex_trylock(&philo[id].chopstick))
		{
			if (pthread_mutex_trylock(&philo[id + 1].chopstick))
				rest(id, philo);
			else
				think(id, philo, id + 1);
		}
		else
		{
			if (pthread_mutex_trylock(&philo[id + 1].chopstick))
				eat(id, philo, 1);
			else
				think(id, philo, id);
		}
	}
	return (NULL);
}
