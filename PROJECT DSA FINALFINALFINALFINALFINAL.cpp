#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
#include<string>

using namespace std;

struct node{
	int id;
	int salary;
	char name[50];
	char qualification[30];
	char city[30];
	char address[50];
	char jobTitle[30];
	char date[30];
	node *prev;
	node *next;
};

void gotoxy(int x, int y){
	COORD c;
	c.X = x; c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void color(int a){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void Splash(){
	char c = 176;
	color(6);
	gotoxy(23,10);
	color(6);
	cout<<"Employee Managment System";
	gotoxy(30,12);
	cout<<"Loading....";
	gotoxy(27,14);
	for(int i=1; i<17; i++){
		Sleep(150);
		cout<<c;
	}
	Sleep(500);
	system("cls");
}
void drawRectangle(){
    char c[10]= {185, 186, 187, 188, 200, 201, 202, 203, 204, 205};
    gotoxy(0,0);
    cout<<c[5];
    for(int i = 1; i < 78; i++){
        gotoxy(i, 0);
        cout<<c[9];
    }
    gotoxy(78,0);
        cout<<c[2];
	    for(int i = 1; i < 25; i++){
        gotoxy(78, i);
        if(i == 6){
            cout<<c[0];
        }
		else{
            cout<<c[1];
        }
    }
    gotoxy(78, 25);
	cout<<c[3];
	for(int i = 77; i > 0; i--){
        gotoxy(i,25);
        if(i == 35){
            cout<<c[6];
        }
		else{
            cout<<c[9];
        }
    }
    gotoxy(0,25);
    cout<<c[4];
    for(int i = 24; i > 0; i--){
        gotoxy(0,i);
        if(i == 6){
            cout<<c[8];
        }
		else{
            cout<<c[1];
        }
    }
    for(int i = 1; i < 78; i++){
        gotoxy(i,6);
        if(i == 35){
            cout<<c[7];
        }
		else{
            cout<<c[9];
        }
    }
    for(int i = 7; i < 25; i++){
        gotoxy(35,i);
        cout<<c[1];
    }
    cout<<endl;
}

void clear(){
	color(0);
    int i,j;
    for(i = 37; i < 78; i++){
        for(j = 7; j < 25; j++){
            gotoxy(i,j);
            cout<<" ";
        }
    }
}
void header(){
	drawRectangle();
	system("color 04");
	color(4);
	gotoxy(23,2);
	cout<<"Employee Management System."<<endl;
	gotoxy(23,3);
	color(6);
	cout<<"Superior university Lahore.";
	color(15);
	gotoxy(19,4);
	cout<<"Roll No BSEM-F18-(002-007-039-049).";
}

node *head = NULL;

bool search(int x) {
	node* temp = new node;
	temp = head;
    while (temp != NULL){  
        if (temp->id == x){
        	return false;
		}
        temp = temp->next;
    }
    return true;  
}

void menu(){
	color(96);
	gotoxy(15,7);
	cout<<"Menu";
	color(2);
	gotoxy(2,9);
	cout<<"1- Add record";
	gotoxy(2,11);
	cout<<"2- Search record";
	gotoxy(2,13);
	cout<<"3- Update record";
	gotoxy(2,15);
	cout<<"4- Delete record";
	gotoxy(2,17);
	cout<<"5- Display record";
	gotoxy(2,19);
	cout<<"6- Save Data";
	gotoxy(2,21);
	cout<<"7- Exit";
}

void add_first(){
	node *newer=new node;
	clear();
	color(96);
	gotoxy(50,7);
	cout<<"Add at beginning";
	color(2);
	gotoxy(37,9);
	cout<<"Employee ID: ";
	cin>>newer->id;
	fflush(stdin);
	if(search(newer->id)){
		gotoxy(37,11);
		cout<<"Name: ";
		cin.getline(newer->name,50);
		fflush(stdin);
		gotoxy(37,13);
		cout<<"Qualification: ";
		cin.getline(newer->qualification,30);
		fflush(stdin);
		gotoxy(37,15);
		cout<<"Address: ";
		cin.getline(newer->address,50);
		fflush(stdin);
		gotoxy(37,17);
		cout<<"City of stay: ";
		cin.getline(newer->city,30);
		fflush(stdin);
		gotoxy(37,19);
		cout<<"Job title: ";
		cin.getline(newer->jobTitle,50);
		fflush(stdin);
		gotoxy(37,21);
		cout<<"Salary: ";
		cin>>newer->salary;
		fflush(stdin);
		gotoxy(37,23);
		cout<<"Date of joining: ";
		cin.getline(newer->date,50);
		fflush(stdin);
		newer->prev=NULL;
		if(head!=NULL){
			newer->next=head;
			head->prev=newer;
		}else{
			newer->next=NULL;
		}
		head=newer;
		color(64);
		gotoxy(43,24);
		cout<<"Recorded added successfully"<<endl;
	}
	else{
		gotoxy(45, 15);
		color(64);
		cout<<"Id already exist.";
	}
	Sleep(1000);
	clear();
}

void add_last(){
	if(head==NULL){
		clear();
		color(96);
		gotoxy(50,7);
		cout<<"Add at the End";
		color(2);
		gotoxy(37,9);
		cout<<"List is empty."<<endl;
		gotoxy(37,11);
	}
	else{
		node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		clear();
		color(96);
		gotoxy(50,7);
		cout<<"Add at the End";
		color(2);
		gotoxy(37,9);
		node *newer=new node;
		cout<<"Employee ID: ";
		cin>>newer->id;
		fflush(stdin);
		if(search(newer->id)){
			gotoxy(37,11);
			cout<<"Name: ";
			cin.getline(newer->name,50);
			fflush(stdin);
			gotoxy(37,13);
			cout<<"Qualification: ";
			cin.getline(newer->qualification,30);
			fflush(stdin);
			gotoxy(37,15);
			cout<<"Address: ";
			cin.getline(newer->address,50);
			fflush(stdin);
			gotoxy(37,17);
			cout<<"City of stay: ";
			cin.getline(newer->city,30);
			fflush(stdin);
			gotoxy(37,19);
			cout<<"Job title: ";
			cin.getline(newer->jobTitle,50);
			fflush(stdin);
			gotoxy(37,21);
			cout<<"Salary: ";
			cin>>newer->salary;
			fflush(stdin);
			gotoxy(37,23);
			cout<<"Date of joining: ";
			cin.getline(newer->date,50);
			fflush(stdin);
			gotoxy(43,24);
			color(64);
			cout<<"Record added Sucessfully.";
			newer->prev=temp;
			temp->next=newer;
			newer->next=NULL;
		}
		else{
			gotoxy(45, 15);
			color(64);
			cout<<"Id already exist.";
		}
	}
	Sleep(1000);
	clear();
}
void add_after(){
	if(head==NULL){
		clear();
		color(96);
		gotoxy(50,7);
		cout<<"After some records";
		color(2);
		gotoxy(37,9);
		cout<<"List is empty"<<endl;
		gotoxy(37,11);
	}
	else{
		clear();
		color(96);
		gotoxy(50,7);
		cout<<"Add after some record";
		color(2);
		gotoxy(37,9);
		int value;
		cout<<"Enter key ID: ";
		cin>>value;
		bool flag = false;
		node *temp=head;
		node *p;
		while(temp!=NULL){
			if(temp->id==value){
				flag = true;
				node *newer=new node;
				clear();
				color(96);
				gotoxy(50,7);
				cout<<"After some records";
				color(2);
				gotoxy(37,9);
				cout<<"Employee ID: ";
				cin>>newer->id;
				fflush(stdin);
				if(search(newer->id)){
					gotoxy(37,11);
					cout<<"Name: ";
					cin.getline(newer->name,50);
					fflush(stdin);
					gotoxy(37,13);
					cout<<"Qualification: ";
					cin.getline(newer->qualification,30);
					fflush(stdin);
					gotoxy(37,15);
					cout<<"Address: ";
					cin.getline(newer->address,50);
					fflush(stdin);
					gotoxy(37,17);
					cout<<"City of stay: ";
					cin.getline(newer->city,30);
					fflush(stdin);
					gotoxy(37,19);
					cout<<"Job title: ";
					cin.getline(newer->jobTitle,50);
					fflush(stdin);
					gotoxy(37,21);
					cout<<"Salary: ";
					cin>>newer->salary;
					fflush(stdin);
					gotoxy(37,23);
					cout<<"Date of joining: ";
					cin.getline(newer->date,50);
					fflush(stdin);
					if(temp->next!=NULL){
						newer->next=temp->next;
						newer->prev=temp;
						p=temp->next;
						temp->next=newer;
						p->prev=newer;
					}
					else{
						newer->prev=temp;
						newer->next=NULL;
						temp->next=newer;
					}
					temp=temp->next;
					gotoxy(43,24);
					color(64);
					cout<<"Record added sucessfully.";
				}
				else{
					gotoxy(45, 15);
					color(64);
					cout<<"Id already exist.";
					goto a;
				}
			}	
		}
		if(flag==true){
			gotoxy(45,15);
			color(64);
			cout<<"ID not found";
		}
	}
	a: Sleep(1000);
	clear();
}
void add_before(){
	if(head==NULL){
		clear();
		color(96);
		gotoxy(47,7);
		cout<<"Before some records";
		gotoxy(37,9);
		cout<<"List is empty"<<endl;
	}
	else{
		clear();
		color(96);
		gotoxy(47,7);
		cout<<"Before some records";
		color(2);
		int value;
		gotoxy(37,9);
		cout<<"Enter key ID: ";
		cin>>value;
		bool flag=false;
		node *temp=head;
		node *p;
		while(temp!=NULL){
			if(temp->id==value){
				node *newer=new node;
				clear();
				flag=true;
				color(96);
				gotoxy(47,7);
				cout<<"Before some records";
				color(2);
				gotoxy(37,9);
				cout<<"Enter employee ID: ";
				cin>>newer->id;
				if(search(newer->id)){
					fflush(stdin);
					gotoxy(37,11);
					cout<<"Name: ";
					cin.getline(newer->name,50);
					fflush(stdin);
					gotoxy(37,13);
					cout<<"Qualification: ";
					cin.getline(newer->qualification,30);
					fflush(stdin);
					gotoxy(37,15);
					cout<<"Address: ";
					cin.getline(newer->address,50);
					fflush(stdin);
					gotoxy(37,17);
					cout<<"City of stay: ";
					cin.getline(newer->city,30);
					fflush(stdin);
					gotoxy(37,19);
					cout<<"Job title: ";
					cin.getline(newer->jobTitle,50);
					fflush(stdin);
					gotoxy(37,21);
					cout<<"Enter salary of employee: ";
					cin>>newer->salary;
					fflush(stdin);
					gotoxy(37,23);
					cout<<"Enter date of joining of employee: ";
					cin.getline(newer->date,50);
					fflush(stdin);
					if(temp->prev!=NULL){
						newer->prev=temp->prev;
						newer->next=temp;
						p=temp->prev;
						temp->prev=newer;
						p->next=newer;
					}
					else{
						newer->prev=NULL;
						newer->next=temp;
						temp->prev=newer;
					}
					color(64);
					gotoxy(43,24);
					color(64);
					cout<<"Record added sucessfully.";
				}
				else{
					gotoxy(45, 15);
					color(64);
					cout<<"Id already exist.";
					goto a1;
				}
			}
			temp=temp->next;
		}
		if(flag==false){
			color(64);
			gotoxy(45, 15);
			cout<<"ID not found"<<endl;
		}
	}
	a1:	Sleep(1000);
	clear();
}
void del(){
	if(head==NULL){
		clear();
		color(96);
		gotoxy(50,7);
		cout<<"Delete Record";
		color(2);
		gotoxy(37,9);
		cout<<"List is empty"<<endl;
	}
	else{
		clear();
		color(96);
		gotoxy(50,7);
		cout<<"Delete Record";
		color(2);
		gotoxy(37,9);
		int value;
		cout<<"Enter ID you want to delete: ";
		cin>>value;
		bool flag=false;
		node *temp=head;
		if(temp->id==value){
			head=temp->next;
			head->prev=NULL;
			delete temp;
			flag=true;
			if(flag==true){
				color(64);
				gotoxy(37,11);
				cout<<"Record has been successfully deleted"<<endl;
			}
		}
		else{
			while(temp!=NULL){
				if(temp->id==value){
					node *p;
					node *q;
					if(temp->next==NULL){
						p=temp->prev;
						p->next=NULL;
						delete temp;
						flag=true;
					}
					else{
						p=temp->prev;
						q=temp->next;
						p->next=q;
						q->prev=p;
						delete temp;
						flag=true;
					}
				}
				temp=temp->next;
			}
			if(flag==true){
				color(64);
				gotoxy(37,11);
				cout<<"Record has been successfully deleted"<<endl;
			}
		}
		if(flag==false){
			color(64);
			gotoxy(45, 15);
			cout<<"ID not found"<<endl;
		}
	}
	Sleep(1000);
	clear();
}
void display(){
	if(head==NULL){
		clear();
		color(96);
		gotoxy(50,7);
		cout<<"Display Record";
		color(2);
		gotoxy(37,9);
		cout<<"List is empty"<<endl;
	}
	else{
		node *temp=head;
		int i = 11;
		clear();
		color(96);
		gotoxy(50,7);
		cout<<"Display Record";
		gotoxy(37,9);
		cout<<"Information of employees"<<endl;
		color(2);
		while(temp!=NULL){
			gotoxy(37,i);
			cout<<"Name: "<<temp->name<<"\tID: "<<temp->id;
			temp=temp->next;
			i=i+2;
		}
		gotoxy(37,i);
		system("pause");
		clear();
	}
}
void search(){
	if(head==NULL){
		clear();
		color(96);
		gotoxy(50,7);
		cout<<"Search Record";
		color(2);
		gotoxy(37,9);
		cout<<"List is empty";
	}
	else{
		clear();
		color(96);
		gotoxy(50,7);
		cout<<"Search Record";
		color(2);
		gotoxy(37,9);
		int value;
		cout<<"Enter ID: ";
		cin>>value;
		node *temp=head;
		bool flag=false;
		while(temp!=NULL){
			if(temp->id==value){
				clear();
				color(96);
				gotoxy(50,7);
				cout<<"Search Record";
				color(64);
				gotoxy(50,9);
				cout<<"Match found";
				color(2);
				gotoxy(37,11);
				cout<<"ID: "<<temp->id;
				gotoxy(37,13);
				cout<<"Name: "<<temp->name;
				gotoxy(37,15);
				cout<<"Qualification: "<<temp->qualification;
				gotoxy(37,17);
				cout<<"Address: "<<temp->address;
				gotoxy(37,19);
				cout<<"City: "<<temp->city;
				gotoxy(37,21);
				cout<<"Job title: "<<temp->jobTitle;
				gotoxy(37,23);
				cout<<"Date of joining: "<<temp->date;
				flag=true;
				gotoxy(37,24);
				color(6);
				system("pause");
			}
			temp=temp->next;
		}
		if(flag==false){
			gotoxy(50,9);
			color(64);
			cout<<"ID not found"<<endl;
		}
	}
	Sleep(1000);
	clear();
}
void update(){
	if(head==NULL){
		clear();
		color(96);
		gotoxy(50,7);
		cout<<"Update Record";
		color(2);
		gotoxy(37,9);
		cout<<"List is empty";
	}
	else{
		clear();
		color(96);
		gotoxy(50,7);
		cout<<"Update Record";
		color(2);
		gotoxy(37,9);
		int value;
		cout<<"Enter ID: ";
		cin>>value;
		clear();
		node *temp=head;
		bool flag=false;
		while(temp!=NULL){
			if(temp->id==value){
				clear();
				color(96);
				gotoxy(50,7);
				cout<<"Update Record";
				color(2);
				gotoxy(37,9);
				cout<<"Employee ID: ";
				cin>>temp->id;
				fflush(stdin);
				gotoxy(37,11);
				cout<<"Name: ";
				cin.getline(temp->name,50);
				fflush(stdin);
				gotoxy(37,13);
				cout<<"Qualification: ";
				cin.getline(temp->qualification,30);
				fflush(stdin);
				gotoxy(37,15);
				cout<<"Address: ";
				cin.getline(temp->address,50);
				fflush(stdin);
				gotoxy(37,17);
				cout<<"City of stay: ";
				cin.getline(temp->city,30);
				fflush(stdin);
				gotoxy(37,19);
				cout<<"Job title: ";
				cin.getline(temp->jobTitle,50);
				fflush(stdin);
				gotoxy(37,21);
				cout<<"Salary: ";
				cin>>temp->salary;
				fflush(stdin);
				gotoxy(37,23);
				cout<<"Date of joining: ";
				cin.getline(temp->date,50);
				fflush(stdin);
				flag=true;
			}
			temp=temp->next;
		}
		if(flag==true){
			color(64);
			gotoxy(37,24);
			cout<<"Record successfully updated"<<endl;
		}
		else{
			color(64);
			gotoxy(37,15);
			cout<<"ID not found"<<endl;
		}
	}
	Sleep(1000);
	clear();
}

void saveOnFile(){
	system("cls");
	drawRectangle();
	ofstream myfile ("Employees Data.txt");
	if (myfile.is_open()){
		myfile<<"\n\t\t\t\t\tInformation of the employees \n";
	    
	    struct node *p=head;
	    int c=0;
			while(p!=NULL){
				myfile <<"ID\t\t"<<p->id<<endl;
				myfile<<"Name\t\t"<<p->name<<endl;
				myfile<<"Address\t\t"<<p->address<<endl;
				myfile<<"City\t\t"<<p->city<<endl;
				myfile<<"Date\t\t"<<p->date<<endl;
				myfile<<"Jobtitle\t"<<p->jobTitle<<endl;
				myfile<<"Qualification\t"<<p->qualification<<endl;
				myfile<<"Salary\t\t"<<p->salary<<endl;
				p=p->next;
				c=c+1;
			}
		myfile<<"\n\nTotal number of information of the employees are :	"<<c;
		}
    myfile.close();
}

void brain(){
	int n;
	char ch;
	do{
		header();
		menu();
		gotoxy(3,23);
		cout<<"Choose an option: ";
		cin>>n;
		if(n==1){
			a:
			color(96);
			gotoxy(50,7);
			cout<<"Add Record.";
			color(2);
			gotoxy(37,9);
			cout<<"Where do you want to add record";
			gotoxy(37,11);
			cout<<"1- At the beginning";
			gotoxy(37,13);
			cout<<"2- At the end";
			gotoxy(37,15);
			cout<<"3- After some record";
			gotoxy(37,17);
			cout<<"4- Before some record";
			gotoxy(37,19);
			cout<<"Choose an option: ";
			cin>>n;
			if(n==1){
				add_first();
			}
			else if(n==2){
				add_last();
			}
			else if(n==3){
				add_after();
			}
			else if(n==4){
				add_before();
			}
			else{
				clear();
				color(96);
				gotoxy(45,15);
				cout<<"Choose correct option: ";
				Sleep(1000);
				color(2);
				clear();
				goto a;
			}
		}
		else if(n==2){
			search();
		}
		else if(n==3){
			update();
		}
		else if(n==4){
			del();
		}
		else if(n==5){
			display();
		}
		else if(n==6){
			if(head==NULL){
				clear();
				gotoxy(45,15);
				color(3);
				cout<<"File not Found";
				Sleep(1000);
				clear();
			}
			else{
				saveOnFile();
				clear();
				gotoxy(45,15);
				color(3);
				cout<<"File Saved";
				Sleep(1000);
				clear();
			}
		}
		else if(n==7){
			system("cls");
			gotoxy(20,15);
			cout<<"Thank You For Using Employee Managment System";
			Sleep(2500);
			system("cls");
			exit(0);
		}
		else{
			clear();
			gotoxy(41,9);
			color(64);
			cout<<"Choose correct option: ";
			Sleep(500);
			clear();
			Sleep(1000);
		}
	}while(n);
}

int main(){
	system("cls");
	SetConsoleTitle("DSA Group Assignment - Employee Managment System - Sir Tayyab Wahab");
	Splash();
	drawRectangle();
	brain();

	return 0;
}
