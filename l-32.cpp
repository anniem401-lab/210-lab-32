// COMSC-210 | Lab 32 + 33 | Annie Morales
// IDE used: Visual Studio Code

// Milestones:
// [Milestone 1] Branched from Lab 32.
// [Milestone 2] Code has created the array of deques, and tests operations on this complex data structure to validate it.
// [Milestone 3] Code populates the plaza with 2 cars before the simulation runs. Output the current deque status per the sample output.
// [Milestone 4] Code features the loop. Inside the loop, only two probabilities: 50/50 of the car paying/leaving and of the car joining the deque. Code should fully exercise the data structures.

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
const int Indent = 6; // for Setw()
const int Initial_Cars = 2, Car_Count = 8, Num_Lanes = 4, Period_Max = 21;
const int P_Car_Pays = 46, P_Car_Joins = 39, P_Rear_Change = 15; // Probabilities

int main(){
    srand(time(0)); // For random number generation

    array<deque<Car>, Num_Lanes> lanes; // Deque Array to hold 4 lanes

    deque<Car> cars; // Deque holds cars
    for(int i = 0; i < Car_Count; i++){
        cars.push_back(Car()); // Cars pushed into cars deque
    }
    
    cout << "Original Deque of Cars: " << endl;
    for(int i = 0; i < 8; i++){
        cars[i].print(); // Prints cars from cars deque
    } cout << "-----------------------------------------" << endl;
    
    // Pushes cars unto each lane
    for(int i = 0; i < Num_Lanes; i++){
        lanes[i].push_back(cars[i]);
        lanes[i].push_back(cars[i + 4]);
    }

    // Outputs 2 cars into 4 separate lanes
    cout << "\nInitial queue:" << endl;
    for(int i = 0; i < Num_Lanes; i++){
        cout << "Lane: " << i + 1 << endl;
    
        for(int j = 0; j < Initial_Cars; j++){
            cout << setw(Indent); lanes[i][j].print(); // Prints cars from lanes deque
        }
        
    } cout << endl;

    // Running Time Periods
    int period = 1; // Starts time period at 1, will end at 20
    int i = 1;
    cout << "** Start of Time Periods **" << endl;
    
    while(!lanes[i].empty() && period != Period_Max){
        cout << "=========================================\n";
        cout << "Time: " << period << endl;
        cout << "-----------------------------------------" << endl;
        int prob = rand() % 100 + 1;
        if (prob <= 50){// 50% probability that the car at the head of the line pays its toll and leaves the queue
            for (int i = 0; i < Num_Lanes; i++){
                cout << "Lane: " << i + 1 << " Paid: "; lanes[i].front().print(); // Car at head is printed 
                lanes[i].pop_front(); // Removes car at head in the deque
            }
        }

        prob = rand() % 100 + 1;
        if (prob <= 50){// 50% probability that another car joins the queue
            for (int i = 0; i < Num_Lanes; i++){
                lanes[i].push_back(Car()); // Adds a car to back of the deque
                cout << "Lane: " << i + 1 << " Joined: "; lanes[i].back().print(); // Car in back is printed
            }
        }
        cout << "-----------------------------------------" << endl;
        // Queue is printed out
        for(int i = 0; i < Num_Lanes; i++){
        cout << "Lane: " << i + 1 << " Queue:" << endl;
    
        for(int j = 0; j < lanes[i].size(); j++){
            cout << setw(Indent); lanes[i][j].print(); // Prints cars from lanes deque
        }
        
        } cout << endl;

        for(int i = 0; i < 1; i++){
            if (lanes[i].empty()){
                cout << " Empty...\n" << endl;
            }
            else{
                cout << " Lanes are still populated...\n" << endl;
            }
        }
        period++; // increases operation by one
        
    }
    cout << "** End of simulation! **" << endl;
    return 0;
}