#include <iostream>
#include <list>
#include <iterator>
#include <functional>
#include <numeric>
#include <algorithm>
using namespace std;

void _print(list<double> &lt)
{

    list<double>::iterator it; //����������
    for (it = lt.begin(); it != lt.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<double> lt; //����list���������洢ѧ���ɼ�
    cout << "������ѧ���ɼ���������-1ʱ���������룺" << endl;
    int ret = 1;
    double score;
    while (ret) //�Ӽ�������ѧ���ɼ�
    {
        cin >> score;

        if (score == -1)
            break;
        else if (score < 0 || score > 100)
        {
            cout << "��������ȷ�ĳɼ���" << endl;
            continue;
        }
        lt.push_back(score);
    }

    //��ѧ���ɼ���С��������
    lt.sort();
    cout << "ѧ���ɼ���С��������" << endl;
    _print(lt); //���ѧ���ɼ�

    //����ĳһ��ѧ���ĳɼ�
    double cnum;
    cout << "������Ҫ����ĳɼ���" << endl;
    cin >> cnum;
    for (list<double>::iterator it = lt.begin(); it != lt.end(); it++)
    {
        if (*it >= cnum) //��֤�������
        {
            lt.insert(it, cnum);
            break;
        }
    }
    cout << "����Ԫ�غ�" << endl;
    _print(lt);

    //���ҳɼ�
    int count = 0; //��¼Ҫ���ҵĳɼ��м���
    double num;
    cout << "������Ҫ���ҵĳɼ���" << endl;
    cin >> num;
    list<double>::iterator itf = find(lt.begin(), lt.end(), num);
    //find()��������һ��������

    if (itf == lt.end())
        cout << num << "�ֵĳɼ������ڣ�" << endl;
    else
    {
        cout << num << "�ֵĳɼ����ڣ�" << endl;
        for (list<double>::iterator it = lt.begin(); it != lt.end(); it++)
        {
            if (*it == num)
                count++;
        }

        cout << "�ҹ���" << count << "���ɼ�Ϊ" << num << "��ѧ��" << endl;
    }

    //���ɼ�����ĳһ������ѧ���ɼ��޳�
    double tnum;
    cout << "���Ҫɾ������ĳһ�����ĳɼ���������ɾ����׼��" << endl;
    cin >> tnum;
    list<double>::iterator it;
    for (it = lt.begin(); it != lt.end(); it++)
    {
        if (*it >= tnum)
        {
            lt.erase(lt.begin(), it); //�뿪�����䣬itλ���ϵ�Ԫ�ز��ᱻ�޳�
            cout << "ɾ������" << tnum << "�ķ�����:" << endl;
            _print(lt);
            break;
        }
        if (tnum > *(--lt.end()))
        {
            lt.clear();
            cout << "ɾ������" << tnum << "�ķ���������Ϊ�գ�" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}
