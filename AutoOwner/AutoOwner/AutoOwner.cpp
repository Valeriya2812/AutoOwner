// AutoOwner.cpp: ���������� ����� ����� ��� ����������� ����������.
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
		cout << "1 - �������� ������ \n2 - ������� ������ \n3 - ������������� ������ \n4 - ����� ������� ������������� �� ������ ����������\n5 - ����� ������� ��������, ��������������� �� �������" << endl;
		cout << "0 - ����� \n�������� ��������:";
		do {
			cin >> k;
		} while ((k < 0) || (k>5));
		switch (k)
		{
		case 1:
			cout << "������� ���������� �������, ������� �� ������ �������� � �������: ";
			cin >> count;
			for (i = 0; i < count; i++)
			{
				cout << "������� ���������� � ���������: ";
				cin >> str1;
				cout << "������� ����� ������: ";
				cin >> str2;
				obj.add_new_auto_owner(str1, str2);
			}
			cout << "��� �������: " << endl;
			obj.print_directory();
			break;
		case 2:
			cout << "������� ����� ������, ������� ������ �������: ";
			cin >> count;
			obj.delete_auto_owner(count);
			cout << "��� �������: " << endl;
			obj.print_directory();
			break;
		case 3:
			obj.edit_auto_owner();
			cout << "��� �������: " << endl;
			obj.print_directory();
			break;
		case 4:
			cout << "������� ����� ������ ��� ������ �������������: ";
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
