//в ходе решения получилось, что для  заданного ряда область сходимости R = (-1;1), если х не принадлежит этому промежутку, то посчитать частичную сумму не получится
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
 
double sumN(double x, int n, double& last)
{
    double sum = 1;
    last = -x * x;
    double r = -x * x;
    for (int i = 1; i < n; i++)
    {
        sum += last * 1 / i;
        last *= -r / i;
    }
return sum;
} 
 
double sumE (double x, double E, int& n)
{
    double sum = 1;
    double last = -x*x;
    double r=-x * x;
    for (n=1; fabs(last)>fabs(E); n++)
    {
        sum+= last/ n;
        last*= -r / n;
    }
    return sum;
}
 
int main()
{
    setlocale(LC_ALL, "Rus");   
    while(1)
    {
        
        int z=0;
        cout<<"Выберите действие: 1 - вычисление, 0 - выход."<<endl;
        cin>>z;
        if (z!=1) 
        {
            break;
        }
 
        double x;
        double func;
        int n;
        double sum;
        double abspgr;
 
        cout<<"Задание №1"<<endl;
        // Проверка на принадлежность значения x области сходимости функции.
    do
    {
        cout <<"Введите значение аргумента из области сходимости функции R = (-1 ; 1) : ";
        cin >> x;

    } 
    while (x < -1 || x > 1);
        cout<<"Введите значение аргумента x:"<<endl;
        cin>>x;
        func = exp(-x*x);
        cout<<"Введите число слагаемых:"<<endl;
        cin>>n;
        double last;
        abspgr=fabs(func - sum);
        cout<<"Значение суммы частичного ряда: "<<sumN(x,n,last)<<endl;
        cout<<"Абсолютная погрешность:"<<abspgr<<endl;
        if (abspgr<fabs(last))
            {
                cout<<"Абсолютная погрешность меньше последнего слагаемого."<<endl;
            }
        else 
            {   
                if (abspgr>fabs(last))
                    {
                        cout<<"Абсолютная погрешность больше последнего слагаемого."<<endl;
                    }
                else
                    {
                    if (abspgr=fabs(last))
                        {
                            cout<<"Абсолютная погрешность равна последнему слагаемому."<<endl;
                        }
                    }
            }
        
 
        cout<<"Задание №2"<<endl;       
        double E;
        cout<<"Введите значение аргумента x:"<<endl;
        cin>>x;
        func= exp(-x*x);
        cout<<"Введите точнось вычислений Е:"<<endl;
        cin>>E;
        while(x<=E)
        {
            cout<<"Значение Е превышает значение аргумента х, введите другое значение х или Е"<<endl;
            cout<<"Введите другую точность вычислений:"<<endl;
            cin>>E;
            cout<<"Введите значение х:";
            cin>>x;
        }
            cout<<"Точное значение функции:"<< func << endl;
            sum = sumE(x,E,n);
            cout<<"Частичная сумма ряда с точностью Е:"<< sum <<endl;
            cout<<"Кол-во слагаемых числового ряда, больших Е:"<<n<<endl;
            cout << "Частичная сумма ряда с точностью, превосходящей Е в 10 раз: " << sumE(x,E/10,n) << endl;
            cout<<"Количество слагаемых, превосходящих точность Е: "<<n<<endl;
    system("cls");    
    }
 system("pause");
}
