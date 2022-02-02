#pragma once
#include <string>
#include <cstdlib>

int caesarDecipher(const char* input, size_t len, size_t shift, char *output);
std::pair<int, std::string> caesarDecipher(std::string msg, size_t shift);
