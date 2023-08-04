/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:34:06 by pducloux          #+#    #+#             */
/*   Updated: 2023/08/02 15:32:18 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define true	1
# define false	0

# include <sys/types.h>
# include <pthread.h>

typedef int8_t	bool;

typedef struct s_mutex {
	pthread_mutex_t	mutex;
	bool			is_initialized;
}	t_mutex;

/**
 * @struct s_thread
 * @brief contain each thread data
 *
 * @var t_philosopher::tid				the thread id
 * @var t_philosopher::last_eat			last eat time in microseconds
 * @var t_philosopher::near				number of time the thread should eat (-1 = infinite)
 * @var t_philosopher::philo_data		pointer to global datas
 * @var t_philosopher::mutex_is_dead	mutex for is_dead
 * @var t_philosopher::fork_r			right fork
 * @var t_philosopher::fork_l			left fork
 */
typedef struct s_philosopher {
	u_int64_t				tid;
	u_int64_t				last_eat;
	t_mutex					neat_mutex;
	int64_t					neat;
	struct s_philo_data		*philo_data;
	t_mutex					mutex_is_dead;
	u_int8_t				is_dead;
	pthread_mutex_t			*fork_r;
	pthread_mutex_t			*fork_l;
}	t_philosopher;

/**
 * @struct s_philo_data
 * @brief	contain philo datas
 * 
 * @var t_philo_data::ttd		time to die
 * @var t_philo_data::tte		time to eat
 * @var t_philo_data::tts		time to sleep
 * @var t_philo_data::neat		number of time to eat
 * @var t_philo_data::start		start of the program
 * @var t_philo_data::forks		the forks
 * @var t_philo_data::iforks	number of forks initialized
 * @var t_philo_data::philos	philosophers storage buffer
 * @var t_philo_data::nphilo	number of philosophers
 * @var t_philo_data::threads	thread storage buffer
 * @var t_philo_data::nthreads	number of threads
*/
typedef struct s_philo_data {
	u_int64_t		ttd;
	u_int64_t		tte;
	u_int64_t		tts;
	int64_t			neat;
	u_int64_t		start;
	pthread_mutex_t	*forks;
	u_int64_t		iforks;
	t_philosopher	*philos;
	u_int64_t		nphilo;
	pthread_t		*threads;
	u_int64_t		nthreads;
	pthread_mutex_t mutex_is_finished;
	bool			is_finished_initialized;
	bool			is_finished;
}	t_philo_data;

#endif