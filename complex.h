#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
private:
  double Real;
  double Imag;
public:
    Complex(double x=0, double y=0) {
        this->Real = x;
        this->Imag = y;
    };


  Complex & operator= (const Complex & s)
  {
    Real = s.Real;
    Imag = s.Imag;
    return *this;
  };

  Complex operator- () const
  {
    return Complex(-Real,-Imag);
  };

  Complex & operator= (double co)
  {
    Real = co;
    Imag = 0;
    return *this;
  };

  Complex operator+ (const Complex& co) const
  {
    Complex n;
    n.Real = this->Real + co.Real;
    n.Imag = this->Imag + co.Imag;
    return n;
  };

  Complex operator/(const Complex& co) const 
  {
  Complex n;
  n.Real = (co.Real * co.Real + co.Imag * co.Imag) / (co.Real * co.Real + co.Imag * co.Imag);
  n.Imag = -(co.Real * co.Imag - co.Imag * co.Real) / (co.Real * co.Real +   co.Imag * co.Imag);
  return n;
  };


  Complex & operator+= (Complex co)
  {
    Real += co.Real;
    Imag += co.Imag;
    return *this;
  };

  Complex & operator-= (Complex co)
  {
    Real -= co.Real;
    Imag -= co.Imag;
    return *this;
  };

  Complex operator/=(const Complex& co)
  {
  this->Real = (co.Real * co.Real + co.Imag * co.Imag) / (co.Real * co.Real + co.Imag * co.Imag);
  this->Imag = -(co.Real * co.Imag - co.Imag * co.Real) / (co.Real * co.Real + co.Imag * co.Imag);
  return *this;
  };

  double abs(const Complex& co)
  {
  double mod;
  mod = sqrt((co.Real * co.Real)+(co.Imag * co.Imag));
  return mod;
  };

   double phase(const Complex& co)
   {
   double faza;
   faza = atan2(co.Imag, co.Real);
   return faza;
   };

 
  friend Complex operator- (Complex, Complex);
  friend ostream & operator << (ostream & s, const Complex & c)
  {
    s << "(" << c.Real << "," << c.Imag << ")";
    return s;
  };
};

inline Complex
operator - (Complex s1, Complex s2)
{
  Complex n (s1);
  return n -= s2;
};

#endif /* __Complex_H__ */
