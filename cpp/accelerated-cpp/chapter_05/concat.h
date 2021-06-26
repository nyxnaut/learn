#ifndef GUARD_concat_h
#define GUARD_concat_h

#include <vector>
#include <string>


std::vector<std::string> vcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom);
std::vector<std::string> hcat(const std::vector<std::string>& left, const std::vector<std::string>& right);

#endif
