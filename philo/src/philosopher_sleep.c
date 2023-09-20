/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_sleep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:53 by pducloux          #+#    #+#             */
/*   Updated: 2023/09/07 19:39:54 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "ft_math.h"

void	philosopher_sleep(t_philosopher *p)
{
	print_sleep(p);
	usleep(p->datas->tts * 1000);
}
