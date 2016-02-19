#include "Time.h"

Time::Time(){
    time = 0;
    timeStep = changeTime();
}

double Time::getCurrentTime(){
    return time;
}

double Time::getCurrentStep(){
    return timeStep;
}

void Time::nextStep(){
    time += timeStep;
    timeStep = changeTime();
}
