#pragma once

#include <iostream>
#include "ClosableObject.h"

class Window: public ClosableObject
{
 public:
  void open() override
  {
    std::cout << "I am a Window being opened." <<std::endl;
  }   
  void close() override
  {
    std::cout << "I am a Window being closed." <<std::endl;
  }

  virtual ~Window() = default;

};
