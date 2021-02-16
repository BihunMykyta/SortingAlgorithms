#include<iostream>
#include <ctime>

using namespace std;

class Array
{
private:
    int* arr;
    int N;
public:
    Array() //конструктор без параметров
    {
        N = 1;
        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = 0;
    }
    Array(int n) //конструктор с одним параметром
    {
        N = n;
        arr = new int[N];
        set();
    }

    Array(int n, bool fRand) //конструктор с двумя параметрами
    {
        N = n;
        arr = new int[N];
        setRand();
    }

    ~Array() //деструктор
    {
        delete[] arr; //освобождение памяти
    }

    void printArray() //показать массив
    {
        for (int i = 0; i < N; i++)
            cout << arr[i] << "  ";
        cout << endl;
    }

    void setRand() //ввод случайных элементов массива
    {
        for (int i = 0; i < N; i++)
            arr[i] = rand() % 100;
    }

    void set() //ввод элементов заданных пользователем
    {
        for (int i = 0; i < N; i++)
        {
            cout << "Введите " << i << " элемент массива: ";
            cin >> arr[i];
        }
    }

};

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n;
    char variant;

    cout << "Введите желаемый вариант заполнения массива : \n \t1) Заполнить собственными значениями \n \t2) Заполнить рандомными значениями\n" << "Ваш выбор: ";
    cin >> variant;

    cout << "Введите размер массива: ";
    cin >> n;

    switch (variant)
    {
    case '1': {
        Array array(n);
        cout << "Массив" << endl;
        array.printArray();
        break;
    }
    case '2': {
        Array array(n, true);
        cout << "Массив" << endl;
        array.printArray();
        break;
    }
    default:
    {
        cout << "Необходимо выбрать один из вариантов" << endl;
    }
    }

    system("pause");
    return 0;
}
