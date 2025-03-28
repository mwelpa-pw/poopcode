#ifndef SONG_DURATION_HPP
#define SONG_DURATION_HPP

#include <string>
#include <iostream>

class SongDuration {
  private:
    unsigned int minutes;
    unsigned int seconds;
  public:
    SongDuration(unsigned int g_minutes=0 , unsigned int g_seconds=0) {
      while (g_seconds > 60) {
        g_seconds -= 60;
        g_minutes += 1;
        }

      this->minutes = g_minutes;
      this->seconds = g_seconds;
    }

    int get_total_seconds() {
      return minutes * 60 + seconds;
    }

    std::string get_formatted() {
      return std::to_string(minutes) + "m " + std::to_string(seconds) + "s";
    }
};

#endif