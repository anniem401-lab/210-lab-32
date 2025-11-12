// COMSC-210 | Lab 32 | Annie Morales
// IDE used: Visual Studio Code

// Headers
#include "Car.h" // To use Car.h file
#include <deque> // Requirement 1 & for use of std::deque
#include <ctime>
#include <cstdlib>
using namespace std;

// Constant
const int In_sz = 2; // Initial size of deque

int main(){
    srand(time(0)); // For random number generation

    deque<Car> cars;
    for(int i = 0; i < In_sz; i++){
    cars.push_back(Car());
    }
    cout << "\nInitial queue:" << endl;
    for(int i = 0; i < cars.size(); i++){
        cars[i].print(); // Uses print function from Car class
    } cout << endl;


    // Running cycles
    while(cars.size() > 1){
        for (int i = 1; i < cars.size(); i++){
            cout << "Time: " << i << " Operation: ";
            
            int prob = rand() % 100 + 1;
         if (prob <= 55) {// 55% probability that the car at the head of the line pays its toll and leaves the toll booth
                cars.pop_front(); // Removes car at head in the deque
                cout << "Car paid: ";
                cout << "\nQueue: " << endl;
                cars[i].print();
            }
        
            prob = rand() % 100 + 1;
            if(prob <= 45) {// 45% probability that another car joins the line for the toll booth
                cars.push_back(Car()); // Adds a car to back of the deque
                cout << "Joined lane: ";
                cout << "\nQueue: " << endl;
                cars[i].print();
            }
        }
    }

    return 0;
}