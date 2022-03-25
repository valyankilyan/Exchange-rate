#ifndef ECHANGETABLE_H
#define ECHANGETABLE_H

#include "../include/CurrentExchangeAPI.hpp"
#include "../include/CurrentExchangeUnit.hpp"
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class SillyExchangeTable {
   public:
   /**
    * @brief Construct a new Silly Exchange Table object and makes first query
    * 
    * @param api 
    */
    SillyExchangeTable(CurrentExchangeAPI* api);

    ~SillyExchangeTable();

    /**
     * @brief Get the Currencies list and its size
     * 
     * @param currencies string array with names of currencies
     * @param size count of all the currencies CB gave
     */
    string* getCurrencies(size_t* size);
    
    /**
     * @brief makes request and adds it to the array
     * 
     * @return true 
     * @return false 
     */
    void makeRequest();

    /**
     * @brief make request and Get the Latest rates
     * 
     * @return CurrentExchangeUnit& 
     */
    CurrentExchangeUnit& getLatest();

    /**
     * @brief returns CurrenExchangeUnit object
     * 
     * @param num 
     * @return CurrentExchangeUnit 
     */
    CurrentExchangeUnit& operator[](size_t num);

    size_t size();

    /**
     * @brief Get the Median Rates CEU
     * 
     * @return CurrentExchangeUnit 
     */
    CurrentExchangeUnit getMedianRates();

    /**
     * @brief Get the Average Rates CEU
     * 
     * @return CurrentExchangeUnit 
     */
    CurrentExchangeUnit getAverageRates();

   private:

    void request_rates();
    
    size_t currencies_size;
    // currencies
    string* currencies;
    // table rate of currencies
    vector <CurrentExchangeUnit> table;
    // api
    CurrentExchangeAPI* api;
};

#endif