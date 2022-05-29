/*
Jason Zhang
11/13/2019
*/

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

//Media constructer
Media::Media(char* newTitle, int newYear) {
  title = new char[strlen(newTitle)+1];
  strcpy(title, newTitle);
  year = newYear;
}
//get title
char* Media::getTitle(){
  return title;
}
//get year
int Media::getYear(){
  return year;
}
//get type
int Media::getType(){
}
//deconstructor
Media::~Media(){
  delete[] title;
}
