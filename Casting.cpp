#include <iostream>
using namespace std;

// Classes
class Distance
{
private:
    float MTF;    // Meters to Feet
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0), MTF(3.280833F)    // Constructor (no arguments)
    {}

    Distance(int meters): MTF(3.280833F)            // Constructor (one argument)
    {
        float fltfeet = MTF * meters;   // convert to float feet

        feet = int(fltfeet);            // feet is the integer part
        // Same as feet = static_cast<int>(fltfeet);
        inches = 12*(fltfeet - feet);   // inches is what is left
    }
    Distance(int f, float i) : MTF(3.280833F)          // Constructor (two arguments)
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

    Distance operator +(Distance) const;    // add 2 distances (return new)
    void operator +=(Distance);   // add distance to existing   (does not return, only modifies)
    operator float() const          // convert to inches
    {
        float ffeet = inches/12;
        ffeet += static_cast<float>(feet);
        return ffeet/MTF;
    }

};

// Main
int main()
{
    Distance d1;            // 1st constructor
    Distance d2(11, 6.25);  // 2nd constructor
    Distance d3(5);         // 3rd constructor
    float mtrs;

    d1.getDistance();
    cout << "Distance d1 = ";
    d1.showDistance();
    cout << endl;
    cout << "Distance d2 = ";
    d2.showDistance();
    cout << endl;

    cout << "Distance d3 = ";
    d3.showDistance();
    cout << endl;

    mtrs = static_cast<float>(d2);      // user conversion operator

    cout << "Distance d2 = " << mtrs << " meters" << endl;

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
Distance Distance::operator+(Distance d2) const // Don't want to modify any existing thing.
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
