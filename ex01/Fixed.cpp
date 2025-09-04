/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:54:04 by ysumeral          #+#    #+#             */
/*   Updated: 2025/09/04 19:00:33 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : numberValue(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called." << std::endl;
	this->numberValue = raw << fractionalBits;
}

Fixed::Fixed(const float raw)
{
	int fixedValue;
	
	std::cout << "Float constructor called." << std::endl;
	fixedValue = roundf(raw * (1 << fractionalBits));
	this->numberValue = fixedValue;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	this->numberValue = ref.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &ref)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	setRawBits(ref.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &ref)
{
	os << ref.toFloat();
	return (os);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	float	floatValue;

	floatValue = (float)this->numberValue / (1 << fractionalBits);
	return (floatValue);
}

int		Fixed::toInt(void) const
{
	return (this->numberValue >> fractionalBits);
}

int		Fixed::getRawBits(void) const
{
	return (this->numberValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->numberValue = raw;
}