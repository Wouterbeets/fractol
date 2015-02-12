/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:29:45 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/11/25 16:26:28 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int c)
{
	int		result;

	result = 0;
	if (c >= 65 && c <= 90)
		return (result = (c + 32));
	else
		return (c);
}
