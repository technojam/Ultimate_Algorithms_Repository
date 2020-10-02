#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*Fuction to get gcd of a and b*/
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;

	else
		return gcd(b, a % b);
}

/*Function to left rotate arr[] of siz n by d*/
void leftRotate(ll arr[], ll d, ll n)
{
	/* To handle if d >= n */
	d = d % n;
	ll g_c_d = gcd(d, n);
	for (ll i = 0; i < g_c_d; i++) {
		/* move i-th values of blocks */
		ll temp = arr[i];
		ll j = i;

		while (1) {
			ll k = j + d;
			if (k >= n)
				k = k - n;

			if (k == i)
				break;

			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}

// Function to print an array
void printArray(ll arr[], ll size)
{
	for (ll i = 0; i < size; i++)
		cout << arr[i] << " ";
}

/* Driver program to test above functions */
int main()
{
	ll n; //size of array
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;

    cout<<endl<<"Enter the elements to be put in the array"<<endl;
    ll arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<endl<<"Enter 'd' i.e. by how many elements you want to rotate the array"<<endl;
    ll d;
    cin>>d;
	// Function calling
	cout<<endl<<"The left rotated array is"<<endl;
	leftRotate(arr, d, n);
	printArray(arr, n);

	return 0;
}
