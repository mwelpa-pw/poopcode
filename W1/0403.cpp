namespace huj {
	#include <string>
	using tekst = string;
	void fun() {
		std::cout << "gowno";
	}
}

int main() {
	using namespace huj;
	fun(); 
	string shit = "huj";
	std::cout << shit;
}
