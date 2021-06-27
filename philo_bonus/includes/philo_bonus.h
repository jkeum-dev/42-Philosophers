#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>	// exit
# include <stdio.h>
# include <string.h>
# include <signal.h>	// kill
# include <sys/time.h>	// gettimeofday
# include <sys/wait.h>	// waitpid
# include <semaphore.h>	// sem_()
# include "structures.h"

# define MAX_INT 2147483647

# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5

int		str_err(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin_free(char *s1, char *s2);
int		get_time(void);

int		ft_atoi_pos(char *arg);
char	*ft_itoa(int n);

int		dining_philo(t_info *info);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

void	print_status(t_philo *philo, int status);

#endif
