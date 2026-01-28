#ifndef HEADER_HPP
#define HEADER_HPP


#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>
#include <unordered_set>

extern size_t userSize;
extern size_t staffCount;
extern std::string userStatus[3];
extern std::string* loginArr;
extern std::string* passArr;
extern std::string* statusArr;
extern double* bonusArr;
extern unsigned int* userIdArr;
extern unsigned int currentId;
extern std::string currentStatus;
extern std::unordered_set<char> loginSymbols;
extern std::unordered_set<char> passSymbols;
extern bool isLoginSetCreated;
extern bool isPassSetCreated;
extern size_t checkSize;
extern int* idArrCheck;
extern std::string* nameArrCheck;
extern unsigned int* countArrCheck;
extern double* priceArrCheck;
extern double* totalPriceArrCheck;
extern double cashIncome;
extern double bankIncome;
extern double cash;
extern bool comboskidka;
extern bool moneySkidka;

extern size_t dynSize;

extern unsigned int* idArr;
extern std::string* nameArr;
extern unsigned int* countArr;
extern double* priceArr;

extern bool isStorageCreated;

void CreateStorage();
void BuildStorage();
void ShowStorage(int mode = 0);
void ShowSuperAdminMenu();
void ShowAdminMenu();
void ShowUserMenu();
void AddStorageItem();
void RemoveStorageItem();
void ChangeStoragePrice();
void ChangeStorage();
void AddNewItem();
void ChangeName();
void DeleteItem();
void ChangeUser();

bool Logout();

void AddNewUser();
void ChangePass();
void ShowUsers(int mode = 0);
void DeleteUser();
void SetLoginSymbols();
void SetPassSymbols();

bool CheckLogin(const std::string &str);
bool CheckPass(const std::string& str);

void Selling();
void PrintCheck(double &totalSum);
void StorageReturner();
void CheckArrAppend();
void End();
void CheckSkidki(double &totalSum);
void ShowIncome();


bool IsNumber(const std::string& str);
void Start();
bool Login();
inline void GetLine(std::string& str);
inline void Err(int time = 1500);

template<typename ArrType>
void FillArr(ArrType* dynArr, ArrType* staticArr, size_t arrSize);

#endif // !HEADER_HPP