
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iomanip>
# include <iostream>
# include <string>

class Fixed
{
	private:
		int			_nb_value;
		static int	_nb_bits_fract;

	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed &operator=(const Fixed& other);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;

};

std::ostream &operator<<(std::ostream &os, const Fixed& nb);

#endif