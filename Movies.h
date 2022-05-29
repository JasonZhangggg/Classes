#include <iostream>
#include <cstring>
#include "Media.h"
using namespace std;

class Movies :public Media{
 public:
  //all the functions
  Movies(char*, int, char*, int, float);
  char* getDirector();
  int getRating();
  float getDuration();
  int getType();
  ~Movies();
 private:
  //all the variables
  int rating;
  char* director;
  float duration;
};
