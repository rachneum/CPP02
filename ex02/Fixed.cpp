#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        _value = rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return (_value);
}

void Fixed::setRawBits( int const raw )
{
    _value = raw;
}

float Fixed::toFloat() const
{
    return ((float)_value / (1 << _fractionalBits));
}

int Fixed::toInt() const
{
    return (_value >> _fractionalBits);
}

bool Fixed::operator>(const Fixed& rhs) const
{
    return (_value > rhs._value);
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return (_value < rhs._value);
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return (_value >= rhs._value);
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return (_value <= rhs._value);
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return (_value == rhs._value);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return (_value != rhs._value);
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed res;
    res.setRawBits(_value + rhs._value);
    return (res);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed res;
    res.setRawBits(_value - rhs._value);
    return (res);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed res;
    long result = (long)_value * (long)rhs._value;
    res.setRawBits(result >> _fractionalBits);//>>_fB pour revenir à la bonne échelle de nombre à virgule fixe, après avoir multiplié mes deux valeurs entières.
    return (res);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    if (rhs._value == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return (Fixed());
    }
    Fixed res;
    long result = ((long)_value << _fractionalBits) / rhs._value;//On multiplie seulement _value par 256 pour augmenter la précision du numérateur avant division entière.
    res.setRawBits(result);
    return (res);
}

Fixed& Fixed::operator++()
{
    _value += 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    _value += 1;
    return (tmp);
}

Fixed& Fixed::operator--()
{
    _value -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _value -= 1;
    return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)//Référence non const, je peux modifier a et b.
{
    return ((a < b) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)//Compare mes 2 objets et renvoie une référence au plus petit.
{//Si a strrictement plus petit que b, retourne a. Sinon retourne b.
    return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return ((a > b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return ((a > b) ? a : b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& f)//Surcharge <<.
{
    out << f.toFloat();
    return (out);
}
