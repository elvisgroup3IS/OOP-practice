#pragma once

class Beer{
    private:
    char *brand;
    int mililiters;

    public:
    void setBrand(const char * brand);
    void setMililiters(const int mililiters);
    const char * getBrand()const;
    const int getMililiters()const;
    Beer();
    Beer(const char* brand,const int mililiters);
    ~Beer();
    const Beer& add(Beer& other,int addMililiters);
    void isPrimes();
    bool check(const char * brand);  
    void erase() ;
};