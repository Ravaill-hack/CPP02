/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:45:04 by Lmatkows          #+#    #+#             */
/*   Updated: 2025/05/12 22:31:07 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

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
	return (std::abs(triangle_Area - subTriangles_Area) < 0.0001f);
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