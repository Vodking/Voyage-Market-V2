#include "Header.hpp"

size_t userSize = 2;

std::string userStatus[3]{ "Супер администратор", "Администратор", "Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "ad", "us" };
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
		"патом", "пaaатом",
		"патом", "паaaтом",
		"патом", "паaaтом",
		"патом", "паaaтом",
		"патом", "паaaтом"
	};
	unsigned int count[staticSize]{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	double price[staticSize]{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

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
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
		}
		system("pause");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название\t\t" << "Кол-во\t\n";
		for (size_t i = 0; i < dynSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\t";
		}
		system("pause");
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название\t\t" << "Цена\t\n";

		for (size_t i = 0; i < dynSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t\t" << priceArr[i] << "\n";
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

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

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
		GetLine(choose);
		if (choose == "exit")
		{
			std::cout << "Отмена операций пополнения товара!\n";
		}
		std::cout << "Введите кол-во товара для пополнения: ";
		GetLine(chooseCount);

		std::stoi(chooseCount);

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
