# 🎬 Movie Ticket Booking System

A menu-driven **Movie Ticket Booking System** developed in C++ for a single cinema. The project demonstrates core **Object-Oriented Programming (OOP)** principles, modular design, SOLID principles, runtime polymorphism, composition, aggregation, and file-independent in-memory booking management.

---

## 📌 Project Overview

The Movie Ticket Booking System simulates a real-world cinema booking workflow.

Customers can:

- View currently playing movies
- Select a movie and available show
- View the seat layout
- Select one or more seats
- Calculate ticket prices based on seat type
- Pay using UPI, Card, or Cash
- Receive a printed ticket with booking details
- View their booked tickets
- Cancel an existing booking

The system ensures that seats are booked only after successful payment and that cancelled seats become available again.

---

## ✨ Features

### 🎥 Movie Management
- Display all currently playing movies
- Show movie language and duration
- Select a movie to view its available shows

### 🕐 Show Management
- Display screen and show timings
- Associate each show with a movie and screen
- Maintain independent seat availability for every show

### 💺 Seat Management
The cinema supports three seat categories:

| Seat Type | Price |
|-----------|------:|
| SILVER | ₹150 |
| GOLD | ₹250 |
| PLATINUM | ₹400 |

Seats are displayed with their current availability status.

### 🎟️ Ticket Booking
- Book one or multiple seats
- Prevent booking of already booked seats
- Validate invalid seat numbers
- Calculate total ticket price automatically
- Confirm booking only after successful payment

### 💳 Payment System
Supports:

- UPI
- Card
- Cash

Payment is implemented using an abstract `Payment` class and derived payment classes.

### ❌ Booking Cancellation
- Cancel an existing booking
- Automatically release the booked seats
- Make cancelled seats available again

### 🎫 Ticket Printing
Each successful booking displays:

- Booking ID
- Movie name
- Screen
- Show time
- Seat numbers
- Seat types
- Total amount
- Payment method

---

## 🏗️ Project Architecture

The project follows a modular class-based architecture.

```text
Movie Ticket Booking System
│
├── Movie
├── Seat
├── Screen
├── Cinema
├── Show
├── ShowSeat
├── Customer
├── Booking
│
├── Payment
│   ├── UpiPayment
│   ├── CardPayment
│   └── CashPayment
│
├── PriceCalculator
├── TicketPrinter
└── BookingService
