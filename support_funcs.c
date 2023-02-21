/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   support_funcs.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 15:00:32 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/02/21 15:01:24 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// get str length: 
unsigned	int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}