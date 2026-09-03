#ifndef PAYMENT_CPP
#define PAYMENT_CPP

class Payment {
public:
    virtual ~Payment() = default;
    virtual bool pay(double amount) = 0;
    virtual const char* methodName() const = 0;
};

#endif
