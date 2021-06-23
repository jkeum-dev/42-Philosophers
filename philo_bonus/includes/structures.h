#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <unistd.h>	// fork, usleep

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct s_info
{
	int		num_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_must_eat;
	int		stop;
	int		base_time;
	sem_t	*fork;
	sem_t	*print;
	sem_t	*full;
	sem_t	*died;
	t_philo	*philo;
};

struct s_philo
{
	int		n;
	int		start_time;
	int		meals;
	pid_t	philo_p;
	sem_t	*eating;
	t_info	*info;
};

#endif
