#include <iostream>
using namespace std;
template<class T>
void f(T* a, int* mark, int n, int i)//n为递归层数
{

	if (n == i)//当设置完数组内的全部元素后输出
	{
		cout << "{";
		for (int k = 0; k < i; k++)
		{
			if (mark[k] == 1)
				cout << a[k];
		}
		cout << "}" << endl;
		return;
	}

	mark[n] = 0;//不选第n个元素
	f(a, mark, n + 1, i);
	mark[n] = 1;//选第n个元素
	f(a, mark, n + 1, i);
}
int main()
{
	while (true) {
		int i;
		cout << "Please input a number(1-26):";
		cin >> i;
		if (i > 0 && i < 27) {
			int* mark = new int[i];//构造一个大小为i的数组
			char a[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
			f(a, mark, 0, i);
		}
		else//输入超过范围时提示
			cout << "WRONG!" << endl;
	}
	
	
	return 0;
}
