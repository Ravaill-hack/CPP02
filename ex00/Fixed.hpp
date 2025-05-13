
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iomanip>
# include <iostream>
# include <string>

class Fixed
{
	private:
		int			_raw;
		static int	_nb_bits_fract;

	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed &operator=(const Fixed& other);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);

};

#endif