// AutoOwner.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "AutoOwnerDirectory.h"


int main()
{
	setlocale(LC_ALL, "Rus");
	int k, i, count;
	string str1, str2;
	autoOwnerDirectory obj;
	do {
		cout << "1 - добавить данные \n2 - удалить запись \n3 - редактировать запись \n4 - поиск фамилии автовладельца по номеру автомобиля\n5 - вывод записей каталога, отсортированных по номерам" << endl;
		cout << "0 - выход \nВыберите операцию:";
		do {
			cin >> k;
		} while ((k < 0) || (k>5));
		switch (k)
		{
		case 1:
			cout << "Введите количество записей, которые вы хотите добавить в каталог: ";
			cin >> count;
			for (i = 0; i < count; i++)
			{
				cout << "Введите информацию о владельце: ";
				cin >> str1;
				cout << "Введите номер машины: ";
				cin >> str2;
				obj.add_new_auto_owner(str1, str2);
			}
			cout << "Ваш каталог: " << endl;
			obj.print_directory();
			break;
		case 2:
			cout << "Введите номер записи, которую хотите удалить: ";
			cin >> count;
			obj.delete_auto_owner(count);
			cout << "Ваш каталог: " << endl;
			obj.print_directory();
			break;
		case 3:
			obj.edit_auto_owner();
			cout << "Ваш каталог: " << endl;
			obj.print_directory();
			break;
		case 4:
			cout << "Введите номер машины для поиска автовладельца: ";
			cin >> str2;
			obj.search_owner(str2);
			break;
		case 5:
			obj.sort_auto_owner();
			break;
		}
	} while (k != 0);
	system("pause");
	return 0;
}
