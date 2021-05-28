//
// Created by dcohe on 26/05/2021.
//

#include "symbol_table.h"
#include "hw3_output.hpp"

SymbolTable::SymTableEntry::SymTableEntry(std::string type, int offset) : type(type), returnType(""), offset(offset) {}

SymbolTable::SymTableEntry::SymTableEntry(std::string returnType, std::vector<std::string> pTypes, int offset) :
returnType(returnType), pTypes(pTypes), offset(offset){}

void SymbolTable::insert(std::string name, std::string type, int offset) {
    insertionList.push_back(name);
    table.insert(std::pair<std::string, SymbolTable::SymTableEntry> (name, SymTableEntry(type, offset)));
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
    return table.find(name)->first == type || (table.find(name)->first == "int" && type == "byte");
}

bool SymbolTable::funMatchesDefInTable(std::string name, std::string retType, std::vector<std::string> pTypes) {
    auto& fun = table.find(name)->second;
    if(fun.returnType != retType || fun.pTypes.size() != pTypes.size()) return false;
    for(size_t i = 0; i < pTypes.size(); i++){
        if(fun.pTypes[i] != pTypes[i] && !(fun.pTypes[i] == "int" && pTypes[i] == "byte")) return false;
    }
    return true;
}
bool SymbolTable::isfunction(std::string name) {
    return table.find(name)->second.returnType == "";
}
