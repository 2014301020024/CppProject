//
// Created by wuli on 2022/9/23.
//

#include <iostream>

using namespace std;

#include "string"

#define MAX 1000

struct Person {
    string name;
    int sex = 0;
    int age = 0;
    string phone;
    string address;
};

struct AddressBooks {
    Person personArray[MAX];
    int size = 0;
};

void showMenu();

void addPerson(AddressBooks *abs);

void showPerson(AddressBooks *abs);

int isExisted(AddressBooks *abs, const string &name);

void searchPerson(AddressBooks *abs);

void deletePerson(AddressBooks *abs);

void changePerson(AddressBooks *abs);

void clearPerson(AddressBooks *abs);