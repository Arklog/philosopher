/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:34:06 by pducloux          #+#    #+#             */
/*   Updated: 2023/05/24 15:37:33 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define PHILO_EATING		1
# define PHILO_SLEEPING		2
# define PHILO_DEAD			3

# include <sys/types.h>

typedef struct s_philosopher
{
	int		id;
	char	state;
}	t_philo;

typedef struct s_philo_data
{
	t_philo	*philosophers;
	size_t	n;
	size_t	time_to_die;
	size_t	time_to_eat;
	int		neat;
}	t_philo_data;

#endif