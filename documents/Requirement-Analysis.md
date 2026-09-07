# A. Requirement Analysis

## Functional Requirements

### FR1 – List Movies
The system shall display all movies currently playing in the cinema along with their language and duration.

### FR2 – List Shows
The system shall allow the customer to select a movie and display its available shows with screen number and start time.

### FR3 – Display Seat Availability
The system shall display the seat layout for a selected show and show each seat as either AVAILABLE or BOOKED.

### FR4 – Book Seats
The system shall allow the customer to select one or more available seats for a show. The system shall reject any seat that is already booked.

### FR5 – Calculate Booking Price
The system shall calculate the total booking amount according to seat type:

- SILVER – ₹150
- GOLD – ₹250
- PLATINUM – ₹400

### FR6 – Make Payment
The system shall support UPI, Card and Cash payment methods. A failed payment shall not confirm the booking and the selected seats shall be released.

### FR7 – Print Ticket
After successful payment, the system shall print a ticket containing the booking ID, movie name, screen number, show time, seat numbers and total amount.

### FR8 – Cancel Booking
The system shall allow a customer to cancel a confirmed booking. After cancellation, all seats belonging to that booking shall become AVAILABLE again.

## Non-Functional Requirements

### NFR1 – Modularity
Each major responsibility shall be implemented in a separate class and each class shall be stored in its own Java file.

### NFR2 – Extensibility
The payment system shall use an abstract Payment class so that a new payment method can be added without changing the existing payment implementations.

### NFR3 – Input Validation
The system shall validate menu choices, seat numbers and payment details and display a clear error message instead of crashing.

### NFR4 – Maintainability
Each method shall perform one clear responsibility, use meaningful names and avoid unnecessary duplicate code.