#include <bits/stdc++.h>
using namespace std;
int main(){
	int ans=0;
	string s1, s2;
	cin >> s1 >> s2;
	if(s1.length() != s2.length())		cout << "No" << endl;
	else{
		s1 = s1 + s1;
		if(s1.find(s2)!=string::npos)	cout << "Yes" << endl;
		else	cout << "No" << endl;
	}
	return 0;
}