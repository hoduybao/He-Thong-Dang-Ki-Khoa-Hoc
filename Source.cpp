#include"Header.h"
void gotoXY(int pX, int pY) {
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void List_Acount_Empty_Staff(List_Acount_Staff& l)
{
	l.Head = NULL;
	l.Tail = NULL;
}
void List_Acount_Empty_Student(List_Acount_Student& l)
{
	l.Head = NULL;
	l.Tail = NULL;

}
Node* CreateNode(Acount x)
{
	Node* p = new Node;
	p->a = x;
	p->Next = NULL;
	return p;
}
void Add_Tail_Staff(List_Acount_Staff& l, Node* p)
{
	if (l.Head == NULL)
	{
		l.Head = p;
		l.Tail = p;
	}
	else {
		l.Tail->Next = p;
		l.Tail = p;
	}

}
void Add_Tail_Student(List_Acount_Student& l, Node* p)
{
	if (l.Head == NULL)
	{
		l.Head = p;
		l.Tail = p;
	}
	else {
		l.Tail->Next = p;
		l.Tail = p;
	}

}
void ReadfileAcount_Staff(List_Acount_Staff& l)
{
	
	ifstream myfile;
	myfile.open("AcountStaff.txt", ios_base::in);
	while (!myfile.eof())
	{
		Acount x;
		getline(myfile, x.name, ',');
		getline(myfile, x.pass,'\n');
		Node* p = CreateNode(x);
		Add_Tail_Staff(l, p);
	}

	

}
void ReadfileAcount_Student(List_Acount_Student& l)
{
	ifstream myfile;
	myfile.open("AcountStudent.txt", ios_base::in);
	while (!myfile.eof())
	{
		Acount x;
		getline(myfile, x.name, ',');
		getline(myfile, x.pass, '\n');
		Node* p = CreateNode(x);
		Add_Tail_Student(l, p);
	}

}


bool Login_Staff(List_Acount_Staff& l,Acount x)
{
	bool kt = false;
		Node* temp = l.Head;
		while (temp != NULL)
		{
			if (temp->a.name == x.name && temp->a.pass == x.pass)
			{
				kt = true;
				break;
			}
			temp = temp->Next;
		}
	
	
     return kt;

}
bool Login_Student(List_Acount_Student& l, Acount x)
{
	bool kt = false;
	Node* temp = l.Head;
	while (temp != NULL)
	{
		if (temp->a.name == x.name && temp->a.pass == x.pass)
		{
			kt = true;
			break;
		}
		temp = temp->Next;
	}


	return kt;
}


void txtColor(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
/*void selectMenu_InPutLogin_Staff(int choose,List_Acount_Staff l) {
	int kt = 0;
	while (kt==0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;

			Menu_InPutLogin(choose, l);
		}
		if (move == 'A')
		{
			kt = 1;
			system("cls");
			processMenu(choose,l);
		}
	}

}*/
void selectMenu_InPutLogin(int choose,List_Acount_Staff l1, List_Acount_Student l2) {
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;

			Menu_InPutLogin(choose, l1,l2);
		}
		if (move == 'A')
		{
			kt = 1;
			system("cls");
			processMenu(choose, l1,l2);
		}
	}

}

void Menu_InPutLogin(int choose, List_Acount_Staff& l1,List_Acount_Student& l2)
{
		system("cls");
		Acount x;
		txtColor(14);
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t\t\t\tWELCOME TO THE SUBJECT REGISTRATION SYSTEM" << endl;
		txtColor(11);
		cout << "\t\t\t\t\t******************************************" << endl;
		txtColor(11);
		cout << "\t\t\t\t\t\t        ";
		txtColor(11);
		
		cout << "Name:";
		
		txtColor(15);
		getline(cin, x.name);
		txtColor(11);
		cout << "\t\t\t\t\t\t        Pass:";
		txtColor(15);
		cin >> x.pass;
		cin.ignore();
		txtColor(11);
		cout << "\t\t\t\t\t******************************************" << endl;
		if (choose == 1)
		{
			if (Login_Staff(l1, x))
			{
				exit(0);
			}
			else {
				gotoXY(22, 21);
				txtColor(12);
				cout << "Account or password is not wrong!!Press A to back or Press EnTer to login again" << endl;
				selectMenu_InPutLogin(choose, l1,l2);

			}
		}
		else {
			if (Login_Student(l2, x))
			{
				exit(0);
			}
			else {
				gotoXY(22, 21);
				txtColor(12);
				cout << "Account or password is not wrong!!Press A to back or Press EnTer to login again" << endl;
				selectMenu_InPutLogin(choose, l1,l2);

			}
		}
		



	


	

	
}
void printMenu(int selection)
{
	switch (selection)
	{
	case 1:
		gotoXY(52, 19);
		txtColor(11);
		cout << "I AM A STUDENT";
		gotoXY(52, 18);
		txtColor(12);
		cout << "I AM A CLASSROOM STAFF";
		gotoXY(0, 20);
		break;
	case 2:
		gotoXY(52, 18);
		txtColor(11);
		cout << "I AM A CLASSROOM STAFF";
		gotoXY(52, 19);
		txtColor(12);
		cout << "I AM A STUDENT";
		gotoXY(0, 20);
		break;

	}
}

int selectMenu()
{
	int selection = 1;
	int choose = 0;
	while (1)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			switch (selection)
			{
			case 1:
				selection++;
				break;
			case 2:
				selection = 1;
				break;
			}
			printMenu(selection);

		}
		if (move == 'W' || move == 72)
		{
			switch (selection)
			{
			case 1:
				selection = 2;
				break;
			case 2: 
				selection--;
				break;
			}
			printMenu(selection);
		}
		if (move == 13)
			return selection;
	}
}

void selectMenu_Login(int choose, List_Acount_Staff l1,List_Acount_Student l2) {
	
	int kt = 0;
	while (kt==0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 'A')
		{
			kt = 1;
			Menu(l1,l2);
		}
		if (move == 13)
		{
			kt = 1;
			Menu_InPutLogin(choose, l1,l2);
		}
			
		
	}

}
void processMenu(int choose,List_Acount_Staff& l1,List_Acount_Student& l2)
{
	switch (choose)
	{
	case 1:
		system("cls");
		txtColor(14);
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t\t\t\tWELCOME TO THE SUBJECT REGISTRATION SYSTEM" << endl;
		txtColor(11);
		cout << "\t\t\t\t\t******************************************" << endl;
		txtColor(11);
		cout << "\t\t\t\t\t*\t          ";
		txtColor(12);
		cout << "LOGIN";
		txtColor(11);
		cout << "                  *" << endl;
		txtColor(11);
		cout << "\t\t\t\t\t*\t                                 *" << endl;
		cout << "\t\t\t\t\t******************************************" << endl;
		selectMenu_Login(choose, l1,l2);
	case 2:
	{

		system("cls");
		txtColor(14);
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t\t\t\tWELCOME TO THE SUBJECT REGISTRATION SYSTEM" << endl;
		txtColor(11);
		cout << "\t\t\t\t\t******************************************" << endl;
		txtColor(11);
		cout << "\t\t\t\t\t*\t          ";
		txtColor(12);
		cout << "LOGIN";
		txtColor(11);
		cout << "                  *" << endl;
		txtColor(11);
		cout << "\t\t\t\t\t*\t                                 *" << endl;
		cout << "\t\t\t\t\t******************************************" << endl;
		selectMenu_Login(choose, l1,l2);


	}
	}
}











