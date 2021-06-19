#include "philo.h"

void	take_fork(t_philo *philo)
{
	// if (philo->n % 2 == 0)
	// {
	// 	pthread_mutex_lock(&(philo->info->fork[philo->fork_r]));
	// 	print_status(philo, FORK);
	// 	pthread_mutex_lock(&(philo->info->fork[philo->fork_l]));
	// 	print_status(philo, FORK);
	// }
	// else
	// {
	// 	pthread_mutex_lock(&(philo->info->fork[philo->fork_l]));
	// 	print_status(philo, FORK);
	// 	pthread_mutex_lock(&(philo->info->fork[philo->fork_r]));
	// 	print_status(philo, FORK);
	// }
	// if (philo->info->starv[philo->fork_r] == 0 && philo->info->starv[philo->fork_l] == 0)
	// {
	// 	philo->info->starv[philo->fork_r] = 1;
	// 	philo->info->starv[philo->fork_l] = 1;
	// 	pthread_mutex_lock(&(philo->info->fork[philo->fork_r]));
	// 	print_status(philo, FORK);
	// 	pthread_mutex_lock(&(philo->info->fork[philo->fork_l]));
	// 	print_status(philo, FORK);
	// 	return (0);
	// }
	// else
	// 	return (1);

	pthread_mutex_lock(&(philo->info->fork[philo->fork_r]));
	print_status(philo, FORK);
	pthread_mutex_lock(&(philo->info->fork[philo->fork_l]));
	print_status(philo, FORK);
}

void	eating(t_philo *philo)
{
	// if (take_fork(philo))
	// 	return (1);
	take_fork(philo);
	print_status(philo, EATING);
	philo->start_time = get_time();
	while (get_time() - philo->start_time <= philo->info->time_eat && \
	!philo->info->stop)
		usleep(1000);
	philo->meals++;
	// if (philo->n % 2 == 0)
	// {
	// 	pthread_mutex_unlock(&(philo->info->fork[philo->fork_r]));
	// 	pthread_mutex_unlock(&(philo->info->fork[philo->fork_l]));
	// }
	// else
	// {
	// 	pthread_mutex_unlock(&(philo->info->fork[philo->fork_l]));
	// 	pthread_mutex_unlock(&(philo->info->fork[philo->fork_r]));
	// }
	pthread_mutex_unlock(&(philo->info->fork[philo->fork_r]));
	pthread_mutex_unlock(&(philo->info->fork[philo->fork_l]));
	// philo->info->starv[philo->fork_r] = 0;
	// philo->info->starv[philo->fork_l] = 0;
	// return (0);
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
