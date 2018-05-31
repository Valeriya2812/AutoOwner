#include "stdafx.h"
#include "AutoOwnerDirectory.h"


void autoOwnerDirectory::print_directory()
{
	int i = 1;
	for (pos = auto_owner.begin(); pos != auto_owner.end(); ++pos)
	{
		cout << i << "\t" << pos->first << "\t" << pos->second << endl;
		i++;
	}
}


void autoOwnerDirectory::add_new_auto_owner(string owner, string number) {
	auto_owner.insert(make_pair(owner, number));
}
void autoOwnerDirectory::delete_auto_owner(int num) {
	num -= 1;
	pos = auto_owner.begin();
	advance(pos, num);
	if (pos != auto_owner.end())
		auto_owner.erase(pos);
	else
		cout << "Запись не найдена!" << endl;
}
void autoOwnerDirectory::edit_auto_owner() {
	int num, k;
	string str_num, str_owner;
	cout << "Введите номер записи, которую хотите изменить: ";
	cin >> num;
	num -= 1;
	pos = auto_owner.begin();
	advance(pos, num);
	do {
		do {
			cout << "Если вы хоти изменить номер машины, нажмите 1, если информацию о владельце - 2, выйти - 0 ";
			cin >> k;
		} while ((k < 0) || (k>2));
		switch (k)
		{
		case 1:
			cout << "Введите новый номер машины: ";
			cin >> pos->second;
			break;
		case 2:
			str_num = pos->second;
			delete_auto_owner(num + 1);
			cout << "Введите информацию о владельце: ";
			cin >> str_owner;
			add_new_auto_owner(str_owner, str_num);
			break;
		}
	} while (k != 0);

}


void autoOwnerDirectory::search_owner(string auto_num)
{
	for_each(auto_owner.begin(), auto_owner.end(), findNum(auto_num));
}


void autoOwnerDirectory::sort_auto_owner()
{
	int i = 1;
	multimap<string, string>num_sort;
	for (pos = auto_owner.begin(); pos != auto_owner.end(); ++pos)
		num_sort.insert(make_pair(pos->second, pos->first));
	for (pos = num_sort.begin(); pos != num_sort.end(); ++pos)
	{
		cout << i << "\t" << pos->first << "\t" << pos->second << endl;
		i++;
	}
	num_sort.erase(num_sort.begin(), num_sort.end());
}
