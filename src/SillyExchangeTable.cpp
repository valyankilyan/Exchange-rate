#include "../include/SillyExchangeTable.hpp"

SillyExchangeTable::SillyExchangeTable(CurrentExchangeAPI* api) {
    this->api = api;
    table.push_back(CurrentExchangeUnit(api));
    currencies = table[0].getCurrencies(&size);
}

SillyExchangeTable::~SillyExchangeTable() {
    delete api;
    delete[] currencies;
}

string* SillyExchangeTable::getCurrencies(int* size) {
    return table[0].getCurrencies(size);
}

void SillyExchangeTable::makeRequest() {
    table.push_back(CurrentExchangeUnit(api));
}

CurrentExchangeUnit& SillyExchangeTable::operator[](size_t num) {
    return table[num]; 
}

