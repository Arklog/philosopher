/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:34:06 by pducloux          #+#    #+#             */
/*   Updated: 2023/08/02 10:57:13 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <sys/types.h>
# include <pthread.h>

/**
 * @struct s_thread
 * @brief contain each thread data
 *
 * @var t_thread_data::tid				the thread id
 * @var t_thread_data::last_eat			last eat time in microseconds
 * @var t_thread_data::near				number of time the thread have eat
 * @var t_thread_data::philo_data		pointer to global datas
 * @var t_thread_data::mutex_is_dead	mutex for is_dead
 * @var t_thread_data::fork_r			right fork
 * @var t_thread_data::fork_l			left fork
 */
typedef struct s_thread {
	u_int64_t				tid;
	u_int64_t				last_eat;
	u_int64_t				neat;
	struct s_philo_data		*philo_data;
	pthread_mutex_t			mutex_is_dead;
	u_int8_t				is_dead;
	pthread_mutex_t			*fork_r;
	pthread_mutex_t			*fork_l;
}	t_thread_data;

/**
 * @struct s_philo_data
 * @brief	contain philo datas
 * 
 * @var t_philo_data::ttd		time to die
 * @var t_philo_data::tte		time to eat
 * @var t_philo_data::tts		time to sleep
 * @var t_philo_data:ttt		time to think
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
	u_int64_t		start;
	int				finished;
	pthread_mutex_t	*forks;
	u_int64_t		iforks;
	t_thread_data	*philos;
	u_int64_t		nphilo;
	pthread_t		*threads;
	u_int64_t		nthreads;
}	t_philo_data;

#endif