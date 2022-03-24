#include "../include/CurrentExchangeUnit.hpp"
#include <curl/curl.h>

CurrentExchangeUnit::CurrentExchangeUnit(CurrentExchangeAPI* api) {
    this->api = api;
    request_rates();
    rtime = time(0);
}

void CurrentExchangeUnit::getCurrencies(string** currencies, int* size) {
    *size = this->size;
    string* temp = new string[this->size];
    for (int i = 0; i < this->size; i++) {
        temp[i] = this->currencies[i];        
    }
    *currencies = temp;
}
 
Rate CurrentExchangeUnit::getRate(string rcurrency) {
    int ind = 0;
    for (; ind < size && rcurrency != currencies[ind]; ind++);
    if (ind == size) {
        return Rate(0, 0);
    } else {
        return rate[ind];
    }
}

void CurrentExchangeUnit::request_rates() {
    api->getRate(&currencies, &rate, &size);
}