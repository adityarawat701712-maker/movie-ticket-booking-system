# Movie Ticket Booking System

A small menu-driven C++ console application for a single cinema.

## Required Features

- List all currently playing movies
- List shows for a selected movie
- Display seat layout and AVAILABLE / BOOKED status
- Book one or more seats
- Reject already-booked seats
- Calculate Silver Rs.150, Gold Rs.250, Platinum Rs.400
- Pay using UPI, Card or Cash
- Failed payment does not confirm a booking
- Print ticket
- Cancel booking and release seats

## OOP Concepts Demonstrated

1. Encapsulation
2. Abstraction
3. Inheritance
4. Runtime polymorphism
5. Compile-time polymorphism
6. Static member
7. `this` keyword
8. Composition
9. Aggregation
10. Association

## Build

C++17 or later:

```bash
g++ -std=c++17 main.cpp -o movie_booking
```

Windows:

```bash
g++ -std=c++17 main.cpp -o movie_booking.exe
movie_booking.exe
```

## Repository Structure

```text
movie-ticket-booking/
├── 01_Movie.cpp
├── 02_Seat.cpp
├── 03_Screen.cpp
├── 04_Cinema.cpp
├── 05_Show.cpp
├── 06_ShowSeat.cpp
├── 07_Customer.cpp
├── 08_Booking.cpp
├── 09_Payment.cpp
├── 10_PaymentTypes.cpp
├── 11_PriceCalculator.cpp
├── 12_TicketPrinter.cpp
├── 13_BookingService.cpp
├── main.cpp
├── README.md
└── .gitignore
```

The assignment specifically asks for one class per `.cpp` file and no header files, so `main.cpp` uses a simple unity-build approach by including the class `.cpp` files.
