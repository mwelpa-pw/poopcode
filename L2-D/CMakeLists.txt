
cmake_minimum_required(VERSION 3.10)  # Minimalna wymagana wersja CMake
project(MyProject)                    # Nazwa projektu

set(CMAKE_CXX_STANDARD 20)            # Standard C++ (11, 14, 17, 20...)
set(CMAKE_CXX_STANDARD_REQUIRED ON)    # Wymuś wybrany standard

add_executable(MyProject main.cpp)     # Dodaj plik źródłowy (np. main.cpp)