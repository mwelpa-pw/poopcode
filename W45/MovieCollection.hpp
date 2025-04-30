#ifndef MOVIECOLLECTION_HPP
#define MOVIECOLLECTION_HPP

#include "Movie.hpp"
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
// Pojedynczy film reprezentowany jest przez klasę Movie<double>
class MovieCollection {
    private:
        std::map<char, std::vector<Movie<double>>> moviesByLetter;
    public:
        std::map<char, std::vector<Movie<double>>>& getMoviesByLetter() {
            return moviesByLetter;
        }

        std::vector<Movie<double>> getAllMovies() {
            std::vector<Movie<double>> allMovies;
            for (const auto& pair : moviesByLetter) {
                allMovies.insert(allMovies.end(), pair.second.begin(), pair.second.end());
            }
            return allMovies;
        }

        void addMovie(const Movie<double>& movie) {
            moviesByLetter[movie.getTitle()[0]].push_back(movie);
        }

        void sortMovies() {
            for (auto& pair : moviesByLetter) { // & bo chcemy sie odniesc do obiektu
                std::sort(pair.second.begin(), pair.second.end())
            }
        }

};

std::ostream& operator<<(std::ostream& os, MovieCollection movieCollection) {
    const auto& moviesByLetter = movieCollection.getMoviesByLetter();

    for(const auto& pair : moviesByLetter) {
        os << "\n===" << pair.first << "===" << std::endl;
        for (const auto& movie : pair.second) {
            os << " " << movie << std::endl;
        }
    }

    return os;
}

#endif