#include "Components/Component.h"
#include <vector>

using namespace std;

class Node{
	private:
		int numNode;
		vector<Component*> components;
	public:
		Node(int numNode){
			this -> numNode = numNode;
		}

		void addComponent(Component* component){
			components.push_back(component);
		}

		void createStiffMatrix(double **matrix , int length , int y){
			double* array = matrix[0];
			vector<Component*>::iterator iterator = components.begin();
			while(iterator != components.end()){
				Component* component = *iterator;
				double* matrix = component -> include();
				if(component -> getFirstNode() == numNode){
					array[component -> getFirstNode()] += matrix[0];
					array[component -> getSecondNode()] += *(&matrix[0] + 1);
					array[length - 1] += *(&matrix[0] + 2);
				}
				else{
					array[component -> getFirstNode()] += matrix[1];
					array[component -> getSecondNode()] += *(&matrix[1] + 1);
					array[length - 1] += *(&matrix[1] + 2);
				}
			}
		}
};