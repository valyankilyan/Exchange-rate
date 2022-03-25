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

CurrentExchangeUnit CurrentExchangeUnit::operator+(const CurrentExchangeUnit &b) {
    CurrentExchangeUnit ans = *this;
    if (ans.size != b.size) {
        cerr << "Sizes of two additional objects don't match\n";
        return ans;
    }
    for (int i = 0; i < size; i++) {
        if (ans.currencies[i] != b.currencies[i]){
            cerr << "Currencies of two additional object doesn't match\n";
            return ans;
        }
        ans.rate[i]+= b.rate[i];
    }
    return ans;
}

void CurrentExchangeUnit::operator+=(const CurrentExchangeUnit &b) {
    if (this->size != b.size) {
        cerr << "Sizes of two additional objects don't match\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        if (this->currencies[i] != b.currencies[i]){
            cerr << "Currencies of two additional object doesn't match\n";
            return;
        }
        this->rate[i]+= b.rate[i];
    }
}

CurrentExchangeUnit CurrentExchangeUnit::operator/(int d) {
    CurrentExchangeUnit ans = *this;
    for (int i = 0; i < size; i++) {
        ans.rate[i]/= d;
    }
    return ans;
}

void CurrentExchangeUnit::operator/=(int d) {
    for (int i = 0; i < size; i++) {
        this->rate[i]/= d;
    }
}

ostream& operator<<(ostream& os, CurrentExchangeUnit &ceu) {
    os << "Exchange Rate:\n";
    for (int i = 0; i < ceu.size; i++) {
        os << ceu.currencies[i] << ": " << ceu.rate[i] << endl;
    }
    return os;
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