#pragma once
#include<thread>
#include<iostream>
using namespace std;
class timer
{

    atomic<bool> stopFlag = false;  //atomic means that this operation will not interfere with other threads
public:

    void printCurrentTime();
    void run();
    void stop();
};

