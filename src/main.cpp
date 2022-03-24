#include <ctime>
#include <string>
#include <iostream>
#include "../include/OnePrimeAPI.hpp"
#include "../include/CurrentExchangeUnit.hpp"

#define DELTA 10

using namespace std;

int main() {
    OnePrimeAPI* api = new OnePrimeAPI();

    Rate* r = NULL;
    string* curr = NULL;
    int size = 0;

    api->getRate(&curr, &r, &size);

    for (int i = 0; i < size; i++) {
        cout << curr[i] << ": " << r[i] << endl;
    }

    CurrentExchangeUnit* cu = new CurrentExchangeUnit(api);
    cu->getCurrencies(&curr, &size);
    Rate rat = cu->getRate(curr[0]);
    cout << "cu get rate = " << rat << endl;
    
    Rate a1 = Rate("123.9456");
    Rate a2 = Rate("234567.422225");
    
    Rate dans = a1 + a2;
    Rate ans = (a1 + a2) / 2;
    cout << a1 << " + " << a2 << " = " << dans << endl;
    cout << "ans = " << ans << endl;

    Rate b1 = Rate("2.2");
    Rate b2 = Rate("1.1");
    Rate bns = (b1 + b2) / 2;
    cout << bns << endl;

    // cout << "dr = " << dr;


}
