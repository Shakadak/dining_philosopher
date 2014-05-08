/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 15:18:07 by npineau           #+#    #+#             */
/*   Updated: 2014/05/08 17:00:43 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void	think(int id, t_philo *list, int stick_id)
{
	pthread_mutex_unlock(&list[stick_id].chopstick);
	list[id].eating = 0;
	usleep(1000000 * THINK_T);
}
