#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <clocale>
#include <Windows.h>
#include <ctype.h>
#include <math.h>
using namespace std;
struct Date
{
	int day;
	int mon;
	int year;

};
struct Tstart
{
	int hour;
	int minut;
	int sec;

};
struct Tend
{
	int hourend;
	int minutend;
	int secend;

};
struct BSIP
{
	char login[20];
	Date date;
	Tstart tstart;
	Tend tend;
	int prin;
	int otpr;
};
int main()
{
	system("mode con cols=150 lines=150");
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int ct;
	cout << "Введите количество пользователей: ";
	cin >> ct;
	BSIP *BSIPS = new BSIP[ct];
	int i, countt = 1;
	for (i = 0; i<ct; i++)
	{
		cout<< countt << ") Пользователь" << endl;
		cout<< "Логин пользователя: ";
		cin >>BSIPS[i].login;
		cout<< "Дата выхода в онлайн: " << endl;
		cin >>BSIPS[i].date.day;
		cin >>BSIPS[i].date.mon;
		cin >>BSIPS[i].date.year;
		cout<< "Время начала сеанса онлайн: " << endl;
		cin >>BSIPS[i].tstart.hour;
		cin >>BSIPS[i].tstart.minut;
		cin >>BSIPS[i].tstart.sec;
		cout<< "Время завершения: " << endl;
		cin >>BSIPS[i].tend.hourend;
		cin >>BSIPS[i].tend.minutend;
		cin >>BSIPS[i].tend.secend;
		cout<< "Объем принятой информации: ";
		cin >>BSIPS[i].prin; //cout « "(Kb)";
		cout<< "Объем отправленной информации: ";
		cin >>BSIPS[i].otpr; //cout « "(Kb)";
		countt++;
	}
	int h, m, s;
	for (i = 0; i<ct; i++)
	{
		if (BSIPS[i].tstart.hour > BSIPS[i].tend.hourend)
			h = (24 - BSIPS[i].tstart.hour) + BSIPS[i].tend.hourend;
		else if (BSIPS[i].tstart.hour < BSIPS[i].tend.hourend)
			h = BSIPS[i].tend.hourend - BSIPS[i].tstart.hour;
		m = (60 - BSIPS[i].tstart.minut) + BSIPS[i].tend.minutend;
		if (m > 60)
		{
			m = m - 60;
			h = h + 1;
		}
		s = (60 - BSIPS[i].tstart.sec) + BSIPS[i].tend.secend;
		if (s > 60)
		{
			s = s - 60;
			m = m + 1;
		}
		int traf;
		traf = (BSIPS[i].prin + BSIPS[i].otpr) / 1000;
		cout << "Пользователь: " << BSIPS[i].login << " был онлайн в течении " << h << ":" << m << ":" << s << endl;
		cout << "И потребил трафика " << traf << " Mb" << endl;
	}
	countt = 1;
	int di1, di2, mi1, mi2, yi1, yi2;
	cout <<"Введите начало интервала даты: \n";
	cin>> di1;
	cin>> mi1;
	cin>> yi1;
	cout << "Введите конец интервала даты: \n";
	cin >> di2;
	cin >> mi2;
	cin >> yi2;
	int kd1, kd2, *kdi = new int[ct];
	kd1 = (yi1 * 365) + (mi1 * 30) + di1;
	kd2 = (yi2 * 365) + (mi2 * 30) + di2;
	for (i = 0; i<ct; i++)
	{
		kdi[i] = (BSIPS[i].date.year * 365) + (BSIPS[i].date.mon * 30) + BSIPS[i].date.day;
	}
	for (i = 0; i<ct; i++)
	{
		if (kdi[i] > kd1 && kdi[i] < kd2)
		{
			if (((BSIPS[i].prin + BSIPS[i].otpr) / 1000) > 20)
			{
				cout << "Пользователь: " << BSIPS[i].login  << " потребил больше 20 Mb, в период с " <<
					di1 << "." << mi1 << "." << yi1 << " по " << di2 << "." << mi2 << "." << yi2 << endl;
			}
		}
	}
	return 0;
}