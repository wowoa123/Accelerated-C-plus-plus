#ifndef a61_H
#define a61_H

#include <vector>
#include <string>

std::vector<std::string> frame(const std::vector<std::string> &v);
std::vector<std::string> hcat(const std::vector<std::string> &left,
                              const std::vector<std::string> &right);
std::string::size_type width(const std::vector<std::string> &v);

#endif // a61_H
