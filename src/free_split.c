/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:27:15 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/29 17:34:40 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	free_split(char **nums)
{
	int	i;

	i = 0;
	if (!nums)
		return ;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}
