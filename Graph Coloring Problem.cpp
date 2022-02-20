#include <iostream>
using namespace std;

int G_size;

void printSolution(int color[]);


bool isSafe(int v, bool graph[100][100], int color[], int c)
{
	for (int i = 0; i < G_size; i++)
		if (graph[v][i] && c == color[i])
			return false;
	return true;
}

bool graphColoringUtil(bool graph[100][100], int N_color, int color[], int v)
{
	if (v == G_size)
		return true;

 	for (int c = 1; c <= N_color; c++)
	{
		if (isSafe(v, graph, color, c))
		{
			color[v] = c;

			if (graphColoringUtil(graph, N_color, color, v + 1) == true)
				return true;

			color[v] = 0;
		}
	}

	return false;
}


bool graphColoring(bool graph[100][100], int N_color)
{
	int color[G_size];
	for (int i = 0; i < G_size; i++)
		color[i] = 0;

	if (graphColoringUtil(graph, N_color, color, 0) == false)
	{
		cout<<"The graph can't be colored with these number of colors";
		return false;
	}

	printSolution(color);
	return true;
}

void printSolution(int color[])
{
	cout<<endl<<"The graph can be colored with these number of colors"<<endl;
	cout<<"The sequence of colors are: ";
	for (int i = 0; i < G_size; i++)
		cout<<color[i]<<",";
	cout<<endl;
}


int main()
{
    int N_color;

    cout<<"Enter the Graph Size: ";
    cin>>G_size;
    cout<<"Enter the Number of Color: ";
    cin>>N_color;

    bool graph[100][100];

    cout<<endl<<"Enter the Value of the Graph: "<<endl;
    for(int i=0;i<G_size;i++)
    {
        for(int j=0;j<G_size;j++)
        {
            cin>>graph[i][j];
        }
    }

	graphColoring(graph, N_color);
	return 0;
}

