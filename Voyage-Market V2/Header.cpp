#include "Header.hpp"

void Login(std::string*& loginArr, std::string*& passwordArr, std::string*& roleArr, int size)
{
	std::cout << "Доступные аккаунты: ";
	if (size == 1)
	{
		std::cout << "\nАккаунтов не найдено, регистрация аккаунта администратора\nВведите логин: ";
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << loginArr[i] << '\n';
	}
	std::string inputLogin, inputPassword;
	std::cout << "Введите существующий логин, чтобы войти или новый, чтобы зарегистрироваться:";
}
