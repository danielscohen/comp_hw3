//
// Created by dcohe on 26/05/2021.
//

#ifndef PROJECTNAME_PARSER_UTILS_H
#define PROJECTNAME_PARSER_UTILS_H

#include "yystype.h"
#include "symbol_table.h"
#include <vector>
#include "parser.tab.hpp"


extern std::vector<SymbolTable> symTableStack;
extern std::vector<int> offsetStack;
extern int yylineno;

bool symPrevDefined(std::string);
void defMatchesUse(std::string, std::string);
void defMatchesCall(std::string, std::string, std::vector<std::string>);

void enterScopeSetup();
void exitScopeActions();
void printProductionRule(int a);
void prevDefCheck(std::string name);
void addFunDef(std::string retType, std::string name, std::vector<std::string> pNames, std::vector<std::string> pTypes);


void addVarToSymTable(YYSTYPE var);
void addFunToSymTable(std::string retType, std::string name, std::vector<std::string> pNames);
void checkNot(YYSTYPE y);
YYSTYPE doBinop(YYSTYPE lhs, YYSTYPE rhs, std::string op);
void checkBool(YYSTYPE lhs, YYSTYPE rhs);
void checkRelop(YYSTYPE lhs, YYSTYPE rhs);
YYSTYPE getById(YYSTYPE id);

void printpNames(std::string pNames);

#endif //PROJECTNAME_PARSER_UTILS_H
