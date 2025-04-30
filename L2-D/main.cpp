#include <iostream>
#include <vector>

// Funkcja z wyciekiem pamięci
void memory_leak_example() {
    int* arr = new int[100];
    for (int i = 0; i < 100; ++i) {
        arr[i] = i;
    }
    // Brak delete[] arr → WYCIEK PAMIĘCI!
}

// Funkcja z dzieleniem przez zero
void divide_by_zero() {
    int a = 10;
    int b = 0;
    int result = a / b; // DZIELENIE PRZEZ ZERO!
    std::cout << result << std::endl;
}

// Funkcja z błędem logicznym (zła suma liczb parzystych)
int bad_sum_of_evens(const std::vector<int>& numbers) {
    int sum = 0;
    for (size_t i = 0; i <= numbers.size(); ++i) { // Błąd: <= zamiast <
        if (numbers[i] % 2 == 0) {
            sum += numbers[i];
        }
    }
    return sum;
}

// Funkcja z nieprawidłowym dostępem do pamięci
void invalid_memory_access() {
    int* ptr = nullptr;
    *ptr = 5; // PRÓBA ZAPISU POD NULLPTR!
}

int main() {
    // Testowanie wycieku pamięci
    memory_leak_example();
    std::cout << "Wyciek pamieci - sprawdz zadanie w debugerze (valgrind, ASan)" << std::endl;

    // Testowanie dzielenia przez zero (odkomentuj, aby zobaczyć crash)
    // divide_by_zero();

    // Testowanie błędnej sumy liczb parzystych
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    int sum = bad_sum_of_evens(numbers);
    std::cout << "Suma liczb parzystych: " << sum << std::endl; // Błędny wynik lub crash

    // Testowanie nieprawidłowego dostępu do pamięci (odkomentuj, aby zobaczyć crash)
    // invalid_memory_access();

    return 0;
}