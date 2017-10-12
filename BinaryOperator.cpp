#include <iostream>
using namespace std;

// Classes
class Distance
{
private:
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0)    // Constructor (no arguments)
    {}

    Distance(int f, float i)            // Constructor (two arguments)
    {
        feet = f;
        inches = i;
    }

    void getDistance()                  // get length for user
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showDistance()                 // Display distance
    {
        cout << feet << "\' " << inches << "\"";
    }

    Distance operator +(Distance) const;    // add 2 distances
    void operator +=(Distance);   // add distance to existing

};

// Main
int main()
{
    Distance d1, d3;
    Distance d2(11, 6.25);

    d1.getDistance();
    cout << "Distance d1 = ";
    d1.showDistance();
    cout << endl;
    cout << "Distance d2 = ";
    d2.showDistance();
    cout << endl;

    // Add binary operator support
    d3 = d1 + d2;
    cout << "Distance d3 = ";
    d3.showDistance();
    cout << endl;

    d2 += d3;

    cout << "Distance d2 = ";
    d2.showDistance();
    cout << endl;



    return 0;
}

// Prototypes
//  Return the sum
Distance Distance::operator+(Distance d2) const
{
    int f = feet + d2.feet;
    float i = inches + d2.inches;
    if (i >= 12.0)
    {
        i -= 12.0;
        f++;
    }
    return Distance(f, i);
}

// Plus Equals
void Distance::operator+=(Distance d2)  // Doesn't return anything. Only modifies existing
{
    feet += d2.feet;
    inches += d2.inches;
    if (inches >= 12.0)
    {
        inches -= 12.0;
        feet++;
    }
}
