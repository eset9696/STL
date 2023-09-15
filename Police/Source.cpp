#include <iostream>
#include <fstream>
#include <map>
#include <list>

#define tab "\t"

using std::cin;
using std::cout;
using std::endl;

class Crime;
void print(const std::map<std::string, std::list<Crime>>& base);
std::ostream& operator<<(std::ostream& os, const Crime& crime);
std::ostream& operator<<(std::ostream& os, const std::pair<std::string, std::list<Crime>>& pair);
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);

const std::map<int, std::string> CRIMES =
{
	{0, "���������� ������������ ��������� ��� ����"},
	{1, "������ �� ������� ���� ���������"},
	{2, "���������� ��������"},
	{3, "�������� � ������������ �����"},
	{4, "����������� ��������"},
	{5, "���������� ������������ ��������� � ��������� ����"},
	{6, "����������� ���������� �������"},
	{7, "�������������� ������ ������������"}
};

class Crime
{
	int id;
	std::string place;
public:
	int get_id() const
	{
		return id;
	}
	const std::string& get_place() const
	{
		return place;
	}

	void set_id(int id)
	{
		if (id > CRIMES.size()) id = 0;
		this->id = id;
	}

	void set_place(const std::string& place)
	{
		this->place = place;
	}

	Crime(int id, const std::string& place)
	{
		set_id(id);
		set_place(place);
	}
	~Crime() { }
};

std::ostream& operator<<(std::ostream& os, const Crime& crime)
{
	for(std::map<int, std::string>::const_iterator it = CRIMES.begin(); it != CRIMES.end(); it++)
	{
		if (crime.get_id() == it->first)
		{
			os << tab;
			os.width(55);
			os << std::left;
			os  << it->second;
		}
	}
	
	os << crime.get_place() << endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const std::pair<std::string, std::list<Crime>>& pair)
{
	os << pair.first << ":" << endl;
	for(std::list<Crime>::const_iterator it = pair.second.begin(); it != pair.second.end(); it++)
	{
		os << *it;
	}
	return os;
}


void main()
{
	setlocale(LC_ALL, "");

	std::map<std::string, std::list<Crime>> base =
	{
		{"m777ab", {Crime(1, "����� ������"), Crime(2, "����� ������"), Crime(4, "����� ��������� �������")}},
		{"k231cc", {Crime(5, "����� ����� ������"), Crime(6, "����� ����� ������")}},
		{"l441oc", {Crime(3, "����� ������������"), Crime(7, "����� ������������")}},
	};
	for(std::pair<std::string, std::list<Crime>> i : base)
	{
		cout << i << endl;
	}
	save(base, "Base.txt");
}

void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); it++)
	{
		cout << it->first << ":" << endl;
		for (std::list<Crime>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); l_it++) cout << *l_it;
		cout << endl;
	}
}

void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout;
	fout.open(filename);
	if(fout.is_open())
	{
		for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); it++)
		{
			fout << it->first << ":" << endl;
			for (std::list<Crime>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); l_it++) fout << *l_it;
			cout << endl;
		}
	}
	else
	{
		std::cerr << "������!" << endl;
	}
	fout.close();
	std::string command = "start notepad ";
	command += filename;
	system(command.c_str());
}
