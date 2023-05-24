/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:34:06 by pducloux          #+#    #+#             */
/*   Updated: 2023/05/24 14:45:13 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define PHILO_EATING		1
# define PHILO_SLEEPING		2
# define PHILO_DEAD			3

# include <sys/types.h>

typedef char	t_philo;

typedef struct s_philo_data
{
	t_philo	*philosophers;
	size_t	n;
}	t_philo_data;

#endif