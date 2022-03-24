#include "../include/OnePrimeAPI.hpp"
#include <iostream>
#include <typeinfo>
         
size_t writeFunction(void *ptr, size_t size, size_t nmemb, string* data);

OnePrimeAPI::OnePrimeAPI(){
    currencies = NULL;
    rate = NULL;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, LINK);

    string response_string;
    getJSON(&response_string); 
    // cout << response_string;

    json j = json::parse(response_string);
    updateData(&j);
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

void OnePrimeAPI::updateData(json* j) {
    delete [] currencies;
    delete [] rate;
    size = j->size();
    currencies = new string[size];
    rate = new Rate[size];

    cout << "json.size() = " << j->size() << endl;
    // cout << j[0]["date"] << " " << j[1] << endl;

    int id = 0;
    for (json::iterator it = j->begin(); it != j->end(); it++, id++) {
        currencies[id] = (*it)["name"];
        string rate = (*it)["value"].dump();
        cout << rate << endl;
        // rate[id] = (*it)["value"];
        cout << typeid((*it)["value"]).name() << endl;

        // cout << (*it) << endl;
        // cout << currencies[id] << ": " << rate[id] << endl;
    }
    // for (int i = 0; i < j->size(); i++) {
    //     cout << j[i] << " ";
    // }
}

void OnePrimeAPI::writeToUnits(Rate *r) {
    size_t dot = -1;
    for (int i = 0; i < r->str.size(); i++) {
        if (r->str[i] == '.') {
            if (dot != -1) {
                cerr << "#TYPE ERROR: number required, but " << r->str << " given\n";
                r->units = 0;
                r->mill = 0;
                return;
            }
            dot = i;
        }
    }
}

