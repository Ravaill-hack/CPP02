/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:32:59 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/12 22:31:49 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	const Point A(0.0f, 1.0f);
	const Point B(-0.75f, -0.5f);
	const Point C(0.75f, -0.5f);
	const Point D(0.0f, -1.0f);
	const Point E(-0.75f, 0.5f);
	const Point F(0.75f, 0.5f);
	const Point G(0, 0);
	const Point H(0, 1);
	const Point I(1, 0);
	const Point J(0.25f, 0.25f);

	printRes(A, B, C, D);
	printRes(G, H, I, J);
	printRes(G, H, I, G);
	printRes(G, H, I, H);
	printRes(G, H, I, I);
	return (0);
}
