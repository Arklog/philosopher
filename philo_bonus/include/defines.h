#ifndef DEFINES_H
# define DEFINES_H

#include <pthread.h>

typedef struct	s_philo_data
{
	int nphilos;
	int id;
	int ttd;
	int tte;
	int tts;
	int max_eat;
}	t_philo_data;

typedef struct	s_philo_data_main
{
	t_philo_data	_data;
	pid_t			*childs;
}	t_philo_data_main;

#endif