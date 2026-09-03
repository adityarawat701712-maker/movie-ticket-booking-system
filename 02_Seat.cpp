#ifndef SEAT_CPP
#define SEAT_CPP

#include <string>
using namespace std;

enum class SeatType { SILVER, GOLD, PLATINUM };

class Seat {
private:
    string number;
    SeatType type;

public:
    static constexpr double SILVER_PRICE = 150.0;
    static constexpr double GOLD_PRICE = 250.0;
    static constexpr double PLATINUM_PRICE = 400.0;

    Seat(const string& number, SeatType type) : number(number), type(type) {}

    string getNumber() const { return number; }
    SeatType getType() const { return type; }

    static double priceForType(SeatType type) {
        switch (type) {
            case SeatType::SILVER: return SILVER_PRICE;
            case SeatType::GOLD: return GOLD_PRICE;
            case SeatType::PLATINUM: return PLATINUM_PRICE;
        }
        return 0;
    }

    static string typeName(SeatType type) {
        switch (type) {
            case SeatType::SILVER: return "SILVER";
            case SeatType::GOLD: return "GOLD";
            case SeatType::PLATINUM: return "PLATINUM";
        }
        return "UNKNOWN";
    }
};

#endif
