# Minimalna wymagana wersja CMake
cmake_minimum_required(VERSION 3.10)

# Nazwa projektu
project(Lab02)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

# Ustawienie standardu C++ (np. C++17, Ņeby mieś spokůj z nowoczesnymi funkcjami)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Znajdü wszystkie pliki .cpp w folderze src/ (odpowiednik Twojego "wildcard")
file(GLOB SOURCES "src/*.cpp")

# Tworzymy plik wykonywalny o podanej nazwie na podstawie znalezionych ürůde≥
add_executable(Konrad_Machowski ${SOURCES})

# Informujemy kompilator, gdzie znajdujĻ siÍ pliki nag≥ůwkowe .h (odpowiednik flagi -I)
target_include_directories(Konrad_Machowski PRIVATE include)