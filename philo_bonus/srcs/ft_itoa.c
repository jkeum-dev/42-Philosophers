#include "philo_bonus.h"

static int	n_len(int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	while (i < --len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
	}
	return (str);
}

static char	*get_arr(char *res, int n, int len, int sign)
{
	int	i;

	i = 0;
	res[len + sign] = '\0';
	if (n == 0)
		res[i] = '0';
	else
	{
		while (n > 0)
		{
			res[i++] = n % 10 + '0';
			n /= 10;
		}
		if (sign == 1)
			res[i] = '-';
		res = ft_strrev(res);
	}
	return (res);
}

static char	*ft_strdup(char *s1)
{
	char	*res;
	int		i;

	res = malloc(ft_strlen(s1) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	len = n_len(n);
	res = (char *)malloc(len + sign + 1);
	if (!res)
		return (NULL);
	res = get_arr(res, n, len, sign);
	return (res);
}
