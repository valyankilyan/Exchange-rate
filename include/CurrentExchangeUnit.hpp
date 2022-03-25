#ifndef CURRENTECHANGEUNIT_H
#define CURRENTECHANGEUNIT_H

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
     * @brief Get the All Rates object
     * 
     * @param size 
     * @return Rate* 
     */
    Rate* getAllRates(int *size);

    /**
     * @brief Get the Currencies object
     * 
     * @param size 
     * @return string* 
     */
    string* getCurrencies(int* size);


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