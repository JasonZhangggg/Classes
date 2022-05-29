#include <iostream>
#include "Movies.h"
#include "Media.h"
#include <cstring>
using namespace std;

Movies::Movies(char* title, int year, char* newDirector, int newRating, float newDuration): Media(title, year){
  director = new char[strlen(newDirector)+1];
  strcpy(director, newDirector);
  rating = newRating;
  duration = newDuration;
}
char* Movies:: getDirector(){
  return director;
}
int Movies:: getRating(){
  return rating;
}
float Movies:: getDuration(){
  return duration;
}

int Movies:: getType(){
  return 3;
}
Movies::~Movies(){
  delete director;
}

