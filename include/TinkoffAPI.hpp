#ifndef TINKOFF_API
#define TINKOFF_API

#include "ExchangeAPI.hpp"
#include <string>
#include <ctime>

using namespace std;

#define TIME_FORMAT "%Y-%m-%dT%H:%M:%SZ"

class TinkoffAPI : ExchangeAPI {
    public:
        /**
         * @brief Construct a new TinkoffAPI object from api token
         * 
         * @param token 
         */
        TinkoffAPI(string token);

        /**
         * @brief Set the Token object
         * 
         * @param token 
         */
        void setToken(string token);

        /**
         * @brief Get all names of Currencies
         * 
         * @param currencies 
         * @param size 
         */
        void getCurrencies(string* currencies, int size);

        /**
         * @brief Get present Rate of all Currencies
         * 
         * @param currencies 
         * @param rate 
         * @param size 
         */
        void getRate(string* currencies, int* rate, int size);

        /**
         * @brief Get the Rate of all Currencies at exact time
         * 
         * @param currencies 
         * @param rate 
         * @param size 
         * @param datetime 
         */
        void getRate(string* currencies, int* rate, int size, time_t datetime);

    private:


        string token;
};


#endif