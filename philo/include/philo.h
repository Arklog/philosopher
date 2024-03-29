/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:38:16 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/11 16:15:52 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include "defines.h"

void		*algo(void *p);

void		philosopher_eat(t_philosopher *p);

void		philosopher_sleep(t_philosopher *p);

void		philosopher_think(t_philosopher *p);

void		philosopher_die(t_philosopher *p);

t_bool		is_philosopher_dead(t_philosopher *p);

t_bool		have_philosopher_eaten(t_philosopher *p);

u_int64_t	gettimestamp(void);

t_bool		is_philo_finished(t_philo_data *d);

void		set_philo_finished(t_philo_data *d);

void		monitor(t_philo_data *d);

void		print_text(t_philosopher *p, char *text);

void		print_take_fork(t_philosopher *p);

void		print_eat(t_philosopher *p);

void		print_sleep(t_philosopher *p);

void		print_think(t_philosopher *p);

/**
 * @brief Usleep with 
 * 
 * @param usecond 
 * @param d 
 */
void		safe_usleep(u_int64_t usecond, t_philo_data *d);

#endif
