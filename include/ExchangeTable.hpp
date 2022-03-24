#ifndef ECHANGETABLE_H
#define ECHANGETABLE_H

#include "../include/CurrentExchangeAPI.hpp"
#include "../include/CurrentExchangeUnit.hpp"
#include <ctime>
#include <string>

using namespace std;

class ExchangeTable {
   public:
    /**
     * @brief Construct a new Exchange Table object
     * 
     * @param api 
     * @param delta 
     * @param duration 
     */
    ExchangeTable(CurrentExchangeAPI* api, time_t delta, time_t duration);

    /**
     * @brief Construct a new Exchange Table object
     * 
     * @param api 
     * @param delta 
     * @param times count of 
     */
    ExchangeTable(CurrentExchangeAPI* api, time_t delta, int times);
    

    ~ExchangeTable();

    /**
     * @brief Get the Currencies list and its size
     * 
     * @param currencies string array with names of currencies
     * @param size count of all the currencies CB gave
     */
    void getCurrencies(string** currencies, int* size);

    /**
     * @brief returns whether it's been updated from the last query
     * assigns is_updated to False after call
     * @return true 
     * @return false 
     */
    bool isUpdated();

    /**
     * @brief Get the Median Rates array
     * 
     * @param currencies 
     * @param mrates 
     * @param size 
     * @return Rate 
     */
    Rate getMedianRates(string** currencies, Rate** mrates, int* size);

    /**
     * @brief Get the Average Rates array
     * 
     * @param currencies 
     * @param arates 
     * @param size 
     * @return Rate 
     */
    Rate getAverageRates(string** currencies, Rate** arates, int* size);


    /**
     * @brief Get the Time object
     * 
     * @return time_t 
     */
    time_t startTime();

    time_t endTime();

   private:

    void request_rates();

    // time of start and finish
    time_t stime, ftime;
    // size of Table
    int size;
    // rate of currencies
    CurrentExchangeUnit* table;
    // api
    CurrentExchangeAPI* api;
};

#endif