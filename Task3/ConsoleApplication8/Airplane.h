#pragma once

#include <iostream> 
#include <fstream>
#include <string> 

class Airplane {

private:
	std::string Name;
	std::string Airline;
	int YearOfIssue, Capacity, NumberOfPassengers;
	int Percent = 0;// добавил новое поле(процент заполнености) для сортировки 
public:
	Airplane() {
		Name = "???";
		Airline = "???";
		NumberOfPassengers = Capacity = YearOfIssue = -1;
	}
	
	Airplane(const std::string name_, const std::string airline_,int year_, int capacity_) {
		Name = name_;
		Airline = airline_;
		YearOfIssue = year_;
		Capacity = capacity_;
		NumberOfPassengers = -1;
	}
	
	void SetModel(const std::string name_) {
		Name = name_;
	}
	
	void SetAirline(const std::string airline_) {
		Airline = airline_;
	}
	
	void SetYearOfIssue(const int year_) {
		YearOfIssue = year_;
	}
	
	void SetNumberOfPassengers(const int NumberOfPassengers_) {
		NumberOfPassengers = NumberOfPassengers_;
	}
	
	void SetCapacity(const int capacity_) {
		Capacity = capacity_;
	}
	int GetPecent() {
		return Percent;
	}

	void PrintInfo() {
		setlocale(LC_ALL, "Russian");
		std::cout << "Модель: " << Name << "(Год выпуска: " << YearOfIssue << ")" <<  std::endl;
		std::cout << "Рейс: " << Airline << " Статус: Успешно" << std::endl;
		// Значение поля для процентов считается с округление вниз 
		std::cout << "Количество пассажиров: " << NumberOfPassengers << " из возможных "<< Capacity << std::endl;
		std::cout << std::endl;
	}
	
	void Move() {
		if(NumberOfPassengers == -1) {
			srand(time(NULL));
			NumberOfPassengers = rand() % (Capacity + 1);
			Percent = 100 * NumberOfPassengers / Capacity;
		}
	}
	
	void serialize() {
		setlocale(LC_ALL, "Russian");
		std::ofstream File("Запись.txt", std::ofstream::app);
		if (!File.is_open()) {
			std::cout << "Файл не найден!" << std::endl;
			return;
		}
		File << Name << "\n";
		File << Airline << "\n";
		File << NumberOfPassengers << ' ' << Capacity << ' ' << YearOfIssue << "\n";
	 }
	
	void deserialize() {
		setlocale(LC_ALL, "Russian");
		std::ifstream File("Чтение.txt");
		if (!File.is_open()) {
			std::cout << "Файл не найден!" << std::endl;
			return;
		}
		File >> Name;
		File >> Airline;
		File >> NumberOfPassengers >> Capacity >> YearOfIssue;
	}
	
	void serialize(const std::string filename) {
		setlocale(LC_ALL, "Russian");
		std::ofstream File(filename, std::ofstream::app);
		if (!File.is_open()) {
			std::cout << "Файл не найден!" << std::endl;
			return;
		}
		File << Name << "\n";
		File << Airline << "\n";
		File << NumberOfPassengers << ' ' << Capacity << ' ' << YearOfIssue << "\n";
	}
	
	void deserialize(const std::string filename) {
		setlocale(LC_ALL, "Russian");
		std::ifstream File(filename);
		if (!File.is_open()) {
			std::cout << "Файл не найден!" << std::endl;
			return;
		}
		File >> Name;
		File >> Airline;
		File >> NumberOfPassengers >> Capacity >> YearOfIssue;
		
	}
};