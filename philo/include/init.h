/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:38:10 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/12 20:22:33 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <stdlib.h>
# include "defines.h"

/**
 * Initialize philo
 *
 * @param argc
 * @param argv
 * @param d
 */
int		philo_init(int argc, char **argv, t_philo_data *d);

int		philo_parse_args(int argc, char **argv, t_philo_data *d);

void	philo_exit(t_philo_data *d);

/**
 * @brief Initalize a mutex
 * 
 * @param m	The mutex to initialize
 * 
 * @return 1 on success, 0 on failure
 */
int		philo_init_mutex(t_mutex *m);

#endif
