/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:28:29 by ysumeral          #+#    #+#             */
/*   Updated: 2025/09/04 21:12:07 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static float sign(Point const point, Point const edgeStart, Point const edgeEnd)
{
	float	result;
	float	edgeVecX;
	float	edgeVecY;
	float	pointVecX;
	float	pointVecY;

	edgeVecX = edgeEnd.getXFixed().toFloat() - edgeStart.getXFixed().toFloat();
	edgeVecY = edgeEnd.getYFixed().toFloat() - edgeStart.getYFixed().toFloat();
	pointVecX = point.getXFixed().toFloat() - edgeStart.getXFixed().toFloat();
	pointVecY = point.getYFixed().toFloat() - edgeStart.getYFixed().toFloat();
	result = (edgeVecX * pointVecY) - (edgeVecY * pointVecX);
	return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	result;
	float	signAB;
	float	signBC;
	float	signCA;

	signAB = sign(point, a, b);
	signBC = sign(point, b, c);
	signCA = sign(point, c, a);
	if (signAB == 0.0f || signBC == 0.0f || signCA == 0.0f)
		return (false);
	result = ((signAB > 0.0f) && (signBC > 0.0f) && (signCA > 0.0f))
			|| ((signAB < 0.0f) && (signBC < 0.0f) && (signCA < 0.0f));
	return (result);
}
