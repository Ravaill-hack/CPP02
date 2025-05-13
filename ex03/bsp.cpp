/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:45:04 by Lmatkows          #+#    #+#             */
/*   Updated: 2025/05/13 08:23:43 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	isOnEdge(Point const & a, Point const & b, Point const point)
{
	float	triangle_Area = triangleArea(a, b, point);

	if (triangle_Area >= 0.0001)
		return (0);
	else if (point.getFixedX() >= Fixed::min(a.getFixedX(), b.getFixedX())
			&& point.getFixedX() <= Fixed::max(a.getFixedX(), b.getFixedX())
			&& point.getFixedY() >= Fixed::min(a.getFixedY(), b.getFixedY())
			&& point.getFixedY() <= Fixed::max(a.getFixedY(), b.getFixedY()))
			return (1);
	else
		return (0);
}

float	triangleArea(Point const & a, Point const & b, Point const & c)
{
	return (0.5f * std::abs(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	triangle_Area = triangleArea(a, b, c);
	float	subTriangles_Area = (triangleArea(a, b, point) + triangleArea(b, c, point) + triangleArea(c, a, point));

	if ((a.getX() == b.getX() && a.getY() == b.getY())
		|| (b.getX() == c.getX() && b.getY() == c.getY())
		|| (c.getX() == a.getX() && c.getY() == a.getY()))
	{
		std::cerr << "Error : the points must be distinct" << std::endl;
		return (0);
	}
	if (std::abs(triangle_Area - subTriangles_Area) < 0.0001 )
	{
		if (isOnEdge(a, b, point) || isOnEdge(b, c, point) || isOnEdge(c, a, point))
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

bool	printRes(Point const & a, Point const & b, Point const & c, Point const & point)
{
	std::cout << std::endl;
	std::cout << "We are testing (" << point.getX() << "," << point.getY() << ") in triangle ("
			<< a.getX() << "," << a.getY() << "), ("
			<< b.getX() << "," << b.getY() << "), ("
			<< c.getX() << "," << c.getY() << ")" << std::endl;
	if (bsp(a, b, c, point) == true)
	{
		std::cout << "The point is inside the triangle" << std::endl;
		return (true);
	}
	else
	{
		std::cout << "The point is outside the triangle" << std::endl;
		return (false);
	}
}