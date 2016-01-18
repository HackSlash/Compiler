// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Take the name prefix into account.
#define yylex   examplelex

// First part of user declarations.
#line 4 "parser.yy" // lalr1.cc:404
 /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>

#include "expression.h"
#include "tree.h"


#line 49 "parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.h"

// User implementation prologue.
#line 182 "parser.yy" // lalr1.cc:412


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


#line 75 "parser.tab.cc" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace example {
#line 161 "parser.tab.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg, std::vector<classdeclNode*> & classes_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg),
      classes (classes_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 44 "parser.yy" // lalr1.cc:741
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 541 "parser.tab.cc" // lalr1.cc:741

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 198 "parser.yy" // lalr1.cc:859
    {}
#line 651 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 199 "parser.yy" // lalr1.cc:859
    {}
#line 657 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 201 "parser.yy" // lalr1.cc:859
    {classes.push_back((yystack_[0].value.classdecl));}
#line 663 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 202 "parser.yy" // lalr1.cc:859
    {classes.push_back((yystack_[1].value.classdecl));}
#line 669 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 205 "parser.yy" // lalr1.cc:859
    {(yylhs.value.classdecl) = new classdeclNode((yystack_[2].value.type),(yystack_[1].value.varformals),(yystack_[0].value.classbody));}
#line 675 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 206 "parser.yy" // lalr1.cc:859
    {(yylhs.value.classdecl) = new classdeclNode((yystack_[5].value.type),(yystack_[4].value.varformals),(yystack_[2].value.type),(yystack_[1].value.actuals),(yystack_[0].value.classbody));}
#line 681 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 207 "parser.yy" // lalr1.cc:859
    {(yylhs.value.classdecl) = new classdeclNode((yystack_[4].value.type),(yystack_[3].value.varformals),new typeNode(-1),NULL,(yystack_[0].value.classbody));}
#line 687 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 210 "parser.yy" // lalr1.cc:859
    {(yylhs.value.varformals) = new varformalsNode();}
#line 693 "parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 211 "parser.yy" // lalr1.cc:859
    {(yylhs.value.varformals) = new varformalsNode((yystack_[1].value.varform));}
#line 699 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 214 "parser.yy" // lalr1.cc:859
    {(yylhs.value.varform) = new varformNode((yystack_[2].value.id),(yystack_[0].value.type));}
#line 705 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 215 "parser.yy" // lalr1.cc:859
    {(yylhs.value.varform) = new varformNode((yystack_[5].value.varform),(yystack_[2].value.id),(yystack_[0].value.type));}
#line 711 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 218 "parser.yy" // lalr1.cc:859
    {(yylhs.value.classbody) = new classbodyNode((yystack_[1].value.features));}
#line 717 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 221 "parser.yy" // lalr1.cc:859
    {(yylhs.value.features) = NULL;}
#line 723 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 222 "parser.yy" // lalr1.cc:859
    {(yylhs.value.features) = new featuresNode(false,(yystack_[8].value.features),(yystack_[6].value.id),(yystack_[5].value.formals),(yystack_[3].value.type),(yystack_[1].value.expr));}
#line 729 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 223 "parser.yy" // lalr1.cc:859
    {(yylhs.value.features) = new featuresNode(true,(yystack_[9].value.features),(yystack_[6].value.id),(yystack_[5].value.formals),(yystack_[3].value.type),(yystack_[1].value.expr));}
#line 735 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 224 "parser.yy" // lalr1.cc:859
    {(yylhs.value.features) = new featuresNode(false,(yystack_[8].value.features),(yystack_[6].value.id),(yystack_[5].value.formals),(yystack_[3].value.type));}
#line 741 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 225 "parser.yy" // lalr1.cc:859
    {(yylhs.value.features) = new featuresNode(true,(yystack_[9].value.features),(yystack_[6].value.id),(yystack_[5].value.formals),(yystack_[3].value.type));}
#line 747 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 226 "parser.yy" // lalr1.cc:859
    {(yylhs.value.features) = new featuresNode((yystack_[5].value.features),(yystack_[3].value.id));}
#line 753 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 227 "parser.yy" // lalr1.cc:859
    {(yylhs.value.features) = new featuresNode((yystack_[7].value.features),(yystack_[5].value.id),(yystack_[3].value.type),(yystack_[1].value.expr))}
#line 759 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 228 "parser.yy" // lalr1.cc:859
    {(yylhs.value.features) = new featuresNode((yystack_[4].value.features),(yystack_[2].value.block));}
#line 765 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 231 "parser.yy" // lalr1.cc:859
    {(yylhs.value.formals) = new formalsNode();}
#line 771 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 232 "parser.yy" // lalr1.cc:859
    {(yylhs.value.formals) = new formalsNode((yystack_[1].value.form));}
#line 777 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 235 "parser.yy" // lalr1.cc:859
    {(yylhs.value.form) = new formNode((yystack_[2].value.id),(yystack_[0].value.type));}
#line 783 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 236 "parser.yy" // lalr1.cc:859
    {(yylhs.value.form) = new formNode((yystack_[4].value.form),(yystack_[2].value.id),(yystack_[0].value.type));}
#line 789 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 239 "parser.yy" // lalr1.cc:859
    {(yylhs.value.actuals) = new actualsNode();}
#line 795 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 240 "parser.yy" // lalr1.cc:859
    {(yylhs.value.actuals) = new actualsNode((yystack_[1].value.actual));}
#line 801 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 241 "parser.yy" // lalr1.cc:859
    {genError(inv_syn,yytext,yylineno);}
#line 807 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 244 "parser.yy" // lalr1.cc:859
    {(yylhs.value.actual) = new actualNode((yystack_[0].value.expr));}
#line 813 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 245 "parser.yy" // lalr1.cc:859
    {(yylhs.value.actual) = new actualNode((yystack_[2].value.actual),(yystack_[0].value.expr));}
#line 819 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 248 "parser.yy" // lalr1.cc:859
    {}
#line 825 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 249 "parser.yy" // lalr1.cc:859
    {(yylhs.value.block) = new blockNode((yystack_[0].value.expr));}
#line 831 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 250 "parser.yy" // lalr1.cc:859
    {(yylhs.value.block) = new blockNode((yystack_[0].value.blockpt));}
#line 837 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 253 "parser.yy" // lalr1.cc:859
    {(yylhs.value.blockpt) = new blockptNode((yystack_[2].value.expr),(yystack_[0].value.expr));}
#line 843 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 254 "parser.yy" // lalr1.cc:859
    {(yylhs.value.blockpt) = new blockptNode((yystack_[2].value.expr),(yystack_[0].value.blockpt));}
#line 849 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 255 "parser.yy" // lalr1.cc:859
    {(yylhs.value.blockpt) = new blockptNode((yystack_[6].value.id),(yystack_[4].value.type),(yystack_[2].value.expr),(yystack_[0].value.expr));}
#line 855 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 256 "parser.yy" // lalr1.cc:859
    {(yylhs.value.blockpt) = new blockptNode((yystack_[6].value.id),(yystack_[4].value.type),(yystack_[2].value.expr),(yystack_[0].value.blockpt));}
#line 861 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 259 "parser.yy" // lalr1.cc:859
    {sym = yytext; (yylhs.value.id) = new idNode(yytext);}
#line 867 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 262 "parser.yy" // lalr1.cc:859
    {(yylhs.value.type) = new typeNode(yytext);}
#line 873 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 265 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(assign,(yystack_[2].value.id),(yystack_[0].value.expr));}
#line 879 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 266 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(unary_not,(yystack_[0].value.expr));}
#line 885 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 267 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(unary_minus,(yystack_[0].value.expr));}
#line 891 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 268 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(if_statement,(yystack_[4].value.expr),(yystack_[2].value.expr),(yystack_[0].value.expr));}
#line 897 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 269 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(while_loop,(yystack_[2].value.expr),(yystack_[0].value.expr));}
#line 903 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 270 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(super_call,(yystack_[1].value.id),(yystack_[0].value.actuals));}
#line 909 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 271 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(call,(yystack_[1].value.id),(yystack_[0].value.actuals));}
#line 915 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 272 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(instantiation,(yystack_[1].value.type),(yystack_[0].value.actuals));}
#line 921 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 273 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(braced_block,(yystack_[1].value.block));}
#line 927 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 274 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(par_expr,(yystack_[1].value.expr));}
#line 933 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 275 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(obj_call,(yystack_[3].value.expr),(yystack_[1].value.id),(yystack_[0].value.actuals));}
#line 939 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 276 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(match_cases,(yystack_[2].value.expr),(yystack_[0].value.cases));}
#line 945 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 277 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(cmp_lteq,(yystack_[2].value.expr),(yystack_[0].value.expr));}
#line 951 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 278 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(cmp_lt,(yystack_[2].value.expr),(yystack_[0].value.expr));}
#line 957 "parser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 279 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(cmp_eq,(yystack_[2].value.expr),(yystack_[0].value.expr));}
#line 963 "parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 280 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(multiplication,(yystack_[2].value.expr),(yystack_[0].value.expr));}
#line 969 "parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 281 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(division,(yystack_[2].value.expr),(yystack_[0].value.expr));}
#line 975 "parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 282 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(addition,(yystack_[2].value.expr),(yystack_[0].value.expr));}
#line 981 "parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 283 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(subtraction,(yystack_[2].value.expr),(yystack_[0].value.expr));}
#line 987 "parser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 284 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(null);}
#line 993 "parser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 285 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(unit);}
#line 999 "parser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 286 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(identifier,(yystack_[0].value.id));}
#line 1005 "parser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 287 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(lit_int,new IntNode(yytext));}
#line 1011 "parser.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 288 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(lit_string,new StringNode(yytext));}
#line 1017 "parser.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 289 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(lit_bool,new BoolNode(yytext));}
#line 1023 "parser.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 290 "parser.yy" // lalr1.cc:859
    {(yylhs.value.expr) = new exprNode(this_reference);}
#line 1029 "parser.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 293 "parser.yy" // lalr1.cc:859
    {(yylhs.value.cases) = new casesNode((yystack_[1].value.cas));}
#line 1035 "parser.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 296 "parser.yy" // lalr1.cc:859
    {(yylhs.value.cas) = new casNode((yystack_[4].value.id),(yystack_[2].value.type),(yystack_[0].value.block));}
#line 1041 "parser.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 297 "parser.yy" // lalr1.cc:859
    {(yylhs.value.cas) = new casNode((yystack_[6].value.cas),(yystack_[4].value.id),(yystack_[2].value.type),(yystack_[0].value.block));}
#line 1047 "parser.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 298 "parser.yy" // lalr1.cc:859
    {(yylhs.value.cas) = new casNode(new exprNode(),(yystack_[0].value.block));}
#line 1053 "parser.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 299 "parser.yy" // lalr1.cc:859
    {(yylhs.value.cas) = new casNode((yystack_[4].value.cas),new exprNode(),(yystack_[0].value.block));}
#line 1059 "parser.tab.cc" // lalr1.cc:859
    break;


#line 1063 "parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -91;

  const signed char Parser::yytable_ninf_ = -1;

  const short int
  Parser::yypact_[] =
  {
     -24,    -2,    34,   -91,   -24,   -91,     9,   -91,   -91,    40,
     -20,   -91,    44,   -21,   -12,   -91,   -91,   -91,    31,   -91,
      36,    48,    51,   -13,    -2,    44,   -91,   139,    48,    54,
      44,   160,   -91,    44,   -91,    58,    56,    60,    61,   251,
     251,   -91,    78,   -91,   -91,   -91,   -91,    -2,   188,   -91,
     160,    -9,     0,   400,   -91,    44,    62,    44,    63,   -91,
     317,     8,    -2,   -91,   251,   251,    79,    79,    44,    51,
     -91,   284,    67,   -91,   251,   251,   -91,    69,   251,   251,
     251,   251,   251,   251,   251,    44,    62,    -6,    68,    75,
      77,   160,    86,    -2,   -91,   295,   306,    51,   -91,   -91,
     -91,   400,   400,    85,   -91,    59,    59,    72,    30,    30,
      79,    79,    51,    80,   -91,    10,    81,    -2,    -2,   -91,
     -91,   317,    83,   114,   251,   251,   -91,    42,   -18,   -91,
      -2,   -91,    44,    -2,   117,   118,   -91,   251,   384,   -91,
      82,    94,    55,   -91,   125,    96,   -91,   209,   251,   328,
     251,   160,    -2,    89,   100,   230,    -2,   103,   345,   356,
     -91,   -91,   -91,    97,   160,    -2,   104,   373,   -91,   -91,
     -91,   160,   160,   -91,    99,   -91,   -91,   -91,   317,   -91,
     160,   -91
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       3,     0,     0,     2,     4,    39,     0,     1,     5,     0,
       0,     9,     0,     0,     0,    14,     6,    38,     0,    10,
       0,     0,     0,     0,     0,     0,     8,     0,     0,     0,
       0,    31,    13,     0,    11,     0,     0,     0,     0,     0,
       0,    65,     0,    59,    63,    62,    64,     0,     0,    26,
      31,     0,    61,    29,     7,     0,     0,     0,     0,    33,
      32,     0,     0,    28,     0,     0,    42,    41,     0,     0,
      60,     0,     0,    27,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,    47,    49,
      48,    30,    40,     0,    51,    52,    53,    54,    57,    58,
      55,    56,     0,     0,    22,     0,     0,     0,     0,    21,
      35,    34,     0,     0,     0,     0,    45,     0,     0,    50,
       0,    23,     0,     0,     0,     0,    19,     0,     0,    44,
       0,     0,     0,    66,     0,     0,    24,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    43,    69,     0,    31,     0,     0,     0,    25,    17,
      15,     0,    31,    70,     0,    18,    16,    37,    36,    67,
      31,    68
  };

  const short int
  Parser::yypgoto_[] =
  {
     -91,   -91,   141,   -91,   -91,   -91,    16,   -91,    66,   -91,
     -45,   -91,   -46,   -90,     5,   -14,   -25,   -91,   -91
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    10,    13,    16,    23,    88,   115,
      28,    51,    58,    59,    52,     6,    60,   104,   128
  };

  const unsigned char
  Parser::yytable_[] =
  {
      22,   120,    53,    75,    72,    14,     1,    76,   142,    29,
      34,    92,    21,    17,    66,    67,    19,    18,    15,     5,
      20,   143,    30,    71,    98,    31,    32,    33,    73,     5,
      35,   114,    74,    69,     7,    56,    27,    26,    61,    95,
      96,    93,    83,    84,    54,     9,    85,   131,    94,   101,
     102,   132,   126,   105,   106,   107,   108,   109,   110,   111,
      86,    17,    89,    17,    24,   140,   121,   129,    80,    81,
      82,    83,    84,    97,    17,    85,    25,    11,   153,   123,
      12,   177,    81,    82,    83,    84,    15,    27,    85,    55,
     112,    62,   116,    63,    68,    85,    64,    65,    87,   138,
     139,   117,    90,   134,   135,   162,   100,   103,   118,   119,
     122,   127,   149,   130,   133,   136,   144,   137,   173,   146,
     147,   148,   158,   159,   151,   161,   179,   152,   155,   156,
     167,   164,   141,   165,   181,   169,   175,   145,   163,   172,
      36,   180,   168,    37,    38,     8,   178,   154,     0,     0,
      39,   174,   113,    40,     0,     0,     0,     0,    17,    41,
      42,     0,    43,     0,    37,    38,    44,    45,    46,     0,
       0,    39,     0,    47,    40,    48,    49,    50,     0,    17,
      41,    42,     0,    43,     0,     0,     0,    44,    45,    46,
       0,     0,    37,    38,    47,     0,    48,     0,    50,    39,
      57,     0,    40,     0,     0,     0,     0,    17,    41,    42,
       0,    43,     0,    37,    38,    44,    45,    46,     0,     0,
      39,     0,    47,    40,    48,    70,    50,     0,    17,    41,
      42,     0,    43,   157,    37,    38,    44,    45,    46,     0,
       0,    39,     0,    47,    40,    48,     0,    50,     0,    17,
      41,    42,     0,    43,   166,    37,    38,    44,    45,    46,
       0,     0,    39,     0,    47,    40,    48,     0,    50,     0,
      17,    41,    42,     0,    43,     0,     0,     0,    44,    45,
      46,     0,     0,     0,     0,    47,     0,    48,     0,    50,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
      85,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,    85,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    99,    85,    77,    78,    79,    80,    81,    82,    83,
      84,     0,   124,    85,    77,    78,    79,    80,    81,    82,
      83,    84,     0,   125,    85,     0,     0,     0,     0,    91,
       0,    77,    78,    79,    80,    81,    82,    83,    84,     0,
     160,    85,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,    85,     0,     0,     0,     0,   170,     0,    77,
      78,    79,    80,    81,    82,    83,    84,     0,   171,    85,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
      85,   150,     0,     0,     0,   176,    77,    78,    79,    80,
      81,    82,    83,    84,     0,     0,    85
  };

  const short int
  Parser::yycheck_[] =
  {
      14,    91,    27,     3,    50,    25,    30,    52,    26,    22,
      24,     3,    24,    19,    39,    40,    37,    12,    38,    31,
      41,    39,    35,    48,    69,    38,    39,    40,    37,    31,
      25,    37,    41,    47,     0,    30,    36,    21,    33,    64,
      65,    33,    12,    13,    28,    36,    16,    37,    62,    74,
      75,    41,    97,    78,    79,    80,    81,    82,    83,    84,
      55,    19,    57,    19,    33,    23,    91,   112,     9,    10,
      11,    12,    13,    68,    19,    16,    40,    37,    23,    93,
      40,   171,    10,    11,    12,    13,    38,    36,    16,    35,
      85,    33,    87,    37,    16,    16,    36,    36,    36,   124,
     125,    33,    39,   117,   118,   151,    39,    38,    33,    32,
      24,    26,   137,    33,    33,    32,   130,     3,   164,   133,
       3,     3,   147,   148,    42,   150,   172,    33,     3,    33,
     155,    42,   127,    33,   180,    32,    32,   132,   152,    42,
       1,    42,   156,     4,     5,     4,   171,   142,    -1,    -1,
      11,   165,    86,    14,    -1,    -1,    -1,    -1,    19,    20,
      21,    -1,    23,    -1,     4,     5,    27,    28,    29,    -1,
      -1,    11,    -1,    34,    14,    36,    37,    38,    -1,    19,
      20,    21,    -1,    23,    -1,    -1,    -1,    27,    28,    29,
      -1,    -1,     4,     5,    34,    -1,    36,    -1,    38,    11,
      40,    -1,    14,    -1,    -1,    -1,    -1,    19,    20,    21,
      -1,    23,    -1,     4,     5,    27,    28,    29,    -1,    -1,
      11,    -1,    34,    14,    36,    37,    38,    -1,    19,    20,
      21,    -1,    23,    24,     4,     5,    27,    28,    29,    -1,
      -1,    11,    -1,    34,    14,    36,    -1,    38,    -1,    19,
      20,    21,    -1,    23,    24,     4,     5,    27,    28,    29,
      -1,    -1,    11,    -1,    34,    14,    36,    -1,    38,    -1,
      19,    20,    21,    -1,    23,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,    -1,    -1,    34,    -1,    36,    -1,    38,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      16,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    16,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    37,    16,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    37,    16,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    37,    16,    -1,    -1,    -1,    -1,    32,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      32,    16,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    32,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    32,    16,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      16,    17,    -1,    -1,    -1,    32,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    16
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    30,    44,    45,    46,    31,    58,     0,    45,    36,
      47,    37,    40,    48,    25,    38,    49,    19,    57,    37,
      41,    24,    58,    50,    33,    40,    49,    36,    53,    22,
      35,    38,    39,    40,    58,    57,     1,     4,     5,    11,
      14,    20,    21,    23,    27,    28,    29,    34,    36,    37,
      38,    54,    57,    59,    49,    35,    57,    40,    55,    56,
      59,    57,    33,    37,    36,    36,    59,    59,    16,    58,
      37,    59,    55,    37,    41,     3,    53,     6,     7,     8,
       9,    10,    11,    12,    13,    16,    57,    36,    51,    57,
      39,    32,     3,    33,    58,    59,    59,    57,    53,    37,
      39,    59,    59,    38,    60,    59,    59,    59,    59,    59,
      59,    59,    57,    51,    37,    52,    57,    33,    33,    32,
      56,    59,    24,    58,    37,    37,    53,    26,    61,    53,
      33,    37,    41,    33,    58,    58,    32,     3,    59,    59,
      23,    57,    26,    39,    58,    57,    58,     3,     3,    59,
      17,    42,    33,    23,    57,     3,    33,    24,    59,    59,
      32,    59,    55,    58,    42,    33,    24,    59,    58,    32,
      32,    32,    42,    55,    58,    32,    32,    56,    59,    55,
      42,    55
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    43,    44,    44,    45,    45,    46,    46,    46,    47,
      47,    48,    48,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    51,    51,    52,    52,    53,    53,    53,    54,
      54,    55,    55,    55,    56,    56,    56,    56,    57,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    61,    61,    61,
      61
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     0,     1,     2,     4,     7,     6,     2,
       3,     4,     6,     3,     0,     9,    10,     9,    10,     6,
       8,     5,     2,     3,     3,     5,     2,     3,     3,     1,
       3,     0,     1,     1,     3,     3,     8,     8,     1,     1,
       3,     2,     2,     7,     5,     4,     2,     3,     3,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     1,     1,     1,     1,     1,     3,     6,     7,     4,
       5
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "EQ", "IF", "WHILE", "MATCH", "LTEQ",
  "LT", "EQEQ", "ADD", "SUB", "MULT", "DIV", "EXM", "UMIN", "DOT", "ELSE",
  "W", "ID", "THIS", "SUPER", "OVERRIDE", "NULLVAL", "NATIVE", "EXTENDS",
  "CASE", "STRING", "INTEGER", "BOOL", "CLASS", "TYPE", "SEMICOLON",
  "COLON", "NEW", "DEF", "PAR_OPEN", "PAR_CLOSE", "BRACE_OPEN",
  "BRACE_CLOSE", "VAR", "COMMA", "ARROW", "$accept", "program",
  "classdecls", "classdecl", "varformals", "varform", "classbody",
  "features", "formals", "form", "actuals", "actual", "block", "blockpt",
  "id", "type", "expr", "cases", "cas", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   198,   198,   199,   201,   202,   205,   206,   207,   210,
     211,   214,   215,   218,   221,   222,   223,   224,   225,   226,
     227,   228,   231,   232,   235,   236,   239,   240,   241,   244,
     245,   248,   249,   250,   253,   254,   255,   256,   259,   262,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   293,   296,   297,   298,
     299
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
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
      35,    36,    37,    38,    39,    40,    41,    42
    };
    const unsigned int user_token_number_max_ = 297;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // example
#line 1642 "parser.tab.cc" // lalr1.cc:1167
#line 303 "parser.yy" // lalr1.cc:1168
 /*** Additional Code ***/

void example::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
