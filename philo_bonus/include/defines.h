#ifndef DEFINES_H
# define DEFINES_H

# include <pthread.h>
# include <semaphore.h>

# ifndef TRUE
#  define TRUE	1
# endif
# ifndef FALSE
#  define FALSE	0
# endif

typedef int	t_bool;

typedef struct s_sem {
	sem_t	*sem;
	char	*name;
}	t_sem;

typedef struct	s_philo_data
{
	int				nphilos;
	int				id;
	int				ttd;
	int				tte;
	int				tts;
	int				max_eat;
	pthread_mutex_t	mutex_last_eat;
	u_int64_t		last_eat;
	t_sem			output_sem;
	t_sem			forks_prelock;
	t_sem			forks;
	t_sem			sem_finished;
	t_bool			is_finished;
}	t_philo_data;

typedef struct	s_philo_data_main
{
	t_philo_data	_data;
	pid_t			*childs;
}	t_philo_data_main;

#endif