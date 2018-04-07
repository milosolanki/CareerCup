#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<vector<int> > mt;
	vector<int> u;
	u.push_back(0);
	u.push_back(1);
	u.push_back(2);
	u.push_back(3);
	u.push_back(4);
	u.push_back(5);
	u.push_back(6);
	int n = 7;
	for(int i=0;i<n;i++)
		mt.push_back(u);
	for(int i=0;i<n/2;i++){
		for(int j=i;j<n-i-1;j++){
			int x=i,y=j,t;
			int temp = mt[n-y-1][x],prev;
			mt[n-y-1][x] = mt[x][y];
			t = x;
			x = n-y-1;
			y=t;
			prev = temp;
			temp = mt[n-y-1][x];
			mt[n-y-1][x] = prev;
			t = x;
			x = n-y-1;
			y=t;
			prev = temp;
			temp = mt[n-y-1][x];
			mt[n-y-1][x] = prev;
			t = x;
			x = n-y-1;
			y=t;
			mt[n-y-1][x] = temp;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)	cout << mt[i][j] << " ";
		cout << endl;
	}
}