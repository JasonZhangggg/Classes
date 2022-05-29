/*
Jason Zhang
10/13/2019
*/

#include <iostream>
#include "Music.h"
#include "Media.h"
#include <cstring>
using namespace std;

Music::Music(char* title, int year, char* newPublisher, float newDuration, char* newArtist): Media(title, year){
  publisher = new char[strlen(newPublisher)+1];
  artist = new char[strlen(newArtist)+1];
  strcpy(publisher, newPublisher);
  strcpy(artist, newArtist);
  duration = newDuration;
}
char* Music:: getPublisher(){
  return publisher;
}
char* Music:: getArtist(){
  return artist;
}
float Music::getDuration(){
  return duration;
}

int Music:: getType(){
  return 2;
}
Music::~Music(){
  delete publisher;
  delete artist;
}
