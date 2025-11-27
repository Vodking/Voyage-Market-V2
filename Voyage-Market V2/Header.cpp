#include "Header.hpp"

size_t userSize = 3;
size_t staffCount = 1;

std::string userStatus[3]{ "Супер администратор", "Администратор", "Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "admin","Admin123" "user" };
std::string* passArr = new std::string[userSize]{ "123","111" "321" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[1], userStatus[2]};
double* bonusArr = new double[userSize] { 0.0, 0.0, 0.0 };
unsigned int* userIdArr = new unsigned int[userSize] {1, 2, 3 };
unsigned int currentId = 0;
std::string currentStatus{};

std::unordered_set<char> loginSymbols;
std::unordered_set<char> passSymbols;
bool isLoginSetCreated = false;
bool isPassSetCreated = false;
// Продажии
size_t checkSize = 0;
int* idArrCheck;
std::string* nameArrCheck;
unsigned int* countArrCheck;
double* priceArrCheck;
double* totalPriceArrCheck;

double cashIncome = 0.0;
double bankIncome = 0.0;
double cash = 3000 + rand() % 7500;

//Cклад
size_t dynSize = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;

void CreateStorage()
{
	const int staticSize = 10;

	unsigned int id[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::string name[staticSize]
	{
		"Термос 0.5 литров", "Термос 1 литр",
		"Термос 2 литра", "Палатка 'Одиночка'",
		"Палатка 'Убежище'", "Палатка 'Вояж Делюкс'",
		"Походный нож 'Грибник'", "Походный нож 'Веточник'",
		"Анти-клещ 'Жижка'", "Рюкзак 'Вояж Простор'"
	};
	unsigned int count[staticSize]{ 5, 13, 10, 3, 4, 2, 7, 14, 6, 10 };
	double price[staticSize]{ 539.99, 749.99, 999.99, 769.99 , 1199.99, 2499.99, 199.99, 499.99, 899.99, 1699.99 };

	if (isStorageCreated)
	{
		delete[]idArr, countArr, nameArr, priceArr;
	}

	dynSize = staticSize;
	idArr = new unsigned int[dynSize];
	countArr = new unsigned int[dynSize];
	nameArr = new std::string[dynSize];
	priceArr = new double[dynSize];
	isStorageCreated = true;

	FillArr(idArr, id, dynSize);
	FillArr(countArr, count, dynSize);
	FillArr(nameArr, name, dynSize);
	FillArr(priceArr, price, dynSize);


}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название\t\t" << "Кол-во\t" << "Цена\t\n";

		for (size_t i = 0; i < dynSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t\t" << countArr[i] << "\t" << priceArr[i] << "руб\n";
		}
		system("pause");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название\t\t" << "Кол-во\t\n";
		for (size_t i = 0; i < dynSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t\t" << countArr[i] << "\n";
		}
		system("pause");
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название\t\t" << "Цена\t\n";

		for (size_t i = 0; i < dynSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t\t" << priceArr[i] << "руб\n";
		}
		system("pause");
	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название\t\t\n";

		for (size_t i = 0; i < dynSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\n";
		}
		system("pause");
	}

}

void ShowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Начать продажу, 2 - Показать склад,\n3 - Пополнить склад, 4 - Списать товар,\n5 - Измененить цены 6 - Редактировать склад,\n 7 - Редактировать персонал, 8 - Отчёт о прибыли,\n0 - Закрыть смену\n";
		std::cout << "Ввод: ";
		GetLine(choose);
		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			AddStorageItem();
		}
		else if (choose == "4")
		{
			RemoveStorageItem();
		}
		else if (choose == "5")
		{
			ChangeStoragePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeUser();
		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

		}
		else
		{
			std::cout << "БАРАН!!!!!!?????!?!?!?!?!?!??!?!?!?!?!!!!\n";
			Err();
		}
		system("cls");
	}
}

void AddStorageItem()
{
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;

	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода: ";
		GetLine(chooseId);
		if (choose == "exit")
		{
			std::cout << "Отмена операций пополнения товара!\n";
			break;
		}
		std::cout << "Введите кол-во товара для пополнения: ";
		GetLine(chooseCount);


		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id+1 < 0 || id > dynSize - 1 || count < 0 || count > 599)
			{
				std::cout << "Некорректный ID или количество\nМаксимальное количество 599\n";
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << '\t' << countArr[id] << " ---> " << countArr[id] + count << "\n\n";
				std::cout << "Подтвердить?\n1 - Да, 2 - Нет, Ввод: ";
				GetLine(choose);
				if (choose == "1")
				{

					countArr[id] += count;
					std::cout << "Успешно!\n";
					Sleep(1500);
					system("cls");
					break;

				}
				else if (choose == "2")
				{
					std::cout << "Отмена попосления товара!\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}


		}
	}
}

void RemoveStorageItem()
{
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;

	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода: ";
		GetLine(chooseId);
		if (choose == "exit")
		{
			std::cout << "Отмена операций списания товара!\n";
			break;
		}
		std::cout << "Введите кол-во товара для списания: ";
		GetLine(chooseCount);


		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id+1 < 0 || id > dynSize - 1 || count < 0)
			{
				std::cout << "Некорректный ID или количество\n";
				Sleep(1500);
				system("cls");
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << '\t' << countArr[id] << " ---> " << countArr[id] - count << "\n\n";
				std::cout << "Подтвердить?\n1 - Да, 2 - Нет, Ввод: ";
				GetLine(choose);
				if (choose == "1")
				{

					countArr[id] -= count;
					std::cout << "Успешно!\n";
					Sleep(1500);
					system("cls");
					break;

				}
				else if (choose == "2")
				{
					std::cout << "Отмена списания товара!\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}


		}
	}
}

void ChangeStoragePrice()
{
	std::string chooseId, choosePrice, choose;
	unsigned int id = 0;
	double price = 0;

	while (true)
	{
		system("cls");
		ShowStorage(2);
		std::cout << "Введите ID товара или \"exit\" для выхода: ";
		GetLine(chooseId);
		if (choose == "exit")
		{
			std::cout << "Отмена операций редактирования цены товара!\n";
			break;
		}
		std::cout << "Введите новую цену товара: ";
		GetLine(choosePrice);


		if (IsNumber(chooseId) && IsNumber(choosePrice))
		{
			id = std::stoi(chooseId) - 1;
			price = std::stoi(choosePrice);

			if (id+1 < 0 || id > dynSize - 1 || price < 0.0 || price > 99999999.0)
			{
				std::cout << "Некорректный ID или количество\nМаксимальная цена 99999999.0\n";
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << '\t' << priceArr[id] << "руб ---> " << price << "руб\n\n";
				std::cout << "Подтвердить?\n1 - Да, 2 - Нет, Ввод: ";
				GetLine(choose);
				if (choose == "1")
				{

					priceArr[id] = price;
					std::cout << "Успешно!\n";
					Sleep(1500);
					system("cls");
					break;

				}
				else if (choose == "2")
				{
					std::cout << "Отмена редактирования цены товара!\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}


		}
	}
}

void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Добавить новый товар\n2 - Изменить название товара\n3 - Удалить товар\n4 - Выход из редактора\n";
		std::cout << "Ввод: ";
		GetLine(choose);
		if (choose == "1")
		{
			AddNewItem();
		}
		else if (choose == "2" && dynSize > 0)
		{
			ChangeName();
		}
		else if (choose == "3" && dynSize > 0)
		{
			DeleteItem();
		}
		else if (choose == "4")
		{
			system("cls");
			break;
		}
		else
		{
			std::cout << "БАРАН\n";
			Err();
		}
	}

}

void AddNewItem()
{
	std::string newName, newPrice, newCount, choose;
	double price = 0.0;
	unsigned int count = 0;
	bool exit = true;
	while (true)
	{
		exit = true;
		while (true)
		{
			
			system("cls");
			std::cout << "Добавление нового товара\nВведите \"exit\" для отмены операции\nВведите название: ";
			GetLine(newName);
			if (newName == "exit")
			{
				std::cout << "Отмена добавления товара!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			
			if (newName.size() <= 0 || newName.size() >= 60)
			{
				std::cout << "Некорректная длинна строки! Максимальная длинна = 60 символов\n";
				Sleep(1488);
			}
			else
			{
				break;
			}
		}
		
		while (exit)
		{
			system("cls");
			std::cout << "Добавление кол-во нового товара\nВведите \"exit\" для отмены операции\nВведите название: ";
			GetLine(newCount);
			if (newName == "exit")
			{
				std::cout << "Отмена добавления товара!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newCount))
			{
				count = std::stoi(newCount);
				if (count > 599)
				{
					std::cout << "Ошибка максимального кол-во товара!\n";
					Sleep(1488);
				}
				else
				{
					break;
				}
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "Добавление цены нового товара\nВведите \"exit\" для отмены операции\nВведите название: ";
			GetLine(newPrice);
			if (newName == "exit")
			{
				std::cout << "Отмена добавления товара!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newPrice))
			{
				price = std::stod(newPrice);
				if (price > 99999999.0 || price < 0)
				{
					std::cout << "Ошибка цены товара!\n";
					Sleep(1488);
				}
				else
				{
					break;
				}
			}
		}
		
		while (exit)
		{
			std::cout << "Новый товар: " << newName << "\n";
			std::cout << "Кол-во: " << newCount << "\n";
			std::cout << "Цена: " << newPrice << "\n";
			std::cout << "Подтвердить?\n1 - Да, 2 - Нет\nВвод: ";
			GetLine(choose);
			if (choose == "1")
			{
				dynSize++;
				unsigned int* idArrTemp = new unsigned int[dynSize];
				std::string* nameArrTemp = new std::string[dynSize];
				unsigned int* countArrTemp = new unsigned int[dynSize];
				double* priceArrTemp = new double[dynSize];

				FillArr(idArrTemp, idArr, dynSize - 1);
				FillArr(nameArrTemp, nameArr, dynSize - 1);
				FillArr(countArrTemp, countArr, dynSize - 1);
				FillArr(priceArrTemp, priceArr, dynSize - 1);

				idArrTemp[dynSize - 1] = dynSize;
				nameArrTemp[dynSize - 1] = newName;
				countArrTemp[dynSize - 1] = count;
				priceArrTemp[dynSize - 1] = price;

				std::swap(idArr, idArrTemp);
				std::swap(nameArr, nameArrTemp);
				std::swap(countArr, countArrTemp);
				std::swap(priceArr, priceArrTemp);

				delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
			}
			else if (choose == "2")
			{
				std::cout << "Отмена!\n";
				Sleep(1500);
				break;
			}
			else
			{
				std::cout << "муравей\n";
				Err();
			}
		}
		if (exit == false)
		{
			break;
		}
	}

}

void ChangeName()
{
	std::string chooseId, newName, choose;
	unsigned int id = 0;

	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "Введите ID товара, для изменения имени, или \"exit\" для выхода: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "ГАЛЯ ОТМЕНА\n";
			Sleep(1488);
			std::cout << "Галя:Идуууу\n";
			Sleep(1488);
			std::cout << "Отменено";
			Sleep(1488);
			break;
		}
		
		std::cout << "Введите новое название товара: ";
		GetLine(newName);

		if (newName.size() <= 0 || newName.size() >= 60)
		{
			std::cout << "Некорректная длинна строки!\n";
			Sleep(1500);
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > dynSize - 1)
			{
				std::cout << "Ошибка ID!\n";
				Sleep(1500);
			}
			else
			{
				std::cout << nameArr[id] << " ---> " << newName << "\n";
				std::cout << "Подвердить? 1 - Да, 2 - Нет\nВвод: ";
				GetLine(choose);
				if (choose == "1")
				{
					nameArr[id] = newName;
					std::cout << "Изменение названия завершено!\n";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "ООООТМЕНАААА\n";
					Sleep(1500);
				}
				else
				{
					std::cout << "Галя недовольна!\n";
					Err();
				}
			}
		}
	}
}

void DeleteItem()
{
	std::string chooseId, choose;
	unsigned int id = 0;
	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\nВведите ID товара для удаления или \"exit\" для выхода: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена баран\n";
			Sleep(1500);
			break;
		}
		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId);
			if (id < 0 || id > dynSize - 1)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1500);
			}
			else
			{
				std::cout << "Товар на удаление: " << nameArr[id] << "\n";
				std::cout << "Подтвердить? 1 - Да, 2 - Нет\nВвод:";
				GetLine(choose);
				if (choose == "1")
				{
					dynSize--;
					unsigned int* idArrTemp = new unsigned int[dynSize];
					std::string* nameArrTemp = new std::string[dynSize];
					unsigned int* countArrTemp = new unsigned int[dynSize];
					double* priceArrTemp = new double[dynSize];

					//FillArray(idArrTemp, idArr, dynSize);
					//FillArray(nameArrTemp, nameArr, dynSize);
					//FillArray(countArrTemp, countArr, dynSize);
					//FillArray(priceArrTemp, priceArr, dynSize);
					for (int i = 0, c = 0; i < dynSize; i++, c++)
					{
						if (id == c)
						{
							c++;
						}
						idArrTemp[i] = i + 1;
						nameArrTemp[i] = nameArr[c];
						countArrTemp[i] = countArr[c];
						priceArrTemp[i] = priceArr[c];
					}
					

					std::swap(idArr, idArrTemp);
					std::swap(nameArr, nameArrTemp);
					std::swap(countArr, countArrTemp);
					std::swap(priceArr, priceArrTemp);

					delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
				}
				else if (choose == "2")
				{
					std::cout << "Отменооо\n";
					Sleep(1500);
				}
				else
				{
					std::cout << "Оса";
					Err();
				}
			}
		}
	}
}

void ChangeUser()
{
	if (!isLoginSetCreated)
	{
		SetLoginSymbols();
	}
	if (!isPassSetCreated)
	{
		SetPassSymbols();
	}
	std::string choose;
	while (true)
	{
		std::cout << "1 - Добавить нового пользователя\n2 - Показать пользователей\n3 - Изменить пароль польователя\n4 - Удалить пользователя\n 5 - Выход из редактора\n";
		std::cout << "Ввод: ";
		GetLine(choose);
		if (choose == "1")
		{
			AddNewUser();
		}
		else if (choose == "2" && userSize > 0)
		{
			ShowUsers();
		}
		else if (choose == "3" && dynSize > 0)
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else
		{
			std::cout << "БАРАН\n";
			Err();
		}
	}

}


void AddNewUser()
{
	std::string newLogin, newPass, newRole ,choose;
	bool exit = true;
	while (true)
	{
		while (true)
		{
			system("cls");
			std::cout << "Введите логин нового пользователя или \"exit\" для выхода";
			GetLine(newLogin);
			if (newLogin == "exit")
			{
				std::cout << "Ооомомомотмена";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckLogin(newLogin))
			{
				break;
			}
			else
			{
				std::cout << "Допустимые символы: a-z A-Z, 0-9\n\n";
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "Введите пароль нового пользователя или \"exit\" для выхода";
			GetLine(newPass);
			if (newPass == "exit")
			{
				std::cout << "Ооомомомотмена";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckPass(newPass))
			{
				break;
			}
			else
			{
				std::cout << "Допустsfasf\n\n";
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "Введите роль нового пользователя или \"exit\" для выхода.\n1 - Админ, 2 - Сотрудник";
			GetLine(choose);
			if (choose == "exit")
			{
				std::cout << "Ооомомомотмена";
				Sleep(1500);
				exit = false;
				break;
			}
			if (choose == "1")
			{
				newRole = userStatus[1];
				break;
			}
			else if (choose == "2")
			{
				newRole = userStatus[2];
				break;
			}
			else
			{
				Err();
			}
		}

		while (exit)
		{
			std::cout << "Пользователь -> " << newLogin << "\nПароль -> " << newPass << "\nРоль -> " << newRole;
			std::cout << "\n1 - Подтвердить, 2 - Отмена. Ввод:";
			GetLine(choose);
			if (choose == "1")
			{
				dynSize++;
				if (newRole == userStatus[2])
				{
					staffCount++;
				}
				std::string* LoginArrTemp = new std::string[dynSize];
				std::string* PassArrTemp = new std::string[dynSize];
				std::string* RoleArrTemp = new std::string[dynSize];
				double* bonusArrTemp = new double[dynSize];
				unsigned int* userIdArrTemp = new unsigned int[dynSize];

				FillArr(LoginArrTemp, loginArr, dynSize - 1);
				FillArr(PassArrTemp, passArr, dynSize - 1);
				FillArr(RoleArrTemp, statusArr, dynSize - 1);
				FillArr(bonusArrTemp, bonusArr, dynSize - 1);
				FillArr(userIdArrTemp, userIdArr, dynSize - 1);

				LoginArrTemp[dynSize - 1] = newLogin;
				PassArrTemp[dynSize - 1] = newPass;
				RoleArrTemp[dynSize - 1] = newRole;
				bonusArrTemp[dynSize - 1] = 0.0;
				userIdArrTemp[dynSize - 1] = dynSize;

				std::swap(loginArr, LoginArrTemp);
				std::swap(statusArr, PassArrTemp);
				std::swap(statusArr, RoleArrTemp);
				std::swap(bonusArr, bonusArrTemp);
				std::swap(userIdArr, userIdArrTemp);

				delete[] LoginArrTemp, PassArrTemp, RoleArrTemp, bonusArrTemp, userIdArrTemp;

				std::cout << "Идёт подготовка...\n";
				Sleep(2000);
				std::cout << "Пользователь успешно добавлен!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			else if (choose == "2")
			{
				std::cout << "Отменанана!\n";
				Sleep(1500);
			}
			else
			{
				Err();
			}
	
		}
		if (exit == false)
		{
			break;
		}
	}
}

void ChangePass()
{
	std::string newPass, newPass2, choose;
	int userId = 0, isAdmin = 0;

	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			ShowUsers(1);
			isAdmin = 0;
		}
		else
		{
			ShowUsers();
			isAdmin = 1;
		}
		std::cout << "\nВведите номер ползователя для смены пароля, \"exit\" для выхода\nВвод: ";
		GetLine(choose);
		if(choose == "exit")
		{
			std::cout << "Отмненен";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userId = std::stoi(choose);

			if (userId < isAdmin || userId > dynSize - 1)
			{
				std::cout << "Пользователя с таким номером не сущестует!\n";
				Sleep(1500);
				continue;
			}
		}

		while (true)
		{
			system("cls");

			if (currentStatus == userStatus[0] && statusArr[userId] == userStatus[1])
			{
				std::cout << "Нельзя менять пароль администратору!\n";
				Sleep(1500);
				break;
			}

			std::cout << "Введите новый пароль для протзователя " << loginArr[userId] << ": ";
			GetLine(newPass);
			std::cout << "Подтвердите пароль: ";
			GetLine(newPass2);
			if (newPass == newPass2)
			{
				passArr[userId] = newPass;
				std::cout << "Успешно!\n";
				Sleep(1500);
				break;
			}
			else
			{
				std::cout << "Повторите попытку\n";
				Sleep(3000);
			}
		}
	}
}

void ShowUsers(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left << std::setw(12) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";
		for (int i = 0; i < userSize; i++)
		{
			std::cout << i << std::left << std::setw(12) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t" << statusArr[i];
		}
		system("pause");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(12) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";
		for (int i = 0; i < userSize; i++)
		{
			std::cout << i << std::left << std::setw(12) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t" << statusArr[i];
		}
		
	}

}

void DeleteUser()
{
	std::string chooseId, checkPass, choose;
	int userId, isAdmin = 1;

	if (currentStatus == userStatus[0] && dynSize < 2)
	{
		std::cout << "Нет доступных польхователей для удаления!\n";
		Sleep(1500);
		return;
	}
	else if (currentStatus == userStatus[1] && staffCount < 1)
	{
		std::cout << "Нет доступных польхователей для удаления!\n";
		Sleep(1500);
		return;
	}
	ShowUsers();
	std::cout << "\nВведите номер пользователя для удаления или\"exit\" для выхода:";
	GetLine(choose);
	if (choose == "exit")
	{
		std::cout << "Отмена удаления пользователя!\n";
		Sleep(1500);
		return;
	}
	else if (IsNumber(choose))
	{
		userId = std::stoi(choose);
		if (userId < isAdmin || userId > dynSize-1)
		{
			std::cout << "Пользователя с таким номером не существует!\n";
			Sleep(1500);
			return;
		}

		while (true)
		{
			system("cls");
			if (currentStatus == userStatus[1] && statusArr[userId] == userStatus[1])
			{
				std::cout << "Нельзя удалять администратора!\n";
				Sleep(1500);
				break;
			}
			std::cout << "Удаления пользователя: " << loginArr[userId] << "\n";
			std::cout << "Для подтверждения введите пароль Супер Администратора или \"exit\" для выхода: ";
			GetLine(checkPass);
			if (checkPass == "exit")
			{
				std::cout << "ОТМЕНА УДАЛЕНИЯ ПОЛЬЗОВАТЕЛЯЯ " << loginArr[userId] << "\n";
				Sleep(1500);
				break;
			}
			else if (checkPass == passArr[0])
			{
				if (statusArr[userId] == userStatus[2])
				{
					staffCount--;
				}
				dynSize--;

				std::string* LoginArrTemp = new std::string[dynSize];
				std::string* PassArrTemp = new std::string[dynSize];
				std::string* RoleArrTemp = new std::string[dynSize];
				double* bonusArrTemp = new double[dynSize];
				unsigned int* userIdArrTemp = new unsigned int[dynSize];

				for (size_t i = 0, c = 0; i < dynSize; i++)
				{
					if (userId == c)
					{
						c++;
					}

					LoginArrTemp[i] = loginArr[c];
					PassArrTemp[i] = passArr[c];
					RoleArrTemp[i] = statusArr[c];
					bonusArrTemp[i] = bonusArr[c];
					userIdArrTemp[i] = i + 1;
				}

				std::swap(loginArr, LoginArrTemp);
				std::swap(statusArr, PassArrTemp);
				std::swap(statusArr, RoleArrTemp);
				std::swap(bonusArr, bonusArrTemp);
				std::swap(userIdArr, userIdArrTemp);

				delete[] LoginArrTemp, PassArrTemp, RoleArrTemp, bonusArrTemp, userIdArrTemp;

			}
			else
			{
				Err();
			}
		}
	}
	else
	{
		Err();
	}
}

void SetLoginSymbols()
{
	for (char i = '0'; i < '9'; i++)
	{
		loginSymbols.insert(i);
	}
	for (char i = 'a'; i < 'z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (char i = 'A'; i < 'Z'; i++)
	{
		loginSymbols.insert(i);
	}
	isLoginSetCreated = true;
}

void SetPassSymbols()
{
	for (char i = '!'; i < '&'; i++)
	{
		loginSymbols.insert(i);
	}
	for (char i = '('; i < '+'; i++)
	{
		loginSymbols.insert(i);
	}
	for (char i = '/'; i < '~'; i++)
	{
		loginSymbols.insert(i);
	}

	isPassSetCreated = true;
}

bool CheckLogin(const std::string& str)
{
	if (str.size() < 5 || str.size() > 20)
	{
		std::cout << "Ошибка длинны логина\n";
		Sleep(1500);
		return false;
	}

	for (char sym: str)
	{
		if (loginSymbols.count(sym))
		{
			std::cout << "Некорректный логин";
			Sleep(1500);
			return false;
		}
	}
	
	for (size_t i = 0; i < userSize; i++)
	{
		if (str == nameArr[i]) 
		{
			std::cout << "Такой пользователь уже существует!\n";
			return false;
		}
	}
	return true;
}

bool CheckPass(const std::string& str)
{
	if (str.size() < 8 || str.size() > 30)
	{
		std::cout << "Ошибка длинны пароля\n";
		Sleep(1500);
		return false;
	}
	int numCount = 0;
	int symCount = 0;
	std::unordered_set<char> specialSymbols{'!','@', '#','$','%','^','&','*','(',')','-','_','=','+', '/','?','|','\\','\"','\'',',','.','<','>','~','`',':',';','{','}','[',']'};


	for (char sym : str)
	{
		if (!passSymbols.count(sym))
		{
			std::cout << "Неккоректный пароль\n";
			Sleep(1500);
			return false;
		}

		if (std::isdigit(sym))
		{
			numCount++;
		}
		if (specialSymbols.count(sym))
		{
			symCount++;
		}
	}
	if (numCount > 2 && symCount > 2)
	{
		return true;
	}
	else
	{
		std::cout << "Минимум 3 спец символа!\n";
		return false;
	}
}

void Selling()
{
	bool isFirst = false;
	std::string chooseId, chooseCount, chooseMoney, choose;
	unsigned int id = 0, count = 0;
	int index = -1;
	double money = 0.0, totalSum = 0.0;

	while (true)
	{
		ShowStorage();
		std::cout << "\nВведите ID товара для покупки или \"exit\" для завершения выбора товаров: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			if (isFirst == false)
			{
				std::cout << "Выход без покупок!\n";
				Sleep(1500);
			}
		}

		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > dynSize-1)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}
		std::cout << "\nВыберите кол-во товара или \"exit\" для выбора другого товара: ";
		GetLine(chooseCount);
		if (chooseCount == "exit")
		{
			std::cout << "Отмена попупки товара: " << nameArr[id] << "\n";
			Sleep(1500);
			continue;
		}

		if (IsNumber(chooseCount))
		{
			count = std::stoi(chooseCount);
			if (count < 1 || count > countArr[id])
			{
				std::cout << "Ошибка кол-ва!\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}
		
		CheckArrAppend();
		if (isFirst == false)
		{
			isFirst == true;
		}
		index++;
		idArrCheck[index] = idArr[id];
		nameArrCheck[index] = nameArr[id];
		priceArrCheck[index] = priceArr[id];
		countArrCheck[index] = count;
		totalPriceArrCheck[index] = count * priceArr[id];
		countArr[id] -= count;
		totalSum += totalPriceArrCheck[index];

		std::cout << "\nТовар добавлен в чек!\n";
		Sleep(1488);

		PrintCheck(totalSum);
		std::cout << "Подтвердить покупку ? 1 - Да, 2 - Еще товар, 3 - Отмена, Ввод : ";
		GetLine(choose);
		if (choose == "1")
		{
			while (true)
			{
				system("cls");
				std::cout << "Выберите способ оплаты, 1 - Наличка, 2 - Безнал, Ввод: ";
				GetLine(choose);
				if (choose == "1")
				{

				}
				else if (choose == "2")
				{
					std::cout << "Приложите карту\n\n";
					Sleep(1500);
					if (rand() % 20 <= 2)
					{
						for (size_t i = 0; i < 5; i++)
						{
							std::cout << i + 1 << "\t"; 
							Beep(500, 400);
							Sleep(800);
						}
						std::cout << "\nСоединение не установлено, повторите попытку\n";
					}
					else
					{
						for (size_t i = 0; i < 5; i++)
						{
							std::cout << i + 1 << "\t";
							Beep(500, 400);
							Sleep(800);
						}
						std::cout << "Оплата прошла успешно. Спасибо за покупку\n";
					}
				}
				else if (choose == "Муравей")
				{

				}
				else
				{
					Err();
				}
			}
			delete[] idArrCheck;
			delete[] countArrCheck;
			delete[] nameArrCheck;
			delete[] priceArrCheck;
			delete[] totalPriceArrCheck;
			break;
		}
		else if (choose == "2")
		{
			continue;
		}
		else if (choose == "3")
		{
			std::cout << "Отмена покупки!\n";
			StorageReturner();
			Sleep(1500);
			system("cls");
			return;
		}
		else
		{
			Err();
			continue;
		}
	}

}

void PrintCheck(double totalSum)
{
	std::cout << "\t" << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Цена за ед.\t\t" << "Кол-во\t" << "иТОГО\n";

	for (size_t i = 0; i < checkSize; i++)
	{
		std::cout << i+1 << "\t" << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i] <<"\t\t" << priceArrCheck[i] << "руб\t\t" << countArrCheck[i] <<"\t" << totalPriceArrCheck<<"\n";
	}
	std::cout << "Итого к оплате " << totalSum << "Руб";
}

void StorageReturner()
{
	for (size_t i = 0; i < checkSize; i++)
	{
		countArr[idArrCheck[i] - 1] += countArrCheck[i];
	}
	delete[] idArrCheck;
	delete[] countArrCheck;
	delete[] nameArrCheck;
	delete[] priceArrCheck;
	delete[] totalPriceArrCheck;
}

void CheckArrAppend()
{
	checkSize++;
	int* idArrCheckTemp = new int[checkSize];
	std::string* nameArrCheckTemp = new std::string[checkSize];
	unsigned int* countArrCheckTemp = new unsigned int[checkSize];
	double* priceArrCheckTemp = new double[checkSize];
	double* totalPriceArrCheckTemp = new double[checkSize];

	FillArr(idArrCheckTemp, idArrCheck,checkSize - 1);
	FillArr(countArrCheckTemp, countArrCheck, checkSize - 1);
	FillArr(nameArrCheckTemp, nameArrCheck, checkSize - 1);
	FillArr(priceArrCheckTemp, priceArrCheck, checkSize - 1);
	FillArr(totalPriceArrCheckTemp, totalPriceArrCheck, checkSize - 1);

	std::swap(idArrCheckTemp, idArrCheck);
	std::swap(countArrCheckTemp, countArrCheck);
	std::swap(nameArrCheckTemp, nameArrCheck);
	std::swap(priceArrCheckTemp, priceArrCheck);
	std::swap(totalPriceArrCheckTemp, totalPriceArrCheck);

	delete[] idArrCheckTemp; 
	delete[] countArrCheckTemp;
	delete[] nameArrCheckTemp; 
	delete[] priceArrCheckTemp;
	delete[] totalPriceArrCheckTemp;
}

void End()
{
	delete[] loginArr, passArr, statusArr, bonusArr, userIdArr;
}





bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "Ошибка длинны числа. Максимум - девятизначные числа!\n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Введённые данные не являются числом!\n";
			Sleep(1500);
			return false;
		}
		return true;
	}
}

void Start()
{
	std::cout << "\n\n\n\n\nVoyage Market\n\n\n\n";
	std::string choose;
	if (Login())
	{
		if (currentStatus == userStatus[0])
		{
			while (true)
			{
				system("cls");
				std::cout << "Выберите склад\n1 - Готовый складб 2 - Создать новый склад\nВвод: ";
				GetLine(choose);
				if (choose == "1")
				{
					if (isStorageCreated == false)
					{
						CreateStorage();
					}

					ShowSuperAdminMenu();
				}
				else if (choose == "2")
				{
					if (isStorageCreated == false)
					{

					}
					// создать новый склад
				}
			}
			CreateStorage();
			// Открытие + создание склада
		}
		else if (currentStatus == userStatus[1])
		{
			CreateStorage();
			// Открытие + создание склада
		}
		else if (currentStatus == userStatus[2])
		{
			CreateStorage();
			// Открытие + создание склада
		}
	}
	else
	{
		system("cls");
		std::cout << "Завершения работы программы" << std::endl << std::endl;
	}
}

bool Login()
{
	std::string login, pass;

	while (true)
	{
		std::cout << "Введите логин: ";
		GetLine(login);
		std::cout << "Введите пароль: ";
		GetLine(pass);
		if (login == "exit" && pass == "exit")
		{
			currentStatus = "";
			return false;
		}
		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::cout << "Пользователь: " << loginArr[i] << "\n\nДобро пожаловать!\n\n";
				std::cout << "Ваш статус: " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				currentId = 0;
				return true;
			}
		}

	}
}

inline void GetLine(std::string& str)
{
	std::getline(std::cin, str, '\n');
}

inline void Err(int time)
{
	std::cout << "Некоректный ввод" << std::endl << std::endl;
	Sleep(time);
	system("cls");
}

template<typename ArrType>
void FillArr(ArrType* dynArr, ArrType* staticArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		dynArr[i] = staticArr[i];
	}
}
