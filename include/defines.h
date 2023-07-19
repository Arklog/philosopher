/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:34:06 by pducloux          #+#    #+#             */
/*   Updated: 2023/07/19 02:20:53 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <sys/types.h>
# include <pthread.h>

typedef struct s_thread {
	u_int64_t	tid;
	u_int64_t	last_eat;
	u_int64_t	last_sleep;
}	t_thread_data;

/**
 * @struct s_philo_data
 * @brief	contain philo datas
 * 
 * @var t_philo_data::nphilo	number of philosophers
 * @var t_philo_data::ttd		time to die
 * @var t_philo_data::tte		time to eat
 * @var t_philo_data::tts		time to sleep
 * @var t_philo_data::neat		number of time to eat
 * @var t_philo_data::start		start of the program
 * @var t_philo_data::forks		the forks
 * @var t_philo_data::iforks	number of forks initialized
*/
typedef struct s_philo_data {
	u_int64_t		nphilo;
	u_int64_t		ttd;
	u_int64_t		tte;
	u_int64_t		tts;
	u_int64_t		start;
	pthread_mutex_t	*forks;
	u_int64_t		iforks;
	pthread_t		*threads;
	t_thread_data	*philos;
	u_int64_t		nthreads;
}	t_philo_data;


#endif