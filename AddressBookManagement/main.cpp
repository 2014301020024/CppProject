#include <iostream>

using namespace std;

#include "string"
#include "main.h"

int main() {
    AddressBooks abs;
    int select;
    while (true) {
        showMenu();
        cin >> select;
        switch (select) {
            case 0:
                cout << "��ӭ�´�ʹ��!" << endl;
                return 0;
            case 1:
                addPerson(&abs);
                break;
            case 2:
                showPerson(&abs);
                break;
            case 3:
                deletePerson(&abs);
                break;
            case 4:
                searchPerson(&abs);
                break;
            case 5:
                changePerson(&abs);
                break;
            case 6:
                clearPerson(&abs);
                break;
            default:
                break;
        }
    }
}

void showMenu() {
    cout << "*************************" << endl;
    cout << "***** 1. �����ϵ�� *****" << endl;
    cout << "***** 2. ��ʾ��ϵ�� *****" << endl;
    cout << "***** 3. ɾ����ϵ�� *****" << endl;
    cout << "***** 4. ��ѯ��ϵ�� *****" << endl;
    cout << "***** 5. �޸���ϵ�� *****" << endl;
    cout << "***** 6. �����ϵ�� *****" << endl;
    cout << "***** 0. �˳�ͨѶ¼ *****" << endl;
    cout << "*************************" << endl;
}

void addPerson(AddressBooks *abs) {
    if (abs->size == MAX) {
        cout << "ͨѶ¼�������޷����" << endl;
        return;
    }

    string name;
    cout << "����������:" << endl;
    cin >> name;
    abs->personArray[abs->size].name = name;

    int sex;
    cout << "�������Ա�:" << endl;
    cout << "1: ��" << endl;
    cout << "2: Ů" << endl;
    while (true) {
        cin >> sex;
        if (sex == 1 || sex == 2) {
            abs->personArray[abs->size].sex = sex;
            break;
        }
    }

    int age;
    cout << "����������:" << endl;
    while (true) {
        cin >> age;
        if (age > 0 && age < 150) {
            abs->personArray[abs->size].age = age;
            break;
        }
    }

    string phone;
    cout << "������绰����:" << endl;
    cin >> phone;
    abs->personArray[abs->size].phone = phone;

    string address;
    cout << "�������ַ:" << endl;
    cin >> address;
    abs->personArray[abs->size].address = address;

    abs->size++;

    cout << "��ӳɹ�" << endl;
}

void showPerson(AddressBooks *abs) {
    if (abs->size == 0) {
        cout << "ͨѶ¼��û��" << endl;
        return;
    }

    for (int i = 0; i < abs->size; i++) {
        cout << "name   : " << abs->personArray[i].name << endl;
        cout << "sex    : " << abs->personArray[i].sex << endl;
        cout << "age    : " << abs->personArray[i].age << endl;
        cout << "phone  : " << abs->personArray[i].phone << endl;
        cout << "address: " << abs->personArray[i].address << endl;
    }
}

int isExisted(AddressBooks *abs, const string &name) {
    for (int i = 0; i < abs->size; i++) {
        if (abs->personArray[i].name == name) {
            return i;
        }
    }
    return -1;
}

void deletePerson(AddressBooks *abs) {
    string namePrevious;
    cout << "����������:" << endl;
    cin >> namePrevious;
    int ret = isExisted(abs, namePrevious);
    if (ret != -1) {
        for (int j = ret; j < abs->size; j++) {
            abs->personArray[j] = abs->personArray[j + 1];
        }
        abs->size--;
    } else {
        cout << "���޴���" << endl;
    }
}

void searchPerson(AddressBooks *abs) {
    string namePrevious;
    cout << "����������:" << endl;
    cin >> namePrevious;
    int ret = isExisted(abs, namePrevious);
    if (ret != -1) {
        cout << "name   : " << abs->personArray[ret].name << endl;
        cout << "sex    : " << abs->personArray[ret].sex << endl;
        cout << "age    : " << abs->personArray[ret].age << endl;
        cout << "phone  : " << abs->personArray[ret].phone << endl;
        cout << "address: " << abs->personArray[ret].address << endl;
    } else {
        cout << "���޴���" << endl;
    }
}

void changePerson(AddressBooks *abs) {
    string namePrevious;
    cout << "����������:" << endl;
    cin >> namePrevious;
    int ret = isExisted(abs, namePrevious);
    if (ret != -1) {
        string name;
        cout << "����������:" << endl;
        cin >> name;
        abs->personArray[ret].name = name;

        int sex;
        cout << "�������Ա�:" << endl;
        cout << "1: ��" << endl;
        cout << "2: Ů" << endl;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[ret].sex = sex;
                break;
            }
        }

        int age;
        cout << "����������:" << endl;
        while (true) {
            cin >> age;
            if (age > 0 && age < 150) {
                abs->personArray[ret].age = age;
                break;
            }
        }

        string phone;
        cout << "������绰����:" << endl;
        cin >> phone;
        abs->personArray[ret].phone = phone;

        string address;
        cout << "�������ַ:" << endl;
        cin >> address;
        abs->personArray[ret].address = address;

        cout << "�޸ĳɹ�" << endl;
    } else {
        cout << "���޴���" << endl;
    }
}

void clearPerson(AddressBooks *abs) {
    abs->size = 0;
    cout << "ͨѶ¼�����" << endl;
    system("pause");
    system("cls");
}

