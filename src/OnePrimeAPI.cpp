#include "../include/OnePrimeAPI.hpp"
#include <iostream>

size_t writeFunction(void *ptr, size_t size, size_t nmemb, string* data);
         
OnePrimeAPI::OnePrimeAPI(){
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, LINK);

    string response_string;
    getJSON(&response_string);
    cout << response_string;
}
        
void OnePrimeAPI::getCurrencies(string* currencies, int size){
    
}

void OnePrimeAPI::getRate(string* currencies, int* rate, int size){
    
}

void OnePrimeAPI::getJSON(string *response_string) {
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_string);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    } else {
        cerr << "curl wasn't inited\n";
    }
}

size_t writeFunction(void *ptr, size_t size, size_t nmemb, string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}