//
// Created by dcohe on 26/05/2021.
//

#ifndef PROJECTNAME_YYSTYPE_H
#define PROJECTNAME_YYSTYPE_H

#include <string>

struct Node {

    Node(int val, const std::string &text);

    std::string name;
    std::string type;
    int val;
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
    explicit Exp(std::string name);
};

struct String : public Node {
    explicit String(std::string text);
};
#define  YYSTYPE Node*
#endif //PROJECTNAME_YYSTYPE_H
