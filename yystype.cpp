//
// Created by dcohe on 26/05/2021.
//

#include "yystype.h"

Num::Num(int val) : Node(val, "", "int") {}
Id::Id(std::string name) : Node(0, name, "") {}
String::String(std::string text) : Node(0, text, "") {}
Type::Type(std::string name) : Node(0, name, "") {}
Formals::Formals(std::string name, std::string type) : Node(0, "", "") {
    pNames.push_back(name);
    pTypes.push_back(type);
}


Node::Node(int val, std::string name, std::string type)
: val(val), name(name), type(type) {
}

//Exp::Exp(std::string name) : Node() {
//
//}
