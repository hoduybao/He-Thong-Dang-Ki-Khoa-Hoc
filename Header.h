#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
struct Acount
{
	string name;
	string pass;

};
struct Node
{
	Acount a;
	Node* Next;
};
struct List_Acount_Staff
{
	Node* Head;
	Node *Tail;
};
struct List_Acount_Student
{
	Node* Head;
	Node* Tail;
};
void Menu(List_Acount_Staff& l1, List_Acount_Student& l2);
int selectMenu();
void processMenu(int choose, List_Acount_Staff& l1, List_Acount_Student& l2);
void selectMenu_Login(int choose, List_Acount_Staff l1, List_Acount_Student l2);
void printMenu(int selection);
void Menu_InPutLogin(int choose, List_Acount_Staff& l1, List_Acount_Student& l2);
void selectMenu_InPutLogin(int choose, List_Acount_Staff l1, List_Acount_Student l2);
void txtColor(int i);
bool Login_Student(List_Acount_Student& l, Acount x);
bool Login_Staff(List_Acount_Staff& l, Acount x);
void ReadfileAcount_Student(List_Acount_Student& l);
void ReadfileAcount_Staff(List_Acount_Staff& l);
void Add_Tail_Student(List_Acount_Student& l, Node* p);
void Add_Tail_Staff(List_Acount_Staff& l, Node* p);
Node* CreateNode(Acount x);
void List_Acount_Empty_Student(List_Acount_Student& l);
void List_Acount_Empty_Staff(List_Acount_Staff& l);
void gotoXY(int pX, int pY);