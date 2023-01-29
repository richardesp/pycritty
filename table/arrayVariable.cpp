/*!
    \file    arrayVariable.cpp
    \brief   Code of some functions of ArrayVariable class
    \author Ricardo Espantaleón Pérez
    \date    2022-05-08
    \version 0.0.1
*/

#include <iostream>

// Delete the comment if you want to use atof in the operator overload >>
// #include <stdlib.h>

#include "arrayVariable.hpp"

/*
 Definitions of the read and write functions of the ArrayVariable class
*/

void lp::ArrayVariable::read()
{
    /*
      // Inherited attributes
       std::cout << "Name of the ArrayVariable: ";
       std::cin >> this->_name;

       std::cout << "Token of the ArrayVariable: ";
       std::cin >> this->_token;
       // The \n character is read
       std::cin.ignore();

       std::cout << "Type of the ArrayVariable: ";
       std::cin >> this->_type;
       // The \n character is read
       std::cin.ignore();


       // Own attribute
       std::cout << "Value of the ArrayVariable: ";
       std::cin >> this->_items;
       // The \n character is read
       std::cin.ignore();
       */
}

void lp::ArrayVariable::write() const
{
    /*
    // Inherited methods
    std::cout << "Name:" << this->getName() << std::endl;
    std::cout << "Token:" << this->getToken() << std::endl;
    std::cout << "Type:" << this->getType() << std::endl;

    // Own method
    std::cout << "Value:" << this->getValue() << std::endl;
    */
}

lp::ArrayVariable &lp::ArrayVariable::operator=(const lp::ArrayVariable &s)
{

    // Check that is not the current object
    if (this != &s)
    {
        // Inherited methods
        this->setName(s.getName());

        this->setToken(s.getToken());

        this->setType(s.getType());

        // Own method
        this->setItems(s.getItems());

        // Own method
        this->setType(s.getType());
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

    std::istream &operator>>(std::istream &i, lp::ArrayVariable &s)
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
        std::string item;

        i >> item;
        s._items.push_back(item);

        // Own attribute
        int type;

        i >> type;

        // s._type.push_back(lp::DataType.ELEMENT_VARIABLE_TYPE_STRING);

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

        // The input stream is returned

        */
        return i;
    }

    std::ostream &operator<<(std::ostream &o, lp::ArrayVariable const &s)
    {
        // Inherited attributes
        o << s._name << std::endl;

        o << s._token << std::endl;

        o << s._type << std::endl;

        // Own attribute
        std::vector<std::string> items = s.getItems();

        for (size_t index = 0; index < items.size(); ++index)
        {
            o << items[index] << " ";
        }

        o << std::endl;

        // The output stream is returned
        return o;
    }

    // End of name space lp
}
