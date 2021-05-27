//
// Created by dcohe on 26/05/2021.
//

#include "symbol_table.h"
#include "hw3_output.hpp"

SymbolTable::SymTableEntry::SymTableEntry(std::string type, int offset) : type(type), returnType(""), offset(offset) {}

SymbolTable::SymTableEntry::SymTableEntry(std::string returnType, ParamList params, int offset) :
returnType(returnType), params(params), offset(offset){}

void SymbolTable::insert(std::string name, std::string type, int offset) {
    table.insert(std::pair<std::string, SymbolTable::SymTableEntry> (name, SymTableEntry(type, offset)));

}

void SymbolTable::insert(std::string name, std::string returnType, std::vector<std::string> pNames,
                         std::vector<std::string> pTypes, int offset) {
    std::vector<std::pair<std::string, std::string>> pList;
    for(size_t i = 0; i < pNames.size(); i++ ){
        pList.push_back(std::pair<std::string, std::string>{pNames[i], pTypes[i]});
    }
    table.insert(std::pair<std::string, SymbolTable::SymTableEntry> (name, SymTableEntry(returnType, pList, offset)));

}

void SymbolTable::printTable() {

    output::endScope();
    for(auto const& x : table) {
        if (x.second.returnType == ""){
            output::printID(x.first, x.second.offset, x.second.type);
        } else {
            std::vector<string> ptypes;
            getParamTypes(x.second.params, ptypes);
            output::printID(x.first, 0, output::makeFunctionType(x.second.returnType, ptypes));
        }
    }

}

void SymbolTable::getParamTypes(ParamList p, std::vector<string>& pTypesList) {
    for(auto const& x : p) {
        pTypesList.push_back(x.second);
    }
}
