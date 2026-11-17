
#include <iostream>
#include <cstring>
using namespace std;

class Prescription
{
private:
    char* medicineName;
    int dosage;

public:
    Prescription(const char* name, int d)
    {
        medicineName = new char[strlen(name) + 1];
        strcpy(medicineName, name);
        dosage = d;
    }

    void display() const
    {
        cout << medicineName << " - "
             << dosage << " mg" << endl;
    }

    // No custom copy constructor yet
    // No custom copy assignment operator yet
    // No destructor yet
};

int main()
{
    Prescription p1("Paracetamol", 500);

    // Compiler-generated copy constructor
    Prescription p2 = p1;

    cout << "Original Prescription: ";
    p1.display();

    cout << "Copied Prescription: ";
    p2.display();

    return 0;
}
