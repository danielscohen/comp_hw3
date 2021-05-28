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

bool symPrevDefined(std::string name) {
    for(SymbolTable& table : symTableStack){
        if(table.existsInTable(name)) return true;
    }
    return false;
}

void defMatchesUse(std::string name, std::string type) {
    for(SymbolTable& table : symTableStack){
        if(!table.existsInTable(name)) continue;
        if(table.isfunction(name)){
            output::errorUndef(yylineno, name);
            exit(0);
        }
        if(!table.varMatchesDefInTable(name, type)){
            output::errorMismatch(yylineno);
            exit(0);
        }
    }
    output::errorMismatch(yylineno);
    exit(0);
}

void defMatchesCall(std::string name, std::string retType, std::vector<std::string> pTypes) {
    for(SymbolTable& table : symTableStack){
        if(!table.existsInTable(name)) continue;
        if(!table.isfunction(name)){
            output::errorUndefFunc(yylineno, name);
            exit(0);
        }
        if(!table.funMatchesDefInTable(name, retType, pTypes)){
            output::errorPrototypeMismatch(yylineno, name, pTypes);
            exit(0);
        }
    }
    output::errorUndefFunc(yylineno, name);
    exit(0);
}

void prevDefCheck(std::string name) {
    if(symPrevDefined(name)){
        output::errorDef(yylineno, name);
        exit(0);
    }


}

void
addFunDef(std::string retType, std::string name, std::vector<std::string> pNames, std::vector<std::string> pTypes) {
    symTableStack.back().insert(name, retType, pTypes, 0);
    enterScopeSetup();
    for(int i = 0; i < (int)pNames.size(); i++){
        symTableStack.back().insert(pNames[i], pTypes[i], -i-1);
    }


}




