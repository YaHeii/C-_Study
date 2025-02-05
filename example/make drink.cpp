#include <iostream>
#include <string>
#include <memory>
using namespace std;

class make_drink {
public:
    virtual ~make_drink() {}
    virtual void brew() = 0;
    virtual void add_excipients() = 0;

    void boiling_water() {
        cout << "煮水" << endl;
    }

    void pour() {
        cout << "冲泡" << endl;
    }

    void makeDrink() {
        boiling_water();
        brew();
        pour();
        add_excipients();
    }
};

class coffee : public make_drink {
    void brew() override {
        cout << "冲咖啡" << endl;
    }
    void add_excipients() override {
        cout << "加入糖和牛奶" << endl;
    }
};

class tea : public make_drink {
    void brew() override {
        cout << "导入茶叶" << endl;
    }
    void add_excipients() override {
        cout << "加入柠檬" << endl;
    }
};

int main() {
    int choice;
    cout << "请选择饮品: 1. 咖啡 2. 茶" << endl;
    cin >> choice;

    std::unique_ptr<make_drink> drink;
    if (choice == 1) {
        drink = std::make_unique<coffee>();
    } else if (choice == 2) {
        drink = std::make_unique<tea>();
    } else {
        cout << "无效选择" << endl;
        return 1;
    }

    drink->makeDrink();
    system("pause");
    return 0;
}
