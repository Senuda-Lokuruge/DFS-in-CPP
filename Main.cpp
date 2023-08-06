#include "Node.h"
#include <vector>
#include <stack>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::stack;
using std::string;

string traverse(Node* root, Node* end);
string tracePath(Node* root, Node* end);

int main() {
   cout << "Tree:                              \n";
   cout << "                        A          \n";
   cout << "                     /  |  \\      \n";
   cout << "                    B   C   D      \n";
   cout << "                  / |   |   | \\   \n";
   cout << "                 F  E   G   H  I   \n";
   cout << "               /  \\               \n";
   cout << "              J    K               \n";
   cout << "             /\\   /|\\            \n";
   cout << "            L  M N O P             \n";
   cout << "                   |               \n";
   cout << "                   Q               \n";
   cout << endl;

   Node a("A");
   Node b("B");
   Node c("C");
   Node d("D");
   Node e("E");
   Node f("F");
   Node g("G");
   Node h("H");
   Node i("I");
   Node j("J");
   Node k("K");
   Node l("L");
   Node m("M");
   Node n("N");
   Node o("O");
   Node p("P");
   Node q("Q");

   a.addNeighbour(&b);
   a.addNeighbour(&c);
   a.addNeighbour(&d);

   b.addNeighbour(&a);
   b.addNeighbour(&e);
   b.addNeighbour(&f);

   c.addNeighbour(&a);
   c.addNeighbour(&g);

   d.addNeighbour(&i);
   d.addNeighbour(&h);

   e.addNeighbour(&b);

   f.addNeighbour(&b);
   f.addNeighbour(&j);
   f.addNeighbour(&k);

   g.addNeighbour(&c);

   i.addNeighbour(&d);
   i.addNeighbour(&h);

   j.addNeighbour(&f);
   j.addNeighbour(&l);
   j.addNeighbour(&m);

   k.addNeighbour(&n);
   k.addNeighbour(&o);
   k.addNeighbour(&p);

   l.addNeighbour(&j);

   m.addNeighbour(&j);

   n.addNeighbour(&k);
   
   o.addNeighbour(&k);
   o.addNeighbour(&q);

   p.addNeighbour(&p);

   Node* root = &a;
   Node* end = &q;

   try {
      cout << traverse(root, end);
   }
   catch (int e) {
      cout << "Error: " << e;
   }
   cout << "\nPress any key to exit." << std::flush;

   char exit;
   cin >> exit;

   return EXIT_SUCCESS;
}

string traverse(Node* root, Node* end) {
   stack<Node*, vector<Node*>> traversalStack;

   Node* currNode = root;
   traversalStack.push(currNode);
   cout << "Traversal order: ";

   while (traversalStack.size() > 0) {
      currNode = traversalStack.top();
      traversalStack.pop();

      cout << currNode->getName() << " ";
      if (currNode == end) {
        break;
      }
      
      currNode->visited = true;
      vector<Node*> neighbours = currNode->getNeighbours();
      for (Node* node : currNode->getNeighbours()) {
         if (node->visited == false) {
            node->setParent(currNode);
            traversalStack.push(node);
         }
      }
   }
   cout << endl;

   return tracePath(root, end);
}

string tracePath(Node* root, Node* end) {
   vector<string> path;
   string pathStr = "Path from " + root->getName() + " to " + end->getName() + " is: ";

   Node* currNode = end;
   while (currNode != root) {
      path.push_back(currNode->getName());
      currNode = currNode->getParent();
   }
   path.push_back(root->getName());

   for (int i = path.size() - 1; i >= 0; i--) {
      pathStr += path.at(i);
      if (i != 0) {
        pathStr += " -> ";
      }
   }

   return pathStr;
}