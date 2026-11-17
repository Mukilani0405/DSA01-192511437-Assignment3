
#include <iostream>
#include <string>
using namespace std;

class Time
{
private:
    int seconds;

public:
    Time(int s = 0) : seconds(s) {}

    // Prefix increment
    Time& operator++()
    {
        ++seconds;
        return *this;
    }

    // Postfix increment
    Time operator++(int)
    {
        Time old = *this;
        ++seconds;
        return old;
    }

    bool operator==(const Time& t) const
    {
        return seconds == t.seconds;
    }

    bool operator<(const Time& t) const
    {
        return seconds < t.seconds;
    }

    void display() const
    {
        cout << seconds / 3600 << ":"
             << (seconds % 3600) / 60 << ":"
             << seconds % 60 << endl;
    }
};

class Playlist
{
private:
    string songs[3] = {"Song A", "Song B", "Song C"};

public:
    string& operator[](int index)
    {
        if (index < 0 || index >= 3)
            throw out_of_range("Invalid playlist index");

        return songs[index];
    }

    const string& operator[](int index) const
    {
        if (index < 0 || index >= 3)
            throw out_of_range("Invalid playlist index");

        return songs[index];
    }
};

int main()
{
    Time t(5);

    Time a = t++;
    Time b = ++t;

    cout << "Postfix result: ";
    a.display();

    cout << "Prefix result: ";
    b.display();

    cout << "Current time: ";
    t.display();

    Playlist p;

    cout << "\nPlaylist:\n";
    for (int i = 0; i < 3; i++)
        cout << p[i] << endl;

    cout << "\nComparison: " << (a < b) << endl;

    try
    {
        cout << p[-1] << endl;
    }
    catch (const out_of_range& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
