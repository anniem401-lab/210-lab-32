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
const int Indent = 6; // for Setw()
const int Initial_Cars = 2, Car_Count = 8, Num_Lanes = 4, Period_Max = 20;
const int P_Car_Pays = 46, P_Car_Joins = 39, P_Rear_Change = 15; // Probabilities

int main(){
    srand(time(0)); // For random number generation

    array<deque<Car>, Num_Lanes> lanes; // Deque Array to hold 4 lanes

    deque<Car> cars; // Deque holds cars
    for(int i = 0; i < Car_Count; i++){
        cars.push_back(Car()); // Cars pushed into cars deque
    }
    
    //cout << "\nCars amount: " << cars.size() << endl; // Checking amount of cars
    for(int i = 0; i < 8; i++){
        cars[i].print(); // Prints cars from cars deque
    }
    
    // Pushes cars unto each lane
    for(int i = 0; i < Num_Lanes; i++){
        lanes[i].push_back(cars[i]);
        lanes[i].push_back(cars[i + 4]);
    }

    // Outputs 2 cars into 4 separate lanes
    cout << "\n\nInitial queue:" << endl;
    for(int i = 0; i < Num_Lanes; i++){
        cout << "Lane: " << i + 1 << endl;
    
        for(int j = 0; j < Initial_Cars; j++){
            cout << setw(Indent); lanes[i][j].print(); // Prints cars from lanes deque
        }
        
    } cout << endl;
    //cout << "\nCars amount: " << cars.size() << endl; // Checking amount of cars

    // Running Time Periods
    int i, period = 1; // Starts time period at 1, will end at 20
    
    while(!lanes[i].empty()){
        cout << "Time: " << period << endl;
        int prob = rand() % 100 + 1;
        if (prob <= P_Car_Pays){// 46% probability that the car at the head of the line pays its toll and leaves the queue
            for (int i = 0; i < Num_Lanes; i++){
                cout << "Lane: " << i + 1 << " Paid: "; lanes[i].front().print(); // Car at head is printed 
                lanes[i].pop_front(); // Removes car at head in the deque
            }
        }

        prob = rand() % 100 + 1;
        if (prob <= P_Car_Joins){// 39% probability that another car joins the queue
            for (int i = 0; i < Num_Lanes; i++){
                lanes[i].push_back(Car()); // Adds a car to back of the deque
                cout << "Lane: " << i + 1 << " Joined: "; lanes[i].back().print(); // Car in back is printed
            }
        }

        cout << endl; // Queue is printed out
        for(int i = 0; i < Num_Lanes; i++){
        cout << "Lane: " << i + 1 << " Queue:" << endl;
    
        for(int j = 0; j < lanes[i].size(); j++){
            cout << setw(Indent); lanes[i][j].print(); // Prints cars from lanes deque
        }
        
        } cout << endl;

        if (lanes[i].empty()){
            cout << setw(14) << "Empty...\n" << endl;
        }
        period++; // increases operation by one
    }

    /*
    while(!cars.empty() && period != 20){
        cout << "Time: " << period << endl;
    }
    */
    return 0;
}

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