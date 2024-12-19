#pragma once

class PayOff {
  public:
    PayOff(){};

    virtual double operator()(double S) const = 0;
    virtual ~PayOff() {}
    virtual PayOff *clone() const = 0;

  private:
};

class PayOffCall : public PayOff {
  public:
    PayOffCall(double _K);

    virtual double operator()(double S) const;
    virtual ~PayOffCall() {}
    virtual PayOff *clone() const;

  private:
    double K;
};

class PayOffPut : public PayOff {
  public:
    PayOffPut(double _K);

    virtual double operator()(double S) const;
    virtual ~PayOffPut() {}
    virtual PayOff *clone() const;

  private:
    double K;
};