#include <bits/stdc++.h>
using namespace std;
int main(){
	string s = "test case for the question in Career cup";
	int i=0;
	while(i<s.length()){
		if(s[i]==' '){
			s[i] = '0';
			s.insert(s.begin()+i,'2');
			s.insert(s.begin()+i,'%');
		}
		i++;
	}
	cout << s << endl;
	return 0;
}