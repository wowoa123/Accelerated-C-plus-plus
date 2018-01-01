#ifndef GRAMMER_H
#define GRAMMER_H

#include <list>
#include <string>
#include <map>
#include <iostream>
#include "split.h"
#include <stdexcept>

typedef std::list<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammer;

Grammer read_grammer(std::istream &in);
std::list<std::string> gen_sentence(const Grammer &g);
bool bracketed(const std::string &s);
void gen_aux(const Grammer &g, const std::string &word,
             std::list<std::string> &ret);
int nrand(int n);

#endif // GRAMMER_H
