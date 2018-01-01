#ifndef GRAMMER_H
#define GRAMMER_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "split.h"
#include <stdexcept>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammer;

Grammer read_grammer(std::istream &in);
std::vector<std::string> gen_sentence(const Grammer &g);
bool bracketed(const std::string &s);
void gen_aux(const Grammer &g, const std::string &word,
             std::vector<std::string> &ret);
int nrand(int n);

#endif // GRAMMER_H
