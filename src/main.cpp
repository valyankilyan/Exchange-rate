#include <ctime>
#include <string>
#include <iostream>
#include "../include/OnePrimeAPI.hpp"
#include "../include/CurrentExchangeUnit.hpp"

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
}
