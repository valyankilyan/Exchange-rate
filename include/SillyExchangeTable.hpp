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
    string* getCurrencies(int* size);
    
    /**
     * @brief makes request and adds it to the array
     * 
     * @return true 
     * @return false 
     */
    void makeRequest();

    /**
     * @brief returns CurrenExchangeUnit object
     * 
     * @param num 
     * @return CurrentExchangeUnit 
     */
    CurrentExchangeUnit& operator[](size_t num);

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

   private:

    void request_rates();
    
    // size of Table
    int size;
    // currencies
    string* currencies;
    // table rate of currencies
    vector <CurrentExchangeUnit> table;
    // api
    CurrentExchangeAPI* api;
};

#endif