/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 14:44:21 by npineau           #+#    #+#             */
/*   Updated: 2014/05/06 15:12:37 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	main(void)
{
	long		i;
	pthread_t	philos[MAX_PHILO];

	i = 0;
	while (i < MAX_PHILO)
	{
		pthread_create(&philos[i], NULL, philosopher, (void *)i);
		i++;
	}
	while (i-- > 0)
		pthread_join(philos[i], NULL);
	return (0);
}
