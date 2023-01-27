#include <iostream>
#include <iomanip>
using namespace std;

struct date {
    int day;
   int month;
   char* t = new char[10];   
};
struct person {
    char name[25];
    char surname[25];
    char lastname[25];
    date d;
};
/*
void Show(date d) {
    cout << d.day << " " << d.month << " " << d.year << endl;
}

date Put() {
    date temp;
    cin >> temp.day >> temp.month >> temp.year;
    return temp;
}
bool IsLeapYear(int year) {
    return (year % 4 != 0 || ((year % 100 == 0) && (year % 400 != 0)))? false : true;
}
*/
struct {
    int x;
    //int* y = new int;
} d, *p;

/*
Задание 1. Создать структуру, описывающую прямоугольник.
Написать функции для работы с этой структурой:
перемещение прямоугольника, изменение размера
прямоугольника, печать прямоугольника.
*/
struct rectangle {
    int width;
    int height;
} rec;
struct move {
    int x;
    int y;
} m;

void Resize() {
    cin >> rec.height >> rec.width;
}
void Print() {
    for (int i = 0; i <= rec.height + m.y; i++) {
        cout << string(m.x, ' ');
        for (int j = 0; j < rec.width && i >= m.y; j++) {
            cout << '*';
        }
        cout << endl;
    }
}
void Moving() {
    cin >> m.x >> m.y;
}

/*
Задание 2. Создайте структуру, описывающую точку
в двумерной системе координат (x, y). С помощью этой
структуры задайте две точки. Напишите функцию,
которая вычисляет расстояние между этими двумя точками?
*/
struct Point {
    int x;
    int y;
}p1, p2;
#define SQR(X) (X)*(X)
double Len() {
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    return sqrt(SQR(p2.x - p1.x) + SQR(p2.y - p1.y));
}

/*
Задание 3. Создайте структуру, описывающую простую
дробь. Реализуйте арифметические операции с дробями:
сумму, разность, умножение, деление.
Учесть возможность сокращения дробей и перевод
из неправильной дроби в простую.
*/
int a = 0;
struct fraction {
    int numerator;
    int denominator;
};

void PrintFract(fraction f) {
    cout << setw(2) << f.numerator << endl;
    (a) ? cout << a << "--\n" : cout << "--\n";
    cout << setw(2) << f.denominator << endl << endl;
}
fraction SumFract(fraction f1, fraction f2) {
    fraction f3;
    f3.denominator = f1.denominator * f2.denominator;
    f3.numerator = f1.numerator * f2.denominator 
        + f2.numerator * f1.denominator;
    return f3;
}
fraction SubFract(fraction f1, fraction f2) {
    fraction f3;
    f3.denominator = f1.denominator * f2.denominator;
    f3.numerator = f1.numerator * f2.denominator
        - f2.numerator * f1.denominator;
    return f3;
}
fraction MultFract(fraction f1, fraction f2) {
    fraction f3;
    f3.numerator = f1.numerator * f2.numerator;
    f3.denominator = f1.denominator * f2.denominator;
    return f3;
}
fraction DivFract(fraction f1, fraction f2) {
    fraction f3;
    f3.numerator = f1.numerator * f2.denominator;
    f3.denominator = f1.denominator * f2.numerator;
    return f3;
}
fraction SimpleFract(fraction f) {
    if (f.numerator > f.denominator) {
        a = f.numerator / f.denominator;
        f.numerator %= f.denominator;
    }
    int del = 1;
    for (int i = f.numerator; i > 1; i--) {
        if (f.numerator % i == 0 && f.denominator % i == 0) {
            del = i;
            break;
        }
    }
    f.numerator /= del;
    f.denominator /= del;

    return f;
}

int main()
{
    /* date myBirthDay = {7,3,1990,3, "march"};
    cout << "BirhDay\n";
    cout << myBirthDay.day << "."
        << myBirthDay.month << "."
        << myBirthDay.year << endl;
    myBirthDay.year = 1988;
    cin >> myBirthDay.month;
    cout << myBirthDay.day << "."
        << myBirthDay.month << "."
        << myBirthDay.year << endl;*/
    
    /*person per;
    strcpy_s(per.name, "Alex");
    per.d.day = 9;*/

    /*person* p;
    strcpy_s(p->lastname, "rthyrth");
    strcpy_s((*p).lastname, "rthyrth");*/

    /*date d{7,3,1990};
    date* p = nullptr;

    p = &d;*/
    //cout << p->day << " " << p->month << " " << p->year;

    //date d2{};
    //d2 = d;

    //cout << d.day << " " << d.month << " " << d.year << endl;
    //cout << d2.day << " " << d2.month << " " << d2.year << endl;
    //d2.day = 19;
    //cout << d.day << " " << d.month << " " << d.year << endl;
    //cout << d2.day << " " << d2.month << " " << d2.year << endl;

    /*Show(d2);
    d2 = Put();
    Show(d2);
    cout << IsLeapYear(d2.year);*/


    //int a; char c; double d;
    //int* i;
    /*cout << sizeof(a) << endl
        << sizeof(c) << endl
        << sizeof(d) << endl
        << sizeof(i) << endl
        << sizeof(int) << endl
        << sizeof(int*) << endl;

    cout << sizeof(date) << endl;
    date d{7, 6, (char*)"tgrth1111"};
    cout << sizeof(d);*/

    /*Resize();
    Print();
    Moving();
    Print();
    Resize();
    Print();*/

    fraction f1{3, 4};
    fraction f2{5, 8};

    fraction f3;
    f3 = SumFract(f1, f2);
    PrintFract(f3);
    f3 = SimpleFract(f3);
    PrintFract(f3);
    /*f3 = SubFract(f1, f2);
    PrintFract(f3);
    f3 = MultFract(f1, f2);
    PrintFract(f3);
    f3 = DivFract(f1, f2);
    PrintFract(f3);*/
}







