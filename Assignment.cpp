#include <iostream>
using namespace std;

// Classes
class Counter
{
private:
    unsigned int count;     // count

public:
    Counter():count(0)       // constructor (no arguments)
    {};
    Counter(int c):count(c)  // constructor (with one argument)

    unsigned int getCount() // returns cout
    {
        return cout;
    }

    // Operator keyword is used to overload the operator
    Counter operator ++()      // increment prefix
    {
        //
        // ++count;
        // Counter temp;
        // temp.count = count;
        // return temp;

        //Better way:
        ++count;
        return Counter(count);

    }
    Counter operator ++ (int)   // increment postfix
    {
        return Counter(count++);

    }

};

// Main
int main()
{
    Counter c1, c2, c3, c4;
    cout << "c1 = " << c1.getCount() << endl;
    cout << "c2 = " << c2.getCount() << endl;

    ++c1;
    ++c1;
    cout << "c1 = " << c1.getCount() << endl;
    cout << "c2 = " << c2.getCount() << endl;

    c3 = ++c1;
    cout << "c1 = " << c1.getCount() << endl;
    cout << "c3 = " << c3.getCount() << endl;

    c4 = c1++;
    cout << "c1 = " << c1.getCount() << endl;
    cout << "c4 = " << c4.getCount() << endl;


    return 0;
}
