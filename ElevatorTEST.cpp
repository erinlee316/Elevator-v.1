// COMSC-200
// Assignment 8, Elevators v.1
// Programmer: Erin Lee
// Student id: 1805820
// c++ main.cpp Building.cpp Rider.cpp Panel.cpp Floor.cpp Elevator.cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <cstdlib>
#include <ctime>

#include "Rider.h"
#include "Building.h"
#include "Floor.h"
#include "Panel.h"

int main()
{
  cout << "Programmer: Erin Lee\n"
  << "Programmer's ID: 1805820\n"
  << "File: " << __FILE__ << "\n\n";

  srand(time(0)); rand();
  // Seed middle elevator with riders on their way to the bottom floor

  for (int i = 0; i < 3; i++)
    Building::elevators[1].board(Rider(4, 0));

  for (int i = 0;; i++) // an infinite counting loop
  {
    cout << "-----------------------------------------------\n";
    cout << "-- Time " << i << " ---------------------------\n";
    for (int elevator = 0; elevator < Building::ELEVATORS; elevator++)
      cout << Building::elevators[elevator] << endl;
  
    for (int floor = 0; floor < Building::FLOORS; floor++)
      cout << Building::floors[floor] << endl;

    Building::action(5.0); // add an average of 5 riders per second

    // type conversion operator test
    cout << "Press ENTER to continue... ";
    cin.get();
  }
}
