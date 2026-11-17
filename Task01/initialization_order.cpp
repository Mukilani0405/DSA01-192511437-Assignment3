
#include <iostream>
using namespace std;

class Demo
{
private:
    int first;
    int second;

public:
    // Intentionally written in the wrong order
    Demo() : second(20), first(10)
    {
        cout << "First: " << first << endl;
        cout << "Second: " << second << endl;
    }
};

int main()
{
    Demo obj;
    return 0;
}
