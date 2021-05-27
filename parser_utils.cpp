//
// Created by dcohe on 26/05/2021.
//

#include "parser_utils.h"
#include "hw3_output.hpp"
std::vector<SymbolTable> symTableStack;
std::vector<int> offsetStack;

void enterScopeSetup() {
    symTableStack.push_back(SymbolTable());
    if(offsetStack.empty()){
        offsetStack.push_back(0);
    }
    offsetStack.push_back(offsetStack.back());

}

void exitScopeActions() {
    symTableStack.back().printTable();
    symTableStack.pop_back();
    offsetStack.pop_back();
}

void addVarToSymTable(std::string type, std::string name) {
    symTableStack.back().insert(name, type, offsetStack.back());
    offsetStack.back()++;
}

void printProductionRule(int a) {

}

