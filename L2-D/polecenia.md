Na podstawie maila od wykładowcy i listy tematów z wykładu, przygotowałem zestaw zadań do ćwiczenia najważniejszych tematów przed testem. Skupiłem się głównie na tematach wymienionych w mailu.

## Zadanie 1: Operatory new, new[], delete, delete[]
Napisz program demonstrujący prawidłowe użycie operatorów `new`, `new[]`, `delete` i `delete[]`. Stwórz funkcje, które:
- Alokują pamięć dla pojedynczego obiektu typu `int` i zwalniają ją
- Alokują tablicę obiektów typu `double` i zwalniają ją
- Pokazują, co się stanie, gdy użyjesz niewłaściwego operatora do zwolnienia pamięci (np. `delete` dla tablicy)

## Zadanie 2: Referencje
Napisz funkcje, które:
- Przyjmują parametr przez wartość i modyfikują go (pokaż, że oryginalna wartość nie ulega zmianie)
- Przyjmują parametr przez referencję i modyfikują go (pokaż, że oryginalna wartość ulega zmianie)
- Przyjmują parametr przez stałą referencję i próbują go zmodyfikować (pokaż błąd kompilacji)
- Zwracają referencję do zmiennej lokalnej (pokaż problemy z tym związane)
- Zwracają referencję do zmiennej statycznej lub globalnej

## Zadanie 3: Typy enum class
Stwórz kilka przykładów typów `enum class`:
- Enum reprezentujący dni tygodnia
- Enum reprezentujący kolory
- Funkcję przyjmującą parametr typu enum i wykorzystującą go w instrukcji switch
- Przykład pokazujący różnicę między starym `enum` a `enum class` (zakres nazw, niejawna konwersja)

## Zadanie 4: Typ std::byte
Napisz program demonstracyjny używający typu `std::byte`:
- Utwórz tablicę bajtów
- Wykonaj operacje bitowe na bajtach (AND, OR, XOR, przesunięcia)
- Pokaż, jak konwertować std::byte do/z innych typów liczbowych

## Zadanie 5: Funkcje memcpy i memmove
Napisz przykłady użycia funkcji `memcpy` i `memmove`:
- Kopiowanie danych z jednego miejsca do drugiego bez nakładania się
- Kopiowanie danych z nakładającymi się obszarami (pokaż różnicę między `memcpy` a `memmove`)
- Implementacja prostej funkcji serializacji korzystającej z `memcpy`

## Zadanie 6: static_cast
Napisz przykłady użycia operatora `static_cast`:
- Konwersja między różnymi typami liczbowymi (int → float, double → int)
- Konwersja między typem `enum class` a liczbami
- Przykład where `static_cast` zadziała, ale rzutowanie w stylu C byłoby niebezpieczne

## Zadanie 7: Dynamiczna alokacja pamięci dla złożonych struktur
Napisz program, który:
- Definiuje prostą strukturę (np. Student z polami imię, nazwisko, oceny)
- Dynamicznie alokuje tablicę tych struktur
- Wypełnia je danymi
- Poprawnie zwalnia pamięć
- Dodatkowo zaimplementuj kopiowanie tablicy struktur przy użyciu `memcpy`

## Zadanie 8: Praca z referencjami do tablic
Napisz funkcje, które:
- Przyjmują tablicę przez referencję
- Modyfikują zawartość tablicy
- Zwracają referencję do tablicy
- Demonstrują poprawne użycie referencji do tablic statycznych i dynamicznych

Te zadania powinny pozwolić Ci dobrze przećwiczyć wszystkie tematy wymienione w mailu od prowadzącego, ze szczególnym naciskiem na operatory new/delete, referencje, enum class, std::byte, memcpy/memmove oraz static_cast. Jednocześnie obejmują one część tematów z listy wykładowej, ale bez zagłębiania się w tematy public/private, które nie są wymagane na zbliżającym się teście.