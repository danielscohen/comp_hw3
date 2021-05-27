//
// Created by dcohe on 26/05/2021.
//

#ifndef PROJECTNAME_PARSER_UTILS_H
#define PROJECTNAME_PARSER_UTILS_H

#include "symbol_table.h"
#include <vector>


extern std::vector<SymbolTable> symTableStack;
extern std::vector<int> offsetStack;

std::string varType(std::string);

void enterScopeSetup();
void exitScopeActions();
void printProductionRule(int a);


void addVarToSymTable(std::string type, std::string name);

#endif //PROJECTNAME_PARSER_UTILS_H
