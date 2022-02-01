#pragma once

#include<memory>
#include "Door.h"
#include "Window.h"

class Security
{
 private:
   std::unique_ptr<Window> window;
   std::unique_ptr<Door>   door;
   
 public:
  Security(std::unique_ptr<Window> _window, std::unique_ptr<Door> _door): 
           window(std::move(_window)), door(std::move(_door)) {}

  void on() const
  {
    std::cout << "Activating security ..." << std::endl;
    window->close();
    door->close();
    std::cout << "Security activated." << std::endl; 
  }

  void off() const
  {
    std::cout << "Deactivating security ..." << std::endl;
    window->open();
    door->open();
    std::cout << "Security deactivated." << std::endl; 
  }  
};  
