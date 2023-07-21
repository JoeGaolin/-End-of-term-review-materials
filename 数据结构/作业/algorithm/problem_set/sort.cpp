#include <stdafx>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct student
{
    string name;//姓名
    int math;//数学成绩
    int english;//英语
};
int c =0;//控制排序规则
bool compare(student a, student b)
{
    if (c == 0)//按照姓名递增排序
    {
        return (a.name<=b.name);
    }
    else if (c == 1)//按照数学成绩递增排序
    {
        return (a.math <= b.math);
    }
    else//按照英语成绩递增排序
    {
        return (a.english <= b.english);
    }
}
int _tmain(int argc, _TCHAR* argv[])
{
    student array[3];
 
    array[0].name = "John";
    array[0].math = 86;
    array[0].english = 91;
 
    array[1].name = "Michelle";
    array[1].math = 85;
    array[1].english =95;
 
    array[2].name = "Kim";
    array[2].math = 89;
    array[2].english = 60;
    cout << "原始顺序：" << endl;
    for (int i = 0; i <3; i++)
        cout << array[i].name << ' ' << array[i].math << ' ' << array[i].english << endl;
    cout << "按姓名递增排序：" << endl;
    c =0;
    sort(array,array+3,compare);
    for (int i = 0; i <3;i++)
        cout << array[i].name << ' ' << array[i].math << ' ' << array[i].english << endl;
    cout << "按数学成绩递增排序：" << endl;
    c =1;
    sort(array, array + 3, compare);
    for (int i = 0; i <3; i++)
        cout << array[i].name << ' ' << array[i].math << ' ' << array[i].english << endl;
    system("pause");
    return 0;
}