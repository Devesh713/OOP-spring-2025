#include <iostream>
#include <string>

using namespace std;

class Movie 
{
private:
    string title;
    string director;
    int duration; 
public:
    Movie(const string& t, const string& d, int dur)
        : title(t), director(d), duration(dur) {}

    void displayDetails() const 
    {
        cout << "Movie: " << title << endl;
        cout << "Directed by: " << director << endl;
        cout << "Runtime: " << duration << " mins" << endl;
    }
};

class CinemaHall 
{
private:
    string hallName;
    Movie** movies;
    int movieCount;  

public:
    CinemaHall(const string& name, int count)
        : hallName(name), movieCount(count) 
    {
        movies = new Movie*[movieCount];
    }

    ~CinemaHall() 
    {
        for (int i = 0; i < movieCount; ++i) 
        {
            delete movies[i];
        }
        delete[] movies;
    }

    void addMovie(int index, const string& title, const string& director, int duration) 
    {
        if (index >= 0 && index < movieCount) 
        {
            movies[index] = new Movie(title, director, duration);
        }
    }

    void displayCinemaDetails() const 
    {
        cout << "Welcome to " << hallName << "!" << endl;
        cout << "Now Showing:" << endl;
        if (movieCount == 0) 
        {
            cout << "No movies currently playing." << endl;
        } 
        else 
        {
            for (int i = 0; i < movieCount; ++i) 
            {
                movies[i]->displayDetails();
                cout << "-------------------------" << endl;
            }
        }
    }
};

int main() 
{
    CinemaHall cinema("Grand Cineplex", 3);
    cinema.addMovie(0, "Inception", "Christopher Nolan", 148);
    cinema.addMovie(1, "Avatar", "James Cameron", 162);
    cinema.addMovie(2, "The Dark Knight", "Christopher Nolan", 152);
    cinema.displayCinemaDetails();
    return 0;
}
