#include <iostream>
using namespace std;

// Assignment requirement: one class per .cpp file and no header files.
#include "01_Movie.cpp"
#include "02_Seat.cpp"
#include "03_Screen.cpp"
#include "04_Cinema.cpp"
#include "05_Show.cpp"
#include "06_ShowSeat.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "10_PaymentTypes.cpp"
#include "11_PriceCalculator.cpp"
#include "12_TicketPrinter.cpp"
#include "13_BookingService.cpp"

int main() {
    Cinema cinema("PVR", 2);
    BookingService service(&cinema);
    service.run();
    return 0;
}
