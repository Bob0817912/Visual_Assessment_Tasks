/**
 * 1. 多次编译运行，观察输出结果。
 * 2. 修改下面的代码，使得 a 的值等于 threadNum * 10000。只能修改 foo 函数，不能修改 main 函数，可以增加变量。
*/

#include <iostream>
#include <thread>
#include <vector>

const int threadNum = 10; // 线程数

void foo(int &a) {
    for (int i = 0; i < 10000; i++) // 每个线程对 a 加 10000 次
        a++;
    return;
}

int main(int argc, char* argv[], char** env)
{
    int a = 0;  // 总计数器
    std::vector<std::thread> threadVec;

    for (int i = 0; i < threadNum; i++) // 创建 threadNum 个线程
        threadVec.push_back(std::thread(foo, std::ref(a)));
    for (int i = 0; i < threadNum; i++)
        threadVec[i].join(); // 等待所有线程结束

      std::cout << "a = " << a << std::endl; // 输出 a 的值

      return 0;
}