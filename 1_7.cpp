#include <bits/stdc++.h>
using namespace std;
int main(){
	int mat[5][5] = {1,2,3,4,0,3,6,0,6,9,9,3,4,1,2,4,7,4,6,3,6,4,3,7,3};
	int rows[5] = {0,0,0,0,0};
	int cols[5] = {0,0,0,0,0};
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<	mat[i][j] << " ";
		}
		cout<< endl;
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(mat[i][j]==0){
				rows[i] = 1;cols[j]=1;
			}
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(rows[i]==1 || cols[j]==1)
				mat[i][j] = 0;
		}
	}

	cout<<endl<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<	mat[i][j] << " ";
		}
		cout<< endl;
	}

	return 0;
}