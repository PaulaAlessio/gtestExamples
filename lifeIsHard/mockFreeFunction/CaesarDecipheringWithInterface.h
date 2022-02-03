#pragma once
#include <string>
#include <cstdlib>

struct IResources
{
  virtual void *r_alloc(size_t size) = 0;
  virtual void r_free(void * data) = 0;
};

class CaesarDeciphering
{
private:
    IResources &m_resources;
    int decipher(const char* input, size_t len, size_t shift, char *output);
public:
    explicit CaesarDeciphering(IResources& resources);
    std::pair<int, std::string> decipher(std::string msg, size_t shift);
};
