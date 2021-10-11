#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

/// <summary>
/// Класс для описания исключения
/// </summary>
class Exception1 {};

/// <summary>
/// Класс для описания исключения
/// с выводом сообщения об ошибке
/// </summary>
class Exception2
{
	string msg;
public:
	Exception2(const string& s) : msg(s) {}
	const char* message() const { return msg.c_str(); }
};

/// <summary>
/// Класс-наследник с описанием исключения 
/// (для указания неверного аргумента)
/// </summary>
class Exception3 : public invalid_argument
{
	bool num;
public:
	Exception3(const string msg, bool n) : invalid_argument(msg), num(n) {}
	bool arg() const { return num; }
};

/// <summary>
/// Структура с описанием даты
/// </summary>
struct Date
{
	/// <summary>
	/// День
	/// </summary>
	int dd;

	/// <summary>
	/// Месяц
	/// </summary>
	int mm;

	/// <summary>
	/// Год
	/// </summary>
	int yy;
};

// число дней в каждом из месяцев
const int monthDays[12]
= { 31, 28, 31, 30, 31, 30,
   31, 31, 30, 31, 30, 31 };

/// <summary>
/// Считает число високосных лет с заданной даты
/// </summary>
int countLeapYears(const Date& d)
{
	int years = d.yy;
	if (d.mm <= 2)
		years--;
	return years / 4
		- years / 100
		+ years / 400;
}

/// <summary>
/// Считает количество дней между двумя датами
/// (без спецификации исключений)
/// </summary>
/// <param name="dt1">первая дата</param>
/// <param name="dt2">вторая дата</param>
/// <returns>число дней</returns>
int getDifference1(Date& dt1, Date& dt2)
{
	if (dt1.dd < 1 || dt1.mm < 1 || dt1.yy < 1 ||
		dt1.dd > 31 || dt1.mm > 12 || dt1.yy > 2021 ||
		dt2.dd < 1 || dt2.mm < 1 || dt2.yy < 1 ||
		dt2.dd > 31 || dt2.mm > 12 || dt2.yy > 2021 ||
		cin.fail())
		cerr << "Произошло исключение в функции getDifference1!" << endl;

	long int n1 = dt1.yy * 365 + dt1.dd;

	for (int i = 0; i < dt1.mm - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(dt1);

	long int n2 = dt2.yy * 365 + dt2.dd;
	
	for (int i = 0; i < dt2.mm - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	int diff = n2 - n1;

	return diff;
}

/// <summary>
/// со спецификацией throw(invalid_argument)
/// </summary>
int getDifference2(Date& dt1, Date& dt2) throw(invalid_argument)
{
	if (dt1.yy < 1 || dt1.yy > 2021 || dt2.yy < 1 || dt2.yy > 2021 ||
		cin.fail())
		throw invalid_argument("Год должен лежать в пределах от 1 до 2021!");

	if (dt1.mm < 1 || dt1.mm > 12 || dt2.mm < 1 || dt2.mm > 12 ||
		cin.fail())
		throw invalid_argument("Месяц должен лежать в пределах от 1 до 12!");

	if (dt1.dd < 1 || dt1.dd > 31 || dt2.dd < 1 || dt2.dd > 31 || 
		cin.fail())
		throw invalid_argument("День должен лежать в пределах от 1 до 31!");


	long int n1 = dt1.yy * 365 + dt1.dd;

	for (int i = 0; i < dt1.mm - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(dt1);

	long int n2 = dt2.yy * 365 + dt2.dd;

	for (int i = 0; i < dt2.mm - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	int diff = n2 - n1;

	return diff;
}

// с собственным реализованным исключением:

/// <summary>
/// как пустой класс
/// </summary>
int getDifference3_1(Date& dt1, Date& dt2) throw(Exception1)
{
	if (dt1.yy < 1 || dt1.yy > 2021 || dt2.yy < 1 || dt2.yy > 2021 ||
		cin.fail())
		throw Exception1();

	if (dt1.mm < 1 || dt1.mm > 12 || dt2.mm < 1 || dt2.mm > 12 ||
		cin.fail())
		throw Exception1();

	if (dt1.dd < 1 || dt1.dd > 31 || dt2.dd < 1 || dt2.dd > 31 ||
		cin.fail())
		throw Exception1();


	long int n1 = dt1.yy * 365 + dt1.dd;

	for (int i = 0; i < dt1.mm - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(dt1);

	long int n2 = dt2.yy * 365 + dt2.dd;

	for (int i = 0; i < dt2.mm - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	int diff = n2 - n1;

	return diff;
}

/// <summary>
/// с конкретной спецификацией с подходящим стандартным исключением
/// </summary>
int getDifference3_2(Date& dt1, Date& dt2) throw(Exception2)
{
	if (dt1.yy < 1 || dt1.yy > 2021 || dt2.yy < 1 || dt2.yy > 2021 ||
		cin.fail())
		throw Exception2("Год должен лежать в пределах от 1 до 2021!");

	if (dt1.mm < 1 || dt1.mm > 12 || dt2.mm < 1 || dt2.mm > 12 ||
		cin.fail())
		throw Exception2("Месяц должен лежать в пределах от 1 до 12!");

	if (dt1.dd < 1 || dt1.dd > 31 || dt2.dd < 1 || dt2.dd > 31 ||
		cin.fail())
		throw Exception2("День должен лежать в пределах от 1 до 31!");


	long int n1 = dt1.yy * 365 + dt1.dd;

	for (int i = 0; i < dt1.mm - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(dt1);

	long int n2 = dt2.yy * 365 + dt2.dd;

	for (int i = 0; i < dt2.mm - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	int diff = n2 - n1;

	return diff;
}

/// <summary>
/// спецификация с собственным реализованным исключением
/// </summary>
int getDifference3_3(Date& dt1, Date& dt2) throw(Exception3)
{
	if (dt1.yy < 1 || dt1.yy > 2021 ||
		cin.fail())
		throw Exception3("Неверный аргумент ", dt1.yy);

	if (dt2.yy < 1 || dt2.yy > 2021 ||
		cin.fail())
		throw Exception3("Неверный аргумент ", dt2.yy);

	if (dt1.mm < 1 || dt1.mm > 12 ||
		cin.fail())
		throw Exception3("Неверный аргумент ", dt1.mm);

	if (dt2.mm < 1 || dt2.mm > 12 ||
		cin.fail())
		throw Exception3("Неверный аргумент ", dt2.mm);

	if (dt1.dd < 1 || dt1.dd > 31 ||
		cin.fail())
		throw Exception3("Неверный аргумент ", dt1.dd);

	if (dt2.dd < 1 || dt2.dd > 31 ||
		cin.fail())
		throw Exception3("Неверный аргумент ", dt2.dd);

	long int n1 = dt1.yy * 365 + dt1.dd;

	for (int i = 0; i < dt1.mm - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(dt1);

	long int n2 = dt2.yy * 365 + dt2.dd;

	for (int i = 0; i < dt2.mm - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	int diff = n2 - n1;

	return diff;
}

void tryRun(int (*getDiff)(Date&, Date&))
{
	Date dt1, dt2;

	cout << endl << "Дата 1." << endl;
	cout << "Введите год: ";
	cin >> dt1.yy;
	cout << "Введите месяц: ";
	cin >> dt1.mm;
	cout << "Введите день: ";
	cin >> dt1.dd;

	cout << endl << "Дата 2." << endl;
	cout << "Введите год: ";
	cin >> dt2.yy;
	cout << "Введите месяц: ";
	cin >> dt2.mm;
	cout << "Введите день: ";
	cin >> dt2.dd;

	cout << "Между датами прошло " << getDiff(dt1, dt2) << " дней." << endl;
}

int main()
{
	system("chcp 1251");
	system("cls");

	try
	{
		tryRun(getDifference1);
	}
	catch (...)
	{
		cout << "Произошло исключение в функции getDifference1!" << endl;
	}

	try
	{
		tryRun(getDifference2);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		tryRun(getDifference3_1);
	}
	catch (Exception1)
	{
		cout << "Произошло исключение Exception1 в функции getDifference3_1!" << endl;
	}

	try
	{
		tryRun(getDifference3_2);
	}
	catch (Exception2& e)
	{
		cout << e.message() << endl;
	}

	try
	{
		tryRun(getDifference3_3);
	}
	catch (Exception3& e)
	{
		cout << e.what() << " " << e.arg() << endl;
	}

	system("pause");

	return 0;
}
