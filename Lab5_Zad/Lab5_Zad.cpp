#include <iostream>
#include <iomanip>
#include <algorithm>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <array>

using std::cin;
using std::wcout;
using std::cerr;
using std::endl;
using std::exception;
using std::max_element;
using std::setw;
using std::vector;
using std::array;

const char* IntCastExceptionMessage = "Podana wartosc nie mogla zostac zrzutowana do typu int.";

auto Zadanie1() -> void
{
	wcout << "[Zadanie 1]" << endl;

	int N;
	wcout << "Podaj rozmiar wektora: "; cin >> N;

	if (cin.fail()) { throw exception{ IntCastExceptionMessage }; }

	if (N <= 0)
	{
		throw exception{ "Rozmiar wektora musi byc wiekszy od 0" };
	}

	vector<int> Wektor(N, 0);

	for (int i = 0; i < N; ++i)
	{
		wcout << L"Podaj wartość dla wektora [" << i << "]: "; cin >> Wektor[i];
		if (cin.fail()) { throw exception{ IntCastExceptionMessage }; }
	}

	int max = 0;
	int index = 0;
	int i = 0;
	for (auto const& element : Wektor)
	{
		if (element > max)
		{
			max = element;
			index = i;
		}

		i++;
	}

	wcout << L"Największy element wektora to: " << max << " o indeksie równym " << index << endl << endl;
}

auto Zadanie2() -> void
{
	wcout << "[Zadanie 2]" << endl;

	int N;
	wcout << L"Podaj rozmiar tablicy: "; cin >> N;

	if (cin.fail()) { throw exception{ IntCastExceptionMessage }; }

	if (N <= 0 || N % 2 == 1)
	{
		throw exception{ "Rozmiar tablicy musi byc wiekszy od 0 i podzielny przez 2" };
	}

	int* Tablica = new int[N];

	for (int i = 0; i < N; ++i)
	{
		wcout << L"Podaj wartość dla Tablica[" << i << "]: "; cin >> Tablica[i];
		if (cin.fail()) { throw exception{ IntCastExceptionMessage }; }
	}

	int HalfN = N / 2;
	for (int i = 0; i < HalfN; ++i)
	{
		int Tmp = Tablica[i];
		Tablica[i] = Tablica[i + HalfN];
		Tablica[i + HalfN] = Tmp;
	}

	for (int i = 0; i < N; ++i)
	{
		wcout << setw(5) << Tablica[i];
	}

	if (Tablica != nullptr)
	{
		delete[] Tablica;
		Tablica = nullptr;
	}
}

auto main() -> int
{
	/* Obsługa wyjątków */
	try
	{
		if (_setmode(_fileno(stdout), _O_U8TEXT) == -1)
		{
			throw exception{ "Nie mozna ustawic kodowania UTF-8" };
		}

		Zadanie1();
		Zadanie2();
	}
	catch (exception ex)
	{
		cerr << "Wyjatek: " << ex.what() << endl;

		return 1; /* Zwracamy błąd */
	}

	return 0;
}