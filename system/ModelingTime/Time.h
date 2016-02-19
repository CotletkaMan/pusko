#ifndef MODELINGTIME_H
#define MODELINGTIME_H


class Time {
    protected:
        double time;
        double timeStep;
    public:
        Time();
        double getCurrentTime();
        double getCurrentStep();
        void nextStep();
    protected:
        virtual double changeTime() = 0;
};

#endif // MODELINGTIME_H
