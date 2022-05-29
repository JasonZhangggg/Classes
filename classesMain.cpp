/*
Jason Zhang
10/30/2019
Classes
*/

#include <iostream>
#include <vector>
#include <cstring>
#include "Media.h"
#include "VideoGame.h"
#include "Music.h"
#include "Movies.h"

using namespace std;

void add(vector<Media*>*);
void search(vector<Media*>*);
void print(Media*);
void deleteItem(vector<Media*>*);
int main(){
  vector<Media*> *vect = new vector<Media*>;
    
  while(true){
    //take in the users input
    char input[80];
    cout<<"Input ADD to add a item, SEARCH search for a item, DELETE to delete a item, and QUIT to exit the program."<<endl;
    cin.get(input, sizeof(input));
    cin.clear();
    cin.ignore(999, '\n');
    //set it to upper case
    for(int i = 0; i<sizeof(input); i++){
      input[i] = toupper(input[i]);
    }
    //if they inputed ADD
    if(strcmp(input, "ADD") == 0){
      //call add 
      add(vect);
    }
    else if(strcmp(input, "SEARCH") == 0){
      search(vect);
    }
    //if they inputed DELETE
    else if(strcmp(input, "DELETE") == 0){
      //run delete
      deleteItem(vect);
      cin.clear();
      cin.ignore(999, '\n');
    }
    //if they inputed QUIT
    else if(strcmp(input, "QUIT") == 0){
      //return 0, exiting the program
      return 0;
    }
    else{
      cout<<"That is invalid."<< endl;
    }
    
  }
}
void add(vector <Media*>* vect){
  //all of the possible inputs of media
  char input[80];
  char title[80];
  int year = 0;
  char publisher[80];
  int rating = 0;
  char artist[80];
  float duration;
  char director[80];

  //promt if they would like to add a videogame, movie, or song
  cout<<"Would you like to add a videogame, movie, or music?"<<endl;
  cin.get(input, sizeof(input));
  cin.clear();
  cin.ignore(999, '\n');
  //add a videogame
  if(strcmp(input, "videogame") == 0){
    cout<<"What is the games's title?"<<endl;
    cin>>title;
    cout<<"What year did the game come out?"<<endl;
    cin>>year;
    cout<<"What is the game's publisher?"<<endl;
    cin>>publisher;
    cout<<"What is the game's rating?(Integer)"<<endl;
    cin>>rating;
    vect->push_back(new VideoGame(title, year, publisher, rating));
    cout<<"Added a videogame"<<endl;
  }
  //add a song
  else if(strcmp(input, "music") == 0){
    cout<<"What is the song's title?"<<endl;
    cin>>title;
    cout<<"What year did the song come out?"<<endl;
    cin>>year;
    cout<<"Who is the song's artist?"<<endl;
    cin>>artist;
    cout<<"What is the song's publisher?"<<endl;
    cin>>publisher;
    cout<<"What is the song's duration?"<<endl;
    cin.clear();
    cin.ignore(999, '\n');
    cin>>duration;
    vect->push_back(new Music(title, year, publisher, duration, artist));
    cout<<"Added a song"<<endl;
  }
  //add a movie
  else if(strcmp(input, "movie") == 0){
    cout<<"What is the movie's title?"<<endl;
    cin>>title;
    cout<<"What year did the movie come out?"<<endl;
    cin>>year;
    cout<<"Who is the movie's director?"<<endl;
    cin>>director;
    cout<<"What is the movie's duration?"<<endl;
    cin>>duration;
    cout<<"What is the movie's rating?(Integer)"<<endl;
    cin>>rating;
    vect->push_back(new Movies(title, year, director, rating, duration));
    cout<<"Added a movie"<<endl;
  }
    
  cin.ignore(999, '\n');
}
void search(vector<Media*>*vect){
  //ask user how they would like to search
  cout<<"Would you like to search by. Year(y), Title(t), print all(a)"<<endl;
  char input;
  char searchS[80];
  int searchI = -10;
  cin>>input;
  cin.clear();
  cin.ignore(999, '\n');
  //take in year
  if(input == 'y'){
    cout<<"What is the year?"<<endl;
    cin>>searchI;
    cin.clear();
    cin.ignore(999, '\n');
  }
  //take in title
  else if(input == 't'){
    cout<<"What is the title?"<<endl;
    cin.get(searchS, sizeof(searchS));
    cin.clear();
    cin.ignore(999, '\n');
 }
  vector<Media*>::iterator i;
  //loop through vector
  for(i=vect->begin();i!=vect->end();i++){
    if(input == 'y' && (*i)->getYear() == searchI || input == 't' && strcmp((*i)->getTitle(), searchS) == 0 || input == 'a'){
      //print out all media that meets the requirments.
      print(*i);
    } 
  }
}
//print function to print all the media
void print(Media* med){
  cout<<"Title: "<< med->getTitle()<<", Year: "<<med->getYear();
  if(med -> getType() == 1){
    VideoGame* vid = (VideoGame*)(med);
    cout<<", Publisher: "<<vid->getPublisher()<<", Rating: "<<vid->getRating()<<endl;
  }
  else if(med-> getType() == 2){
    Music* mus = (Music*)(med);
    cout<<", Artist: "<<mus->getArtist()<<", Publisher: "<<mus->getPublisher()<< ", Duration: "<<mus->getDuration()<<endl;
  }
  else if(med -> getType() == 3){
    Movies* mov = (Movies*)(med);
    cout<<", Director: "<<mov->getDirector()<<", Duration: "<<mov->getDuration()<<", Rating: "<<mov->getRating()<<endl;
  }
}



void deleteItem(vector<Media*>*vect){
  char input;
  char searchS[80];
  int searchI = -10;
  //check how they would like to delete
  cout<<"Would you like to search by year(y) or title(t)?"<<endl;
  cin>>input;
  cin.clear();
  cin.ignore(999, '\n');
  //ask for year
  if(input == 'y'){
    cout<<"What is the year?"<<endl;
    cin>>searchI;
    cin.clear();
    cin.ignore(999, '\n');
  }
  //ask for title
  else if(input == 't'){
    cout<<"What is the title?"<<endl;
    cin.get(searchS, sizeof(searchS));
    cin.clear();
    cin.ignore(999, '\n');
 }
  vector<Media*>::iterator i;
  //loop through vector and print all media that meet the requirments
  for(i=vect->begin();i!=vect->end();i++){
    if(input == 'y' && (*i)->getYear() == searchI || input == 't' && strcmp((*i)->getTitle(), searchS) == 0 || input == 'a'){
      print(*i);
    } 
  }
  //ask user if they are sure they want to delete the values
  cout<<"Would you like to delete these values?(y/n)"<<endl;
  char inputYN;
  cin>>inputYN;
  //if no return
  if(inputYN == 'n'){
    return;
  }
  //if yes then delete
  //loop through vector
  for(i=vect->begin();i!=vect->end();){
    if(input == 'y' && (*i)->getYear() == searchI || input == 't' && strcmp((*i)->getTitle(), searchS) == 0 || input == 'a'){
      delete *i;
      i = vect->erase(i);
    }
    else{
      //only increase i if something is not erased
      i++;
    }
  }    
  cout<<"Deleted"<<endl;
  return;
}
