//
// Created by dcohe on 26/05/2021.
//

#ifndef PROJECTNAME_SYMBOL_TABLE_H
#define PROJECTNAME_SYMBOL_TABLE_H

#include <vector>
#include <map>
#include <utility>
#include <string>


typedef std::vector<std::pair<std::string, std::string>> ParamList;


class SymbolTable{
    struct SymTableEntry{
        std::string type;
        std::string returnType;
        ParamList params;
        int offset;

        SymTableEntry(std::string type, int offset);
        SymTableEntry(std::string returnType, ParamList params, int offset);
    };

    std::map<std::string, SymTableEntry> table;
    void getParamTypes(ParamList, std::vector<string>&);

public:

    void printTable();
    void insert(std::string name, std::string type, int offset);
    void insert(std::string name, std::string returnType, std::vector<std::string> pNames, std::vector<std::string> pTypes, int offset);




};

#endif //PROJECTNAME_SYMBOL_TABLE_H
