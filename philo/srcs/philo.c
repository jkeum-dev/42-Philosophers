#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (philo->n % 2 == 0)
	{
		pthread_mutex_lock(&(philo->info->fork[philo->fork_r]));
		print_status(philo, FORK);
		pthread_mutex_lock(&(philo->info->fork[philo->fork_l]));
		print_status(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(&(philo->info->fork[philo->fork_l]));
		print_status(philo, FORK);
		pthread_mutex_lock(&(philo->info->fork[philo->fork_r]));
		print_status(philo, FORK);
	}
}

void	eating(t_philo *philo)
{
	int	i;

	take_fork(philo);
	print_status(philo, EATING);
	i = -1;
	while (++i < philo->info->time_eat && !philo->info->stop)
		usleep(1000);
	philo->meals++;
	if (philo->n % 2 == 0)
	{
		pthread_mutex_unlock(&(philo->info->fork[philo->fork_r]));
		pthread_mutex_unlock(&(philo->info->fork[philo->fork_l]));
	}
	else
	{
		pthread_mutex_unlock(&(philo->info->fork[philo->fork_l]));
		pthread_mutex_unlock(&(philo->info->fork[philo->fork_r]));
	}
}

void	sleeping(t_philo *philo)
{
	int	i;

	print_status(philo, SLEEPING);
	i = -1;
	while (++i < philo->info->time_sleep && !philo->info->stop)
		usleep(1000);
}

void	thinking(t_philo *philo)
{
	print_status(philo, THINKING);
}
