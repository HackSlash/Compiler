/* $Id$ -*- mode: c++ -*- */
/** \file scanner.ll Define the example Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <string>

#include "scanner.h"

/* import the parser's token type into a local typedef */
typedef example::Parser::token token;
typedef example::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "ExampleFlexLexer" */
%option prefix="Example"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput 

/* enables the use of start condition stacks */
%option stack
%option yylineno

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

/** FLEX Declarations **/
CLASS_ID                            [A-Z][_A-Za-z0-9]*
ID                                  [_a-z][_A-Za-z0-9]*
SIGN                                [+|-]
INT                                 0|[1-9][0-9]*
WS                                  [" "|"\t"|"\n"|"\r"]

/** Declaration of all States **/
%s COMMENT STRING STRESCAPE CHAR CHARESCAPE TRSTRING

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

<INITIAL,COMMENT>"/*"               {
                                        if(comIndent==0)
                                            BEGIN(COMMENT);
                                        comIndent++;
                                    }
<INITIAL,COMMENT>"//"+.*$           ;
<COMMENT>[^"*/"]                    {}
<COMMENT>"*/"                       {
                                        comIndent--;
                                        if(comIndent==0) {
                                            BEGIN(INITIAL);
                                        }
                                    }
<COMMENT>.
<INITIAL>"super"                    return token::SUPER;
<INITIAL>"this"                     return token::THIS;
<INITIAL>"override"                 return token::OVERRIDE;
<INITIAL>"null"                     return token::NULLVAL;
<INITIAL>"extends"                  return token::EXTENDS;
<INITIAL>"if"                       return token::IF;
<INITIAL>"else"                     return token::ELSE;
<INITIAL>"while"                    return token::WHILE;
<INITIAL>"match"                    return token::MATCH;
<INITIAL>"case"                     return token::CASE;
<INITIAL>","                        return token::COMMA;
<INITIAL>"."                        return token::DOT;
<INITIAL>"\"\"\""                   BEGIN(TRSTRING);
<TRSTRING>"\"\"\""                  BEGIN(INITIAL); yylval.stdsting=new std::string(yytext); return token::STRING;
<TRSTRING>.                         yymore();
<INITIAL>"\""                       BEGIN(STRING);
<STRING>"\""                        BEGIN(INITIAL); yylval.stdsting=new std::string(yytext); return token::STRING;
<STRING>.                           yymore();
<INITIAL>{INT}                      yylval.integer=std::to_string(yytext); return token::INTEGER;
<INITIAL>"true"|"false"             yylval.boolean = strcmp(yytext, "true") ? true : false; return token::BOOL; 
<INITIAL>"class"                    return token::CLASS;
<INITIAL>{CLASS_ID}                 yylval.stdstring=new std::string(yytext); return token::TYPE;
<INITIAL>";"                        return token::SEMICOLON;
<INITIAL>":"                        return token::COLON;
<INITIAL>"+"                        return token::ADD;
<INITIAL>"-"                        return token::SUB;
<INITIAL>"/"                        return token::DIV;
<INITIAL>"*"                        return token::MULT;
<INITIAL>"=="                       return token::EQEQ;
<INITIAL>"=>"                       return token::ARROW;
<INITIAL>"<="                       return token::LTEQ;
<INITIAL>"<"                        return token::LT;
<INITIAL>"="                        return token::EQ;
<INITIAL>"!"                        return token::EXM;
<INITIAL>"new"                      return token::NEW;
<INITIAL>"def"                      return token::DEF;
<INITIAL>"("                        return token::PAR_OPEN;
<INITIAL>")"                        return token::PAR_CLOSE;
<INITIAL>"{"                        indent++;return token::BRACE_OPEN;
<INITIAL>"}"                        {
                                        if (indent > 0) {indent--; return token::BRACE_CLOSE;}
                                        else genError(ill_chr, (char*)"}", yylineno);
                                    }
<INITIAL>"var"                      return token::VAR;
<INITIAL>"native"                   {
                                        if (strcmp(filePath, "$CLASSHOME/lib/basic.cool")) return token::NATIVE;
                                        else genError(ill_nat, yytext, yylineno);
                                    }
<INITIAL>"abstract"                 genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"catch"                    genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"do"                       genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"final"                    genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"finally"                  genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"for"                      genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"forsome"                  genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"implicit"                 genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"import"                   genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"lazy"                     genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"object"                   genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"package"                  genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"private"                  genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"protected"                genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"requires"                 genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"return"                   genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"sealed"                   genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"throw"                    genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"trait"                    genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"try"                      genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"type"                     genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"val"                      genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"with"                     genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>"yield"                    genError(ill_key, yytext, yylineno); //Ilegal keyword
<INITIAL>{ID}                       yylval.stdstring=new std::string(yytext); return token::ID;
<*>{WS}                             {}
<*>.                                genError(ill_chr, yytext, yylineno); //Generates correct and incorrect errors.


%% /*** Additional Code ***/

namespace example {

Scanner::Scanner(std::istream* in,
		 std::ostream* out)
    : ExampleFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}

/* This implementation of ExampleFlexLexer::yylex() is required to fill the
 * vtable of the class ExampleFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int ExampleFlexLexer::yylex()
{
    std::cerr << "in ExampleFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int ExampleFlexLexer::yywrap()
{
    return 1;
}
