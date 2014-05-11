/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 14:54:39 by npineau           #+#    #+#             */
/*   Updated: 2014/05/11 19:40:08 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void	rest(int id, t_philo *list)
{
	list[id].eating = 0;
	usleep(SECOND * REST_T);
	list[id].eating = 2;
}
