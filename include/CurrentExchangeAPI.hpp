#ifndef EXCHANGE_API
#define EXCHANGE_API

#include <ctime>
#include <string>
using namespace std;

class CurrentExchangeAPI {
   public:
    CurrentExchangeAPI(){}

    /**
     * @brief Get the array of Currencies strings
     *
     * @param currencies
     * @param size
     */
    virtual void getCurrencies(string* currencies, int size){}

    /**
     * @brief Get the Rate of all Currencies
     *
     * @param currencies
     * @param rate
     * @param size
     */
    virtual void getRate(string* currencies, int* rate, int size){}

   protected:
    string* currencies;
    int size;
};

#endif