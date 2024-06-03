#pragma once
#include <iostream>
#include "Node.h"
#include "Iterator.h"

using namespace std;

template<typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    // Default constructor
    LinkedList() : head(nullptr) {}

    // Constructor to create a list with a single node
    LinkedList(T data) {
        head = new Node<T>(data);
    }

    Iterator<T> begin() { return Iterator<T>(head); }

    void add(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* slider = head;
        while (slider->next != nullptr) {
            slider = slider->next;
        }
        slider->next = newNode;
    }

    // Method to delete a node with a specific value
    void remove(T data) {
        if (head == nullptr) return;

        // If the head needs to be removed
        if (head->data == data) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* slider = head;
        while (slider->next != nullptr && slider->next->data != data) {
            slider = slider->next;
        }

        if (slider->next == nullptr) return; // Node with the given data not found

        Node<T>* nodeToDelete = slider->next;
        slider->next = slider->next->next;
        delete nodeToDelete;
    }

    ~LinkedList() {
        Node<T>* slider = head;
        while (slider != nullptr) {
            Node<T>* next = slider->next;
            delete slider;
            slider = next;
        }
        head = nullptr;
    }

    Iterator<T> end() { return Iterator<T>(nullptr); }

    void printList() {
        Node<T>* slider = head;
        while (slider != nullptr) {
            cout << "Owner: " << slider->data.owner_surname << " " << slider->data.owner_name << " " << slider->data.owner_patronymic;
            cout << ", Car Brand: " << slider->data.car_brand;
            cout << ", License Plate: " << slider->data.license_plate << endl;
            slider = slider->next;
        }
        cout << "\n";
    }
};
