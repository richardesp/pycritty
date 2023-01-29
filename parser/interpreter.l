/*! 
  \file interpreter.l
  \brief Lexical or scanner file
*/
%{
#include <iostream>
#include <vector>
/*********************/
/* NEW in example 4 */
/* atof */
#include <stdlib.h>
/*********************/

/* Macros for the screen */
#include "../includes/macros.hpp"

/*********************/
/* 
  NEW in example 16 
  AST class
  IMPORTANT: must be written before interpreter.tab.h
*/
#include "../ast/ast.hpp"
/*********************/

/*  interpreter.tab.h contains the numeric values of the tokens produced by the parser */
#include "interpreter.tab.h"

/********************/
/* NEW in example 3 */
#include "../error/error.hpp"
/********************/


/*********************************************/
/* NEW in example 7 */
/* Table of symbols */
#include "../table/table.hpp"

#include "../table/numericVariable.hpp"

extern lp::Table table; //!< External Table of Symbols
/*********************************************/

extern int lineNumber; //!< External line counter

/* uso de strdup */
#include <string.h>


%}


/*! \name REGULAR DEFINITIONS  */

DIGIT  					[0-9] 

LETTER 					[a-zA-Z]

NUMBER1 				{DIGIT}+\.?

NUMBER2 				{DIGIT}*\.{DIGIT}+

NUMBER3					{DIGIT}+(\.{DIGIT}+)?((e|E)[+\-]?{DIGIT}+)?

NUMBER_WRONG1			{DIGIT}+\.\.+{DIGIT}*   

NUMBER_WRONG2			{DIGIT}+(e|E)(e|E)+{DIGIT}*

NUMBER_WRONG3			{DIGIT}+(e|E)(\+|\-)(\+|\-)+{DIGIT}*

IDENTIFIER  			{LETTER}({LETTER}|{DIGIT}|_({LETTER}|{DIGIT}))*

IDENTIFIER_WRONG1		_({LETTER}|{DIGIT}|_({LETTER}|{DIGIT}))*

IDENTIFIER_WRONG2		{LETTER}({LETTER}|{DIGIT}|_({LETTER}|{DIGIT}))*_

IDENTIFIER_WRONG3		{LETTER}({LETTER}|{DIGIT}|__({LETTER}|{DIGIT}))+

CADENA					"'"([^'\\]|"\\\'"|\\n|\\t)*"'"

/* New in v. 0.0.7 */
/* STATE  */
%x ERROR 
%x Q1

/*! \name REGULAR EXPRESSIONS  */
%%

[ \t] 			{ ; }    /* skip white space and tabular */

\n      		{ 
					/* Line counter */
           			lineNumber++; 
	
					/* MODIFIED in example 3 */
					/* COMMENTED in example 5 */
        			/* return NEWLINE; */
        		}

 /*! \name RESERVED WORDS */

(?i:leer) 				{ 
							return READ; /* NEW in v.0.0.1 */
						}

(?i:leer_cadena)		{
							return READ_STRING; /* NEW in v.0.0.1 */
						}

(?i:escribir)			{
							return PRINT; /* NEW in v.0.0.1 */
						}	

(?i:escribir_cadena)	{
							return PRINT_STRING; // New in v. 0.0.1
						}

(?i:escribir_array)		{
							return PRINT_ARRAY; // New in v 0.0.8
						}

(?i:si)					{
							return IF; /* NEW in v.0.0.3 */
						}

(?i:entonces) 			{
							return THEN; /* NEW in v.0.0.3 */
						}

(?i:si_no)				{
							return ELSE; /* New in v.0.0.3 */
						}

(?i:fin_si) 			{
							return END_IF; /* NEW in v.0.0.3 */
						}

(?i:mientras)			{
							return WHILE; /* NEW in v.0.0.3 */
						}				

(?i:hacer) 				{	
							return DO; /* NEW in v.0.0.3 */	
						}

(?i:fin_mientras)		{
						return END_WHILE; /* NEW in v.0.0.3 */
						}

(?i:para)				{
							return FOR; /* NEW in v.0.0.3 */
						}

(?i:desde)				{
							return SINCE; /* NEW in v.0.0.3 */
						}

(?i:hasta)				{
							return UNTIL; /* NEW in v.0.0.3 */
						}
				
(?i:fin_para)			{	
							return END_FOR; /* NEW in v.0.0.3 */
						}

(?i:repetir)			{
							return REPEAT; /* NEW in v.0.0.3 */
						}

(?i:paso)				{
							return STEP; /* NEW in v.0.0.3 */
						}

(?i:segun)				{
							return SWITCH ; /* NEW in v.0.0.4 */
						}

(?i:defecto)			{
							return DEFAULT ; /* NEW in v.0.0.4 */
						}

(?i:valor)				{
							return CASE; /* New in v.0.0.4 */
						}

(?i:fin_segun)			{
							return END_SWITCH; /* New in v.0.0.4 */
						}

(?i:verdadero)			{
							yylval.logic  =  true; /* New in v.0.0.6 */	
							return BOOL; 
						}

(?i:falso)				{	
							yylval.logic  =  false; /* New in v.0.0.6 */	
							return BOOL;
						}

(?i:no)					{ 	return NOT; }				/* Modified in v.0.0.6 */

(?i:o)					{ 	return OR; }				/* Modified in v.0.0.6 */

(?i:y)					{ 	return AND; }				/* Modified in v.0.0.6 */

(?i:tipo_de)			{
							return TYPE_OF; /* New in v.0.0.4 */
						}

(?i:borrar_pantalla)	{
							return CLEAR_SCREEN_TOKEN; /* New in v.0.0.6 */
						}

(?i:lugar)				{
							return PLACE_TOKEN; /* New in v.0.0.6 */
						}

 /*! \name STRINGS */

{CADENA}				{	/* NEW in v.0.0.3 */
							memmove(yytext, yytext + 1, yyleng);
							yytext[yyleng - 2] = '\0';

							yylval.identifier =  strdup(yytext); 
							return STRING;
						}		 												  

 /*! \name NUMBERS */

{NUMBER1}|{NUMBER2}|{NUMBER3}  	{
					  				/* MODIFIED in example 4 */
					  				/* Conversion of type and sending of the numerical value to the parser */
					   				yylval.number = atof(yytext); 
                       				return NUMBER; 
                      		   	}

{NUMBER_WRONG1}					{
									execerror("Lexical error:", "Misspelled floating number", "Note: Removes the second decimal point. Use the format expression \'{DIGIT}+(.{DIGIT}+)\'");
								}

{NUMBER_WRONG2}					{
									execerror("Lexical error:", "Power misspelled", "Note: Removes the second exponent. Use the format expression \'{DIGIT}+(.{DIGIT}+)?((e|E)[+-]?{DIGIT}+)?\'");
								}

{NUMBER_WRONG3}					{
									execerror("Lexical error:", "Power misspelled", "Note: Removes the second exponent sign. Use the format expression \'{DIGIT}+(.{DIGIT}+)?((e|E)[+-]?{DIGIT}+)?\'");
								}

	
 /*! \name Identifiers */

{IDENTIFIER}   			 {
							/* NEW in example 7 */
							std::string identifier(yytext);

							/* 
							strdup() function returns a pointer to a new string 
							which  is a duplicate of the string yytext
							*/
							yylval.identifier =  strdup(yytext); 

							/* If the identifier is not in the table of symbols then it is inserted */	
							if (table.lookupSymbol(identifier) == false)
								{
									/* 
									The identifier is inserted into the symbol table 
									as undefined Variable with value 0.0
									*/
									lp::NumericVariable *n = new lp::NumericVariable(identifier,VARIABLE,UNDEFINED,0.0);

									/* A pointer to the new NumericVariable is inserted into the table of symbols */
									table.installSymbol(n);

									return VARIABLE;
								}

							/* MODIFIED in example 11 */
							/* 
								If the identifier is in the table of symbols then its token is returned 
									The identifier can be a variable or a numeric constant
							*/
							else 
								{
									lp::Symbol	*s = table.getSymbol(identifier);

									/*
									std::cout << "lex: "<< s->getName() 
											<< "token " << s->getToken()
											<< std::endl; 
									*/

									/*  If the identifier is in the table then its token is returned  */
									return s->getToken();
								}
                     	}

{IDENTIFIER_WRONG1}		{
							execerror("Lexical error: Incorrectly spelled identifier", "The identifier cannot begin with an underscore", "Note: delete the first underscore");
						}

{IDENTIFIER_WRONG2}		{
							execerror("Lexical error: Incorrectly spelled identifier", "The identifier cannot end with an underscore", "Note: delete the last underscore");
						}

{IDENTIFIER_WRONG3}		{
							execerror("Lexical error: Incorrectly spelled identifier", "The identifier cannot have double underscores", "Note: delete one underscore");
						}					


 /*! \name PRIMITIVE TOKENS */

";"						{	 return SEMICOLON; } /* NEW in example 5 */ 
","						{	 return COMMA; } /* NEW in example 5 */ 

"-"						{ 	return MINUS;  } 			/* NEW in example 3 */
"+"						{ 	return PLUS;   } 			/* NEW in example 3 */

"*"	   					{ 	return MULTIPLICATION; } 	/* NEW in example 3 */
"//"    				{ 	return DIVISION; } 		   /* NEW in example 3 */

"("     				{ 	return LPAREN; } 			/* NEW in example 3 */
")"	    				{ 	return RPAREN; } 			/* NEW in example 3 */

"++"					{ 	return INCREMENT; } 		/* New in v.0.0.6 */
"--"					{ 	return DECREMENT; } 		/* New in v.0.0.6 */

"+:="					{ 	return PLUS_ASSIGN;  } 	    /* New in v.0.0.6 */
"-:="					{ 	return MINUS_ASSIGN; } 	    /* New in v.0.0.6 */

"%"     				{ 	return MODULO; }			/* NEW in example 5 */

"**"					{ 	return POWER; }			    /* NEW in example 5 */

":=" 					{ 	return ASSIGNMENT; }		/* NEW in example 7 */

"||"					{	return CONCATENATION; }		/* NEW in v.0.0.7 */

"=="					{ 	return EQUAL; }			/* NEW in example 15 */

"<>"					{ 	return NOT_EQUAL; }		/* NEW in example 15 */

">="					{ 	return GREATER_OR_EQUAL; }/* NEW in example 15 */

"<="					{ 	return LESS_OR_EQUAL; }	/* NEW in example 15 */

">"						{ 	return GREATER_THAN; }	/* NEW in example 15 */

"<"						{ 	return LESS_THAN; }		/* NEW in example 15 */

"{"						{	return LETFCURLYBRACKET; } 	/* NEW in example 17 */

"}"						{ 	return RIGHTCURLYBRACKET; }	/* NEW in example 17 */

"]"						{ 	return RBRACKET;}			/* NEW in v. 0.0.8 */

"["						{ 	return LBRACKET; } 		/* NEW in v. 0.0.8 */

":"						{ 	return TWO_DOTS; }		/* NEW in v. 0.0.4 */

 /*! \name COMMENTS */

#.*         			; // Comment detected NEW in v. 0.0.7

"<<"        			{ /* New in v 0.0.5 */	
							BEGIN(Q1); 
							yymore();
						} 

<Q1>"<<"				{
							execerror("Lexical error", "Nested multiline comments not allowed", "Note: Close previous comment before opening new ones");
							BEGIN(INITIAL); 
						}
			
<Q1>[^>>\n]   			{	
							yymore(); 
						}

<Q1>>       			{	yymore(); } /* Creo esta norma vacia para evitar imprimir los comparadores */

<Q1>\n   			{
							lineNumber++;
							yymore();
						}

<Q1><<EOF>>				{
							warning("Lexical error", "Multiline comment not closed", "Note: add to the line the following token \'>>\'");
							return 0;
						}


<Q1>">>"			    {	
							BEGIN(INITIAL);
						}


<<EOF>>					 { 	/* The interpreter finishes when finds the end of file character */
							/*
							PLACE(24,10);
							std::cout <<  BICYAN;
							std::cout <<  ">>>>>>> End of file <<<<<<<";
							std::cout << std::endl;
							std::cout << RESET;
							PLACE(25,1);
							*/
							return 0;
						}


.						{ 	
							/* Any other character */
							/* MODIFIIED in example 3 */
							/* Change to error state */
							BEGIN(ERROR); 

							/* The current value of yytext 
								will be concatenated with the next character */
							yymore();  
						}

 /*! \name LEXICAL ERRORS */

<ERROR>[^0-9+\-*/()\^% \t\n\;a-zA-Z=<>!&]	{ 	/* MODIFIED in examples 5, 7, 15 */
												/* The current value of yytext 
												will be concatenated with the next character */
												yymore(); 
											}

<ERROR>(.|\n)           { 
							/* NEW in example 3 */
							/* Rewind one position */
							yyless(yyleng-1); 

							/* Display the error message */
							warning("Lexical error:", "symbol not allowed");

							/* Restore the initial state */
							BEGIN(INITIAL);
						}
%%

