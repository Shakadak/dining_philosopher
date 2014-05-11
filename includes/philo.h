/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 18:29:45 by npineau           #+#    #+#             */
/*   Updated: 2014/05/11 17:07:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <mlx.h>
# include <fcntl.h>

# define X_WIN 1000
# define Y_WIN 1000

# define EAT 0x00FF00
# define THINK 0xFFFFFF
# define REST 0x0000FF
# define REST_IN_PEACE 0x9932CD
# define WOOD 0x663300

# define W_TABLE 800
# define H_TABLE 420

# define MAX_PHILO 7
# define MAX_LIFE 15
# define EAT_T 5
# define REST_T 3
# define THINK_T 1
# define TIMEOUT 60
# define SECOND 500000

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_philo
{
	int				health;
	int				id;
	pthread_mutex_t	chopstick;
	int				sat;
	int				eating;
}					t_philo;

void				*master(void *arg);
void				*philosopher(void *arg);
void				eat(int id, t_philo *list, int reserved);
void				rest(int id, t_philo *list);
void				think(int id, t_philo *list, int stick_id);
t_philo				*init_table(void);
void				stop_philo(pthread_t *threads);

void				draw(t_env *env);

#endif
