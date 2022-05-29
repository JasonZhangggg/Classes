/*
Jason Zhang
10/13/2019
*/

#include <iostream>
#include "VideoGame.h"
#include "Media.h"
#include <cstring>
using namespace std;

VideoGame::VideoGame(char* title, int year, char* newPublisher, int newRating): Media(title, year){
  publisher = new char[strlen(newPublisher)+1];
  strcpy(publisher, newPublisher);
  rating = newRating;
}
char* VideoGame:: getPublisher(){
  return publisher;
}
int VideoGame:: getRating(){
  return rating;
}
int VideoGame:: getType(){
  return 1;
}

VideoGame::~VideoGame(){
  delete publisher;
}
