
#include <iostream>
#include <cstring>
using namespace std;

class Text
{
private:
    char* data;

public:
    Text(const char* str = "")
    {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor
    Text(const Text& other)
    {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy assignment operator
    Text& operator=(const Text& other)
    {
        if (this != &other)
        {
            char* temp = new char[strlen(other.data) + 1];
            strcpy(temp, other.data);

            delete[] data;
            data = temp;
        }
        return *this;
    }

    // Addition operator
    Text operator+(const Text& other) const
    {
        char* temp = new char[
            strlen(data) + strlen(other.data) + 1
        ];

        strcpy(temp, data);
        strcat(temp, other.data);

        Text result(temp);
        delete[] temp;

        return result;
    }

    // Equality operator
    bool operator==(const Text& other) const
    {
        return strcmp(data, other.data) == 0;
    }

    // Inequality operator
    bool operator!=(const Text& other) const
    {
        return !(*this == other);
    }

    // Output stream operator
    friend ostream& operator<<(ostream& out, const Text& t)
    {
        out << t.data;
        return out;
    }

    // Destructor
    ~Text()
    {
        delete[] data;
    }
};

int main()
{
    Text a("Hello ");
    Text b("World");

    Text c = a + b;

    cout << "First text: " << a << endl;
    cout << "Second text: " << b << endl;
    cout << "Combined text: " << c << endl;

    cout << "Equality: " << (a == b) << endl;
    cout << "Inequality: " << (a != b) << endl;

    Text d;
    d = c;

    cout << "Assigned text: " << d << endl;

    d = d;
    cout << "After self assignment: " << d << endl;

    return 0;
}
