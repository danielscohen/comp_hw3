//
// Created by dcohe on 26/05/2021.
//

#include "symbol_table.h"
#include "hw3_output.hpp"
#include <algorithm>
extern int yylineno;

SymbolTable::SymTableEntry::SymTableEntry(std::string type, int val, int offset) : type(type), returnType(""), val(val), offset(offset) {}

SymbolTable::SymTableEntry::SymTableEntry(std::string returnType, std::vector<std::string> pTypes, int offset) :
returnType(returnType), pTypes(pTypes), offset(offset){}

void SymbolTable::insert(std::string name, std::string type, int val, int offset) {
    insertionList.push_back(name);
    table.insert(std::pair<std::string, SymbolTable::SymTableEntry> (name, SymTableEntry(type, val, offset)));
}

void SymbolTable::insert(std::string name, std::string returnType,
                         std::vector<std::string> pTypes, int offset) {
    insertionList.push_back(name);
    table.insert(std::pair<std::string, SymbolTable::SymTableEntry> (name, SymTableEntry(returnType, pTypes, offset)));
}

void SymbolTable::printTable() {

    output::endScope();
    for(std::string& name : insertionList) {
        auto const& x = table.find(name);
        if (x->second.returnType == ""){
            output::printID(x->first, x->second.offset, x->second.type);
        } else {
            output::printID(x->first, 0, output::makeFunctionType(x->second.returnType, x->second.pTypes));
        }
    }

}

void SymbolTable::getParamTypes(ParamList p, std::vector<std::string>& pTypesList) {
    for(auto const& x : p) {
        pTypesList.push_back(x.second);
    }
}

bool SymbolTable::existsInTable(std::string name) {
    return table.count(name) != 0;
}

bool SymbolTable::varMatchesDefInTable(std::string name, std::string type) {
    return table.find(name)->first == type || (table.find(name)->first == "INT" && type == "BYTE");
}

void SymbolTable::funMatchesDefInTable(std::string name, std::vector<std::string> pTypes) {
    auto& fun = table.find(name)->second;
    if(fun.pTypes.size() != pTypes.size()) {
        output::errorPrototypeMismatch(yylineno, name, fun.pTypes);
        exit(0);
    }
    for(size_t i = 0; i < pTypes.size(); i++){
        if(fun.pTypes[i] != pTypes[i] && !(fun.pTypes[i] == "INT" && pTypes[i] == "BYTE")) {
            output::errorPrototypeMismatch(yylineno, name, fun.pTypes);
            exit(0);
        }
    }
}
bool SymbolTable::isfunction(std::string name) {
    return table.find(name)->second.returnType != "";
}

YYSTYPE SymbolTable::getById(std::string name) {
    auto& var = table.find(name)->second;
    std::string type = var.type;
    if(type == "INT"){
        return new Num(var.val);
    }
    if(type == "BYTE"){
        YYSTYPE ret = new Num(var.val);
        ret->type = "BYTE";
        return ret;
    }
    if(type == "BOOL"){
        return new Exp("BOOL");
    }
    return new Exp("STRING");
}

std::string SymbolTable::getTypeById(std::string name) {
    return table.find(name)->second.type;
}

void SymbolTable::setVal(std::string name, int val) {
    table.find(name)->second.val = val;
}

std::string SymbolTable::getRetTypeById(std::string name) {
    return table.find(name)->second.returnType;
}

void SymbolTable::checkRetMatchesFunc(std::string type) {
    if(table.find(insertionList.back())->second.returnType != type){
        output::errorMismatch(yylineno);
        exit(0);
    }
}
