#include <iostream>
#include <conio.h>
#include <string>

template<typename T>
void PushBack(char*& arr, int& size, T value) {
	char* newArray = new char[size+1];

	for (int i = 0; i < size; i++) {
		newArray[i] = arr[i];
	}

	newArray[size] = value;
	delete[] arr;

	arr = newArray;

	size++;
}

std::string generatePassword(bool& numbers, bool& upperCase, bool& lowerCase, int& length) {
	std::string password;
	int SIZE = 0;

	char* arr = nullptr;

	if (numbers == true) {
		for (int i = 48; i <= 57; i++) {
			PushBack(arr, SIZE, i);
		}
	}
	if (upperCase == true) {
		for (int i = 65; i <= 90; i++) {
			PushBack(arr, SIZE, i);
		}
	}
	if (lowerCase == true) {
		for (int i = 97; i <= 122; i++) {
			PushBack(arr, SIZE, i);
		}
	}

	for (int i = 0; i < length; i++) {
		password += arr[rand() % SIZE];
	}
	return password;
}

int main() {
	srand(time(0));

	bool numbers = true;
	bool upperCase = false;
	bool lowerCase = false;
	int length = 16;


	char key;
	while (true) {
		std::cout << "PasswordGenerator v1.0 | GitHub @deadbutton\n\n";
		std::cout << ((numbers == true) ? "[1] \033[32mNumbers\033[0m\n" : "[1] Numbers\n");
		std::cout << ((upperCase == true) ? "[1] \033[32mUpperCase\033[0m\n" : "[2] UpperCase\n");
		std::cout << ((lowerCase == true) ? "[1] \033[32mLowerCase\033[0m\n" : "[3] LowerCase\n");
		std::cout << "Length: " << length << "\tPRESS 0 TO CHANGE\t" << "PRESS ANY KEY DESPITE SHOWED TO UPDATE\n\n\n";
		std::cout << "Password: " << generatePassword(numbers, upperCase, lowerCase, length);
		key = _getch();

		switch (key) {
		case '1': numbers = !numbers; break;
		case '2': upperCase = !upperCase; break;
		case '3': lowerCase = !lowerCase; break;
		case '0':
			system("cls");
			std::cout << "Enter the length of a password: ";
			std::cin >> length;
			system("cls");
		}
		system("cls");
	}
	return 0;
}
