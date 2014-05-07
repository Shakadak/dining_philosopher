/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 14:44:21 by npineau           #+#    #+#             */
/*   Updated: 2014/05/07 18:45:34 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	main(void)
{
	long		i;
	pthread_t	philos[MAX_PHILO];

	i = 0;
	philosopher((void *)-1);
	while (i < MAX_PHILO)
	{
		pthread_create(&philos[i], NULL, philosopher, (void *)i);
		i++;
	}
	while (i-- > 0)
		pthread_join(philos[i], NULL);
	eat(-1);
	return (0);
}
