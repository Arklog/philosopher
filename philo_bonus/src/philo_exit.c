#include "philo.h"

static void	free_sem(t_sem s, t_bool from_child)
{
	if (s.sem != SEM_FAILED && !from_child)
	{
		sem_close(s.sem);
		sem_unlink(s.name);
	}
	else if (s.sem != SEM_FAILED)
	{
		sem_close(s.sem);
	}
}

void	philo_exit(t_philo_data_main *d, int exit_code)
{
	t_philo_data	*dat;

	dat = &(d->_data);
	if (d->childs)
		free(d->childs);
	free_sem(dat->output_sem, FALSE);
	free_sem(dat->forks_prelock, FALSE);
	free_sem(dat->forks, FALSE);
	free_sem(dat->sem_finished, FALSE);
	exit(exit_code);
}

void	philo_exit_child(t_philo_data *d)
{
	t_philo_data_main	*m;

	m = (t_philo_data_main *)d;
	if (m->childs)
		free(m->childs);
	free_sem(d->output_sem, TRUE);
	free_sem(d->forks_prelock, TRUE);
	free_sem(d->forks, TRUE);
	free_sem(d->sem_finished, TRUE);
	exit(0);
}
