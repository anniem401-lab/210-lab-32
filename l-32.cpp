// COMSC-210 | Lab 32 + 33 | Annie Morales
// IDE used: Visual Studio Code

// Milestones:
// [Milestone 1] Branched from Lab 32.

// Headers
#include "Car.h" // To use Car.h file
#include <deque> // Requirement 1 & for use of std::deque
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <array>
using namespace std;

// Constants
const int In_sz = 2, Num_Lanes = 4;
const int P_Car_Pays = 46, P_Car_Joins = 39, P_Rear_Change = 15; // Probabilities

int main(){
    srand(time(0)); // For random number generation

    array<deque<Car>, Num_Lanes> lanes; // Array to hold lanes (4)

    deque<Car> cars; // Deque holds cars
    for(int i = 0; i < In_sz; i++){
        cars.push_back(Car()); // Two cars pushed in
    }
    cout << "\nInitial queue:" << endl;
    for(int i = 0; i < cars.size(); i++){
        cout << "Lane: " << i + 1 << endl;
        cars[i].print(); // Uses print function from Car class
    } cout << endl;

    /*
    // Running cycles
    int cycle = 1; // Starts operation at one
    while(!cars.empty()){
        cout << "Time: " << cycle << " Operation: ";
            
        int prob = rand() % 100 + 1;
        if (prob <= 55) {// 55% probability that the car at the head of the line pays its toll and leaves the toll booth 
            cout << "Car paid: "; cars.front().print(); // Car at head is printed
            cars.pop_front(); // Removes car at head in the deque
            }
            
        else{// 45% probability that another car joins the line for the toll booth
            cars.push_back(Car()); // Adds a car to back of the deque
            cout << "Joined lane: "; cars.back().print(); // Car in back is printed
        }

        cout << "Queue: " << endl; // Queue is printed out
        for(int j = 0; j < cars.size(); j++){
             cout << setw(6); cars[j].print();
        }
        cout << "\n";

        if (cars.empty()){
            cout << setw(14) << "Empty...\n" << endl;
        }
        cycle++; // increases operation by one
    }
    */
    return 0;
}