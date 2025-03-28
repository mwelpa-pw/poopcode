#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include "song.hpp"
#include <vector>

class Playlist {
      private:
            Song* songs;
            unsigned int capacity;
            unsigned int size;

            void resize(unsigned int new_capacity) {

              Song* new_songs = new Song[capacity];
              for (unsigned int i = 0; i < size; i++) {
                new_songs[i] = songs[i];
              }
              delete [] songs;
              songs = new_songs;
              capacity = new_capacity;
            }
      public:
            Playlist(int g_capacity=10) {
                  capacity=g_capacity;
                  size=0;
                  songs = new Song[capacity];
            }
            Playlist(const Playlist& other) {
              capacity=other.capacity;
              size=other.size;
              songs=new Song[other.capacity];
              for(int i=0; i<size; i++) {
                songs[i]=other.songs[i];
              }
            }
            Playlist& operator=(const Playlist& other) {
              if(this==&other) return *this;
              if (capacity!=other.capacity) {
                delete[] songs;
                capacity=other.capacity;
                songs=new Song[other.capacity];
              }
              size=other.size;
              for(int i=0; i<size; i++) {
                songs[i]=other.songs[i];
              }
              return *this;
            }
            Playlist(Playlist&& other) {
              capacity=other.capacity;
              size=other.size;
              songs=other.songs;
              other.songs=nullptr;
              other.capacity=0;
              other.size=0;
            }
            Playlist& operator=(Playlist&& other) {
              if(this==&other) return *this;
              delete[] songs;
              capacity=other.capacity;
              size=other.size;
              songs=other.songs;
              other.songs=nullptr;
              other.capacity=0;
              other.size=0;
              return *this;
            }
            void add_song(const Song& song) {
              if (size == capacity) {
                resize(capacity*2);
              }
                songs[size++]=song;

            }
            int get_size() { return size; }
            void print() {
              if (size == 0) {
                std::cout<<"Playlist is empty"<<std::endl;
                return;
              }
              for (int i = 0; i < size; i++) {
                std::cout<<i+1<<". "<<songs[i].get_title()<<", Artist: "<<songs[i].get_artist()<<" "<<songs[i].get_formatted_duration()<<std::endl;
              }
            }

            ~Playlist() {
              delete[] songs;
            }
};

#endif