
#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i) {}

    Complex operator+(const Complex& c) const
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const
    {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const
    {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    Complex operator/(const Complex& c) const
    {
        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator == 0)
        {
            cout << "Error: Division by zero!" << endl;
            return Complex();
        }

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    bool operator==(const Complex& c) const
    {
        return real == c.real && imag == c.imag;
    }

    double magnitude() const
    {
        return sqrt(real * real + imag * imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c)
    {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";

        return out;
    }
};

int main()
{
    const double PI = 3.141592653589793;
    double frequency = 50.0;
    double omega = 2 * PI * frequency;

    double R = 100.0;
    double L = 0.1;
    double C = 100e-6;

    // Individual impedances
    Complex ZR(R, 0);
    Complex ZL(0, omega * L);
    Complex ZC(0, -1.0 / (omega * C));

    cout << "RESISTOR IMPEDANCE: " << ZR << endl;
    cout << "INDUCTOR IMPEDANCE: " << ZL << endl;
    cout << "CAPACITOR IMPEDANCE: " << ZC << endl;

    // Series RLC circuit
    Complex series = ZR + ZL + ZC;

    cout << "\nSeries Impedance: " << series << endl;
    cout << "Series Magnitude: " << series.magnitude()
         << " Ohms" << endl;

    // Parallel combination of resistor and inductor
    Complex parallel = (ZR * ZL) / (ZR + ZL);

    cout << "\nParallel R-L Impedance: "
         << parallel << endl;

    cout << "Parallel Magnitude: "
         << parallel.magnitude() << " Ohms" << endl;

    // Division by zero test
    Complex zero(0, 0);
    Complex test = ZR / zero;

    return 0;
}
