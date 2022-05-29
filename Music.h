/*
Jason Zhang
11/13/2019
*/
#include <iostream>
#include <cstring>
#include "Media.h"
using namespace std;

class Music :public Media {
 public:
  //all the functions
  Music(char*, int, char*, float, char*);
  char* getArtist();
  char* getPublisher();
  float getDuration();
  int getType();
  ~Music();
 private:
  //all the variables
  char* artist;
  float duration;
  char* publisher;
};







