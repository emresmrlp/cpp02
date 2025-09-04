/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:50:19 by ysumeral          #+#    #+#             */
/*   Updated: 2025/09/04 21:06:43 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0)
{
	return ;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
	return ;
}

Point::Point(const Point &ref) : x(ref.x), y(ref.y)
{
	return ;
}

Point::~Point()
{
	return ;
}

Point &Point::operator=(const Point &ref)
{
	(void)ref;
	return (*this);
}

const Fixed Point::getXFixed() const
{
	return (this->x);
}

const Fixed Point::getYFixed() const
{
	return (this->y);
}