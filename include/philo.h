/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:34:55 by pducloux          #+#    #+#             */
/*   Updated: 2023/07/19 02:43:09 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "defines.h"
# include "output.h"
# include "do.h"
# include <unistd.h>
# include <sys/time.h>

/**
 * Get philo global datas
*/
t_philo_data	*philo(void);

/**
 * Initialize philo
 * 
 * @param argc
 * @param argv
*/
void			philo_init(int argc, char **argv);

/**
 * Exit philo whith given code and display message
*/
void			philo_exit(int code, char *msg);

/**
 * The thread function
 * @param td
 */
void			*algo(void *td);

/**
 * Check given philosopher died
 * @param d
 * @return
 */
int				test_is_dead(t_thread_data *d);

/**
 * Loop checking if any thread died
 *
 * @param pd
 */
void			main_loop(t_philo_data *pd);

/**
 * Start all threads
 *
 * @param pd
 */
void			philo_start(t_philo_data *pd);

#endif