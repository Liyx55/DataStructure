#include <iostream>
using namespace std;
template<class T>
void f(T* a, int* mark, int n, int i)//nΪ�ݹ����
{

	if (n == i)//�������������ڵ�ȫ��Ԫ�غ����
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

	mark[n] = 0;//��ѡ��n��Ԫ��
	f(a, mark, n + 1, i);
	mark[n] = 1;//ѡ��n��Ԫ��
	f(a, mark, n + 1, i);
}
int main()
{
	while (true) {
		int i;
		cout << "Please input a number(1-26):";
		cin >> i;
		if (i > 0 && i < 27) {
			int* mark = new int[i];//����һ����СΪi������
			char a[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
			f(a, mark, 0, i);
		}
		else//���볬����Χʱ��ʾ
			cout << "WRONG!" << endl;
	}
	
	
	return 0;
}
