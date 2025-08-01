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
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& rhs);
    ~Fixed();
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    bool    operator>(const Fixed& rhs) const;
    bool    operator<(const Fixed& rhs) const;
    bool    operator>=(const Fixed& rhs) const;
    bool    operator<=(const Fixed& rhs) const;
    bool    operator==(const Fixed& rhs) const;
    bool    operator!=(const Fixed& rhs) const;//const car je ne vais pas modifier l'objet rhs.

    Fixed   operator+(const Fixed& rhs) const;
    Fixed   operator-(const Fixed& rhs) const;
    Fixed   operator*(const Fixed& rhs) const;
    Fixed   operator/(const Fixed& rhs) const;

    Fixed&  operator++();//pré-incrément.
    Fixed   operator++(int);//post-incrément.
    Fixed&  operator--();//pré-décrément.
    Fixed   operator--(int);//post-décrément.

    static          Fixed& min(Fixed& a, Fixed& b);
    static const    Fixed& min(const Fixed& a, const Fixed& b);
    static          Fixed& max(Fixed& a, Fixed& b);
    static const    Fixed& max(const Fixed& a, const Fixed& b);
};
std::ostream& operator<<(std::ostream &out, const Fixed &f);//Surcharge de l'opérateur <<.

#endif
