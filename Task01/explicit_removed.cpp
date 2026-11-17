
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;

public:
    // No explicit keyword
    Book(string t) : title(t)
    {
    }

    void display()
    {
        cout << "Book title: " << title << endl;
    }
};

int main()
{
    Book b1("C++ Programming");
    b1.display();

    // Implicit conversion from string to Book
    Book b2 = string("Java Programming");
    b2.display();

    return 0;
}
