/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:34:55 by pducloux          #+#    #+#             */
/*   Updated: 2023/05/24 15:43:11 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "defines.h"

void			philo_parse(int argc, char **argv);

void			philo_exit(int code, char *msg);

void			philo_log(t_philo *philo);

t_philo_data	*philo(void);

#endif