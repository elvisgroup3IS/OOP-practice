#include "Task2.cpp" 
int main(){
    Beer beer1("Stella Artois",500);
    Beer beer2("Beeks",500);
    beer1.add(beer2,400);
    std::cout<<beer1.getMililiters()<<std::endl;
    std::cout<<beer2.getBrand()<<std::endl;  
    std::cout<< beer2.getMililiters()<<std::endl;  
    std::cout<<std::boolalpha<<beer1.check("Beeks")<<std::endl;
}