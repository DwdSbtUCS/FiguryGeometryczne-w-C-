// Podstawy programowania zorientowane obiektowo | Dawid Sobota 78618 AWSB

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
#include <sstream>
using namespace std;

// Wspólna funkcja sprawdzająca wprowadzane długości.
double pobierzDlugosc(const char* opis)
{
    string tekst;
    double wartosc;
    while (true)
    {
        cout << opis;
        if (!getline(cin >> ws, tekst))
            throw "Zakonczono wprowadzanie danych.";

        for (char& znak : tekst)
        {
            if (znak == ',') znak = '.';
        }

        istringstream dane(tekst);
        char nadmiar;
        if (dane >> wartosc && !(dane >> nadmiar)
            && isfinite(wartosc) && wartosc > 0)
            return wartosc;

        cout << "Podaj liczbe wieksza od zera.\n";
    }
}

class FiguraGeometryczna
{
protected:
    double Pole = 0;
    double Obwod = 0;
};

class Prostokat : public FiguraGeometryczna
{
    double a = 0, b = 0;
public:
    void pobierzDane()
    {
        a = pobierzDlugosc("Bok a: ");
        b = pobierzDlugosc("Bok b: ");
    }
    double ObliczPole()
    {
        Pole = a * b;
        return Pole;
    }
    double ObliczObwod()
    {
        Obwod = 2 * (a + b);
        return Obwod;
    }
    void WyswietlDane()
    {
        cout << "Prostokat, a = " << a << ", b = " << b << '\n';
        cout << "Pole: " << ObliczPole() << '\n';
        cout << "Obwod: " << ObliczObwod() << '\n';
    }
};

class Kwadrat : public FiguraGeometryczna
{
    double a = 0;
public:
    void pobierzDane()
    {
        a = pobierzDlugosc("Bok a: ");
    }
    double ObliczPole()
    {
        Pole = a * a;
        return Pole;
    }
    double ObliczObwod()
    {
        Obwod = 4 * a;
        return Obwod;
    }
    void WyswietlDane()
    {
        cout << "Kwadrat, a = " << a << '\n';
        cout << "Pole: " << ObliczPole() << '\n';
        cout << "Obwod: " << ObliczObwod() << '\n';
    }
};

class Trojkat : public FiguraGeometryczna
{
    double a = 0, b = 0, c = 0;
public:
    void pobierzDane()
    {
        do
        {
            a = pobierzDlugosc("Bok a: ");
            b = pobierzDlugosc("Bok b: ");
            c = pobierzDlugosc("Bok c: ");
            if (a + b <= c || a + c <= b || b + c <= a)
                cout << "Te boki nie tworza trojkata. Wpisz je ponownie.\n";
        }
        while (a + b <= c || a + c <= b || b + c <= a);
    }
    double ObliczPole()
    {
        double p = (a + b + c) / 2;
        Pole = sqrt(p * (p - a) * (p - b) * (p - c));
        return Pole;
    }
    double ObliczObwod()
    {
        Obwod = a + b + c;
        return Obwod;
    }
    void WyswietlDane()
    {
        cout << "Trojkat, a = " << a << ", b = " << b << ", c = " << c << '\n';
        cout << "Pole: " << ObliczPole() << '\n';
        cout << "Obwod: " << ObliczObwod() << '\n';
    }
};

class Kolo : public FiguraGeometryczna
{
    double r = 0;
    const double PI = 3.141592653589793;
public:
    void pobierzDane()
    {
        r = pobierzDlugosc("Promien r: ");
    }
    double ObliczPole()
    {
        Pole = PI * r * r;
        return Pole;
    }
    double ObliczObwod()
    {
        Obwod = 2 * PI * r;
        return Obwod;
    }
    void WyswietlDane()
    {
        cout << "Kolo, r = " << r << '\n';
        cout << "Pole: " << ObliczPole() << '\n';
        cout << "Obwod: " << ObliczObwod() << '\n';
    }
};

int main()
{
    cout << fixed << setprecision(2);
    cout << "Figury geometryczne - DS78618 / AWSB\n\n";
    cout << "Liczby dziesietne wpisuj z kropka lub przecinkiem.\n";

    try
    {
        while (true)
        {
            cout << "\n1. Kolo\n2. Kwadrat\n3. Prostokat\n4. Trojkat\n0. Wyjscie\nWybor: ";
            int wybor;
            if (!(cin >> wybor))
            {
                if (cin.eof()) break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Podaj numer z menu.\n";
                continue;
            }
            switch (wybor)
            {
                case 1:
                {
                    Kolo figura;
                    figura.pobierzDane();
                    figura.WyswietlDane();
                    cout << "Dziękuje za obserwacje efektów!\n";
                    break;
                }
                case 2:
                {
                    Kwadrat figura;
                    figura.pobierzDane();
                    figura.WyswietlDane();
                    cout << "Dziękuje za obserwacje efektów!\n";
                    break;
                }
                case 3:
                {
                    Prostokat figura;
                    figura.pobierzDane();
                    figura.WyswietlDane();
                    cout << "Dziękuje za obserwacje efektów!\n";
                    break;
                }
                case 4:
                {
                    Trojkat figura;
                    figura.pobierzDane();
                    figura.WyswietlDane();
                    cout << "Dziękuje za obserwacje efektów!\n";
                    break;
                }
                case 0:
                    return 0;
                default:
                    cout << "Nie ma takiej opcji.\n";
                    continue;
            }

            int dalej;
            cout << "\n1. Nowe liczenie\n0. Zamknij program\n";
            while (true)
            {
                cout << "? ";
                if (cin >> dalej && (dalej == 0 || dalej == 1))
                    break;
                if (cin.eof())
                    return 0;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (dalej == 0)
                return 0;
        }
    }
    catch (const char* komunikat)
    {
        cout << '\n' << komunikat << '\n';
    }
    return 0;
}
