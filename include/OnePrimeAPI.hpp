#ifndef ONEPRIME_API
#define ONEPRIME_API

#include <string>
#include <curl/curl.h>

#include "CurrentExchangeAPI.hpp"
#include "../json/single_include/nlohmann/json.hpp"


using json = nlohmann::json;
using namespace std;

#define LINK "https://webservice.1prime.ru/pttable?host=1prime.ru&encoding=utf-8&template=prime_fxcur_jsonp&time=16"

class OnePrimeAPI : public CurrentExchangeAPI {
    public:
        /**
         * @brief Construct a new OnePrimeAPI object
         * 
         */
        OnePrimeAPI();

        /**
         * @brief Destroy the One Prime Api object
         * 
         */
        ~OnePrimeAPI();

        /**
         * @brief Get all names of Currencies
         * 
         * @param currencies 
         * @param size 
         */
        void getCurrencies(string** currencies, int *size);

        /**
         * @brief Get present Rate of all Currencies
         * 
         * @param currencies 
         * @param rate 
         * @param size 
         */
        void getRate(string** currencies, Rate** rate, int *size);

    private:

        /**
         * @brief gives JSON data from oneprime request
         * 
         * @param response_string 
         */
        void getJSON (string *response_string);

        /**
         * @brief updates data to the latest one
         * 
         */
        void updateData();

        string* currencies;
        Rate* rate;
        int size;

        CURL *curl;
};


#endif