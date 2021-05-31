//
// Created by dcohe on 26/05/2021.
//

#ifndef PROJECTNAME_SYMBOL_TABLE_H
#define PROJECTNAME_SYMBOL_TABLE_H

#include <vector>
#include <map>
#include <utility>
#include <string>
#include "yystype.h"


typedef std::vector<std::pair<std::string, std::string>> ParamList;


class SymbolTable{
    struct SymTableEntry{
        std::string type;
        std::string returnType;
        std::vector<std::string> pTypes;
        int val;
        int offset;

        SymTableEntry(std::string type, int val, int offset);
        SymTableEntry(std::string returnType, std::vector<std::string> pTypes , int offset);
    };

    std::map<std::string, SymTableEntry> table;
    std::vector<std::string> insertionList;
    std::string scopeType;
    void getParamTypes(ParamList, std::vector<std::string>&);

public:
    SymbolTable(const std::string &scopeType);

    void printTable();
    void insert(std::string name, std::string type, int val, int offset);
    void insert(std::string name, std::string returnType, std::vector<std::string> pTypes, int offset);
    bool existsInTable(std::string name);
    bool varMatchesDefInTable(std::string name, std::string type);
    void funMatchesDefInTable(std::string name, std::vector<std::string> pTypes);
    bool isfunction(std::string name);
    YYSTYPE getById(std::string name);
    std::string getTypeById(std::string name);
    void setVal(std::string name, int val);
    std::string getRetTypeById(std::string name);
    void checkRetMatchesFunc(std::string type);
    std::string getScopeType();
    void checkForMain();




};

#endif //PROJECTNAME_SYMBOL_TABLE_H
