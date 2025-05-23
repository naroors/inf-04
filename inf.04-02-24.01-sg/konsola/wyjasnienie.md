# Wyjaśnienie pliku `main.cpp`

Plik `main.cpp` definiuje klasę o nazwie `LancuchNarzedzia`, która zawiera narzędzia do manipulacji łańcuchami znaków (stringami).

## Klasa `LancuchNarzedzia`

Klasa ta posiada dwie publiczne, statyczne metody:

### 1. `static int policzSamogloski(string tekst)`

*   **Cel:** Zlicza liczbę samogłosek w podanym łańcuchu znaków.
*   **Argumenty:**
    *   `tekst` (string): Łańcuch znaków, w którym mają być policzone samogłoski.
*   **Zwraca:**
    *   `int`: Liczba znalezionych samogłosek.
*   **Logika działania:**
    1.  Inicjalizuje licznik samogłosek (`licznikSamoglosek`) na 0.
    2.  Definiuje łańcuch `znaki` zawierający wszystkie polskie samogłoski (małe i wielkie litery: "aąeęiouóyAĄEĘIOUÓY").
    3.  Iteruje przez każdy znak w podanym `tekst`.
    4.  Dla każdego znaku z `tekst`, iteruje przez wszystkie znaki w łańcuchu `znaki`.
    5.  Jeśli znak z `tekst` jest taki sam jak znak z `znaki`, inkrementuje `licznikSamoglosek`.
    6.  Po sprawdzeniu wszystkich znaków, zwraca `licznikSamoglosek`.

### 2. `static string usunPowtorzenia(string tekstWejsciowy)`

*   **Cel:** Usuwa kolejne, powtarzające się znaki z podanego łańcucha znaków. Na przykład, "AAABBC" stanie się "ABC".
*   **Argumenty:**
    *   `tekstWejsciowy` (string): Łańcuch znaków, z którego mają być usunięte powtórzenia.
*   **Zwraca:**
    *   `string`: Nowy łańcuch znaków bez kolejnych powtórzeń.
*   **Logika działania:**
    1.  Sprawdza, czy `tekstWejsciowy` jest pusty. Jeśli tak, zwraca pusty łańcuch.
    2.  Inicjalizuje pusty łańcuch `wynik`.
    3.  Dodaje pierwszy znak z `tekstWejsciowy` do `wynik` (ponieważ pierwszy znak nie ma poprzednika do porównania).
    4.  Iteruje przez `tekstWejsciowy` zaczynając od drugiego znaku (indeks 1).
    5.  Dla każdego znaku, porównuje go z poprzednim znakiem w `tekstWejsciowy`.
    6.  Jeśli bieżący znak jest różny od poprzedniego, dodaje bieżący znak do `wynik`.
    7.  Po przetworzeniu całego łańcucha, zwraca `wynik`.

## Funkcja `main()`

Główna funkcja programu (`main`) demonstruje użycie metod z klasy `LancuchNarzedzia`:

1.  Wywołuje `LancuchNarzedzia::policzSamogloski("Przykład tekstu")` i wyświetla wynik (liczbę samogłosek) na konsoli.
2.  Wywołuje `LancuchNarzedzia::usunPowtorzenia("Abba;;;to zespol")` i wyświetla wynik (łańcuch bez kolejnych powtórzeń) na konsoli.

Program kończy działanie, zwracając 0.
