/*! 
  \file interpreter.y
  \brief Grammar file
*/


%{
#include <iostream>
#include <string>

/*******************************************/
/* NEW in example 5 */
/* pow */
#include <math.h>
/*******************************************/

/*******************************************/
/* NEW in example 6 */
/* Use for recovery of runtime errors */
#include <setjmp.h>
#include <signal.h>
/*******************************************/

/* Error recovery functions */
#include "../error/error.hpp"

/* Macros for the screen */
#include "../includes/macros.hpp"


/*******************************************/
/* 
  NEW in example 16
  AST class
  IMPORTANT: this file must be before init.hpp
*/
#include "../ast/ast.hpp"


/*******************************************/
/* NEW in example 7 */
/* Table of symbol */
#include "../table/table.hpp"
/*******************************************/

/*******************************************/
#include "../table/numericVariable.hpp"
/*******************************************/

/* NEW in example 15 */
#include "../table/logicalVariable.hpp"

/*******************************************/
/* NEW in example 11 */
#include "../table/numericConstant.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 15 */
#include "../table/logicalConstant.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 13 */
#include "../table/builtinParameter1.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 14 */
#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter2.hpp"
/*******************************************/


/*******************************************/
/* NEW in example 10 */
#include "../table/init.hpp"
/*******************************************/

/*******************************************/
/* NEW in v. 0.0.7 */
// #include "../table/arrayVariable.hpp"
/*******************************************/

/*! 
	\brief  Lexical or scanner function
	\return int
	\note   C++ requires that yylex returns an int value
	\sa     yyparser
*/
int yylex();


extern int lineNumber; //!< External line counter


/* NEW in example 15 */
extern bool interactiveMode; //!< Control the interactive mode of execution of the interpreter

/* New in example 17 */
extern int control; //!< External: to control the interactive mode in "if" and "while" sentences 


/***********************************************************/
/* NEW in example 2 */
extern std::string progname; //!<  Program name
/***********************************************************/

/*******************************************/
/* NEW in example 6 */
/*
 jhmp_buf
    This is an array type capable of storing the information of a calling environment to be restored later.
   This information is filled by calling macro setjmp and can be restored by calling function longjmp.
*/
jmp_buf begin; //!<  It enables recovery of runtime errors 
/*******************************************/


/*******************************************/
/* NEW in example 7 */
extern lp::Table table; //!< Extern Table of Symbols

/*******************************************/
/* NEW in example 16 */
extern lp::AST *root; //!< External root of the abstract syntax tree AST

%}



/* In case of a syntactic error, more information is shown */
%error-verbose

/* Initial grammar symbol */
%start program

/*******************************************/
/* Data type YYSTYPE  */
/* NEW in example 4 */
%union {
  char * identifier; 				 					/* NEW in example 7 */
  char * string;					 					/* NEW in v. 0.0.2 */
  double number;  										/* NEW in example 5 */
  bool logic;						 					/* NEW in example 15 */
  std::vector<std::string> *arrayItems;					/* New in v 0.0.8 */ 
  std::vector<int> *arrayTypeItems; 					/* New in v 0.0.8 */
  lp::ExpNode *expNode;  			 					/* NEW in example 16 */
  std::list<lp::ExpNode *>  *parameters;    			// New in example 16; NOTE: #include<list> must be in interpreter.l, init.cpp, interpreter.cpp
  std::list<lp::Statement *> *stmts; 					/* NEW in example 16 */
  lp::Statement *st;				 					/* NEW in example 16 */
  lp::AST *prog;					 					/* NEW in example 16 */
  std::list<lp::CaseNode *> *cases;  					/* NEW in v. 0.0.5 */  
  lp::CaseNode *individualCase;							/* New in v. 0.0.5 */
  lp::BlockSwitchCaseNode *switchCase; 					/* NEW in v. 0.0.5 */
  lp::OperatorAssignmentNode *opAssignNode; 			/* New in v. 0.0.6 */
  std::pair<std::string, lp::DataType> *arrayItemNode;	/* New in v. 0.0.8 */
  lp::ArrayNode *arrayNode;								/* New in v. 0.0.8 */
}

/* Type of the non-terminal symbols */
// New in example 17: cond
%type <expNode> exp cond

//%type <arrayItemNode> arrayitem

//%type <arrayList> arrayitemlist

%type <st> create_array

%type <opAssignNode> inc

/* New in example 14 */
%type <parameters> listOfExp  restOfListOfExp

%type <stmts> stmtlist

// New in v. 0.0.4 
%type <cases> caselist

// NEW in v. 0.0.5
%type <individualCase> case defaultcase
 
// NEW in v. 0.0.5
%type <switchCase> switch

// New in example 17: if, while, block. If statement has been created
%type <st> stmt asgn print print_string print_array read read_string if while for block repeat type_of clear_screen place style

%type <prog> program

/* Defined tokens */

/* Minimum precedence */

/*******************************************/
/* NEW in example 5 */
%token SEMICOLON
/*******************************************/

/* NEW in example 17: IF, ELSE, WHILE */
/* NEW in v. 0.0.1: READ_STRING */
%token PRINT PRINT_STRING PRINT_ARRAY READ READ_STRING IF ELSE THEN END_IF WHILE DO END_WHILE FOR SINCE UNTIL STEP END_FOR REPEAT TYPE_OF DEFAULT SWITCH CASE END_SWITCH STYLE

// NEW in v. 0.0.6
%token CLEAR_SCREEN_TOKEN PLACE_TOKEN

/* NEW in example 17 */
%token LETFCURLYBRACKET RIGHTCURLYBRACKET

%nonassoc PLUS_ASSIGN MINUS_ASSIGN

/* NEW in example 7 */
%right ASSIGNMENT

/* NEW in example 14 */
// NEW in v. 0.0.4
%token COMMA TWO_DOTS

/*******************************************/
/* MODIFIED in example 4 */
%token <number> NUMBER 
/*******************************************/

/*******************************************/
/* NEW in v. 0.0.1 */
%token <string> STRING
/*******************************************/

/*******************************************/
/* NEW in v. 0.0.8 */
%token <arrayNode> ARRAY
/*******************************************/

/*******************************************/
/* NEW in v. 0.0.9 */
%token <arrayItemNode> ARRAY_ITEM
/*******************************************/

/*******************************************/
/* NEW in example 15 */
%token <logic> BOOL
/*******************************************/

/* MODIFIED in examples 11, 13 */
%token <identifier> VARIABLE UNDEFINED CONSTANT BUILTIN

/* Left associativity */

/*******************************************************/
/* NEW in example 15 */
%left OR

%left AND

%nonassoc GREATER_OR_EQUAL LESS_OR_EQUAL GREATER_THAN LESS_THAN  EQUAL NOT_EQUAL

%left NOT
/*******************************************************/

/* MODIFIED in example 3 */
%left PLUS MINUS CONCATENATION

/* MODIFIED in example 5 */
%left MULTIPLICATION DIVISION MODULO

/* New in example 13 */
%left LPAREN RPAREN LBRACKET RBRACKET

/* Modify in v.0.0.7 */
%nonassoc  UNARY INCREMENT DECREMENT

// Maximum precedence 
/* MODIFIED in example 5 */
%right POWER


%%
 //! \name Grammar rules

/* MODIFIED  Grammar in example 16 */

program: stmtlist
		  { 
		    // Create a new AST
			$$ = new lp::AST($1); 

			// Assign the AST to the root
			root = $$; 

			// End of parsing
			//	return 1;
		  }
;

stmtlist:  /* empty: epsilon rule */
		  { 
			// create a empty list of statements
			$$ = new std::list<lp::Statement *>(); 
		  }  

        | stmtlist stmt 
		  { 
			// copy up the list and add the stmt to it
			$$ = $1;
			$$->push_back($2);

			// Control the interative mode of execution of the interpreter
			if (interactiveMode == true && control == 0)
 			{
				for(std::list<lp::Statement *>::iterator it = $$->begin(); 
						it != $$->end(); 
						it++)
				{
                    //(*it)->print(); 
					(*it)->evaluate();
					
				}

				// Delete the AST code, because it has already run in the interactive mode.
				$$->clear();
			}
		}

    | stmtlist error 
      { 
			 // just copy up the stmtlist when an error occurs
			 $$ = $1;

			 // The previous look-ahead token ought to be discarded with `yyclearin;'
			 yyclearin; 
       } 
;


stmt: SEMICOLON  /* Empty statement: ";" */
	  {
		// Create a new empty statement node
		$$ = new lp::EmptyStmt(); 
	  }
	| asgn  SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	| print SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	| read SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	 | read_string SEMICOLON // NEW in v. 0.0.1
	    {
			// Default action
			// $$ = $1;
		}
	 | print_string SEMICOLON
	    {
			// Default action
			// $$ = $1;
		}
	 | print_array SEMICOLON
	    {
			// Default action
			// $$ = $1;
		}
	/*  NEW in example 17 */
	| if 
	 {
		// Default action
		// $$ = $1;
	 }
	/*  NEW in example 17 */
	| while 
	 {
		// Default action
		// $$ = $1;
	 }
	/*  NEW in v. 0.0.3 */
	| for
	 {
		// Default action
		// $$ = $1;
	 }
	 /*  NEW in v. 0.0.3 */
	| repeat
	 {
		// Default action
		// $$ = $1;
	 }
	/*  NEW in example 17 */
	| block 
	 {
		// Default action
		// $$ = $1;
	 }
	 /*  NEW in v. 0.0.4 */
	| type_of
	 {
		 // Default action
		 // $$ = $1;
	 }
	 // NEW in v. 0.0.6
	| clear_screen
	 {
		 // Default action
		 // $$ = $1;
	 }
	| place
	 {
		 // Default action
		 // $$ = $1;
	 }
	/*  NEW in v 0.0.9 */
	| style
	 {
		 // Default action
		 // $$ = $1;
	 }
	 /*  NEW in v. 0.0.4 */
	| switch
	 {
		 // Default action
		 // $$ = $1;
	 }
	/*  NEW in v. 0.0.6 */
	| inc
	 {
		 // Default action
		 // $$ = $1;
	 }

	/*  NEW in v. 0.0.6 */
	| create_array
	 {
		 // Default action
		 // $$ = $1;
	 }
;

/* New in v 0.0.7 */
inc :  	VARIABLE INCREMENT // NEW in v. 0.0.6
		{ 
			// Create a new IncrementNode
			$$ = new lp::IncrementNode($1, 1);
		}

	| 	VARIABLE DECREMENT
      	{
			// Create a new IncrementNode
			$$ = new lp::IncrementNode($1, -1);
		}

	| 	INCREMENT VARIABLE 
		{ 
			// Create a new IncrementNode
			$$ = new lp::IncrementNode($2, 1);		 
		 }

	| 	DECREMENT VARIABLE
      	{
			// Create a new IncrementNode
			$$ = new lp::IncrementNode($2, -1);
		}
	/*
	| VARIABLE PLUS_ASSIGN exp 
		{ 
			// Create a new assignment node
			$$ = new lp::IncrementNode($1, $3, 1);
		}

	|  VARIABLE MINUS_ASSIGN exp 
		{ 
			// Create a new assignment node
			$$ = new lp::IncrementNode($1, $3, -1);
		}
	*/
;
/*  NEW in v. 0.0.4 */
switch: SWITCH controlSymbol LPAREN exp RPAREN caselist END_SWITCH
	{	
		// Create a new do statement node
		$$ = new lp::BlockSwitchCaseNode($4, $6);

		// To control the interactive mode
		control--;
	}

	| SWITCH controlSymbol LPAREN exp RPAREN caselist defaultcase END_SWITCH
	{	
		// Create a new do statement node
		$$ = new lp::BlockSwitchCaseNode($4, $6, $7);
		
		// To control the interactive mode
		control--;
	}
;

/* New in v 0.0.5 */
caselist:  /* empty: epsilon rule */
		  { 
			// create a empty list of cases for switch-case
			$$ = new std::list<lp::CaseNode *>(); 
		  }  

        | caselist case
		  { 
			// copy up the list and add the case to it
			$$ = $1;
			$$->push_back($2);
		}
; 

/* New in v 0.0.5 */
case: CASE NUMBER TWO_DOTS stmtlist 
	  {	
		  	lp::ExpNode * exp = new lp::NumberNode($2);
			$$ = new lp::CaseNode(exp, $4);
	  }	
	| CASE CONSTANT TWO_DOTS stmtlist
	  {
		  	lp::ExpNode * exp = new lp::ConstantNode($2);
			$$ = new lp::CaseNode(exp, $4);
	  }	
	| CASE STRING TWO_DOTS stmtlist
	  {
			lp::ExpNode * exp = new lp::StringNode($2);
			$$ = new lp::CaseNode(exp, $4);
	  }	
;

/* New in v 0.0.5 */
defaultcase: DEFAULT TWO_DOTS stmtlist
			{
				// Create a new case node
				$$ = new lp::CaseNode(NULL, $3);
			}
;

/* Modified in v 0.0.5 */
block: LETFCURLYBRACKET stmtlist RIGHTCURLYBRACKET  
		{
			// Create a new block of statements node
			$$ = new lp::BlockStmt($2); 
		}
;

/* Modified in v 0.0.5 */
controlSymbol:  /* Epsilon rule*/
		{
			// To control the interactive mode in "if" and "while" sentences
			control++;
		}
;

/*  NEW in example 17 */
if:	/* Simple conditional statement */
	IF controlSymbol cond THEN stmtlist END_IF
    {
		// Create a new if statement node
		$$ = new lp::IfStmt($3, $5);

		// To control the interactive mode
		control--;
	}

	/* Compound conditional statement */
	| IF controlSymbol cond THEN stmtlist ELSE stmtlist END_IF
	 {
		// Create a new if statement node
		$$ = new lp::IfStmt($3, $5, $7);

		// To control the interactive mode
		control--;
	 }
;

/*  NEW in v. 0.0.3 */
while:  WHILE controlSymbol cond DO stmtlist END_WHILE 
		{
			// Create a new while statement node
			$$ = new lp::WhileStmt($3, $5);

			// To control the interactive mode
			control--;
    }
;

/*  NEW in v. 0.0.3 */
repeat: REPEAT controlSymbol stmtlist UNTIL cond SEMICOLON
	{	
		// Create a new do statement node
		$$ = new lp::RepeatStmt($3, $5);

		// To control the interactive mode
		control--;
	}
;

/*  NEW in v. 0.0.3 */
for:	FOR controlSymbol VARIABLE SINCE exp UNTIL exp DO stmtlist END_FOR
		{
			// Create a new for statement node
			$$ = new lp::ForStmt($3, $5, $7, $9);

			// To control the interactive mode
			control--;
    	}

	|	FOR controlSymbol VARIABLE SINCE exp UNTIL exp STEP exp DO stmtlist END_FOR
		{
			// Create a new for statement node
			$$ = new lp::ForStmt($3, $5, $7, $11, $9);

			// To control the interactive mode
			control--;
		}

;

/*  NEW in example 17 */
cond: 	LPAREN exp RPAREN
		{ 
			$$ = $2;
		}
;

/* Modified in v 0.0.7 */
asgn:   VARIABLE ASSIGNMENT exp 
		{ 
			// Create a new assignment node
			$$ = new lp::AssignmentStmt($1, $3);
		}

	|  VARIABLE ASSIGNMENT asgn 
		{ 
			// Create a new assignment node
			$$ = new lp::AssignmentStmt($1, (lp::AssignmentStmt *) $3);
		}

	   /* NEW in example 11 */ 
	| CONSTANT ASSIGNMENT exp 
		{   
 			execerror("Semantic error in assignment", "It is not allowed to modify a constant", "Note: " + std::string($1) + " its a constant value");
		}
	   /* NEW in example 11 */ 
	| CONSTANT ASSIGNMENT asgn 
		{   
 			execerror("Semantic error in multiple assignment", "It is not allowed to modify a constant", "Note: " + std::string($1) + " its a constant value");
		}

		/* New in v 0.0.8 */
	| VARIABLE LBRACKET NUMBER RBRACKET ASSIGNMENT exp
		{
			// Create a new assignment node
			$$ = new lp::AssignmentArrayStmt($1, $3, $6);
		}
	
		/* New in v 0.0.9 */
	| VARIABLE LBRACKET VARIABLE RBRACKET ASSIGNMENT exp
		{
			$$ = new lp::AssignmentArrayStmt($1, $3, $6);
		}
;

/* Modified in v 0.0.2 */
print:  PRINT exp 
		{
			// Create a new print node
			 $$ = new lp::PrintStmt($2);
		}
;

/* NEW in v. 0.0.2 */
print_string: PRINT_STRING exp 
			   {	
				   // Create a new print node
			 		$$ = new lp::PrintStringStmt($2);
			   }
;

/* New in v 0.0.8 */
print_array: PRINT_ARRAY LPAREN VARIABLE RPAREN
			{
				// Create a new print node
				$$ = new lp::PrintArrayStmt($3);
			}

			| PRINT_ARRAY VARIABLE 
			{
				// Create a new print node
				$$ = new lp::PrintArrayStmt($2);
			}
;

/* Modified in v 0.0.1 */
read:  READ LPAREN VARIABLE RPAREN  
		{
			// Create a new read node
			 $$ = new lp::ReadStmt($3);
		}

  	  /* NEW rule in example 11 */
	| READ LPAREN CONSTANT RPAREN  
		{   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a constant ",$3);
		}
;

/* Modified in v 0.0.2 */
read_string: READ_STRING LPAREN VARIABLE RPAREN // NEW in v. 0.0.1
				{
					// Create a new read_string node
					$$ = new lp::ReadStringStmt($3);
				}
			| READ_STRING LPAREN CONSTANT RPAREN // NEW in v. 0.0.8
				{
					execerror("Semantic error in \"read_string statement\": it is not allowed to modify a constant ",$3);
				}
;

/* NEW in v. 0.0.4 */
type_of: TYPE_OF LPAREN exp RPAREN 
			{
				// Create a new TypeOfStmt
				$$ = new lp::TypeOfStmt($3);
			}
;

/* New in v 0.0.6 */
clear_screen: CLEAR_SCREEN_TOKEN LPAREN RPAREN
				{
					// Create a new ClearScreenStmt
					$$ = new lp::ClearScreenStmt();
				}
;

/* New in v 0.0.6 */
place: PLACE_TOKEN LPAREN exp COMMA exp RPAREN
		{
			// Create a new PlaceStmt
			$$ = new lp::PlaceStmt($3, $5);
		}
;

/* New in v 0.0.6 */
style: STYLE LPAREN exp RPAREN
		{
			// Create a new PlaceStmt
			$$ = new lp::StyleStmt($3);
		}
;

/* Modified in v 0.0.8 */
exp:	NUMBER 
		{ 
			// Create a new number node
			$$ = new lp::NumberNode($1);
		}

	|   STRING
		{ 
			// Create a new String node
			$$ = new lp::StringNode($1);
		}
	
	|   BOOL
		{
			// Create a new Bool node
			$$ = new lp::BoolNode($1);
		}

	| 	exp PLUS exp 
		{ 
			// Create a new plus node
			 $$ = new lp::PlusNode($1, $3);
		 }

	| 	exp MINUS exp
      	{
			// Create a new minus node
			$$ = new lp::MinusNode($1, $3);
		}

	| 	VARIABLE INCREMENT 
		{ 
			// Create a new IncrementNode
			//$$ = new lp::IncrementNode($1, 1);
		 }

	| 	VARIABLE DECREMENT
      	{
			// Create a new IncrementNode
			//$$ = new lp::IncrementNode($1, -1);
		}

	| 	INCREMENT VARIABLE 
		{ 
			// Create a new IncrementNode
			//$$ = new lp::IncrementNode($2, 1);		 
		 }

	| 	DECREMENT VARIABLE
      	{
			// Create a new IncrementNode
			//$$ = new lp::IncrementNode($2, -1);
		}

	| 	exp MULTIPLICATION exp 
		{ 
			// Create a new multiplication node
			$$ = new lp::MultiplicationNode($1, $3);
		}

	| 	exp DIVISION exp
		{
		  // Create a new division node	
		  $$ = new lp::DivisionNode($1, $3);
	   }

	| 	LPAREN exp RPAREN
       	{ 
		    // just copy up the expression node 
			$$ = $2;
		 }

  	| 	PLUS exp %prec UNARY
		{ 
		  // Create a new unary plus node	
  		  $$ = new lp::UnaryPlusNode($2);
		}

	| 	MINUS exp %prec UNARY
		{ 
		  // Create a new unary minus node	
  		  $$ = new lp::UnaryMinusNode($2);
		}

	|	exp MODULO exp 
		{
		  // Create a new modulo node	

		  $$ = new lp::ModuloNode($1, $3);
       }

	|	exp POWER exp 
     	{ 
		  // Create a new power node	
  		  $$ = new lp::PowerNode($1, $3);
		}

	 | VARIABLE
		{
		  // Create a new variable node	
		  $$ = new lp::VariableNode($1);
		}

	 | CONSTANT
		{
		  // Create a new constant node	
		  $$ = new lp::ConstantNode($1);

		}

	| BUILTIN LPAREN listOfExp RPAREN
		{
			// Get the identifier in the table of symbols as Builtin
			lp::Builtin *f= (lp::Builtin *) table.getSymbol($1);

			// Check the number of parameters 
			if (f->getNParameters() ==  (int) $3->size())
			{
				switch(f->getNParameters())
				{
					case 0:
						{
							// Create a new Builtin Function with 0 parameters node	
							$$ = new lp::BuiltinFunctionNode_0($1);
						}
						break;

					case 1:
						{
							// Get the expression from the list of expressions
							lp::ExpNode *e = $3->front();

							// Create a new Builtin Function with 1 parameter node	
							$$ = new lp::BuiltinFunctionNode_1($1,e);
						}
						break;

					case 2:
						{
							// Get the expressions from the list of expressions
							lp::ExpNode *e1 = $3->front();
							$3->pop_front();
							lp::ExpNode *e2 = $3->front();

							// Create a new Builtin Function with 2 parameters node	
							$$ = new lp::BuiltinFunctionNode_2($1,e1,e2);
						}
						break;

					default:
				  			 execerror("Syntax error: too many parameters for function ", $1);
				} 
			}
			else
	  			 execerror("Syntax error: incompatible number of parameters for function", $1);
		}

	| exp GREATER_THAN exp
	 	{
		  // Create a new "greater than" node	
 			$$ = new lp::GreaterThanNode($1,$3);
		}

	| exp GREATER_OR_EQUAL exp 
	 	{
		  // Create a new "greater or equal" node	
 			$$ = new lp::GreaterOrEqualNode($1,$3);
		}

	| exp LESS_THAN exp 	
	 	{
		  // Create a new "less than" node	
 			$$ = new lp::LessThanNode($1,$3);
		}

	| exp LESS_OR_EQUAL exp 
	 	{
		  // Create a new "less or equal" node	
 			$$ = new lp::LessOrEqualNode($1,$3);
		}

	| exp EQUAL exp 	
	 	{
		  // Create a new "equal" node	
 			$$ = new lp::EqualNode($1,$3);
		}

    | exp NOT_EQUAL exp 	
	 	{
		  // Create a new "not equal" node	
 			$$ = new lp::NotEqualNode($1,$3);
		}

    | exp AND exp 
	 	{
		  // Create a new "logic and" node	
 			$$ = new lp::AndNode($1,$3);
		}

    | exp OR exp 
	 	{
		  // Create a new "logic or" node	
 			$$ = new lp::OrNode($1,$3);
		}

    | NOT exp 
	 	{
		  // Create a new "logic negation" node	
 			$$ = new lp::NotNode($2);
		}
	
	| exp CONCATENATION exp
		{
			// Create a new "concatenation" node
			$$ = new lp::ConcatenationNode($1,$3);
		
		}
	
	| VARIABLE LBRACKET NUMBER RBRACKET
	   {
			// Access to an array item
			$$ = new lp::AccessArrayNode($1, $3);  
		   
	   }
	
	| VARIABLE LBRACKET VARIABLE RBRACKET
	    {
		   // Access to an array item
		   $$ = new lp::AccessArrayNode($1, $3);  
		}
		   
;

/* Modified in v 0.0.3 */
listOfExp: 
			/* Empty list of numeric expressions */
			{
			    // Create a new list STL
				$$ = new std::list<lp::ExpNode *>(); 
			}

	|  exp restOfListOfExp
			{
				$$ = $2;

				// Insert the expression in the list of expressions
				$$->push_front($1);
			}
;

/* Modified in v 0.0.3 */
restOfListOfExp:
			/* Empty list of numeric expressions */
			{
			    // Create a new list STL
				$$ = new std::list<lp::ExpNode *>(); 
			}

		|	COMMA exp restOfListOfExp
			{
				// Get the list of expressions
				$$ = $3;
				
				// Insert the expression in the list of expressions
				$$->push_front($2);
			}
;

create_array: VARIABLE ASSIGNMENT LBRACKET NUMBER RBRACKET 
		{
			// Create a new Array node
			$$ = new lp::CreateArrayStmt($1, $4);
		}
	
	|	VARIABLE ASSIGNMENT LBRACKET VARIABLE RBRACKET
		{
			// Create a new Array node
			$$ = new lp::CreateArrayStmt($1, $4);
		}
		
;  


%%


