# Kompilator i flagi (warto używać -Wall i -Wextra by wyłapywać błędy)
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++14 -I../include

# Nazwa pliku wynikowego (program powstanie w głównym folderze lab01)
TARGET = ../program

# Lista plików źródłowych (.cpp)
SRCS = ../src/Main.cpp ../src/MyLibrary.cpp

# Główna reguła kompilacji
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Reguła do czyszczenia (np. usuwanie pliku wykonywalnego)
clean:
	rm -f $(TARGET)