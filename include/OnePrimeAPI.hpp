#ifndef ONEPRIME_API
#define ONEPRIME_API

#include "CurrentExchangeAPI.hpp"
#include <string>
#include <curl/curl.h>

using namespace std;

#define LINK "https://webservice.1prime.ru/pttable?host=1prime.ru&encoding=utf-8&template=prime_fxcur_jsonp&time=16"

class OnePrimeAPI : CurrentExchangeAPI {
    public:
        /**
         * @brief Construct a new OnePrimeAPI object
         * 
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

    private:

        void getJSON (string *response_string);
        

        string* currencies;
        int* rate;
        int size;

        CURL *curl;
};


#endif