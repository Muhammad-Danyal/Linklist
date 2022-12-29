//Programmer Name: Muhammad Danyal
//Reg.NO:4304-BSSE-F21-B
// in this program i am doing marks management by using linklist by structral approch.
#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
void deletion(node*& FIRST, int& s) {
	if (FIRST == NULL) {
		return;
	}
	node* CUR = FIRST;
	while (CUR->next->data != s) {
		CUR = CUR->next;
	}
	node* todelete = CUR->next;
	CUR->next = CUR->next->next;
	delete todelete;
}
void deletefirst(node*& FIRST) {
	node* todelete = FIRST;
	FIRST = FIRST->next;
	delete todelete;
}
int main() {
	int choice, sum = 0, n = 0, s, temp = 0;
	float avg;
	char q;
	bool found = false;
	node* CUR = NULL;
	node* PREV = NULL;
	node* FIRST = NULL;
	while (true) {
		cout << "_____MAIN MENU______" << endl;
		cout << " 1.Create linklist " << endl;
		cout << " 2.Display linklist" << endl;
		cout << " 3.Search " << endl;
		cout << " 4.Deletion " << endl;
		cout << " 5.Updation " << endl;
		cout << " 6.Insertion " << endl;
		cout << " 7.Sorting " << endl;
		cout << " 8.class average" << endl;
		cout << " 9.Exit" << endl;
		cout << "What you want to do? \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "--------------create linklist--------------\n";
			do {
				CUR = new node;
				CUR->next = NULL;
				cout << "Enter Marks:";
				cin >> CUR->data;
				if (FIRST == NULL)
					FIRST = PREV = CUR;
				else {
					PREV->next = CUR;
					PREV = CUR;
				}
				cout << "Did you want to do entry?(y for yes/n for no)" << endl;
				cin >> q;
			} while (q == 'y');
			break;
		case 2:
			system("cls");
			cout << "--------------Display linklist--------------\n";
			CUR = FIRST;
			while (CUR != NULL) {
				cout << "Marks:" << CUR->data << endl;
				CUR = CUR->next;
			}
			break;
		case 3:
			system("cls");
			cout << "--------------search--------------\n";
			cout << "Enter the marks you want to search:";
			cin >> s;
			CUR = FIRST;
			while (CUR) {
				if (s == CUR->data) {
					cout << "Marks found" << endl;
					found = true;
				}
				CUR = CUR->next;
			}
			if (!found) {
				cout << "Not Found" << endl;
			}
			break;
		case 4:
			system("cls");
			cout << "--------------Deletion--------------\n";
			cout << "what you want to do:" << endl;
			cout << "1.Delete element of without first.\n";
			cout << "2.Delete first element.\n";
			cin >> choice;
			if (choice == 1) {
				cout << "Enter the marks you want to delete:";
				cin >> s;
				deletion(FIRST, s);
				cout << "sucessfully deleted" << endl;
			}
			if (choice == 2) {
				deletefirst(FIRST);
				cout << "sucessfully deleted the first node" << endl;
			}
			break;
		case 5:
			system("cls");
			cout << "--------------Updation--------------\n";
			cout << "Enter the marks you want to update:";
			cin >> s;
			CUR = FIRST;
			while (CUR != NULL) {
				if (CUR->data == s) {
					cout << "Enter Marks:";
					cin >> CUR->data;
				}
				CUR = CUR->next;
			}
			break;
		case 6:
			system("cls");
			cout << "--------------Insertion--------------\n";
			cout << "What you wan to do? \n";
			cout << "1.Insert at tail.\n";
			cout << "2.Insert at head.\n";
			cin >> choice;
			if (choice == 1) {
				node* mnode = new node;
				cout << "Enter marks:";
				cin >> mnode->data;
				CUR = FIRST;
				while (CUR->next != NULL) {
					CUR = CUR->next;
				}
				CUR->next = mnode;
				mnode->next = NULL;
			}
			if (choice == 2) {
				node* mnode = new node;
				cout << "Enter marks:";
				cin >> mnode->data;
				mnode->next = FIRST;
				FIRST = mnode;
			}
			break;
		case 7:
			system("cls");
			cout << "--------------Sorting--------------\n";
			for (int i = 0; i < 20; i++) {
				PREV = FIRST;
				CUR = FIRST->next;
				while (CUR != NULL) {
					if (PREV->data > CUR->data) {
						temp = CUR->data;
						CUR->data = PREV->data;
						PREV->data = temp;
					}
					PREV = PREV->next;
					CUR = CUR->next;
				}
			}
			cout << "Data sorted successfully \n";
			break;
		case 8:
			system("cls");
			cout << "--------------class average--------------\n";
			CUR = FIRST;
			while (CUR != NULL) {
				sum += CUR->data;
				++n;
				CUR = CUR->next;
			}
			avg = static_cast<float>(sum) / n;
			cout << "Average:" << avg << endl;
			break;
		case 9:
			exit(0);
		default:
			cout << "Enter a valid input.\n";
			break;
		}
	}
}