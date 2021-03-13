
#include<iostream>
#include<numeric>     
#include "extendedchain.h"

using namespace std;
Chain<int> c;
Chain<int>& meld(Chain<int>& a, Chain<int>& b) {

    int i = 0, j = 0, k = 0;
    for (; j < a.size() && k < b.size();) {
        c.insert(i++, a.get(j++));
        c.insert(i++, b.get(k++));
    }//�������a��b��Ԫ��
    if (j == a.size()) {
        while (k < b.size()) {
            c.insert(i++, b.get(k++));
        }
    }//aȡ���ˣ���b��ʣ��Ԫ�ؼӵ�c��
    else
    {
        while (j < a.size()) {
            c.insert(i++, a.get(j++));
        }
    }//bȡ���ˣ���a��ʣ��Ԫ�ؼӵ�c��
    return c;

}

int main()
{

    Chain<int> y;
    y.insert(0, 4);
    y.insert(1, 5);
    y.insert(2, 6);
    y.insert(3, 7);
    y.insert(4, 8);
    y.insert(5, 9);
    Chain<int> x;
    x.insert(0, 1);
    x.insert(1, 2);
    x.insert(2, 3);
    cout << y << endl;
    cout << x << endl;
    cout << meld(x, y);
    getchar();
    getchar();
    return 0;
}
