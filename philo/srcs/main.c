#include "philo.h"

int	get_base_info(t_info *info, char **argv, int argc)
{
	info->num_philo = ft_atoi_pos(argv[1]);
	if (info->num_philo <= 0)
		return (str_err("The number of philosophers must be at least one.\n"));
	else if (info->num_philo > 200)
		return (str_err("Do not test with more than 200 philosophers\n"));
	info->time_die = ft_atoi_pos(argv[2]);
	info->time_eat = ft_atoi_pos(argv[3]);
	info->time_sleep = ft_atoi_pos(argv[4]);
	if (info->time_die < 60 || info->time_eat < 60 || info->time_sleep < 60)
		return (str_err("Do not test under 60ms\n"));
	if (argc == 6)
		info->num_must_eat = ft_atoi_pos(argv[5]);
	else
		info->num_must_eat = -1;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 5 || argc > 6)
		return (str_err("Error: argument\n"));
	if (get_base_info(&info, argv, argc))
		return (1);
}
