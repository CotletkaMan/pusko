#ifndef COMPONENT_H_
#define COMPONENT_H_
#include "../ModelingTime.cpp"

class Component{
	protected:
		int firstNode;
		int secondNode;
		double* currentStates;
		double matrix[2][3];
	public:
		Component(int firstNode , int secondNode){
			this -> firstNode = firstNode;
			this -> secondNode = secondNode;
			*currentState = 0;
		}

		void setStates(double* states){
			currentStates = states;
		}

		virtual double* include() = 0;
		int getFirstNode(){
			return firstNode;
		}

		int getSecondNode(){
			return secondNode;
		}

};

#endif