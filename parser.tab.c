/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "parser.y"

#include <iostream>
#include <cstdlib>
#include <vector>       
#include "ast.h"
void yyerror(const char *s);
int yylex(void);
std::vector<Function*>* programa = nullptr;

#line 81 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 4,             /* STRING_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 5,               /* CHAR_LITERAL  */
  YYSYMBOL_NUMBER = 6,                     /* NUMBER  */
  YYSYMBOL_TRUE = 7,                       /* TRUE  */
  YYSYMBOL_FALSE = 8,                      /* FALSE  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_LET = 10,                       /* LET  */
  YYSYMBOL_FN = 11,                        /* FN  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_IN = 16,                        /* IN  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_MUT = 18,                       /* MUT  */
  YYSYMBOL_I32 = 19,                       /* I32  */
  YYSYMBOL_F64 = 20,                       /* F64  */
  YYSYMBOL_BOOL = 21,                      /* BOOL  */
  YYSYMBOL_CHAR = 22,                      /* CHAR  */
  YYSYMBOL_STR = 23,                       /* STR  */
  YYSYMBOL_ASSIGN = 24,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 25,                      /* PLUS  */
  YYSYMBOL_MINUS = 26,                     /* MINUS  */
  YYSYMBOL_MULT = 27,                      /* MULT  */
  YYSYMBOL_DIV = 28,                       /* DIV  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_NOT = 31,                       /* NOT  */
  YYSYMBOL_MOD = 32,                       /* MOD  */
  YYSYMBOL_LPAREN = 33,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 34,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 35,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 36,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 37,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 38,                     /* COMMA  */
  YYSYMBOL_EQ = 39,                        /* EQ  */
  YYSYMBOL_NEQ = 40,                       /* NEQ  */
  YYSYMBOL_LEQ = 41,                       /* LEQ  */
  YYSYMBOL_GEQ = 42,                       /* GEQ  */
  YYSYMBOL_LT = 43,                        /* LT  */
  YYSYMBOL_GT = 44,                        /* GT  */
  YYSYMBOL_COLON = 45,                     /* COLON  */
  YYSYMBOL_ARROW = 46,                     /* ARROW  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_function_list = 49,             /* function_list  */
  YYSYMBOL_function = 50,                  /* function  */
  YYSYMBOL_param_list = 51,                /* param_list  */
  YYSYMBOL_param_list_nonempty = 52,       /* param_list_nonempty  */
  YYSYMBOL_param = 53,                     /* param  */
  YYSYMBOL_stmt_list = 54,                 /* stmt_list  */
  YYSYMBOL_stmt = 55,                      /* stmt  */
  YYSYMBOL_expr = 56,                      /* expr  */
  YYSYMBOL_arg_list = 57,                  /* arg_list  */
  YYSYMBOL_arg_list_nonempty = 58,         /* arg_list_nonempty  */
  YYSYMBOL_type = 59                       /* type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   576

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    75,    76,    80,    91,   105,   106,   111,
     117,   127,   136,   137,   138,   142,   145,   148,   151,   154,
     157,   160,   163,   166,   169,   172,   181,   184,   191,   194,
     197,   200,   203,   206,   209,   212,   215,   218,   221,   224,
     227,   230,   233,   236,   239,   242,   245,   248,   251,   254,
     257,   267,   268,   273,   275,   280,   281,   282,   283,   284
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "STRING_LITERAL", "CHAR_LITERAL", "NUMBER", "TRUE", "FALSE", "FLOAT",
  "LET", "FN", "IF", "ELSE", "WHILE", "FOR", "IN", "RETURN", "MUT", "I32",
  "F64", "BOOL", "CHAR", "STR", "ASSIGN", "PLUS", "MINUS", "MULT", "DIV",
  "AND", "OR", "NOT", "MOD", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "SEMICOLON", "COMMA", "EQ", "NEQ", "LEQ", "GEQ", "LT", "GT", "COLON",
  "ARROW", "$accept", "program", "function_list", "function", "param_list",
  "param_list_nonempty", "param", "stmt_list", "stmt", "expr", "arg_list",
  "arg_list_nonempty", "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,     7,    12,    -2,   -41,   -22,   -41,   -41,    14,   -30,
      15,    13,   -41,    57,    11,    14,   -41,   -41,   -41,   -41,
     -41,   -41,   252,    57,   -41,    -6,   -41,   -41,   -41,   -41,
     -41,   -41,     1,   271,   271,    50,    17,   271,   271,   252,
      90,   -41,   266,    20,   271,   271,    18,    53,    25,   286,
     306,    43,   -41,   326,    88,   346,   105,   -41,   -41,   271,
     271,   271,   271,   271,   271,   271,   -41,   271,   271,   271,
     271,   271,   271,   252,   366,   486,    27,    24,   271,    57,
      21,   252,   252,   271,   -41,   -41,   -41,   532,   532,    88,
      88,   526,   506,    88,   -41,   -41,   -41,   -41,   -41,   -41,
     139,   -41,   -41,   271,   386,    41,   271,    57,   154,   188,
     406,   -41,   486,   -41,   271,   426,    46,    54,   -41,   252,
     446,   -41,   271,    36,   203,   -41,   466,   252,   -41,   -41,
     237,   -41
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     7,     0,
       0,     8,     9,     0,     0,     0,    55,    56,    57,    58,
      59,    11,    12,     0,    10,    34,    33,    32,    28,    30,
      31,    29,     0,     0,     0,     0,     0,     0,     0,    12,
       0,    14,     0,     0,     0,    51,     0,     0,    34,     0,
       0,     0,    20,     0,    49,     0,     0,     6,    13,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,    12,     0,    53,     0,    52,     0,     0,
       0,    12,    12,     0,    19,    50,    27,    36,    37,    38,
      39,    41,    42,    40,    43,    44,    47,    48,    45,    46,
       0,    25,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     5,    54,    15,     0,     0,     0,    21,    23,    12,
       0,    16,     0,     0,     0,    17,     0,    12,    24,    18,
       0,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -41,    70,   -41,   -41,    59,   -38,   -40,   -31,
     -41,   -41,   -15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    10,    11,    12,    40,    41,    42,
      76,    77,    21
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    56,    49,    50,    46,    53,    54,    55,    43,     1,
       5,     8,     6,    74,    75,    13,    58,     9,    44,    47,
      48,    26,    27,    28,    29,    30,    31,    45,    87,    88,
      89,    90,    91,    92,    93,   100,    94,    95,    96,    97,
      98,    99,    78,   108,   109,   106,    22,   104,    37,    14,
      38,    15,   110,    51,    52,    73,    80,    23,    45,    83,
      58,   102,   103,    79,   105,   114,   107,   123,    58,    58,
     122,   127,   112,     7,    24,   115,    16,    17,    18,    19,
      20,   124,     0,   120,    58,     0,     0,     0,     0,   130,
      58,   126,   116,    25,    26,    27,    28,    29,    30,    31,
      32,     0,    33,     0,    34,    35,     0,    36,    25,    26,
      27,    28,    29,    30,    31,    32,     0,    33,     0,    34,
      35,    37,    36,    38,     0,    39,    57,    67,    68,    69,
      70,    71,    72,     0,     0,     0,    37,     0,    38,     0,
      39,    86,    25,    26,    27,    28,    29,    30,    31,    32,
       0,    33,     0,    34,    35,     0,    36,    25,    26,    27,
      28,    29,    30,    31,    32,     0,    33,     0,    34,    35,
      37,    36,    38,     0,    39,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    38,     0,    39,
     117,    25,    26,    27,    28,    29,    30,    31,    32,     0,
      33,     0,    34,    35,     0,    36,    25,    26,    27,    28,
      29,    30,    31,    32,     0,    33,     0,    34,    35,    37,
      36,    38,     0,    39,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,    38,     0,    39,   128,
      25,    26,    27,    28,    29,    30,    31,    32,     0,    33,
       0,    34,    35,     0,    36,    25,    26,    27,    28,    29,
      30,    31,    32,     0,    33,     0,    34,    35,    37,    36,
      38,     0,    39,   131,    48,    26,    27,    28,    29,    30,
      31,     0,     0,    37,     0,    38,     0,    39,     0,     0,
       0,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,     0,    37,    66,    38,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,    81,     0,     0,     0,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,    82,     0,     0,     0,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,     0,     0,    84,     0,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,    63,    64,     0,    65,     0,
      85,     0,     0,     0,     0,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,     0,     0,   101,     0,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,     0,     0,   113,     0,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,   119,     0,     0,     0,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,     0,     0,   121,     0,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,     0,     0,   125,     0,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,     0,     0,   129,     0,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,    63,     0,     0,    65,     0,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
      72,    59,    60,    61,    62,     0,     0,     0,    65,    61,
      62,     0,     0,     0,    65,    67,    68,    69,    70,    71,
      72,    67,    68,    69,    70,    71,    72
};

static const yytype_int16 yycheck[] =
{
      40,    39,    33,    34,     3,    36,    37,    38,    23,    11,
       3,    33,     0,    44,    45,    45,    56,     3,    24,    18,
       3,     4,     5,     6,     7,     8,     9,    33,    59,    60,
      61,    62,    63,    64,    65,    73,    67,    68,    69,    70,
      71,    72,    24,    81,    82,    24,    35,    78,    31,    34,
      33,    38,    83,     3,    37,    35,     3,    46,    33,    16,
     100,    34,    38,    45,    79,    24,    45,    13,   108,   109,
      24,    35,   103,     3,    15,   106,    19,    20,    21,    22,
      23,   119,    -1,   114,   124,    -1,    -1,    -1,    -1,   127,
     130,   122,   107,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    17,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    -1,    14,
      15,    31,    17,    33,    -1,    35,    36,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    31,    -1,    33,    -1,
      35,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    -1,    14,    15,    -1,    17,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    -1,    14,    15,
      31,    17,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    35,
      36,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    -1,    14,    15,    -1,    17,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    -1,    14,    15,    31,
      17,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    35,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    17,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    31,    17,
      33,    -1,    35,    36,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    31,    -1,    33,    -1,    35,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    31,    37,    33,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    37,    -1,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      34,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    37,    -1,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    37,    -1,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    37,    -1,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    37,    -1,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    37,    -1,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    25,    26,    27,    28,    -1,    -1,    -1,    32,    27,
      28,    -1,    -1,    -1,    32,    39,    40,    41,    42,    43,
      44,    39,    40,    41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    48,    49,    50,     3,     0,    50,    33,     3,
      51,    52,    53,    45,    34,    38,    19,    20,    21,    22,
      23,    59,    35,    46,    53,     3,     4,     5,     6,     7,
       8,     9,    10,    12,    14,    15,    17,    31,    33,    35,
      54,    55,    56,    59,    24,    33,     3,    18,     3,    56,
      56,     3,    37,    56,    56,    56,    54,    36,    55,    25,
      26,    27,    28,    29,    30,    32,    37,    39,    40,    41,
      42,    43,    44,    35,    56,    56,    57,    58,    24,    45,
       3,    35,    35,    16,    37,    34,    36,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      54,    37,    34,    38,    56,    59,    24,    45,    54,    54,
      56,    36,    56,    37,    24,    56,    59,    36,    36,    35,
      56,    37,    24,    13,    54,    37,    56,    35,    36,    37,
      54,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    59,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,    10,     8,     0,     1,     1,
       3,     3,     0,     2,     1,     5,     6,     7,     8,     3,
       2,     5,     9,     5,     7,     4,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     0,     1,     1,     3,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: function_list  */
#line 68 "parser.y"
      {
          programa = (yyvsp[0].function_list); 
      }
#line 1297 "parser.tab.c"
    break;

  case 3: /* function_list: function_list function  */
#line 75 "parser.y"
                             { (yyvsp[-1].function_list)->push_back((yyvsp[0].function)); (yyval.function_list) = (yyvsp[-1].function_list); }
#line 1303 "parser.tab.c"
    break;

  case 4: /* function_list: function  */
#line 76 "parser.y"
               { (yyval.function_list) = new std::vector<Function*>(); (yyval.function_list)->push_back((yyvsp[0].function)); }
#line 1309 "parser.tab.c"
    break;

  case 5: /* function: FN IDENTIFIER LPAREN param_list RPAREN ARROW type LBRACE stmt_list RBRACE  */
#line 81 "parser.y"
      {
          Function* f = new Function();
          f->name = (yyvsp[-8].id);             
          f->params = *(yyvsp[-6].param_list);          
          delete (yyvsp[-6].param_list);                
          f->ret_type = (yyvsp[-3].type_str);         
          f->body = *(yyvsp[-1].stmt_list);            
          delete (yyvsp[-1].stmt_list);                
          (yyval.function) = f;
      }
#line 1324 "parser.tab.c"
    break;

  case 6: /* function: FN IDENTIFIER LPAREN param_list RPAREN LBRACE stmt_list RBRACE  */
#line 92 "parser.y"
      {
          Function* f = new Function();
          f->name = (yyvsp[-6].id);
          f->params = *(yyvsp[-4].param_list);          
          delete (yyvsp[-4].param_list);
          f->ret_type = "";         
          f->body = *(yyvsp[-1].stmt_list);
          delete (yyvsp[-1].stmt_list);
          (yyval.function) = f;
      }
#line 1339 "parser.tab.c"
    break;

  case 7: /* param_list: %empty  */
#line 105 "parser.y"
      { (yyval.param_list) = new std::vector<std::pair<std::string,std::string>>(); }
#line 1345 "parser.tab.c"
    break;

  case 8: /* param_list: param_list_nonempty  */
#line 106 "parser.y"
                          { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1351 "parser.tab.c"
    break;

  case 9: /* param_list_nonempty: param  */
#line 112 "parser.y"
    {
        (yyval.param_list) = new std::vector<std::pair<std::string,std::string>>();
        (yyval.param_list)->push_back(*(yyvsp[0].param));
        delete (yyvsp[0].param);
    }
#line 1361 "parser.tab.c"
    break;

  case 10: /* param_list_nonempty: param_list_nonempty COMMA param  */
#line 118 "parser.y"
    {
        (yyval.param_list) = (yyvsp[-2].param_list);
        (yyval.param_list)->push_back(*(yyvsp[0].param));
        delete (yyvsp[0].param);
    }
#line 1371 "parser.tab.c"
    break;

  case 11: /* param: IDENTIFIER COLON type  */
#line 128 "parser.y"
    {
        (yyval.param) = new std::pair<std::string,std::string>((yyvsp[-2].id), (yyvsp[0].type_str));
        free((yyvsp[-2].id));
    }
#line 1380 "parser.tab.c"
    break;

  case 12: /* stmt_list: %empty  */
#line 136 "parser.y"
                               { (yyval.stmt_list) = new std::vector<Stmt*>(); }
#line 1386 "parser.tab.c"
    break;

  case 13: /* stmt_list: stmt_list stmt  */
#line 137 "parser.y"
                              { (yyvsp[-1].stmt_list)->push_back((yyvsp[0].stmt)); (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 1392 "parser.tab.c"
    break;

  case 14: /* stmt_list: stmt  */
#line 138 "parser.y"
                              { (yyval.stmt_list) = new std::vector<Stmt*>(); (yyval.stmt_list)->push_back((yyvsp[0].stmt)); }
#line 1398 "parser.tab.c"
    break;

  case 15: /* stmt: LET IDENTIFIER ASSIGN expr SEMICOLON  */
#line 143 "parser.y"
        { (yyval.stmt) = new StmtLet((yyvsp[-3].id), (yyvsp[-1].expr), nullptr, ""); }
#line 1404 "parser.tab.c"
    break;

  case 16: /* stmt: LET MUT IDENTIFIER ASSIGN expr SEMICOLON  */
#line 146 "parser.y"
        { (yyval.stmt) = new StmtLet((yyvsp[-3].id), (yyvsp[-1].expr), nullptr, "", true); }
#line 1410 "parser.tab.c"
    break;

  case 17: /* stmt: LET IDENTIFIER COLON type ASSIGN expr SEMICOLON  */
#line 149 "parser.y"
        { (yyval.stmt) = new StmtLet((yyvsp[-5].id), (yyvsp[-1].expr), (yyvsp[-3].type_str), (yyvsp[-3].type_str)); }
#line 1416 "parser.tab.c"
    break;

  case 18: /* stmt: LET MUT IDENTIFIER COLON type ASSIGN expr SEMICOLON  */
#line 152 "parser.y"
        { (yyval.stmt) = new StmtLet((yyvsp[-5].id), (yyvsp[-1].expr), (yyvsp[-3].type_str), (yyvsp[-3].type_str), true); }
#line 1422 "parser.tab.c"
    break;

  case 19: /* stmt: RETURN expr SEMICOLON  */
#line 155 "parser.y"
        { (yyval.stmt) = new StmtReturn((yyvsp[-1].expr)); }
#line 1428 "parser.tab.c"
    break;

  case 20: /* stmt: RETURN SEMICOLON  */
#line 158 "parser.y"
        { (yyval.stmt) = new StmtReturn(nullptr); }
#line 1434 "parser.tab.c"
    break;

  case 21: /* stmt: IF expr LBRACE stmt_list RBRACE  */
#line 161 "parser.y"
        { (yyval.stmt) = new StmtIf((yyvsp[-3].expr), (yyvsp[-1].stmt_list), new std::vector<Stmt*>()); }
#line 1440 "parser.tab.c"
    break;

  case 22: /* stmt: IF expr LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE  */
#line 164 "parser.y"
        { (yyval.stmt) = new StmtIf((yyvsp[-7].expr), (yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 1446 "parser.tab.c"
    break;

  case 23: /* stmt: WHILE expr LBRACE stmt_list RBRACE  */
#line 167 "parser.y"
        { (yyval.stmt) = new StmtWhile((yyvsp[-3].expr), (yyvsp[-1].stmt_list)); }
#line 1452 "parser.tab.c"
    break;

  case 24: /* stmt: FOR IDENTIFIER IN expr LBRACE stmt_list RBRACE  */
#line 170 "parser.y"
        { (yyval.stmt) = new StmtFor((yyvsp[-5].id), (yyvsp[-3].expr), (yyvsp[-1].stmt_list)); }
#line 1458 "parser.tab.c"
    break;

  case 25: /* stmt: IDENTIFIER ASSIGN expr SEMICOLON  */
#line 173 "parser.y"
        {
            Expr* assign_expr = new Expr();
            assign_expr->kind = Expr::ASSIGN;
            assign_expr->var_name = (yyvsp[-3].id); 
            assign_expr->rhs = (yyvsp[-1].expr);
            (yyval.stmt) = new StmtExpr(assign_expr);
        }
#line 1470 "parser.tab.c"
    break;

  case 26: /* stmt: expr SEMICOLON  */
#line 182 "parser.y"
        { (yyval.stmt) = new StmtExpr((yyvsp[-1].expr)); }
#line 1476 "parser.tab.c"
    break;

  case 27: /* stmt: LBRACE stmt_list RBRACE  */
#line 185 "parser.y"
        { (yyval.stmt) = new StmtBlock((yyvsp[-1].stmt_list)); }
#line 1482 "parser.tab.c"
    break;

  case 28: /* expr: NUMBER  */
#line 192 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::INT; (yyval.expr)->int_val = (yyvsp[0].num); }
#line 1488 "parser.tab.c"
    break;

  case 29: /* expr: FLOAT  */
#line 195 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::FLOAT; (yyval.expr)->float_val = (yyvsp[0].fval); }
#line 1494 "parser.tab.c"
    break;

  case 30: /* expr: TRUE  */
#line 198 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BOOL; (yyval.expr)->bool_val = true; }
#line 1500 "parser.tab.c"
    break;

  case 31: /* expr: FALSE  */
#line 201 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BOOL; (yyval.expr)->bool_val = false; }
#line 1506 "parser.tab.c"
    break;

  case 32: /* expr: CHAR_LITERAL  */
#line 204 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::CHAR; (yyval.expr)->char_val = (yyvsp[0].id)[0]; }
#line 1512 "parser.tab.c"
    break;

  case 33: /* expr: STRING_LITERAL  */
#line 207 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::STRING; (yyval.expr)->string_val = (yyvsp[0].id); }
#line 1518 "parser.tab.c"
    break;

  case 34: /* expr: IDENTIFIER  */
#line 210 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::VAR; (yyval.expr)->var_name = (yyvsp[0].id); }
#line 1524 "parser.tab.c"
    break;

  case 35: /* expr: IDENTIFIER LPAREN arg_list RPAREN  */
#line 213 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::CALL; (yyval.expr)->call.callee = (yyvsp[-3].id); (yyval.expr)->call.args = (yyvsp[-1].expr_list); }
#line 1530 "parser.tab.c"
    break;

  case 36: /* expr: expr PLUS expr  */
#line 216 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = "+"; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1536 "parser.tab.c"
    break;

  case 37: /* expr: expr MINUS expr  */
#line 219 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = "-"; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1542 "parser.tab.c"
    break;

  case 38: /* expr: expr MULT expr  */
#line 222 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = "*"; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1548 "parser.tab.c"
    break;

  case 39: /* expr: expr DIV expr  */
#line 225 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = "/"; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1554 "parser.tab.c"
    break;

  case 40: /* expr: expr MOD expr  */
#line 228 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = "%"; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1560 "parser.tab.c"
    break;

  case 41: /* expr: expr AND expr  */
#line 231 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = "&&"; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1566 "parser.tab.c"
    break;

  case 42: /* expr: expr OR expr  */
#line 234 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = "||"; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1572 "parser.tab.c"
    break;

  case 43: /* expr: expr EQ expr  */
#line 237 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = "=="; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1578 "parser.tab.c"
    break;

  case 44: /* expr: expr NEQ expr  */
#line 240 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = "!="; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1584 "parser.tab.c"
    break;

  case 45: /* expr: expr LT expr  */
#line 243 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = "<"; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1590 "parser.tab.c"
    break;

  case 46: /* expr: expr GT expr  */
#line 246 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = ">"; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1596 "parser.tab.c"
    break;

  case 47: /* expr: expr LEQ expr  */
#line 249 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = "<="; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1602 "parser.tab.c"
    break;

  case 48: /* expr: expr GEQ expr  */
#line 252 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::BINOP; (yyval.expr)->binop.left = (yyvsp[-2].expr); (yyval.expr)->binop.op = ">="; (yyval.expr)->binop.right = (yyvsp[0].expr); }
#line 1608 "parser.tab.c"
    break;

  case 49: /* expr: NOT expr  */
#line 255 "parser.y"
        { (yyval.expr) = new Expr(); (yyval.expr)->kind = Expr::UNOP; (yyval.expr)->unop.op = "!"; (yyval.expr)->unop.operand = (yyvsp[0].expr); }
#line 1614 "parser.tab.c"
    break;

  case 50: /* expr: LPAREN expr RPAREN  */
#line 258 "parser.y"
        { (yyval.expr) = (yyvsp[-1].expr); }
#line 1620 "parser.tab.c"
    break;

  case 51: /* arg_list: %empty  */
#line 267 "parser.y"
        { (yyval.expr_list) = new std::vector<Expr*>(); }
#line 1626 "parser.tab.c"
    break;

  case 52: /* arg_list: arg_list_nonempty  */
#line 269 "parser.y"
        { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 1632 "parser.tab.c"
    break;

  case 53: /* arg_list_nonempty: expr  */
#line 274 "parser.y"
        { (yyval.expr_list) = new std::vector<Expr*>(); (yyval.expr_list)->push_back((yyvsp[0].expr)); }
#line 1638 "parser.tab.c"
    break;

  case 54: /* arg_list_nonempty: arg_list_nonempty COMMA expr  */
#line 276 "parser.y"
        { (yyvsp[-2].expr_list)->push_back((yyvsp[0].expr)); (yyval.expr_list) = (yyvsp[-2].expr_list); }
#line 1644 "parser.tab.c"
    break;

  case 55: /* type: I32  */
#line 280 "parser.y"
            { (yyval.type_str) = "i32"; }
#line 1650 "parser.tab.c"
    break;

  case 56: /* type: F64  */
#line 281 "parser.y"
            { (yyval.type_str) = "f64"; }
#line 1656 "parser.tab.c"
    break;

  case 57: /* type: BOOL  */
#line 282 "parser.y"
            { (yyval.type_str) = "bool"; }
#line 1662 "parser.tab.c"
    break;

  case 58: /* type: CHAR  */
#line 283 "parser.y"
            { (yyval.type_str) = "char"; }
#line 1668 "parser.tab.c"
    break;

  case 59: /* type: STR  */
#line 284 "parser.y"
            { (yyval.type_str) = "str"; }
#line 1674 "parser.tab.c"
    break;


#line 1678 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 287 "parser.y"


void yyerror(const char *s) {
    std::cerr << "Error de sintaxis: " << s << std::endl;
}
