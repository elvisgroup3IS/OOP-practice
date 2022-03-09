#include <iostream>
#include <cstring>
struct Doctor
{
    char surname[32];
    int workYears;
    char nameOfHospital[32];
    char jender[32];

    void print()
    {
        std::cout << surname << std::endl;
        std::cout << workYears << std::endl;
        std::cout << nameOfHospital << std::endl;
        std::cout << jender << std::endl;
    }

    void surnameChange()
    {
        char newSurname[32];
        std::cout << "Enter new surname";
        std::cin.getline(newSurname, 32);
        strcpy(surname, newSurname);
    }

    void hospitalChange()
    {
        char newHospital[32];
        std::cout << "Enter new hospital";
        std::cin.getline(newHospital, 32);
        strcpy(nameOfHospital, newHospital);
    }
};

void sortByYears(Doctor doctors[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (doctors[i].workYears > doctors[j].workYears)
            {
                std::swap(doctors[i], doctors[j]);
            }
        }
    }
}
int main()
{
    Doctor doctors[] = {{"Tasev", 10, "St.Georgi", "male"}, {"Doichinov", 11, "St.Anna", "male"}, {"Hristova", 12, "Pirogov", "fimale"}};
    doctors[1].surnameChange();
    doctors[1].hospitalChange();
    sortByYears(doctors, 3);
    for (int i = 0; i < 3; i++)
    {
        doctors[i].print();
    }
}
