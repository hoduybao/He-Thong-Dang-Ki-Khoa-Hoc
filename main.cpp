#include "Header.h"
void Menu(List_Acount_Staff& l1,List_Acount_Student& l2)
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
	cout << "\t\t\t\t\t*\t    ";
	txtColor(12);
	cout << "I AM A CLASSROOM STAFF";
	txtColor(11);
	cout << "       *" << endl;
	txtColor(11);
	cout << "\t\t\t\t\t*\t    I AM A STUDENT               *" << endl;
	cout << "\t\t\t\t\t******************************************" << endl;
	int x = selectMenu();
	processMenu(x,l1,l2);

}
int main()
{
	List_Acount_Staff l1;
	List_Acount_Empty_Staff(l1);
	ReadfileAcount_Staff(l1);
	List_Acount_Student l2;
	List_Acount_Empty_Student(l2);
	ReadfileAcount_Student(l2);

	Menu(l1,l2);
	return 0;
}