#include <iostream>
#include <string>
using namespace std;
struct qlhs
{
	string mahs, hoten;
	int diem;
};
struct node
{
	qlhs data;
	node *next;
};
struct list 
{
	node *dau = NULL;
	node *duoi = NULL;
};

node *taonode(string a, string b, int c)
{
    node *p = new node;
    p -> data.mahs = a;
    p -> data.hoten = b;
	p -> data.diem = c;
    p -> next = NULL;
    return p;
}

void chendau(list &l, node *p)
{
	if(l.dau == NULL)
	{
		l.dau = p;
	}
	else
	{
		p -> next = l.dau;
		l.dau = p;
	}
}

void in(node *p)
{
	cout << "\tDanh sach da nhap: " << endl;
	while(p != NULL)
	{
		cout << "Ma hoc sinh: " << p -> data.mahs << endl;
		cout << "Ho ten: " << p -> data.hoten << endl;
		cout << "Diem: " << p -> data.diem << endl;
		p = p -> next;
	}
}
void themcuoi(node *p, list l, string a, string b, int c)
{
	p = new node;
	p -> data.mahs = a;
	p -> data.hoten = b;
	p -> data.diem = c;
	p -> next = NULL;
	node *last = l.dau;
	while(last -> next != NULL)
	{
		last = last -> next;
	}
	last -> next = p;
}
// void sapxep(list l)
// {
	
// 	int t;
// 	for(node *i = l.dau; i != NULL; i = i -> next)
// 	{
// 		for(node *j = l.dau -> next; j != NULL; j = j -> next)
// 		{
// 			if(i -> data.diem > j -> data.diem)
// 			{
// 				t = i -> data.diem;
// 				i -> data.diem = j -> data.diem;
// 				j -> data.diem = t;		
// 			}
// 		}
// 	}
// }

void sapxep(list &l)
{
    if (l.dau == NULL) return; // danh sách rỗng
    bool swapped;
    node *ptr1;
    node *lptr = NULL;
    do {
        swapped = false;
        ptr1 = l.dau;
        while (ptr1->next != lptr) {
            if (ptr1->data.diem > ptr1->next->data.diem) {
                // hoán đổi giá trị của hai nút
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void find(list l, string hoten)
{
	node *ptr = l.dau;
	while (ptr != NULL)
	{
		if (ptr -> data.hoten == hoten)
		{
			cout << "Thong tin hoc sinh can tim la: \n";
			cout << ptr -> data.hoten << endl << ptr -> data.mahs << endl << ptr -> data.diem << endl;
		}
		ptr = ptr->next;
	}
	
}
int main()
{
	list l;
	string mahs, hoten;
	int diem;
	node *p;
	while(true)
	{
		cout << "Nhap ma hoc sinh: ";
		getline(cin, mahs);
		if(mahs.length() != 0)
		{
			cout << "Nhap ho va ten: ";
			getline(cin, hoten);
			cout << "Nhap diem: ";	
			cin >> diem;
			cin.ignore();
		}
		else
			break;
		p = taonode(mahs, hoten, diem);	
		chendau(l, p);		
	}
	node *inn = l.dau;
	node *insert = l.dau;
	string a, b;
	int c;
	cout << "Nhap ma hoc sinh bo sung: ";
	getline(cin, a);
	cout << "Nhap ten hoc sinh bo sung: ";
	getline(cin, b);
	cout << "Nhap diem bo sung: ";
	cin >> c;
	cin.ignore();
	themcuoi(p, l, a, b, c);
	sapxep(l);
	in(inn);
	cout << "Nhap ten hoc sinh can tim: ";
	string hotenCantim;
	getline(cin, hotenCantim);
	find(l, hotenCantim);
}