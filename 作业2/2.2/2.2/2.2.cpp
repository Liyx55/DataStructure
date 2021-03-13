#include<iostream>
#include "circularListWithHeader.h"

using namespace std;


void split(circularListWithHeader<int> c) {
	circularListWithHeader<int> a, b;
	int temp;
	b.insert(0, c.get(0));
	for (int i = 1, j = 0, k = 1; i < c.size(); i++) {
		if (i % 2 != 0) {
			a.insert(j, c.get(i));
			j++;
		}
		else
		{
			b.insert(k, c.get(i));
			k++;
		}
	}
	cout << a << endl;
	cout << b << endl;
}

int main()
{

	circularListWithHeader<int> y;
	y.insert(0, 2);
	y.insert(1, 7);
	y.insert(0, 10);
	y.insert(2, 3);
	y.insert(3, 6);
	y.insert(2, 9);


	cout << y << endl;
	split(y);
	circularListWithHeader<int> x;
	x.insert(0, 1);
	x.insert(1, 10);
	x.insert(2, 3);
	x.insert(3, 4);
	x.insert(4, 5);
	x.insert(5, 6);
	cout << x << endl;
	x.split();
	getchar();
	getchar();
	return 0;
}