#include <iostream>
#include <climits>
#include <cmath>
#include <valarray>



using namespace std;


int main()
{

	valarray<int> v {
		0,1,2,3,
		10,11,12,13,
		20,21,22,23
	};


	valarray<int> v1 =  v[slice(0,3,4)];

	for(auto& i : v1 )
		cout << i << ' ';
 //add comment
	return 0;
}
