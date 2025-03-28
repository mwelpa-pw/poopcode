#ifndef SONG_HPP
#define SONG_HPP

#include <iostream>
#include "SongDuration.hpp"

class Song {
    static inline unsigned int count_songs = 0;

    private:
        std::string title;
        std::string artist;
        SongDuration duration;
    public:
        Song(const std::string &g_title = "Untitled", SongDuration g_duration = SongDuration(0, 0), const std::string &g_artist = "Unknown") {
            this->title = g_title;
            this->artist = g_artist;
            this->duration = g_duration;
            count_songs++;
            }
        Song(const std::string &g_title, int minutes, int seconds, const std::string &g_artist) {
            this->title = g_title;
            this->artist = g_artist;
            this->duration = SongDuration(minutes, seconds);
            count_songs++;
        }
        void print() {
            std::cout<<title + ", Artist: " + artist + "[" + duration.get_formatted() + "]"<<std::endl;
        }
        int get_duration() { return duration.get_total_seconds(); }
        void set_duration(int duration) { this->duration = SongDuration(0, duration); }
        static int get_total_songs() { return count_songs; }

        std::string get_artist() { return artist; }
        void set_artist(const std::string& str) { this->artist = str; }

        std::string get_title() { return title; }
        void set_title(const std::string& str) { this->title = str; }

        ~Song() {}
};

#endif