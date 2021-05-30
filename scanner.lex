%{

/* Declarations section */
#include <stdio.h>
#include "yystype.h"
#include "parser.tab.hpp"
#include "hw3_output.hpp"
#include <iostream>
    using namespace std;
	using namespace output;
void lexError();



%}
%option yylineno
%option noyywrap
%option nounput
/*%option debug*/
/*Basic Chars and Numbers*/
Space				( )
Tab					(\t)
CR					(\r)
LF					(\n)
Digit   			([0-9])
Letter  			([a-zA-Z])
Whitespace			([\t\n\r ])
Hexa 				([0-7][0-9a-fA-F])
PrintableChars		([\x20-\x7E]|{WhiteSpace})
%%

(void)                        return VOID;
(int)                         return INT;
(byte)                        return BYTE;
(b)                           return B;
(bool)                        return BOOL;
(and)                         return AND;
(or)                          return OR;
(not)                         return NOT;
(true)                        {yylval = new Exp("BOOL"); return TRUE;}
(false)                       {yylval = new Exp("BOOL"); return FALSE;}
(return)                      return RETURN;
(if)                          return IF;
(else)                        return ELSE;
(while)                       return WHILE;
(break)                       return BREAK;
(continue)                    return CONTINUE;
(switch)					  return SWITCH;
(case)						  return CASE;
(default)					  return DEFAULT;
\:							  return COLON;
\;                            return SC;
\,                            return COMMA;
\(                            return LPAREN;
\)                            return RPAREN;
\{                            return LBRACE;
\}                            return RBRACE;
\=                            return ASSIGN;
(<)|(>)|(<=)|(>=)   return RELOP;
(==)|(!=)   return EQUALITY;
\+                         return ADD;
\-                         return SUB;
\*                         return MULT;
\/                         return DIV;
{Letter}+[0-9a-zA-Z]*	      {yylval = new Id(yytext); return ID;}
[1-9]{Digit}*|0			      {yylval = new Num(stoi(yytext)); return NUM;}
\"([^\n\r\"\\]|\\[rnt"\\])+\"  {yylval = new String(yytext); return STRING;}     
{Whitespace}|(\/\/[^\r\n]*(\r|\n|\r\n)?)				 ;
.		                    lexError();

%%

void lexError(){
    errorLex(yylineno);
    exit(0);
}

