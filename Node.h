#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using std::vector;
using std::string;
using std::ostringstream;
using std::endl;

class Node {
    public:
        Node(string nodeName);
        Node();

        bool visited = false;
        string getName(){return this->name;};

        void addNeighbour(Node* neighbour);
        vector<Node*> getNeighbours(){return this->neighbours;};
        ostringstream neighboursSS();
        bool hasNeighbours();

        void setParent(Node* parent){this->parent = parent;};
        Node* getParent(){return this->parent;};

    private:
        string name;
        vector<Node*> neighbours;
        Node* parent = nullptr;
};