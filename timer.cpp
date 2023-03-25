#include "timer.h"
#include<iostream>
using namespace std;

void timer::printCurrentTime() {
    time_t current_time = time(nullptr);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &current_time);
    cout << "Current time: " << buffer;
    return;
}

void timer::run() {
    while (!stopFlag) { // loop until stopFlag is true
        printCurrentTime();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void timer::stop() {
    this->stopFlag = true; // set the flag to true to stop the loop
}