#include <iostream>
#include <fstream>

struct Node
{
	int a1, a2, w;
};
struct Graf
{
	int a1, a2;
};

void Enter_Node_from_file(Node* p);
void Enter_Node(Node*);
void Krass(Node*, Graf*);
void Print_Graf(Graf*); 
void Sort_Nodes(Node*);

using namespace std;
int V, R;
int main()
{
	cout << "Enter number of Vertices: ";  cin >> V;
	cout << "Enter number of Edges: "; cin >> R;
	Graf* g = new Graf [V - 1];
	Node* p = new Node [R];
	Enter_Node_from_file(p); 
	Sort_Nodes(p);
	Krass(p, g);
	Print_Graf(g);
	delete[] g;
	delete[] p;
}


void Enter_Node_from_file(Node* p)
{
	ifstream fp;
	fp.open("graf.txt");
	if (fp.is_open())
	{	
		for ( int i = 0 ; i < R ; i++)
		{
			fp >> p[i].a1 >> p[i].a2 >> p[i].w;
		}
	}
	fp.close();
}

void Enter_Node(Node* p)
{
	for (int i = 0; i < R; i++)
	{
		cin >> p[i].a1 >> p[i].a2 >> p[i].w;
	}
}

void Krass(Node* p, Graf* g)
{
	int* arr_for_v = new int [V];
	for (int i = 0; i < V; i++)
	{
		arr_for_v[i] = i;
	}
	int counter = 0;
	for (int i = 0; i < R ; i++)
	{
		int a1 = p[i].a1, a2 = p[i].a2;
		if (arr_for_v[a1-1] != arr_for_v[a2-1])
		{
			g[counter].a1 = a1; g[counter].a2 = a2;
			counter++;
			int new_ver = arr_for_v[a1-1], old_ver = arr_for_v[a2-1];
			for (int j = 0; j < V ; j++)
			{
				if (arr_for_v[j] == old_ver)
				{
					arr_for_v[j] = new_ver;
				}
			}
		}

	}
	delete[] arr_for_v;
}

void Print_Graf(Graf* g)
{
	for (int i = 0; i < V - 1; i++)
	{
		cout << g[i].a1 << " " << g[i].a2 << endl;
	}
}
void Sort_Nodes(Node* p)
{
	Node T = { 0 ,0 ,0 };
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < R - i; j++)
		{
			if (p[j].w > p[j + 1].w)
			{
				T = p[j];
				p[j] = p[j + 1];
				p[j + 1] = T;
			}
		}
	}
}
