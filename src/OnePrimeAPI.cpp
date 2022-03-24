#include "../include/OnePrimeAPI.hpp"
#include <iostream>
#include <typeinfo>
         
size_t writeFunction(void *ptr, size_t size, size_t nmemb, string* data);

OnePrimeAPI::OnePrimeAPI(){
    currencies = NULL;
    rate = NULL;

    updateData();
}

OnePrimeAPI::~OnePrimeAPI() {
    curl_easy_cleanup(curl);
    delete[] currencies;\
    delete[] rate;
}
        
void OnePrimeAPI::getCurrencies(string** currencies, int *size){
    string* temp = new string[this->size];
    for (int i = 0; i < this->size; i++) {
        temp[i] = this->currencies[i];
    }
    *currencies = temp;
    *size = this->size;
}

void OnePrimeAPI::getRate(string** currencies, Rate** rate, int *size){
    updateData();
    string* tempc = new string[this->size];
    Rate* tempr = new Rate[this->size];
    *size = this->size;
    for (int i = 0; i < this->size; i++) {
        tempc[i] = this->currencies[i];
    }

    for (int i = 0; i < this->size; i++) {
        tempr[i] = this->rate[i];
    }

    *currencies = tempc;
    *rate = tempr;
}

void OnePrimeAPI::getJSON(string *response_string) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, LINK);
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_string);
        curl_easy_perform(curl);
    } else {
        cerr << "curl wasn't inited\n";
    }
}

size_t writeFunction(void *ptr, size_t size, size_t nmemb, string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

void OnePrimeAPI::updateData() {
    string response_string;
    getJSON(&response_string); 

    json j = json::parse(response_string);

    delete [] currencies;
    delete [] rate;
    size = j.size();
    currencies = new string[size];
    rate = new Rate[size];

    int id = 0;
    for (json::iterator it = j.begin(); it != j.end(); it++, id++) {
        currencies[id] = (*it)["id"];
        rate[id] = Rate((*it)["value"].dump());
    }
}

