/*
Jason Zhang
10/13/2019
*/
#include <iostream>
#include <cstring>
#include "Media.h"
using namespace std;

class VideoGame :public Media	{
 public:
  //all the functions
  VideoGame(char*, int, char*, int);
  char* getPublisher();
  int getRating();
  int getType();
  ~VideoGame();
 private:
  //all the variables
  char* publisher;
  int rating;
};
