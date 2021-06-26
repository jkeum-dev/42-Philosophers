#include "philo_bonus.h"

void	eating(t_philo *philo)
{
	sem_wait(philo->info->fork);
	print_status(philo, FORK);
	sem_wait(philo->info->fork);
	print_status(philo, FORK);
	sem_wait(philo->protect);
	print_status(philo, EATING);
	philo->start_time = get_time();
	sem_post(philo->protect);
	while (get_time() - philo->start_time <= philo->info->time_eat && \
	!philo->info->stop)
		usleep(1000);
	philo->meals++;
	sem_post(philo->info->fork);
	sem_post(philo->info->fork);
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
