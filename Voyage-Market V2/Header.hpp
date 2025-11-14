#ifndef HEADER_HPP
#define HEADER_HPP


#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>

void CreateStorage();
void ShowStorage(int mode = 0);
void ShowSuperAdminMenu();
void AddStorageItem();
void RemoveStorageItem();
void ChangeStoragePrice();

bool IsNumber(const std::string& str);
void Start();
bool Login();
inline void GetLine(std::string& str);
inline void Err(int time = 1500);

template<typename ArrType>
void FillArr(ArrType* dynArr, ArrType* staticArr, size_t arrSize);
#endif // !HEADER_HPP