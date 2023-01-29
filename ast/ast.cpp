/*!
    \file    ast.cpp
    \brief   Code of funcitons of AST clas
    \author  Ricardo Espanteleón Pérez y Antonio Lujano Luna
    \date    2018-12-13
    \version 1.0
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>

// Para usar la funciones pow y std::abs
#include <cmath>

// AST hpp
#include "ast.hpp"

// Symbol Table hpp
#include "../table/table.hpp"

// warning
#include "../error/error.hpp"

// Macros for the screen
#include "../includes/macros.hpp"

//
#include "../table/numericVariable.hpp"
#include "../table/stringVariable.hpp"
#include "../table/logicalVariable.hpp"
#include "../table/arrayVariable.hpp"

#include "../table/numericConstant.hpp"
#include "../table/logicalConstant.hpp"

#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter1.hpp"
#include "../table/builtinParameter2.hpp"

#include "../parser/interpreter.tab.h"

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

extern lp::Table table; //!< Reference to the Table of Symbols

extern lp::AST *root; //!< Reference to the object at the base of the AST

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::VariableNode::getType()
{
    // Get the identifier in the table of symbols as Variable
    lp::Variable *var = (lp::Variable *)table.getSymbol(this->_id);

    // Return the type of the Variable
    return var->getType();
}

void lp::VariableNode::print()
{
    std::cout << "VariableNode: " << this->_id;
    std::cout << " (Type: " << this->getType() << ")" << std::endl;
}

double lp::VariableNode::evaluateNumber()
{
    double result = 0.0;

    if (this->getType() == NUMBER)
    {
        // Get the identifier in the table of symbols as NumericVariable
        lp::NumericVariable *var = (lp::NumericVariable *)table.getSymbol(this->_id);

        // Copy the value of the NumericVariable
        result = var->getValue();
    }
    else
    {
        warning("Runtime error in evaluateNumber(): the variable is not numeric",
                this->_id);
    }

    // Return the value of the NumericVariable
    return result;
}

bool lp::VariableNode::evaluateBool()
{
    bool result = false;

    if (this->getType() == BOOL)
    {
        // Get the identifier in the table of symbols as LogicalVariable
        lp::LogicalVariable *var = (lp::LogicalVariable *)table.getSymbol(this->_id);

        // Copy the value of the LogicalVariable
        result = var->getValue();
    }
    else
    {
        warning("Runtime error in evaluateBool(): the variable is not boolean",
                this->_id);
    }

    // Return the value of the LogicalVariable
    return result;
}

// Virtual function must be implemented
std::string lp::VariableNode::evaluateString() // NEW in v.0.0.2
{
    std::string result = "";

    if (this->getType() == STRING)
    {
        // Get the identifier in the table of symbols as StringVariable
        lp::StringVariable *var = (lp::StringVariable *)table.getSymbol(this->_id);

        // Copy the value of the StringVariable
        result = var->getValue();
    }
    else
    {
        warning("Runtime error in evaluateString(): the variable is not string",
                this->_id);
    }

    // Return the value of the StringlVariable
    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ConstantNode::print()
{
    std::cout << "ConstantNode: " << this->_id;
    std::cout << " (Type: " << this->getType() << ")" << std::endl;
}

int lp::ConstantNode::getType()
{
    // Get the identifier in the table of symbols as Constant
    lp::Constant *var = (lp::Constant *)table.getSymbol(this->_id);

    // Return the type of the Constant
    return var->getType();
}

double lp::ConstantNode::evaluateNumber()
{
    double result = 0.0;

    if (this->getType() == NUMBER)
    {
        // Get the identifier in the table of symbols as NumericConstant
        lp::NumericConstant *constant = (lp::NumericConstant *)table.getSymbol(this->_id);

        // Copy the value of the NumericConstant
        result = constant->getValue();
    }
    else
    {
        warning("Runtime error in evaluateNumber(): the constant is not numeric",
                this->_id);
    }

    // Return the value of the NumericVariable
    return result;
}

bool lp::ConstantNode::evaluateBool()
{
    bool result = false;

    if (this->getType() == BOOL)
    {
        // Get the identifier in the table of symbols as LogicalConstant
        lp::LogicalConstant *constant = (lp::LogicalConstant *)table.getSymbol(this->_id);

        // Copy the value of the LogicalConstant
        result = constant->getValue();
    }
    else
    {
        warning("Runtime error in evaluateBool(): the constant is not boolean",
                this->_id);
    }

    // Return the value of the LogicalVariable
    return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::NumberNode::getType()
{
    return NUMBER;
}

void lp::NumberNode::print()
{
    std::cout << "NumberNode: " << this->_number << std::endl;
}

double lp::NumberNode::evaluateNumber()
{
    return this->_number;
}

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BoolNode::getType()
{
    return BOOL;
}

void lp::BoolNode::print()
{
    std::cout << "BoolNode: " << this->_bool << std::endl;
}

bool lp::BoolNode::evaluateBool()
{
    return this->_bool;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::StringNode::getType()
{
    return STRING;
}

void lp::StringNode::print()
{
    std::cout << "StringNode: " << this->_string << std::endl;
}

std::string lp::StringNode::evaluateString()
{
    return this->_string;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::ConcatenationNode::getType()
{
    return STRING;
}

void lp::ConcatenationNode::print()
{
    std::cout << "StringNode:" << std::endl;
    this->_left->print();
    this->_right->print();
}

std::string lp::ConcatenationNode::evaluateString()
{
    std::string concatenatedString = "";
    if (this->getType() == STRING)
        concatenatedString = this->_left->evaluateString() + this->_right->evaluateString();
    else
        execerror("Runtime error, the expressions are not a string", "Inconpatible types", "Note: Use 2 strings to concatenate");

    return concatenatedString;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::NumericUnaryOperatorNode::getType()
{
    int result;

    if (this->_exp->getType() == NUMBER)
    {
        result = NUMBER;
    }
    else
    {
        warning("Runtime error: incompatible types for", "Numeric Unary Operator");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalUnaryOperatorNode::getType()
{
    int result;

    if (this->_exp->getType() == BOOL)
    {
        result = BOOL;
    }
    else
    {
        warning("Runtime error: incompatible types for", "Logical Unary Operator");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::NumericOperatorNode::getType()
{
    int result = 0;

    if ((this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
        result = NUMBER;
    else
        warning("Runtime error: incompatible types for", "Numeric Operator");

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::RelationalOperatorNode::getType()
{
    int result = 0;

    if ((this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
        result = BOOL;
    else if ((this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
        result = BOOL;
    else if ((this->_left->getType() == STRING) and (this->_right->getType() == STRING))
        result = BOOL;
    else
        warning("Runtime error: incompatible types for", "Relational Operator");

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalOperatorNode::getType()
{
    int result = 0;

    if ((this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
    {
        //
        result = BOOL;
    }
    else
        warning("Runtime error: incompatible types for", "Logical Operator");

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::UnaryMinusNode::print()
{
    std::cout << "UnaryMinusNode: -" << std::endl;
    std::cout << "\t";
    this->_exp->print();
}

double lp::UnaryMinusNode::evaluateNumber()
{
    double result = 0.0;

    // Ckeck the type of the expression
    if (this->getType() == NUMBER)
    {
        // Minus
        result = -this->_exp->evaluateNumber();
    }
    else
    {
        warning("Runtime error: the expressions are not numeric for ", "UnaryMinus");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::UnaryPlusNode::print()
{
    std::cout << "UnaryPlusNode: +" << std::endl;
    std::cout << "\t";
    this->_exp->print();
}

double lp::UnaryPlusNode::evaluateNumber()
{
    double result = 0.0;

    // Ckeck the type of the expression
    if (this->getType() == NUMBER)
    {
        result = this->_exp->evaluateNumber();
    }
    else
    {
        warning("Runtime error: the expressions are not numeric for ", "UnaryPlus");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PlusNode::print()
{
    std::cout << "PlusNode: +" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

double lp::PlusNode::evaluateNumber()
{
    double result = 0.0;

    // Ckeck the types of the expressions
    if (this->getType() == NUMBER)
    {
        result = this->_left->evaluateNumber() + this->_right->evaluateNumber();
    }
    else
    {
        warning("Runtime error: the expressions are not numeric for ", "Plus");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MinusNode::print()
{
    std::cout << "MinusNode: -" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

double lp::MinusNode::evaluateNumber()
{
    double result = 0.0;

    // Ckeck the types of the expressions
    if (this->getType() == NUMBER)
    {
        result = this->_left->evaluateNumber() - this->_right->evaluateNumber();
    }
    else
    {
        warning("Runtime error: the expressions are not numeric for ", "Minus");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::IncrementNode::print()
{
    std::cout << "IncrementNode: " << std::endl;
    std::cout << "\t";
    std::cout << "Increment: " << this->_inc << std::endl;
    std::cout << "\t";
    std::cout << "VariableNode: " << this->_id << std::endl;
}

double lp::IncrementNode::evaluateNumber()
{
    /* Get the identifier in the table of symbols as NumericVariable */
    lp::NumericVariable *n = (lp::NumericVariable *)table.getSymbol(this->_id);

    if (n->getType() != NUMBER)
        execerror("Runtime error: the identifier is not a numeric variable for ", "Increment", "Note: use a numeric value");

    /* Assignment the read value to the identifier */
    n->setValue(n->getValue() + this->_inc);

    return n->getValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MultiplicationNode::print()
{
    std::cout << "MultiplicationNode: *" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

double lp::MultiplicationNode::evaluateNumber()
{
    double result = 0.0;

    // Ckeck the types of the expressions
    if (this->getType() == NUMBER)
    {
        result = this->_left->evaluateNumber() * this->_right->evaluateNumber();
    }
    else
    {
        execerror("Runtime error: the expressions are not numeric for ", "Multiplication", "Note: use numeric values instead");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::DivisionNode::print()
{
    std::cout << "DivisionNode: /" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

double lp::DivisionNode::evaluateNumber()
{
    double result = 0.0;

    // Ckeck the types of the expressions
    if (this->getType() == NUMBER)
    {
        double leftNumber, rightNumber;

        leftNumber = this->_left->evaluateNumber();
        rightNumber = this->_right->evaluateNumber();

        // The divisor is not zero
        if (std::abs(rightNumber) > ERROR_BOUND)
        {
            result = (long)(leftNumber / rightNumber);
        }
        else
        {
            execerror("Runtime error", "Division by zero", "Note: Check the denominator beforehand");
        }
    }
    else
    {
        execerror("Runtime error: the expressions are not numeric for", "Division", "Note: use numeric values instead");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ModuloNode::print()
{
    std::cout << "ModuloNode: %" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

double lp::ModuloNode::evaluateNumber()
{
    double result = 0.0;

    // Ckeck the types of the expressions
    if (this->getType() == NUMBER)
    {
        double leftNumber, rightNumber;

        leftNumber = this->_left->evaluateNumber();
        rightNumber = this->_right->evaluateNumber();

        if (std::abs(rightNumber) > ERROR_BOUND)
            result = (int)leftNumber % (int)rightNumber;
        else
            warning("Runtime error", "Division by zero", "Note: Check the mod expression beforehand");
    }
    else
    {
        warning("Runtime error: the expressions are not numeric for", "Modulo");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PowerNode::print()
{
    std::cout << "PowerNode: ^" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

double lp::PowerNode::evaluateNumber()
{
    double result = 0.0;

    // Ckeck the types of the expressions
    if (this->getType() == NUMBER)
    {
        result = pow(this->_left->evaluateNumber(), this->_right->evaluateNumber());
    }
    else
    {
        warning("Runtime error: the expressions are not numeric for", "Power");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int lp::BuiltinFunctionNode_0::getType()
{
    return NUMBER;
}

void lp::BuiltinFunctionNode_0::print()
{
    std::cout << "BuiltinFunctionNode_0: " << std::endl;
    std::cout << "\t";
    std::cout << this->_id << std::endl;
}

double lp::BuiltinFunctionNode_0::evaluateNumber()
{
    // Get the identifier in the table of symbols as BuiltinParameter0
    lp::BuiltinParameter0 *f = (lp::BuiltinParameter0 *)table.getSymbol(this->_id);

    // Apply the function and copy the result
    return f->getFunction()();
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_1::getType()
{
    int result = 0;

    if (this->_exp->getType() == NUMBER)
        result = NUMBER;
    else
        warning("Runtime error: incompatible type for", "BuiltinFunctionNode_1");

    return result;
}

void lp::BuiltinFunctionNode_1::print()
{
    std::cout << "BuiltinFunctionNode_1: " << std::endl;
    std::cout << "\t";
    std::cout << this->_id << std::endl;
    std::cout << "\t";
    this->_exp->print();
    std::cout << std::endl;
}

double lp::BuiltinFunctionNode_1::evaluateNumber()
{
    double result = 0.0;

    // Ckeck the type of the expression
    if (this->getType() == NUMBER)
    {
        // Get the identifier in the table of symbols as BuiltinParameter1
        lp::BuiltinParameter1 *f = (lp::BuiltinParameter1 *)table.getSymbol(this->_id);

        // Apply the function to the parameter and copy the result
        result = f->getFunction()(this->_exp->evaluateNumber());
    }
    else
    {
        warning("Runtime error: incompatible type of parameter for ", this->_id);
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_2::getType()
{
    int result = 0;

    if (this->_exp1->getType() == this->_exp2->getType())
        result = this->_exp1->getType();
    else
        warning("Runtime error: incompatible types for", "BuiltinFunctionNode_2");

    return result;
}

void lp::BuiltinFunctionNode_2::print()
{
    std::cout << "BuiltinFunctionNode_2: " << std::endl;
    std::cout << "\t";
    std::cout << this->_id << std::endl;
    std::cout << "\t";
    this->_exp1->print();
    std::cout << "\t";
    this->_exp2->print();
    std::cout << std::endl;
}

double lp::BuiltinFunctionNode_2::evaluateNumber()
{
    double result = 0.0;

    // Ckeck the types of the expressions
    if (this->getType() == NUMBER)
    {
        // Get the identifier in the table of symbols as BuiltinParameter2
        lp::BuiltinParameter2 *f = (lp::BuiltinParameter2 *)table.getSymbol(this->_id);

        // Apply the function to the parameters and copy the result
        result = f->getFunction()(this->_exp1->evaluateNumber(), this->_exp2->evaluateNumber());
    }
    else
    {
        warning("Runtime error: incompatible types of parameters for ", this->_id);
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterThanNode::print()
{
    std::cout << "GreaterThanNode: >" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

bool lp::GreaterThanNode::evaluateBool()
{
    bool result = false;
    std::string leftString, rightString;

    if (this->getType() == BOOL)
    {
        switch (this->_left->getType())
        {
        case NUMBER:
            double leftNumber, rightNumber;
            leftNumber = this->_left->evaluateNumber();
            rightNumber = this->_right->evaluateNumber();

            result = (leftNumber > rightNumber);
            break;
        case STRING:
            leftString = this->_left->evaluateString();
            rightString = this->_right->evaluateString();

            result = (leftString > rightString);
            break;
        default:
            warning("Runtime error: incompatible types of parameters for ", "operator Less or equal than");
            break;
        }
    }
    else
    {
        warning("Runtime error: incompatible types of parameters for ", "operator Greater than");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterOrEqualNode::print()
{
    std::cout << "GreaterOrEqualNode: >= " << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

bool lp::GreaterOrEqualNode::evaluateBool()
{
    bool result = false;
    std::string leftString, rightString;

    if (this->getType() == BOOL)
    {
        switch (this->_left->getType())
        {
        case NUMBER:
            double leftNumber, rightNumber;
            leftNumber = this->_left->evaluateNumber();
            rightNumber = this->_right->evaluateNumber();

            result = (leftNumber >= rightNumber);
            break;
        case STRING:
            leftString = this->_left->evaluateString();
            rightString = this->_right->evaluateString();

            result = (leftString >= rightString);
            break;
        default:
            warning("Runtime error: incompatible types of parameters for ", "operator Less or equal than");
            break;
        }
    }
    else
    {
        warning("Runtime error: incompatible types of parameters for ", "operator Greater or equal than");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessThanNode::print()
{
    std::cout << "LessThanNode: <" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

bool lp::LessThanNode::evaluateBool()
{
    bool result = false;
    std::string leftString, rightString;

    if (this->getType() == BOOL)
    {
        switch (this->_left->getType())
        {
        case NUMBER:
            double leftNumber, rightNumber;
            leftNumber = this->_left->evaluateNumber();
            rightNumber = this->_right->evaluateNumber();

            result = (leftNumber < rightNumber);
            break;
        case STRING:
            leftString = this->_left->evaluateString();
            rightString = this->_right->evaluateString();

            result = (leftString < rightString);
            break;
        default:
            warning("Runtime error: incompatible types of parameters for ", "operator Less or equal than");
            break;
        }
    }
    else
    {
        warning("Runtime error: incompatible types of parameters for ", "operator Less than");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessOrEqualNode::print()
{
    std::cout << "LessOrEqualNode: <=" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

bool lp::LessOrEqualNode::evaluateBool()
{
    bool result = false;

    std::string leftString, rightString;

    if (this->getType() == BOOL)
    {
        switch (this->_left->getType())
        {
        case NUMBER:
            double leftNumber, rightNumber;
            leftNumber = this->_left->evaluateNumber();
            rightNumber = this->_right->evaluateNumber();

            result = (leftNumber <= rightNumber);
            break;
        case STRING:
            leftString = this->_left->evaluateString();
            rightString = this->_right->evaluateString();

            result = (leftString <= rightString);
            break;
        default:
            warning("Runtime error: incompatible types of parameters for ", "operator Less or equal than");
            break;
        }
    }
    else
    {
        warning("Runtime error: incompatible types of parameters for ", "operator Less or equal than");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EqualNode::print()
{
    std::cout << "EqualNode: ==" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

bool lp::EqualNode::evaluateBool()
{
    std::string leftString, rightString;
    bool result = false;

    if (this->getType() == BOOL)
    {
        switch (this->_left->getType())
        {
        case NUMBER:
            double leftNumber, rightNumber;
            leftNumber = this->_left->evaluateNumber();
            rightNumber = this->_right->evaluateNumber();

            // ERROR_BOUND to control the precision of real numbers
            result = (std::abs(leftNumber - rightNumber) < ERROR_BOUND);
            break;

        case BOOL:
            bool leftBoolean, rightBoolean;
            leftBoolean = this->_left->evaluateBool();
            rightBoolean = this->_right->evaluateBool();

            //
            result = (leftBoolean == rightBoolean);
            break;

        case STRING:
            leftString = this->_left->evaluateString();
            rightString = this->_right->evaluateString();

            //
            result = (leftString == rightString);
            break;
        default:
            warning("Runtime error: incompatible types of parameters for ",
                    "Equal operator");
        }
    }
    else
    {
        warning("Runtime error: incompatible types of parameters for ",
                "Equal operator");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotEqualNode::print()
{
    std::cout << "NotEqualNode: !=" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

bool lp::NotEqualNode::evaluateBool()
{
    bool result = false;
    std::string leftString, rightString;

    if (this->getType() == BOOL)
    {
        switch (this->_left->getType())
        {
        case NUMBER:
            double leftNumber, rightNumber;
            leftNumber = this->_left->evaluateNumber();
            rightNumber = this->_right->evaluateNumber();

            // ERROR_BOUND to control the precision of real numbers
            result = (std::abs(leftNumber - rightNumber) >= ERROR_BOUND);
            break;
        case BOOL:
            bool leftBoolean, rightBoolean;
            leftBoolean = this->_left->evaluateBool();
            rightBoolean = this->_right->evaluateBool();

            //
            result = (leftBoolean != rightBoolean);
            break;

        case STRING:
            leftString = this->_left->evaluateString();
            rightString = this->_right->evaluateString();

            //
            result = (leftString != rightString);
            break;

        default:
            warning("Runtime error: incompatible types of parameters for ",
                    "Not Equal operator");
        }
    }
    else
    {
        warning("Runtime error: incompatible types of parameters for ", "Not Equal operator");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AndNode::print()
{
    std::cout << "AndNode: &&" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

bool lp::AndNode::evaluateBool()
{
    bool result = false;

    if (this->getType() == BOOL)
    {
        bool leftBool, rightBool;

        leftBool = this->_left->evaluateBool();
        rightBool = this->_right->evaluateBool();

        result = leftBool and rightBool;
    }
    else
    {
        warning("Runtime error: incompatible types of parameters for ", "operator And");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::OrNode::print()
{
    std::cout << "OrNode: ||" << std::endl;
    std::cout << "\t";
    this->_left->print();
    std::cout << "\t";
    this->_right->print();
}

bool lp::OrNode::evaluateBool()
{
    bool result = false;

    if (this->getType() == BOOL)
    {
        bool leftBool, rightBool;

        leftBool = this->_left->evaluateBool();
        rightBool = this->_right->evaluateBool();

        result = leftBool or rightBool;
    }
    else
    {
        warning("Runtime error: incompatible types of parameters for ", "operator Or");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotNode::print()
{
    std::cout << "NotNode: !" << std::endl;
    std::cout << "\t";
    this->_exp->print();
}

bool lp::NotNode::evaluateBool()
{
    bool result = false;

    if (this->getType() == BOOL)
    {
        result = not this->_exp->evaluateBool();
    }
    else
    {
        warning("Runtime error: incompatible types of parameters for ", "operator Not");
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AssignmentStmt::print()
{
    std::cout << "assignment_node: =" << std::endl;
    std::cout << "\t";
    std::cout << this->_id << std::endl;
    std::cout << "\t";

    // Check the expression
    if (this->_exp != NULL)
    {
        this->_exp->print();
        std::cout << std::endl;
    }
    // this->_asgn is not NULL: multiple assingment
    else
        this->_asgn->print();
}

void lp::AssignmentStmt::evaluate()
{
    lp::Variable *firstVar = (lp::Variable *)table.getSymbol(this->_id);
    std::pair<std::string, lp::DataType> itemPair;
    bool boolean;
    std::string value;
    std::string str;

    // Check the expression
    if (this->_exp != NULL)
    {
        // Check the type of the expression of the asgn
        switch (this->_exp->getType())
        {
        case NUMBER:
        {
            double value;
            // evaluate the expression as NUMBER
            value = this->_exp->evaluateNumber();

            // Check the type of the first varible
            if (firstVar->getType() == NUMBER)
            {
                // Get the identifier in the table of symbols as NumericVariable
                lp::NumericVariable *v = (lp::NumericVariable *)table.getSymbol(this->_id);

                // Assignment the value to the identifier in the table of symbols
                v->setValue(value);
            }
            // The type of variable is not NUMBER
            else
            {
                // Delete the variable from the table of symbols
                table.eraseSymbol(this->_id);

                // Insert the variable in the table of symbols as NumericVariable
                // with the type NUMBER and the value
                lp::NumericVariable *v = new lp::NumericVariable(this->_id,
                                                                 VARIABLE, NUMBER, value);
                table.installSymbol(v);
            }
        }
        break;

        case BOOL:
        {
            bool value;
            // evaluate the expression as BOOL
            value = this->_exp->evaluateBool();

            if (firstVar->getType() == BOOL)
            {
                // Get the identifier in the table of symbols as LogicalVariable
                lp::LogicalVariable *v = (lp::LogicalVariable *)table.getSymbol(this->_id);

                // Assignment the value to the identifier in the table of symbols
                v->setValue(value);
            }
            // The type of variable is not BOOL
            else
            {
                // Delete the variable from the table of symbols
                table.eraseSymbol(this->_id);

                // Insert the variable in the table of symbols as NumericVariable
                // with the type BOOL and the value
                lp::LogicalVariable *v = new lp::LogicalVariable(this->_id,
                                                                 VARIABLE, BOOL, value);
                table.installSymbol(v);
            }
        }
        break;

        // Must be implemented for assingment with STRINGs types
        case STRING: // NEW in v. 0.0.2
        {
            std::string value;
            // evaluate the expression as STRING
            value = this->_exp->evaluateString();

            if (firstVar->getType() == STRING)
            {
                // Get the identifier in the table of symbols as StringVariable
                lp::StringVariable *v = (lp::StringVariable *)table.getSymbol(this->_id);

                // Assignment the value to the identifier in the table of symbols
                v->setValue(value);
            }
            // The type of variable is not STRING
            else
            {
                // Delete the variable from the table of symbols
                table.eraseSymbol(this->_id);

                // Insert the variable in the table of symbols as StringVariable
                // with the type BOOL and the value
                lp::StringVariable *v = new lp::StringVariable(this->_id,
                                                               VARIABLE, STRING, value);
                table.installSymbol(v);
            }
        }
        break;

        case ARRAY_ITEM:
            itemPair = this->_exp->evaluateArrayItem();

            switch (itemPair.second)
            {
            case lp::ELEMENT_VARIABLE_TYPE_NUMBER:
            {
                str = itemPair.first;
                double value;
                sscanf(str.c_str(), "%lf", &value);

                // Check the type of the first varible
                if (firstVar->getType() == NUMBER)
                {
                    // Get the identifier in the table of symbols as NumericVariable
                    lp::NumericVariable *v = (lp::NumericVariable *)table.getSymbol(this->_id);

                    // Assignment the value to the identifier in the table of symbols
                    v->setValue(value);
                }
                // The type of variable is not NUMBER
                else
                {
                    // Delete the variable from the table of symbols
                    table.eraseSymbol(this->_id);

                    // Insert the variable in the table of symbols as NumericVariable
                    // with the type NUMBER and the value
                    lp::NumericVariable *v = new lp::NumericVariable(this->_id,
                                                                     VARIABLE, NUMBER, value);

                    table.installSymbol(v);
                }

                break;

            case lp::ELEMENT_VARIABLE_TYPE_STRING:
                str = itemPair.first;

                // Check the type of the first varible
                if (firstVar->getType() == STRING)
                {
                    // Get the identifier in the table of symbols as NumericVariable
                    lp::StringVariable *v = (lp::StringVariable *)table.getSymbol(this->_id);

                    // Assignment the value to the identifier in the table of symbols
                    v->setValue(str);
                }
                // The type of variable is not NUMBER
                else
                {
                    // Delete the variable from the table of symbols
                    table.eraseSymbol(this->_id);

                    // Insert the variable in the table of symbols as NumericVariable
                    // with the type NUMBER and the value
                    lp::StringVariable *v = new lp::StringVariable(this->_id,
                                                                   VARIABLE, STRING, str);

                    table.installSymbol(v);
                }

                break;

            case lp::ELEMENT_VARIABLE_TYPE_BOOLEAN:
                boolean = itemPair.first == "verdadero" ? true : false;

                // Check the type of the first varible
                if (firstVar->getType() == BOOL)
                {
                    // Get the identifier in the table of symbols as NumericVariable
                    lp::LogicalVariable *v = (lp::LogicalVariable *)table.getSymbol(this->_id);

                    // Assignment the value to the identifier in the table of symbols
                    v->setValue(boolean);
                }
                // The type of variable is not NUMBER
                else
                {
                    // Delete the variable from the table of symbols
                    table.eraseSymbol(this->_id);

                    // Insert the variable in the table of symbols as NumericVariable
                    // with the type NUMBER and the value
                    lp::LogicalVariable *v = new lp::LogicalVariable(this->_id,
                                                                     VARIABLE, BOOL, boolean);

                    table.installSymbol(v);
                }
                break;
            }

            break;

            default:
                warning("Runtime error: incompatible type of expression for ", "Assigment");
            }
        }
    }

    //////////////////////////////////////////////

    else // this->_asgn is not NULL
    {
        // IMPORTANT
        //  evaluate the assigment child
        this->_asgn->evaluate();

        /* Get the identifier of the previous asgn in the table of symbols as Variable */
        lp::Variable *secondVar = (lp::Variable *)table.getSymbol(this->_asgn->_id);

        // Get the type of the variable of the previous asgn
        switch (secondVar->getType())
        {
        case NUMBER:
        {
            /* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
            lp::NumericVariable *secondVar = (lp::NumericVariable *)table.getSymbol(this->_asgn->_id);
            // Check the type of the first variable
            if (firstVar->getType() == NUMBER)
            {
                /* Get the identifier of the first variable in the table of symbols as NumericVariable */
                lp::NumericVariable *firstVar = (lp::NumericVariable *)table.getSymbol(this->_id);
                // Get the identifier o f the in the table of symbols as NumericVariable
                //					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

                // Assignment the value of the second variable to the first variable
                firstVar->setValue(secondVar->getValue());
            }
            // The type of variable is not NUMBER
            else
            {
                // Delete the first variable from the table of symbols
                table.eraseSymbol(this->_id);

                // Insert the first variable in the table of symbols as NumericVariable
                // with the type NUMBER and the value of the previous variable
                lp::NumericVariable *firstVar = new lp::NumericVariable(this->_id,
                                                                        VARIABLE, NUMBER, secondVar->getValue());
                table.installSymbol(firstVar);
            }
        }
        break;

        case BOOL:
        {
            /* Get the identifier of the previous asgn in the table of symbols as LogicalVariable */
            lp::LogicalVariable *secondVar = (lp::LogicalVariable *)table.getSymbol(this->_asgn->_id);
            // Check the type of the first variable
            if (firstVar->getType() == BOOL)
            {
                /* Get the identifier of the first variable in the table of symbols as LogicalVariable */
                lp::LogicalVariable *firstVar = (lp::LogicalVariable *)table.getSymbol(this->_id);
                // Get the identifier o f the in the table of symbols as NumericVariable
                //					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

                // Assignment the value of the second variable to the first variable
                firstVar->setValue(secondVar->getValue());
            }
            // The type of variable is not BOOL
            else
            {
                // Delete the first variable from the table of symbols
                table.eraseSymbol(this->_id);

                // Insert the first variable in the table of symbols as NumericVariable
                // with the type BOOL and the value of the previous variable
                lp::LogicalVariable *firstVar = new lp::LogicalVariable(this->_id,
                                                                        VARIABLE, BOOL, secondVar->getValue());
                table.installSymbol(firstVar);
            }
        }
        break;

        default:
            warning("Runtime error: incompatible type of expression for ", "Assigment");
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AssignmentArrayStmt::print()
{
    if (this->_isIndexAVariable)
    {
        lp::Variable *indexVariable = (lp::Variable *)table.getSymbol(this->_indexVar);

        if (indexVariable->getType() != NUMBER)
            execerror("Runtime error:", "The index of the array it's not supported", "Note: use a NUMBER type instead");

        lp::NumericVariable *indexVar = (lp::NumericVariable *)table.getSymbol(this->_indexVar);

        this->_index = (long)indexVar->getValue();
    }
    std::cout << "assignment_array_node: =" << std::endl;
    std::cout << "\t";
    std::cout << this->_id << std::endl;
    std::cout << "\t Index: ";
    std::cout << this->_index << std::endl;
    std::cout << "\t Expression: ";

    // Check the expression
    if (this->_exp != NULL)
    {
        this->_exp->print();
        std::cout << std::endl;
    }
    // this->_asgn is not NULL: multiple assingment
    else
        this->_asgn->print();
}

void lp::AssignmentArrayStmt::evaluate()
{
    if (this->_isIndexAVariable)
    {
        lp::Variable *indexVariable = (lp::Variable *)table.getSymbol(this->_indexVar);

        if (indexVariable->getType() != NUMBER)
            execerror("Runtime error:", "The index of the array it's not supported", "Note: use a NUMBER type instead");

        lp::NumericVariable *indexVar = (lp::NumericVariable *)table.getSymbol(this->_indexVar);

        this->_index = (long)indexVar->getValue();
    }

    /* Get the identifier in the table of symbols as Variable */
    lp::ArrayVariable *firstVar = (lp::ArrayVariable *)table.getSymbol(this->_id);

    if (firstVar->getType() != ARRAY)
        execerror("Syntax error", "Variable is not an array", "Note: array insertion by the operator \'[INTEGER]\' is only allowed for arrays");

    if (this->_index >= firstVar->getItems().size())
        execerror("Runtime error", "Index out of range", "Note: use a index in the interval [0-N)");

    // Check the expression
    if (this->_exp != NULL)
    {
        // Check the type of the expression of the asgn
        switch (this->_exp->getType())
        {
        case NUMBER:
        {
            double value;
            // evaluate the expression as NUMBER
            value = this->_exp->evaluateNumber();

            // The C way:
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "%g", value);

            firstVar->setItemByIndex(this->_index, std::string(buffer));
            firstVar->setTypeByIndex(this->_index, ELEMENT_VARIABLE_TYPE_NUMBER);
        }
        break;

        case STRING:
        {
            std::string value;
            // evaluate the expression as NUMBER
            value = this->_exp->evaluateString();

            firstVar->setItemByIndex(this->_index, value);
            firstVar->setTypeByIndex(this->_index, ELEMENT_VARIABLE_TYPE_STRING);
        }
        break;

        case BOOL:
        {
            bool value;
            // evaluate the expression as NUMBER
            value = this->_exp->evaluateBool();
            std::string string;

            if (value == true)
                string = "verdadero";

            else
                string = "falso";

            firstVar->setItemByIndex(this->_index, string);
            firstVar->setTypeByIndex(this->_index, ELEMENT_VARIABLE_TYPE_BOOLEAN);
        }
        break;

        default:
            warning("Runtime error: incompatible type of expression for ", "Assigment");
        }
    }

    //////////////////////////////////////////////
    // Allow multiple assigment -> a = b = c = 2;

    else // this->_asgn is not NULL
    {
        // IMPORTANT
        //  evaluate the assigment child
        this->_asgn->evaluate();

        /* Get the identifier of the previous asgn in the table of symbols as Variable */
        lp::Variable *secondVar = (lp::Variable *)table.getSymbol(this->_asgn->_id);

        // Get the type of the variable of the previous asgn
        switch (secondVar->getType())
        {
        case NUMBER:
        {
            /* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
            lp::NumericVariable *secondVar = (lp::NumericVariable *)table.getSymbol(this->_asgn->_id);
            // Check the type of the first variable
            if (firstVar->getType() == NUMBER)
            {
                /* Get the identifier of the first variable in the table of symbols as NumericVariable */
                lp::NumericVariable *firstVar = (lp::NumericVariable *)table.getSymbol(this->_id);
                // Get the identifier o f the in the table of symbols as NumericVariable
                //					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

                // Assignment the value of the second variable to the first variable
                firstVar->setValue(secondVar->getValue());
            }
            // The type of variable is not NUMBER
            else
            {
                // Delete the first variable from the table of symbols
                table.eraseSymbol(this->_id);

                // Insert the first variable in the table of symbols as NumericVariable
                // with the type NUMBER and the value of the previous variable
                lp::NumericVariable *firstVar = new lp::NumericVariable(this->_id,
                                                                        VARIABLE, NUMBER, secondVar->getValue());
                table.installSymbol(firstVar);
            }
        }
        break;

        default:
            warning("Runtime error: incompatible type of expression for ", "Assigment");
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PrintStmt::print()
{
    std::cout << "PrintStmt: print" << std::endl;
    std::cout << "\t";
    this->_exp->print();
    std::cout << std::endl;
}

void lp::PrintStmt::evaluate()
{
    /*
    std::cout << BIYELLOW;
    std::cout << "Escribir: ";
    std::cout << RESET;
    */

    switch (this->_exp->getType())
    {
    case NUMBER:
        std::cout << this->_exp->evaluateNumber();

        break;

    case BOOL:
        if (this->_exp->evaluateBool())
            std::cout << "verdadero";
        else
            std::cout << "falso";

        break;

    case UNDEFINED:
        execerror("Runtime error: trying to print a not defined variable", "The variable is not defined", "Note: use \'tipo_de()\' function to determinate if the variable has not been previously defined.");

    default:
        warning("Runtime error: incompatible type for ", "\'Escribir\' must print numerical and booleans values",
                "Note: use \'escribir_cadena\' for this data type");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PrintStringStmt::print()
{
    std::cout << "PrintStringStmt: print" << std::endl;
    std::cout << "\t";
    this->_exp->print();
    std::cout << std::endl;
}

void lp::PrintStringStmt::evaluate()
{
    /*
    std::cout << BCYAN;
    std::cout << "Escribir cadena: ";
    std::cout << RESET;
    */

    std::string var = this->_exp->evaluateString();

    switch (this->_exp->getType())
    {
    case STRING:
        for (size_t index = 0; index < var.size(); ++index)
        {
            if (var[index] == '\\' and var[index + 1] == 'n')
            {
                std::cout << "\n";
                ++index;
            }

            else if (var[index] == '\\' and var[index + 1] == 't')
            {
                std::cout << "\t";
                ++index;
            }

            else
                std::cout << var[index];
        }
        break;

    case UNDEFINED:
        execerror("Runtime error: trying to print a not defined variable", "The variable is not defined", "Note: use \'tipo_de()\' function to determinate if the variable has not been previously defined.");

        break;

    default:
        execerror("Runtime error: incompatible type for ", "escribir_cadena", "Note: use a string value");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PrintArrayStmt::print()
{
    std::cout << "PrintArrayStmt: print" << std::endl;
    std::cout << "\t";
    std::cout << "VariableNode: " << this->_id;
    std::cout << std::endl;
}

void lp::PrintArrayStmt::evaluate()
{
    /*
    std::cout << BBLUE;
    std::cout << "Escribir array: ";
    std::cout << RESET;
    */

    lp::ArrayVariable *v = (lp::ArrayVariable *)table.getSymbol(this->_id);
    std::vector<std::string> items;
    std::vector<lp::DataType> types;

    switch (v->getType())
    {
    case ARRAY:
        items = v->getItems();
        types = v->getTypes();

        std::cout << "[";
        for (size_t index = 0; index < items.size(); index++)
        {
            if (types[index] == ELEMENT_VARIABLE_TYPE_NUMBER or types[index] == ELEMENT_VARIABLE_TYPE_BOOLEAN)
            {
                if (index == items.size() - 1)
                    std::cout << items[index] << "]";

                else
                    std::cout << items[index] << ", ";
            }

            else if (types[index] == ELEMENT_VARIABLE_TYPE_STRING)
            {
                if (index == items.size() - 1)
                    std::cout << "\'" << items[index] << "\'"
                              << "]";

                else
                    std::cout << "\'" << items[index] << "\'"
                              << ", ";
            }
        }
        break;

    case UNDEFINED:
        execerror("Runtime error: trying to print a not defined variable", "The variable is not defined", "Note: use \'tipo_de()\' function to determinate if the variable has not been previously defined.");

        break;

    default:
        warning("Runtime error: incompatible type for ", "escribir_array", "Note: use an array value");
    }

    std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ReadStmt::print()
{
    std::cout << "ReadStmt: read" << std::endl;
    std::cout << "\t";
    std::cout << this->_id;
    std::cout << std::endl;
}

void lp::ReadStmt::evaluate()
{
    double value;
    /*
    std::cout << BIYELLOW;
    std::cout << "Inserta un valor de tipo numérico --> " ;
    std::cout << RESET;
    */
    std::cin >> value;
    std::cin.ignore();

    /* Get the identifier in the table of symbols as Variable */
    lp::Variable *var = (lp::Variable *)table.getSymbol(this->_id);

    // Check if the type of the variable is NUMBER
    if (var->getType() == NUMBER)
    {
        /* Get the identifier in the table of symbols as NumericVariable */
        lp::NumericVariable *n = (lp::NumericVariable *)table.getSymbol(this->_id);

        /* Assignment the read value to the identifier */
        n->setValue(value);
    }
    // The type of variable is not NUMBER
    else
    {
        // Delete $1 from the table of symbols as Variable
        table.eraseSymbol(this->_id);

        // Insert $1 in the table of symbols as NumericVariable
        // with the type NUMBER and the read value
        lp::NumericVariable *n = new lp::NumericVariable(this->_id,
                                                         VARIABLE, NUMBER, value);

        table.installSymbol(n);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ReadStringStmt::print()
{
    std::cout << "ReadStmt: read" << std::endl;
    std::cout << "\t";
    std::cout << this->_id;
    std::cout << std::endl;
}

// Modified in v. 0.0.3
void lp::ReadStringStmt::evaluate()
{
    std::string value;
    /*
    std::cout << BCYAN;
    std::cout << "Inserta un valor de tipo cadena --> " ;
    std::cout << RESET;
    */
    std::getline(std::cin, value);
    /* Get the identifier in the table of symbols as Variable */
    lp::Variable *var = (lp::Variable *)table.getSymbol(this->_id);

    // Check if the type of the variable is STRING
    if (var->getType() == STRING)
    {
        /* Get the identifier in the table of symbols StringVariable */
        lp::StringVariable *s = (lp::StringVariable *)table.getSymbol(this->_id);

        /* Assignment the read value to the identifier */
        s->setValue(value);

        std::cout << s->getValue();
    }
    // The type of variable is not STRING
    else
    {
        // Delete $1 from the table of symbols as Variable
        table.eraseSymbol(this->_id);

        // Insert $1 in the table of symbols as StringVariable
        // with the type STRING and the read value
        lp::StringVariable *s = new lp::StringVariable(this->_id,
                                                       VARIABLE, STRING, value);

        table.installSymbol(s);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EmptyStmt::print()
{
    std::cout << "EmptyStmt " << std::endl;
}

void lp::EmptyStmt::evaluate()
{
    // Empty
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in v. 0.0.4

// Block Statement has been added

void lp::IfStmt::print()
{
    std::cout << "IfStmt: " << std::endl;
    // Condition
    std::cout << "\t";
    this->_cond->print();

    // Consequent
    std::cout << "\t";
    this->_block1->print();

    // The alternative is printed if exists
    if (this->_block2 != NULL)
    {
        std::cout << "\t";
        this->_block2->print();
    }

    std::cout << std::endl;
}

void lp::IfStmt::evaluate()
{
    // If the condition is true,
    if (this->_cond->evaluateBool() == true)
        // the consequent is run
        this->_block1->evaluate();

    // Otherwise, the alternative is run if exists
    else if (this->_block2 != NULL)
        this->_block2->evaluate();
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Modified in v.0.0.3

void lp::WhileStmt::print()
{
    std::cout << "WhileStmt: " << std::endl;
    // Condition
    std::cout << "\t";
    this->_cond->print();

    // Body of the while loop
    std::cout << "\t";
    this->_block->print();

    std::cout << std::endl;
}

void lp::WhileStmt::evaluate()
{
    // While the condition is true. the body is run
    while (this->_cond->evaluateBool() == true)
    {
        this->_block->evaluate();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Modified in v.0.0.4

void lp::RepeatStmt::print()
{
    std::cout << "repeatStmt: " << std::endl;
    // Condition
    std::cout << "\t";
    this->_cond->print();

    // Body of the Do loop
    std::cout << "\t";
    this->_block->print();
    std::cout << std::endl;
}

void lp::RepeatStmt::evaluate()
{
    // The body is run until the condition is true.
    do
    {
        this->_block->evaluate();
    } while (this->_cond->evaluateBool() == false);
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in v. 0.0.3

void lp::ForStmt::print()
{
    std::cout << "ForStmt: " << std::endl;
    // Variable to initialize
    std::cout << "\t";
    std::cout << this->_var;

    // Since expresion
    std::cout << "\t";
    this->_since->print();

    // Until expresion
    std::cout << "\t";
    this->_until->print();

    // Body statement
    std::cout << "\t";
    /*
  for (int i = 0; i < this->_stmts.size(); i++)
  {
      this->_stmts[i]->print();
  }
    */
    std::cout << std::endl;
}

void lp::ForStmt::evaluate()
{
    if (this->_since->getType() != NUMBER)
        execerror("Runtime error", "Initial value it's not a number");

    if (this->_until->getType() != NUMBER)
        execerror("Runtime error", "Last value it's not a number");

    if (this->_step != NULL and this->_step->getType() != NUMBER)
        execerror("Runtime error", "Step value it's not a number");

    if (this->_until->evaluateNumber() < this->_since->evaluateNumber())
        execerror("Runtime error", "Interval not valid, until value must be greater than since value");

    lp::NumericVariable *n = new lp::NumericVariable();

    // Check if Var exists in the table of symbols
    if (table.lookupSymbol(this->_var) == false)
        n = new lp::NumericVariable(this->_var, VARIABLE, NUMBER, this->_since->evaluateNumber());

    else
    {
        lp::Variable *var = (lp::Variable *)table.getSymbol(this->_var);

        if (var->getType() == NUMBER)
            n = (lp::NumericVariable *)table.getSymbol(this->_var);

        else
        {
            // Delete $1 from the table of symbols as Variable
            table.eraseSymbol(this->_var);

            // Insert $1 in the table of symbols as NUMBERVariable
            // with the type NUMBER and the read value
            n = new lp::NumericVariable(this->_var, VARIABLE, NUMBER);

            table.installSymbol(n);
        }

        n->setValue(this->_since->evaluateNumber());
    }

    double step = 1.0;

    if (this->_step != NULL and this->_step->evaluateNumber() <= ERROR_BOUND)
        execerror("Runtime error", "Step has no increment, infinite loop", "Note: use step default value");

    else if (this->_step != NULL)
        step = this->_step->evaluateNumber();

    for (; n->getValue() <= this->_until->evaluateNumber(); n->setValue(n->getValue() + step))
    {
        this->_block->evaluate();
    }

    /* table.eraseSymbol(this->_var); */
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::BlockStmt::print()
{
    std::list<Statement *>::iterator stmtIter;

    std::cout << "BlockStmt: " << std::endl;

    for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++)
    {
        (*stmtIter)->print();
    }
}

void lp::BlockStmt::evaluate()
{
    std::list<Statement *>::iterator stmtIter;

    for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++)
    {
        (*stmtIter)->evaluate();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW v. 0.0.5

int lp::CaseNode::getType()
{
    return this->_exp->getType();
}

void lp::CaseNode::print()
{
    std::list<Statement *>::iterator itr;
    std::cout << "CaseNode: " << std::endl;
    std::cout << "\t";
    for (itr = this->_stmtList->begin(); itr != this->_stmtList->end(); itr++)
    {
        (*itr)->print();
    }
    std::cout << std::endl;
}

void lp::CaseNode::evaluate()
{
    std::list<Statement *>::iterator itr;
    for (itr = this->_stmtList->begin(); itr != this->_stmtList->end(); itr++)
    {
        (*itr)->evaluate();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW v. 0.0.5

void lp::BlockSwitchCaseNode::print()
{
    std::list<CaseNode *>::iterator itr;
    std::cout << "CasesStmt: " << std::endl;
    std::cout << "\t";
    this->_exp->print();
    std::cout << "\t";
    for (itr = this->_cases->begin(); itr != this->_cases->end(); itr++)
    {
        (*itr)->print();
    }
    if (this->_defaultCase != NULL)
    {
        this->_defaultCase->print();
    }
    std::cout << std::endl;
}

void lp::BlockSwitchCaseNode::evaluate()
{
    int type = this->_exp->getType();
    std::list<CaseNode *>::iterator caseIter;
    bool enteredCase = false;

    for (caseIter = this->_cases->begin(); caseIter != this->_cases->end() && !enteredCase; caseIter++)
    {
        if ((*caseIter)->getType() == type)
        {
            switch (type)
            {
            case NUMBER:
            {
                if ((*caseIter)->getExp()->evaluateNumber() == this->_exp->evaluateNumber())
                {
                    (*caseIter)->evaluate();
                    enteredCase = true;
                }
            }
            break;

            case BOOL:
            {
                if ((*caseIter)->getExp()->evaluateBool() == this->_exp->evaluateBool())
                {
                    (*caseIter)->evaluate();
                    enteredCase = true;
                }
            }
            break;

            case STRING:
            {
                if ((*caseIter)->getExp()->evaluateString() == this->_exp->evaluateString())
                {
                    (*caseIter)->evaluate();
                    enteredCase = true;
                }
            }
            break;

            default:
                warning("Runtime error: incompatible types for ", "valor");
            }
        }

        else
        {
            warning("Runtime error: incompatible types for ", "valor");
        }
    }

    if (!enteredCase && this->_defaultCase != NULL)
    {
        this->_defaultCase->evaluate();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AST::print()
{
    std::list<Statement *>::iterator stmtIter;

    for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++)
    {
        (*stmtIter)->print();
    }
}

void lp::AST::evaluate()
{
    std::list<Statement *>::iterator stmtIter;

    for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++)
    {
        (*stmtIter)->evaluate();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/* NEW in v. 0.0.4 */

void lp::TypeOfStmt::print()
{
    std::cout << "TypeOfStmt: print" << std::endl;
    std::cout << "\t";
    this->_exp->print();
    std::cout << std::endl;
}

void lp::TypeOfStmt::evaluate()
{
    switch (this->_exp->getType())
    {
    case NUMBER:
        std::cout << "Número" << std::endl;

        break;

    case BOOL:
        std::cout << "Boolean" << std::endl;

        break;

    case STRING:
        std::cout << "Cadena" << std::endl;

        break;

    case ARRAY:
        std::cout << "Array" << std::endl;
        break;

    default:
        std::cout << "INDEFINIDO" << std::endl;

        break;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/* NEW in v. 0.0.9 */

void lp::StyleStmt::print()
{
    std::cout << "StyleStmt: print" << std::endl;
    std::cout << "\t";
    this->_exp->print();
    std::cout << std::endl;
}

void lp::StyleStmt::evaluate()
{
    if (this->_exp->getType() == STRING)
    {
        std::string style = this->_exp->evaluateString();

        for (size_t index = 0; index < style.size(); index++)
            style[index] = toupper(style[index]);

        if (style == "NEGRITA")
            std::cout << INTENSITY;

        else if (style == "ITALICA" or style == "ITÁLICA")
            std::cout << ITALIC;

        else if (style == "DEFECTO")
            std::cout << RESET;
        
        else if (style == "SUAVE")
            std::cout << FAINT;

        else if (style == "SUBRAYADO")
            std::cout << UNDERLINE;

        else if (style == "PARPADEO")
            std::cout << BLINK;

        else if (style == "INVERSO")
            std::cout << INVERSE;

        ///////////////////////////////////////////////////////////////

        else if (style == "NEGRO")
            std::cout << BLACK;

        else if (style == "ROJO")
            std::cout << RED;

        else if (style == "VERDE")
            std::cout << GREEN;
        
        else if (style == "AMARILLO")
            std::cout << YELLOW;

        else if (style == "AZUL")
            std::cout << BLUE;

        else if (style == "MAGENTA")
            std::cout << PURPLE;

        else if (style == "CYAN")
            std::cout << CYAN;

        else if (style == "BLANCO")
            std::cout << WHITE;
        
        ///////////////////////////////////////////////////////////////

        else if (style == "NEGRITA_NEGRO")
            std::cout << BBLACK;

        else if (style == "NEGRITA_ROJO")
            std::cout << BRED;

        else if (style == "NEGRITA_VERDE")
            std::cout << BGREEN;
        
        else if (style == "NEGRITA_AMARILLO")
            std::cout << BYELLOW;

        else if (style == "NEGRITA_AZUL")
            std::cout << BBLUE;

        else if (style == "NEGRITA_MAGENTA")
            std::cout << BPURPLE;
            
        else if (style == "NEGRITA_CYAN")
            std::cout << BCYAN;

        else if (style == "NEGRITA_BLANCO")
            std::cout << BWHITE;

        ///////////////////////////////////////////////////////////////

        else if (style == "SUBRAYADO_NEGRO")
            std::cout << UBLACK;

        else if (style == "SUBRAYADO_ROJO")
            std::cout << URED;

        else if (style == "SUBRAYADO_VERDE")
            std::cout << UGREEN;
        
        else if (style == "SUBRAYADO_AMARILLO")
            std::cout << UYELLOW;

        else if (style == "SUBRAYADO_AZUL")
            std::cout << UBLUE;

        else if (style == "SUBRAYADO_MAGENTA")
            std::cout << UPURPLE;
            
        else if (style == "SUBRAYADO_CYAN")
            std::cout << UCYAN;

        else if (style == "SUBRAYADO_BLANCO")
            std::cout << UWHITE;

        ///////////////////////////////////////////////////////////////

        else if (style == "FONDO_NEGRO")
            std::cout << ONBLACK;

        else if (style == "FONDO_ROJO")
            std::cout << ONRED;

        else if (style == "FONDO_VERDE")
            std::cout << ONGREEN;
        
        else if (style == "FONDO_AMARILLO")
            std::cout << ONYELLOW;

        else if (style == "FONDO_AZUL")
            std::cout << ONBLUE;

        else if (style == "FONDO_MAGENTA")
            std::cout << ONPURPLE;
            
        else if (style == "FONDO_CYAN")
            std::cout << ONCYAN;

        else if (style == "FONDO_BLANCO")
            std::cout << ONWHITE;

        ///////////////////////////////////////////////////////////////

        else if (style == "INTENSO_NEGRO")
            std::cout << IBLACK;

        else if (style == "INTENSO_ROJO")
            std::cout << IRED;

        else if (style == "INTENSO_VERDE")
            std::cout << IGREEN;
        
        else if (style == "INTENSO_AMARILLO")
            std::cout << IYELLOW;

        else if (style == "INTENSO_AZUL")
            std::cout << IBLUE;

        else if (style == "INTENSO_MAGENTA")
            std::cout << IPURPLE;
            
        else if (style == "INTENSO_CYAN")
            std::cout << ICYAN;

        else if (style == "INTENSO_BLANCO")
            std::cout << IWHITE;

        ///////////////////////////////////////////////////////////////

        else if (style == "NEGRITA_INTENSO_NEGRO")
            std::cout << BIBLACK;

        else if (style == "NEGRITA_INTENSO_ROJO")
            std::cout << BIRED;

        else if (style == "NEGRITA_INTENSO_VERDE")
            std::cout << BIGREEN;
        
        else if (style == "NEGRITA_INTENSO_AMARILLO")
            std::cout << BIYELLOW;

        else if (style == "NEGRITA_INTENSO_AZUL")
            std::cout << BIBLUE;

        else if (style == "NEGRITA_INTENSO_MAGENTA")
            std::cout << BIPURPLE;
            
        else if (style == "NEGRITA_INTENSO_CYAN")
            std::cout << BICYAN;

        else if (style == "NEGRITA_INTENSO_BLANCO")
            std::cout << BIWHITE;

        ///////////////////////////////////////////////////////////////

        else if (style == "INTENSO_FONDO_NEGRO")
            std::cout << ONIBLACK;

        else if (style == "INTENSO_FONDO_ROJO")
            std::cout << ONIRED;

        else if (style == "INTENSO_FONDO_VERDE")
            std::cout << ONIGREEN;
        
        else if (style == "INTENSO_FONDO_AMARILLO")
            std::cout << ONIYELLOW;

        else if (style == "INTENSO_FONDO_AZUL")
            std::cout << ONIBLUE;

        else if (style == "INTENSO_FONDO_MAGENTA")
            std::cout << ONIPURPLE;
            
        else if (style == "INTENSO_FONDO_CYAN")
            std::cout << ONICYAN;

        else if (style == "INTENSO_FONDO_BLANCO")
            std::cout << ONIWHITE;

        ///////////////////////////////////////////////////////////////

        else   
            warning("Runtime error: Command not found", "estilo", "Note: use a valid style");

    }

    else
    {
        warning("Runtime error: incompatible types for ", "estilo", "Note: use a string value instead");
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/* NEW in v. 0.0.6 */

void lp::ClearScreenStmt::print()
{
    std::cout << "ClearScreenStmt: print MACRO CLEAR_SCREEN" << std::endl;
    std::cout << "\t";
    std::cout << std::endl;
}

void lp::ClearScreenStmt::evaluate()
{
    std::cout << CLEAR_SCREEN;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/* NEW in v. 0.0.6 */

void lp::PlaceStmt::print()
{
    std::cout << "PlaceStmt: print" << std::endl;
    std::cout << "\t";
    this->_expX->print();
    this->_expY->print();
    std::cout << std::endl;
}

void lp::PlaceStmt::evaluate()
{
    if (this->_expX->getType() != NUMBER or this->_expY->getType() != NUMBER)
        execerror("Runtime error", "The variable is not a number", "Note: Use numeric variables");

    PLACE((int)this->_expX->evaluateNumber(), (int)this->_expY->evaluateNumber());
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::ArrayNode::getType()
{
    return ARRAY;
}

void lp::ArrayNode::print()
{

    if (this->_sizeGivenAsString)
    {
        lp::Variable *sizeVariable = (lp::Variable *)table.getSymbol(this->_sizeString);

        if (sizeVariable->getType() != NUMBER)
            execerror("Runtime error:", "The number of elements of the array it's not supported", "Note: use a NUMBER type instead");

        lp::NumericVariable *sizeVar = (lp::NumericVariable *)table.getSymbol(this->_sizeString);

        this->_size = (long)sizeVar->getValue();
    }

    if ((long)this->_size <= 0)
            execerror("Runtime error:", "The size of the array is not valid", "Note: use a positive number");

    std::cout << "ArrayNode: " << std::endl;
    std::cout << "\t";
    std::cout << "ArraySize: " << this->_size;
    std::cout << std::endl;
}

std::vector<std::string> lp::ArrayNode::evaluateArray()
{
    if (this->_sizeGivenAsString)
    {
        lp::Variable *sizeVariable = (lp::Variable *)table.getSymbol(this->_sizeString);

        if (sizeVariable->getType() != NUMBER)
            execerror("Runtime error:", "The number of elements of the array it's not supported", "Note: use a NUMBER type instead");

        lp::NumericVariable *sizeVar = (lp::NumericVariable *)table.getSymbol(this->_sizeString);

        this->_size = (long)sizeVar->getValue();

    }

    if ((long)this->_size <= 0)
            execerror("Runtime error:", "The size of the array is not valid", "Note: use a positive number");

    return this->_items;
}

std::vector<lp::DataType> lp::ArrayNode::evaluateTypes()
{
    if (this->_sizeGivenAsString)
    {
        lp::Variable *sizeVariable = (lp::Variable *)table.getSymbol(this->_sizeString);

        if (sizeVariable->getType() != NUMBER)
            execerror("Runtime error:", "The number of elements of the array it's not supported", "Note: use a NUMBER type instead");

        lp::NumericVariable *sizeVar = (lp::NumericVariable *)table.getSymbol(this->_sizeString);

        this->_size = (long)sizeVar->getValue();
    }

    if ((long)this->_size <= 0)
            execerror("Runtime error:", "The size of the array is not valid", "Note: use a positive number");

    return this->_types;
}

size_t lp::ArrayNode::evaluateSize()
{
    if (this->_sizeGivenAsString)
    {
        lp::Variable *sizeVariable = (lp::Variable *)table.getSymbol(this->_sizeString);

        if (sizeVariable->getType() != NUMBER)
            execerror("Runtime error:", "The number of elements of the array it's not supported", "Note: use a NUMBER type instead");

        lp::NumericVariable *sizeVar = (lp::NumericVariable *)table.getSymbol(this->_sizeString);

        this->_size = (long)sizeVar->getValue();
    }

    if ((long)this->_size <= 0)
            execerror("Runtime error:", "The size of the array is not valid", "Note: use a positive number");

    return this->_size;
}

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::AccessArrayNode::getType()
{
    return ARRAY_ITEM;
}

void lp::AccessArrayNode::print()
{
    if (this->_givenIndexAsString)
    {
        lp::Variable *indexVar = (lp::Variable *)table.getSymbol(this->_indexByString);

        if (indexVar->getType() != NUMBER)
            execerror("Runtime error", "Variable is not a number", "Note: the index must be a numeric value");

        lp::NumericVariable *indexNumericVar = (lp::NumericVariable *)table.getSymbol(this->_indexByString);

        this->_indexItem = indexNumericVar->getValue();
    }

    std::cout << "ArrayNode: " << this->_arrayId << std::endl;
    std::cout << "\t";
    std::cout << "IndexOfItem: " << this->_indexItem << std::endl;
}

/*
std::pair<std::string, lp::DataType> lp::AccessArrayNumberNode::evaluate()
{
    std::string str;
    bool boolean;

    if (this->_givenIndexAsString)
    {
        lp::Variable *indexVar = (lp::Variable *) table.getSymbol(this->_indexByString);

        if (indexVar->getType() != NUMBER)
            execerror("Syntax error", "Variable is not a number", "Note: the index must be a numeric value");

        lp::NumericVariable *indexNumericVar = (lp::NumericVariable*) table.getSymbol(this->_indexByString);

        this->_indexItem = indexNumericVar->getValue();

    }

    lp::Variable *var = (lp::Variable *) table.getSymbol(this->_arrayId);

    if(var->getType() != ARRAY)
        execerror("Syntax error", "Variable is not an array", "Note: array access is only allowed for arrays");

    lp::ArrayVariable *arrayVar = (lp::ArrayVariable *) table.getSymbol(this->_arrayId);

    std::vector<lp::DataType> types = arrayVar->getTypes();
    std::vector<std::string> items = arrayVar->getItems();

    lp::ExpNode * value;

    switch(types[this->_indexItem])
    {
        case lp::ELEMENT_VARIABLE_TYPE_NUMBER:
            str = items[this->_indexItem];
            double d;

            sscanf(str.c_str(), "%lf", &d);

            value = new lp::NumberNode(d);

        break;

        case lp::ELEMENT_VARIABLE_TYPE_STRING:
            value = new lp::StringNode(items[this->_indexItem]);

        break;

        case lp::ELEMENT_VARIABLE_TYPE_BOOLEAN:
            boolean = items[this->_indexItem] == "verdadero" ? true : false;

            value = new lp::BoolNode(boolean);

        break;

        default:
            execerror("Runtime error:", "The item of the array it's not defined", "Note: check the index specified");
    }

    return value;
}
*/

double lp::AccessArrayNode::getValue()
{
    double d;
    lp::ArrayVariable *var = (lp::ArrayVariable *)table.getSymbol(this->_arrayId);
    std::vector<std::string> items = var->getItems();
    std::string str = items[this->_indexItem];

    sscanf(str.c_str(), "%lf", &d);

    return d;
}

std::pair<std::string, lp::DataType> lp::AccessArrayNode::evaluateArrayItem()
{
    std::pair<std::string, lp::DataType> item;

    std::string str;

    if (this->_givenIndexAsString)
    {
        lp::Variable *indexVar = (lp::Variable *)table.getSymbol(this->_indexByString);

        if (indexVar->getType() != NUMBER)
            execerror("Syntax error", "Variable is not a number", "Note: the index must be a numeric value");

        lp::NumericVariable *indexNumericVar = (lp::NumericVariable *)table.getSymbol(this->_indexByString);

        this->_indexItem = indexNumericVar->getValue();
    }

    lp::Variable *var = (lp::Variable *)table.getSymbol(this->_arrayId);

    if (var->getType() != ARRAY)
        execerror("Syntax error", "Variable is not an array", "Note: array access is only allowed for arrays");

    lp::ArrayVariable *arrayVar = (lp::ArrayVariable *)table.getSymbol(this->_arrayId);

    std::vector<lp::DataType> types = arrayVar->getTypes();
    std::vector<std::string> items = arrayVar->getItems();

    switch (types[this->_indexItem])
    {
    case lp::ELEMENT_VARIABLE_TYPE_NUMBER:
        /*
        str = items[this->_indexItem];
        double d;

        sscanf(str.c_str(), "%lf", &d);
        */

        item.first = items[this->_indexItem];
        item.second = lp::ELEMENT_VARIABLE_TYPE_NUMBER;

        break;

    case lp::ELEMENT_VARIABLE_TYPE_STRING:
        // value = new lp::StringNode(items[this->_indexItem]);

        item.first = items[this->_indexItem];
        item.second = lp::ELEMENT_VARIABLE_TYPE_STRING;

        break;

    case lp::ELEMENT_VARIABLE_TYPE_BOOLEAN:
        // boolean = items[this->_indexItem] == "verdadero" ? true : false;
        // value = new lp::BoolNode(boolean);

        item.first = items[this->_indexItem];
        item.second = lp::ELEMENT_VARIABLE_TYPE_BOOLEAN;

        break;

    default:
        execerror("Runtime error:", "The item of the array it's not defined", "Note: check the index specified");
    }

    return item;
}

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::StringOperatorNode::getType()
{
    if (this->_left->getType() == STRING && this->_right->getType() == STRING)
        return STRING;
    else
    {
        execerror("Runtime Error: Concatenation of non-string expressions", "The expressions have incompatible types", "Note: Use 2 strings to use concatenation Operator");
        return UNDEFINED;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::CreateArrayStmt::print()
{
    this->_array->print();
}

void lp::CreateArrayStmt::evaluate()
{
    size_t size = this->_array->evaluateSize();

    // evaluate the expression as ARRAY
    lp::Variable *v = (lp::Variable *)table.getSymbol(this->_id);

    if (v->getType() == ARRAY)
    {
        // Get the identifier in the table of symbols as LogicalVariable
        lp::ArrayVariable *v = (lp::ArrayVariable *)table.getSymbol(this->_id);

        if (size <= 0)
            execerror("Runtime error:", "The size of the array is not valid", "Note: use a positive number");

        // Assignment the value to the identifier in the table of symbols
        v->setSize(size);
    }
    // The type of variable is not ARRAY
    else
    {
        // Delete the variable from the table of symbols
        table.eraseSymbol(this->_id);

        if (size <= 0)
            execerror("Runtime error:", "The size of the array is not valid", "Note: use a positive number");

        // Insert the variable in the table of symbols as NumericVariable
        // with the type BOOL and the value
        lp::ArrayVariable *v = new lp::ArrayVariable(this->_id,
                                                     VARIABLE, ARRAY, size);

        table.installSymbol(v);
    }
}