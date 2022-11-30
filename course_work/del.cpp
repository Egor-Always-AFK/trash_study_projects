// Kursah_5sem.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//https://www.cyberforum.ru/cpp-beginners/thread2663575.html

/*
1. Создать класс элементов заданной структуры, используя шаблоны классов. +
2. Работа программы осуществляется с помощью главного меню.
3. Предусмотреть ввод элементов класса, производить проверку корректности ввода
4. Предусмотреть сохранение введенных данных заданной структуры в файл, а также считывание данных из файла.
5. Предусмотреть сортировку элементов класса по выбранному параметру
6. Предусмотреть поиск определенного элемента класса по заданному параметру и вывод всех параметров данного элемента на экран.
7. Предусмотреть редактирование выбранного элемента класса.

Артикул обуви, цвет, Размер, Страна изготовитель, Сезон, состав, Цена, отдел, Количество. Выдавать список обуви в выбранном отделе для выбранного сезона.
  */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
 
struct  Shoes
{
private:
    string article;
    string color;
    int size;
    string country;
    string sizon;
    string sostav;
    double price;
    int otdel;
    int value;
 
public:
    friend istream & operator>>(istream &in, Shoes &a)
    {
        cout << "Input Shoes data:" << endl;
        cout << "\tАртикул: ";
        in >> a.article;
        cout << "\tЦвет: ";
        in >> a.color;
        cout << "\tРазмер: ";
        in >> a.size;
        cout << "\tСтрана изготовителя: ";
        in >> a.country;
        cout << "\tСезон: ";
        in >> a.sizon;
        cout << "\tСостав: ";
        in >> a.sostav;
        cout << "\tЦена: ";
        in >> a.price;
        cout << "\tОтдел: ";
        in >> a.otdel;
        cout << "\tКол-во на складе: ";
        in >> a.value;
        cout << endl;
        return in;
    }
 
    friend ostream & operator<<(ostream &out, const Shoes &a)
    {
        out << "Обувь: " << a.article << " " << a.color << " " << a.size << " " << a.country << " " << a.sizon << " " << a.sostav << " " 
        << a.price << " " << a.otdel << " " << a.value << endl;
        out << endl;
        return out;
    }
    friend ofstream & operator<<(ofstream &, const vector<Shoes> &);
    friend ifstream & operator>>(ifstream &, vector<Shoes> &);
};

 
ofstream & operator<<(ofstream &fout, const vector<Shoes> &abts)
{
    fout << abts.size() << endl;
    for (unsigned i = 0; i < abts.size(); ++i)
    {
        fout << abts[i].article 
             << abts[i].color 
             << abts[i].size 
             << abts[i].country 
             << abts[i].sizon 
             << abts[i].sostav 
             << abts[i].price 
             << abts[i].otdel
             << abts[i].value << endl;
      }
  return fout;
}
 
ifstream & operator>>(ifstream &fin, vector<Shoes> &abts)
{
    abts.clear();
    unsigned n;
    fin >> n;
    for (unsigned i = 0; i < n; ++i)
    {
        abts.push_back(Shoes());
        fin >> abts[i].article  
             >> abts[i].color  
             >> abts[i].size 
             >> abts[i].country 
             >> abts[i].sizon 
             >> abts[i].sostav 
             >> abts[i].price 
             >> abts[i].otdel 
             >> abts[i].value;
    }
    return fin;
}
 
void showMenu(void)
{
    cout << "Список действий:" << endl
         << "1. Заполнить вручную." << endl
         << "2. Вывод базы данных" << endl
         << "3. Сохранить файл." << endl
         << "4. Загрузить файл для чтения." << endl
         << "5. Добавление модели в  список." << endl
         << "6. Удалить модель по номеру." << endl
         << "7. Выход." << endl << endl
         << "Ваш выбор: ";
}
 
int main()
{
    vector<Shoes> abts;
    char choise = '\0';
    while (true)
    {
        unsigned n;
 
        if (choise == '7')
            break;
 
        showMenu();
 
        cin >> choise;
        cout << endl;
        switch (choise) {
        case '1':
        {
            cout << "Кол-во моделей? ";
            cin >> n;
            Shoes tmp;
            for (unsigned i = 0; i < n; ++i)
            {
                cout << i + 1 << ". ";
                cin >> tmp;
                abts.push_back(tmp);
            }
        }
            break;
        case '2':
            for (unsigned i = 0; i < abts.size(); ++i)
                cout << abts[i];
            break;
        case '3':
        {
            string fname;
            cout << "Set file name: ";
            cin >> fname;
            ofstream fout;
            fout.open(fname, ofstream::out);
            if (fout.is_open())
            {
                fout << abts;
                cout << endl << "data was written in file: \"" << fname << "\"" << endl << endl;
                fout.close();
            }
            else
                cout << "Error open file!" << endl << endl;
        }
            break;
        case '4':
        {
            string fname;
            cout << "Specify file name: ";
            cin >> fname;
            ifstream fin;
            fin.open(fname, ifstream::in);
            if (fin.is_open())
            {
                fin >> abts;
                cout << endl << "data was readen from file: \"" << fname << "\"" << endl << endl;
                fin.close();
            }
            else
                cout << "Error open file!" << endl << endl;
        }
            break;
        case '5':
        {
            string fname;
            cout << "Specify file name: ";
            cin >> fname;
            ifstream fin;
            fin.open(fname, ifstream::in);
            if (fin.is_open())
            {
                fin >> abts;
                cout << endl << "data was readen from file: \"" << fname << "\"" << endl << endl;
                fin.close();
            }
            else
            {
                cout << "Error open file to read!" << endl << endl;
                break;
            }
            unsigned k;
            cout << "Count of Shoess? ";
            cin >> k;
            vector<Shoes> tmp;
            for (unsigned i = 0; i < k; ++i)
            {
                tmp.push_back(Shoes());
                cout << i + 1 << ". ";
                cin >> tmp[i];
            }
            tmp.insert(tmp.begin(), abts.begin(), abts.end());
            ofstream fout;
            fout.open(fname, ofstream::out);
            if (fout.is_open())
            {
                fout << tmp;
                cout << endl << "data was written in file: \"" << fname << "\"" << endl << endl;
                fout.close();
            }
            else
                cout << "Error open file to write!" << endl << endl;
 
        }
            break;
        case '6':
        {
            string fname;
            cout << "Specify file name: ";
            cin >> fname;
            ifstream fin;
            fin.open(fname, ifstream::in);
            if (fin.is_open())
            {
                fin >> abts;
                cout << endl << "data was readen from file: \"" << fname << "\"" << endl << endl;
                fin.close();
            }
            else
            {
                cout << "Error open file to read!" << endl << endl;
                break;
            }
            unsigned k;
            cout << "Какой номер артикула вы хотите удалить из файла? \"" << fname << "\": ";
            cin >> k;
            abts.erase(abts.begin() + k - 1);
            ofstream fout;
            fout.open(fname, ofstream::out);
            if (fout.is_open())
            {
                fout << abts;
                cout << "Обувь по артиклу " << k << " была удалена из файла \"" << fname << "\"" << endl << endl;
                fout.close();
            }
            else
                cout << "Error open file to write!" << endl << endl;
        }
            break;
        case '7':
            cout << "Выход из программы..." << endl;
            break;
        case '8':
          {
            string fname;
            cout << "Specify file name: ";
            cin >> fname;
            ifstream fin;
            fin.open(fname, ifstream::in);
            if (fin.is_open())
            {
                fin >> abts;
                cout << endl << "data was readen from file: \"" << fname << "\"" << endl << endl;
                fin.close();
            }
            else
            {
                cout << "Error open file to read!" << endl << endl;
                break;
            }
              string cinOne;
              int cinTwo;
              for (unsigned i = 0; i < abts.size(); ++i){
                // if и вывод как то надо припендюрить 
              }
              
          }
        default:
            cout << "Не правильный ввод \"" << choise << "\"" << endl << endl;
            break;
        }
    }
}