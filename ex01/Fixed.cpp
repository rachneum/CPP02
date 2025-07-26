#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits;//Multiplie par 2^8.
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(f * (1 << _fractionalBits));// Multiplie par 256 et arrondit.
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;//Utilise l'opérateur =.
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=( const Fixed &rhs )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        _value = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
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

std::ostream &operator<<(std::ostream &out, const Fixed &f)// Surcharge de l'opérateur <<.
{
    out << f.toFloat();
    return out;
}
