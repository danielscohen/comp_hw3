%{

/* Declarations section */
#include <stdio.h>
#include "parser.tab.hpp"
#include "output.hpp"
#include <iostream>
    using namespace std;
	using namespace output;
void lexError();



%}
%option yylineno
%option noyywrap
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
(true)                        return TRUE;
(false)                       return FALSE;
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
\+|\-                         return ADDSUB;
\*|\/                         return MULTDIV;
{Letter}+[0-9a-zA-Z]*	      return ID;
[1-9]{Digit}*|0			      return NUM;
\"([^\n\r\"\\]|\\[rnt"\\])+\"       return STRING;
{Whitespace}|(\/\/[^\r\n]*(\r|\n|\r\n)?)				 ;
.		                    lexError();

%%

void lexError(){
    errorLex(yylineno);
    exit(0);
}

