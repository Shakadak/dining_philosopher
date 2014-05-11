/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 14:18:58 by npineau           #+#    #+#             */
/*   Updated: 2014/05/11 19:38:39 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy(t_philo *list)
{
	int	i;

	i = 0;
	while (i < 7)
		pthread_mutex_destroy(&list[i++].chopstick);
}

void		stop_philo(pthread_t *threads)
{
	t_philo	*list;
	int		i;

	list = (t_philo *)philosopher((void *)-1);
	i = 0;
	while (i < 7)
		pthread_join(threads[i++], NULL);
	destroy(list);
}
