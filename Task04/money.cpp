
#include <iostream>
#include <iomanip>
using namespace std;

class Money
{
private:
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
    {
        paise = rupees * 100 + p;
    }

    // Addition operator
    Money operator+(const Money& other) const
    {
        return Money(0, paise + other.paise);
    }

    // Subtraction operator
    Money operator-(const Money& other) const
    {
        return Money(0, paise - other.paise);
    }

    // Addition assignment operator
    Money& operator+=(const Money& other)
    {
        paise += other.paise;
        return *this;
    }

    // Equality operator
    bool operator==(const Money& other) const
    {
        return paise == other.paise;
    }

    // Less-than operator
    bool operator<(const Money& other) const
    {
        return paise < other.paise;
    }

    // Output stream operator
    friend ostream& operator<<(ostream& out, const Money& m)
    {
        long long value = m.paise;
        if (value < 0)
        {
            out << "-Rs ";
            value = -value;
        }
        else
        {
            out << "Rs ";
        }

        out << value / 100 << "."
            << setw(2) << setfill('0') << value % 100;
        return out;
    }

    // Input stream operator
    friend istream& operator>>(istream& in, Money& m)
    {
        long long rupees;
        int p;
        in >> rupees >> p;
        m.paise = rupees * 100 + p;
        return in;
    }
};

int main()
{
    Money a(150, 75);
    Money b(49, 25);

    cout << "First amount: " << a << endl;
    cout << "Second amount: " << b << endl;

    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;

    a += b;
    cout << "After += : " << a << endl;

    cout << "Equality: " << (a == b) << endl;
    cout << "Less than: " << (b < a) << endl;

    return 0;
}
