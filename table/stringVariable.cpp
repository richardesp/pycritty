/*!
    \file    stringVariable.cpp
    \brief   Code of some functions of StringVariable class
    \author Ricardo Espantaleón Pérez
    \date    2022-05-08
    \version 0.0.1
*/

#include <iostream>

// Delete the comment if you want to use atof in the operator overload >>
// #include <stdlib.h>

#include "stringVariable.hpp"

/*
 Definitions of the read and write functions of the StringVariable class
*/

void lp::StringVariable::read()
{
    // Inherited attributes
    std::cout << "Name of the StringVariable: ";
    std::cin >> this->_name;

    std::cout << "Token of the StringVariable: ";
    std::cin >> this->_token;
    // The \n character is read
    std::cin.ignore();

    std::cout << "Type of the StringVariable: ";
    std::cin >> this->_type;
    // The \n character is read
    std::cin.ignore();

    // Own attribute
    std::cout << "Value of the StringVariable: ";
    std::cin >> this->_value;
    // The \n character is read
    std::cin.ignore();
}

void lp::StringVariable::write() const
{
    // Inherited methods
    std::cout << "Name:" << this->getName() << std::endl;
    std::cout << "Token:" << this->getToken() << std::endl;
    std::cout << "Type:" << this->getType() << std::endl;

    // Own method
    std::cout << "Value:" << this->getValue() << std::endl;
}

lp::StringVariable &lp::StringVariable::operator=(const lp::StringVariable &s)
{
    // Check that is not the current object
    if (this != &s)
    {
        // Inherited methods
        this->setName(s.getName());

        this->setToken(s.getToken());

        this->setType(s.getType());

        // Own method
        this->setValue(s.getValue());
    }

    // Return the current object
    return *this;
}

/*!
    \namespace lp
    \brief Name space for the subject Language Processors
*/
namespace lp
{

    std::istream &operator>>(std::istream &i, lp::StringVariable &s)
    {
        // Inherited attributes
        i >> s._name;

        i >> s._token;
        // The \n character is read
        i.ignore();

        i >> s._type;
        // The \n character is read
        i.ignore();

        i >> s._token;
        // The \n character is read
        i.ignore();

        ////////////////////////////////////

        // Own attribute

        i >> s._value;
        // The \n character is read
        i.ignore();

        ////////////////////////////////////

        /* Alternative way using an auxiliar string

          std::string auxiliar;

          std::getline(i,auxiliar);
          n._token = atof(auxiliar.c_str());

          std::getline(i,auxiliar);
          n._type = atof(auxiliar.c_str());

          std::getline(i,auxiliar);
          n._value = atof(auxiliar.c_str());

        */

        // The input stream is returned
        return i;
    }

    std::ostream &operator<<(std::ostream &o, lp::StringVariable const &s)
    {
        // Inherited attributes
        o << s._name << std::endl;

        o << s._token << std::endl;

        o << s._type << std::endl;

        // Own attribute
        o << s._value << std::endl;

        // The output stream is returned
        return o;
    }

    // End of name space lp
}
