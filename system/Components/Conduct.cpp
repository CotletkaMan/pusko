#include "Component.h"

class Conduct: public Component{
	private:
		double C;
	public:
		Conduct(int firstNode , int secondNode , double c) : Component(firstNode , secondNode){
			C = c;
		}

		double* include(){
			double dt = ModelingTime::getStep();
			matrix[0][0] = C/dt; matrix[0][1] = - C/dt; matrix[0][2] = C/dt * (currentState[secondNode] - currentState[firstNode]);
			matrix[1][0] = - C/dt; matrix[1][1] = C/dt; matrix[1][2] = -C/dt * (currentState[secondNode] - currentState[firstNode]);
			return &matrix[0][0];
		}
};