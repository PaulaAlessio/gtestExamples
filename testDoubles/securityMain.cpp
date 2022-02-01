#include <memory>

#include "Security.h"

int main()
{
  auto window = std::make_unique<Window>();
  auto door = std::make_unique<Door>();

  Security security(std::move(window), std::move(door));
  security.on();
  security.off();

  return 0;
}  
