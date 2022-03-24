#ifndef RATE_H
#define RATE_H

#include <string>
#include <iostream>

using namespace std;

#define RATE_MOD 1000000
#define MAX_UNIT_LEN 9
#define MAX_MILL_LEN 15

class Rate {
    public:

    Rate();
    Rate(string str);
    Rate(unsigned int u, unsigned int m);

    friend ostream& operator<<(ostream& os, const Rate& rate);

    Rate operator+(const Rate &b);

    private:

    void rateDeserialize();
    void rateSerialize();

    void typeError();

    unsigned int units;
    unsigned int mill;
    string str;

};

#endif