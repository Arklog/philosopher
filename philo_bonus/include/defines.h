#ifndef DEFINES_H
# define DEFINES_H

# include <pthread.h>
# include <semaphore.h>

typedef struct	s_philo_data
{
	int			nphilos;
	int			id;
	int			ttd;
	int			tte;
	int			tts;
	int			max_eat;
	u_int64_t	last_eat;
	sem_t		*output_sem;
	sem_t		*forks[2];
}	t_philo_data;

typedef struct	s_philo_data_main
{
	t_philo_data	_data;
	pid_t			*childs;
	sem_t			*forks;
}	t_philo_data_main;

#endif