#ifndef SHOW_CPP
#define SHOW_CPP

#include <vector>
#include <string>
#include "01_Movie.cpp"
#include "03_Screen.cpp"
#include "06_ShowSeat.cpp"
using namespace std;

class Show {
private:
    int showId;
    Movie* movie;
    Screen* screen;
    string startTime;
    vector<ShowSeat> showSeats;

public:
    Show(int showId, Movie* movie, Screen* screen, const string& startTime)
        : showId(showId), movie(movie), screen(screen), startTime(startTime) {
        for (Seat& seat : screen->getSeats())
            showSeats.emplace_back(&seat);
    }

    int getShowId() const { return showId; }
    Movie* getMovie() const { return movie; }
    Screen* getScreen() const { return screen; }
    string getStartTime() const { return startTime; }
    vector<ShowSeat>& getShowSeats() { return showSeats; }
};

#endif
