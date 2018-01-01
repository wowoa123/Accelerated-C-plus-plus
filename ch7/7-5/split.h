#ifndef SPLIT_H
#define SPLIT_H

#include <string>
#include <list>
#include <cctype>
#include <algorithm>

bool space(char c);
bool not_space(char c);
std::list<std::string> split(const std::string & str);

#endif // SPLIT_H
