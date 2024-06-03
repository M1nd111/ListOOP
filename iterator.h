#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include "Node.h"

using namespace std;

template<typename T>
class Iterator {
private:
    Node<T>* slider;

    bool IsFibonacci(int num) {
        int a = 0, b = 1, c = 0;
        while (c < num) {
            c = a + b;
            a = b;
            b = c;
        }
        return num == c;
    }

    void move_to_next() {
        while (slider != nullptr) {
            if (IsFibonacci(slider->data.license_plate)) {
                break;
            }
            slider = slider->next;
        }
    }

public:
    Iterator(Node<T>* start) : slider(start) {
        move_to_next();
    }

    Iterator& operator++() {
        if (slider != nullptr) {
            slider = slider->next;
            move_to_next();
        }
        return *this;
    }

    T operator*() {
        return slider->data;
    }

    bool operator==(const Iterator& it) {
        return slider == it.slider;
    }

    bool operator!=(const Iterator& it) {
        return !(*this == it);
    }
};
