/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:38:25 by pducloux          #+#    #+#             */
/*   Updated: 2023/09/07 19:38:26 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <sys/types.h>
# include <pthread.h>
# include "libft.h"

# ifndef TRUE
#  define TRUE	1
# endif
# ifndef FALSE
#  define FALSE	0
# endif

typedef u_int8_t	t_bool;

/**
 *	Represent a mutex
 *
 *	@var t_mutex::m	the mutex
 *	@var t_mutex::i	is the mutex initialized
 */
typedef struct s_mutex {
	pthread_mutex_t	m;
	t_bool			i;
}	t_mutex;

/**
 * @var	t_philosopher::id				the philosopher's id (> 0)
 * @var t_philosopher::last_eat_mutex	mutex for last philosopher_eat
 * @var t_philosopher::last_eat			last time the philosopher did philosopher_eat
 * @var	t_philosopher::first			pointer to first fork
 * @var t_philosopher::second			pointer to second fork
 */
typedef struct s_philosopher {
	unsigned int		id;
	t_mutex				last_eat_mutex;
	u_int64_t			last_eat;
	t_mutex				remaining_eat_mutex;
	int64_t				remaining_eat;
	t_mutex				*first;
	t_mutex				*second;
	struct s_philo_data	*datas;
}	t_philosopher;

/**
 * @var t_philo_data::nphilos			the number of philosophers
 * @var t_philo_data::ttd				time to die
 * @var t_philo_data::tte				time to philosopher_eat
 * @var t_philo_data::tts				time to sleep
 * @var t_philo_data::max_eat			max time to philosopher_eat (-1 == INF)
 * @var t_philo_data::philosophers		philosophers buffer
 * @var t_philo_data::forks				forks buffer
 * @var	t_philo_data::is_finished_mutex is_finished's mutex
 * @var t_philo_data::is_finished		is the program finished ?
 */
typedef struct s_philo_data {
	int				nphilos;
	int				ttd;
	int				tte;
	int				tts;
	int				max_eat;
	t_mutex			still_eating_mutex;
	int				still_eating;
	u_int64_t		start_time;
	t_philosopher	*philosophers;
	t_mutex			*forks;
	t_mutex			is_finished_mutex;
	t_bool			is_finished;
	pthread_t		*threads;
}	t_philo_data;

#endif
