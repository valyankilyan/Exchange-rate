#include "../include/Rate.hpp"

Rate::Rate() {
    str = "";
    units = 0;
    mill = 0;
}

Rate::Rate(string _str) {
    this->str = _str;
    serialized = 1;
    Deserialize();
}

Rate::Rate(unsigned int u, unsigned int m) {
    serialized = 0;
    units = u;
    mill = m;
}

int Rate::getUnits() {
    return units;
}

int Rate::getMill() {
    return mill;
}

ostream& operator<<(ostream& os, Rate& rate) {
    if (!rate.serialized) {
        rate.Serialize();
    }
    os << rate.str;
    return os;
}

Rate Rate::operator+(const Rate& b) {
    Rate temp = *this;
    temp.mill += b.mill;
    temp.units += b.units + b.mill / RATE_MOD;
    temp.mill %= RATE_MOD;
    return temp;
}

bool Rate::operator<(const Rate &b) {
    bool ans = this->units < b.units;
    if (this->units == b.units) {
        ans = this->mill < b.mill;
    }
    return ans;
}

bool Rate::operator>(const Rate &b) {
    bool ans = this->units > b.units;
    if (this->units == b.units) {
        ans = this->mill > b.mill;
    }
    return ans;
}

bool Rate::operator==(const Rate &b) {
    return this->units == b.units && this->mill == b.mill;
}

bool Rate::operator<=(const Rate &b) {
    return operator<(b) || operator==(b);
}
bool Rate::operator>=(const Rate &b) {
    return operator>(b) || operator==(b);
}

void Rate::Deserialize() {
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
    for (size_t i = dot - 1; i != (size_t)-1; i--, pw *= 10) {
        units += pw * (str[i] - '0');
    }
    pw = RATE_MOD / 10;
    for (size_t i = dot + 1; i < str.size() && pw > 0; i++, pw /= 10) {
        mill += pw * (str[i] - '0');
    }
}

void Rate::Serialize() {
    str = "";
    int upw = 1, ulen = 0;
    while (units >= upw) {
        upw *= 10;
        ulen++;
    }
    upw /= 10;
    unsigned int temp = units;
    while (upw > 0) {
        str += (temp / upw) + '0';
        temp %= upw;
        upw /= 10;
    }
    if (units == 0) {
        str += '0';
    }

    temp = mill;
    int mlen = MILL_LEN;
    for (; mlen > 0; mlen--) {
        if (temp % 10 != 0)
            break;
        temp /= 10;
    }

    if (mlen != 0) {
        str += '.';
    }

    temp = mill;
    int mpw = RATE_MOD / 10;
    for (int i = 0; i < mlen && mpw > 0; i++) {
        int digit = temp / mpw;
        str += digit + '0';
        temp -= digit * mpw;
        mpw /= 10;
    }

    serialized = 1;
}

void Rate::typeError() {
    str = "0.0";
    return;
}