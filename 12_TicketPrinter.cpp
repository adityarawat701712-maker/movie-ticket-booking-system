#ifndef TICKETPRINTER_CPP
#define TICKETPRINTER_CPP

#include <iostream>
#include <iomanip>
#include "08_Booking.cpp"
using namespace std;

class TicketPrinter {
public:
    void print(const Booking& booking) const {
        cout << "\n================ TICKET ================\n";
        cout << "Booking ID : " << booking.getBookingId() << '\n';
        cout << "Customer   : " << booking.getCustomer()->getName() << '\n';
        cout << "Phone      : " << booking.getCustomer()->getPhone() << '\n';
        cout << "Movie      : " << booking.getShow()->getMovie()->getTitle() << '\n';
        cout << "Screen     : " << booking.getShow()->getScreen()->getScreenNumber() << '\n';
        cout << "Show Time  : " << booking.getShow()->getStartTime() << '\n';
        cout << "Seats      : ";

        for (ShowSeat* seat : booking.getSeats())
            cout << seat->getNumber() << ' ';

        cout << "\nPayment    : " << booking.getPayment()->methodName();
        cout << "\nAmount     : Rs." << fixed << setprecision(2)
             << booking.getTotalAmount();
        cout << "\nStatus     : " << Booking::statusName(booking.getStatus());
        cout << "\n=========================================\n";
    }
};

#endif
