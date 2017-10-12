#include <iostream>
using namespace std;

// Classes
class Counter
{
private:
    unsigned int count;     // count

public:
    Counter():cout(0)       // constructor
    {};

    unsigned int getCount() // returns cout
    {
        return count;
    }

    // Operator keyword is used to overload the operator
    void operator ++()      // increment prefix
    {
        ++count;
    }

};

// Main
int main()
{
    Counter c1, c2;
    cout << "c1 = " << c1.getCount() << endl;
    cout << "c2 = " << c2.getCount() << endl;

    ++c1;
    ++c1;
    cout << "c1 = " << c1.getCount() << endl;
    cout << "c2 = " << c2.getCount() << endl;

    return;
}
