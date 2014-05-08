/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 18:29:45 by npineau           #+#    #+#             */
/*   Updated: 2014/05/08 13:24:57 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define MAX_PHILO 7
# define MAX_LIFE 7
# define EAT_T 6
# define REST_T 3
# define THINK_T 4
# define TIMEOUT 60

typedef struct		s_philo
{
	int				health;
	int				id;
	pthread_mutex_t	chopstick;
	int				sat;
}					t_philo;

void				*philosopher(void *arg);
void				eat(int id, t_philo *list);
t_philo				*init_table(void);

#endif
