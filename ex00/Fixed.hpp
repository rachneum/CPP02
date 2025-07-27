#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    private:
        int _value;
        static const int _fractionalBits = 8;//Nombre de bits pour la partie fractionnaire.
    
    public:
        Fixed();//Constructeur par défaut.
        Fixed(const Fixed &other);//Constructeur de copie.
        Fixed &operator=(const Fixed &rhs);//Opérateur d’affectation. rhs = right-hand side, je défini comment l'objet à gauche du = recoit une copie de l'objet de droite.
        ~Fixed();
        int     getRawBits( void ) const;//Retourne la valeur brute. Valeur brute = l'entier interne que la classe fixed utilise pour stocker un nombre fixe.
        void    setRawBits( int const raw );//Définit la valeur brute.
    };

#endif
