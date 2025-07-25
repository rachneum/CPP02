#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    //this est un pointeur automatique que cpp me donne toujours dans toutes mes fonnctions membres non statiques.
    *this = other;//J'appelle l'opérateur =.
}

Fixed &Fixed::operator=(const Fixed &rhs)
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
    std::cout << "getRawBits member function called" << std::endl;
    return (_value);
}

void Fixed::setRawBits( int const raw )
{
    _value = raw;
}
