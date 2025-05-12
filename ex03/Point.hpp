
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point(void);
		~Point(void);
		Point(Point const & to_copy);
		Point & operator=(const Point & other);

		Point(float const x, float const y);
		float	getX(void) const;
		float	getY(void) const;
};

float	triangleArea(Point const & a, Point const & b, Point const & c);
bool	bsp(Point const a, Point const b, Point const c, Point const point);
bool	printRes(Point const & a, Point const & b, Point const & c, Point const & point);

#endif