#ifndef EXCHANGE_API
#define EXCHANGE_API

#include <ctime>
#include <string>
using namespace std;

class ExchangeAPI {
   public:
    /**
     * @brief Get the array of Currencies strings
     *
     * @param currencies
     * @param size
     */
    virtual void getCurrencies(string* currencies, int size);

    /**
     * @brief Get the Rate of all Currencies
     *
     * @param currencies
     * @param rate
     * @param size
     */
    virtual void getRate(string* currencies, int* rate, int size);

    /**
     * @brief Get the Rate of all Currencies at exact times
     *
     * @param currencies
     * @param rate
     * @param size
     * @param datetime
     */
    virtual void getRate(string* currencies, int* rate, int size, time_t datetime);

   protected:
    string* currencies;
    int size;
};

#endif