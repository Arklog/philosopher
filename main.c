/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:34:47 by pducloux          #+#    #+#             */
/*   Updated: 2023/07/07 02:35:24 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	size_t	i;
	void	*r;

	philo_init(argc, argv);
	philo_start(philo());
	main_loop(philo());
	i = 0;
	while (i < philo()->nphilo)
		pthread_join(philo()->threads[i++], &r);
	philo_exit(0, NULL);
}
