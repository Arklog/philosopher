/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parse_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:36:36 by pierre            #+#    #+#             */
/*   Updated: 2023/10/12 19:36:13 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_stdlib.h"

static int	parse_mandatory(int argc, char **argv, t_philo_data *d)
{
	char	*endptr;

	(void)argc;
	endptr = NULL;
	d->nphilos = ft_strtoi(argv[1], &endptr, 10);
	if (endptr != argv[1] + ft_strlen(argv[1]) || d->nphilos <= 0)
		return (0);
	d->ttd = ft_strtoi(argv[2], &endptr, 10);
	if (endptr != argv[2] + ft_strlen(argv[2]) || d->ttd < 0)
		return (0);
	d->tte = ft_strtoi(argv[3], &endptr, 10);
	if (endptr != argv[3] + ft_strlen(argv[3]) || d->tte < 0)
		return (0);
	d->tts = ft_strtoi(argv[4], &endptr, 10);
	if (endptr != argv[4] + ft_strlen(argv[4]) || d->tts < 0)
		return (0);
	return (1);
}

int	philo_parse_args(int argc, char **argv, t_philo_data *d)
{
	char	*endptr;

	if (argc < 5 || argc > 6)
		return (0);
	endptr = NULL;
	if (!parse_mandatory(argc, argv, d))
		return (0);
	if (argc == 6)
	{
		d->max_eat = ft_strtoi(argv[5], &endptr, 10);
		if (endptr != argv[5] + ft_strlen(argv[5]) || d->max_eat <= 0)
			return (0);
	}
	else
		d->max_eat = -1;
	return (1);
}
