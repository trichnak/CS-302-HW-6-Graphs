#ifndef CITY
#define CITY

#include <iostream>
#include <fstream>
using namespace std;

class City {
public:
    std::string name;
    int position;

    City() {
        name = "";
        position = 0;
    }

    City(std::string name, int position) {
        this->name = name;
        this->position = position;
    }

    friend ostream& operator<<(ostream& os, const City& ct) {
        os << ct.name;
        return os;
    }
    friend ofstream& operator<<(ofstream& of, const City& ct) {
        of << ct.name;
        return of;
    }

    friend bool operator>(const City& a, const City& b) {
        return a.position > b.position;
    }
    friend bool operator>(const City& a, const int b) {
        return a.position > b;
    }

    friend bool operator<(const City& a, const City& b) {
        return a.position < b.position;
    }
    friend bool operator<(const City& a, const int b) {
        return a.position < b;
    }
};
#endif