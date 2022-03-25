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
    Rate* getAllRates(size_t *size);

    /**
     * @brief Get the Currencies object
     * 
     * @param size 
     * @return string* 
     */
    string* getCurrencies(size_t* size);


    /**
     * @brief Get the Time object
     * 
     * @return time_t 
     */
    time_t getTime();
    
    // /**
    //  * @brief get currency rate by its name
    //  * 
    //  * @param rcurrenciy 
    //  * @return Rate 
    //  */
    // Rate operator[](string rcurrenciy);
    
    /**
     * @brief get Rate object by it's number
     * 
     * @param num 
     * @return Rate 
     */
    Rate& operator[](size_t num);

    CurrentExchangeUnit operator+(const CurrentExchangeUnit &b);
    void operator+=(const CurrentExchangeUnit &b);
    CurrentExchangeUnit operator/(int d);
    void operator/=(int d);

    friend ostream& operator<<(ostream& os, CurrentExchangeUnit &ceu);

    void _from_any_variables(size_t size, const string* currencies, const Rate* rate, CurrentExchangeAPI* api);

    // CurrentExchangeUnit operator=(const CurrentExchangeUnit &b);
    

   private:

    void request_rates();

    // time of rates
    time_t rtime;
    // size of currencies
    size_t size;
    // names of currencies
    string* currencies;
    // rate of currencies
    Rate* rate;
    // api
    CurrentExchangeAPI* api;
};

#endif