#ifndef ECHANGE_UNIT
#define ECHANGE_UNIT

#include <ctime>
#include <string>

using namespace std;

class ExchangeUnit {
   public:
    /**
     * @brief Construct a new Exchange Unit object
     * with current exchange rate
     */
    ExchangeUnit();

    /**
     * @brief Construct a new Exchange Unit object
     * with exchange rate at given time
     * 
     * @param time when exchange rate was taken 
     */
    ExchangeUnit(time_t time);


    /**
     * @brief Get the Rate
     * for ruble related to <rcurrency>
     * 
     * @param rcurrency name of currency ruble related to 
     * @return int rate * 10^4
     */
    int getRate(string rcurrency);

    /**
     * @brief Get the Rate object
     * for <currency> related to <rcurrency>
     * 
     * @param currency name of main currency 
     * @param rcurrency name of currency main currency related to 
     * @return int rate * 10^4
     */
    int getRate(string currency, string rcurrency);

    
    /**
     * @brief Get the Currencies list and its size
     * 
     * @param currencies string array with names of currencies
     * @param size count of all the currencies CB gave
     */
    void getCurrencies(string* currencies, int* size);

   private:

    void request_rates(time_t time);

    // time of rates
    time_t rtime;
    // size of currencies
    int size;
    // names of currencies
    string* currencies;
    // rate of currencies
    int* rate;
};

#endif