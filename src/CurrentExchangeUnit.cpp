#include "../include/CurrentExchangeUnit.hpp"
#include <curl/curl.h>

CurrentExchangeUnit::CurrentExchangeUnit(CurrentExchangeAPI* api) {
    this->api = api;
    request_rates();
    rtime = time(0);
}

CurrentExchangeUnit::~CurrentExchangeUnit() {
    delete[] currencies;
    delete[] rate;
}

string* CurrentExchangeUnit::getCurrencies(int* size) {
    *size = this->size;
    string* temp = new string[this->size];
    for (int i = 0; i < this->size; i++) {
        temp[i] = this->currencies[i];        
    }
    return temp;
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

Rate CurrentExchangeUnit::operator[](string rcurrency) {
    return getRate(rcurrency);
}

Rate* CurrentExchangeUnit::getAllRates(int *size) {
    *size = this->size;
    Rate* temp = new Rate[this->size];
    for (int i = 0; i < this->size; i++) {
        temp[i] = this->rate[i];
    }  
    return temp;
}


time_t CurrentExchangeUnit::getTime() {
    return rtime;
}

void CurrentExchangeUnit::request_rates() {
    api->getRate(&currencies, &rate, &size);
}