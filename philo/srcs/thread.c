#include "philo.h"

void	*philo(t_philo *philo)
{
	while (!philo->info->stop)
	{
		eating(philo);
		if (philo->info->stop)
			break ;
		sleeping(philo);
		if (philo->info->stop)
			break ;
		thinking(philo);
		if (philo->info->stop)
			break ;
	}
	return (NULL);
}

void	*monitor(t_philo *philo)
{

}

int		dining_philo(t_info *info)
{
	int	i;

	info->base_time = get_time();
	i = -1;
	while (++i < info->num_philo)
	{
		info->philo[i].start_time = get_time();
		if (pthread_create(&(info->philo[i].philo_th), NULL, philo, &(info->philo[i])))
			return (str_err("Failed to create thread.\n"));
		if (pthread_create(&(info->philo[i].monitor), NULL, monitor, &(info->philo[i])))
			return (str_err("Failed to create thread.\n"));
		usleep(1000);
	}
	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_join(info->philo[i].philo_th, NULL))
			return (str_err("Failed to join thread.\n"));
		if (pthread_join(info->philo[i].monitor, NULL))
			return (str_err("Failed to join thread.\n"));
	}
	return (0);
}
