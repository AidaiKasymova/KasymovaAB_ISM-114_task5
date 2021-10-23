#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

/// <summary>
/// ����� ��� �������� ����������
/// </summary>
class Exception1 {};

/// <summary>
/// ����� ��� �������� ����������
/// � ������� ��������� �� ������
/// </summary>
class Exception2
{
	string msg;
public:
	Exception2(const string& s) : msg(s) {}
	const char* message() const { return msg.c_str(); }
};

/// <summary>
/// �����-��������� � ��������� ���������� 
/// (��� �������� ��������� ���������)
/// </summary>
class Exception3 : public invalid_argument
{
	bool num;
public:
	Exception3(const string msg, bool n) : invalid_argument(msg), num(n) {}
	bool arg() const { return num; }
};

/// <summary>
/// ��������� � ��������� ����
/// </summary>
struct Date
{
	/// <summary>
	/// ����
	/// </summary>
	int day;

	/// <summary>
	/// �����
	/// </summary>
	int month;

	/// <summary>
	/// ���
	/// </summary>
	int year;
};

// ����� ���� � ������ �� �������
const int monthDays[12]
= { 31, 28, 31, 30, 31, 30,
   31, 31, 30, 31, 30, 31 };

/// <summary>
/// ������� ����� ���������� ��� � �������� ����
/// </summary>
int countLeapYears(const Date& d)
{
	int years = d.year;
	if (d.month <= 2)
		years--;
	return years / 4
		- years / 100
		+ years / 400;
}

/// <summary>
/// ������� ���������� ���� ����� ����� ������
/// (��� ������������ ����������)
/// </summary>
/// <param name="date1">������ ����</param>
/// <param name="date2">������ ����</param>
/// <returns>����� ����</returns>
int getDifference1(Date& date1, Date& date2)
{
	if (date1.day < 1 || date1.month < 1 || date1.year < 1 ||
		date1.day > 31 || date1.month > 12 || date1.year > 2021 ||
		date2.day < 1 || date2.month < 1 || date2.year < 1 ||
		date2.day > 31 || date2.month > 12 || date2.year > 2021)

		throw "��������� ���������� � ������� getDifference1!";
	
	long int n1 = date1.year * 365 + date1.day;

	for (int i = 0; i < date1.month - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(date1);

	long int n2 = date2.year * 365 + date2.day;
	
	for (int i = 0; i < date2.month - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(date2);

	int diff = n2 - n1;

	return diff;
}

/// <summary>
/// �� ������������� throw(invalid_argument)
/// </summary>
int getDifference2(Date& date1, Date& date2) throw(invalid_argument)
{
	if (date1.year < 1 || date1.year > 2021 || date2.year < 1 || date2.year > 2021)
		throw invalid_argument("��� ������ ������ � �������� �� 1 �� 2021!");

	if (date1.month < 1 || date1.month > 12 || date2.month < 1 || date2.month > 12)
		throw invalid_argument("����� ������ ������ � �������� �� 1 �� 12!");

	if (date1.day < 1 || date1.day > 31 || date2.day < 1 || date2.day > 31)
		throw invalid_argument("���� ������ ������ � �������� �� 1 �� 31!");


	long int n1 = date1.year * 365 + date1.day;

	for (int i = 0; i < date1.month - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(date1);

	long int n2 = date2.year * 365 + date2.day;

	for (int i = 0; i < date2.month - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(date2);

	int diff = n2 - n1;

	return diff;
}

// � ����������� ������������� �����������:

/// <summary>
/// ��� ������ �����
/// </summary>
int getDifference3_1(Date& date1, Date& date2) throw(Exception1)
{
	if (date1.year < 1 || date1.year > 2021 || date2.year < 1 || date2.year > 2021)
		throw Exception1();

	if (date1.month < 1 || date1.month > 12 || date2.month < 1 || date2.month > 12)
		throw Exception1();

	if (date1.day < 1 || date1.day > 31 || date2.day < 1 || date2.day > 31)
		throw Exception1();

	long int n1 = date1.year * 365 + date1.day;

	for (int i = 0; i < date1.month - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(date1);

	long int n2 = date2.year * 365 + date2.day;

	for (int i = 0; i < date2.month - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(date2);

	int diff = n2 - n1;

	return diff;
}

/// <summary>
/// � ���������� ������������� � ���������� ����������� �����������
/// </summary>
int getDifference3_2(Date& date1, Date& date2) throw(Exception2)
{
	if (date1.year < 1 || date1.year > 2021 || date2.year < 1 || date2.year > 2021)
		throw Exception2("��� ������ ������ � �������� �� 1 �� 2021!");

	if (date1.month < 1 || date1.month > 12 || date2.month < 1 || date2.month > 12)
		throw Exception2("����� ������ ������ � �������� �� 1 �� 12!");

	if (date1.day < 1 || date1.day > 31 || date2.day < 1 || date2.day > 31)
		throw Exception2("���� ������ ������ � �������� �� 1 �� 31!");


	long int n1 = date1.year * 365 + date1.day;

	for (int i = 0; i < date1.month - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(date1);

	long int n2 = date2.year * 365 + date2.day;

	for (int i = 0; i < date2.month - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(date2);

	int diff = n2 - n1;

	return diff;
}

/// <summary>
/// ������������ � ����������� ������������� �����������
/// </summary>
int getDifference3_3(Date& date1, Date& date2) throw(Exception3)
{
	if (date1.year < 1 || date1.year > 2021)
		throw Exception3("�������� �������� ", date1.year);

	if (date2.year < 1 || date2.year > 2021)
		throw Exception3("�������� �������� ", date2.year);

	if (date1.month < 1 || date1.month > 12)
		throw Exception3("�������� �������� ", date1.month);

	if (date2.month < 1 || date2.month > 12)
		throw Exception3("�������� �������� ", date2.month);

	if (date1.day < 1 || date1.day > 31)
		throw Exception3("�������� �������� ", date1.day);

	if (date2.day < 1 || date2.day > 31)
		throw Exception3("�������� �������� ", date2.day);

	long int n1 = date1.year * 365 + date1.day;

	for (int i = 0; i < date1.month - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(date1);

	long int n2 = date2.year * 365 + date2.day;

	for (int i = 0; i < date2.month - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(date2);

	int diff = n2 - n1;

	return diff;
}

void tryRun(int (*getDiff)(Date&, Date&))
{
	Date date1, date2;

	cout << endl << "���� 1." << endl;
	cout << "������� ���: ";
	cin >> date1.year;
	cout << "������� �����: ";
	cin >> date1.month;
	cout << "������� ����: ";
	cin >> date1.day;

	cout << endl << "���� 2." << endl;
	cout << "������� ���: ";
	cin >> date2.year;
	cout << "������� �����: ";
	cin >> date2.month;
	cout << "������� ����: ";
	cin >> date2.day;

	cout << "����� ������ ������ " << getDiff(date1, date2) << " ����." << endl;
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
		cout << "��������� ���������� � ������� getDifference1!" << endl;
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
		cout << "��������� ���������� Exception1 � ������� getDifference3_1!" << endl;
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
