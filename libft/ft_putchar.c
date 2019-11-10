/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:38:45 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 07:04:11 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	outputs char c to standard output
*/

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}
