#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
long long F[95] = { 0 };//先全部赋值为0
long long __Fibonacci(int n)
{

    if (n < 2) {
        return F[n] = 1;//修改前两项为1
    }
    else {
        if (F[n] != 0)//已经计算
            return F[n];
        else {//还未计算的现在计算
            return F[n] = __Fibonacci(n - 1) + __Fibonacci(n - 2);
        }
    }
}

void Fibonacci()
{
    char c[20];
    int count = 0;//来记录实际长度
    cout << "Please input a number(0-90):";
    cin >> c;//输入数值
    int n = -1;
    for (int i = 0; i < sizeof(c); i++) {//sizeof（c）=20
        if (c[i] == '\0') {
            break;
        }
        count++;
    }
    int j = count - 1;
    for (int i = 0; i < count; i++) {
        if (c[i] < '0' || c[i] > '9') {//判断是否输入为数字
            cout << "WRONG!" << endl;
            break;
        }
        else {
            //n = n + 1;
            n = n + (c[i] - 48) * pow(10.00, j);//转换为对应的数字
            j--;
        }
    }
    if (n < 0 || n > 90)//是否超过范围
        cout << "WRONG!" << endl;
    else if (n >= 0 && n <= 90) {
        __Fibonacci(n);//未超出则调用函数计算
        cout << F[n] << endl;
    }
}
int main()
{
    while (true) {
        Fibonacci();
    }
    getchar();
    getchar();//读取字符
    return 0;
}