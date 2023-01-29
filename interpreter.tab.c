/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "parser/interpreter.y" /* yacc.c:339  */

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


#line 189 "interpreter.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    PRINT = 259,
    PRINT_STRING = 260,
    PRINT_ARRAY = 261,
    READ = 262,
    READ_STRING = 263,
    IF = 264,
    ELSE = 265,
    THEN = 266,
    END_IF = 267,
    WHILE = 268,
    DO = 269,
    END_WHILE = 270,
    FOR = 271,
    SINCE = 272,
    UNTIL = 273,
    STEP = 274,
    END_FOR = 275,
    REPEAT = 276,
    TYPE_OF = 277,
    DEFAULT = 278,
    SWITCH = 279,
    CASE = 280,
    END_SWITCH = 281,
    STYLE = 282,
    CLEAR_SCREEN_TOKEN = 283,
    PLACE_TOKEN = 284,
    LETFCURLYBRACKET = 285,
    RIGHTCURLYBRACKET = 286,
    PLUS_ASSIGN = 287,
    MINUS_ASSIGN = 288,
    ASSIGNMENT = 289,
    COMMA = 290,
    TWO_DOTS = 291,
    NUMBER = 292,
    STRING = 293,
    ARRAY = 294,
    ARRAY_ITEM = 295,
    BOOL = 296,
    VARIABLE = 297,
    UNDEFINED = 298,
    CONSTANT = 299,
    BUILTIN = 300,
    OR = 301,
    AND = 302,
    GREATER_OR_EQUAL = 303,
    LESS_OR_EQUAL = 304,
    GREATER_THAN = 305,
    LESS_THAN = 306,
    EQUAL = 307,
    NOT_EQUAL = 308,
    NOT = 309,
    PLUS = 310,
    MINUS = 311,
    CONCATENATION = 312,
    MULTIPLICATION = 313,
    DIVISION = 314,
    MODULO = 315,
    LPAREN = 316,
    RPAREN = 317,
    LBRACKET = 318,
    RBRACKET = 319,
    UNARY = 320,
    INCREMENT = 321,
    DECREMENT = 322,
    POWER = 323
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 141 "parser/interpreter.y" /* yacc.c:355  */

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

#line 315 "interpreter.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 330 "interpreter.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1001

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  234

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   283,   283,   297,   302,   325,   336,   341,   346,   351,
     356,   361,   366,   372,   378,   384,   390,   396,   402,   408,
     413,   419,   425,   431,   438,   446,   452,   458,   464,   484,
     493,   505,   510,   519,   524,   529,   537,   545,   554,   562,
     572,   583,   594,   605,   614,   626,   633,   639,   646,   651,
     657,   664,   671,   679,   687,   693,   701,   708,   715,   720,
     727,   735,   743,   751,   759,   765,   771,   777,   783,   789,
     795,   801,   807,   813,   819,   825,   831,   837,   843,   850,
     856,   862,   869,   916,   922,   928,   934,   940,   946,   952,
     958,   964,   970,   977,   984,   995,  1000,  1012,  1017,  1027,
    1033
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "PRINT", "PRINT_STRING",
  "PRINT_ARRAY", "READ", "READ_STRING", "IF", "ELSE", "THEN", "END_IF",
  "WHILE", "DO", "END_WHILE", "FOR", "SINCE", "UNTIL", "STEP", "END_FOR",
  "REPEAT", "TYPE_OF", "DEFAULT", "SWITCH", "CASE", "END_SWITCH", "STYLE",
  "CLEAR_SCREEN_TOKEN", "PLACE_TOKEN", "LETFCURLYBRACKET",
  "RIGHTCURLYBRACKET", "PLUS_ASSIGN", "MINUS_ASSIGN", "ASSIGNMENT",
  "COMMA", "TWO_DOTS", "NUMBER", "STRING", "ARRAY", "ARRAY_ITEM", "BOOL",
  "VARIABLE", "UNDEFINED", "CONSTANT", "BUILTIN", "OR", "AND",
  "GREATER_OR_EQUAL", "LESS_OR_EQUAL", "GREATER_THAN", "LESS_THAN",
  "EQUAL", "NOT_EQUAL", "NOT", "PLUS", "MINUS", "CONCATENATION",
  "MULTIPLICATION", "DIVISION", "MODULO", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "UNARY", "INCREMENT", "DECREMENT", "POWER", "$accept",
  "program", "stmtlist", "stmt", "inc", "switch", "caselist", "case",
  "defaultcase", "block", "controlSymbol", "if", "while", "repeat", "for",
  "cond", "asgn", "print", "print_string", "print_array", "read",
  "read_string", "type_of", "clear_screen", "place", "style", "exp",
  "listOfExp", "restOfListOfExp", "create_array", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))

#define YYTABLE_NINF -37

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-37)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -65,    30,    10,   -65,   -65,   -65,   704,   704,   -40,   -28,
     -20,   -65,   -65,   -65,   -65,   -19,   -65,   -12,   -11,     5,
     -65,   -10,    33,    32,    36,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,    72,    76,    77,    83,   103,   104,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,    -8,   -65,    27,
     704,   704,   704,   704,    70,    74,   891,   891,   -65,    84,
     -37,    19,    52,    52,    86,   -65,   704,    53,   704,    56,
     704,   319,   677,   -33,   -65,   -65,   731,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -17,   -65,   -65,   704,    95,
      59,    59,   753,   -65,   -65,   704,   704,   704,   704,   704,
     704,   704,   704,   704,   704,   704,   704,   704,   704,   704,
      68,    69,    73,    87,    94,   704,   122,   120,   119,   366,
     776,   704,   799,   -65,   626,   -65,     2,    33,   -15,   -65,
     891,    97,   100,   -65,   891,   101,   102,   652,   105,   -65,
     905,   919,   933,   933,   933,   933,   933,   933,    13,    13,
      13,    59,    59,    59,    59,   -65,   -65,   -65,   -65,   -65,
     822,   -65,   -65,   704,    52,   -65,   845,   -65,   704,   731,
       6,   106,   108,   125,   134,   -65,   -65,   704,   -65,   -65,
     -65,   289,   396,   600,   166,   -65,   868,   109,   110,   -65,
     -65,   704,   704,   652,   -65,   -65,   -65,   704,   -65,    85,
     -65,   125,   134,   891,   891,   -65,   443,   554,   139,    -9,
     -65,   -65,   150,   -65,   -65,   704,   -65,   141,   142,   143,
     -65,   473,   577,   520,   -65,   -65,   -65,   -65,   -65,   116,
     212,   242,   550,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     5,     6,     0,     0,     0,     0,
       0,    38,    38,    38,    38,     0,    38,     0,     0,     0,
       3,     0,     0,     0,     0,     4,    23,    22,    17,    13,
      14,    16,    15,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,    24,    64,    65,    66,    80,    81,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    55,     0,
       0,     0,     0,     0,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,    27,    28,     7,
       8,    11,    12,     9,    10,     0,    69,    70,    95,    91,
      76,    77,     0,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,    37,    80,    81,     0,    47,
      46,     0,     0,    49,    48,     0,     0,    97,     0,    75,
      90,    89,    84,    86,    83,    85,    87,    88,    67,    68,
      92,    73,    74,    78,    79,    54,    56,    57,    58,    59,
       0,     3,     3,     0,     0,    60,     0,    63,     0,     0,
       0,     0,     0,     0,     0,    93,    94,     0,    96,    82,
      45,     0,     0,     0,     0,    31,     0,     0,     0,    99,
     100,     0,     0,    97,     3,    39,    41,     0,    42,     0,
      62,    93,    94,    50,    51,    98,     0,     0,     0,     0,
      29,    32,     0,    40,     3,     0,     3,     0,     0,     0,
      30,     0,     0,     0,     3,     3,     3,    43,     3,     0,
       0,     0,     0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -14,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
      71,   -65,   -65,   -65,   -65,   -60,   -64,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,    -6,   -65,    -5,   -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    25,    26,    27,   199,   211,   212,    28,
      62,    29,    30,    31,    32,   116,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   130,   138,   178,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    57,    58,   117,   131,   111,    71,   112,   129,   132,
      -2,     4,   133,     5,     6,     7,     8,     9,    10,    11,
     135,    59,   171,    12,    72,   136,    13,   172,   217,   218,
       3,    14,    15,    60,    16,   219,   169,    17,    18,    19,
      20,    61,    66,   187,    89,    90,    91,    92,   188,    68,
      69,   119,    21,    73,    22,    85,    74,    75,    86,    87,
     120,   113,   122,   114,   124,   170,    70,    76,    86,    87,
     134,   106,   107,   108,    77,    79,    23,    24,    78,    80,
      81,   109,   137,    63,    64,    65,    82,    67,    88,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   184,   129,    83,    84,   208,   160,
     209,   210,    93,   115,   121,   166,    94,     4,   123,     5,
       6,     7,     8,     9,    10,    11,   110,   109,   118,    12,
     155,   156,    13,   161,   162,   157,   163,    14,    15,   -33,
      16,   -33,   -33,    17,    18,    19,    20,   181,   182,   158,
     103,   104,   105,   106,   107,   108,   159,   183,    21,   191,
      22,   173,   186,   109,   174,   175,   176,   179,   192,   198,
     189,   193,   190,   201,   202,   216,   220,   224,   225,   226,
     206,     0,    23,    24,     0,   203,   204,     0,   205,     0,
       0,   207,     0,     0,     0,     0,     0,     0,     0,     0,
     221,     0,   223,     0,     0,     0,     0,     0,     0,   222,
     229,   230,   231,     4,   232,     5,     6,     7,     8,     9,
      10,    11,     0,     0,     0,    12,     0,     0,    13,     0,
       0,     0,     0,    14,    15,   -35,    16,   -35,   -35,    17,
      18,    19,    20,     4,     0,     5,     6,     7,     8,     9,
      10,    11,     0,     0,    21,    12,    22,     0,    13,     0,
       0,     0,     0,    14,    15,   -34,    16,   -34,   -34,    17,
      18,    19,    20,     0,     0,     0,     0,     0,    23,    24,
       0,     0,     0,     0,    21,     0,    22,     0,     0,     0,
       4,     0,     5,     6,     7,     8,     9,    10,    11,   194,
       0,   195,    12,     0,     0,    13,     0,     0,    23,    24,
      14,    15,     0,    16,     0,     0,    17,    18,    19,    20,
       4,     0,     5,     6,     7,     8,     9,    10,    11,     0,
       0,    21,    12,    22,     0,    13,     0,     0,     0,     0,
      14,    15,     0,    16,     0,     0,    17,    18,    19,    20,
     125,     0,     0,     0,     0,    23,    24,     0,     0,     0,
       0,    21,     0,    22,     0,     0,     0,     4,     0,     5,
       6,     7,     8,     9,    10,    11,     0,     0,     0,    12,
       0,     0,    13,     0,   164,    23,    24,    14,    15,     0,
      16,     0,     0,    17,    18,    19,    20,     4,     0,     5,
       6,     7,     8,     9,    10,    11,     0,     0,    21,    12,
      22,   196,    13,     0,     0,     0,     0,    14,    15,     0,
      16,     0,     0,    17,    18,    19,    20,     0,     0,     0,
       0,     0,    23,    24,     0,     0,     0,     0,    21,     0,
      22,     0,     0,     0,     4,     0,     5,     6,     7,     8,
       9,    10,    11,     0,     0,   213,    12,     0,     0,    13,
       0,     0,    23,    24,    14,    15,     0,    16,     0,     0,
      17,    18,    19,    20,     4,     0,     5,     6,     7,     8,
       9,    10,    11,     0,     0,    21,    12,    22,     0,    13,
       0,     0,     0,   227,    14,    15,     0,    16,     0,     0,
      17,    18,    19,    20,     0,     0,     0,     0,     0,    23,
      24,     0,     0,     0,     0,    21,     0,    22,     0,     0,
       0,     4,     0,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,    12,     0,     0,    13,     0,     0,    23,
      24,    14,    15,     0,    16,     0,   -36,    17,    18,    19,
      20,     4,     0,     5,     6,     7,     8,     9,    10,    11,
       0,     0,    21,    12,    22,     0,    13,     0,   214,     0,
     233,    14,    15,   215,    16,     0,     0,    17,    18,    19,
      20,     0,     0,     0,     0,     0,    23,    24,     0,     0,
       0,   228,    21,     0,    22,     0,     0,     0,     0,     0,
      95,    96,    97,    98,    99,   100,   101,   102,     0,   103,
     104,   105,   106,   107,   108,     0,    23,    24,   197,     0,
       0,     0,   109,    95,    96,    97,    98,    99,   100,   101,
     102,     0,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,     0,     0,     0,   109,    95,    96,    97,    98,
      99,   100,   101,   102,     0,   103,   104,   105,   106,   107,
     108,   168,     0,     0,     0,     0,     0,     0,   109,     0,
       0,     0,    95,    96,    97,    98,    99,   100,   101,   102,
       0,   103,   104,   105,   106,   107,   108,   177,     0,     0,
       0,     0,     0,     0,   109,     0,     0,     0,    95,    96,
      97,    98,    99,   100,   101,   102,     0,   103,   104,   105,
     106,   107,   108,     0,    44,    45,     0,     0,    46,   126,
     109,   127,    49,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    51,    52,     0,     0,     0,     0,    53,     0,
     128,    44,    45,    54,    55,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    51,
      52,     0,     0,     0,     0,    53,     0,     0,    44,    45,
      54,    55,    46,   126,     0,   127,    49,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,     0,     0,
       0,     0,    53,     0,     0,     0,     0,    54,    55,    95,
      96,    97,    98,    99,   100,   101,   102,     0,   103,   104,
     105,   106,   107,   108,     0,   139,     0,     0,     0,     0,
       0,   109,    95,    96,    97,    98,    99,   100,   101,   102,
       0,   103,   104,   105,   106,   107,   108,     0,   165,     0,
       0,     0,     0,     0,   109,    95,    96,    97,    98,    99,
     100,   101,   102,     0,   103,   104,   105,   106,   107,   108,
       0,   167,     0,     0,     0,     0,     0,   109,    95,    96,
      97,    98,    99,   100,   101,   102,     0,   103,   104,   105,
     106,   107,   108,     0,   180,     0,     0,     0,     0,     0,
     109,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,   104,   105,   106,   107,   108,     0,   185,     0,     0,
       0,     0,     0,   109,    95,    96,    97,    98,    99,   100,
     101,   102,     0,   103,   104,   105,   106,   107,   108,     0,
     200,     0,     0,     0,     0,     0,   109,    95,    96,    97,
      98,    99,   100,   101,   102,     0,   103,   104,   105,   106,
     107,   108,    96,    97,    98,    99,   100,   101,   102,   109,
     103,   104,   105,   106,   107,   108,     0,    97,    98,    99,
     100,   101,   102,   109,   103,   104,   105,   106,   107,   108,
       0,   -37,   -37,   -37,   -37,   -37,   -37,   109,   103,   104,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
       0,   109
};

static const yytype_int16 yycheck[] =
{
       6,     7,    42,    63,    37,    42,    20,    44,    72,    42,
       0,     1,    76,     3,     4,     5,     6,     7,     8,     9,
      37,    61,    37,    13,    34,    42,    16,    42,    37,    38,
       0,    21,    22,    61,    24,    44,    34,    27,    28,    29,
      30,    61,    61,    37,    50,    51,    52,    53,    42,    61,
      61,    65,    42,    63,    44,    63,    66,    67,    66,    67,
      66,    42,    68,    44,    70,    63,    61,    34,    66,    67,
      76,    58,    59,    60,    42,     3,    66,    67,    42,     3,
       3,    68,    88,    12,    13,    14,     3,    16,    61,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   164,   169,     3,     3,    23,   115,
      25,    26,    42,    61,    61,   121,    42,     1,    62,     3,
       4,     5,     6,     7,     8,     9,    42,    68,    42,    13,
      62,    62,    16,    11,    14,    62,    17,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,   161,   162,    62,
      55,    56,    57,    58,    59,    60,    62,   163,    42,    34,
      44,    64,   168,    68,    64,    64,    64,    62,    34,     3,
      64,   177,    64,    64,    64,    36,    26,    36,    36,    36,
     194,    -1,    66,    67,    -1,   191,   192,    -1,   193,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,    -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,   215,
     224,   225,   226,     1,   228,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    13,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    42,    13,    44,    -1,    16,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    42,    -1,    44,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    16,    -1,    -1,    66,    67,
      21,    22,    -1,    24,    -1,    -1,    27,    28,    29,    30,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    42,    13,    44,    -1,    16,    -1,    -1,    -1,    -1,
      21,    22,    -1,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    42,    -1,    44,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    13,
      -1,    -1,    16,    -1,    18,    66,    67,    21,    22,    -1,
      24,    -1,    -1,    27,    28,    29,    30,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    42,    13,
      44,    15,    16,    -1,    -1,    -1,    -1,    21,    22,    -1,
      24,    -1,    -1,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    42,    -1,
      44,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    16,
      -1,    -1,    66,    67,    21,    22,    -1,    24,    -1,    -1,
      27,    28,    29,    30,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    42,    13,    44,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    -1,    -1,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    42,    -1,    44,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    13,    -1,    -1,    16,    -1,    -1,    66,
      67,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      30,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    42,    13,    44,    -1,    16,    -1,    14,    -1,
      20,    21,    22,    19,    24,    -1,    -1,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    14,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    -1,    66,    67,    18,    -1,
      -1,    -1,    68,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    35,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    -1,    37,    38,    -1,    -1,    41,    42,
      68,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      63,    37,    38,    66,    67,    41,    42,    -1,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    37,    38,
      66,    67,    41,    42,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    68,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    68,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    47,    48,    49,    50,    51,    52,    53,    68,
      55,    56,    57,    58,    59,    60,    -1,    48,    49,    50,
      51,    52,    53,    68,    55,    56,    57,    58,    59,    60,
      -1,    48,    49,    50,    51,    52,    53,    68,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,    71,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    13,    16,    21,    22,    24,    27,    28,    29,
      30,    42,    44,    66,    67,    72,    73,    74,    78,    80,
      81,    82,    83,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    98,    37,    38,    41,    42,    44,    45,
      54,    55,    56,    61,    66,    67,    95,    95,    42,    61,
      61,    61,    79,    79,    79,    79,    61,    79,    61,    61,
      61,    71,    34,    63,    66,    67,    34,    42,    42,     3,
       3,     3,     3,     3,     3,    63,    66,    67,    61,    95,
      95,    95,    95,    42,    42,    46,    47,    48,    49,    50,
      51,    52,    53,    55,    56,    57,    58,    59,    60,    68,
      42,    42,    44,    42,    44,    61,    84,    84,    42,    71,
      95,    61,    95,    62,    95,    31,    42,    44,    63,    85,
      95,    37,    42,    85,    95,    37,    42,    95,    96,    62,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    62,    62,    62,    62,    62,
      95,    11,    14,    17,    18,    62,    95,    62,    35,    34,
      63,    37,    42,    64,    64,    64,    64,    35,    97,    62,
      62,    71,    71,    95,    84,    62,    95,    37,    42,    64,
      64,    34,    34,    95,    10,    12,    15,    18,     3,    75,
      62,    64,    64,    95,    95,    97,    71,    95,    23,    25,
      26,    76,    77,    12,    14,    19,    36,    37,    38,    44,
      26,    71,    95,    71,    36,    36,    36,    20,    14,    71,
      71,    71,    71,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    76,    77,    78,    79,    80,
      80,    81,    82,    83,    83,    84,    85,    85,    85,    85,
      85,    85,    86,    87,    88,    88,    89,    89,    90,    90,
      91,    92,    93,    94,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    96,    96,    97,    97,    98,
      98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     7,
       8,     0,     2,     4,     4,     4,     3,     3,     0,     6,
       8,     6,     6,    10,    12,     3,     3,     3,     3,     3,
       6,     6,     2,     2,     4,     2,     4,     4,     4,     4,
       4,     3,     6,     4,     1,     1,     1,     3,     3,     2,
       2,     2,     2,     3,     3,     3,     2,     2,     3,     3,
       1,     1,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     4,     4,     0,     2,     0,     3,     5,
       5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 284 "parser/interpreter.y" /* yacc.c:1646  */
    { 
		    // Create a new AST
			(yyval.prog) = new lp::AST((yyvsp[0].stmts)); 

			// Assign the AST to the root
			root = (yyval.prog); 

			// End of parsing
			//	return 1;
		  }
#line 1735 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 297 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// create a empty list of statements
			(yyval.stmts) = new std::list<lp::Statement *>(); 
		  }
#line 1744 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 303 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// copy up the list and add the stmt to it
			(yyval.stmts) = (yyvsp[-1].stmts);
			(yyval.stmts)->push_back((yyvsp[0].st));

			// Control the interative mode of execution of the interpreter
			if (interactiveMode == true && control == 0)
 			{
				for(std::list<lp::Statement *>::iterator it = (yyval.stmts)->begin(); 
						it != (yyval.stmts)->end(); 
						it++)
				{
                    //(*it)->print(); 
					(*it)->evaluate();
					
				}

				// Delete the AST code, because it has already run in the interactive mode.
				(yyval.stmts)->clear();
			}
		}
#line 1770 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 326 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			 // just copy up the stmtlist when an error occurs
			 (yyval.stmts) = (yyvsp[-1].stmts);

			 // The previous look-ahead token ought to be discarded with `yyclearin;'
			 yyclearin; 
       }
#line 1782 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 337 "parser/interpreter.y" /* yacc.c:1646  */
    {
		// Create a new empty statement node
		(yyval.st) = new lp::EmptyStmt(); 
	  }
#line 1791 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 342 "parser/interpreter.y" /* yacc.c:1646  */
    {
		// Default action
		// $$ = $1;
	  }
#line 1800 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 347 "parser/interpreter.y" /* yacc.c:1646  */
    {
		// Default action
		// $$ = $1;
	  }
#line 1809 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 352 "parser/interpreter.y" /* yacc.c:1646  */
    {
		// Default action
		// $$ = $1;
	  }
#line 1818 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 357 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Default action
			// $$ = $1;
		}
#line 1827 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 362 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Default action
			// $$ = $1;
		}
#line 1836 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 367 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Default action
			// $$ = $1;
		}
#line 1845 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 373 "parser/interpreter.y" /* yacc.c:1646  */
    {
		// Default action
		// $$ = $1;
	 }
#line 1854 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 379 "parser/interpreter.y" /* yacc.c:1646  */
    {
		// Default action
		// $$ = $1;
	 }
#line 1863 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 385 "parser/interpreter.y" /* yacc.c:1646  */
    {
		// Default action
		// $$ = $1;
	 }
#line 1872 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 391 "parser/interpreter.y" /* yacc.c:1646  */
    {
		// Default action
		// $$ = $1;
	 }
#line 1881 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 397 "parser/interpreter.y" /* yacc.c:1646  */
    {
		// Default action
		// $$ = $1;
	 }
#line 1890 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 403 "parser/interpreter.y" /* yacc.c:1646  */
    {
		 // Default action
		 // $$ = $1;
	 }
#line 1899 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 409 "parser/interpreter.y" /* yacc.c:1646  */
    {
		 // Default action
		 // $$ = $1;
	 }
#line 1908 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 414 "parser/interpreter.y" /* yacc.c:1646  */
    {
		 // Default action
		 // $$ = $1;
	 }
#line 1917 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 420 "parser/interpreter.y" /* yacc.c:1646  */
    {
		 // Default action
		 // $$ = $1;
	 }
#line 1926 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 426 "parser/interpreter.y" /* yacc.c:1646  */
    {
		 // Default action
		 // $$ = $1;
	 }
#line 1935 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 432 "parser/interpreter.y" /* yacc.c:1646  */
    {
		 // Default action
		 // $$ = $1;
	 }
#line 1944 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 439 "parser/interpreter.y" /* yacc.c:1646  */
    {
		 // Default action
		 // $$ = $1;
	 }
#line 1953 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 447 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// Create a new IncrementNode
			(yyval.opAssignNode) = new lp::IncrementNode((yyvsp[-1].identifier), 1);
		}
#line 1962 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 453 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new IncrementNode
			(yyval.opAssignNode) = new lp::IncrementNode((yyvsp[-1].identifier), -1);
		}
#line 1971 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 459 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// Create a new IncrementNode
			(yyval.opAssignNode) = new lp::IncrementNode((yyvsp[0].identifier), 1);		 
		 }
#line 1980 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 465 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new IncrementNode
			(yyval.opAssignNode) = new lp::IncrementNode((yyvsp[0].identifier), -1);
		}
#line 1989 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 485 "parser/interpreter.y" /* yacc.c:1646  */
    {	
		// Create a new do statement node
		(yyval.switchCase) = new lp::BlockSwitchCaseNode((yyvsp[-3].expNode), (yyvsp[-1].cases));

		// To control the interactive mode
		control--;
	}
#line 2001 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 494 "parser/interpreter.y" /* yacc.c:1646  */
    {	
		// Create a new do statement node
		(yyval.switchCase) = new lp::BlockSwitchCaseNode((yyvsp[-4].expNode), (yyvsp[-2].cases), (yyvsp[-1].individualCase));
		
		// To control the interactive mode
		control--;
	}
#line 2013 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 505 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// create a empty list of cases for switch-case
			(yyval.cases) = new std::list<lp::CaseNode *>(); 
		  }
#line 2022 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 511 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// copy up the list and add the case to it
			(yyval.cases) = (yyvsp[-1].cases);
			(yyval.cases)->push_back((yyvsp[0].individualCase));
		}
#line 2032 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 520 "parser/interpreter.y" /* yacc.c:1646  */
    {	
		  	lp::ExpNode * exp = new lp::NumberNode((yyvsp[-2].number));
			(yyval.individualCase) = new lp::CaseNode(exp, (yyvsp[0].stmts));
	  }
#line 2041 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 525 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  	lp::ExpNode * exp = new lp::ConstantNode((yyvsp[-2].identifier));
			(yyval.individualCase) = new lp::CaseNode(exp, (yyvsp[0].stmts));
	  }
#line 2050 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 530 "parser/interpreter.y" /* yacc.c:1646  */
    {
			lp::ExpNode * exp = new lp::StringNode((yyvsp[-2].string));
			(yyval.individualCase) = new lp::CaseNode(exp, (yyvsp[0].stmts));
	  }
#line 2059 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 538 "parser/interpreter.y" /* yacc.c:1646  */
    {
				// Create a new case node
				(yyval.individualCase) = new lp::CaseNode(NULL, (yyvsp[0].stmts));
			}
#line 2068 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 546 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new block of statements node
			(yyval.st) = new lp::BlockStmt((yyvsp[-1].stmts)); 
		}
#line 2077 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 554 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// To control the interactive mode in "if" and "while" sentences
			control++;
		}
#line 2086 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 563 "parser/interpreter.y" /* yacc.c:1646  */
    {
		// Create a new if statement node
		(yyval.st) = new lp::IfStmt((yyvsp[-3].expNode), (yyvsp[-1].stmts));

		// To control the interactive mode
		control--;
	}
#line 2098 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 573 "parser/interpreter.y" /* yacc.c:1646  */
    {
		// Create a new if statement node
		(yyval.st) = new lp::IfStmt((yyvsp[-5].expNode), (yyvsp[-3].stmts), (yyvsp[-1].stmts));

		// To control the interactive mode
		control--;
	 }
#line 2110 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 584 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new while statement node
			(yyval.st) = new lp::WhileStmt((yyvsp[-3].expNode), (yyvsp[-1].stmts));

			// To control the interactive mode
			control--;
    }
#line 2122 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 595 "parser/interpreter.y" /* yacc.c:1646  */
    {	
		// Create a new do statement node
		(yyval.st) = new lp::RepeatStmt((yyvsp[-3].stmts), (yyvsp[-1].expNode));

		// To control the interactive mode
		control--;
	}
#line 2134 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 606 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new for statement node
			(yyval.st) = new lp::ForStmt((yyvsp[-7].identifier), (yyvsp[-5].expNode), (yyvsp[-3].expNode), (yyvsp[-1].stmts));

			// To control the interactive mode
			control--;
    	}
#line 2146 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 615 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new for statement node
			(yyval.st) = new lp::ForStmt((yyvsp[-9].identifier), (yyvsp[-7].expNode), (yyvsp[-5].expNode), (yyvsp[-1].stmts), (yyvsp[-3].expNode));

			// To control the interactive mode
			control--;
		}
#line 2158 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 627 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			(yyval.expNode) = (yyvsp[-1].expNode);
		}
#line 2166 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 634 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].identifier), (yyvsp[0].expNode));
		}
#line 2175 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 640 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].identifier), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2184 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 647 "parser/interpreter.y" /* yacc.c:1646  */
    {   
 			execerror("Semantic error in assignment: it is not allowed to modify a constant ", (yyvsp[-2].identifier));
		}
#line 2192 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 652 "parser/interpreter.y" /* yacc.c:1646  */
    {   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a constant ",(yyvsp[-2].identifier));
		}
#line 2200 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 658 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentArrayStmt((yyvsp[-5].identifier), (yyvsp[-3].number), (yyvsp[0].expNode));
		}
#line 2209 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 665 "parser/interpreter.y" /* yacc.c:1646  */
    {
			(yyval.st) = new lp::AssignmentArrayStmt((yyvsp[-5].identifier), (yyvsp[-3].identifier), (yyvsp[0].expNode));
		}
#line 2217 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 672 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new print node
			 (yyval.st) = new lp::PrintStmt((yyvsp[0].expNode));
		}
#line 2226 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 680 "parser/interpreter.y" /* yacc.c:1646  */
    {	
				   // Create a new print node
			 		(yyval.st) = new lp::PrintStringStmt((yyvsp[0].expNode));
			   }
#line 2235 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 688 "parser/interpreter.y" /* yacc.c:1646  */
    {
				// Create a new print node
				(yyval.st) = new lp::PrintArrayStmt((yyvsp[-1].identifier));
			}
#line 2244 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 694 "parser/interpreter.y" /* yacc.c:1646  */
    {
				// Create a new print node
				(yyval.st) = new lp::PrintArrayStmt((yyvsp[0].identifier));
			}
#line 2253 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 702 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new read node
			 (yyval.st) = new lp::ReadStmt((yyvsp[-1].identifier));
		}
#line 2262 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 709 "parser/interpreter.y" /* yacc.c:1646  */
    {   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a constant ",(yyvsp[-1].identifier));
		}
#line 2270 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 716 "parser/interpreter.y" /* yacc.c:1646  */
    {
					// Create a new read_string node
					(yyval.st) = new lp::ReadStringStmt((yyvsp[-1].identifier));
				}
#line 2279 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 721 "parser/interpreter.y" /* yacc.c:1646  */
    {
					execerror("Semantic error in \"read_string statement\": it is not allowed to modify a constant ",(yyvsp[-1].identifier));
				}
#line 2287 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 728 "parser/interpreter.y" /* yacc.c:1646  */
    {
				// Create a new TypeOfStmt
				(yyval.st) = new lp::TypeOfStmt((yyvsp[-1].expNode));
			}
#line 2296 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 736 "parser/interpreter.y" /* yacc.c:1646  */
    {
					// Create a new ClearScreenStmt
					(yyval.st) = new lp::ClearScreenStmt();
				}
#line 2305 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 744 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new PlaceStmt
			(yyval.st) = new lp::PlaceStmt((yyvsp[-3].expNode), (yyvsp[-1].expNode));
		}
#line 2314 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 752 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new PlaceStmt
			(yyval.st) = new lp::StyleStmt((yyvsp[-1].expNode));
		}
#line 2323 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 760 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// Create a new number node
			(yyval.expNode) = new lp::NumberNode((yyvsp[0].number));
		}
#line 2332 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 766 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// Create a new String node
			(yyval.expNode) = new lp::StringNode((yyvsp[0].string));
		}
#line 2341 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 772 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new Bool node
			(yyval.expNode) = new lp::BoolNode((yyvsp[0].logic));
		}
#line 2350 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 778 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// Create a new plus node
			 (yyval.expNode) = new lp::PlusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		 }
#line 2359 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 784 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new minus node
			(yyval.expNode) = new lp::MinusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2368 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 790 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// Create a new IncrementNode
			//$$ = new lp::IncrementNode($1, 1);
		 }
#line 2377 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 796 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new IncrementNode
			//$$ = new lp::IncrementNode($1, -1);
		}
#line 2386 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 802 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// Create a new IncrementNode
			//$$ = new lp::IncrementNode($2, 1);		 
		 }
#line 2395 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 808 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new IncrementNode
			//$$ = new lp::IncrementNode($2, -1);
		}
#line 2404 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 814 "parser/interpreter.y" /* yacc.c:1646  */
    { 
			// Create a new multiplication node
			(yyval.expNode) = new lp::MultiplicationNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2413 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 820 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new division node	
		  (yyval.expNode) = new lp::DivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
	   }
#line 2422 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 826 "parser/interpreter.y" /* yacc.c:1646  */
    { 
		    // just copy up the expression node 
			(yyval.expNode) = (yyvsp[-1].expNode);
		 }
#line 2431 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 832 "parser/interpreter.y" /* yacc.c:1646  */
    { 
		  // Create a new unary plus node	
  		  (yyval.expNode) = new lp::UnaryPlusNode((yyvsp[0].expNode));
		}
#line 2440 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 838 "parser/interpreter.y" /* yacc.c:1646  */
    { 
		  // Create a new unary minus node	
  		  (yyval.expNode) = new lp::UnaryMinusNode((yyvsp[0].expNode));
		}
#line 2449 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 844 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new modulo node	

		  (yyval.expNode) = new lp::ModuloNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
       }
#line 2459 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 851 "parser/interpreter.y" /* yacc.c:1646  */
    { 
		  // Create a new power node	
  		  (yyval.expNode) = new lp::PowerNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2468 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 857 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new variable node	
		  (yyval.expNode) = new lp::VariableNode((yyvsp[0].identifier));
		}
#line 2477 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 863 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new constant node	
		  (yyval.expNode) = new lp::ConstantNode((yyvsp[0].identifier));

		}
#line 2487 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 870 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Get the identifier in the table of symbols as Builtin
			lp::Builtin *f= (lp::Builtin *) table.getSymbol((yyvsp[-3].identifier));

			// Check the number of parameters 
			if (f->getNParameters() ==  (int) (yyvsp[-1].parameters)->size())
			{
				switch(f->getNParameters())
				{
					case 0:
						{
							// Create a new Builtin Function with 0 parameters node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_0((yyvsp[-3].identifier));
						}
						break;

					case 1:
						{
							// Get the expression from the list of expressions
							lp::ExpNode *e = (yyvsp[-1].parameters)->front();

							// Create a new Builtin Function with 1 parameter node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_1((yyvsp[-3].identifier),e);
						}
						break;

					case 2:
						{
							// Get the expressions from the list of expressions
							lp::ExpNode *e1 = (yyvsp[-1].parameters)->front();
							(yyvsp[-1].parameters)->pop_front();
							lp::ExpNode *e2 = (yyvsp[-1].parameters)->front();

							// Create a new Builtin Function with 2 parameters node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_2((yyvsp[-3].identifier),e1,e2);
						}
						break;

					default:
				  			 execerror("Syntax error: too many parameters for function ", (yyvsp[-3].identifier));
				} 
			}
			else
	  			 execerror("Syntax error: incompatible number of parameters for function", (yyvsp[-3].identifier));
		}
#line 2537 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 917 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new "greater than" node	
 			(yyval.expNode) = new lp::GreaterThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2546 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 923 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new "greater or equal" node	
 			(yyval.expNode) = new lp::GreaterOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2555 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 929 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new "less than" node	
 			(yyval.expNode) = new lp::LessThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2564 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 935 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new "less or equal" node	
 			(yyval.expNode) = new lp::LessOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2573 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 941 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new "equal" node	
 			(yyval.expNode) = new lp::EqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2582 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 947 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new "not equal" node	
 			(yyval.expNode) = new lp::NotEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2591 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 953 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new "logic and" node	
 			(yyval.expNode) = new lp::AndNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2600 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 959 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new "logic or" node	
 			(yyval.expNode) = new lp::OrNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2609 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 965 "parser/interpreter.y" /* yacc.c:1646  */
    {
		  // Create a new "logic negation" node	
 			(yyval.expNode) = new lp::NotNode((yyvsp[0].expNode));
		}
#line 2618 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 971 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new "concatenation" node
			(yyval.expNode) = new lp::ConcatenationNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		
		}
#line 2628 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 978 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Access to an array item
			(yyval.expNode) = new lp::AccessArrayNode((yyvsp[-3].identifier), (yyvsp[-1].number));  
		   
	   }
#line 2638 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 985 "parser/interpreter.y" /* yacc.c:1646  */
    {
		   // Access to an array item
		   (yyval.expNode) = new lp::AccessArrayNode((yyvsp[-3].identifier), (yyvsp[-1].identifier));  
		}
#line 2647 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 995 "parser/interpreter.y" /* yacc.c:1646  */
    {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 2656 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1001 "parser/interpreter.y" /* yacc.c:1646  */
    {
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 2667 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1012 "parser/interpreter.y" /* yacc.c:1646  */
    {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 2676 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1018 "parser/interpreter.y" /* yacc.c:1646  */
    {
				// Get the list of expressions
				(yyval.parameters) = (yyvsp[0].parameters);
				
				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 2688 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1028 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new Array node
			(yyval.st) = new lp::CreateArrayStmt((yyvsp[-4].identifier), (yyvsp[-1].number));
		}
#line 2697 "interpreter.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1034 "parser/interpreter.y" /* yacc.c:1646  */
    {
			// Create a new Array node
			(yyval.st) = new lp::CreateArrayStmt((yyvsp[-4].identifier), (yyvsp[-1].identifier));
		}
#line 2706 "interpreter.tab.c" /* yacc.c:1646  */
    break;


#line 2710 "interpreter.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1042 "parser/interpreter.y" /* yacc.c:1906  */



