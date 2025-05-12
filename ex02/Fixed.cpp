/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:32:33 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/12 20:36:18 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::_nb_bits_fract = 8;

Fixed::Fixed() : _raw(0)
{
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int i)
{
	setRawBits(i << _nb_bits_fract);
}

Fixed::Fixed(const float f)
{
	setRawBits(roundf(f * (1 << _nb_bits_fract)));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		setRawBits(other.getRawBits());
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (_raw);
}

void	Fixed::setRawBits(int const raw)
{
	_raw = (int)raw;	
}

std::ostream &operator<<(std::ostream &os, Fixed const & nb)
{
	os << nb.toFloat();
	return (os);
}

float	Fixed::toFloat(void) const
{
	return (((float)_raw) / (1 << _nb_bits_fract));
}

int		Fixed::toInt(void) const
{
	return (_raw >> _nb_bits_fract);
}

//////////////////////////////////////////////////
//			OPERATEURS DE COMPARAISON			//
//////////////////////////////////////////////////

bool	Fixed::operator>(const Fixed & other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed & other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed & other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed & other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed & other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed & other) const
{
	return (this->toFloat() != other.toFloat());
}

//////////////////////////////////////////////////
//			OPERATEURS ARITHMETIQUES			//
//////////////////////////////////////////////////

Fixed	Fixed::operator+(const Fixed & other) const
{
	Fixed	sum;

	sum.setRawBits (this->getRawBits() + other.getRawBits());
	return (sum);
}

Fixed	Fixed::operator-(const Fixed & other) const
{
	Fixed	sub;

	sub.setRawBits (this->getRawBits() - other.getRawBits());
	return (sub);
}

Fixed	Fixed::operator*(const Fixed & other) const
{
	Fixed	prod;

	prod.setRawBits ((this->getRawBits() * other.getRawBits()) / (1 << _nb_bits_fract));
	return (prod);
}

Fixed	Fixed::operator/(const Fixed & other) const
{
	Fixed	div;

	div.setRawBits ((this->getRawBits() * (1 << _nb_bits_fract) / other.getRawBits()));
	return (div);	
}

//////////////////////////////////////////////////
//			OPERATEURS D'INCREMENTATION			//
//////////////////////////////////////////////////

Fixed	& Fixed::operator++()
{
	++this->_raw;
	return (*this);
}
		
Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	++this->_raw;
	return (tmp);
}

Fixed	& Fixed::operator--()
{
	--this->_raw;
	return (*this);
}	

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	--this->_raw;
	return (tmp);	
}

//////////////////////////////////////////////////
//					MIN ET MAX					//
//////////////////////////////////////////////////

Fixed	Fixed::min(Fixed & n1, Fixed & n2)
{
	if (n1.toFloat() <= n2.toFloat())
		return (n1);
	else
		return (n2);
}

Fixed	Fixed::min(Fixed const & n1, Fixed const & n2)
{
	if (n1.toFloat() <= n2.toFloat())
		return (n1);
	else
		return (n2);
}

Fixed	Fixed::max(Fixed & n1, Fixed & n2)
{
	if (n1.toFloat() >= n2.toFloat())
		return (n1);
	else
		return (n2);
}

Fixed	Fixed::max(Fixed const & n1, Fixed const & n2)
{
	if (n1.toFloat() >= n2.toFloat())
		return (n1);
	else
		return (n2);
}
