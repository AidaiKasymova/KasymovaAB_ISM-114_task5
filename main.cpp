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
	int dd;

	/// <summary>
	/// �����
	/// </summary>
	int mm;

	/// <summary>
	/// ���
	/// </summary>
	int yy;
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
	int years = d.yy;
	if (d.mm <= 2)
		years--;
	return years / 4
		- years / 100
		+ years / 400;
}

/// <summary>
/// ������� ���������� ���� ����� ����� ������
/// (��� ������������ ����������)
/// </summary>
/// <param name="dt1">������ ����</param>
/// <param name="dt2">������ ����</param>
/// <returns>����� ����</returns>
int getDifference1(Date& dt1, Date& dt2)
{
	if (dt1.dd < 1 || dt1.mm < 1 || dt1.yy < 1 ||
		dt1.dd > 31 || dt1.mm > 12 || dt1.yy > 2021 ||
		dt2.dd < 1 || dt2.mm < 1 || dt2.yy < 1 ||
		dt2.dd > 31 || dt2.mm > 12 || dt2.yy > 2021 ||
		cin.fail())
		cerr << "��������� ���������� � ������� getDifference1!" << endl;

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
/// �� ������������� throw(invalid_argument)
/// </summary>
int getDifference2(Date& dt1, Date& dt2) throw(invalid_argument)
{
	if (dt1.yy < 1 || dt1.yy > 2021 || dt2.yy < 1 || dt2.yy > 2021 ||
		cin.fail())
		throw invalid_argument("��� ������ ������ � �������� �� 1 �� 2021!");

	if (dt1.mm < 1 || dt1.mm > 12 || dt2.mm < 1 || dt2.mm > 12 ||
		cin.fail())
		throw invalid_argument("����� ������ ������ � �������� �� 1 �� 12!");

	if (dt1.dd < 1 || dt1.dd > 31 || dt2.dd < 1 || dt2.dd > 31 || 
		cin.fail())
		throw invalid_argument("���� ������ ������ � �������� �� 1 �� 31!");


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

// � ����������� ������������� �����������:

/// <summary>
/// ��� ������ �����
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
/// � ���������� ������������� � ���������� ����������� �����������
/// </summary>
int getDifference3_2(Date& dt1, Date& dt2) throw(Exception2)
{
	if (dt1.yy < 1 || dt1.yy > 2021 || dt2.yy < 1 || dt2.yy > 2021 ||
		cin.fail())
		throw Exception2("��� ������ ������ � �������� �� 1 �� 2021!");

	if (dt1.mm < 1 || dt1.mm > 12 || dt2.mm < 1 || dt2.mm > 12 ||
		cin.fail())
		throw Exception2("����� ������ ������ � �������� �� 1 �� 12!");

	if (dt1.dd < 1 || dt1.dd > 31 || dt2.dd < 1 || dt2.dd > 31 ||
		cin.fail())
		throw Exception2("���� ������ ������ � �������� �� 1 �� 31!");


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
/// ������������ � ����������� ������������� �����������
/// </summary>
int getDifference3_3(Date& dt1, Date& dt2) throw(Exception3)
{
	if (dt1.yy < 1 || dt1.yy > 2021 ||
		cin.fail())
		throw Exception3("�������� �������� ", dt1.yy);

	if (dt2.yy < 1 || dt2.yy > 2021 ||
		cin.fail())
		throw Exception3("�������� �������� ", dt2.yy);

	if (dt1.mm < 1 || dt1.mm > 12 ||
		cin.fail())
		throw Exception3("�������� �������� ", dt1.mm);

	if (dt2.mm < 1 || dt2.mm > 12 ||
		cin.fail())
		throw Exception3("�������� �������� ", dt2.mm);

	if (dt1.dd < 1 || dt1.dd > 31 ||
		cin.fail())
		throw Exception3("�������� �������� ", dt1.dd);

	if (dt2.dd < 1 || dt2.dd > 31 ||
		cin.fail())
		throw Exception3("�������� �������� ", dt2.dd);

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

	cout << endl << "���� 1." << endl;
	cout << "������� ���: ";
	cin >> dt1.yy;
	cout << "������� �����: ";
	cin >> dt1.mm;
	cout << "������� ����: ";
	cin >> dt1.dd;

	cout << endl << "���� 2." << endl;
	cout << "������� ���: ";
	cin >> dt2.yy;
	cout << "������� �����: ";
	cin >> dt2.mm;
	cout << "������� ����: ";
	cin >> dt2.dd;

	cout << "����� ������ ������ " << getDiff(dt1, dt2) << " ����." << endl;
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
