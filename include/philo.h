/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:34:55 by pducloux          #+#    #+#             */
/*   Updated: 2023/08/02 15:48:12 by pducloux         ###   ########.fr       */
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
 * Check if given philosopher died
 * 
 * @param d
 * 
 * @return
 */
bool				test_is_dead(t_philosopher *d);

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

/**
 * Check if philosopher is finished (eg: one philosopher died or all ate enough)
 * 
 * @param pd 
 * 
 * @return true		if philosopher is finished
 * @return false	if philosopher is not finished
 */
bool			philo_is_finished(t_philo_data *pd);

/**
 * Set philosopher as finished
 * 
 * @param pd 
 */
void			philo_set_finished(t_philo_data *pd);

#endif