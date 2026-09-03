#ifndef SCREEN_CPP
#define SCREEN_CPP

#include <vector>
#include <string>
#include "02_Seat.cpp"
using namespace std;

class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

    void createSeats() {
        for (int i = 1; i <= 4; ++i)
            seats.emplace_back("A" + to_string(i), SeatType::SILVER);

        for (int i = 1; i <= 3; ++i)
            seats.emplace_back("B" + to_string(i), SeatType::GOLD);

        for (int i = 1; i <= 2; ++i)
            seats.emplace_back("C" + to_string(i), SeatType::PLATINUM);
    }

public:
    Screen(int screenNumber) : screenNumber(screenNumber) {
        createSeats();
    }

    int getScreenNumber() const { return screenNumber; }
    vector<Seat>& getSeats() { return seats; }
};

#endif
