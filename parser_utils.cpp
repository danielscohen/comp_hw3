//
// Created by dcohe on 26/05/2021.
//

#include "parser_utils.h"
#include "hw3_output.hpp"
#include <iostream>
#include <algorithm>
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

void addVarToSymTable(std::string type, std::string id, int val) {
    symTableStack.back().insert(id, type, val, offsetStack.back());
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

YYSTYPE funCall(std::string name, std::vector<std::string> pTypes) {
    std::reverse(pTypes.begin(), pTypes.end());
    for(SymbolTable& table : symTableStack){
        if(!table.existsInTable(name)) continue;
        if(!table.isfunction(name)){
            output::errorUndefFunc(yylineno, name);
            exit(0);
        }
        table.funMatchesDefInTable(name, pTypes);
        return new Exp(table.getRetTypeById(name));
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
    std::reverse(pNames.begin(), pNames.end());
    std::reverse(pTypes.begin(), pTypes.end());
    symTableStack.back().insert(name, retType, pTypes, 0);
    enterScopeSetup();
    for(int i = 0; i < (int)pNames.size(); i++){
        symTableStack.back().insert(pNames[i], pTypes[i], 0, -i - 1);
    }


}

void
addFunDefPrint(std::string retType, std::string name, std::vector<std::string> pNames, std::vector<std::string> pTypes) {
    symTableStack.back().insert(name, retType, pTypes, 0);
}
void printpNames(std::string pNames) {
        std::cout << "1: " << pNames << std::endl;
//    for(std::string a : pNames){
//        std::cout << "1: " << a << std::endl;
//    }

}

void checkNot(YYSTYPE y) {
    if(y->type != "BOOL"){
        output::errorMismatch(yylineno);
        exit(0);
    }
}

Node *doBinop(Node *lhs, Node *rhs, std::string op) {
    std::string lType = lhs->type;
    std::string rType = rhs->type;
    int lVal = lhs->val;
    int rVal = rhs->val;
    if((rType != "INT" && rType != "BYTE") || (lType != "INT" && lType != "BYTE")){
        output::errorMismatch(yylineno);
        exit(0);
    }
    YYSTYPE ret = new Num(0);

    if(lType == "INT" || rType == "INT"){
        ret->type = "INT";
    } else {
        ret->type = "BYTE";
    }

    if(op == "+") ret->val = lVal + rVal;
    else if (op == "-") ret->val = lVal - rVal;
    else if (op == "*") ret->val = lVal * rVal;
    else ret->val = lVal / rVal;

    if(ret->type == "BYTE" && ret->val > 255){
        output::errorByteTooLarge(yylineno, std::to_string(ret->val));
        exit(0);
    }

    return ret;
}

void checkBool(Node *lhs, Node *rhs) {
    if(lhs->type != "BOOL" || rhs->type != "BOOL"){
        output::errorMismatch(yylineno);
        exit(0);
    }
}

void checkRelop(Node *lhs, Node *rhs) {
    if(( lhs->type != "INT" && lhs->type != "BYTE" ) && ( rhs->type != "INT" && rhs->type != "BYTE" )){
        output::errorMismatch(yylineno);
        exit(0);
    }
}

Node *getById(Node *id) {
    std::string name = id->name;
    for(SymbolTable& table : symTableStack){
        if(!table.existsInTable(name)) continue;
        return table.getById(name);
    }
    output::errorUndef(yylineno, name);
    exit(0);
}

void checkTypeMatch(std::string type1, std::string type2) {
    if(type1 == type2 || (type1 == "INT" && type2 == "BYTE")) return;

    output::errorMismatch(yylineno);
    exit(0);
}

std::string getTypeById(std::string name) {
    for(SymbolTable& table : symTableStack){
        if(!table.existsInTable(name)) continue;
        return table.getTypeById(name);
    }
    output::errorUndef(yylineno, name);
    exit(0);
}

void changeValOfVar(std::string name, int val) {
    for(SymbolTable& table : symTableStack){
        if(!table.existsInTable(name)) continue;
        table.setVal(name, val);
    }
    output::errorUndef(yylineno, name);
    exit(0);



}

void checkRetMatchesFunc(std::string type) {
    SymbolTable gTable = symTableStack[0];
    gTable.checkRetMatchesFunc(type);

}





