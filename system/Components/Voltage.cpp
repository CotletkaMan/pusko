#include "Component.h"

class Voltage : public Component{
	private:
		double (*Func)(double);
		double inResist;
	public:
		Voltage(int firstNode , int secondNode, double (*func)(double)) : Component(firstNode , secondNode){
			Func = func;
			inResist = 0.001;
		}

		double* include(){
			matrix[0][0] = -1./inResist; matrix[0][1] = 1./inResist; matrix[0][2] = -Func(ModelingTime::getTime() + ModelingTime::getStep()) / inResist;
			matrix[1][0] = 1./inResist; matrix[1][1] = -1./inResist; matrix[1][2] = Func(ModelingTime::getTime() + ModelingTime::getStep()) / inResist;
			return &matrix[0][0];
	}
};