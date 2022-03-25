#include "../include/SillyExchangeTable.hpp"
#include <algorithm>

SillyExchangeTable::SillyExchangeTable(CurrentExchangeAPI* api) {
    this->api = api;
    table.push_back(CurrentExchangeUnit(api));
    currencies = table[0].getCurrencies(&currencies_size);
}

SillyExchangeTable::~SillyExchangeTable() {
    delete[] currencies;
}

string* SillyExchangeTable::getCurrencies(size_t* size) {
    return table[0].getCurrencies(size);
}

void SillyExchangeTable::makeRequest() {
    table.push_back(CurrentExchangeUnit(api));
}

CurrentExchangeUnit& SillyExchangeTable::getLatest() {
    makeRequest();
    return table[table.size() - 1];
}

CurrentExchangeUnit& SillyExchangeTable::operator[](size_t num) {
    return table[num]; 
}

size_t SillyExchangeTable::size() {
    return table.size();
}

CurrentExchangeUnit SillyExchangeTable::getMedianRates() {
    CurrentExchangeUnit ans = table[0];
    vector <vector <Rate> > sortarray(currencies_size);
    for (size_t i = 0; i < table.size(); i++) {
        size_t rate_size = 0;
        Rate* rates = table[i].getAllRates(&rate_size);
        for (size_t j = 0; j < rate_size; j++) {
            sortarray[j].push_back(rates[j]);
        }
    }
    for (size_t i = 0; i < currencies_size; i++) {
        sort(sortarray[i].begin(), sortarray[i].end());
        cout << ans[i] << endl;
        ans[i] = sortarray[i][table.size() / 2];
    }
    return ans;
}

CurrentExchangeUnit SillyExchangeTable::getAverageRates() {
    CurrentExchangeUnit ans = table[0];
    for (size_t i = 1; i < table.size(); i++) {
        ans+= table[i];
    }
    ans/= table.size();
    return ans;
}

