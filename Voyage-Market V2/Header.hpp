#ifndef HEADER_HPP
#define HEADER_HPP


#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>
#include <unordered_set>
	
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