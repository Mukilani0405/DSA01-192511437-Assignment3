
#include <iostream>
#include <string>
using namespace std;

class Prescription
{
private:
    string medicineName;

public:
    static int copyCount;

    Prescription(string name) : medicineName(name)
    {
    }

    Prescription(const Prescription& other)
        : medicineName(other.medicineName)
    {
        copyCount++;
    }

    void display() const
    {
        cout << medicineName << endl;
    }
};

int Prescription::copyCount = 0;

void passByValue(Prescription p)
{
    cout << "Pass by value: ";
    p.display();
}

void passByReference(const Prescription& p)
{
    cout << "Pass by const reference: ";
    p.display();
}

int main()
{
    Prescription p1("Paracetamol");

    Prescription::copyCount = 0;
    passByValue(p1);
    cout << "Copy count: " << Prescription::copyCount << endl;

    Prescription::copyCount = 0;
    passByReference(p1);
    cout << "Copy count: " << Prescription::copyCount << endl;

    return 0;
}
