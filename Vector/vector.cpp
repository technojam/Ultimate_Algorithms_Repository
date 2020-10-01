// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // to decelare vector
	vector<int> g1;
    // to fill vector using push_back() function
	for (int i = 1; i <= 5; i++)
		g1.push_back(i);
    //use of begin() and end() function
	for (auto i = g1.begin(); i != g1.end(); ++i)
		cout << *i << " ";
        cout<<endl;
    //use of cbegin() and cend() function
	for (auto i = g1.cbegin(); i != g1.cend(); ++i)
		cout << *i << " ";
        cout<<endl;
	//use of rbegin() and rend() function
	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
		cout << *ir << " ";
		cout<<endl;
	//use of crbegin() and crend() function
	for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
		cout << *ir << " ";
    cout<<endl;
    //use of capacity() and size() and max_size() function
    cout << "Size : " << g1.size();
    cout << "\nCapacity : " << g1.capacity();
    cout << "\nMax_Size : " << g1.max_size();

    // resizes the vector size to 4
    g1.resize(4);

    // prints the vector size after resize()
    cout << "\nSize : " << g1.size();

    // checks if the vector is empty or not
    if (g1.empty() == false)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";
    // use of at() and []
	cout << "\ng1[2] = " << g1[2];
	cout << "\ng1.at(2) = " << g1.at(2);
    //use of front() and back()
	cout << "\ng1.front() = " << g1.front();
	cout << "\ng1.back() = " << g1.back();


  	return 0;
}
