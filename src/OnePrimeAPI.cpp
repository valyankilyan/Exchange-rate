#include "../include/OnePrimeAPI.hpp"
#include <iostream>
         
OnePrimeAPI::OnePrimeAPI(){
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, LINK);
    getJSON();
}
        
void OnePrimeAPI::getCurrencies(string* currencies, int size){
    
}

void OnePrimeAPI::getRate(string* currencies, int* rate, int size){
    
}

void OnePrimeAPI::getRate(string* currencies, int* rate, int size, time_t datetime){
    
}

void OnePrimeAPI::getJSON() {
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_perform(curl);
    } else {
        cerr << "curl wasn't inited\n";
    }
}