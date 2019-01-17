#include <iostream>
using namespace std;

bool is_prime(int i){
	for(int j=2; j*j<i;i++){
		if(i%j==0){return true;}
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	for (int i = 1; i < n; i++)
	{
		if(is_prime(i)){
			cout<<i<<endl;
		}
	}

	return 0;
}
