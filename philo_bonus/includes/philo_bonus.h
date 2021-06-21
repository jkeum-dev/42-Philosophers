#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>	// exit
# include <stdio.h>
# include <string.h>
# include <signal.h>	// kill
# include <sys/time.h>	// gettimeofday
# include <sys/wait.h>	// waitpid
# include <pthread.h>	// pthread_()
# include <semaphore.h>	// sem_()
# include "structures.h"

# define MAX_INT 2147483647

int		str_err(char *str);
int		ft_strlen(char *str);
int		get_time(void);

int		ft_atoi_pos(char *arg);

#endif
