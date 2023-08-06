#ifndef DEFINES_H
# define DEFINES_H

# include <sys/types.h>
# include <pthread.h>

# ifndef TRUE
#  define TRUE	1
# endif
# ifndef FALSE
#  define FALSE	0
# endif

typedef u_int8_t	t_bool;

/**
 *	Represent a mutex
 *
 *	@var t_mutex::m	the mutex
 *	@var t_mutex::i	is the mutex initialized
 */
typedef struct s_mutex {
	pthread_mutex_t	m;
	t_bool			i;
}	t_mutex;

/**
 * @var	t_philosopher::id				the philosopher's id (> 0)
 * @var t_philosopher::last_eat_mutex	mutex for last eat
 * @var t_philosopher::last_eat			last time the philosopher did eat
 * @var	t_philosopher::first			pointer to first fork
 * @var t_philosopher::second			pointer to second fork
 */
typedef struct s_philosopher {
	unsigned int		id;
	t_mutex				last_eat_mutex;
	u_int64_t			last_eat;
	t_mutex				*first;
	t_mutex				*second;
	struct s_philo_data	*datas;
}	t_philosopher;

/**
 * @var t_philo_data::nphilos			the number of philosophers
 * @var t_philo_data::ttd				time to die
 * @var t_philo_data::tte				time to eat
 * @var t_philo_data::tts				time to sleep
 * @var t_philo_data::max_eat			max time to eat (-1 == INF)
 * @var t_philo_data::philosophers		philosophers buffer
 * @var t_philo_data::forks				forks buffer
 * @var	t_philo_data::is_finished_mutex is_finished's mutex
 * @var t_philo_data::is_finished		is the program finished ?
 */
typedef struct s_philo_data {
	unsigned int	nphilos;
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int	tts;
	int				max_eat;
	t_philosopher	*philosophers;
	t_mutex			*forks;
	t_mutex			is_finished_mutex;
	t_bool			is_finished;
}	t_philo_data;

#endif
