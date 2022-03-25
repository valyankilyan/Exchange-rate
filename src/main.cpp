#include <ctime>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include "../include/OnePrimeAPI.hpp"
#include "../include/CurrentExchangeUnit.hpp"
#include "../include/SillyExchangeTable.hpp"

#define DELTA 1
#define COUNT 3

using namespace std;

int main() {
    OnePrimeAPI* api = new OnePrimeAPI();

    Rate* r = NULL;
    string* curr = NULL;
    size_t size = 0;

    api->getRate(&curr, &r, &size);

    for (size_t i = 0; i < size; i++) {
        cout << curr[i] << ": " << r[i] << endl;
    }

    CurrentExchangeUnit* cu = new CurrentExchangeUnit(api);
    curr = cu->getCurrencies(&size);
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

    CurrentExchangeUnit* cu1 = new CurrentExchangeUnit(api);

    (*cu)+= *cu1;
    cout << (*cu) << endl;
    (*cu)/= 2;
    cout << (*cu) << endl;

    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    SillyExchangeTable SET = SillyExchangeTable(api);

    // vector <CurrentExchangeUnit*> v;
    // for (int i = 0; i < 10; i++) {
        
    //     v.push_back(new CurrentExchangeUnit(api));
    //     cout << "vector of units " << i << endl;
    //     sleep_for(seconds(DELTA));
    // }

    for (int i = 0; i < COUNT; i++) {
        // cout << "---------------" << i << endl;
        CurrentExchangeUnit* latest = SET.getLatest();
        cout << (*latest) << endl;
        
        sleep_for(seconds(DELTA));
    }

    CurrentExchangeUnit avg = SET.getAverageRates();
    cout << "AVERAGE:\n" << avg << endl << endl;

    // cout << "SET[0] = \n" << *(SET[0]) << endl;

    CurrentExchangeUnit med = SET.getMedianRates();
    cout << "MEDIAN:\n" << med << endl;


    // cout << "dr = " << dr;


}
