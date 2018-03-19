#include <iostream>
using namespace std;

struct SP {
	int ID;
	int price;
	char nuocSx;
};

struct Node {
	SP info;
	Node *Pnext;
};

struct List {
	Node *Phead;
	Node *Ptail;
};

void creatList(List &l){
	l.Phead = l.Ptail = NULL;
}

Node *CreateNode(SP sp) {
	Node *p;
	if (p) {
		p->info.ID = sp.ID;
		p->info.nuocSx = sp.nuocSx;
		p->info.price = sp.price;
		p->Pnext = NULL;
	}
	return p;
}

void addtail(List &l, Node *p) {
	if (!l.Phead) {
		l.Phead = l.Ptail = p;
	}
	else {
		l.Ptail->Pnext = p;
		l.Ptail = p;
	}
}

void inputList(List &l) {
	int n;
	cout << "nhap n : ";
	cin >> n;
	Node *p;
	SP sp;
	for (int  i = 0; i < n; i++)
	{
		cout << "Nhap thong tin san pham thu " << i + 1 << endl;
		cout << "Nhap ID : "; cin >> sp.ID;
		cout << "Nhap gia sp : "; cin >> sp.price;
		cout << "Nhap nuoc sx : "; cin >> sp.nuocSx;
		p = CreateNode(sp);
		addtail(l,p);
	}
}

void PrintList(List l) {
	int i = 1;
	if (l.Phead) {
		for (Node *p = l.Phead; p != NULL; p=p->Pnext) {
			cout << "San pham " << i << endl;
			cout << "ID cua san pham la : " << p->info.ID << endl;
			cout << "Gia cua san pham la : " << p->info.price << endl;
			cout << "Nuoc san xuat : " << p->info.nuocSx << endl;
			cout << "-----------------------------------------" << endl;
		}
	}
	else
		cout << "List rong!" << endl;
}

void timGiaCaoNhat(List l) {
	if (l.Phead) {
		SP temp;
		int max = l.Phead->info.price;
		temp.ID = l.Phead->info.ID;
		temp.nuocSx = l.Phead->info.nuocSx;
		temp.price = l.Phead->info.price;
		for (Node *p = l.Phead; p != NULL;p= p->Pnext) {
			if (p->info.price > max) {
				max = p->info.price;
				temp.ID = p->info.ID;
				temp.nuocSx = p->info.nuocSx;
				temp.price = p->info.price;
			}
		}
		cout << "San pham co gia cao nhat la : ";
		cout << "ID : " << temp.ID << endl;
		cout << "Nuoc sx : " << temp.nuocSx << endl;
		cout << "Gia : " << temp.price << endl;
	}
	else {
		cout << "ham rong";
	}
}

void ThongKeNuocSx(List l) {
	if (l.Phead) {
		cout << "San pham sx o Viet Nam : " << endl;
		for (Node *p = l.Phead; p != NULL; p = p->Pnext) {
			if (p->info.nuocSx == 'v') {
				cout << "ID : " << p->info.ID << endl;
				cout << "Nuoc sx : " << p->info.nuocSx << endl;
				cout << "Gia : " << p->info.price << endl;
			}
		}
		cout << "-----------------------------------------" << endl;
		cout << "San pham sx o Han quoc : " << endl;
		for (Node *p = l.Phead; p != NULL; p = p->Pnext) {
			if (p->info.nuocSx == 'k') {
				cout << "ID : " << p->info.ID << endl;
				cout << "Nuoc sx : " << p->info.nuocSx << endl;
				cout << "Gia : " << p->info.price << endl;
			}
		}
		cout << "-----------------------------------------" << endl;
		cout << "San pham sx o My : " << endl;
		for (Node *p = l.Phead; p != NULL; p = p->Pnext) {
			if (p->info.nuocSx == 'a') {
				cout << "ID : " << p->info.ID << endl;
				cout << "Nuoc sx : " << p->info.nuocSx << endl;
				cout << "Gia : " << p->info.price << endl;
			}
		}
	}
	else
		cout << "List rong" << endl;
}

void swap(Node *p, Node *q) {
	SP temp;
	temp.ID = p->info.ID;
	temp.nuocSx = p->info.nuocSx;
	temp.price = p->info.price;
	p->info.ID = q->info.ID;
	p->info.nuocSx = q->info.nuocSx;
	p->info.price = q->info.price;
	q->info.ID = temp.ID;
	q->info.nuocSx = temp.nuocSx;
	q->info.price = temp.price;
}

void Sort(List &l) {
	if (l.Phead) {
		for (Node *p = l.Phead; p != NULL; p = p->Pnext) {
			for (Node *q = p->Pnext; q != NULL; q = q->Pnext) {
				if (p->info.ID < q->info.ID)
					swap(p, q);
			}
		}
	}
}
int main()
{
	int menu;
	List list1;
	creatList(list1);
	inputList(list1);
	system("cls");
	do {
		cout << "nhan so 0 de thoat " << endl;
		cout << "nhan so 1 de xuat ds ra man hinh " << endl;
		cout << "nhan so 2 de tim san pham co gia cao nhat " << endl;
		cout << "nhan so 3 de thong ke san pham theo nuoc san xuat " << endl;
		cout << "nhan so 4 de sap xep san pham theo ID (giam dan)" << endl;
		cin.ignore();
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:PrintList(list1); break;
		case 2:timGiaCaoNhat(list1); break;
		case 3:ThongKeNuocSx(list1); break;
		case 4:Sort(list1);
					 PrintList(list1); break;
		default:cout << "khong co phuong thuc phu hop!" << endl;
			break;
		}
	} while (menu != 0);
    return 0;
}

