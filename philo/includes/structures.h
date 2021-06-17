#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <pthread.h>

typedef struct	s_info	t_info;
typedef struct	s_philo	t_philo;

struct s_info
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_must_eat;
	int				stop;
	int				base_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	status;
	t_philo			*philo;
};

struct s_philo
{
	int			n;
	int			fork_l;
	int			fork_r;
	int			start_time;
	int			meals;
	pthread_t	philo_th;
	pthread_t	monitor;
	t_info		*info;
};

#endif
