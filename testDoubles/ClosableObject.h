#pragma once

class ClosableObject
{
 public:
  virtual void open() = 0; 
  virtual void close() = 0;
  virtual ~ClosableObject() = default;
};
