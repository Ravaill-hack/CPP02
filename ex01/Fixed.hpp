
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int			_raw;
		static int	_nb_bits_fract;

	public:
		Fixed();
		Fixed(Fixed const & other);
		~Fixed();
		
		Fixed & operator=(const Fixed& other);

		Fixed(const int i);
		Fixed(const float f);

		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;

};

std::ostream & operator<<(std::ostream & os, Fixed const & nb);

#endif