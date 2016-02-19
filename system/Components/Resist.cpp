#include "Component.h"

class Resist: public Component{
	private:
		double R;
	public:
		Resist(int firstNode , int secondNode , double r) : Component(firstNode , secondNode){
			R = r;
		}

		double* include(){
			matrix[0][0] = 1./R; matrix[0][1] = - 1./R; matrix[0][2] = 0;
			matrix[1][0] = - 1./R; matrix[1][1] = 1./R; matrix[1][2] = 0;
			return &matrix[0][0];
		}
};