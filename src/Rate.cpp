#include "../include/Rate.hpp"

Rate::Rate() {
    str = "";
    units = 0;
    mill = 0;
}

Rate::Rate(string _str) {
    this->str = _str;
    rateDeserialize();
}

Rate::Rate(unsigned int u, unsigned int m) {

}


ostream& operator<<(ostream& os, const Rate& rate) {
    os << rate.str;
    return os;
}

Rate Rate::operator+(const Rate &b) {
    Rate temp = *this;
    temp.mill+= b.mill;
    temp.units+= b.units + b.mill / RATE_MOD;
    temp.mill%= RATE_MOD;
}

void Rate::rateDeserialize() {
    units = 0;
    mill = 0;
    size_t dot = 0;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '.') {
            if (dot != 0 || i == 0) {                
                return typeError();
            }
            dot = i;
        } else if (!(str[i] >= '0' && str[i] <= '9')) {
            return typeError();
        }
    }

    if (dot >= MAX_UNIT_LEN || str.size() - dot >= MAX_MILL_LEN) {
        return typeError();
    }

    int pw = 1;
    for(size_t i = dot - 1; i != -1; i--, pw*= 10) {
        units+= pw * (str[i] - '0');
    }
    pw = RATE_MOD;
    for (size_t i = dot + 1; i <= str.size() && pw > 0; i++, pw/= 10) {
        mill+= pw * (str[i] - '0');
    }
}

void Rate::rateSerialize() {

}

void Rate::typeError() {
    cerr << "#TYPE ERROR: number required, but " << str << " given\n";
    str = "0.0";
    return;
}