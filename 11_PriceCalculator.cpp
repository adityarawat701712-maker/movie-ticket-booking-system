#ifndef PRICECALCULATOR_CPP
#define PRICECALCULATOR_CPP

#include <vector>
#include "06_ShowSeat.cpp"
using namespace std;

class PriceCalculator {
public:
    double calculateTotal(const vector<ShowSeat*>& seats) const {
        double total = 0;
        for (ShowSeat* seat : seats)
            total += seat->getPrice();
        return total;
    }

    double calculateTotal(const vector<Seat>& seats) const {
        double total = 0;
        for (const Seat& seat : seats)
            total += Seat::priceForType(seat.getType());
        return total;
    }
};

#endif
