#include "philo.h"

void	eating(t_philo *philo)
{
	if (philo->info->num_philo == 1)
	{
		pthread_mutex_lock(&philo->info->fork[philo->fork_r]);
		print_status(philo, FORK);
		while (!philo->info->stop)
			usleep(1000);
		pthread_mutex_unlock(&philo->info->fork[philo->fork_r]);
	}
	else
	{
		pthread_mutex_lock(&philo->info->fork[philo->fork_r]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->info->fork[philo->fork_l]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->protect);
		print_status(philo, EATING);
		philo->start_time = get_time();
		pthread_mutex_unlock(&philo->protect);
		while (get_time() - philo->start_time <= philo->info->time_eat && \
		!philo->info->stop)
			usleep(1000);
		philo->meals++;
		pthread_mutex_unlock(&philo->info->fork[philo->fork_r]);
		pthread_mutex_unlock(&philo->info->fork[philo->fork_l]);
	}
}

void	sleeping(t_philo *philo)
{
	int	start_sleep;

	start_sleep = get_time();
	print_status(philo, SLEEPING);
	while (get_time() - start_sleep <= philo->info->time_sleep && \
	!philo->info->stop)
		usleep(1000);
}

void	thinking(t_philo *philo)
{
	print_status(philo, THINKING);
}
