#include "stdafx.h"
#include <iostream>
#include <fstream>
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
istream& operator>>(istream& is, BSIP& s)
{
	is >> s.login >> s.date.day >> s.date.mon >> s.date.year >>
		s.tstart.hour >> s.tstart.minut >> s.tstart.sec >> s.tend.hourend >>
		s.tend.minutend >> s.tend.secend >> s.prin >> s.otpr;
	return is;
}

int main()
{
	system("mode con cols=150 lines=150");
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int ct;
	cout << "Введите количество пользователей: ";
	cin >> ct;
	BSIP *bsip = new BSIP[ct];
	int i, countt = 1;
	for (i = 0; i<ct; i++)
	{
		cout << countt << ") Пользователь" << endl;
		cout <<"Логин пользователя: ";
		cin >> bsip[i].login;
		cout << "Дата выхода в онлайн: " << endl;
		cin >> bsip[i].date.day;
		cin >> bsip[i].date.mon;
		cin >> bsip[i].date.year;
		cout << "Время начала сеанса онлайн: " << endl;
		cin >> bsip[i].tstart.hour;
		cin >> bsip[i].tstart.minut;
		cin >> bsip[i].tstart.sec;
		cout << "Время завершения: " << endl;
		cin >> bsip[i].tend.hourend;
		cin >> bsip[i].tend.minutend;
		cin >> bsip[i].tend.secend;
		cout << "Объем принятой информации: ";
		cin >> bsip[i].prin; //cout << "(Kb)";
		cout << "Объем отправленной информации: ";
		cin >> bsip[i].otpr; //cout << "(Kb)";
		countt++;
	}
	ofstream Q("Laba9V.txt");
	int countt1 = 1;
	for (i = 0; i<ct; i++)
	{
		Q << countt1 << ") пользователь" << endl << "Логин: " << bsip[i].login << endl << "Дата выхода в онлайн: " <<
			bsip[i].date.day << "." << bsip[i].date.mon << "." << bsip[i].date.year << endl << "Время начала сеанса онлайн: " <<
			bsip[i].tstart.hour << ":" << bsip[i].tstart.minut << ":" << bsip[i].tstart.sec << endl << "Время завершения: " <<
			bsip[i].tend.hourend << ":" << bsip[i].tend.minutend << ":" << bsip[i].tend.secend << endl << "Объем принятой информации: " <<
			bsip[i].prin << " (Kb) " << endl << "Объем отправленной информации: " << bsip[i].otpr << " (Kb) " << endl;
		countt1++;
	}
	Q.close();
	ofstream A("Laba9VD.txt");
	for (i = 0; i<ct; i++)
	{
		A << bsip[i].login << endl << bsip[i].date.day << endl << bsip[i].date.mon << endl << bsip[i].date.year << endl <<
			bsip[i].tstart.hour << endl << bsip[i].tstart.minut << endl << bsip[i].tstart.sec << endl <<
			bsip[i].tend.hourend << endl << bsip[i].tend.minutend << endl << bsip[i].tend.secend << endl <<
			bsip[i].prin << endl << bsip[i].otpr << endl;;
	}
	BSIP *bsip2 = new BSIP[ct];
	ifstream Z("Laba9VD.txt");
	for (i = 0; i<ct; i++)
	{
		Z >> bsip2[i];
	}
	Z.close();
	system("CLS");
	int countt2 = 1;
	for (i = 0; i<ct; i++)
	{
		cout << countt2 << ") Пользователь" << endl;
		cout << "Логин пользователя: " << bsip2[i].login << endl;
		cout << "Дата выхода в онлайн: " << bsip2[i].date.day << "." << bsip2[i].date.mon << "." << bsip2[i].date.year << endl;
		cout << "Время начала сеанса онлайн: " << bsip2[i].tstart.hour << ":" << bsip2[i].tstart.minut << ":" << bsip2[i].tstart.sec << endl;
		cout << "Время завершения: " << bsip2[i].tend.hourend << ":" << bsip2[i].tend.minutend << ":" << bsip2[i].tend.secend << endl;
		cout << "Объем принятой информации: " << bsip2[i].prin << " (Kb) " << endl;
		cout << "Объем отправленной информации: " << bsip2[i].otpr << " (Kb) " << endl;
		countt2++;
	}
	int numo;
	cout << "Введите номер месяца, чтобы подсчитать для него колличество сеансов выхода on-line в прошлом году...";
	cin >> numo;
	int countt3 = 0;

		for (i = 0; i<ct; i++)
		{
			if (bsip2[i].date.mon == numo && bsip2[i].date.year == 2017)
				countt3++;
		}
	cout << "За прошлый год, в указаном Вами месяце (" << numo << "), " << "было " << countt3 << " сеансов выхода on-line." << endl;
	int nud, num, nuy, maxh, maxm, maxs, *h=new int [ct], *m=new int[ct], *s=new int[ct], v;
	cout << "Введите дату, чтобы найти для неё максимальную длительность сеанса on-line" << endl;
	cin >> nud;
	cin >> num;
	cin >> nuy;
	for (i = 0; i<ct; i++)
	{
		if (bsip2[i].tstart.hour > bsip2[i].tend.hourend)
			h[i] = (24 - bsip2[i].tstart.hour) + bsip2[i].tend.hourend;
		else if (bsip2[i].tstart.hour < bsip2[i].tend.hourend)
			h[i] = bsip2[i].tend.hourend - bsip2[i].tstart.hour;
		m[i] = (60 - bsip2[i].tstart.minut) + bsip2[i].tend.minutend;
		if (m[i] > 60)
		{
			m[i] = m[i] - 60;
			h[i] = h[i] + 1;
		}
		s[i] = (60 - bsip2[i].tstart.sec) + bsip2[i].tend.secend;
		if (s[i] > 60)
		{
			s[i] = s[i] - 60;
			m[i] = m[i] + 1;
		}
	}
	for (i = 0; i<ct; i++)
	{
		maxh = h[0];
		maxm = m[0];
		maxs = s[0];
		if (bsip2[i].date.day == nud && bsip2[i].date.mon == num && bsip2[i].date.year == nuy)
		{
			if (h[i] > maxh && m[i] > maxm && s[i] > maxs)
			{
				maxh = h[i];
				maxm = m[i];
				maxs = s[i];
				v = i;
			}
		}
	}
	cout << nud << "." << num << "." << nuy << " максимальная длительность сеанса on-line была у пользователя " << bsip2[v].login
		<< " и равна " << maxh << ":" << maxm << ":" << maxs << " (ЧЧ:ММ:СС)" << endl;
	ofstream R("Колличество сеансов выхода в on-line за прошлый год.txt");
	R << "За прошлый год, в указаном Вами месяце (" << numo << "), " << "было " << countt3 << " сеансов выхода on-line.";
	R.close();
	ofstream R2("Максимальная длительность сеанса on-line для введенной Вами датой.txt");
	R2 << nud << "." << num << "." << nuy << " максимальная длительность сеанса on-line была у пользователя " << bsip2[v].login
		<< " и равна " << maxh << ":" << maxm << ":" << maxs << " (ЧЧ:ММ:СС)";
	R2.close();
	return 0;
}