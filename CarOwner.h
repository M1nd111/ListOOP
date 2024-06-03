#pragma once
#include <iostream>
#include <string>

using namespace std;

struct CarOwner {
    string owner_surname;
    string owner_name;
    string owner_patronymic;
    string car_brand;
    int license_plate;

    CarOwner(const string& surname, const string& name, const string& patronymic, const string& brand, int plate)
        : owner_surname(surname), owner_name(name), owner_patronymic(patronymic), car_brand(brand), license_plate(plate) {}
};
