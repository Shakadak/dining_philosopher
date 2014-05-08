/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 14:44:21 by npineau           #+#    #+#             */
/*   Updated: 2014/05/08 13:03:54 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	main(void)
{
	long		i;
	pthread_t	philos[MAX_PHILO];
	t_philo		*list;

	i = 0;
	list = (t_philo *)philosopher((void *)-1);
	while (i < MAX_PHILO)
	{
		pthread_create(&philos[i], NULL, philosopher, (void *)i);
		i++;
	}
	while (i-- > 0)
		pthread_join(philos[i], NULL);
	return (0);
}
