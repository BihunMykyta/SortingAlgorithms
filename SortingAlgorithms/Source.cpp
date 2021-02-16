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
    Array() //����������� ��� ����������
    {
        N = 1;
        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = 0;
    }
    Array(int n) //����������� � ����� ����������
    {
        N = n;
        arr = new int[N];
        set();
    }

    Array(int n, bool fRand) //����������� � ����� �����������
    {
        N = n;
        arr = new int[N];
        setRand();
    }

    ~Array() //����������
    {
        delete[] arr; //������������ ������
    }

    void printArray() //�������� ������
    {
        for (int i = 0; i < N; i++)
            cout << arr[i] << "  ";
        cout << endl;
    }

    void setRand() //���� ��������� ��������� �������
    {
        for (int i = 0; i < N; i++)
            arr[i] = rand() % 100;
    }

    void set() //���� ��������� �������� �������������
    {
        for (int i = 0; i < N; i++)
        {
            cout << "������� " << i << " ������� �������: ";
            cin >> arr[i];
        }
    }

};

void getCorrectInput(int& value) {
    cin >> value;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������������ ����. ����������, ���������� ��� ���: ";
        cin >> value;
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, variant;

    do {
        cout << "������� �������� ������� ���������� ������� : \n \t1) ��������� ������������ ���������� \n \t2) ��������� ���������� ����������\n" << "��� �����: ";
        getCorrectInput(variant);
    } while (variant < 0 || variant > 2);
    
    do {
        cout << "������� ������ �������: ";
        getCorrectInput(n);
    } while (n < 0);

    switch (variant)
    {
        case 1: {
            Array array(n);
            cout << "������: " << endl;
            array.printArray();
            break;
        }
        case 2: {
            Array array(n, true);
            cout << "������: " << endl;
            array.printArray();
            break;
        }
        default:
        {
            cout << "���������� ������� ���� �� ���������" << endl;
        }
    }

    system("pause");
    return 0;
}
