// File: MyTime.cpp
// Created by Sean Bigler on 10/12/2017 for CS1410.
// Copyright (c) 2017 WSU
//
#include <iostream>

using namespace std;
// Constants, Structs, Classes
class time12
{
private:
    bool pm;    // true = pm, false = am
    int hrs;
    int mins;
public:
    time12(): pm(true), hrs(0), mins(0)
    {}
    time12(bool ap, int h, int m)
    {
        pm = ap;
        hrs = h;
        mins = m;
    }
    void display() const    // Format: HH:MM p.m
    {
        cout << hrs << ':';
        if(mins < 10)
            cout << '0';
        cout << mins << ' ';
        // Test for true or false
        string am_pm = pm ? "p.m." : "a.m";     // if pm is true, then first. if false, then second
        cout << am_pm;
    }
};

class time24
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    time24(): hours(0), minutes(0), seconds(0)  // Default constructor
    {}
    time24(int h, int m, int s)         // Constructor 3 arguments
    {
        hours = h;
        minutes = m;
        seconds = s;
    }
    void display() const    // format:  23:13:01  HH:MM:SS
    {
        if(hours < 10)
            cout << '0';
        cout << hours << ":";

        if(minutes < 10)
            cout << '0';
        cout << minutes << ":";

        if(seconds < 10)
            cout << '0';
        cout << seconds;
    }
};

// Prototypes


// Main Program
int main()
{
    time24 t1;
    time24 t2(12, 2, 40);

    time12 t3;
    time12 t4(false, 2, 40);
    t1.display();
    cout << endl;
    t2.display();
    cout << endl;
    t3.display();
    cout << endl;
    t4.display();

    return 0;
}

// Function Definitions