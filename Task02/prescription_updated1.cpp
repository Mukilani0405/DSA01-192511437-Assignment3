
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

    // Deep copy constructor
    Prescription(const Prescription& other)
    {
        medicineName = new char[strlen(other.medicineName) + 1];
        strcpy(medicineName, other.medicineName);
        dosage = other.dosage;
    }

    // Copy assignment operator
    Prescription& operator=(const Prescription& other)
    {
        if (this != &other)
        {
            char* newName = new char[strlen(other.medicineName) + 1];
            strcpy(newName, other.medicineName);

            delete[] medicineName;

            medicineName = newName;
            dosage = other.dosage;
        }

        return *this;
    }

    // Destructor
    ~Prescription()
    {
        delete[] medicineName;
    }

    void changeName(const char* name)
    {
        delete[] medicineName;
        medicineName = new char[strlen(name) + 1];
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
    Prescription p2("Ibuprofen", 200);

    cout << "Before assignment:" << endl;
    p1.display();
    p2.display();

    p2 = p1;

    cout << "\nAfter assignment:" << endl;
    p1.display();
    p2.display();

    p2.changeName("Cetirizine");

    cout << "\nAfter modifying p2:" << endl;
    p1.display();
    p2.display();

    return 0;
}
