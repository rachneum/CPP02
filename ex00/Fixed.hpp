#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int             _value;
        static const    int _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();
        int     getRawBits( void ) const;//Retourne la valeur brute. Valeur brute = l'entier interne que la classe fixed utilise pour stocker un nombre fixe.
        void    setRawBits( int const raw );//Définit la valeur brute.
};

#endif
