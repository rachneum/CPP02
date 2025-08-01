#ifndef  FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class   Fixed
{
    private:
        int                 _value;
        static const int    _fractionalBits = 8;
    public:
        Fixed();
        /*Nouveaux constructeurs*/
        Fixed(const int n);
        Fixed(const float f);

        Fixed(const Fixed& other);
        Fixed& operator=( const Fixed& rhs );
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif