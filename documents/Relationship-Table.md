# C. Relationship Table

| Pair | Relationship | Justification |
|---|---|---|
| Cinema – Screen | Composition | Cinema owns its screens. If the Cinema object is destroyed, its owned screens no longer exist in the system. |
| Screen – Seat | Composition | Screen creates and owns its physical Seat objects. If the Screen is destroyed, its seats are also destroyed with it. |
| Show – Movie | Aggregation | Show uses an existing Movie. Destroying a Show does not destroy the Movie because the Movie can be used by other shows. |
| Show – Screen | Aggregation | Show uses an existing Screen. Destroying the Show does not destroy the Screen because the Screen can host other shows. |
| Show – ShowSeat | Composition | ShowSeat objects represent seat status specifically for a Show and are created for that Show. If the Show is destroyed, those ShowSeat objects are no longer needed. |
| Booking – Customer | Association | A Booking is related to a Customer, but destroying a Booking does not destroy the Customer. |
| Booking – ShowSeat | Aggregation | Booking refers to existing ShowSeat objects. Destroying a Booking does not destroy the actual ShowSeat objects. |
| Booking – Payment | Association | Payment is used to complete a Booking, but Payment does not own the Booking and the Booking does not own the Payment object. |
| Payment – UpiPayment | Inheritance | UpiPayment is a specialized type of Payment and inherits the common Payment contract. |
| BookingService – Booking | Association | BookingService coordinates creation and processing of Booking objects but does not permanently own their lifetime. |