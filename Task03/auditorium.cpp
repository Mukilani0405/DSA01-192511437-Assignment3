
#include <iostream>
using namespace std;

class Auditorium
{
private:
    int rows, seats;
    bool** seatMap;

public:
    // Dynamic constructor
    Auditorium(int r, int s) : rows(r), seats(s)
    {
        seatMap = new bool*[rows];

        for (int i = 0; i < rows; i++)
        {
            seatMap[i] = new bool[seats];

            for (int j = 0; j < seats; j++)
                seatMap[i][j] = false;
        }

        cout << "Auditorium created: "
             << rows << " rows, "
             << seats << " seats per row" << endl;
    }

    void bookSeat(int r, int s)
    {
        if (r < 0 || r >= rows || s < 0 || s >= seats)
        {
            cout << "Invalid seat" << endl;
        }
        else if (seatMap[r][s])
        {
            cout << "Seat already booked" << endl;
        }
        else
        {
            seatMap[r][s] = true;
            cout << "Seat booked successfully" << endl;
        }
    }

    void cancelSeat(int r, int s)
    {
        if (r < 0 || r >= rows || s < 0 || s >= seats)
        {
            cout << "Invalid seat" << endl;
        }
        else if (!seatMap[r][s])
        {
            cout << "Seat is not booked" << endl;
        }
        else
        {
            seatMap[r][s] = false;
            cout << "Booking cancelled" << endl;
        }
    }

    void display() const
    {
        cout << "\nSeat Map (0 = Available, 1 = Booked)\n";

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < seats; j++)
                cout << seatMap[i][j] << " ";

            cout << endl;
        }
    }

    // Destructor
    ~Auditorium()
    {
        for (int i = 0; i < rows; i++)
            delete[] seatMap[i];

        delete[] seatMap;

        cout << "Auditorium memory released" << endl;
    }
};

int main()
{
    Auditorium hall(3, 4);

    hall.bookSeat(0, 1);
    hall.bookSeat(1, 2);
    hall.bookSeat(0, 1);

    hall.display();

    hall.cancelSeat(0, 1);

    hall.display();

    return 0;
}
