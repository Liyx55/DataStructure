#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
long long F[95] = { 0 };//��ȫ����ֵΪ0
long long __Fibonacci(int n)
{

    if (n < 2) {
        return F[n] = 1;//�޸�ǰ����Ϊ1
    }
    else {
        if (F[n] != 0)//�Ѿ�����
            return F[n];
        else {//��δ��������ڼ���
            return F[n] = __Fibonacci(n - 1) + __Fibonacci(n - 2);
        }
    }
}

void Fibonacci()
{
    char c[20];
    int count = 0;//����¼ʵ�ʳ���
    cout << "Please input a number(0-90):";
    cin >> c;//������ֵ
    int n = -1;
    for (int i = 0; i < sizeof(c); i++) {//sizeof��c��=20
        if (c[i] == '\0') {
            break;
        }
        count++;
    }
    int j = count - 1;
    for (int i = 0; i < count; i++) {
        if (c[i] < '0' || c[i] > '9') {//�ж��Ƿ�����Ϊ����
            cout << "WRONG!" << endl;
            break;
        }
        else {
            //n = n + 1;
            n = n + (c[i] - 48) * pow(10.00, j);//ת��Ϊ��Ӧ������
            j--;
        }
    }
    if (n < 0 || n > 90)//�Ƿ񳬹���Χ
        cout << "WRONG!" << endl;
    else if (n >= 0 && n <= 90) {
        __Fibonacci(n);//δ��������ú�������
        cout << F[n] << endl;
    }
}
int main()
{
    while (true) {
        Fibonacci();
    }
    getchar();
    getchar();//��ȡ�ַ�
    return 0;
}