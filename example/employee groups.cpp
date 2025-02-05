#include <iostream>
#include<map>
#include <string>
#include <vector>
using namespace std;

class worker
{
public:
    string m_name;
    int m_salary;
};

void creatWorker(vector<worker> &v)
{
    string Nameseed = "ABCDEFG";
    for(int i = 0;i<10; i++)
    {
        worker worker;
        worker.m_name = "员工";
        worker.m_name+=Nameseed[i];
        worker.m_salary = rand()%10000+10000;//10000-19999
        v.push_back(worker);
    }
}
void showGroup(const multimap<int, worker>& groups) {
    for (int depnum = 0; depnum < 3; ++depnum) {
        cout << (depnum == 0 ? "策划部门：" : (depnum == 1 ? "美术部门：" : "研发部门：")) << endl;

        auto pos = groups.lower_bound(depnum);  // 获取该部门的第一个员工
        auto end = groups.upper_bound(depnum);  // 获取该部门的最后一个员工之后的位置
        for (; pos != end; ++pos) {
            cout << "姓名：" << pos->second.m_name << " 工资是：" << pos->second.m_salary << endl;
        }
    }
}
void setGroup(vector<worker> &v,multimap<int,worker> &m)
{
    for(vector<worker>::iterator it = v.begin();it!=v.end();it++)
    {
        //产生随机部门编号
        int depnum = rand()%3;//0 1 2
        //插入员工
        m.insert(make_pair(depnum,*it));
    }
}

int main(){
    //创建员工
    vector<worker> vWorker;
    creatWorker(vWorker);
    //员工分组
    multimap<int,worker> mWorker;
    setGroup(vWorker,mWorker);
    //分组显示员工
    showGroup(mWorker);
    system("pause");
    return 0;
}