#include <iostream>
#include <ctime>
#include <typeinfo>

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

void getCorrectInput(int& value) {
    cin >> value;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неправильный ввод. Пожалуйста, попробуйте еще раз: ";
        cin >> value;
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, variant;

    do {
        cout << "Введите желаемый вариант заполнения массива : \n \t1) Заполнить собственными значениями \n \t2) Заполнить рандомными значениями\n" << "Ваш выбор: ";
        getCorrectInput(variant);
    } while (variant < 0 || variant > 2);
    
    do {
        cout << "Введите размер массива: ";
        getCorrectInput(n);
    } while (n < 0);

    switch (variant)
    {
        case 1: {
            Array array(n);
            cout << "Массив: " << endl;
            array.printArray();
            break;
        }
        case 2: {
            Array array(n, true);
            cout << "Массив: " << endl;
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
