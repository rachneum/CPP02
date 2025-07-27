#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits;//Transforme int ex: 6 qui est en realite 6.0 en fixed-point.
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(f * (1 << _fractionalBits));//Me sert de 1 pour << car je ne peux pas le faire avec des float.
}   //roundf va arrondir mon resultat.

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;//Utilise l'opérateur =.
}

Fixed& Fixed::operator=( const Fixed& rhs )
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

float Fixed::toFloat() const
{
    return ((float)_value / (1 << _fractionalBits));
}

int Fixed::toInt() const
{
    return (_value >> _fractionalBits);
}
//Utilisation de toFloat() car _value est un int interne, donc illisible directement.
std::ostream& operator<<(std::ostream& out, const Fixed& f)//Surcharge de l'opérateur <<.
{
    out << f.toFloat();//Appelle la méthode pour afficher la vraie valeur flottante.
    return (out);//Permet l’enchaînement : std::cout << a << b << c;
}
