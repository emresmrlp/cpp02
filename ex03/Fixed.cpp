/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:54:04 by ysumeral          #+#    #+#             */
/*   Updated: 2025/09/04 21:07:11 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : numberValue(0)
{
	return ;
}

Fixed::Fixed(const int raw)
{
	this->numberValue = raw << fractionalBits;
}

Fixed::Fixed(const float raw)
{
	int fixedValue;
	
	fixedValue = roundf(raw * (1 << fractionalBits));
	this->numberValue = fixedValue;
}

Fixed::Fixed(const Fixed &ref)
{
	this->numberValue = ref.getRawBits();
}

Fixed::~Fixed()
{
	return ;
}

Fixed &Fixed::max(Fixed &ref_one, Fixed &ref_two)
{
	if (ref_one < ref_two)
		return (ref_two);
	return (ref_one);	
}

const Fixed &Fixed::max(const Fixed &ref_one, const Fixed &ref_two)
{
	if (ref_one < ref_two)
		return (ref_two);
	return (ref_one);	
}

Fixed &Fixed::min(Fixed &ref_one, Fixed &ref_two)
{
	if (ref_one > ref_two)
		return (ref_two);
	return (ref_one);
}

const Fixed &Fixed::min(const Fixed &ref_one, const Fixed &ref_two)
{
	if (ref_one > ref_two)
		return (ref_two);
	return (ref_one);
}

Fixed &Fixed::operator=(const Fixed &ref)
{
	setRawBits(ref.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &ref)
{
	os << ref.toFloat();
	return (os);
}

Fixed Fixed::operator+(const Fixed &ref) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + ref.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &ref) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - ref.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &ref) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() * ref.getRawBits()) >> fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &ref) const
{
	Fixed result;
	if (ref.getRawBits() != 0)
		result.setRawBits((this->getRawBits() << fractionalBits) / ref.getRawBits());
	else
	{
		std::cerr << "Error: Division by zero. Returned the main value!" << std::endl;
		return (*this);
	}
	return (result);
}

bool Fixed::operator<(const Fixed &ref) const
{
	if (this->getRawBits() < ref.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &ref) const
{
	if (this->getRawBits() <= ref.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed &ref) const
{
	if (this->getRawBits() > ref.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &ref) const
{
	if (this->getRawBits() >= ref.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &ref) const
{
	if (this->getRawBits() == ref.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &ref) const
{
	if (this->getRawBits() != ref.getRawBits())
		return (true);
	return (false);
}

Fixed &Fixed::operator++()
{
	this->numberValue += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->numberValue += 1;
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->numberValue -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->numberValue -= 1;
	return (temp);
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