#pragma once

class PayOff {
  public:
    PayOff(){};

    virtual double operator()(double S) const = 0;
    virtual ~PayOff() {}

  private:
};

class PayOffCall : public PayOff {
  public:
    PayOffCall(double _K);
    virtual double operator()(double S) const;
    virtual ~PayOffCall() {}

  private:
    double K;
};

class PayOffPut : public PayOff {
  public:
    PayOffPut(double _K);
    virtual double operator()(double S) const;
    virtual ~PayOffPut() {}

  private:
    double K;
};