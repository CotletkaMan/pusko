#include "Component.h"

#include "Component.h"

class Induct: public Component{
	private:
		double L;
		double I;
	public:
		Induct(int firstNode , int secondNode, double l) : Component(firstNode , secondNode){
			L = l;
			I = 0;
		}

		double* include(){
			double dt = ModelingTime::getStep();
			I += dt/L * (currentState[secondNode] - currentState[firstNode]);
			matrix[0][0] = dt/L; matrix[0][1] = - dt/L; matrix[0][2] = - I;
			matrix[1][0] = - dt/L; matrix[1][1] = dt/L; matrix[1][2] = + I;
			return &matrix[0][0];
		}
};