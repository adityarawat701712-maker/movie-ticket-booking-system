# B. Noun–Verb Analysis

## Nouns Identified

| Noun | Keep as Class? | Reason |
|---|---|---|
| Movie | Yes | Has its own title, language and duration. |
| Seat | Yes | Represents one physical seat with number and type. |
| Screen | Yes | Represents an auditorium containing seats. |
| Cinema | Yes | Represents the theatre containing screens. |
| Show | Yes | Represents a movie screening on a particular screen and time. |
| ShowSeat | Yes | Maintains the status of one seat for one particular show. |
| Customer | Yes | Stores customer information. |
| Booking | Yes | Represents a customer's booking and its details. |
| Payment | Yes | Defines the common payment contract. |
| UPI Payment | Yes | Implements UPI payment behaviour. |
| Card Payment | Yes | Implements card payment behaviour. |
| Cash Payment | Yes | Implements cash payment behaviour. |
| Price Calculator | Yes | Responsible for calculating booking price. |
| Ticket Printer | Yes | Responsible for printing tickets. |
| Booking Service | Yes | Coordinates the complete booking process. |
| Seat Layout | No | It is a view of ShowSeat objects, not an independent entity. |
| Ticket | No | Ticket printing is required, but a separate Ticket class is not necessary for the specified scope. |

## Verbs Identified

Important verbs from the problem statement include:

- see
- list
- pick
- display
- book
- pay
- print
- cancel
- reject
- calculate
- release

## Mapping of Verbs to Methods

| Verb | Class / Method |
|---|---|
| List movies | `Main.listMovies()` |
| Display seats | `Show.displaySeats()` |
| Book seats | `BookingService.createBooking()` |
| Pay | `Payment.pay()` |
| Calculate price | `PriceCalculator.calculateTotal()` |
| Print ticket | `TicketPrinter.printTicket()` |
| Cancel booking | `Booking.cancelBooking()` |
| Release seats | `ShowSeat.cancelSeat()` |