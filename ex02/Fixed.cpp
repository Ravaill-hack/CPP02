/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:32:33 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/12 16:44:08 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::_nb_bits_fract = 8;

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(i << _nb_bits_fract);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(f * (1 << _nb_bits_fract)));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
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

bool	Fixed::operator>(const Fixed & other) const
{
	
}

bool	Fixed::operator<(const Fixed & other) const
{

}

bool	Fixed::operator>=(const Fixed & other) const
{

}

bool	Fixed::operator<=(const Fixed & other) const
{
	
}

bool	Fixed::operator==(const Fixed & other) const
{
	
}

bool	Fixed::operator!=(const Fixed & other) const
{
	
}

Fixed	Fixed::operator+(const Fixed & other) const
{
	
}

Fixed	Fixed::operator-(const Fixed & other) const
{
	
}

Fixed	Fixed::operator*(const Fixed & other) const
{
	
}

Fixed	Fixed::operator/(const Fixed & other) const
{
	
}

Fixed	& Fixed::operator++()
{
	
}
		
Fixed	Fixed::operator++(int)
{
	
}

Fixed	& Fixed::operator--()
{
	
}	

Fixed	Fixed::operator--(int)
{
	
}

static Fixed	min(Fixed & n1, Fixed & n2);

static Fixed	min(Fixed const & n1, Fixed const & n2);

static Fixed	max(Fixed & n1, Fixed & n2);

static Fixed	max(Fixed const & n1, Fixed const & n2);