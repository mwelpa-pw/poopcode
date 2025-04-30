#include <iostream>
#include <vector>
#include <memory>
#include "SongDuration.hpp"
#include "Song.hpp"
#include "Playlist.hpp"

int main() {

    std::cout << "*************** PART 1 (SongDuration) ***************\n\n";


    SongDuration duration1(0, 125);  // 2m 5s
    SongDuration duration2(3, 98);  // 4m 38s

    std::cout << "Duration 1: " << duration1.get_formatted() << " (" << duration1.get_total_seconds() << "s)\n";

    std::cout << "Duration 2: " << duration2.get_formatted() << " (" << duration2.get_total_seconds() << "s)\n";


    std::cout << "\n*************** PART 2 (Song) ***************\n\n";


    Song song1;
    Song song2("Recursion Anthem", duration2, "Stack Overflow");
    Song song3("Binary Love", 3, 45, "The Algorithms");
    {
        Song song4("Segmentation Fault", duration1);
        Song song5("Git Happens", 2);

        song1.print();
        song2.print();
        song3.print();
        song4.print();
        song5.print();
        std::cout << "\nTotal songs: " << Song::get_total_songs() << std::endl;
    }
    std::cout << "\nTotal songs: " << Song::get_total_songs() << std::endl << std::endl;

    song1.set_title("Polymorphic Dreams");
    song1.set_artist("Object-Oriented Orchestra");
    song1.set_duration(300);
    std::cout << "get_title(): " << song1.get_title() << std::endl;
    std::cout << "get_artist(): " << song1.get_artist() << std::endl;
    std::cout << "get_duration(): " << song1.get_duration() << std::endl;


    std::cout << "\n*************** PART 3 (Playlist) ***************\n\n";


    Playlist playlist;
    playlist.add_song(song1);
    playlist.add_song(song2);
    playlist.add_song(song3);

    std::cout << "Playlist size: " << playlist.get_size() << std::endl;
    playlist.print();

    Playlist playlist_copy1(playlist);
    std::cout << "\nPlaylist copy (constructor):" << std::endl;
    playlist_copy1.print();

    Playlist playlist_copy2 = playlist;
    playlist_copy2 = playlist;
    std::cout << "\nPlaylist copy (assignment):" << std::endl;
    playlist_copy2.print();

    Playlist playlist_move1(std::move(playlist_copy1));
    std::cout << "\nPlaylist moved (constructor):" << std::endl;
    playlist_move1.print();
    std::cout << "\nMoved from:\n";
    playlist_copy1.print();

    Playlist playlist_move2;
    playlist_move2 = std::move(playlist_copy2);
    std::cout << "\nPlaylist moved (assignment):" << std::endl;
    playlist_move2.print();
    std::cout << "\nMoved from:\n";
    playlist_copy2.print();


    std::cout << "\n*************** PART 4 (Smart Pointers) ***************\n\n";


    struct Dummy {
        char id;
        Dummy(char id) : id(id) {
            std::cout << id << " created" << std::endl;
        }
        ~Dummy() {
            std::cout << id << " destroyed" << std::endl;
        }
    };

    // Define two empty vectors storing shared_ptr to Dummy
    std::vector<std::shared_ptr<Dummy>> v1;
    std::vector<std::shared_ptr<Dummy>> v2;

    {
        // Define 3 variables storing shared_ptr to Dummy with identifiers A, B and C
        std::shared_ptr<Dummy> A = std::make_shared<Dummy>('A');
        std::shared_ptr<Dummy> B = std::make_shared<Dummy>('B');
        std::shared_ptr<Dummy> C = std::make_shared<Dummy>('C');

        // Add A, B and C to v1
        v1.push_back(A);
        v1.push_back(B);
        v1.push_back(C);

        // Add B and C to v2
        v2.push_back(B);
        v2.push_back(C);
    }

    std::cout << "\nClearing v1" << std::endl;
    v1.clear();
    std::cout << std::endl;

    std::cout << "Clearing v2" << std::endl;
    v2.clear();
    std::cout << std::endl;

    // Define empty vector storing unique_ptr to Dummy
    std::vector<std::unique_ptr<Dummy>> v3;

    // Add to v3 two unique_ptr with identifiers D and E
    v3.push_back(std::make_unique<Dummy>('D'));
    v3.push_back(std::make_unique<Dummy>('E'));

    return 0;
}