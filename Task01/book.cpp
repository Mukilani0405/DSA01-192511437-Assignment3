
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int copies;

public:
    // Default constructor
    Book() : Book("", "Unknown", 0)
    {
    }

    // Donated book: title only
    explicit Book(string t) : Book(t, "Unknown", 0)
    {
    }

    // Parameterized constructor: full details
    Book(string t, string a, int c)
        : title(t), author(a), copies(c >= 0 ? c : 0)
    {
    }

    void display() const
    {
        cout << "Title: " << title
             << " | Author: " << author
             << " | Copies: " << copies << '\n';
    }
};

int main()
{
    Book emptyBook;
    Book donatedBook("C++ Programming");
    Book fullBook("Data Structures", "Mark Allen", 5);
    Book invalidBook("Algorithms", "Robert", -3);

    cout << "LIBRARY BOOK RECORDS\n";

    emptyBook.display();
    donatedBook.display();
    fullBook.display();
    invalidBook.display();

    return 0;
}
