#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph g;
    int choice;

    do
    {
        cout << "1 to insert in the graph\n2 to print the array\n3 to use floydWarshall and get median \n4 to clear the graph \n5 to remove an edge \nAny value to Exit:" << endl;
        cin >> choice;

        bool run = true;
        int x, y;
        switch (choice)
        {
        case(1):
            cout << "Choose 1 if the graph has no directions 0 if it has directions" << endl;
            cin >> run;
            while (run == true || run == false)
            {
                cout << "Input two points between " << 0 << " and " << V - 1 << " to assign distance between them -1 to exit" << endl;
                cin >> x;
                if (x == -1)
                 break;
                cin >> y;
                if (y == -1)
                    break;
                g.addEdge(x, y, run);
            }
            break;
        case(2):
            g.PrintArray(g.graph);
            break;
        case(3):
            g.floydWarshall(g.graph);
            break;
       
        case(4):
            g.clearGraph(g.graph);

        case(5):
            while (run == true || run == false)
            {
                cout << "Input two points between " << 0 << " and " << V - 1 << " to delete the edge between them -1 to exit" << endl;
                cin >> x;
                if (x == -1)
                    break;
                cin >> y;
                if (y == -1)
                    break;
                g.removeEdge(x, y, run);
            }
            break;
        default:
            break;
        }
    } 
    while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);

    
}

