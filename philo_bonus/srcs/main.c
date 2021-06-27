#include "philo_bonus.h"

int		ft_pthread_init(pthread_t pth, void *func, void *param)
{
	if (pthread_create(&pth, NULL, func, param))
		return (str_err("Failed to create thread.\n"));
	if (pthread_detach(pth))
		return (str_err("Failed to detach thread.\n"));
	return (0);
}

sem_t	*ft_sem_unlink_open(char *name, int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

int		init_info(t_info *info, char **argv, int argc)
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
	info->all_full = 0;
	info->fork = ft_sem_unlink_open("/fork", info->num_philo);
	info->status = ft_sem_unlink_open("/status", 1);
	info->full = ft_sem_unlink_open("/full", 0);
	info->died = ft_sem_unlink_open("/died", 0);
	return (0);
}

int		init_philo(t_info *info)
{
	int		i;
	char	*name;

	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (!info->philo)
		return (str_err("Failed to allocate memory.\n"));
	i = -1;
	while (++i < info->num_philo)
	{
		info->philo[i].n = i;
		info->philo[i].start_time = 0;
		info->philo[i].meals = 0;
		info->philo[i].info = info;
		name = ft_strjoin_free("/protect", ft_itoa(i + 1));
		info->philo[i].protect = ft_sem_unlink_open(name, 1);
		free(name);
	}
	return (0);
}

int		main(int argc, char *argv[])
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
	{
		free_all(&info);
		return (1);
	}
	free_all(&info);
	// system("leaks philo_bonus");
	return (0);
}
