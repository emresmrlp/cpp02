/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:54:17 by ysumeral          #+#    #+#             */
/*   Updated: 2025/09/04 19:42:15 by ysumeral         ###   ########.fr       */
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
	~Fixed();
	Fixed				&operator=(const Fixed& ref);
	Fixed				operator+(const Fixed& ref) const;
	Fixed				operator-(const Fixed& ref) const;
	Fixed				operator*(const Fixed& ref) const;
	Fixed				operator/(const Fixed& ref) const;
	bool				operator<(const Fixed& ref) const;
	bool				operator<=(const Fixed& ref) const;
	bool				operator>(const Fixed& ref) const;
	bool				operator>=(const Fixed& ref) const;
	bool				operator==(const Fixed& ref) const;
	bool				operator!=(const Fixed& ref) const;
	Fixed				&operator++();
	Fixed				operator++(int);
	Fixed				&operator--();
	Fixed				operator--(int);
	static Fixed		&max(Fixed &ref_one, Fixed &ref_two);
	static const Fixed	&max(const Fixed &ref_one, const Fixed &ref_two);
	static Fixed		&min(Fixed &ref_one, Fixed &ref_two);
	static const Fixed	&min(const Fixed &ref_one, const Fixed &ref_two);
	float				toFloat(void) const;
	int					toInt(void) const;
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
private:
	int         		numberValue;
	static const int    fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed& ref);