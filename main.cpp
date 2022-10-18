/*David Archer
Numbers of Vehicles*/

#include <cctype>
#include <string>
#include <iostream>
#include <random>


using namespace std;

constexpr auto MAX = 100;
constexpr auto MIN = 50;
constexpr auto PASS = 1;
constexpr auto CASH = 3;

class TollBooth
{
public:
    int NumberOfVehicles;
    int CurrentWaitTime;
    int TotalWaitTime;
    typedef float AverageWaitTime;
};

int toll_kind()
{
    return (std::rand() % 2 == 0) ? PASS : CASH; 
}

void toll_sim(const int NumberOfBooths)
{
    TollBooth booth [NumberOfBooths];

    int TotalNumberOfVehicles = MIN + (std::rand() % (MAX - MIN + 1));
    std::cout << "Total number of cars (randomly generated between 50 and 100) = " << TotalNumberOfVehicles << std::endl;

    for (int i = 0; i < NumberOfBooths; ++i)
    {
        booth[i].NumberOfVehicles = TotalNumberOfVehicles / NumberOfBooths;
        booth[i].TotalWaitTime = 0;
    }

    int remainder = TotalNumberOfVehicles % NumberOfBooths;

    for (int i = 0; i < remainder; ++i)
    {
        booth[i].NumberOfVehicles += 1;
    }

    for (int i = 0; i < NumberOfBooths; ++i)
    {
        for (int j = 0; j < booth[i].NumberOfVehicles; ++j)
        {
            booth[i].CurrentWaitTime = toll_kind();
            booth[i].totalWaitTime += booth[i].CurrentWaitTime;
        }
        booth[i].AverageWaitTime = booth[i].TotalWaitTime / (float)booth[i].NumberOfVehicles;
        std::cout << std::endl << "Booth #" << i + 1 << std::endl;
        std::cout << "---------" << std::endl;
        std::cout << "Maximum wait time (in time units) = " << booth[i].total_wait_time << std::endl;
        std::cout << "Number of cars in the booth = " << booth[i].number_of_vehicles << std::endl;
        std::cout << "Average wait time (in time units) = " << booth[i].average_wait_time << std::endl;
    }
    return;
}

int main(void)
{
    for (int i = 2; i < 6; ++i)
    {
        std::cout << std::endl << std::endl;
        std::cout << "Number of booths = " << i << std::endl;
        std::cout << "=============================" << std::endl << std::endl;
        toll_sim(i);
    }
}
