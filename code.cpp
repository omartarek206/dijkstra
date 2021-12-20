#include <iostream>
using namespace std;
#define INF 999

int v;
int dist[100];
int source;
int cost[100][100] ;
bool visited[100] = { 0 };

void input();
void run();
int getnearest();
void dijkstr();
void display();
void init();

int main() {
	input();
	run();
}

void init() {
	for (int i = 0; i < v; i++)
		dist[i] = INF;
	dist[source] = 0;
}

int getnearest() {
	int min_dis = INF;
	int minnode = 0;
	for (int i = 0; i < v; i++)
		if (!visited[i] && dist[i]<min_dis){
			min_dis = dist[i];
			minnode = i;
		}
	return minnode;
}

void dijkstr() {
	for (int i = 0; i < v; i++) {
		int nearest = getnearest();
		visited[nearest] = true;
		for (int adj = 0; adj < v; adj++)
			if (cost[nearest][adj]!=INF && dist[adj]>dist[nearest]+cost[nearest][adj])
				dist[adj]= dist[nearest] + cost[nearest][adj];
	}
}

void display() {
	cout << "Node\t\tCost "<<endl;
	for (int i = 0; i < v; i++)
	{
		cout << i + 1 << "\t\t" << dist[i] << "\t\t" << " ";
		cout << endl;
	}
}

void input(){
	cout << "enter no of vertecies: ";
	cin >> v;

	cout << "enter cost matrix: ";
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			cin >> cost[i][j];
		}
	}
	 
	cout << "enter source vertix: ";
	cin >> source;
	source--;
	while(source < 0 || source >= v) {
		cout << "enter valid source vertix: ";
		cin >> source;
		source--;
	}
}

void run(){
	init();
	dijkstr();
	display();
}
