#ifndef EXCHANGE_API
#define EXCHANGE_API

#include <ctime>
#include <string>

#include "../include/Rate.hpp"
using namespace std;


class CurrentExchangeAPI {
   public:
    CurrentExchangeAPI() {}

    /**
     * @brief Get the array of Currencies strings
     *
     * @param currencies
     * @param size
     */
    virtual void getCurrencies(string** currencies, int *size) {}

    /**
     * @brief Get the Rate of all Currencies
     *
     * @param currencies
     * @param rate
     * @param size
     */
    virtual void getRate(string** currencies, Rate** rate, size_t *size) {}

   protected:
    string* currencies;
    Rate* rate;
    int size;
};

#endif