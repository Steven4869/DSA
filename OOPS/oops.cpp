#include <bits/stdc++.h>
using namespace std;

class Anime
{
public:
    // Default Constructor
    Anime()
    {
        name = "Unknown";
        genre = "Unknown";
        episodeCount = 0;
    }
    // Parameterised Constructor
    Anime(string name, string genre, int episodeCount)
    {
        this->name = name;
        this->genre = genre;
        this->episodeCount = episodeCount;
    }
    // Copy Constructor
    Anime(const Anime &other)
    {
        name = other.name;
        genre = other.genre;
        episodeCount = other.episodeCount;
    }
    // Destructor
    ~Anime()
    {
        cout << "Destructor was called"<<endl;
    }

    // Getters and setters
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setGenre(string genre)
    {
        this->genre = genre;
    }
    string getGenre()
    {
        return genre;
    }
    void setEpisodeCount(int episodeCount)
    {
        this->episodeCount = episodeCount;
    }
    int getEpisodeCount()
    {
        return episodeCount;
    }

    void print()
    {
        cout << "[Anime: " << name << ", Genre: " << genre << ", Episodes: " << episodeCount << "]" << endl;
    }

private:
    string name;
    string genre;
    int episodeCount;
};

int main(){
    //Default Constructor 
    Anime a1;
    a1.print();

    //Parameterised Constructor 
    Anime a2("One Piece", "Shonen", 1070);
    a2.print();

    //Copy Constructor 
    Anime a3 = a2;
    a3.setName("Attack on Titan");
    a3.setEpisodeCount(100);
    a3.print();

}