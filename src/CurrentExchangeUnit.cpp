#include "../include/CurrentExchangeUnit.hpp"

#include <curl/curl.h>

CurrentExchangeUnit::CurrentExchangeUnit() {
    this->api = NULL;
}

CurrentExchangeUnit::CurrentExchangeUnit(CurrentExchangeAPI* api) {
    this->api = api;
    request_rates();
    rtime = time(0);
}

CurrentExchangeUnit::~CurrentExchangeUnit() {
    delete[] currencies;
    delete[] rate;
}

void CurrentExchangeUnit::setAPI(CurrentExchangeAPI* api) {
    this->api = api;
}

string* CurrentExchangeUnit::getCurrencies(size_t* size) {
    *size = this->size;
    string* temp = new string[this->size];
    for (size_t i = 0; i < this->size; i++) {
        temp[i] = this->currencies[i];
    }
    return temp;
}

Rate CurrentExchangeUnit::getRate(string rcurrency) {
    size_t ind = 0;
    for (; ind < size && rcurrency != currencies[ind]; ind++)
        ;
    if (ind == size) {
        return Rate(0, 0);
    } else {
        return rate[ind];
    }
}

Rate& CurrentExchangeUnit::operator[](size_t num) {
    return rate[num];
}

CurrentExchangeUnit CurrentExchangeUnit::operator+(const CurrentExchangeUnit& b) {
    CurrentExchangeUnit ans = *this;
    if (ans.size != b.size) {
        cerr << "Sizes of two additional objects don't match\n";
        return ans;
    }
    for (size_t i = 0; i < size; i++) {
        if (ans.currencies[i] != b.currencies[i]) {
            cerr << "Currencies of two additional object doesn't match\n";
            return ans;
        }
        ans.rate[i] += b.rate[i];
    }
    return ans;
}

void CurrentExchangeUnit::operator+=(const CurrentExchangeUnit& b) {
    if (this->size != b.size) {
        cerr << "Sizes of two additional objects don't match\n";
        return;
    }
    for (size_t i = 0; i < size; i++) {
        if (this->currencies[i] != b.currencies[i]) {
            cerr << "Currencies of two additional object doesn't match\n";
            return;
        }
        this->rate[i] += b.rate[i];
    }
}

CurrentExchangeUnit CurrentExchangeUnit::operator/(int d) {
    CurrentExchangeUnit ans = *this;
    for (size_t i = 0; i < size; i++) {
        ans.rate[i] /= d;
    }
    return ans;
}

void CurrentExchangeUnit::operator/=(int d) {
    for (size_t i = 0; i < size; i++) {
        this->rate[i] /= d;
    }
}

ostream& operator<<(ostream& os, CurrentExchangeUnit& ceu) {
    os << "Exchange Rate:\n";
    for (size_t i = 0; i < ceu.size; i++) {
        os << ceu.currencies[i] << ": " << ceu.rate[i] << endl;
    }
    return os;
}

void CurrentExchangeUnit::copy(const CurrentExchangeUnit &b) {
    this->api = b.api;
    this->size = b.size;
    this->currencies = new string[size];
    this->rate = new Rate[size];

    for (size_t i = 0; i < b.size; i++) {
        this->currencies[i] = b.currencies[i];
        this->rate[i] = b.rate[i];
    }
}

Rate* CurrentExchangeUnit::getAllRates(size_t* size) {
    *size = this->size;
    Rate* temp = new Rate[this->size];
    for (size_t i = 0; i < this->size; i++) {
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

void CurrentExchangeUnit::_from_any_variables(size_t size, const string* currencies,
                                              const Rate* rate, CurrentExchangeAPI* api) {
    this->size = size;
    this->currencies = new string[size];
    this->rate = new Rate[size];
    for (size_t i = 0; i < size; i++) {
        this->currencies[i] = currencies[i];
        this->rate[i] = rate[i];
    }
    this->api = api;
}