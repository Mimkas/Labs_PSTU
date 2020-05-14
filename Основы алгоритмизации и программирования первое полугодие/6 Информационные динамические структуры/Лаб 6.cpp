#include "Iostream"
#include <fstream>
#define NULL 0
using namespace std;
struct number
{
    char key[20];
    char data[20];
    number* next;
    number* prev;
}
*head, * tail;
void enter()
{
    number* n = head;
    n = NULL;
    head = tail = NULL;
    cout << "пустой лист создан.\n";
    bool cont = true;
    do 
    {
        number* n = new number;
        cout << "\nвведите ключ для записи:\n";
        cin >> n->key;
        cout << "\nвведите данные:\n";
        cin >> n->data;
        if (head == NULL)
        {
            n->prev = NULL;
            head = n;
            tail = head;
        }
        else
        {
            n->prev = tail;
            tail->next = n;
        }
        n->next = NULL;
        tail = n;
        cout << "Продолжить ввод данных (y/n): ";
        char h;
        cin >> h;
        cout << "\n";

        while (h != 'y' && h != 'n') {
            cout << "Ответ не распознан\n";
            cout << "Продолжить ввод данных, введите y(да) или n(нет):\n";
            cin >> h;
        }

        if (h == 'y') cont = true;
        else if (h == 'n') cont = false;
    } 
    while (cont);
}
void coutdata()
{
    number* n = head;
    int num = 0;
    if (n == NULL || (head && tail) == NULL)
    {
        cout << "В списке нет данных\n";
    }
    else
    {
        cout << "Список имеет вид:\n" << "номер\t\t" << "ключ\t\t" << "данные\n";
        while (n != NULL)
        {
            ++num;
            cout << num << "\t\t" << n->key << "\t\t" << n->data << "\n";
            n = n->next;
        }
    }
    cout << "\n";
}
void deleteelem() {
    number* n = head;
    char keyserch[20];
    cout << "Введите ключ для удаляемого элемента:\n";
    cin >> keyserch;
    cout << "\n";
    while (n != NULL) 
    {
        if (!strcmp(n->key, keyserch)) 
        {
            if (n->prev) n->prev->next = n->next;
            if (n->next) n->next->prev = n->prev;
            if (!n->prev) head = n->next;
            if (!n->next) tail = n->prev;
            delete n;
            return;
        }
        else n = n->next;
    }
}
void appelem() 
{
    number* bof = new number;
    number* n = head;
    if (head == NULL || (head && tail) == NULL) 
    {
        cout << "В списке нет данных, невозможно вставить элемент\n";
    }
    else 
    {
        int num, kol=0;
        for (number* n = head; n != NULL; n = n->next)
        {
            kol++;
        }
        cout << "В списке " << kol << " элементов\n";
        cout << "Введите номер для добавления элемента:\n";
        cin >> num;
        cout << "\n";
        if (num > kol) 
        {
            cout << "Введите новый ключ элемента:\n";
            cin >> bof->key;
            cout << "Введите данные:\n";
            cin >> bof->data;
            bof->next = NULL;
            bof->prev = tail;
            if (tail) tail->next = bof;
            tail = bof;
            if (head == NULL) head = bof;
            cout << "\n";
        }
        else if (num <= 1) 
        {
            cout << "Введите новый ключ элемента:\n";
            cin >> bof->key;
            cout << "Введите данные:\n";
            cin >> bof->data;
            bof->next = head;
            bof->prev = NULL;
            if (head) head->prev = bof;
            head = bof;
            if (tail == NULL) tail = bof;
            cout << "\n";
        }
        else 
        {
            for (int i = 1; i <= num - 1; i++) n = n->next;
            if (n == NULL) exit(5);
            cout << "Введите новый ключ элемента:\n";
            cin >> bof->key;
            cout << "Введите данные:\n";
            cin >> bof->data;
            bof->prev = n;
            bof->next = n->next;
            if (n->next) n->next->prev = bof;
            n->next = bof;
            if (!n->prev) head = n;
            if (!n->next) tail = n;
            cout << "\n";
        }
    }
}
void infile() 
{
    number* n = head;
    ofstream data("data.txt");
    do 
    {
        data.write((char*)&(n->key), sizeof(n->key));
        data.write((char*)&(n->data), sizeof(n->data));
        n = n->next;
    } 
    while (n != NULL);
    data.close();
}
void outfile() 
{
    ifstream data("data.txt");
    while (data.peek() > NULL) 
    {
        number* n = new number;

        data.read((char*)&(n->key), sizeof(n->key));
        data.read((char*)&(n->data), sizeof(n->data));

        if (head == NULL) 
        {
            n->prev = NULL;
            head = n;
            tail = head;
        }
        else 
        {
            n->prev = tail;
            tail->next = n;
        }

        n->next = NULL;
        tail = n;
    }
    data.close();
}
void alldelete() 
{
    number* n = head;
    if (n == NULL || (head && tail) == NULL)
    {
        cout << "Невозможно удалить пустой список!\n";
        exit(1);
    }
    else 
    {
        while (n != NULL) 
        {
            head = n->next;
            delete n;
            n = head;
        }
    }
    if ((head && tail) == NULL) cout << "Список пуст\n\n";
}

void main()
{
    setlocale(LC_ALL, "Russian");
    enter();
    coutdata();
    deleteelem();
    coutdata();
    appelem();
    coutdata();
    infile();
    alldelete();
    coutdata();
    outfile();
    coutdata();
    alldelete();
    coutdata();
}