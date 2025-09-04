/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:54:17 by ysumeral          #+#    #+#             */
/*   Updated: 2025/09/04 14:32:32 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
public:
	Fixed();
    Fixed(const int raw);
    Fixed(const float raw);
	Fixed(const Fixed& ref);
	Fixed &operator=(const Fixed& ref);
	~Fixed();
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int         		numberValue;
	static const int    fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed& ref);