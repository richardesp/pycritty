/*!
    \file    arrayVariable.hpp
    \brief   Declaration of ArrayVariable class
    \author  Ricardo Espantaleón Pérez
    \date    2022-05-18
    \version 0.0.7
*/

#ifndef _ARRAYVARIABLE_HPP_
#define _ARRAYVARIABLE_HPP_

#include <string>
#include <iostream>
#include <vector>

#include "variable.hpp"

/*!
    \namespace lp
    \brief Name space for the subject Language Processors
*/
namespace lp
{

    /*!
        \enum DataType
        \brief Enum for the array item's classes
    */
    enum DataType
    {
        ELEMENT_VARIABLE_TYPE_NUMBER, //!< Type for number
        ELEMENT_VARIABLE_TYPE_STRING, //!< Type for string
        ELEMENT_VARIABLE_TYPE_BOOLEAN //!< Type for bool
    };

    /*!
      \class ArrayVariable
      \brief Definition of atributes and methods of ArrayVariable class
      \note  ArrayVariable Class publicly inherits from Variable class
    */
    class ArrayVariable : public lp::Variable
    {
        /*!
        \name Private atributes of ArrayVariable class
        */
    private:
        std::vector<std::string> _items; //!< \brief Vector of the ArrayVariable
        std::vector<DataType> _types;    //!< \brief Type of the ArrayVariable
                                         /*!
                                         \name Public methods of ArrayVariable class
                                         */
    public:
        /*!
            \name Constructors
        */

        /*!
            \brief Constructor with arguments with default values
            \note  Inline function that uses Variable's constructor as members initializer
            \param name: name of the ArrayVariable
            \param token: token of the ArrayVariable
            \param type: type of the ArrayVariable
            \param size: size_t value of the ArrayVariable
            \pre   None
            \post  A new ArrayVariable is created with the values of the parameters
            \sa   setName, setValue
        */
        ArrayVariable(std::string name = "", int token = 0, int type = 0, size_t size = 0) : Variable(name, token, type)
        {
            _items = std::vector<std::string>(size);
            _types = std::vector<DataType>(size);

            for (size_t index = 0; index < size; index++)
            {
                _items[index] = "0";
                _types[index] = ELEMENT_VARIABLE_TYPE_NUMBER;
            }
        }

        /*!
            \brief Copy constructor
            \note  Inline function
            \param s: object of ArrayVariable class
            \pre   None
            \post  A new ArrayVariable is created with the values of an existent ArrayVariable
            \sa    setName, setValue
        */
        ArrayVariable(const ArrayVariable &s)
        {
            // Inherited methods
            this->setName(s.getName());

            this->setToken(s.getToken());

            this->setType(s.getType());

            // Own method
            this->setItems(s.getItems());
        }

        /*!
            \name Observer
        */

        /*!
            \brief  Public method that returns the value of the ArrayVariable
            \note   Función inline
            \pre    None
            \post   None
            \return Value of the ArrayVariable
            \sa		getValue
        */
        inline std::vector<std::string> getItems() const
        {
            return this->_items;
        }

        /*!
            \brief  Public method that returns the types of the ArrayVariable
            \note   Función inline
            \pre    None
            \post   None
            \return Types of the ArrayVariable
            \sa		getTypes
        */

        inline std::vector<DataType> getTypes() const
        {
            return this->_types;
        }

        /*!
            \name Modifier
        */

        /*!
            \brief   This functions modifies the value of the ArrayVariable
            \note    Inline function
            \param   items: new value of the ArrayVariable
            \pre     None
            \post    The value of the ArrayVariable is equal to the parameter
            \return  void
            \sa 	 setValue
        */
        inline void setItems(std::vector<std::string> items)
        {
            this->_items = items;
        }

        /*!
            \brief   This functions modifies the types of the ArrayVariable
            \note    Inline function
            \param   types: new types of the ArrayVariable types
            \pre     None
            \post    The value of the ArrayVariable is equal to the parameter
            \return  void
            \sa 	 setValue
        */
        inline void setTypes(std::vector<DataType> types)
        {
            this->_types = types;
        }

        /*!
            \brief   This functions modifies the current size of the ArrayVariable
            \note    Inline function
            \param   size: new size of the ArrayVariable
            \pre     None
            \post    The value of the ArrayVariable is equal to the parameter
            \return  void
            \sa 	 setValue
        */
        inline void setSize(size_t size)
        {
            size_t oldSize = this->_items.size();

            this->_items.resize(size);
            this->_types.resize(size);

            if (size > oldSize)
            {
                for (size_t index = oldSize; index < size; index++)
                {
                    this->_items[index] = "0";
                    this->_types[index] = ELEMENT_VARIABLE_TYPE_NUMBER;
                }
            }
        }

        /*!
            \brief   This functions modifies the value of a specific index in the ArrayVariable
            \note    Inline function
            \param 	 index: index position from the value to change
            \param   value: new value of the ArrayVariable
            \pre     None
            \post    The value of the ArrayVariable is equal to the parameter
            \return  void
            \sa 	 setValue
        */
        inline void setItemByIndex(size_t index, std::string value)
        {
            this->_items[index] = value;
        }

        /*!
            \brief   This functions modifies the types of a specific index of the ArrayVariable
            \note    Inline function
            \param   index: index position from the value to change
            \param   type: new type of the ArrayVariable
            \pre     None
            \post    The value of the ArrayVariable is equal to the parameter
            \return  void
            \sa 	 setValue
        */
        inline void setTypeByIndex(size_t index, lp::DataType type)
        {
            this->_types[index] = type;
        }

        /*!
            \name I/O Functions
        */

        /*!
            \brief Read a ArrayVariable
            \pre   None
            \post  The atributes of the ArrayVariable are modified with the read values
            \sa    write
        */
        void read();

        /*!
            \brief Write a ArrayVariable
            \pre   None
            \post  None
            \sa    read
        */
        void write() const;

        /*!
            \name Operators
        */

        /*!
            \brief  Assignment Operator
            \param  s: objectoof ArrayVariable class
            \post   The atributes of this object are equal to the atributes of the parameter
            \return Reference to this object
        */
        ArrayVariable &operator=(const ArrayVariable &s);

        //! \name Friend functions
        /*!
            \brief  Insertion operator
            \param  i: input stream
            \param  s: object of ArrayVariable class
            \pre    nome
            \post   The atributes of the ArrayVariable are modified with the inserted values from the input stream
            \return The input stream
        */
        friend std::istream &operator>>(std::istream &i, ArrayVariable &s);

        /*!
            \brief  Extraction operator
            \param  o: output stream
            \param  s: object of ArrayVariable class
            \pre    nome
            \post   The atributes of the ArrayVariable are written in the output stream
            \return The output stream
        */
        friend std::ostream &operator<<(std::ostream &o, ArrayVariable const &s);

        // End of NumericVariable class
    };

    // End of name space lp
}

// End of _NUMERICVARIABLE_HPP_
#endif
