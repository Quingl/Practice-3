// Prakt3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//3 5   1 2     0.6>0.5 3 6 и 6 12 

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
class Fraction
{
private:

	int m_Numerator;
	int m_Denominator;
public:
	Fraction() {}
	Fraction(int Numerator, int Denominator) : m_Numerator(Numerator), m_Denominator(Denominator)
	{
	}
	int getNumerator() { return m_Numerator; }
	void setNumerator(int Numerator) { m_Numerator = Numerator; }
	int getDenominator() { return m_Denominator; }
	void setDenominator(int Denominator) { m_Denominator = Denominator; }

	
	friend bool operator==(Fraction a,  Fraction b);
	friend bool operator!= (Fraction& s1,  Fraction& s2);

	friend bool operator> (Fraction s1,  Fraction s2);
	friend bool operator>= (Fraction& s1,  Fraction& s2);

	friend bool operator< (Fraction s1,  Fraction s2);
	friend bool operator<= (Fraction& s1,  Fraction& s2);

	friend std::ostream& operator<< (std::ostream& out, const Fraction& s);
	
};
bool operator==(Fraction a, Fraction b) 
{
return((a.getNumerator() == b.getNumerator()) && (a.getDenominator() == b.getDenominator()));
}
	bool operator< (Fraction a, Fraction b)
	{
		double aq = (double)a.m_Numerator / (double)a.m_Denominator;
		double bq = (double)b.m_Numerator / (double)b.m_Denominator;
		return aq < bq;
	}

std::ostream& operator<< (std::ostream& out, const Fraction& s)
{

	out << "Fraction(" << s.m_Numerator << ", " << s.m_Denominator << ")";

	return out;
}
//4
bool equality(Fraction value){
	return value.getDenominator() == value.getNumerator();
}
//5
Fraction replecator(Fraction value)
{
	value.setDenominator(value.getNumerator() * 3);
	return Fraction(value.getNumerator(), value.getDenominator());
}
//8
void IncreaseOn2(Fraction &value)
{
	
	if (value.getNumerator() % 13 == 0)
	{

		value.setNumerator(value.getNumerator());
		cout << value.setNumerator << endl;
	}
}
// 9
void OutputVector(Fraction value)
{
	cout << value << " ";
} 
// 10 2 3 4      2 3 4 5 6
template <class _FwdIt, class _SwdIt>
inline int EQ(const _FwdIt _FFirst, const _FwdIt _FLast, const _SwdIt _SFirst, const _SwdIt _SLast) {
	auto _UFFirst = _Get_unwrapped(_FFirst);
	const auto _UFLast = _Get_unwrapped(_FLast);
	auto _USFirst = _Get_unwrapped(_SFirst);
	const auto _USLast = _Get_unwrapped(_SLast);
	for (int i = 0; _UFFirst != _UFLast && _USFirst != _USLast; i++, ++_UFFirst, ++_USFirst) {
		if (*_UFFirst == *_USFirst) {
			
		}
		else
		{
			return i;
		}
	}
	if (_UFLast - _UFFirst == _USFirst - _USLast)
		return -1;
	else
		return -2;
}


int main(int argc, char* argv[], char* env[])
{
	setlocale(LC_ALL, "Russian");
	//1. Создать последовательный контейнер(Vector).
	cout << "*********1*********" << endl;
	cout << "создан контейнер vector" << endl;
	vector<Fraction> Vector;
	//2Заполнить контейнер элементами пользовательского типа (тип указан в варианте). 
	//Данные читать из файла, имя файла передается в виде параметра функции main, при отсутствии параметра запрашивается у пользователя. 
	//	Для пользовательского типа перегрузить необходимые операции (присваивание, сравнение, вывод).
	cout << "*********2*********" << endl;
	cout << "заполнение Vector из файла" << endl;
	string inputfilename;
	if (argc > 1) {
		inputfilename = argv[argc - 1];
		cout << " использован файл" << inputfilename << " для сбора данных" << endl;
	}
	else {
		cout << " пожалуйста введите название файла" << endl;
		cin >> inputfilename;
	}
	ifstream fin(inputfilename);
	while (!fin.eof()) {
		int first;
		double second;
		fin >> first >> second;
		fin.get();
		Vector.push_back(Fraction(first, second));
	}

	//3 Посчитать количество элементов контейнера с равными числителем и знаменателем
	cout << "*********3*********" << endl;
	cout << "Счет количества элементов с равными числителем и знаменателем" << endl;
	cout << "Колличество элементов с равным числителем и знаменателем = " << count_if(Vector.begin(), Vector.end(), equality) << endl;
	//4. Заменить элементы Для элементов равных заданному увеличить в 3 раза второе поле пары
	cout << "*********4*********" << endl;
	cout << "Введите пару элементов типа int " << endl;
	int Num = 0;
	int Den = 0;
	cin >> Num >> Den;
	Fraction task4 = Fraction(Num,Den);
	replace(Vector.begin(), Vector.end(), task4, Fraction(task4.getDenominator(),task4.getNumerator()*3));
	vector<Fraction>::const_iterator it1 = Vector.begin();
	cout << "Вывод Vector на экран" << endl;
	for_each(Vector.begin(), Vector.end(), OutputVector);
	cout << endl;
	//5 Удалить элеметы Равные заданному
	cout << "*********5*********" << endl;
	cout << "Введите пару элементов типа int " << endl;
	Num = 0;
	Den = 0;
	cin >> Num >> Den;
	Fraction task5 = Fraction(Num, Den);
	auto new_end = remove(Vector.begin(),Vector.end(), task5);
	Vector.erase(new_end, Vector.end()); // Удалить лишнее
	it1 = Vector.begin();
	cout << "Вывод Vector на экран" << endl;
	for_each(Vector.begin(), Vector.end(), OutputVector);
	cout << endl;

	//6 Отсортировать контейнер по убыванию и по возрастанию ключевого поля(использовать алгоритм sort())
	cout << "*********6*********" << endl;
	cout << "сортировка Vector по значению a/b" << endl;
	sort(Vector.rbegin(), Vector.rend());
	cout << "Вывод Vector отсортированного по убыванию  на экран" << endl;
	for_each(Vector.begin(), Vector.end(), OutputVector);
	cout << endl;
	sort(Vector.begin(), Vector.end());
	cout << "Вывод Vector отсортированного по возростанию на экран" << endl;
	for_each(Vector.begin(), Vector.end(), OutputVector);
	cout << endl;
	//7 Найти в контейнере заданный элемент Последний меньший заданного
	cout << "*********7*********" << endl;
	cout << "Введите пару элементов типа int " << endl;
	Fraction* p;
	Num = 0;
	Den = 0;
	cin >> Num >> Den;
	Fraction task7 = Fraction(Num, Den);
	auto q = find(Vector.begin(), Vector.end(), task7);
	if (q > Vector.begin())
	cout << *(q - 1) << endl;
	else
		cout << "Меньше значений нет" << endl;
	
	// 8 Каждый элемент увеличить в 2 раза 
	cout << "*********8*********" << endl;
	cout << "Вывод Vector отсортированного по возростанию на экран" << endl;
	
	for_each(Vector.begin(), Vector.end(), IncreaseOn2);
	cout << "Вывод Vector отсортированного по возростанию на экран" << endl;
	for_each(Vector.begin(), Vector.end(), OutputVector);
	cout << endl;
	 // 9 вывод
	cout << "*********9*********" << endl;
	for_each(Vector.begin(), Vector.end(), OutputVector);
	// 10 вывод
	vector<Fraction> vec1;
	vec1.push_back(Fraction(5, 2));
	vec1.push_back(Fraction(3, 1));
	vec1.push_back(Fraction(4, 7));
	vector<Fraction> vec2;
	vec2.push_back(Fraction(5, 2));
	vec2.push_back(Fraction(3, 1));
	vec2.push_back(Fraction(4, 7));
	vec2.push_back(Fraction(7, 7));
	cout << EQ(vec1.begin(), vec1.end(), vec2.begin(),vec2.end());
	return 0;
}

//Контейнер – вектор Тип элементов – Fraction; 
//Класс Fraction. Представлен в виде двух полей: числитель, знаменатель.
//вариант создаваемого обобщенного алгоритма 18
//18. Написать обобщенный алгоритм, который сравнивает элементы 2х диапазонов источников в соответствии с определенных бинарным 
//предикатом и находит первую позицию, где происходит несоответствие.
//3
//С равными числителем и знаменателем
//4
//Для элементов равных заданному увеличить в 3 раза второе поле пары
//5
//Равные заданному
//7
//Последний меньший заданного
//8
//Каждый элемент увеличить в 2 раза
