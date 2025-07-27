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
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &rhs);//Opérateur d'affectation.
    ~Fixed();
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    //Comparaison
    bool    operator>(const Fixed &rhs) const;
    bool    operator<(const Fixed &rhs) const;
    bool    operator>=(const Fixed &rhs) const;
    bool    operator<=(const Fixed &rhs) const;
    bool    operator==(const Fixed &rhs) const;
    bool    operator!=(const Fixed &rhs) const;

    //Arithmétique
    Fixed   operator+(const Fixed &rhs) const;
    Fixed   operator-(const Fixed &rhs) const;
    Fixed   operator*(const Fixed &rhs) const;
    Fixed   operator/(const Fixed &rhs) const;

    //Incrémentation / Décrémentation
    Fixed   &operator++();//pré-incrément.
    Fixed   operator++(int);//post-incrément.
    Fixed   &operator--();//pré-décrément.
    Fixed   operator--(int);//post-décrément.

    //Fonctions statiques min / max.
    static          Fixed &min(Fixed &a, Fixed &b);
    static const    Fixed &min(const Fixed &a, const Fixed &b);
    static          Fixed &max(Fixed &a, Fixed &b);
    static const    Fixed &max(const Fixed &a, const Fixed &b);
};
//Surcharge de l'opérateur <<.
std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
