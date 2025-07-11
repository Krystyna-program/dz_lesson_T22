#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Computer {
    char* title;
    double frequency;        
    int ramSize;
    bool hasDVD;             
    float price;

public:
    Computer();
    Computer(const char* _title, double _frequency, int _ramSize, bool _hasDVD, float _price);
    Computer(const Computer& obj);
    Computer& operator=(const Computer& obj);
    ~Computer();

    void setTitle(const char* _title);
    void setRAMSize(int _ramSize);
    void setPrice(float _price);

    const char* getTitle() const;
    double getFrequency() const;
    int getRAMSize() const;
    bool getDVD() const;
    float getPrice() const;

    void showInfo() const;
};