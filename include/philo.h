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

void			algo(t_thread_data *td);

#endif