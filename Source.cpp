#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;


class Calendar
{
	string month, year;
public:
	Calendar(){}

	int converter(string &m)
	{
		int result = 0;
		if (m == "January" || m == "january")
			result = 1;
		if (m == "February" || m == "february")
			result = 3;
		if (m == "March" || m == "march")
			result = 5;
		if (m == "April" || m == "april")
			result = 7;
		if (m == "May" || m == "may")
			result = 9;
		if (m == "June" || m == "june")
			result = 11;
		if (m == "July" || m == "july")
			result = 13;
		if (m == "August" || m == "august")
			result = 15;
		if (m == "September" || m == "september")
			result = 17;
		if (m == "October" || m == "october")
			result = 19;
		if (m == "November" || m == "november")
			result = 21;
		if (m == "December" || m == "december")
			result = 23;
		return result;
	}

	void prod_calendar()
	{
		cout << "Please, input month: ";
		getline(cin, month);
		cout << "Please, input year: ";
		getline(cin, year);

		int number_of_month = 0;

		number_of_month = converter(month);

		system("cls");
		cout << month << ", " << year << endl;

		string path = "mybase.txt";
		ifstream fin, gin;
		fin.open(path);
		gin.open(path);

		char y_ear[4];

		int counter = 0;
		int current_counter = 0;
		int ending = 0;

		string str;
		string bufer_year;
		char fymbol = ' ';
		char quotes = '"';

		string monther = "";

		if (!fin.is_open() || !gin.is_open())
			cout << "\nFile not found!";
		else
		{
			while (!fin.eof() && ending != 1)
			{
				bufer_year = "";
				getline(fin, str);
				for (int i = 0; i < 4; i++)
				{
					bufer_year += str[i];
					y_ear[i] = bufer_year[i];
				}

				if (bufer_year == year)
				{
					ending = 1;
					do{
						gin >> fymbol;
						if (fymbol == quotes)
							counter++;
						
					} while (counter != number_of_month);

					counter = 0;
					gin >> fymbol;

					while (fymbol != quotes)
					{
						if (fymbol != '*' || fymbol != '+')
						{ 
							monther += fymbol;
							current_counter++;
							gin >> fymbol;
						}
						else if(fymbol == '*' || fymbol == '+')
							gin >> fymbol;
					}
				}
			}
		}
		fin.close();
		gin.close();

		//cout << bufer_year << "  " << monther << "    = " << current_counter << endl << endl;


		int iter = 0;
		char *buffer_monther = new char[current_counter];
		for (int i = 0; i < current_counter; i++)
		{
			buffer_monther[i] = monther[i];
			if (buffer_monther[i] == ',')
				iter++;
		}

		int* arr = new int[current_counter - iter];
		int newcounter = 0;

		for (int i = 0; i < current_counter; i++)
		{
			if (buffer_monther[i] != ',' && buffer_monther[i+1] == ',')
			{
				arr[newcounter] = monther[i] - 48;
				newcounter++;
			}
			if (buffer_monther[i] != ',' && buffer_monther[i + 1] != ',' && i+1 != current_counter)
			{
				arr[newcounter] = monther[i] - 48;
				arr[newcounter] *= 10;
				arr[newcounter] += monther[i + 1] - 48;
				i++;
				newcounter++;
			}
		}
		/*for (int i = 0; i < newcounter; i++)
		{
			cout << arr[i] << " ";
		}*/

		int y_e_a_r[4];
		int number = 0;
		int lol = 1000;
		for (int i = 0; i < 4; i++)
		{
			y_e_a_r[i] = y_ear[i] - 48;
			//cout << "\n" << y_e_a_r[i];
			number += (y_e_a_r[i]*lol);
			lol /= 10;
		}
		if (number_of_month == 3)
			number_of_month = 2;
		if (number_of_month == 5)
			number_of_month = 3;
		if (number_of_month == 7)
			number_of_month = 4;
		if (number_of_month == 9)
			number_of_month = 5;
		if (number_of_month == 11)
			number_of_month = 6;
		if (number_of_month == 13)
			number_of_month = 7;
		if (number_of_month == 15)
			number_of_month = 8;
		if (number_of_month == 17)
			number_of_month = 9;
		if (number_of_month == 19)
			number_of_month = 10;
		if (number_of_month == 21)
			number_of_month = 11;
		if (number_of_month == 23)
			number_of_month = 12;
		//cout << "\n\n" << number_of_month << endl;
		production_calendar(number, number_of_month, arr, newcounter);
	}

	void production_calendar(int number, int number_of_month, int* arr, int siz)
	{
		struct Day
		{
			int day;
			char holiday = ' ';
		};

		Day Object;

		int current_day = 4;
		int limit = 0;
		int param = 31;

		cout << endl;


		for (int y = number; y <= number; y++)
		{
			for (int moy = 1; moy <= 12; moy++)
			{
				if (moy == 1 || moy == 3 || moy == 5 || moy == 7 || moy == 8 || moy == 10 || moy == 12)
					param = 31;
				if (moy == 4 || moy == 6 || moy == 9 || moy == 11)
					param = 30;
				if (moy == 2 && (y % 4) == 0)
					param = 29;
				if (moy == 2 && (y % 4) != 0)
					param = 28;

				limit = 0;

				for (int d = 1; d <= param; d++)
				{
					limit++;
					current_day++;
					if (current_day == 8)
					{
						current_day = 1;
					}

					Object.day = d; 
					if (moy == number_of_month)
					{
						if (current_day == 1)
						{
							cout << "mn-" << Object.day;
							for (int p = 0; p < siz; p++)
							{
								if(Object.day == arr[p])
									cout << "-h";
							}
							cout << ",  ";
						}
						if (current_day == 2)
						{
							cout << "tu-" << Object.day;
							for (int p = 0; p < siz; p++)
							{
								if (Object.day == arr[p])
									cout << "-h";
							}
							cout << ",  ";
						}
						if (current_day == 3)
						{
							cout << "wn-" << Object.day;
							for (int p = 0; p < siz; p++)
							{
								if (Object.day == arr[p])
									cout << "-h";
							}
							cout << ",  ";
						}
						if (current_day == 4)
						{
							cout << "th-" << Object.day;
							for (int p = 0; p < siz; p++)
							{
								if (Object.day == arr[p])
									cout << "-h";
							}
							cout << ",  ";
						}
						if (current_day == 5)
						{
							cout << "fr-" << Object.day;
							for (int p = 0; p < siz; p++)
							{
								if (Object.day == arr[p])
									cout << "-h";
							}
							cout << ",  ";
						}
						if (current_day == 6)
						{
							cout << "st-" << Object.day;
							for (int p = 0; p < siz; p++)
							{
								if (Object.day == arr[p])
									cout << "-h";
							}
							cout << ",  ";
						}
						if (current_day == 7)
						{
							cout << "sn-" << Object.day;
							for (int p = 0; p < siz; p++)
							{
								if (Object.day == arr[p])
									cout << "-h";
							}
							cout << ",  \n";
						}
					}
				}
				if (moy == number_of_month)
					cout << endl << endl;
			}
		}
	}
};


int main()
{
	Calendar Object;

	Object.prod_calendar();
	
	_getch();
}
