/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 13:38:18 by npineau           #+#    #+#             */
/*   Updated: 2014/05/08 13:37:36 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //////////////////
#include <unistd.h>
#include "libft.h"
#include "philo.h"

void	eat(int	id, t_philo *list)
{
	pthread_mutex_lock(&list[(id + id % 2) % MAX_PHILO].chopstick);
	printf("Philosopher %d took chopstick #%d\n", id, (id + id % 2) % MAX_PHILO);
	pthread_mutex_lock(&list[(id + (id + 1) % 2) % MAX_PHILO].chopstick);
	printf("Philosopher %d took chopstick #%d\n", id, (id + (id + 1) % 2) % MAX_PHILO);
	usleep(EAT_T * 1000000);
	pthread_mutex_unlock(&list[(id + id % 2) % MAX_PHILO].chopstick);
	pthread_mutex_unlock(&list[(id + (id + 1) % 2) % MAX_PHILO].chopstick);
}
