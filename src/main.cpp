#include <ctime>
#include <string>
#include <iostream>
#include "../include/OnePrimeAPI.hpp"

using namespace std;

int main() {
    OnePrimeAPI api = OnePrimeAPI();

    Rate* r = NULL;
    string* curr = NULL;
    int size = 0;

    api.getRate(&curr, &r, &size);

    for (int i = 0; i < size; i++) {
        cout << curr[i] << ": " << r[i] << endl;
    }
}
