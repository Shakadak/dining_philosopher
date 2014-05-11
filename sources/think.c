/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 15:18:07 by npineau           #+#    #+#             */
/*   Updated: 2014/05/11 16:23:12 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "philo.h"

void	think(int id, t_philo *list, int stick_id)
{
	list[id].eating = -1;
	usleep(SECOND * THINK_T);
	list[id].eating = 2;
	pthread_mutex_unlock(&list[stick_id].chopstick);
}
