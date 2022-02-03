#include <string>
#include <cstdlib>
#include <algorithm>
#include "CaesarDecipheringWithInterface.h"
#include "resources.h"

// 32 spacebar
constexpr char SPACEBAR = ' ';
// A-Z: 65 - 90 (26)
constexpr char FIRSTUPPER = 'A';
// a-z: 97 - 122 (26)
constexpr char FIRSTLOWER = 'a';
// alphabetLength
constexpr char ALPHABETLENGTH = 26;

struct Resources: public IResources
{
  void *r_alloc(size_t size)
  {
    return r_alloc(size);
  }
  void r_free(void * data)
  {
    r_free(data);
  }
};


CaesarDeciphering::CaesarDeciphering(IResources &resources): m_resources(resources) { }

int CaesarDeciphering::decipher(const char* input, size_t len, size_t shift, char *output)
{
   char first = FIRSTUPPER;
   if (len == 0)  return -1;
   for (size_t i = 0; i < len; i++)
   {
     if (input[i] == SPACEBAR)
     {
       output[i] = input[i];
       continue;
     }
     first = (input[i] >= FIRSTLOWER ? FIRSTLOWER : FIRSTUPPER);
     output[i] = (input[i] - first + shift) % ALPHABETLENGTH + first;
   }
   return 0;  
} 

std::pair<int, std::string> CaesarDeciphering::decipher(std::string msg, size_t shift)
{
  // Sanity checks
  if (!std::all_of(msg.begin(), msg.end(),[](char letter) { return (std::isalpha(letter) || letter == SPACEBAR); }))
  {
    return std::make_pair(-1, std::string());
  }
  size_t size = msg.size() + 1;

  char * p = static_cast<char *>(m_resources.r_alloc(size));

  if (!p) return std::make_pair(-1, std::string());

  int ret = 0;
  if ((ret = decipher(msg.data(), size - 1, shift, p)) != 0)
  {
    m_resources.r_free(p);
    return std::make_pair(ret, std::string());
  }
  std::string result(p, size-1);
  m_resources.r_free(p);
  return {ret, result};
}

