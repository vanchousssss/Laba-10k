#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

int create_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream)
		return -1;
	int n;
	Money p;
	cout << "���������� ��������: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		stream << p << "\n";
	}
	stream.close();
	return n;
}
int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	Money p;
	int i = 0;
	while (stream >> p)
	{
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}
int delete_file(const char* f_name)
{
	Money k1, k2;
	cout << "������� ���������� ���������, ������� ����� �������(������� �����, ������ �������, ����� - ������): ";
	cin >> k1 >> k2;
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	int i = 0;
	Money p;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		i++;
		if ((p < k1) || (p > k2))
			temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}
int add_file(const char* f_name, int k)

{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	Money p, m;
	int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		i++;
		if (i == 1)
		{
			for (int j = 0; j < k; j++)
			{
				cin >> m;
				temp << m;//�������� � temp ����� ������
				l++;
			}
		}
		temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}
int element_x2(const char* f_name, Money mm)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	Money p;
	int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		i++;
		if (p == mm)
		{
			temp << p + p;//�������� � temp ����� ������
		}
		else temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}
int srav(const char* f_name)
{
	Money m1, m2;
	fstream stream(f_name, ios::app);
	if (!stream)
		return -1;
	cout << "������� 2 �������� ��� ��������� � �����: ";
	cin >> m1 >> m2;
	if (m1 > m2)
		cout << "������ ������� ������\n ";
	if (m1 < m2)
		cout << "������ ������� ������\n ";
	if (m1 == m2)
		cout << "�������� �����\n ";
	m1 = m1 + m2;
	cout << "�� ����� = " << m1;
	stream << m1;
	return 1;

}