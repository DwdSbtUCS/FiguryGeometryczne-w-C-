# Figury geometryczne

Aplikacja konsolowa w C++ autorstwa Dawida Soboty, przygotowana w ramach podstaw programowania zorientowanego obiektowo w Akademii WSB.

## Funkcje

- Alfabetyczne menu: koło, kwadrat, prostokąt, trójkąt.
- Pobieranie wymiarów i obliczanie pola oraz obwodu.
- Sprawdzanie dodatnich długości i nierówności trójkąta.
- Obsługa kropki i przecinka przy wpisywaniu długości.
- Wybór kolejnego obliczenia lub zakończenia programu.

## Budowa

Klasa bazowa `FiguraGeometryczna` przechowuje pola `Pole` i `Obwod`. Dziedziczą po niej `Kolo`, `Kwadrat`, `Prostokat` i `Trojkat`. Każda figura udostępnia metody `pobierzDane()`, `WyswietlDane()`, `ObliczObwod()` i `ObliczPole()`. Pole trójkąta obliczane jest wzorem Herona.

## Uruchomienie na Linuxie

Wymagany kompilator C++17, np. G++.

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o figury
./figury
```

## Windows

Kod można umieścić w projekcie konsolowym C++ w Visual Studio. Projekt powinien zawierać tylko jedną funkcję `main()`. Dla wersji 32-bitowej wybierz platformę Win32/x86. W razie potrzeby wyłącz nagłówki prekompilowane.

Testy przeprowadzono na Linuxie. Projekt Visual Studio i plik Windows EXE nie są dołączone; wersja Windows nie została jeszcze przetestowana.

## Przykłady

| Figura | Wymiary | Pole | Obwód |
|---|---|---:|---:|
| Koło | r = 2 | 12,57 | 12,57 |
| Kwadrat | a = 4 | 16,00 | 16,00 |
| Prostokąt | a = 3, b = 4 | 12,00 | 14,00 |
| Trójkąt | a = 3, b = 4, c = 5 | 6,00 | 12,00 |

Długości podawaj w tej samej jednostce. Pole jest wyrażone w jednostkach kwadratowych. Projekt edukacyjny używa typu double; skrajne wartości mogą powodować błędy numeryczne.
