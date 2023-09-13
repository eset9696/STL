#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <forward_list>

using std::cin;
using std::cout;
using std::endl;

#define delimeter "\n--------------------------------------------\n"
#define tab "\t"

template <typename T> void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:    " << vec.size() << endl;
	cout << "max_size: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
}
template <typename T> void list_print(const std::list<T>& lst)
{
	for(int i : lst)
	{
		cout << i << "\t";
	}
	cout << endl;
}

template <typename T> void f_list_print(const std::forward_list<T>& f_lst)
{
	for (int i : f_lst)
	{
		cout << i << "\t";
	}
	cout << endl;
}
//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_LIST
#define STL_FORWARD_LIST
void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_ARRAY
	//Array Ц это контейнер, который хранит данные в виде статического массива.

	const int N = 5;
	std::array<int, N> arr = { 3, 5, 8, 13, 21};
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнер, который хранит данные в виде динамического массива.

	std::vector<int> vec = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
	/*try
	{
		for (int i = 0; i < vec.size() * 2; i++)
		{
			cout << vec.at(i) << "\t";
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	vector_properties(vec);
	vec.push_back(55);
	vector_properties(vec);
	cout << delimeter;
	vec.reserve(120);
	vec.shrink_to_fit();
	vector_properties(vec);
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	cout << delimeter;
	std::vector<double> d_vec = {2.7, 3.14, 4.5};
	vector_properties(d_vec);
	cout << d_vec.front()<< endl;
	cout << d_vec.back() << endl;*/


	int index;
	int value;
	cout << "¬ведите индекс добавл€емого элемента:\t"; cin >> index;
	cout << "¬ведите значение добавл€емого элемента:\t"; cin >> value;
	vec.insert(vec.begin() + index, value);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	vec.erase(vec.begin() + index);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	for (std::vector<int>::iterator it = vec.begin(); it < vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it < vec.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (int i : vec)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif // STL_VECTOR
#ifdef STL_LIST
	int index;
	int value;
	cout << "¬ведите индекс вставл€емого элемента:\t"; cin >> index;
	cout << "¬ведите значение вставл€емого элемента:\t"; cin >> value;
	std::list<int> lst = { 0, 1, 1, 2, 3, 5, 8, 13, 21 };
	list_print(lst);
	std::list<int>::iterator it = lst.begin();
	try
	{
		if (lst.size() - 1 < index) throw std::exception("¬ыход за пределы списка!");
		else
		{
			std::advance(it, index);
			lst.insert(it, value);
			list_print(lst);
			lst.erase(--it);
			list_print(lst);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	
#endif // STL_LIST

#ifdef STL_FORWARD_LIST
	int index;
	int value;
	cout << "¬ведите индекс вставл€емого элемента:\t"; cin >> index;
	cout << "¬ведите значение вставл€емого элемента:\t"; cin >> value;
	std::forward_list<int> f_lst = { 0, 1, 1, 2, 3, 5, 8, 13, 21 };
	f_list_print(f_lst);
	std::forward_list<int>::iterator it = f_lst.before_begin();
	std::advance(it, index);
	f_lst.insert_after(it, value);
	f_list_print(f_lst);
	f_lst.erase_after(it);
	f_list_print(f_lst);
#endif // STL_FORWARD_LIST

}