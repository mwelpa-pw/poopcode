#ifndef MOVIECOLLECTION_HPP
#define MOVIECOLLECTION_HPP

#include "Movie.hpp"
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <numeric>
// Pojedynczy film reprezentowany jest przez klasę Movie<double>
class MovieCollection {
    private:
        std::map<char, std::vector<Movie<double>>> moviesByLetter;
    public:
        std::map<char, std::vector<Movie<double>>>& getMoviesByLetter() {
            return moviesByLetter;
        }

        std::vector<Movie<double>> getAllMovies() const {
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
                std::sort(pair.second.begin(), pair.second.end());
            }
        }

        void removeMoviesOlderThan(char letter, int year) {
            struct IsOlderThan {
                int year;
            
                IsOlderThan(int y) : year(y) {}
            
                bool operator()(const Movie<double>& movie) const {
                    return movie.getYear() < year;
                }
            };

            auto it = moviesByLetter.find(letter);
            if (it != moviesByLetter.end()) {
                auto& movieList = it->second;
                movieList.erase(
                    std::remove_if(movieList.begin(), movieList.end(), IsOlderThan(year)), 
                    movieList.end()
                );
            }

        }

        double getAverageTopRating() const  {
            struct AddTopRating {
                double operator()(double sum, const Movie<double>& movie) const {
                    return sum + movie.getTopRating();
                }
            };

            auto allMovies = getAllMovies();
            double totalSum = std::accumulate(allMovies.begin(), allMovies.end(), 0.0, AddTopRating());
            return totalSum / allMovies.size();
        }


        // tu juz mi sie nei chce
        std::vector<Movie<double>> getMoviesByDirector(const std::string& directorName) const {
            struct DirectedBy {
                const std::string& name;
                explicit DirectedBy(const std::string& directorName) : name(directorName) {}
                bool operator()(const Movie<double>& movie) const {
                    const auto& directorVariant = movie.getDirector();
                    if (std::holds_alternative<typename Movie<double>::Director>(directorVariant)) {
                        return std::get<typename Movie<double>::Director>(directorVariant).name == name;
                    } else {
                        return std::get<std::string>(directorVariant) == name;
                    }
                }
            };
        
            auto allMovies = getAllMovies();
            std::vector<Movie<double>> result;
            std::copy_if(allMovies.begin(), allMovies.end(), std::back_inserter(result), DirectedBy(directorName));
            return result;
        }

        std::optional<Movie<double>> findMovieWithAverageAbove(double threshold) const {
            struct HasAverageAbove {
                double threshold;
                explicit HasAverageAbove(double threshold) : threshold(threshold) {}
        
                bool operator()(const Movie<double>& movie) const {
                    return movie.getAverageRating() > threshold;
                }
            };
        
            auto allMovies = getAllMovies();
            auto it = std::find_if(allMovies.begin(), allMovies.end(), HasAverageAbove(threshold));
            if (it != allMovies.end()) {
                return *it;
            }
            return std::nullopt;
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