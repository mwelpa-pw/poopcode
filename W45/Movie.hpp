#ifndef MOVIE_HPP
#define MOVIE_HPP

using namespace std;
#include <iostream>
#include <list>

template<typename RatingType>
class Movie {
    public:
        struct Director {
            std::string name;
            int numberOfOscars;

            Director(const std::string &name, int nOO) : name(name), numberOfOscars(nOO) {}
        };

    private:
        std::string title;
        int year;
        std::variant<Director, std::string> director;
        std::optional<std::string> description;
        std::list<RatingType> ratings;
    
    public:
        Movie(std::string title, int year, std::variant<Director, std::string> director, std::optional<std::string>description = std::nullopt)
            : title(title), year(year), director(director), description(description) {}
    
        std::string getTitle() const {
            return title;
        }

        int getYear() const {
            return year;
        }

        std::optional<std::string> getDescription() const {
            return description;
        }

        std::variant<Director, std::string> getDirector() const {
            return director;
        }

        std::list<RatingType> getRatings() const {
            return ratings;
        }

        double getAverageRating() const {

            if (ratings.empty()) {
                return RatingType(0);
            }

            int elements = 0;
            RatingType sum = 0;
            for (const RatingType& rating : ratings) {
                sum += rating;
                elements++;
            }
            return (static_cast<double>(sum)/elements);
        }

        RatingType getTopRating() const {
            if (ratings.empty()) {
                return RatingType(0);
            }

            typename std::list<RatingType>::const_iterator it;
            it = ratings.cbegin();
            RatingType highest = *it;

            for (++it; it != ratings.cend(); ++it) { // Iteracja od drugiego elementu
                if (*it > highest) {
                    highest = *it;
                }
            }
            return highest;
        }

        bool operator<(const Movie& movie) const {
            if (this->title < movie.title) {
                return 1;
            } else if (this->title == movie.title) {
                return this->year < movie.year;
            } else {
                return 0;
            }
        }

        bool operator==(const Movie& movie) {
            return (this->title == movie.title && this->year == movie.year);
        }

        Movie& operator+(const RatingType& rating) {
            this->ratings.push_back(rating);
            return *this;
        }
};

template <typename RatingType>
std::ostream& operator<<(std::ostream& os, const Movie<RatingType>& movie) {
    os << movie.getTitle() << " (" << movie.getYear() << "), ";

    if (std::holds_alternative<typename Movie<RatingType>::Director>(movie.getDirector())) {
        os << "Director: " << std::get<typename Movie<RatingType>::Director>(movie.getDirector()).name << " (Oscars: " << std::get<typename Movie<RatingType>::Director>(movie.getDirector()).numberOfOscars << ")";
    } else {
        os << "Director: " << std::get<std::string>(movie.getDirector());
    }


    os << ", Avg: " << std::fixed << std::setprecision(2) << movie.getAverageRating()
       << ", Top: " << movie.getTopRating();

    os << std::endl;

    if (movie.getDescription().has_value()) {
        os << "Description: " << movie.getDescription().value() << std::endl;
    }

    return os;
}

#endif