#include "philo_bonus.h"

void	*monitor(void *param)
{
	t_philo	*philo;

	philo = param;
	while (!philo->info->stop)
	{
		sem_wait(philo->protect);
		if (get_time() - philo->start_time >= philo->info->time_die)
		{
			print_status(philo, DIED);
			philo->info->stop = 1;
			sem_post(philo->info->died);
			sem_post(philo->protect);
			break ;
		}
		sem_post(philo->protect);
		usleep(100);
	}
	return (NULL);
}

int		process(t_philo *philo)
{
	philo->start_time = get_time();
	if (pthread_create(&philo->monitor, NULL, monitor, philo))
		return (str_err("Failed to create thread.\n"));
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
	if (pthread_join(philo->monitor, NULL))
		return (str_err("Failed to join thread.\n"));
	return (0);
}

void	*check_meals(void *param)
{
	int		cnt;
	t_info	*info;

	info = param;
	cnt = 0;
	while (1)
	{
		sem_wait(info->full);

		cnt++;
		if (cnt == info->num_philo)
			break ;
	}
	return (NULL);
}

int		dining_philo(t_info *info)
{
	int			i;
	pthread_t	full;

	if (pthread_create(&full, NULL, check_meals, info))
		return (str_err("Failed to create thread.\n"));
	info->base_time = get_time();
	i = -1;
	while (++i < info->num_philo)
	{
		// info->philo[i].start_time = get_time();
		info->philo[i].philo_p = fork();
		if (info->philo[i].philo_p == 0)
		{
			if (process(&info->philo[i]))
				return (1);
		}
		else if (info->philo[i].philo_p < 0)
			return (str_err("Failed to fork process.\n"));
	}

	return (0);
}
