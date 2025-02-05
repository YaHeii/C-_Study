#include<iostream>
#include<string>
using namespace std;
class triangle
{
public:
    //传参
    void set_parameter(int M_H, int M_L,int M_W){
        L = M_L;
        W = M_W;
        H = M_H;
    }
    //求解面积
    int Square(){
        int S = 2*(H*L+H*W+W*L);
        return S;
    }
    //求解体积
    int Volume(){
        int V = H*L*W;
        return V;
    }
private:
    int H = 1;
    int L = 1;
    int W = 1;
};
int main(){
    triangle t1;
    int M_H;int M_L;int M_W;
    cout << "请依次输入高、长、宽：" << endl;
    cin >> M_H;
    cin >> M_L;
    cin >> M_W;
    t1.set_parameter(M_H,M_L,M_W);
    cout << "面积为："<<t1.Square() << endl;
    cout << "体积为："<<t1.Volume() << endl;

}