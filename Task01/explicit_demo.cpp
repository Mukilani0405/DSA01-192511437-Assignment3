
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;

public:
    explicit Book(string t) : title(t)
    {
    }

    void display()
    {
        cout << "Book title: " << title << endl;
    }
};

int main()
{
    // Direct initialization: allowed
    Book b1("C++ Programming");
    b1.display();

    // Copy initialization: not allowed with explicit
    Book b2 = "Java Programming";

    b2.display();

    return 0;
}
