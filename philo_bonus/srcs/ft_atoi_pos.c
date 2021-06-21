#include "philo_bonus.h"

static int	chk_arg_length(char *arg)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (arg[0] == '+' || arg[0] == '-')
	{
		i++;
		len--;
	}
	while (arg[i] == '0')
		i++;
	while (arg[i++])
		len++;
	return (len);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	is_numeric(char *arg)
{
	int	i;

	if (!arg)
		return (0);
	i = -1;
	if (arg[0] == '+' || arg[0] == '-')
		i++;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
	}
	return (1);
}

static int	check_arg(char *arg)
{
	int	len;

	len = chk_arg_length(arg);
	if (!is_numeric(arg) || len > 11 || len < 0)
		return (0);
	else
		return (1);
}

int			ft_atoi_pos(char *arg)
{
	int			i;
	int			sign;
	long long	value;

	if (!check_arg(arg))
		return (-1);
	i = 0;
	sign = 1;
	value = 0;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i++] == '-')
			sign = -1;
	}
	while (arg[i])
		value = value * 10 + (arg[i++] - '0');
	value = value * sign;
	if (value > MAX_INT || value <= 0)
		return (-1);
	return (value);
}
