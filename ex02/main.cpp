/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:32:59 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/12 20:38:52 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{

////////////////////
//  SUBJECT MAIN  //
////////////////////

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

////////////////////
//   EXTRA MAIN   //
////////////////////

	Fixed		c(10.5f);
	Fixed		d(2.25f);
    const Fixed e(42.42f);
    const Fixed f(24.24f);

	std::cout << std::endl;
	std::cout << "--- Own Tests ---" << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "const e: " << e.toFloat() << ", const f: " << f.toFloat() << std::endl;
	std::cout << std::endl;
	std::cout << "--- Arithmetic Operators ---" << std::endl;
	std::cout << "c + d: " << (c + d) << std::endl;
	std::cout << "c - d: " << (c - d) << std::endl;
	std::cout << "c * d: " << (c * d) << std::endl;
	std::cout << "c / d: " << (c / d) << std::endl;
	std::cout << std::endl;
    std::cout << "--- Comparison Operators ---" << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;
	std::cout << std::endl;
	std::cout << "--- Min/Max ---" << std::endl;
    std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
    std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
    std::cout << "const min(e, f): " << Fixed::min(e, f) << std::endl;
    std::cout << "const max(e, f): " << Fixed::max(e, f) << std::endl;
	return (0);
}
