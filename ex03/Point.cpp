/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:45:44 by Lmatkows          #+#    #+#             */
/*   Updated: 2025/05/13 08:24:58 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(void) : _x(0.0f), _y(0.0f) {}

Point::~Point(void){}

Point::Point(Point const & to_copy) : _x(to_copy._x), _y(to_copy._y) {}

Point & Point::operator=(const Point & other)
{
	(void)other;
	return (*this); // cet operateur ne peut pas copier les membres car _x et _y sont demandes constants et donc jamais modifiables apres l'instanciation... Erreur de la consigne??
}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

float Point::getX(void) const
{
	return (this->_x.toFloat());
}

float Point::getY(void) const
{
	return (this->_y.toFloat());
}

Fixed const & Point::getFixedX(void) const
{
	return (this->_x);
}

Fixed const & Point::getFixedY(void) const
{
	return (this->_y);
}
