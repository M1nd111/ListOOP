#include <iostream>
#include <string>
#include "LinkedList.h"
#include "CarOwner.h"

using namespace std;

int main() {
    LinkedList<CarOwner> car_owners_list;

    car_owners_list.add(CarOwner("Korikov", "Mihail", "Evgenevich", "Toyota", 1));
    car_owners_list.add(CarOwner("Ivanova", "Anna", "Petrovna", "Honda", 24));
    car_owners_list.add(CarOwner("Sidorov", "Pavel", "Alexandrovich", "Ford", 3));
    car_owners_list.add(CarOwner("Smirnova", "Maria", "Sergeevna", "BMW", 46));
    car_owners_list.add(CarOwner("Popov", "Dmitry", "Vladimirovich", "Audi", 13)); // *
    car_owners_list.add(CarOwner("Mikhailov", "Svetlana", "Ivanovna", "Mercedes", 60));
    car_owners_list.add(CarOwner("Fedorov", "Andrey", "Nikolaevich", "Hyundai", 7)); 
    car_owners_list.add(CarOwner("Petrova", "Olga", "Dmitrievna", "Volkswagen", 8)); // *

    cout << "List of car owners:\n";
    car_owners_list.printList();

    cout << "Car owners with Fibonacci:\n";
    for (Iterator<CarOwner> it = car_owners_list.begin(); it != car_owners_list.end(); ++it) {
        cout << "License Plate: " << (*it).license_plate << ", Owner: " << (*it).owner_surname << " " << (*it).owner_name << " " << (*it).owner_patronymic << ", Car Brand: " << (*it).car_brand << endl;
    }

    return 0;
}
