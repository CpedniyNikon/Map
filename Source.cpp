#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Pass
{
private:
	int year;
	int key;
public:
	void set_year(int year)
	{
		this->year = year;
	}
	void set_key(int key)
	{
		this->key = key;
	}
	int get_year()
	{
		return year;
	}
	int get_key()
	{
		return key;
	}
};

bool operator<(Pass A, Pass B)
{
	if (A.get_key() == B.get_key()) { return (A.get_year() < B.get_year()); }
	else return (A.get_key() < B.get_key());
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите количество пользователей." << endl;
	int size_arr = 0;
	cin >> size_arr;
	map <Pass, int> passes;
	map <Pass, int>::iterator iter_p = passes.begin();
	cout << "¬ведите год, пароль и значение соответственно каждому пользователю." << endl;
	for (int i = 0; i < size_arr; i++)
	{
		Pass pass;
		int year = 0;
		int key = 0;
		int value = 0;
		cin >> year >> key >> value;
		pass.set_year(year);
		pass.set_key(key);
		passes.emplace(pass, value);
	}

	cout << "¬ведите год и пароль дл€ получени€ значени€." << endl;
	Pass secondpass;
	int year_ = 0;
	int key_ = 0;
	cin >> year_ >> key_;
	secondpass.set_year(year_);
	secondpass.set_key(key_);
	if (passes.find(secondpass) != passes.end())
	{
		cout << "«начение: " << passes[secondpass] << endl;
	}
	else
	{
		cout << "ќшибка доступа!" << endl;
	}
	system("pause");
	return 0;
}