#ifndef BOOKINGSERVICE_CPP
#define BOOKINGSERVICE_CPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "04_Cinema.cpp"
#include "05_Show.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "10_PaymentTypes.cpp"
#include "11_PriceCalculator.cpp"
#include "12_TicketPrinter.cpp"
using namespace std;

class BookingService {
private:
    Cinema* cinema;
    vector<Movie> movies;
    vector<Show> shows;
    vector<Booking> bookings;
    vector<unique_ptr<Payment>> payments;
    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;

public:
    BookingService(Cinema* cinema) : cinema(cinema) {
        movies.emplace_back("3 Idiots", "Hindi", 170);
        movies.emplace_back("Interstellar", "English", 169);

        shows.emplace_back(1, &movies[0], &cinema->getScreens()[0], "06:00 PM");
        shows.emplace_back(2, &movies[0], &cinema->getScreens()[1], "09:00 PM");
        shows.emplace_back(3, &movies[1], &cinema->getScreens()[0], "12:30 PM");
        shows.emplace_back(4, &movies[1], &cinema->getScreens()[1], "03:30 PM");
    }

    void listMovies() const {
        cout << "\n--- MOVIES ---\n";
        for (int i = 0; i < (int)movies.size(); ++i) {
            cout << "[" << i + 1 << "] " << movies[i].getTitle()
                 << " | " << movies[i].getLanguage()
                 << " | " << movies[i].getDuration() << " min\n";
        }
    }

    void listShowsForMovie(int movieIndex) const {
        if (movieIndex < 1 || movieIndex > (int)movies.size()) {
            cout << "Invalid movie.\n";
            return;
        }

        Movie* movie = const_cast<Movie*>(&movies[movieIndex - 1]);

        cout << "\n--- SHOWS FOR " << movie->getTitle() << " ---\n";
        for (const Show& show : shows) {
            if (show.getMovie() == movie) {
                cout << "[" << show.getShowId() << "] Screen "
                     << show.getScreen()->getScreenNumber()
                     << " | " << show.getStartTime() << '\n';
            }
        }
    }

    Show* findShow(int showId) {
        for (Show& show : shows)
            if (show.getShowId() == showId)
                return &show;
        return nullptr;
    }

    ShowSeat* findSeat(Show* show, const string& number) {
        for (ShowSeat& seat : show->getShowSeats())
            if (seat.getNumber() == number)
                return &seat;
        return nullptr;
    }

    void printSeatLayout(Show* show) const {
        cout << "\nSCREEN-" << show->getScreen()->getScreenNumber()
             << " | " << show->getStartTime()
             << " | " << show->getMovie()->getTitle() << "\n";

        for (const ShowSeat& seat : show->getShowSeats()) {
            cout << seat.getNumber() << " "
                 << seat.getTypeName() << " "
                 << (seat.isAvailable() ? "[AVAILABLE]" : "[BOOKED]")
                 << " Rs." << seat.getPrice() << '\n';
        }
    }

    unique_ptr<Payment> createPayment(int choice) {
        if (choice == 1) return make_unique<UpiPayment>();
        if (choice == 2) return make_unique<CardPayment>();
        if (choice == 3) return make_unique<CashPayment>();
        return nullptr;
    }

    void bookTicket(Customer& customer) {
        listMovies();

        int movieChoice;
        cout << "Choose movie: ";
        cin >> movieChoice;

        if (movieChoice < 1 || movieChoice > (int)movies.size()) {
            cout << "Invalid movie.\n";
            return;
        }

        listShowsForMovie(movieChoice);

        int showId;
        cout << "Choose show: ";
        cin >> showId;

        Show* show = findShow(showId);
        if (!show || show->getMovie() != &movies[movieChoice - 1]) {
            cout << "Invalid show selection.\n";
            return;
        }

        printSeatLayout(show);

        int count;
        cout << "How many seats? ";
        cin >> count;

        if (count <= 0 || count > (int)show->getShowSeats().size()) {
            cout << "Invalid number of seats.\n";
            return;
        }

        vector<ShowSeat*> selected;

        for (int i = 0; i < count; ++i) {
            string seatNumber;
            cout << "Enter seat " << i + 1 << ": ";
            cin >> seatNumber;

            ShowSeat* seat = findSeat(show, seatNumber);

            if (!seat) {
                cout << "Seat does not exist. Booking rejected.\n";
                return;
            }

            if (!seat->isAvailable()) {
                cout << "Seat " << seatNumber
                     << " is already BOOKED. Booking rejected.\n";
                return;
            }

            if (find(selected.begin(), selected.end(), seat) != selected.end()) {
                cout << "Duplicate seat selected. Booking rejected.\n";
                return;
            }

            selected.push_back(seat);
        }

        double total = priceCalculator.calculateTotal(selected);

        cout << "\nTotal amount: Rs." << total << '\n';
        cout << "Pay by: 1.UPI  2.Card  3.Cash: ";

        int paymentChoice;
        cin >> paymentChoice;

        unique_ptr<Payment> payment = createPayment(paymentChoice);

        if (!payment) {
            cout << "Invalid payment method. Booking failed.\n";
            return;
        }

        bool paid = payment->pay(total);

        if (!paid) {
            cout << "Payment failed. Seats remain AVAILABLE.\n";
            return;
        }

        for (ShowSeat* seat : selected)
            seat->book();

        payments.push_back(move(payment));

        bookings.emplace_back(
            &customer,
            show,
            selected,
            total,
            payments.back().get(),
            BookingStatus::CONFIRMED
        );

        cout << "Payment successful. Booking confirmed.\n";
        ticketPrinter.print(bookings.back());
    }

    void cancelBooking() {
        if (bookings.empty()) {
            cout << "No bookings found.\n";
            return;
        }

        int id;
        cout << "Enter booking ID: ";
        cin >> id;

        for (Booking& booking : bookings) {
            if (booking.getBookingId() == id) {
                if (booking.getStatus() != BookingStatus::CONFIRMED) {
                    cout << "Only confirmed bookings can be cancelled.\n";
                    return;
                }

                for (ShowSeat* seat : booking.getSeats())
                    seat->release();

                booking.setStatus(BookingStatus::CANCELLED);
                cout << "Booking cancelled. Seats are AVAILABLE again.\n";
                return;
            }
        }

        cout << "Booking ID not found.\n";
    }

    void printMyTickets() const {
        bool found = false;

        for (const Booking& booking : bookings) {
            if (booking.getStatus() == BookingStatus::CONFIRMED) {
                ticketPrinter.print(booking);
                found = true;
            }
        }

        if (!found)
            cout << "No confirmed tickets.\n";
    }

    void run() {
        Customer customer("Aditya", "9999999999");

        while (true) {
            cout << "\n========== MOVIE TICKET BOOKING ==========\n";
            cout << "1. Movies\n";
            cout << "2. Book\n";
            cout << "3. Cancel\n";
            cout << "4. My tickets\n";
            cout << "0. Exit\n";
            cout << "Choose: ";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1: listMovies(); break;
                case 2: bookTicket(customer); break;
                case 3: cancelBooking(); break;
                case 4: printMyTickets(); break;
                case 0: cout << "Thank you!\n"; return;
                default: cout << "Invalid choice.\n";
            }
        }
    }
};

#endif
