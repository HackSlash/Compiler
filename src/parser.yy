/* $Id$ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>

#include "expression.h"
#include "tree.h"

%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "program" */
%start program

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="example"

%defines "parser.h"

/* set the parser's class identifier */
%define "parser_class_name" "Parser"

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver}{std::vector<classdeclNode*> & classes}

/* verbose error messages */
%error-verbose

 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

//%union {
//    int  			integerVal;
//    double 			doubleVal;
//    std::string*		stringVal;
//    class CalcNode*		calcnode;
//}

%left EQ
%left IF WHILE
%left MATCH
%left LTEQ LT
%left EQEQ
%left ADD SUB
%left MULT DIV
%left EXM UMIN
%left DOT
%left ELSE
%left W

%union {
	StringNode* string;
	IntNode* Int;
	BoolNode* Bool;
	Node* node;
	programNode* program;
	classdeclNode* classdecl;
	varformalsNode* varformals;
	varformNode* varform;
	classbodyNode* classbody;
	featuresNode* features;
	formalsNode* formals;
	formNode* form;
	actualsNode* actuals;
	actualNode* actual;
	blockNode* block;
	blockptNode* blockpt;
	exprNode* expr;
	casesNode* cases;
	casNode* cas;
	typeNode* type;
	idNode* id;
	classdeclsNode* classdecls;
	symbol* sym;

	bool boolean;
	std::string* stdstring;
	int integer;
}

%token UMIN
%token MULT
%token DIV
%token ADD
%token SUB
%token <idVal> ID
%token EXM
%token THIS
%token SUPER
%token OVERRIDE
%token NULLVAL
%token NATIVE
%token EXTENDS
%token IF
%token ELSE
%token WHILE
%token MATCH
%token CASE
%token <stringVal> STRING
%token <intVal> INTEGER
%token <boolVal> BOOL
%token CLASS
%token <typeVal> TYPE
%token SEMICOLON
%token COLON
%token EQEQ
%token LTEQ
%token LT
%token EQ
%token NEW
%token DEF
%token PAR_OPEN
%token PAR_CLOSE
%token BRACE_OPEN
%token BRACE_CLOSE
%token VAR
%token DOT
%token COMMA
%token ARROW

//%token			END	     0	"end of file"
//%token			EOL		"end of line"
//%token <integerVal> 	INTEGER		"integer"
//%token <doubleVal> 	DOUBLE		"double"
//%token <stringVal> 	STRING		"string"

//%type <calcnode>	constant variable
//%type <calcnode>	atomexpr powexpr unaryexpr mulexpr addexpr expr

%type <program> program
%type <classdecl> classdecl
%type <varformals> varformals
%type <varform> varform
%type <classbody> classbody
%type <features> features
%type <formals> formals
%type <form> form
%type <actuals> actuals
%type <actual> actual
%type <block> block
%type <blockpt> blockpt
%type <expr> expr
%type <cases> cases
%type <cas> cas
%type <type> type
%type <id> id
%type <classdecls> classdecls

//%destructor { delete $$; } STRING
//%destructor { delete $$; } constant variable
//%destructor { delete $$; } atomexpr powexpr unaryexpr mulexpr addexpr expr

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%% /*** Grammar Rules ***/


program		: classdecls															{}
			|/*empty*/																{}

classdecls	: classdecl																{classes.push_back($1);}
			| classdecl classdecls													{classes.push_back($1);}
			;

classdecl  	: CLASS type varformals classbody										{$$ = new classdeclNode($2,$3,$4);}
			| CLASS type varformals EXTENDS type actuals classbody					{$$ = new classdeclNode($2,$3,$5,$6,$7);}
			| CLASS type varformals EXTENDS NATIVE classbody						{$$ = new classdeclNode($2,$3,new typeNode(-1),NULL,$6);}
	        ;

varformals	: PAR_OPEN PAR_CLOSE													{$$ = new varformalsNode();}
			| PAR_OPEN varform PAR_CLOSE											{$$ = new varformalsNode($2);}
			;

varform		: VAR id COLON type														{$$ = new varformNode($2,$4);}
			| varform COMMA VAR id COLON type 										{$$ = new varformNode($1,$4,$6);}
			;

classbody	: BRACE_OPEN features BRACE_CLOSE										{$$ = new classbodyNode($2);}
			;

features	: /* empty */															{$$ = NULL;}
			| features DEF id formals COLON type EQ expr SEMICOLON					{$$ = new featuresNode(false,$1,$3,$4,$6,$8);}
			| features OVERRIDE DEF id formals COLON type EQ expr SEMICOLON			{$$ = new featuresNode(true,$1,$4,$5,$7,$9);}
			| features DEF id formals COLON type EQ NATIVE SEMICOLON				{$$ = new featuresNode(false,$1,$3,$4,$6);}
			| features OVERRIDE DEF id formals COLON type EQ NATIVE SEMICOLON		{$$ = new featuresNode(true,$1,$4,$5,$7);}
			| features VAR id EQ NATIVE SEMICOLON									{$$ = new featuresNode($1,$3);}
			| features VAR id COLON type EQ expr SEMICOLON							{$$ = new featuresNode($1,$3,$5,$7)}
			| features BRACE_OPEN block BRACE_CLOSE SEMICOLON						{$$ = new featuresNode($1,$3);}
			;

formals		: PAR_OPEN PAR_CLOSE													{$$ = new formalsNode();}
			| PAR_OPEN form PAR_CLOSE												{$$ = new formalsNode($2);}
			;

form 		: id COLON type															{$$ = new formNode($1,$3);}
			| form COMMA id COLON type 												{$$ = new formNode($1,$3,$5);}
			;

actuals		: PAR_OPEN PAR_CLOSE													{$$ = new actualsNode();}
			| PAR_OPEN actual PAR_CLOSE												{$$ = new actualsNode($2);}
			| PAR_OPEN error PAR_CLOSE												{genError(inv_syn,yytext,yylineno);}
			;

actual 		: expr																	{$$ = new actualNode($1);}
			| actual COMMA expr 													{$$ = new actualNode($1,$3);}
			;

block 		: /* empty */															{}
			| expr																	{$$ = new blockNode($1);}
			| blockpt																{$$ = new blockNode($1);}
			;

blockpt		: expr SEMICOLON expr													{$$ = new blockptNode($1,$3);}
			| expr SEMICOLON blockpt												{$$ = new blockptNode($1,$3);}
			| VAR id COLON type EQ expr SEMICOLON expr								{$$ = new blockptNode($2,$4,$6,$8);}
			| VAR id COLON type EQ expr SEMICOLON blockpt							{$$ = new blockptNode($2,$4,$6,$8);}
			;

id			: ID																	{sym = yytext; $$ = new idNode(yytext);}
			;

type		: TYPE																	{$$ = new typeNode(yytext);}
			;

expr		: id EQ expr															{$$ = new exprNode(assign,$1,$3);}
			| EXM expr																{$$ = new exprNode(unary_not,$2);}
			| SUB expr %prec UMIN													{$$ = new exprNode(unary_minus,$2);}
			| IF PAR_OPEN expr PAR_CLOSE expr ELSE expr %prec W						{$$ = new exprNode(if_statement,$3,$5,$7);}
			| WHILE PAR_OPEN expr PAR_CLOSE expr %prec W							{$$ = new exprNode(while_loop,$3,$5);}
			| SUPER DOT id actuals													{$$ = new exprNode(super_call,$3,$4);}
			| id actuals															{$$ = new exprNode(call,$1,$2);}
			| NEW type actuals														{$$ = new exprNode(instantiation,$2,$3);}
			| BRACE_OPEN block BRACE_CLOSE											{$$ = new exprNode(braced_block,$2);}
			| PAR_OPEN expr PAR_CLOSE												{$$ = new exprNode(par_expr,$2);}
			| expr DOT id actuals													{$$ = new exprNode(obj_call,$1,$3,$4);}
			| expr MATCH cases														{$$ = new exprNode(match_cases,$1,$3);}
			| expr LTEQ expr 														{$$ = new exprNode(cmp_lteq,$1,$3);}
			| expr LT expr															{$$ = new exprNode(cmp_lt,$1,$3);}
			| expr EQEQ expr														{$$ = new exprNode(cmp_eq,$1,$3);}
			| expr MULT expr														{$$ = new exprNode(multiplication,$1,$3);}
			| expr DIV expr															{$$ = new exprNode(division,$1,$3);}
			| expr ADD expr															{$$ = new exprNode(addition,$1,$3);}
			| expr SUB expr															{$$ = new exprNode(subtraction,$1,$3);}
			| NULLVAL																{$$ = new exprNode(null);}
			| PAR_OPEN PAR_CLOSE													{$$ = new exprNode(unit);}
			| id																	{$$ = new exprNode(identifier,$1);}
			| INTEGER																{$$ = new exprNode(lit_int,new IntNode(yytext));}
			| STRING																{$$ = new exprNode(lit_string,new StringNode(yytext));}
			| BOOL																	{$$ = new exprNode(lit_bool,new BoolNode(yytext));}
			| THIS																	{$$ = new exprNode(this_reference);}
			;

cases		: BRACE_OPEN cas BRACE_CLOSE 											{$$ = new casesNode($2);}
			;

cas 		: CASE id COLON type ARROW block										{$$ = new casNode($2,$4,$6);}
			| cas CASE id COLON type ARROW block									{$$ = new casNode($1,$3,$5,$7);}
			| CASE NULLVAL ARROW block 												{$$ = new casNode(new exprNode(),$4);}
			| cas CASE NULLVAL ARROW block											{$$ = new casNode($1,new exprNode(),$5);}
			;


%% /*** Additional Code ***/

void example::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
