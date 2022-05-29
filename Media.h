
#include <iostream>
#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H

using namespace std;

class Media {
 public:
  //all the functions
  Media (char*, int);
  virtual ~Media();
  char* getTitle();
  int getYear();
  virtual int getType();
 private:
  //all the variables
  char* title;
  int year;
  int type;
};

#endif
