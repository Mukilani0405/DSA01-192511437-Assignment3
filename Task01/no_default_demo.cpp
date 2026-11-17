
#include <iostream>
using namespace std;

class Book
{
private:
    int copies;

public:
    // Only parameterized constructor
    Book(int c) : copies(c)
    {
    }
};

int main()
{
    // This array requires a default constructor
    Book books[3];

    cout << "Array created successfully";
    return 0;
}
