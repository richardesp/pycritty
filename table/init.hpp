/*!
    \file   init.hpp
    \brief   Prototype of the function for the initialization of table of symbols
    \author
    \date    2017-12-5
    \version 1.0
*/

#ifndef _INIT_HPP_
#define _INIT_HPP_

// sin, cos, atan, fabs, ...
#include <math.h>

#include "table.hpp"

// IMPORTANT: This file must be before y.tab.h
#include "../ast/ast.hpp"
///////////////////////////////////////

//  interpreter.tab.h contains the number values of the tokens produced by the parser
#include "../parser/interpreter.tab.h"

///////////////////////////////////////
// NEW in example 13
#include "mathFunction.hpp"
#include "builtinParameter1.hpp"
///////////////////////////////////////

///////////////////////////////////////
// NEW in example 14
#include "builtinParameter0.hpp"
#include "builtinParameter2.hpp"
///////////////////////////////////////

/*!
  \ brief Predefined numeric constants
*/
static struct
{
    std::string name;
    double value;
} numericConstant[] = {
    {"PI", 3.14159265358979323846},
    {"E", 2.71828182845904523536},
    {"GAMMA", 0.57721566490153286060},
    {"DEG", 57.29577951308232087680},
    {"PHI", 1.61803398874989484820},
    {"", 0}};

/*!
  \ brief Predefined Variable constants
*/
static struct
{
    std::string name;
    int value;
} variableTypeConstant[] = {
    {"INDEFINIDO", 1},
    {"NUMERO", 2},
    {"CADENA", 3},
    {"BOOLEANO", 4},
    {"ARRAY", 5},
    {"", 0}};


/*!
  \ brief Predefined logical constants
*/
// NEW in example 16
static struct
{
    std::string name;
    bool value;
} logicalConstant[] = {
    {"verdadero", true}, // NEW in v. 0.0.6
    {"falso", false},    // NEW in v. 0.0.6
    {"", 0}};

// NEW in example 12
/*!
  \ brief Predefined keywords
*/
static struct
{
    std::string name;
    int token;
} keyword[] = {
    {"escribir", PRINT},
    {"escribir_cadena", PRINT_STRING}, // NEW in v. 0.0.1
    {"escribir_array", PRINT_ARRAY},   // NEW in v. 0.0.8
    {"leer", READ},
    {"leer_cadena", READ_STRING},            // NEW in v. 0.0.1
    {"si", IF},                              // NEW in v. 0.0.3
    {"entonces", THEN},                      // NEW in v. 0.0.3
    {"si_no", ELSE},                         // NEW in v. 0.0.3
    {"fin_si", END_IF},                      // NEW in v. 0.0.3
    {"mientras", WHILE},                     // NEW in v. 0.0.3
    {"hacer", DO},                           // NEW in v. 0.0.3
    {"fin_mientras", END_WHILE},             // NEW in v. 0.0.3
    {"para", FOR},                           // NEW in v. 0.0.3
    {"paso", STEP},                          // NEW in v. 0.0.3
    {"fin_para", END_FOR},                   // NEW in v. 0.0.3
    {"desde", SINCE},                        // NEW in v. 0.0.3
    {"hasta", UNTIL},                        // NEW in v. 0.0.3
    {"repetir", REPEAT},                     // NEW in v. 0.0.3
    {"tipo_de", TYPE_OF},                    // NEW in v. 0.0.4
    {"borrar_pantalla", CLEAR_SCREEN_TOKEN}, // NEW in v. 0.0.6
    {"lugar", PLACE_TOKEN},                  // NEW in v. 0.0.6
    {"segun", SWITCH},                       // NEW in v. 0.0.4
    {"defecto", DEFAULT},                    // NEW in v. 0.0.4
    {"valor", CASE},                         // NEW in v. 0.0.4
    {"fin_segun", END_SWITCH},               // NEW in v. 0.0.4
    {"estilo", STYLE},                      // NEW in v. 0.0.9
    {"", 0}};

// NEW in example 13

static struct
{ /* Predefined functions names */
    std::string name;
    lp::TypePointerDoubleFunction_1 function;
} function_1[] = {
    {"sin", sin},
    {"cos", cos},
    {"atan", atan},
    {"log", Log},
    {"log10", Log10},
    {"exp", Exp},
    {"sqrt", Sqrt},
    {"integer", integer},
    {"abs", fabs},
    {"", 0}};

// NEW in example 14
static struct
{
    std::string name;
    lp::TypePointerDoubleFunction_0 function;
} function_0[] = {
    {"uniforme", Random},
    {"", 0}};

// NEW in example 14

static struct
{ /* Nombres predefinidos de funciones con 2 argumentos */
    std::string name;
    lp::TypePointerDoubleFunction_2 function;
} function_2[] = {
    {"atan2", Atan2},
    {"", 0}};

/*!
    \brief   Initialize the table of symbols
    \return  void
*/

void init(lp::Table &t);

// End of _INIT_HPP_
#endif
