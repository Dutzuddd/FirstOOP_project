#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

class Agency {
	int offerNumber;
	double price;
	string location;
	string country;
	int numberOfDays;

public:
	Agency(){}

	Agency(int offerNumber, double price, string location, string country, int numberOfDays)
	{
		Agency::offerNumber = offerNumber;
		Agency::price = price;
		Agency::location = location;
		Agency::country = country;
		Agency::numberOfDays = numberOfDays;
	}
	

	void showOfffer()
	{
		cout << "****************************************"<<endl;
		cout << "Offer number: " << Agency::offerNumber << endl;
		cout << "Location: " << Agency::location << endl;
		cout << "Country: " << Agency::country << endl;
		cout << "Number of Days: " << Agency::numberOfDays << endl;
		cout << "Price: " << Agency::price << " Euros" << endl;

	}

	double getPrice()
	{
		return Agency::price;
	}
	};

class SummerHoliday : public Agency {
	double temperature;
	string beachType;

public:
	SummerHoliday(){}

	SummerHoliday(int offerNumber, double price, string location, string country, int numberOfDays,
		double temperature, string beachType) : Agency(offerNumber, price, location, country, numberOfDays)
	{
		SummerHoliday::temperature = temperature;
		SummerHoliday::beachType = beachType;
	}

	void showOfffer() {
		Agency::showOfffer();
		cout << "Medium Temperature: " << SummerHoliday::temperature << endl;
		cout << "Beach type: " << SummerHoliday::beachType << endl;
	}
};

class WinterHoliday : public Agency {
	int altitude;
	double kmOfSkiSlopes;

public:
	WinterHoliday(){}

	WinterHoliday(int offerNumber, double price, string location, string country,
		int numberOfDays, int altitude, double kmOfSkiSlopes) : Agency(offerNumber, price, location, country, numberOfDays)
	{
		WinterHoliday::altitude = altitude;
		WinterHoliday::kmOfSkiSlopes = kmOfSkiSlopes;
	}

	void showOfffer() {
		Agency::showOfffer();
		cout << "Location Altitude: " << WinterHoliday::altitude << endl;
		cout << "Ski slopes have in total: " << WinterHoliday::kmOfSkiSlopes << " km" << endl;
	}
};

int main() {
	int offerNr, numberOfDays, altitude, ok1 = 0, ok2 = 0;
	string location, country, beachType;
	double price, temperature, kmOfSkiSlopes, priceToSearch;

	SummerHoliday summer[10];
	WinterHoliday winter[10];
	unsigned int option, nr1, nr2;

	do {
		cout << "1. Insert Summer Holiday vacations." << endl;
		cout << "2. Insert Winter Holiday vacations." << endl;
		cout << "3. Display available offers." << endl;
		cout << "4. Search by price." << endl;
		cout << "0. Exit" << endl;
		cout << "\nChose option(Options 3&4 work only if there are offers inserted first): ";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "How many Summer Holiday vacations do you want to insert?";
			cin >> nr1;
			for (int i = 0; i < nr1; i++)
			{
				cout << "Offer number ?";
				cin >> offerNr;
				cout << "Price?";
				cin >> price;
				cout << "Location?";
				cin >> location;
				cout << "Country?";
				cin >> country;
				cout << "Number of days:";
				cin >> numberOfDays;
				cout << "Temperature?";
				cin >> temperature;
				cout << "Beach type?";
				cin >> beachType;

				summer[i] = SummerHoliday(offerNr, price, location, country, numberOfDays, temperature, beachType);
			}
			break;
		case 2:
			cout << "How many Winter Holiday Vacations do you want to insert?";
			cin >> nr2;
			for (int j = 0; j < nr2; j++)
			{
				cout << "Offer number ?";
				cin >> offerNr;
				cout << "Price?";
				cin >> price;
				cout << "Location?";
				cin >> location;
				cout << "Country?";
				cin >> country;
				cout << "Number of days:";
				cin >> numberOfDays;
				cout << "Altitude?";
				cin >> altitude;
				cout << "Km of Slopes?";
				cin >> kmOfSkiSlopes;

				winter[j] = WinterHoliday(offerNr, price, location, country, numberOfDays, altitude, kmOfSkiSlopes);
			}
			break;
		case 3:
			cout << "---------------------Available Offers---------------------\n";
			cout << "\n";
			cout << "---------------------Summer Vacations---------------------\n";
			for (int i = 0; i < nr1; i++)
			{
				summer[i].showOfffer();
			}
			cout << "\n";
			cout << "---------------------Winter Vacations---------------------\n";
			for (int j = 0; j < nr2; j++)
			{
				winter[j].showOfffer();
			}
			break;
		case 4:
			cout << "Enter the price: ";
			cin >> priceToSearch;
			for (int i = 0; i < nr1; i++)
				if (priceToSearch >= summer[i].getPrice())
				{
					cout << "Found offers: \n";
					summer[i].showOfffer();
					ok1 = 1;
					cout << endl;
				}
				else
					if (ok1 == 0)
						cout << "No offers found!\n";
			for (int j = 0; j < nr2; j++)
				if (priceToSearch >= winter[j].getPrice())
				{
					cout << "Found offers: \n";
					winter[j].showOfffer();
					ok2 = 1;
					cout << endl;
				}
				else
					if (ok2 == 0)
						cout << "No offers found!\n";
			break;
		case 0:
			break;
	
		default:
			cout << "Wrong option!\n";
			break;
		}

	} while (option != 0);
	system("pause");
	return 0;
}
