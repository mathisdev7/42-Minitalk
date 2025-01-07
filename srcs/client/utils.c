/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:17:47 by mazeghou          #+#    #+#             */
/*   Updated: 2025/01/07 15:27:32 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"
#include "../../includes/client_bonus.h"

int	calculate_delay(int len)
{
	if (len > 50000)
		return (100);
	if (len > 25000)
		return (60);
	if (len > 10000)
		return (35);
	return (15);
}
