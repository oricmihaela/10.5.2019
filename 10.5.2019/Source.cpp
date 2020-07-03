#include<iostream>

using namespace std;

//1. zadatak
template <typename Tip>
int findLargestGrowth(Tip *array, int size)
{
	int maxGrowth = 0;
	int currentGrowth;
	for (int i = 0; i < size; i++)
	{
		currentGrowth = 1;
		for (int j = i + 1; array[j] > array[j - 1]; j++)
		{
			currentGrowth++;
		}
		if (currentGrowth > maxGrowth)
		{
			maxGrowth = currentGrowth;
		}
	}
	return maxGrowth;
}

//2. zadatak
class Battery
{
private:
	double capacityMah, percentageFull;
public:
	Battery() : capacityMah(0), percentageFull(0) {}
	Battery(double capacity) : capacityMah(capacity), percentageFull(0) {}
	Battery(double capacity, double percentage) : capacityMah(capacity), percentageFull(percentage) {}
	friend bool operator>(const Battery&, const Battery&);
	friend ostream& operator<<(ostream&, const Battery&);
};
bool operator>(const Battery& b1, const Battery& b2)
{
	return b1.capacityMah > b2.capacityMah && b1.percentageFull > b2.percentageFull;
}
ostream& operator<<(ostream& izlaz, const Battery& b)
{
	izlaz << b.capacityMah << ", " << b.percentageFull << endl;
	return izlaz;
}

//3. zadatak
class Taximeter
{
protected:
	double pricePerKm;
	double startPrice;
public:
	Taximeter() : pricePerKm(0), startPrice(0) {}
	Taximeter(double price, double start) : pricePerKm(price), startPrice(start)
	{
		if (pricePerKm < 0)
			pricePerKm *= -1;
		if (startPrice < 0)
			pricePerKm *= -1;
	}
	void changePricePerKm(double newPrice)
	{
		pricePerKm = newPrice;
	}
};


int main()
{
	int array[] = { 1, 2, 1, 2, 3, 1 };
	cout << findLargestGrowth(array, 6) << endl;

	Battery batteries[] = { Battery(), Battery(1566), Battery(3456), Battery(1234) };
	if (findLargestGrowth(batteries, 4) == 1)
	{
		cout << batteries[0] << endl;
	}

	system("pause");
}