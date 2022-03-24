#ifndef RATE_H
#define RATE_H

#include <string>
#include <iostream>

using namespace std;

#define RATE_MOD 1000000
#define MILL_LEN 6
#define MAX_UNIT_LEN 9
#define MAX_MILL_LEN 15

class Rate {
    public:

    /**
     * @brief Construct a new Rate object
     * 
     */
    Rate();

    /**
     * @brief Construct a new Rate object from rate string
     * 
     * @param str 
     */
    Rate(string str);

    /**
     * @brief Construct a new Rate object from units and milli variables
     * 
     * @param u 
     * @param m 
     */
    Rate(int u, int m);

    /**
     * @brief Get the Units object
     * 
     * @return int 
     */
    int getUnits();

    /**
     * @brief Get the Mill object
     * 
     * @return int 
     */
    int getMill();


    /**
     * @brief returns string representation of rate
     * 
     * @param os 
     * @param rate 
     * @return ostream& 
     */
    friend ostream& operator<<(ostream& os, Rate& rate);

    Rate operator+(const Rate &b);
    Rate operator/(const int d);
    
    bool operator<(const Rate &b);
    bool operator>(const Rate &b);
    bool operator==(const Rate &b);
    bool operator<=(const Rate &b);
    bool operator>=(const Rate &b);

    private:

    /**
     * @brief Deserializes from string object
     * 
     */
    void Deserialize();

    /**
     * @brief Serializes from units and milli objects 
     * 
     */
    void Serialize();

    /**
     * @brief prints type error
     * I didn' want to learn how to make proper exceptions
     */
    void typeError();

    /**
     * @brief makes Rate from long double units and long double mills
     * 
     * @param u 
     * @param m 
     */
    void from_long_double(long double u, long double m);

    int units;
    int mill;
    bool serialized;
    string str;

};

#endif