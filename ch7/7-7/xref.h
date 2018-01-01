#ifndef XREF_H
#define XREF_H

#include <map>
#include <vector>
#include <iostream>
#include <string>
#include "split.h"

std::map<std::string, std::vector<int> > xref(std::istream &in, bool &lines,
                                              std::vector<std::string> find_words(const std::string&) = split);

#endif // XREF_H
