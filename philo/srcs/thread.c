#include "philo.h"

int		check_meals(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->num_philo)
	{
		if (philo->info->philo[i].meals != philo->info->num_must_eat)
			return (0);
	}
	philo->info->stop = 1;
	return (1);
}

void	*philo(void *param)
{
	t_philo	*philo;

	philo = param;
	while (!philo->info->stop)
	{
		eating(philo);
		if (philo->info->num_must_eat != -1 && check_meals(philo))
			break ;
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

void	*monitor(void *param)
{
	t_philo	*philo;

	philo = param;
	while (!philo->info->stop)
	{
		if (get_time() - philo->start_time >= philo->info->time_die)
		{
			print_status(philo, DIED);
			philo->info->stop = 1;
			break ;
		}
		usleep(100);
	}
	return (NULL);
}

int		dining_philo(t_info *info)
{
	int	i;

	info->base_time = get_time();
	i = -1;
	while (++i < info->num_philo)
	{
		info->philo[i].start_time = get_time();
		if (pthread_create(&info->philo[i].philo_th, NULL, \
		philo, &info->philo[i]))
			return (str_err("Failed to create thread.\n"));
		if (pthread_create(&info->philo[i].monitor, NULL, \
		monitor, &info->philo[i]))
			return (str_err("Failed to create thread.\n"));
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
