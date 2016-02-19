#include "Time.h"

class UniformTime{
    private:
        double step;
    public:
        UniformTime(double step){
            this -> step = step;
        }
    protected:
        double changeTime(){
            return step;
        }
};
