// Proszę przygotować brakujące elementy projektu tak, aby program kompilował się,
// linkował i działał poprawnie, a jego wynik odpowiadał przykładom na końcu pliku.
// Pliku Main.cpp NIE WOLNO modyfikować.
//
// LABORATORIUM 0 — BUILD DETECTIVE: OD KODU ŹRÓDŁOWEGO DO PROGRAMU
//
// Cel zadania:
// Prześledzić proces budowania programu C++ składającego się z kilku plików.
// Tym razem najważniejsze NIE jest pisanie kodu C++, lecz zrozumienie:
// - preprocesowania,
// - kompilacji do asemblera,
// - asemblacji do plików obiektowych,
// - linkowania,
// - działania Bash, CMake oraz generatorów Make i Ninja,
// - różnic między konfiguracjami Debug i Release.
//
// Fabuła:
// Otrzymali Państwo mały projekt, który ktoś dotychczas budował jednym
// poleceniem. Zadaniem jest przygotowanie powtarzalnego procesu budowania
// i pokazanie, co dokładnie dzieje się na każdym jego etapie.
//
// Pliki dostarczone w zadaniu:
// - Main.cpp                  — ten plik, nie wolno go zmieniać,
// - include/Arithmetic.h      — deklaracje prostych funkcji,
// - include/BuildMode.h       — deklaracja funkcji zwracającej tryb budowania,
// - src/Arithmetic.cpp        — dwie bardzo proste funkcje do poprawienia,
// - src/BuildMode.cpp         — kod wykorzystujący preprocesor (#ifdef NDEBUG).
//
// CZĘŚĆ 1. MINIMALNY KOD C++
// W src/Arithmetic.cpp poprawić wyłącznie wyniki funkcji add() i multiply(),
// aby wykonywały działania zgodne ze swoimi nazwami.
// Nie jest potrzebna znajomość klas ani zaawansowanego C++.
//
// CZĘŚĆ 2. RĘCZNY PROCES BUDOWANIA — build.sh (NAJWAŻNIEJSZA CZĘŚĆ)
// Napisać skrypt Bash o nazwie build.sh w katalogu głównym projektu.
// Skrypt ma przyjmować dwa argumenty:
//    ./build.sh gcc Debug
//    ./build.sh gcc Release
//    ./build.sh clang Debug
//    ./build.sh clang Release
//
// Uwaga: dla kodu C++ proszę korzystać odpowiednio z g++ lub clang++.
// Skrypt powinien:
//  1) sprawdzić liczbę i poprawność argumentów;
//  2) utworzyć oddzielny katalog wynikowy, np. manual/gcc/Debug/;
//  3) dla KAŻDEGO pliku .cpp osobno wygenerować wynik preprocesora
//     (opcja -E, rozszerzenie .ii dla preprocesowanego C++);
//  4) z plików .ii wygenerować asembler (opcja -S, pliki .s);
//  5) z plików .s otrzymać pliki obiektowe (opcja -c, pliki .o);
//  6) wykonać ODDZIELNE linkowanie wszystkich plików .o do programu
//     o nazwie BuildDetective (nie podawać plików .cpp linkerowi);
//  7) uruchomić otrzymany program.
//
// W obu trybach należy używać C++17 oraz ostrzeżeń -Wall -Wextra -Wpedantic.
// Dla Debug zastosować -g i -O0, a dla Release -O2 i -DNDEBUG.
// Skrypt powinien zakończyć działanie w razie niepowodzenia któregokolwiek
// etapu, zamiast próbować uruchomić stary program z wcześniejszej kompilacji.
//
// CZĘŚĆ 3. LINKER — EKSPERYMENT
// Po zbudowaniu programu należy ręcznie spróbować wykonać linkowanie
// z pominięciem pliku Arithmetic.o (bez zmieniania Main.cpp).
// Proszę przeczytać komunikat linkera, a następnie powtórzyć poprawne
// linkowanie z kompletem plików obiektowych.
//
// CZĘŚĆ 4. CMAKE
// Samodzielnie napisać CMakeLists.txt, który:
// - buduje TEN SAM program z trzech plików .cpp;
// - ustawia standard C++17;
// - udostępnia katalog include/;
// - włącza -Wall -Wextra -Wpedantic;
// - działa w trybach Debug i Release;
// - umożliwia budowanie poza katalogiem źródeł (out-of-source).
//
// Proszę sprawdzić Debug oraz Release za pomocą CMake (w ODDZIELNYCH
// katalogach), a także przetestować oba generatory: Ninja i Unix Makefiles.
// Nie trzeba samodzielnie pisać pliku Makefile — ma go wygenerować CMake.
// Proszę pamiętać, że generator i kompilator to nie to samo.
//
// CZĘŚĆ 5. KRÓTKIE ODPOWIEDZI — answers.txt
// W osobnym pliku tekstowym odpowiedzieć własnymi słowami (1–3 zdania):
//  1) Co zawierają pliki .ii, .s i .o?
//  2) Czym różni się kompilacja od linkowania?
//  3) Dlaczego linkowanie bez Arithmetic.o nie powiedzie się?
//  4) Co w tym projekcie zmienia definicja NDEBUG?
//  5) Czym różni się CMake od Make i Ninja?
//
// DO ODDANIA:
// - Main.cpp oraz dostarczone pliki include/ i src/ (z poprawką Arithmetic.cpp),
// - własny build.sh,
// - własny CMakeLists.txt,
// - answers.txt.
// Całość jako archiwum .tar.gz z katalogiem lab00/.
// NIE dołączać katalogów manual/, build/, build-debug/, build-release/
// ani żadnych innych plików wynikowych, takich jak .o, .ii, .s.
//
// Zadanie jest oceniane przede wszystkim za poprawność skryptu Bash,
// rozdzielenie etapów budowania, poprawne linkowanie oraz konfigurację CMake.

#include <iostream>
#include "Arithmetic.h"
#include "BuildMode.h"

int main() {
    std::cout << "=== Build Detective ===\n";
    std::cout << "7 + 5 = " << add(7, 5) << "\n";
    std::cout << "7 * 5 = " << multiply(7, 5) << "\n";
    std::cout << "Build mode: " << buildMode() << "\n";
    return 0;
}

/* Oczekiwany wynik działania programu (Debug):
=== Build Detective ===
7 + 5 = 12
7 * 5 = 35
Build mode: Debug
*/

/* Oczekiwany wynik działania programu (Release):
=== Build Detective ===
7 + 5 = 12
7 * 5 = 35
Build mode: Release
*/
