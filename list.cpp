#include <iostream>
#include <list>
#include <iterator>
#include <functional>
#include <numeric>
#include <algorithm>
using namespace std;

void _print(list<double> &lt)
{

    list<double>::iterator it; //创建迭代器
    for (it = lt.begin(); it != lt.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<double> lt; //创建list容器用来存储学生成绩
    cout << "请输入学生成绩，当输入-1时，结束输入：" << endl;
    int ret = 1;
    double score;
    while (ret) //从键盘输入学生成绩
    {
        cin >> score;

        if (score == -1)
            break;
        else if (score < 0 || score > 100)
        {
            cout << "请输入正确的成绩：" << endl;
            continue;
        }
        lt.push_back(score);
    }

    //将学生成绩从小到大排序
    lt.sort();
    cout << "学生成绩由小到大排序：" << endl;
    _print(lt); //输出学生成绩

    //插入某一个学生的成绩
    double cnum;
    cout << "请输入要插入的成绩：" << endl;
    cin >> cnum;
    for (list<double>::iterator it = lt.begin(); it != lt.end(); it++)
    {
        if (*it >= cnum) //保证有序插入
        {
            lt.insert(it, cnum);
            break;
        }
    }
    cout << "插入元素后：" << endl;
    _print(lt);

    //查找成绩
    int count = 0; //记录要查找的成绩有几个
    double num;
    cout << "请输入要查找的成绩：" << endl;
    cin >> num;
    list<double>::iterator itf = find(lt.begin(), lt.end(), num);
    //find()函数返回一个迭代器

    if (itf == lt.end())
        cout << num << "分的成绩不存在！" << endl;
    else
    {
        cout << num << "分的成绩存在！" << endl;
        for (list<double>::iterator it = lt.begin(); it != lt.end(); it++)
        {
            if (*it == num)
                count++;
        }

        cout << "且共有" << count << "个成绩为" << num << "的学生" << endl;
    }

    //将成绩低于某一分数的学生成绩剔除
    double tnum;
    cout << "如果要删除低于某一分数的成绩，请输入删除标准：" << endl;
    cin >> tnum;
    list<double>::iterator it;
    for (it = lt.begin(); it != lt.end(); it++)
    {
        if (*it >= tnum)
        {
            lt.erase(lt.begin(), it); //半开闭区间，it位置上的元素不会被剔除
            cout << "删除低于" << tnum << "的分数后:" << endl;
            _print(lt);
            break;
        }
        if (tnum > *(--lt.end()))
        {
            lt.clear();
            cout << "删除低于" << tnum << "的分数后，容器为空！" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}
