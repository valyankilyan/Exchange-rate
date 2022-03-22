#include "../include/ExchangeUnit.hpp"
#include <curl/curl.h>

ExchangeUnit::ExchangeUnit() {
    request_rates(time(0));
}

ExchangeUnit::ExchangeUnit(time_t time) {
    request_rates(time);
}

int ExchangeUnit::getRate(string rcurrency) {
    // returns ruble exhange rate relate to <rcurrency>
}

int ExchangeUnit::getRate(string currency, string rcurrency) {
    // returns <currency> exchange rate relate to <rcurrency>
}
