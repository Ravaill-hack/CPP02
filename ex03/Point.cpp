/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:45:44 by Lmatkows          #+#    #+#             */
/*   Updated: 2025/05/12 21:21:12 by Lmatkows         ###   ########.fr       */
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
	return (*this); // on ne peut rien faire car _x et _y sont demandes constants et donc jamais modifiables apres l'instanciation... Erreur de la consigne??
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
