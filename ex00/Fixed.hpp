/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:54:17 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/30 09:46:46 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& ref);
	Fixed& operator=(const Fixed& ref);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int					fixedNumberValue;
	static const int	fractionalBits = 8;
};