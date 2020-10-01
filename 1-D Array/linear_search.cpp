#include<iostream>
using namespace std;

int main(){
	int n,key;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
    cin>>key;
	int i;
	for( i=0;i<=n-1;i++){
		if(a[i]==key){
			cout<<key<<" found at "<<i<<endl;
			break;
		}
	}
	if(i==n){
		cout<<key<<" is not found"<<endl;
	}
	return 0;
}
