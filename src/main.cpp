#include <ctime>
#include <string>
#include <iostream>
#include "../include/OnePrimeAPI.hpp"

using namespace std;

int main() {
    Rate r = Rate(1, 0);
    Rate a = Rate(123, 123000);
    Rate b = Rate(123, 123400);
    Rate c = Rate("123.123");

    cout << r.getUnits() << " " << a.getUnits() << " " << b.getUnits() << " " << c.getUnits() << endl;
    cout << r.getMill() << " " << a.getMill() << " " << b.getMill() << " " << c.getMill() << endl;
    cout << r << " " << a << " " << b << " " << c << endl;
    cout << (r < a) << " " << (a == c) << " " << (a >= b) << endl;
    cout << r << endl;    
    // OnePrimeAPI api = OnePrimeAPI();
}
