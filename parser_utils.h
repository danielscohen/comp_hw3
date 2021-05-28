//
// Created by dcohe on 26/05/2021.
//

#ifndef PROJECTNAME_PARSER_UTILS_H
#define PROJECTNAME_PARSER_UTILS_H

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


void addVarToSymTable(std::string type, std::string name);
void addFunToSymTable(std::string retType, std::string name, std::vector<std::string> pNames);

void printpNames(std::string pNames);

#endif //PROJECTNAME_PARSER_UTILS_H
