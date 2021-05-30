//
// Created by dcohe on 26/05/2021.
//

#ifndef PROJECTNAME_YYSTYPE_H
#define PROJECTNAME_YYSTYPE_H

#include <string>
#include <vector>

struct Node {


    int val;
    std::string name;
    std::string type;
    std::vector<std::string> pNames;
    std::vector<std::string> pTypes;

    Node(int val, std::string text, std::string type);
};

struct Num : public Node {

    explicit Num(int val);

};

struct Id : public Node {
    explicit Id(std::string name);
};

struct Type : public Node {
    explicit Type(std::string name);

};

struct Exp : public Node {
    explicit Exp(std::string type);
};

struct String : public Node {
    explicit String(std::string text);
};

struct Formals : public Node {
    explicit Formals(std::string name, std::string type);
};

//struct Bool : public Node {
//    explicit Bool(bool b);
//};
#define  YYSTYPE Node*
#endif //PROJECTNAME_YYSTYPE_H
