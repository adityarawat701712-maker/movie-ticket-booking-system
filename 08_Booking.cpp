#ifndef BOOKING_CPP
#define BOOKING_CPP

#include <vector>
#include <string>
#include "07_Customer.cpp"
#include "05_Show.cpp"
#include "09_Payment.cpp"
using namespace std;

enum class BookingStatus { CONFIRMED, FAILED, CANCELLED };

class Booking {
private:
    static int nextBookingId;
    int bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> seats;
    double totalAmount;
    BookingStatus status;
    Payment* payment;

public:
    Booking(Customer* customer, Show* show, const vector<ShowSeat*>& seats,
            double totalAmount, Payment* payment, BookingStatus status)
        : customer(customer), show(show), seats(seats),
          totalAmount(totalAmount), status(status), payment(payment) {
        this->bookingId = nextBookingId++;
    }

    int getBookingId() const { return bookingId; }
    Customer* getCustomer() const { return customer; }
    Show* getShow() const { return show; }
    const vector<ShowSeat*>& getSeats() const { return seats; }
    double getTotalAmount() const { return totalAmount; }
    BookingStatus getStatus() const { return status; }
    Payment* getPayment() const { return payment; }

    void setStatus(BookingStatus newStatus) { status = newStatus; }

    static string statusName(BookingStatus status) {
        switch (status) {
            case BookingStatus::CONFIRMED: return "CONFIRMED";
            case BookingStatus::FAILED: return "FAILED";
            case BookingStatus::CANCELLED: return "CANCELLED";
        }
        return "UNKNOWN";
    }
};

int Booking::nextBookingId = 1001;

#endif
