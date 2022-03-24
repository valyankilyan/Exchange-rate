#ifndef RATE_H
#define RATE_H

#include <string>
#include <iostream>

using namespace std;

#define RATE_MOD 1000000
#define MILL_LEN 6
#define MAX_UNIT_LEN 9
#define MAX_MILL_LEN 15

class Rate {
    public:

    Rate();
    Rate(string str);
    Rate(unsigned int u, unsigned int m);

    friend ostream& operator<<(ostream& os, Rate& rate);

    Rate operator+(const Rate &b);

    private:

    void Deserialize();
    void Serialize();

    void typeError();

    int units;
    int mill;
    bool serialized;
    string str;

};

#endif