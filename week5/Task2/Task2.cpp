#include <iostream>
#include "Task2.h"
#include <cstring>

const char *Beer::getBrand() const
{
    return this->brand;
}
const int Beer::getMililiters() const
{
    return this->mililiters;
}
void Beer::setBrand(const char *brand)
{
    this->brand = new char[strlen(brand)];
    strcpy(this->brand, brand);
}
void Beer::setMililiters(const int mililiters)
{
    this->mililiters = mililiters;
}
Beer::Beer()
{
    this->brand = new char[1];
    strcpy(this->brand, "");
    this->mililiters = 0;
}
Beer::Beer(const char *brand, const int mililiters)
{
    setBrand(brand);
    setMililiters(mililiters);
}
void Beer::erase()
{
    delete[] brand;
}
const Beer &Beer::add(Beer &other, int addMililiters)
{
    this->mililiters = other.getMililiters() + addMililiters;
    char *copyBeerMark = new char[strlen(this->brand) + 1];
    strcpy(copyBeerMark, this->brand);
    erase();
    this->brand = new char[strlen(other.brand) + strlen(copyBeerMark) + 2];
    strcpy(this->brand, copyBeerMark);
    strcat(this->brand, "&");
    strcat(this->brand, other.getBrand());
    other.setMililiters(other.getMililiters() - addMililiters);
    return *this;
}

bool Beer::check(const char *brand)
{
    int count = 0;
    char *copyBeerMark = new char[32];
    //coppy data from the class to compare
    while (this->brand[count] != '&' && this->brand[count] != '\0')
    {
        copyBeerMark[count] = this->brand[count];
        count++;
    }
    copyBeerMark[count]='\0';
    if (!strcasecmp(brand, copyBeerMark))
    {
        delete[] copyBeerMark;
        return true;
    }
    //if havent &
    if(this->brand[count] == '\0'){
        return false;
    }
    int secondCount = 0;
    count++;
    //coppy data from the class if have & between to compare
    while (this->brand[count] != '&' && this->brand[count] != '\0')
    {
        copyBeerMark[secondCount] = this->brand[count];
        count++;
        secondCount++;
    }
    copyBeerMark[secondCount] = '\0';
    
    if (!strcasecmp(brand, copyBeerMark))
    {
        delete[] copyBeerMark;
        return true;
    }
    delete[] copyBeerMark;
    return false;
}
Beer::~Beer()
{
    erase();
}
