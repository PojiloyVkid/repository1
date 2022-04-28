#include <iostream>
#include <vector>

using namespace std;

//при нехватке памяти для размещения новых элементов емкость вектора выделяется по степеням двойки

void memory1() {
    vector<int> a;
    for (int i = 0; i < 100; i++) {
        a.push_back(i);
        cout << a.capacity() << endl;
    }

}

//емкость вектора увеличивается в 2 раза ,если задать её начальное значение вручную с помощью reserve
void memory2() {
    vector<int> a;
    a.reserve(25);
    for (int i = 0; i < 100; i++) {
        a.push_back(i);
        cout << a.capacity() << endl;
    }
}

//в случае,когда вектор запросил большой объем памяти 
//и на выполнение след.запроса у ОС может не хватать ресурсов
//сложно проанализировать
void memory3() {
    vector<int> a;
    for (int i = 0; i < 999999; i++) {
        a.push_back(i);
        cout << a.capacity() << endl;
    }

}
int main() {
    memory1();
}

//auto begin chrono::