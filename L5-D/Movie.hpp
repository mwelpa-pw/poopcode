#ifndef MOVIE_HPP
#define MOVIE_HPP

template <typename RatingType>

class Movie {
	private:
		std::string Title;
		int year;
		std::varaint<Director, std::string> director;
	public:
		Movie(std::string name, int noo) {
			
		}
		
		struct Director {
			std::string name;
			int numberOfOscars;

			Director(const std::string& directorName, int oscars)
				: name(directorName), numberOfOscars(oscars) {}
		};

		std::vector<RatingType> ratings;	
}
#endif
