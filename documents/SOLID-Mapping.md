# G. SOLID Mapping

## 1. Single Responsibility Principle (SRP)

Each class has one primary responsibility.

- `Movie` stores movie information.
- `Seat` represents a physical seat.
- `PriceCalculator` calculates prices.
- `TicketPrinter` prints tickets.
- `BookingService` coordinates the booking process.
- Payment classes handle their respective payment methods.

For example, `Booking` does not print the ticket. Ticket printing is handled separately by `TicketPrinter`.

## 2. Open/Closed Principle (OCP)

The payment system is designed so that new payment methods can be added without changing the existing payment implementations.

For example, a future `NetBankingPayment` class could extend `Payment` and implement the `pay()` method.

The existing `BookingService` does not need to be rewritten for the new payment class.

## 3. Liskov Substitution Principle (LSP)

`UpiPayment`, `CardPayment` and `CashPayment` are subclasses of `Payment`.

Any of these payment objects can be used wherever a `Payment` object is expected.

Example:

```java
Payment payment = new UpiPayment(amount, upiId);