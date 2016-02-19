#include "Node.cpp"
#include <vector>

class Plate{
	private:
		int X;
		int Y;
		int countNodes;
		double* voltage;
		Node** nodes;
		std::vector<Component*> components;

	public:
		Plate(int x , int y , double* voltage){
			this -> X = x + 1;
			this -> Y = y + 1;
			this -> voltage = voltage;
			countNodes = (X * Y) + 1;
			nodes = new Node*[countNodes];
			for(int i = 0 ; i < countNodes ; i++)
				nodes[i] = new Node(i);
		}

		~Plate(){
			for(int i = 0 ; i < countNodes ; i++)
				delete nodes[i];
			delete nodes;
			for(int i = 0 ; i < components.size() ; i++)
				delete components[i];
		}

		bool validateNode(int Node){
			return (Node % X) >=0 && (Node % X) < X && (Node / X) >= 0 && (Node / X) < Y;
		}

		void addComponent(int out , int in , Component* component){
			if(validateNode(out) && validateNode(in)){
				component.setStates(voltage);
				nodes[out].addComponent(component);
				nodes[in].addComponent(component);
				components.push_back(component);
			}
		}

		Node** getNodes(){
			return nodes;
		}
};
