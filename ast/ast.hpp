/*!
    \file    ast.hpp
    \brief   Declaration of AST class
    \author
    \date    2018-12-13
    \version 1.0
*/

#ifndef _AST_HPP_
#define _AST_HPP_

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include <vector>
#include "../table/arrayVariable.hpp"

#define ERROR_BOUND 1.0e-6 //!< Error bound for the comparison of real numbers.

namespace lp
{

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    /*!
      \class   ExpNode
      \brief   Definition of atributes and methods of ExpNode class
      \warning Abstract class
    */
    class ExpNode
    {
    public:
        /*!
            \brief   Type of  the expression
            \warning Pure virtual function: must be redefined in the heir classes
            \return  int
            \sa		 print()
        */
        virtual int getType() = 0;

        /*!
            \brief   Print the expression
            \warning Pure virtual function: must be redefined in the heir classes
            \return  void
            \sa		 evaluate()
        */
        virtual void print() = 0;

        /*!
            \brief   Evaluate the expression as NUMBER
            \warning Virtual function: could be redefined in the heir classes
            \return  double
            \sa		 evaluateBool()
        */
        virtual double evaluateNumber()
        {
            return 0.0;
        }

        /*!
            \brief   Evaluate the expression as BOOL
            \warning Virtual function: could be redefined in the heir classes
            \return  bool
            \sa		 evaluateString()
        */
        virtual bool evaluateBool()
        {
            return false;
        }

        /*!
            \brief   Evaluate the expression as STRING
            \warning Virtual function: could be redefined in the heir classes
            \return  String
            \sa		 evaluateArray()
        */
        virtual std::string evaluateString() // NEW in v. 0.0.2
        {
            return "";
        }

        /*!
            \brief   Evaluate the expression as ARRAY (items)
            \warning Virtual function: could be redefined in the heir classes
            \return  std::vector<std::string>
            \sa		 evaluateTypes()
        */
        virtual std::vector<std::string> evaluateArray() // NEW in v. 0.0.8
        {
            return std::vector<std::string>();
        }

        /*!
            \brief   Evaluate the expression as ARRAY (types)
            \warning Virtual function: could be redefined in the heir classes
            \return  std::vector<lp::DataType>
            \sa		 evaluateSize()
        */
        virtual std::vector<lp::DataType> evaluateTypes() // NEW in v. 0.0.8
        {
            return std::vector<lp::DataType>();
        }

        /*!
            \brief   Evaluate the size of vector
            \warning Virtual function: could be redefined in the heir classes
            \return  size_t
            \sa		 evaluateArrayItem()
        */
        virtual size_t evaluateSize() // NEW in v. 0.0.8
        {
            return size_t(0);
        }

        /*!
            \brief   Evaluate an item of vector
            \warning Virtual function: could be redefined in the heir classes
            \return  std::pair<std::string, lp::DataType>
            \sa		 getType()
        */
        virtual std::pair<std::string, lp::DataType> evaluateArrayItem()
        {
            return std::pair<std::string, lp::DataType>("", lp::ELEMENT_VARIABLE_TYPE_STRING);
        }
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class VariableNode
      \brief Definition of atributes and methods of VariableNode class
      \note  VariableNode Class publicly inherits from ExpNode class
    */
    class VariableNode : public ExpNode
    {
    private:
        std::string _id; //!< Name of the VariableNode

    public:
        /*!
            \brief Constructor of VariableNode
            \param value: std::string
            \post  A new VariableNode is created with the name of the parameter
            \note  Inline function
        */
        VariableNode(std::string const &value)
        {
            this->_id = value;
        }

        /*!
            \brief   Type of the Variable
            \return  int
            \sa		 print
        */
        int getType();

        /*!
            \brief   Print the Variable
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the Variable as NUMBER
            \return  double
            \sa		 evaluateBool()
        */
        double evaluateNumber(); // NEW in v.0.0.2

        /*!
            \brief   Evaluate the Variable as BOOL
            \return  bool
            \sa		 evaluateString()
        */
        bool evaluateBool();

        /*!
            \brief   Evaluate the Variable as STRING
            \return  string
            \sa		 getType()
        */
        std::string evaluateString();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class ConstantNode
      \brief Definition of atributes and methods of ConstantNode class
      \note  ConstantNode Class publicly inherits from ExpNode class
    */
    class ConstantNode : public ExpNode
    {
    private:
        std::string _id; //!< Name of the ConstantNode

    public:
        /*!
            \brief Constructor of ConstantNode
            \param value: std::string
            \post  A new ConstantNode is created with the name of the parameter
        */
        ConstantNode(std::string value)
        {
            this->_id = value;
        }

        /*!
            \brief   Type of the Constant
            \return  int
            \sa		 print()
        */
        int getType();

        /*!
            \brief   Print the Constant
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the Constant as NUMBER
            \return  double
            \sa		 evaluateBool()
        */
        double evaluateNumber();

        /*!
            \brief   Evaluate the Constant as BOOL
            \return  bool
            \sa		 getType()
        */
        bool evaluateBool();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class BoolNode
      \brief Definition of atributes and methods of BoolNode class
      \note  BoolNode Class publicly inherits from ExpNode class
    */
    class BoolNode : public ExpNode
    {
    private:
        bool _bool; //!< \brief bool of the BoolNode

    public:
        /*!
            \brief Constructor of BoolNode
            \param value: bool
            \post  A new BoolNode is created with the value of the parameter
            \note  Inline function
        */
        BoolNode(bool value)
        {
            this->_bool = value;
        }

        /*!
        \brief   Get the type of the expression: BOOL
        \return  bool
        \sa		 print()
        */
        int getType();

        /*!
            \brief   Print the expression
            \return  void
            \sa		 evaluateBool()
        */
        void print();

        /*!
            \brief   Evaluate the expression
            \return  bool
            \sa		 getType()
        */
        bool evaluateBool();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class NumberNode
      \brief Definition of atributes and methods of NumberNode class
      \note  NumberNode Class publicly inherits from ExpNode class
    */
    class NumberNode : public ExpNode
    {
    private:
        double _number; //!< \brief number of the NumberNode

    public:
        /*!
            \brief Constructor of NumberNode
            \param value: double
            \post  A new NumberNode is created with the value of the parameter
            \note  Inline function
        */
        NumberNode(double value)
        {
            this->_number = value;
        }

        /*!
        \brief   Get the type of the expression: NUMBER
        \return  int
        \sa		 print()
        */
        int getType();

        /*!
            \brief   Print the expression
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the expression
            \return  double
            \sa		 getType()
        */
        double evaluateNumber();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class StringNode
      \brief Definition of atributes and methods of StringNode class
      \note  StringNode Class publicly inherits from ExpNode class
    */
    class StringNode : public ExpNode
    {
    protected:
        std::string _string; //!< \brief string of the StringNode

    public:
        /*!
            \brief Constructor of StringNode
            \param value: string
            \post  A new StringNode is created with the value of the parameter
            \note  Inline function
        */
        StringNode(std::string value)
        {
            this->_string = value;
        }

        /*!
        \brief   Get the type of the expression: STRING
        \return  int
        \sa		 print()
        */
        int getType();

        /*!
            \brief   Print the expression
            \return  void
            \sa		 evaluateString()
        */
        void print();

        /*!
            \brief   Evaluate the expression
            \return  String
            \sa		 getType()
        */
        std::string evaluateString();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   UnaryOperatorNode
      \brief   Definition of atributes and methods of UnaryOperatorNode class
      \note    UnaryOperatorNode Class publicly inherits from ExpNode class
      \warning Abstract class, because it does not redefine the print method of ExpNode
    */
    class UnaryOperatorNode : public ExpNode
    {
    protected:
        ExpNode *_exp; //!< Child expression

    public:
        /*!
            \brief Constructor of UnaryOperatorNode links the node to it child,
                   and stores the character representation of the operator.
            \param expression: pointer to ExpNode
            \post  A new OperatorNode is created with the parameters
            \note  Inline function
        */
        UnaryOperatorNode(ExpNode *expression)
        {
            this->_exp = expression;
        }

        /*!
        \brief   Get the type of the child expression
        \return  int
        \sa		 print
        */
        inline int getType()
        {
            return this->_exp->getType();
        }
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   NumericUnaryOperatorNode
      \brief   Definition of atributes and methods of NumericUnaryOperatorNode class
      \note    NumericUnaryOperatorNode Class publicly inherits from UnaryOperatorNode class
      \warning Abstract class, because it does not redefine the print method of ExpNode
    */
    class NumericUnaryOperatorNode : public UnaryOperatorNode
    {
    public:
        /*!
            \brief Constructor of NumericUnaryOperatorNode uses UnaryOperatorNode's constructor as member initializer
            \param expression: pointer to ExpNode
            \post  A new NumericUnaryOperatorNode is created with the parameters
            \note  Inline function
        */
        NumericUnaryOperatorNode(ExpNode *expression) : UnaryOperatorNode(expression)
        {
            // Empty
        }

        /*!
        \brief   Get the type of the child expression
        \return  int
        \sa		 print
        */
        int getType();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    /*!
      \class   OperatorAssignmentNode
      \brief   Definition of atributes and methods of OperatorAssignmentNode class
      \warning Abstract class
    */
    class OperatorAssignmentNode
    {
    protected:
        std::string _id; //!< Identifier of the variable to assign

    public:
        /*!	\brief Constructor of the OperatorAssignmentNode
            \param id: ID from variable to assign
            \post  A new OperatorAssignmentNode is created with the parameter id
            \note  Inline function
        */
        OperatorAssignmentNode(std::string id)
        {
            this->_id = id;
        }

        /*!
            \brief   Print the expression
            \warning Pure virtual function: must be redefined in the heir classes
            \return  void
            \sa		 evaluateNumber()
        */
        virtual void print() = 0;

        /*!
            \brief   Evaluate the expression as NUMBER
            \warning Virtual function: could be redefined in the heir classes
            \return  double
            \sa		 print()
        */
        virtual double evaluateNumber()
        {
            return 0.0;
        }
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // NEW in v. 0.0.6

    /*!
      \class   IncrementNode
      \brief   Definition of atributes and methods of IncrementNode class
    */
    class IncrementNode : public OperatorAssignmentNode
    {
    private:
        int _inc; //!< Increment of the variable

    public:
        /*!
            \brief   Constructor of IncrementNode
            \param   id: std::string
            \param   inc: int
            \post  A new IncrementNode is created with the value of the parameters
            \return  void
        */
        IncrementNode(std::string const &id, int inc) : OperatorAssignmentNode(id)
        {
            this->_inc = inc;
        }

        /*!
            \brief   Constructor of IncrementNode
            \param   id: std::string
            \param	 exp: pointer to ExpNode
            \param   sign: sign of the increment
            \post  A new IncrementNode is created with the value of the parameters
            \return  void
        */
        IncrementNode(std::string const &id, ExpNode *exp, int sign) : OperatorAssignmentNode(id)
        {
            this->_inc = exp->evaluateNumber() * sign;
        }

        /*!
            \brief   Print the expression
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the expression as NUMBER
            \return  double
            \sa		 print()
        */
        double evaluateNumber();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   LogicalUnaryOperatorNode
      \brief   Definition of atributes and methods of LogicalUnaryOperatorNode class
      \note    LogicalUnaryOperatorNode Class publicly inherits from UnaryOperatorNode class
      \warning Abstract class, because it does not redefine the print method of ExpNode
    */
    class LogicalUnaryOperatorNode : public UnaryOperatorNode
    {
    public:
        /*!
            \brief Constructor of LogicalUnaryOperatorNode uses UnaryOperatorNode's constructor as member initializer
            \param expression: pointer to ExpNode
            \post  A new LogicalUnaryOperatorNode is created with the parameters
            \note  Inline function
        */
        LogicalUnaryOperatorNode(ExpNode *expression) : UnaryOperatorNode(expression)
        {
            // Empty
        }

        /*!
        \brief   Get the type of the child expression
        \return  int
        */
        int getType();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   UnaryMinusNode
      \brief   Definition of atributes and methods of UnaryMinusNode class
      \note    UnaryMinusNode Class publicly inherits from NumericUnaryOperatorNode class
    */
    class UnaryMinusNode : public NumericUnaryOperatorNode
    {

    public:
        /*!
            \brief Constructor of UnaryMinusNode
            \param expression: pointer to ExpNode
            \post  A new UnaryMinusNode is created with the parameter
            \note  Inline function: the NumericUnaryOperatorNode's constructor is used ad member initializer
        */
        UnaryMinusNode(ExpNode *expression) : NumericUnaryOperatorNode(expression)
        {
            // empty
        }

        /*!
            \brief   Print the expression
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the expression
            \return  double
            \sa		 print()
        */
        double evaluateNumber();
    };

    //////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////

    /*!
      \class   UnaryPlusNode
      \brief   Definition of atributes and methods of UnaryPlusNode class
      \note    UnaryPlusNode Class publicly inherits from NumericUnaryOperatorNode class
    */
    class UnaryPlusNode : public NumericUnaryOperatorNode
    {

    public:
        /*!
            \brief Constructor of UnaryPlusNode
            \param expression: pointer to ExpNode
            \post  A new UnaryPlusNode is created with the parameter
            \note  Inline function: the NumericUnaryOperatorNode's constructor is used as member initializer
        */
        UnaryPlusNode(ExpNode *expression) : NumericUnaryOperatorNode(expression)
        {
            // empty
        }

        /*!
            \brief   Print the expression
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the expression
            \return  double
            \sa		 print()
        */
        double evaluateNumber();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   OperatorNode
      \brief   Definition of atributes and methods of OperatorNode class
      \note    OperatorNode Class publicly inherits from ExpNode class
      \warning Abstract class, because it does not redefine the print and getType methods of ExpNode
    */
    class OperatorNode : public ExpNode
    {
    protected:
        ExpNode *_left;  //!< Left expression
        ExpNode *_right; //!< Right expression

    public:
        /*!
            \brief Constructor of OperatorNode links the node to its children,
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new OperatorNode is created with the parameters
        */
        OperatorNode(ExpNode *L, ExpNode *R)
        {
            this->_left = L;
            this->_right = R;
        }
    };

    //////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   NumericOperatorNode
      \brief   Definition of atributes and methods of NumericOperatorNode class
      \note    NumericOperatorNode Class publicly inherits from OperatorNode class
      \warning Abstract class, because it does not redefine the print method of ExpNode
    */
    class NumericOperatorNode : public OperatorNode
    {
    public:
        /*!
            \brief Constructor of NumericOperatorNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new NumericOperatorNode is created with the parameters
            \note  Inline function: the OperatorNode's constructor is used as member initializer
        */
        NumericOperatorNode(ExpNode *L, ExpNode *R) : OperatorNode(L, R)
        {
            //	Empty
        }

        /*!
        \brief   Get the type of the children expressions
        \return  int
        \sa		 print()
        */
        int getType();
    };

    //////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   RelationalOperatorNode
      \brief   Definition of atributes and methods of RelationalOperatorNode class
      \note    RelationalOperatorNode Class publicly inherits from OperatorNode class
      \warning Abstract class, because it does not redefine the print method of ExpNode
    */
    class RelationalOperatorNode : public OperatorNode
    {
    public:
        /*!
            \brief Constructor of RelationalOperatorNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new RelationalOperatorNode is created with the parameters
            \note  Inline function: the OperatorNode's constructor is used as member initializer

        */
        RelationalOperatorNode(ExpNode *L, ExpNode *R) : OperatorNode(L, R)
        {
            //	Empty
        }

        /*!
        \brief   Get the type of the children expressions
        \return  int
        */
        int getType();
    };

    //////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   LogicalOperatorNode
      \brief   Definition of atributes and methods of LogicalOperatorNode class
      \note    LogicalOperatorNode Class publicly inherits from OperatorNode class
      \warning Abstract class, because it does not redefine the print method of ExpNode
    */
    class LogicalOperatorNode : public OperatorNode
    {
    public:
        /*!
            \brief Constructor of LogicalOperatorNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new NumericOperatorNode is created with the parameters
            \note  Inline function: the OperatorNode constructor is used as member initializer
        */
        LogicalOperatorNode(ExpNode *L, ExpNode *R) : OperatorNode(L, R)
        {
            //	Empty
        }

        /*!
        \brief   Get the type of the children expressions
        \return  int
        */
        int getType();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   PlusNode
      \brief   Definition of atributes and methods of PlusNode class
      \note    PlusNode Class publicly inherits from NumericOperatorNode class
               and adds its own print and evaluate functions
    */
    class PlusNode : public NumericOperatorNode
    {
    public:
        /*!
            \brief Constructor of PlusNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new PlusNode is created with the parameter
            \note  Inline function: the NumericOperatorNode's constructor is used ad member initializer
        */
        PlusNode(ExpNode *L, ExpNode *R) : NumericOperatorNode(L, R)
        {
            // Empty
        }

        /*!
            \brief   Print the PlusNode
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the PlusNode
            \return  double
            \sa		 print()
        */
        double evaluateNumber();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   MinusNode
      \brief   Definition of atributes and methods of MinusNode class
      \note    MinusNode Class publicly inherits from NumericOperatorNode class
               and adds its own print and evaluate functions
    */
    class MinusNode : public NumericOperatorNode
    {
    public:
        /*!
            \brief Constructor of MinusNode uses NumericOperatorNode's constructor as members initializer
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new MinusNode is created with the parameter
        */
        MinusNode(ExpNode *L, ExpNode *R) : NumericOperatorNode(L, R)
        {
            // Empty
        }
        /*!
            \brief   Print the MinusNode
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the MinusNode
            \return  double
            \sa		 print
        */
        double evaluateNumber();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   MultiplicationNode
      \brief   Definition of atributes and methods of MultiplicationNode class
      \note    MultiplicationNode Class publicly inherits from NumericOperatorNode class
               and adds its own print and evaluate functions
    */
    class MultiplicationNode : public NumericOperatorNode
    {
    public:
        /*!
            \brief Constructor of MultiplicationNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new MultiplicationNode is created with the parameter
            \note  Inline function: the NumericOperatorNode's constructor is used ad member initializer
        */
        MultiplicationNode(ExpNode *L, ExpNode *R) : NumericOperatorNode(L, R)
        {
            // Empty
        }
        /*!
            \brief   Print the MultiplicationNode
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the MultiplicationNode
            \return  double
            \sa		 print()
        */
        double evaluateNumber();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   DivisionNode
      \brief   Definition of atributes and methods of DivisionNode class
      \note    DivisionNode Class publicly inherits from NumericOperatorNode class
               and adds its own print and evaluate functions
    */
    class DivisionNode : public NumericOperatorNode
    {
    public:
        /*!
            \brief Constructor of DivisionNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new DivisionNode is created with the parameter
            \note  Inline function: the NumericOperatorNode's constructor is used ad member initializer
        */
        DivisionNode(ExpNode *L, ExpNode *R) : NumericOperatorNode(L, R)
        {
            // Empty
        }
        /*!
            \brief   Print the DivisionNode
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the DivisionNode
            \return  double
            \sa		 print()
        */
        double evaluateNumber();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   ModuloNode
      \brief   Definition of atributes and methods of ModuloNode class
      \note    ModuloNode Class publicly inherits from NumericOperatorNode class
               and adds its own print and evaluate functions
    */
    class ModuloNode : public NumericOperatorNode
    {
    public:
        /*!
            \brief Constructor of ModuloNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new ModuloNode is created with the parameter
            \note  Inline function: the NumericOperatorNode's constructor is used ad member initializer
        */
        ModuloNode(ExpNode *L, ExpNode *R) : NumericOperatorNode(L, R)
        {
            // Empty
        }
        /*!
            \brief   Print the ModuloNode
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the ModuloNode
            \return  double
            \sa		 print()
        */
        double evaluateNumber();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   PowerNode
      \brief   Definition of atributes and methods of PowerNode class
      \note    PowerNode Class publicly inherits from NumericOperatorNode class
               and adds its own print and evaluate functions
    */
    class PowerNode : public NumericOperatorNode
    {
    public:
        /*!
            \brief Constructor of PowerNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new PowerNode is created with the parameter
            \note  Inline function: the NumericOperatorNode's constructor is used ad member initializer
        */
        PowerNode(ExpNode *L, ExpNode *R) : NumericOperatorNode(L, R)
        {
            // Empty
        }

        /*!
            \brief   Print the PowerNode
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the PowerNode
            \return  double
            \sa		 print()
        */
        double evaluateNumber();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   BuiltinFunctionNode
      \brief   Definition of atributes and methods of BuiltinFunctionNode class
      \note    BuiltinFunctionNode Class publicly inherits from ExpNode class
    */
    class BuiltinFunctionNode : public ExpNode
    {
    protected:
        std::string _id; //!< Name of the BuiltinFunctionNode

    public:
        /*!
            \brief Constructor of BuiltinFunctionNode
            \param id: string, name of the BuiltinFunction
            \post  A new BuiltinFunctionNode is created with the parameter
        */
        BuiltinFunctionNode(std::string id)
        {
            this->_id = id;
        }
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   BuiltinFunctionNode_0
      \brief   Definition of atributes and methods of BuiltinFunctionNode_0 class
      \note    BuiltinFunctionNode_0 Class publicly inherits from BuiltinFunctionNode class
               and adds its own print and evaluate functions
    */
    class BuiltinFunctionNode_0 : public BuiltinFunctionNode
    {
    public:
        /*!
            \brief Constructor of BuiltinFunctionNode_0
            \param id: string, name of the BuiltinFunction
            \post  A new BuiltinFunctionNode_2 is created with the parameter
            \note  Inline function: the BuiltinFunctionNode's constructor is used ad member initializer
        */
        BuiltinFunctionNode_0(std::string id) : BuiltinFunctionNode(id)
        {
            //
        }

        /*!
            \brief   Get the type of BuiltinFunctionNode_0:
            \return  int
            \sa		 print()
        */
        int getType();

        /*!
            \brief   Print the BuiltinFunctionNode_0
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the BuiltinFunctionNode_0
            \return  double
            \sa		 getType()
        */
        double evaluateNumber();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   BuiltinFunctionNode_1
      \brief   Definition of atributes and methods of BuiltinFunctionNode_1 class
      \note    BuiltinFunctionNode_1 Class publicly inherits from BuiltinFunctionNode class
               and adds its own print and evaluate functions
    */
    class BuiltinFunctionNode_1 : public BuiltinFunctionNode
    {
    private:
        ExpNode *_exp; //!< Argument of the BuiltinFunctionNode_1

    public:
        /*!
            \brief Constructor of BuiltinFunctionNode_1
            \param id: string, name of the BuiltinFunction
            \param expression: pointer to ExpNode, argument of the BuiltinFunctionNode_1
            \post  A new BuiltinFunctionNode_1 is created with the parameters
            \note  Inline function: the BuiltinFunctionNode's constructor is used ad member initializer
        */
        BuiltinFunctionNode_1(std::string id, ExpNode *expression) : BuiltinFunctionNode(id)
        {
            this->_exp = expression;
        }

        /*!
            \brief   Get the type of the BuiltinFunctionNode_1:
            \return  int
            \sa		 print()
        */
        int getType();

        /*!
            \brief   Print the BuiltinFunctionNode_1
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the BuiltinFunctionNode_1
            \return  double
            \sa		 getType()
        */
        double evaluateNumber();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   BuiltinFunctionNode_2
      \brief   Definition of atributes and methods of BuiltinFunctionNode_2 class
      \note    BuiltinFunctionNode_2 Class publicly inherits from BuiltinFunctionNode class
               and adds its own print and evaluate functions
    */
    class BuiltinFunctionNode_2 : public BuiltinFunctionNode
    {
    private:
        ExpNode *_exp1; //!< First argument of the BuiltinFunction_2
        ExpNode *_exp2; //!< Second argument of the BuiltinFunction_2

    public:
        /*!
            \brief Constructor of BuiltinFunctionNode_2
            \param id: string, name of the BuiltinFunction_2
            \param expression1: pointer to ExpNode, first argument of the BuiltinFunctionNode
            \param expression2: pointer to ExpNode, second argument of the BuiltinFunctionNode
            \post  A new BuiltinFunctionNode_2 is created with the parameters
            \note  Inline function: the BuiltinFunctionNode's constructor is used ad member initializer
        */
        BuiltinFunctionNode_2(std::string id, ExpNode *expression1, ExpNode *expression2) : BuiltinFunctionNode(id)
        {
            this->_exp1 = expression1;
            this->_exp2 = expression2;
        }

        /*!
        \brief   Get the type of the BuiltinFunctionNode_2:
        \return  int
        \sa		 print
        */
        int getType();

        /*!
            \brief   Print the BuiltinFunctionNode_2
            \return  void
            \sa		 evaluateNumber()
        */
        void print();

        /*!
            \brief   Evaluate the BuiltinFunctionNode_2
            \return  double
            \sa		 print()
        */
        double evaluateNumber();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   GreaterThanNode
      \brief   Definition of atributes and methods of GreaterThanNode class
      \note    GreaterThanNode Class publicly inherits from RelationalOperatorNode class
               and adds its own print and evaluate functions
    */
    class GreaterThanNode : public RelationalOperatorNode
    {
    public:
        /*!
            \brief Constructor of GreaterThanNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new GreaterThanNode is created with the parameter
            \note  Inline function: the RelationalOperatorNode's constructor is used ad member initializer
        */
        GreaterThanNode(ExpNode *L, ExpNode *R) : RelationalOperatorNode(L, R)
        {
            // Empty
        }

        /*!
            \brief   Print the GreaterThanNode
            \return  void
            \sa		 evaluateBool()
        */
        void print();

        /*!
            \brief   Evaluate the GreaterThanNode
            \return  bool
            \sa		 print()
        */
        bool evaluateBool();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   GreaterOrEqualNode
      \brief   Definition of atributes and methods of GreaterOrEqualNode class
      \note    GreaterOrEqualNode Class publicly inherits from RelationalOperatorNode class
               and adds its own print and evaluate functions
    */
    class GreaterOrEqualNode : public RelationalOperatorNode
    {
    public:
        /*!
            \brief Constructor of GreaterOrEqualNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new GreaterOrEqualNode is created with the parameter
            \note  Inline function: the RelationalOperatorNode's constructor is used ad member initializer
        */
        GreaterOrEqualNode(ExpNode *L, ExpNode *R) : RelationalOperatorNode(L, R)
        {
            // Empty
        }
        /*!
            \brief   Print the GreaterOrEqualNode
            \return  void
            \sa		 evaluateBool()
        */
        void print();

        /*!
            \brief   Evaluate the GreaterOrEqualNode
            \return  bool
            \sa		 print()
        */
        bool evaluateBool();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   LessThanNode
      \brief   Definition of atributes and methods of LessThanNode class
      \note    LessThanNode Class publicly inherits from RelationalOperatorNode class
               and adds its own print and evaluate functions
    */
    class LessThanNode : public RelationalOperatorNode
    {
    public:
        /*!
            \brief Constructor of LessThanNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new LessThanNode is created with the parameter
            \note  Inline function: the RelationalOperatorNode's constructor is used ad member initializer
        */
        LessThanNode(ExpNode *L, ExpNode *R) : RelationalOperatorNode(L, R)
        {
            // Empty
        }
        /*!
            \brief   Print the LessThanNode
            \return  void
            \sa		 evaluateBool()
        */
        void print();

        /*!
            \brief   Evaluate the LessThanNode
            \return  bool
            \sa		 print()
        */
        bool evaluateBool();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   LessOrEqualNode
      \brief   Definition of atributes and methods of LessOrEqualNode class
      \note    LessThanNode Class publicly inherits from RelationalOperatorNode class
               and adds its own print and evaluate functions
    */
    class LessOrEqualNode : public RelationalOperatorNode
    {
    public:
        /*!
            \brief Constructor of LessOrEqualNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new LessOrEqualNode is created with the parameter
            \note  Inline function: the RelationalOperatorNode's constructor is used ad member initializer
        */
        LessOrEqualNode(ExpNode *L, ExpNode *R) : RelationalOperatorNode(L, R)
        {
            // Empty
        }
        /*!
            \brief   Print the LessOrEqualNode
            \return  void
            \sa		 evaluateBool()
        */
        void print();

        /*!
            \brief   Evaluate the LessOrEqualNode
            \return  bool
            \sa		 print()
        */
        bool evaluateBool();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   EqualNode
      \brief   Definition of atributes and methods of EqualNode class
      \note    EqualNode Class publicly inherits from RelationalOperatorNode class
               and adds its own print and evaluate functions
    */
    class EqualNode : public RelationalOperatorNode
    {
    public:
        /*!
            \brief Constructor of EqualNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new EqualNode is created with the parameter
            \note  Inline function: the RelationalOperatorNode's constructor is used ad member initializer
        */
        EqualNode(ExpNode *L, ExpNode *R) : RelationalOperatorNode(L, R)
        {
            // Empty
        }
        /*!
            \brief   Print the EqualNode
            \return  void
            \sa		 evaluateBool()
        */
        void print();

        /*!
            \brief   Evaluate the EqualNode
            \return  bool
            \sa		 print()
        */
        bool evaluateBool();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   NotEqualNode
      \brief   Definition of atributes and methods of NotEqualNode class
      \note    NotEqualNode Class publicly inherits from RelationalOperatorNode class
               and adds its own print and evaluate functions
    */
    class NotEqualNode : public RelationalOperatorNode
    {
    public:
        /*!
            \brief Constructor of NotEqualNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new NotEqualNode is created with the parameter
            \note  Inline function: the RelationalOperatorNode's constructor is used ad member initializer
        */
        NotEqualNode(ExpNode *L, ExpNode *R) : RelationalOperatorNode(L, R)
        {
            // Empty
        }

        /*!
            \brief   Print the NotEqualNode
            \return  void
            \sa		 evaluateBool()
        */
        void print();

        /*!
            \brief   Evaluate the NotEqualNode
            \return  bool
            \sa		 print()
        */
        bool evaluateBool();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   AndNode
      \brief   Definition of atributes and methods of AndNode class
      \note    AndNode Class publicly inherits from LogicalOperatorNode class
               and adds its own print and evaluate functions
    */
    class AndNode : public LogicalOperatorNode
    {
    public:
        /*!
            \brief Constructor of AndNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new AndNode is created with the parameter
            \note  Inline function: the LogicalOperatorNode's constructor is used ad member initializer
        */
        AndNode(ExpNode *L, ExpNode *R) : LogicalOperatorNode(L, R)
        {
            // Empty
        }

        /*!
            \brief   Print the AndNode
            \return  void
            \sa		 evaluateBool()
        */
        void print();

        /*!
            \brief   Evaluate the AndNode
            \return  bool
            \sa		 print()
        */
        bool evaluateBool();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   OrNode
      \brief   Definition of atributes and methods of OrNode class
      \note    OrNode Class publicly inherits from LogicalOperatorNode class
               and adds its own print and evaluate functions
    */
    class OrNode : public LogicalOperatorNode
    {
    public:
        /*!
            \brief Constructor of AndNode
            \param L: pointer to ExpNode
            \param R: pointer to ExpNode
            \post  A new AndNode is created with the parameter
            \note  Inline function: the LogicalOperatorNode's constructor is used ad member initializer
        */
        OrNode(ExpNode *L, ExpNode *R) : LogicalOperatorNode(L, R)
        {
            // Empty
        }

        /*!
            \brief   Print the OrNode
            \return  void
            \sa		 evaluateBool()
        */
        void print();

        /*!
            \brief   Evaluate the OrNode
            \return  bool
            \sa		 print()
        */
        bool evaluateBool();
    };

    //////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////

    /*!
      \class   NotNode
      \brief   Definition of atributes and methods of UnaryPlusNode class
      \note    NotNode Class publicly inherits from LogicalUnaryOperatorNode class
    */
    class NotNode : public LogicalUnaryOperatorNode
    {

    public:
        /*!
            \brief Constructor of NotNode
            \param expression: pointer to ExpNode
            \post  A new NotNode is created with the parameter
            \note  Inline function: the LogicalOperatorNode's constructor is used ad member initializer

        */
        NotNode(ExpNode *expression) : LogicalUnaryOperatorNode(expression)
        {
            // empty
        }

        /*!
            \brief   Print the NotNode
            \return  void
            \sa		 evaluateBool()
        */
        void print();

        /*!
            \brief   Evaluate the NotNode
            \return  bool
            \sa		 print()
        */
        bool evaluateBool();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   Statement
      \brief   Definition of atributes and methods of Statement class
      \warning Abstract class
    */

    class Statement
    {
    public:
        /*!
            \brief   Print the Statement
            \note    Virtual function: can be redefined in the heir classes
            \return  void
            \sa		 evaluate()
        */

        virtual void print() {}

        /*!
            \brief   Evaluate the Statement
            \warning Pure virtual function: must be redefined in the heir classes
            \return  void
            \sa		 print()
        */
        virtual void evaluate() = 0;
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Modified in v.0.0.4

    /*!
      \class   BlockStmt
      \brief   Definition of atributes and methods of BlockStmt class
      \note    BlockStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions
    */
    class BlockStmt : public Statement
    {
    private:
        std::list<Statement *> *_stmts; //!< List of statements

    public:
        /*!
            \brief Constructor of  BlockStmt
            \param stmtList: list of Statement
            \post  A new BlockStmt is created with the parameters
        */
        BlockStmt(std::list<Statement *> *stmtList) : _stmts(stmtList)
        {
            // Empty
        }

        /*!
            \brief   Print the BlockStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the BlockStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   AssignmentStmt
      \brief   Definition of atributes and methods of AssignmentStmt class
      \note    AssignmentStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions
    */
    class AssignmentStmt : public Statement
    {
    public:
        std::string _id; //!< Name of the variable of the assignment statement
        ExpNode *_exp;   //!< Expresssion the assignment statement

        AssignmentStmt *_asgn; //!< Pointer to Allow multiple assigments

    public:
        /*!
            \brief Constructor of AssignmentStmt
            \param id: string, variable of the AssignmentStmt
            \param expression: pointer to ExpNode
            \post  A new AssignmentStmt is created with the parameters
        */
        AssignmentStmt(std::string id, ExpNode *expression) : _id(id), _exp(expression)
        {
            this->_asgn = NULL;
        }

        /*!
            \brief Constructor of AssignmentStmt
            \param id: string, variable of the AssignmentStmt
            \param asgn: pointer to AssignmentStmt
            \post  A new AssignmentStmt is created with the parameters
        */

        AssignmentStmt(std::string id, AssignmentStmt *asgn) : _id(id), _asgn(asgn)
        {
            this->_exp = NULL;
        }

        /*!
            \brief   Print the AssignmentStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the AssignmentStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   PrintStmt
      \brief   Definition of atributes and methods of PrintStmt class
      \note    PrintStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions
      \warning  In this class, print and evaluate functions have the same meaning.
    */
    class PrintStmt : public Statement
    {
    private:
        ExpNode *_exp; //!< Expresssion the print statement

    public:
        /*!
            \brief Constructor of PrintStmt
            \param expression: pointer to ExpNode
            \post  A new PrintStmt is created with the parameter
        */
        PrintStmt(ExpNode *expression)
        {
            this->_exp = expression;
        }

        /*!
            \brief   Print the PrintStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the PrintStmt
            \return  double
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   PrintStringStmt
      \brief   Definition of atributes and methods of PrintStringStmt class
      \note    PrintStringStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions
      \warning  In this class, print and evaluate functions have the same meaning.
    */
    class PrintStringStmt : public Statement // NEW in v.0.0.2
    {
    private:
        ExpNode *_exp; //!< Expresssion the print statement

    public:
        /*!
            \brief Constructor of PrintStringStmt
            \param expression: pointer to ExpNode
            \post  A new PrintStringStmt is created with the parameter
        */
        PrintStringStmt(ExpNode *expression)
        {
            this->_exp = expression;
        }

        /*!
            \brief   Print the PrintStringStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the PrintStringStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   PrintArrayStmt
      \brief   Definition of atributes and methods of PrintArrayStmt class
      \note    PrintArrayStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions
      \warning  In this class, print and evaluate functions have the same meaning.
    */
    class PrintArrayStmt : public Statement // NEW in v.0.0.2
    {
    private:
        std::string _id; //!< String of the print statement

    public:
        /*!
            \brief Constructor of PrintArrayStmt
            \param id: String of the print statement
            \post  A new PrintArrayStmt is created with the parameter
        */
        PrintArrayStmt(std::string id)
        {
            this->_id = id;
        }

        /*!
            \brief   Print the PrintArrayStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the PrintStringStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   ReadStmt
      \brief   Definition of atributes and methods of ReadStmt class
      \note    ReadStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions
    */
    class ReadStmt : public Statement
    {
    private:
        std::string _id; //!< Name of variable of the ReadStmt

    public:
        /*!
            \brief Constructor of ReadStmt
            \param id: string, name of the variable of the ReadStmt
            \post  A new ReadStmt is created with the parameter
        */
        ReadStmt(std::string id)
        {
            this->_id = id;
        }

        /*!
            \brief   Print the ReadStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the ReadStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   ReadStringStmt
      \brief   Definition of atributes and methods of ReadStringStmt class (for string variables)
      \note    ReadStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions for strings values
    */
    class ReadStringStmt : public Statement
    {
    private:
        std::string _id; //!< Name of the variable of the ReadStmt

    public:
        /*!
            \brief Constructor of ReadStmt
            \param id: string, name of the variable of the ReadStmt
            \post  A new ReadStmt is created with the parameter
        */
        ReadStringStmt(std::string id)
        {
            this->_id = id;
        }

        /*!
            \brief   Print the ReadStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the ReadStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   EmptyStmt
      \brief   Definition of atributes and methods of EmptyStmt class
      \note    EmptyStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions
    */
    class EmptyStmt : public Statement
    {
        // No attributes

    public:
        /*!
            \brief Constructor of EmptyStmt
            \post  A new EmptyStmt is created
        */
        EmptyStmt()
        {
            // Empty
        }

        /*!
            \brief   Print the EmptyStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the EmptyStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // NEW in example 17

    /*!
      \class   IfStmt
      \brief   Definition of atributes and methods of IfStmt class
      \note    IfStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions
    */
    class IfStmt : public Statement
    {
    private:
        ExpNode *_cond;     //!< Condition of the if statement
        BlockStmt *_block1; //!< Block of Statements of the consequent
        BlockStmt *_block2; //!< Block of Statements of the alternative

    public:
        /*!
            \brief Constructor of Single IfStmt (without alternative)
            \param condition: ExpNode of the condition
            \param stmtList1: Block of statements of the consequent
            \post  A new IfStmt is created with the parameters
        */
        IfStmt(ExpNode *condition, std::list<Statement *> *stmtList1)
        {
            this->_cond = condition;
            this->_block1 = new BlockStmt(stmtList1);
            this->_block2 = NULL;
        }

        /*!
            \brief Constructor of Compound IfStmt (with alternative)
            \param condition: ExpNode of the condition
            \param stmtList1: Block of Statements of the consequent
            \param stmtList2: Block of Statements of the alternative
            \post  A new IfStmt is created with the parameters
        */
        IfStmt(ExpNode *condition, std::list<Statement *> *stmtList1, std::list<Statement *> *stmtList2)
        {
            this->_cond = condition;
            this->_block1 = new BlockStmt(stmtList1);
            this->_block2 = new BlockStmt(stmtList2);
        }

        /*!
            \brief   Print the IfStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the IfStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Modified in v.0.0.3

    /*!
      \class   WhileStmt
      \brief   Definition of atributes and methods of WhileStmt class
      \note    WhileStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions
    */
    class WhileStmt : public Statement
    {
    private:
        ExpNode *_cond;    //!< Condition of the while statement
        BlockStmt *_block; //!< Statement of the body of the while loop

    public:
        /*!
            \brief Constructor of  WhileStmt
            \param condition: ExpNode of the condition
            \param stmtList: Statement of the body of the loop
            \post  A new WhileStmt is created with the parameters
        */
        WhileStmt(ExpNode *condition, std::list<Statement *> *stmtList)
        {
            this->_cond = condition;
            this->_block = new BlockStmt(stmtList);
        }

        /*!
            \brief   Print the WhileStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the WhileStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Modified in v.0.0.3

    /*!
      \class   RepeatStmt
      \brief   Definition of atributes and methods of RepeatStmt class
      \note    RepeatStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions
    */
    class RepeatStmt : public Statement
    {
    private:
        ExpNode *_cond;    //!< Condition of the while statement
        BlockStmt *_block; //!< Block of Statements of the body of the while loop

    public:
        /*!
            \brief Constructor of  RepeatStmt
            \param condition: ExpNode of the condition
            \param stmtList: Block of Statements of the body of the loop
            \post  A new RepeatStmt is created with the parameters
        */
        RepeatStmt(std::list<Statement *> *stmtList, ExpNode *condition)
        {
            this->_cond = condition;
            this->_block = new BlockStmt(stmtList);
        }

        /*!
            \brief   Print the RepeatStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the RepeatStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // NEW in v. 0.0.3

    /*!
      \class   ForStmt
      \brief   Definition of atributes and methods of ForStmt class
      \note    ForStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions
    */
    class ForStmt : public Statement
    {
    private:
        std::string _var;  //!< Name of the identifier
        ExpNode *_since;   //!< Since expresion of the for statement
        ExpNode *_until;   //!< Until expresion of the for statement
        BlockStmt *_block; //!< Block of Statements of the body of the for loop
        ExpNode *_step;    //!< step expresion of the for statement

    public:
        /*!
            \brief Constructor of  ForStmt
            \param var //!< ExpNode of the condition
            \param since //!< Expression that initializes the looping variable
            \param until //!< Condition to stop the loop
            \param stmtList //!< List of Statements of the body of the loop
            \param step //!< Step of the loop
            \post  A new ForStmt is created with the parameters
        */
        ForStmt(std::string var, ExpNode *since, ExpNode *until, std::list<Statement *> *stmtList, ExpNode *step = NULL)
        {
            this->_var = var;
            this->_since = since;
            this->_until = until;
            this->_block = new BlockStmt(stmtList);
            this->_step = step;
        }

        /*!
            \brief   Print the WhileStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the WhileStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   AST
      \brief   Definition of atributes and methods of AST class
    */
    class AST
    {
    private:
        std::list<Statement *> *stmts; //!< List of statements

    public:
        /*!
            \brief Constructor of PrintStmt
            \param stmtList: pointer to a list of pointers to Statement
            \post  A new PrintStmt is created with the parameter
        */
        AST(std::list<Statement *> *stmtList) : stmts(stmtList)
        {
            // Empty
        }

        /*!
            \brief   print the AST
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   evaluate the AST
            \return  double
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   TypeOfStmt
      \brief   Definition of atributes and methods of TypeOfStmt class
    */
    class TypeOfStmt : public Statement
    {
    private:
        ExpNode *_exp; //!< Expression to be evaluated

    public:
        /*!
            \brief Constructor of TypeOfStmt
            \param exp: Pointer to the expression of the TypeOfStmt
            \post  A new TypeOfStmt is created with the parameter
        */
        TypeOfStmt(ExpNode *exp)
        {
            this->_exp = exp;
        }

        /*!
            \brief   print the TypeOfStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   evaluate the TypeOfStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };


    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   StyleStmt
      \brief   Definition of atributes and methods of StyleStmt class
    */
    class StyleStmt : public Statement
    {
    private:
        ExpNode *_exp; //!< Expression to be evaluated

    public:
        /*!
            \brief Constructor of StyleStmt
            \param exp: Pointer to the expression of the StyleStmt
            \post  A new StyleStmt is created with the parameter
        */
        StyleStmt(ExpNode *exp)
        {
            this->_exp = exp;
        }

        /*!
            \brief   print the StyleStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   evaluate the StyleStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };


    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // NEW in v. 0.0.6

    /*!
      \class   ClearScreenStmt
      \brief   Definition of atributes and methods of ClearScreenStmt class
    */
    class ClearScreenStmt : public Statement
    {

    public:
        /*!
            \brief Constructor of ClearScreenStmt
            \post  A new ClearScreenStmt is created with the parameter
        */
        ClearScreenStmt()
        {
            // Empty
        }

        /*!
            \brief   print the ClearScreenStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   evaluate the ClearScreenStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // NEW in v. 0.0.6

    /*!
      \class   PlaceStmt
      \brief   Definition of atributes and methods of PlaceStmt class
    */
    class PlaceStmt : public Statement
    {
    private:
        ExpNode *_expX; //!< Expression of the x coordinate
        ExpNode *_expY; //!< Expression of the y coordinate

    public:
        /*!
            \brief Constructor of PlaceStmt
            \param expX: Pointer to the expression of the x coordinate
            \param expY: Pointer to the expression of the y coordinate
            \post  A new PlaceStmt is created with the parameter
        */
        PlaceStmt(ExpNode *expX, ExpNode *expY)
        {
            this->_expX = expX;
            this->_expY = expY;
        }

        /*!
            \brief   print the PlaceStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   evaluate the PlaceStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // New in v.0.0.5
    /*!
      \class   CaseNode
      \brief   Definition of atributes and methods of CaseNode class
    */

    class CaseNode
    {
    public:
        ExpNode *_exp; //!< Expression to evaluate in Case
        std::list<Statement *> *_stmtList; //!< std::list<Statement*> List of expresions with the statements of the case

    public:
        /*!
            \brief Constructor of CaseNode
            \param expCase: Pointer to the expression of the Case
            \param stmtList: Pointer to the list of statements of the Case
            \post  A new CaseNode is created with the parameter
        */
        CaseNode(ExpNode *expCase, std::list<Statement *> *stmtList) : _stmtList(stmtList)
        {
            this->_exp = expCase;
        }

        /*!
            \brief   Print the CaseNode
            \return  void
            \sa		 evaluate()
        */

        void print();

        /*!
            \brief   Evaluate the CaseNode
            \return  void
            \sa		 print()
        */
        void evaluate();

        /*!
            \brief   Returns the type of the CaseNode
            \return  int with the type
            \sa		 getExp()
        */
        int getType();

        /*!
            \brief   Get the expression of the CaseNode
            \return  ExpNode*
        */
        lp::ExpNode *getExp()
        {
            return this->_exp;
        }
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Modified in v.0.0.5

    /*!
      \class   BlockSwitchCaseNode
      \brief   Definition of atributes and methods of BlockSwitchCaseNode class
      \note    BlockSwitchCaseNode Class publicly inherits from Statement class
               and adds its own print and evaluate functions
    */
    class BlockSwitchCaseNode : public Statement
    {

    private:
        ExpNode *_exp;                 //!< Value of the switch to "switch between cases"
        std::list<CaseNode *> *_cases; //!< List of SwitchCases
        lp::CaseNode *_defaultCase;    //!< Default case

    public:
        /*!
            \brief Constructor of BlockSwitchCase
            \param initialValue: expresion with the name of the variable to be used in the switch
            \param switchCasesList: list of cases
            \param defaultCase: pointer to the default case
            \post  A new BlockSwitchCase is created with the parameters
        */
        BlockSwitchCaseNode(ExpNode *initialValue, std::list<lp::CaseNode *> *switchCasesList, lp::CaseNode *defaultCase = NULL) : _cases(switchCasesList)
        {
            this->_exp = initialValue;
            this->_defaultCase = defaultCase;
        }

        /*!
            \brief   Print the BlockSwitchCase
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the BlockSwitchCase
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class ArrayNode
      \brief Definition of atributes and methods of ArrayNode class
      \note  ArrayNode Class publicly inherits from ExpNode class
    */
    class ArrayNode : public ExpNode
    {
    protected:
        std::vector<std::string> _items;  //!< Vector of strings with the items of the array
        std::vector<lp::DataType> _types; //!< Vector with the types of the items of the array
        size_t _size;                     //!< Size of the array
        bool _sizeGivenAsString;          //!< Flag to know if the size is given as a string
        std::string _sizeString;          //!< String with the size of the array

    public:
        /*!
            \brief Constructor of ArrayNode
            \param size: Size of the array
            \post  A new ArrayNode is created with the size given. Both vectors are initialize with 0
            \note  Inline function
        */
        ArrayNode(double size)
        {
            this->_sizeGivenAsString = false;
            this->_size = long(size);
            this->_items = std::vector<std::string>(this->_size);
            this->_types = std::vector<lp::DataType>(this->_size);
        }

        /*!
            \brief Constructor of ArrayNode
            \param varSize: Size of the array saved in a variable
            \post  A new ArrayNode is created with the size given. Both vectors are initialize with 0
            \note  Inline function
        */
        ArrayNode(std::string varSize)
        {
            this->_sizeGivenAsString = true;
            this->_sizeString = varSize;
            this->_items = std::vector<std::string>();
            this->_types = std::vector<lp::DataType>();
        }

        /*!
            \brief Constructor of ArrayNode
            \param arrayNode: ArrayNode to be copied
            \post  A new ArrayNode is created with the array given.
            \note  Inline function
        */
        ArrayNode(const lp::ArrayNode *arrayNode)
        {
            this->_sizeGivenAsString = false;
            this->_size = long(arrayNode->_size);
            this->_items = std::vector<std::string>(this->_size);
            this->_types = std::vector<lp::DataType>(this->_size);
        }

        /*!
        \brief   Get the type of the ArrayNode:
        \return  int
        \sa		 print()
        */
        int getType();

        /*!
            \brief   Print the array
            \return  void
            \sa		 evaluateArray()
        */
        void print();

        /*!
            \brief   Evaluate the items array
            \return  std::vector<std::string> with the items array
            \sa		 evaluateTypes()
        */
        std::vector<std::string> evaluateArray();

        /*!
            \brief   Evaluate the types array
            \return  std::vector<lp::DataType> with the types array
            \sa		 getType()
        */
        std::vector<lp::DataType> evaluateTypes();

        /*!
            \brief   Gets the size of the Array
            \return  size_t Size of the array
            \sa		 print()
        */
        size_t evaluateSize();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class AccessArrayNode
      \brief Definition of atributes and methods of AccessArrayNode class
      \note  AccessArrayNode Class publicly inherits from ExpNode class
    */
    class AccessArrayNode : public ExpNode
    {
    protected:
        std::string _arrayId;       //!< \brief String with the name of the array
        long _indexItem;            //!< \brief long with the index of the array
        std::string _indexByString; //!< \brief string with the index of the array
        bool _givenIndexAsString;   //!< \brief bool that works as a flag

    public:
        /*!
            \brief Constructor of AccessArrayNumberNode
            \param arrayId: Name of the array to access
            \param indexItem: Index of the array to access
            \post  A new StringNode is created with the value of the parameter
            \note  Inline function
        */
        AccessArrayNode(std::string arrayId, long indexItem)
        {
            this->_arrayId = arrayId;
            this->_indexItem = indexItem;
            this->_givenIndexAsString = false;
        }

        /*!
            \brief Constructor of AccessArrayNumberNode
            \param arrayId: Name of the array to access
            \param indexItem: Index of the array to access given as string
            \post  A new StringNode is created with the value of the parameter
            \note  Inline function
        */
        AccessArrayNode(std::string arrayId, std::string indexItem)
        {
            this->_arrayId = arrayId;
            this->_indexByString = indexItem;
            this->_givenIndexAsString = true;
        }
        /*!
            \brief Get the item accessed
            \return The value of the Array at index given
            \sa getType()
        */
        double getValue();

        /*!
        \brief   Get the type of the expression: INT
        \return  int
        \sa		 print()
        */
        int getType();

        /*!
            \brief   Print the Element accessed
            \return  void
            \sa		 evaluateArrayItem()
        */
        void print();

        /*!
            \brief   Evaluate the item accessed
            \return  std::Pair with item and type
            \sa		 getValue()
        */

        std::pair<std::string, lp::DataType> evaluateArrayItem();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   AssignmentArrayStmt
      \brief   Definition of atributes and methods of AssignmentArrayStmt class
      \note    AssignmentArrayStmt Class publicly inherits from AssignmentStmt class
               and adds its own print and evaluate functions
    */
    class AssignmentArrayStmt : public AssignmentStmt
    {
    private:
        size_t _index;          //!< size_t with the index of the array to be accessed
        bool _isIndexAVariable; //!< bool to know if the index is a variable or a number
        std::string _indexVar;  //!< std::string With the var that will be evaluated to get the index

    public:
        /*!
            \brief Constructor of AssignmentArrayStmt
            \param id: string, variable of the AssignmentArrayStmt
            \param expression: pointer to ExpNode
            \param index: size_t, index of the array to be accessed
            \post  A new AssignmentArrayStmt is created with the parameters
        */
        AssignmentArrayStmt(std::string id, size_t index, ExpNode *expression) : AssignmentStmt(id, expression)
        {
            this->_index = index;
            this->_isIndexAVariable = false;
        }

        /*!
            \brief Constructor of AssignmentArrayStmt
            \param id: string, variable of the AssignmentArrayStmt
            \param expression: pointer to ExpNode
            \param index: string, variable that will be evaluated to be the index of the array to be accessed
            \post  A new AssignmentArrayStmt is created with the parameters
        */
        AssignmentArrayStmt(std::string id, std::string index, ExpNode *expression) : AssignmentStmt(id, expression)
        {
            this->_indexVar = index;
            this->_isIndexAVariable = true;
        }

        /*!
            \brief   Print the AssignmentArrayStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the AssignmentArrayStmt
            \return  void‘SwitchCase’ no se declaró en este ámbito
         std::list<SwitchCase *> *_switchCasesList; //!< List of SwitchCases
            \sa		 print()
        */
        void evaluate();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class StringOperatorNode
      \brief Definition of atributes and methods of StringOperatorNode class
      \note  StringOperatorNode Class publicly inherits from OperatorNode class
    */
    class StringOperatorNode : public OperatorNode
    {

    public:
        /*!
            \brief Constructor of StringOperatorNode
            \param string1: string with the first string
            \param string2: string with the second string
            \post  A new StringOperatorNode is created with the value of the parameter
            \note  Inline function
        */
        StringOperatorNode(ExpNode *string1, ExpNode *string2) : OperatorNode(string1, string2)
        {
        }

        /*!
        \brief   Get the type of the expression: STRING
        \return  int
        */
        int getType();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class ConcatenationNode
      \brief Definition of atributes and methods of ConcatenationNode class
      \note  ConcatenationNode Class publicly inherits from ExpNode class
    */
    class ConcatenationNode : public StringOperatorNode
    {

    public:
        /*!
            \brief Constructor of ConcatenationNode
            \param string1: string with the first string
            \param string2: string with the second string
            \post  A new ConcatenationNode is created with the value of the parameter
            \note  Inline function
        */
        ConcatenationNode(ExpNode *string1, ExpNode *string2) : StringOperatorNode(string1, string2)
        {
        }

        /*!
        \brief   Get the type of the expression: STRING
        \return  int
        \sa		 print()
        */
        int getType();

        /*!
            \brief   Print the expression
            \return  void
            \sa		 evaluateString()
        */
        void print();

        /*!
            \brief   Evaluate the expression
            \return  String
            \sa		 getType()
        */
        std::string evaluateString();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /*!
      \class   CreateArrayStmt
      \brief   Definition of atributes and methods of CreateArrayStmt class
      \note    CreateArrayStmt Class publicly inherits from Statement class
               and adds its own print and evaluate functions
    */
    class CreateArrayStmt : public Statement
    {
    public:
        std::string _id;       //!< Name of the variable of the assignment statement
        lp::ArrayNode *_array; //!< Expresssion the assignment statement

    public:
        /*!
            \brief Constructor of CreateArrayStmt
            \param id: string, variable of the CreateArrayStmt
            \param size: size of the array
            \post  A new CreateArrayStmt is created with the parameters
        */
        CreateArrayStmt(std::string id, size_t size) : _id(id)
        {
            this->_array = new lp::ArrayNode(size);
        }

        /*!
            \brief Constructor of CreateArrayStmt
            \param id: string, variable of the CreateArrayStmt
            \param size: size of the array
            \post  A new CreateArrayStmt is created with the parameters
        */
        CreateArrayStmt(std::string id, std::string size) : _id(id)
        {
            this->_array = new lp::ArrayNode(size);
        }

        /*!
            \brief   Print the CreateArrayStmt
            \return  void
            \sa		 evaluate()
        */
        void print();

        /*!
            \brief   Evaluate the CreateArrayStmt
            \return  void
            \sa		 print()
        */
        void evaluate();
    };

    // End of name space lp
}

// End of _AST_HPP_
#endif