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
    std::vector<std::string> insertionList;
    void getParamTypes(ParamList, std::vector<std::string>&);

public:

    void printTable();
    void insert(std::string name, std::string type, int offset);
    void insert(std::string name, std::string returnType, std::vector<std::string> pNames, std::vector<std::string> pTypes, int offset);
    bool existsInTable(std::string name);
    bool varMatchesDefInTable(std::string name, std::string type);
    bool funMatchesDefInTable(std::string name, std::string retType, std::vector<std::string> pTypes);
    bool isfunction(std::string name);




};

#endif //PROJECTNAME_SYMBOL_TABLE_H
