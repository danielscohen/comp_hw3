//
// Created by dcohe on 26/05/2021.
//

#include "yystype.h"

Num::Num(int val) : Node(val, "", "") {}
Id::Id(std::string name) : Node(0, name, "") {}
String::String(std::string text) : Node(0, text, "") {}
Type::Type(std::string name) : Node(0, name) {}


Node::Node(int val, std::string name, std::string type) : val(val), name(name), type(type) {}

Exp::Exp(std::string name) {

}
