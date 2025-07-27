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
        Fixed(const int n);//Nouveau constructeur.
        Fixed(const float f);//Nouveau constructeur.
        Fixed(const Fixed &other);//Constructeur de copie.
        Fixed &operator=( const Fixed &rhs );//Opérateur d'affectation.
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);//Opérateur << à l’extérieur de la classe.

#endif