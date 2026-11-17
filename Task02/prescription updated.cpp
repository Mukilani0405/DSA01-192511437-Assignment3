
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

    void changeName(const char* name)
    {
        strcpy(medicineName, name);
    }

    void display() const
    {
        cout << medicineName << " - "
             << dosage << " mg" << endl;
    }
};

int main()
{
    Prescription p1("Paracetamol", 500);

    Prescription p2 = p1;

    cout << "Before modification:" << endl;
    cout << "Original: ";
    p1.display();
    cout << "Copied: ";
    p2.display();

    p2.changeName("Ibuprofen");

    cout << "\nAfter modifying copied object:" << endl;
    cout << "Original: ";
    p1.display();
    cout << "Copied: ";
    p2.display();

    return 0;
}
