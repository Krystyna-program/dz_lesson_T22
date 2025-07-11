#include "Computer.h"

Computer::Computer() {
    title = new char[30] { "undefined" };
    frequency = 0.0;
    ramSize = 0;
    hasDVD = false;
    price = 0.0f;
}

Computer::Computer(const char* _title, double _frequency, int _ramSize, bool _hasDVD, float _price) {
    int size_title = strlen(_title) + 1;
    title = new char[size_title];
    strcpy_s(title, size_title, _title);

    frequency = _frequency;
    ramSize = _ramSize;
    hasDVD = _hasDVD;
    price = _price;
}

Computer::Computer(const Computer& obj) {
    int size_title = strlen(obj.title) + 1;
    title = new char[size_title];
    strcpy_s(title, size_title, obj.title);

    frequency = obj.frequency;
    ramSize = obj.ramSize;
    hasDVD = obj.hasDVD;
    price = obj.price;
}

Computer& Computer::operator=(const Computer& obj) {
    if (this != &obj) {
        delete[] title;
        int size_title = strlen(obj.title) + 1;
        title = new char[size_title];
        strcpy_s(title, size_title, obj.title);

        frequency = obj.frequency;
        ramSize = obj.ramSize;
        hasDVD = obj.hasDVD;
        price = obj.price;
    }
    return *this;
}

Computer::~Computer() {
    delete[] title;
}

void Computer::setTitle(const char* _title) {
    if (strlen(_title) < 2) {
        cout << "Error: setTitle!\n";
    }
    else {
        delete[] title;
        int size_title = strlen(_title) + 1;
        title = new char[size_title];
        strcpy_s(title, size_title, _title);
    }
}

void Computer::setRAMSize(int _ramSize) {
    if (_ramSize >= 0)
        ramSize = _ramSize;
    else
        cout << "Error: setRAMSize!\n";
}

void Computer::setPrice(float _price) {
    if (_price > 0)
        price = _price;
    else
        cout << "Error: setPrice!\n";
}

const char* Computer::getTitle() const { return title; }
double Computer::getFrequency() const { return frequency; }
int Computer::getRAMSize() const { return ramSize; }
bool Computer::getDVD() const { return hasDVD; }
float Computer::getPrice() const { return price; }

void Computer::showInfo() const {
    cout << "Computer Title: " << title << endl;
    cout << "Frequency:      " << frequency << " GHz" << endl;
    cout << "RAM Size:       " << ramSize << " GB" << endl;
    cout << "DVD ROM:        ";
    if (hasDVD)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
    cout << "Price:          " << price << " UAH" << endl << endl;
}