#include "philo.h"

int	init_fork(t_info *info)
{
	int	i;

	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
	* info->num_philo);
	if (!info->fork)
		return (str_err("Failed to allocate memory.\n"));
	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (str_err("Failed to initialize mutex.\n"));
	}
	return (0);
}

int	init_info(t_info *info, char **argv, int argc)
{
	info->num_philo = ft_atoi_pos(argv[1]);
	if (info->num_philo <= 0)
		return (str_err("The number of philosophers must be at least one.\n"));
	else if (info->num_philo > 200)
		return (str_err("Do not test with more than 200 philosophers.\n"));
	info->time_die = ft_atoi_pos(argv[2]);
	info->time_eat = ft_atoi_pos(argv[3]);
	info->time_sleep = ft_atoi_pos(argv[4]);
	if (info->time_die < 60 || info->time_eat < 60 || info->time_sleep < 60)
		return (str_err("Do not test under 60ms.\n"));
	if (argc == 6)
	{
		info->num_must_eat = ft_atoi_pos(argv[5]);
		if (info->num_must_eat <= 0)
			return (str_err("Each philosopher must eat at least once.\n"));
	}
	else
		info->num_must_eat = -1;
	info->stop = 0;
	info->base_time = 0;
	if (init_fork(info))
		return (1);
	if (pthread_mutex_init(&info->status, NULL))
		return (str_err("Failed to initialize mutex.\n"));
	return (0);
}

int	init_philo(t_info *info)
{
	int	i;

	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (!info->philo)
		return (str_err("Failed to allocate memory.\n"));
	i = -1;
	while (++i < info->num_philo)
	{
		info->philo[i].n = i;
		info->philo[i].fork_l = i;
		info->philo[i].fork_r = (i + 1) % info->num_philo;
		info->philo[i].start_time = 0;
		info->philo[i].meals = 0;
		info->philo[i].info = info;
		if (pthread_mutex_init(&info->philo[i].protect, NULL))
			return (str_err("Failed to initialize mutex.\n"));
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 5 || argc > 6)
		return (str_err("Error: argument\n"));
	memset(&info, 0, sizeof(t_info));
	if (init_info(&info, argv, argc))
		return (1);
	if (init_philo(&info))
		return (1);
	if (dining_philo(&info))
		return (1);
	return (0);
}
