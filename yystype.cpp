//
// Created by dcohe on 26/05/2021.
//

#include "yystype.h"

Num::Num(int val) : Node(val, true, "", "int") {}
Id::Id(std::string name) : Node(0, true, name, "") {}
String::String(std::string text) : Node(0, true, text, "") {}
Type::Type(std::string name) : Node(0, true, name, "") {}
Formals::Formals(std::string name, std::string type) : Node(0, true, "", "") {
    pNames.push_back(name);
    pTypes.push_back(type);
}
Bool::Bool(bool boolVal) : Node(0, boolVal, "", "") {}


Node::Node(int val, bool boolVal, std::string name, std::string type)
: val(val), boolVal(boolVal), name(name), type(type) {
}

//Exp::Exp(std::string name) : Node() {
//
//}
