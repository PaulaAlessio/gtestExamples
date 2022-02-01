#pragma once

#include <iostream>
#include "ClosableObject.h"

class Door: public ClosableObject
{
 public:
  void open() override
  {
    std::cout << "I am a Door being opened." << std::endl;
  }  
  void close() override
  {
    std::cout << "I am a Door being closed." << std::endl;
  }

  virtual ~Door() = default;

};
