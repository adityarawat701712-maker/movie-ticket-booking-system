#ifndef SHOWSEAT_CPP
#define SHOWSEAT_CPP

#include <string>
#include "02_Seat.cpp"
using namespace std;

class ShowSeat {
private:
    Seat* seat;
    bool available;

public:
    ShowSeat(Seat* seat) : seat(seat), available(true) {}

    string getNumber() const { return seat->getNumber(); }
    Seat* getSeat() const { return seat; }
    bool isAvailable() const { return available; }

    void book() { available = false; }
    void release() { available = true; }

    double getPrice() const {
        return Seat::priceForType(seat->getType());
    }

    string getTypeName() const {
        return Seat::typeName(seat->getType());
    }
};

#endif
