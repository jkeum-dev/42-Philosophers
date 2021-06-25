#include "philo_bonus.h"

void	eating(t_philo *philo)
{
	sem_wait(philo->info->fork);
	print_status(philo, FORK);
	sem_wait(philo->info->fork);
	print_status(philo, FORK);
	sem_wait(philo->protect);
	print_status(philo, EATING);
	
}