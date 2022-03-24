#ifndef CURRENTECHANGE_UNIT
#define CURRENTECHANGE_UNIT

#include "../include/CurrentExchangeAPI.hpp"
#include <ctime>
#include <string>

using namespace std;

class CurrentExchangeUnit {
   public:
    /**
     * @brief Construct a new Exchange Unit object
     * with current exchange rate
     */
    CurrentExchangeUnit(CurrentExchangeAPI* api);

    ~CurrentExchangeUnit();

    /**
     * @brief Get the Rate
     * for ruble related to <rcurrency>
     * 
     * @param rcurrency name of currency ruble related to 
     * @return Rate rate;
     */
    Rate getRate(string rcurrency);
    
    /**
     * @brief Get the Rates for all currencies
     * 
     * @param currencies 
     * @param rate 
     * @param size 
     */
    void getAllRates(string** currencies, Rate** rate, int *size);

    /**
     * @brief Get the Currencies list and its size
     * 
     * @param currencies string array with names of currencies
     * @param size count of all the currencies CB gave
     */
    void getCurrencies(string** currencies, int* size);


    /**
     * @brief Get the Time object
     * 
     * @return time_t 
     */
    time_t getTime();

   private:

    void request_rates();

    // time of rates
    time_t rtime;
    // size of currencies
    int size;
    // names of currencies
    string* currencies;
    // rate of currencies
    Rate* rate;
    // api
    CurrentExchangeAPI* api;
};

#endif