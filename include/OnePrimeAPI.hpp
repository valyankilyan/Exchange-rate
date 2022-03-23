#ifndef ONEPRIME_API
#define ONEPRIME_API

// #include "ExchangeAPI.hpp"
#include <string>
#include <curl/curl.h>

using namespace std;

#define LINK "https://webservice.1prime.ru/pttable?host=1prime.ru&encoding=utf-8&template=prime_fxcur_jsonp&time=16"

class OnePrimeAPI {
    public:
        /**
         * @brief Construct a new OnePrimeAPI object
         * 
         * @param token 
         */
        OnePrimeAPI();

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

        void getJSON ();
        

        string* currencies;
        int* rate;
        int size;

        CURL *curl;
        CURLcode res;
};


#endif