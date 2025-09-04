/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:55:13 by ysumeral          #+#    #+#             */
/*   Updated: 2025/09/04 20:28:14 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#pragma once

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &ref);
	Point	&operator=(const Point& ref);
	~Point();
	const Fixed getXFixed() const;
	const Fixed getYFixed() const;
private:
	const Fixed x;
	const Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);