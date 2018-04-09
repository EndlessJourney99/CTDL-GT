#include <iostream>
using namespace std;

struct TNode {
	int key;
	TNode *left;
	TNode *right;
};

typedef TNode *Tree;

void createTree(Tree &t) {
	t = NULL;
}

Tree createTNode(int x) {
	Tree p = new TNode;
	if (!p)
		exit(1);
	p->key = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void insertTNode(Tree &t, int x) {
	Tree p = createTNode(x);
	if (t == NULL)
		t = p;
	else {
		Tree q, f;
		q = t;
		f = NULL;
		while (q) {
			f = q;
			if (x == q->key)
				return;
			if (x < q->key)
				q = q->left;
			else
				q = q->right;
		}
		if (x < f->key)
			f->left = p;
		else
			f->right = p;
	}
}

void inputTree(Tree &t) {
	int key[13] = { 60,40,80,20,50,70,100,30,90,25,35,85,95 };
	for (int i = 0; i < 13; i++)
	{
		insertTNode(t, key[i]);
	}
}

void LNR(Tree t) {
	if (t) {
		LNR(t->left);
		cout << t->key<<" ";
		LNR(t->right);
	}
}

void LRN(Tree t) {
	if (t) {
		LNR(t->left);
		LNR(t->right);
		cout << t->key<<" ";
	}
}

void NLR(Tree t) {
	if (t) {
		cout << t->key<<" ";
		LNR(t->left);
		LNR(t->right);
	}
}

void CNode2con(Tree t, int &counting) {
	if (t) {
		CNode2con(t->left,counting);
		if (t->left != NULL && t->right != NULL)
			counting++;
		CNode2con(t->right,counting);
	}
}

void CNode1con(Tree t, int &counting) {
	if (t) {
		CNode1con(t->left,counting);
		CNode1con(t->right,counting);
		if (t->left == NULL && t->right != NULL || t->left != NULL && t->right == NULL)
			counting++;
	}
}

void CNodeLa(Tree t,int &counting) {
	if (t) {
		if (t->left == NULL && t->right == NULL)
			counting++;
		CNodeLa(t->left, counting);
		CNodeLa(t->right, counting);
	}
}

void demNodeLa(Tree t){
	int counting = 0;
	CNodeLa(t, counting);
	cout << "so luong node la = " << counting << endl;
}

void demNode1con(Tree t) {
	int counting = 0;
	CNode1con(t, counting);
	cout << "so luong node 1 con = " << counting << endl;
}

void demNode2con(Tree t) {
	int counting = 0;
	CNode2con(t, counting);
	cout << "so luong node 2 con = " << counting << endl;
}

void PrintLeaf(Tree t) {
	if (t) {
		if (t->left == NULL && t->right == NULL)
			cout << t->key << " ";
		PrintLeaf(t->left);
		PrintLeaf(t->right);
	}
}

void Print1Con(Tree t) {
	if (t) {
		Print1Con(t->left);
		Print1Con(t->right);
		if (t->left == NULL && t->right != NULL || t->left != NULL && t->right == NULL)
			cout << t->key << " ";
	}
}

void Print2Con(Tree t) {
	if (t) {
		Print2Con(t->left);
		if (t->left != NULL && t->right != NULL)
			cout << t->key << " ";
		Print2Con(t->right);
	}
}

void GTNodeLa(Tree t, int &gt) {
	if (t) {
		GTNodeLa(t->left, gt);
		if (t->left == NULL && t->right == NULL)
			gt += t->key;
		GTNodeLa(t->right, gt);
	}
}

void TongGTNodela(Tree t) {
	int gt = 0;
	GTNodeLa(t, gt);
	cout << "Tong gia tri cua node la = " << gt << endl;
}

void GTNode1(Tree t, int &gt) {
	if (t) {
		GTNode1(t->left,gt);
		GTNode1(t->right,gt);
		if (t->left == NULL && t->right != NULL || t->left != NULL && t->right == NULL)
			gt += t->key;
	}
}

void TongGtNode1(Tree t) {
	int gt = 0;
	GTNode1(t, gt);
	cout << "Tong gia tri cua node 1 con = " << gt << endl;
}

void GTNode2(Tree t, int &gt) {
	if (t) {
		GTNode2(t->left, gt);
		if (t->left != NULL && t->right != NULL)
			gt += t->key;
		GTNode2(t->right,gt);
	}
}

void TongGtNode2(Tree t) {
	int gt = 0;
	GTNode2(t, gt);
	cout << "Tong gia tri node 2 con = " << gt << endl;
}
int main()
{
	Tree tree;
	createTree(tree);
	int menu;
	do
	{
		cout << "Nhap 0 de thoat chuong trinh" << endl;
		cout << "Nhap 1 de tao n node cho cay" << endl;
		cout << "Nhap 2 de duyet cay bang LNR" << endl;
		cout << "Nhap 3 de duyet cay bang LRN" << endl;
		cout << "Nhap 4 de duyet cay bang NLR" << endl;
		cout << "Nhap 5 de liet ke cac node la" << endl;
		cout << "Nhap 6 de liet ke cac node co 1 con" << endl;
		cout << "Nhap 7 de liet ke cac node co 2 con" << endl;
		cout << "Nhap 8 de dem so luong node la" << endl;
		cout << "Nhap 9 de dem so luong node co 1 con" << endl;
		cout << "Nhap 10 de dem so luong node co 2 con" << endl;
		cout << "Nhap 11 de tinh tong gia tri cac node la" << endl;
		cout << "Nhap 12 de tinh tong gia tri cac node co 1 con" << endl;
		cout << "Nhap 13 de tinh tong gia tri cac node co 2 con" << endl;
		cin >> menu;
		system("cls");
		switch (menu)
		{
			case 0:break;
			case 1:inputTree(tree); break;
			case 2:LNR(tree); cout << endl; break;
			case 3:LRN(tree); cout << endl; break;
			case 4:NLR(tree); cout << endl; break;
			case 5:cout << "Cac node la gom : "; PrintLeaf(tree);
				cout << endl; break;
			case 6:cout << "Cac node co 1 con gom : "; Print1Con(tree);
				cout << endl; break;
			case 7:cout << "Cac node co 2 con gom : "; Print2Con(tree);
				cout << endl; break;
			case 8:demNodeLa(tree); break;
			case 9:demNode1con(tree); break;
			case 10:demNode2con(tree); break;
			case 11:TongGTNodela(tree); break;
			case 12:TongGtNode1(tree); break;
			case 13:TongGtNode2(tree); break;
			default:cout << "khong co trong menu " << endl;
				break;
		}
	} while (menu != 0);

	return 1;
}
