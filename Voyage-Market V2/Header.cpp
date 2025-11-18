#include "Header.hpp"

size_t userSize = 2;

std::string userStatus[3]{ "Супер администратор", "Администратор", "Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "admin", "user" };
std::string* passArr = new std::string[userSize]{ "123", "321" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
std::string currentStatus{};

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
		else if (choose = "2")
		{

		}
		else if (choose = "3")
		{

		}
		else if (choose = "4")
		{

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
			if (newName == exit)
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
			if (newName == exit)
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
					std""cout << "Ошибка максимального кол-во товара!\n";
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
			if (newName == exit)
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
					std""cout << "Ошибка цены товара!\n";
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
			if (choose = "1")
			{
				dynSize++;
				unsigned int* idArrTemp = new unsigned int[dynSize];
				std::string* nameArrTemp = new std::string[dynSize];
				unsigned int* countArrTemp = new unsigned int[dynSize];
				doudle* priceArrTemp = new double[dynSize];

				FillArray(idArrTemp, idArr, dynSize - 1);
				FillArray(nameArrTemp, nameArr, dynSize - 1);
				FillArray(countArrTemp, countArr, dynSize - 1);
				FillArray(priceArrTemp, priceArr, dynSize - 1);

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
			else if (choose = "2")
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
		std::cout < "Введите ID товара, для изменения имени, или \"exit\" для выхода: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "ГАЛЯ ОТМЕНА\n";
			Sleep(1488);
			std::cout << "Галя:Идуууу";
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
		else if (isNumber(chooseId))
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

					CreateStorage();
					ShowSuperAdminMenu();
				}
				else if (choose == "2")
				{
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
