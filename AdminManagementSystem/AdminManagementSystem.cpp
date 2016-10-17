#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<windows.h>
using namespace std;

class Admin
{
    protected:
    char name[30];
    int no;
    char fname[40];
    int jod;
    int year;
    string DOB;
    int age;

    public:
    void hello()
    {
        system("cls");
        cout<<"\n\t\t#########################################";
        cout<<"\n\t\t &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout<<"\n\t\t\t ADMIN MANAGEMENT SYSTEM";
        cout<<"\n\n\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout<<"\n\t\t*****************************************\n\n\n";
        cout<<"\n\t\t\t\t\t PREPARED BY :-";
        cout<<"\n\t\t\t\t\t      CHARMI JAIN     15012101007";
        cout<<"\n\t\t\t\t\t      ROHAN JAIN      15012101009";
        getch();
        system("cls");

    }
    void getData()
    {
        cout<<"enter the name:"<<endl;
        cin>>name;

        cout<<"enter the father name:"<<endl;
        cin>>fname;

        cout<<"enter the mobile number:"<<endl;
        cin>>no;

        cout<<"enter the age:"<<endl;
        cin>>age;

        cout<<"enter the date of joining:"<<endl;
        cin>>jod;

        cout<<"enter the year of joining:"<<endl;
        cin>>year;

        cout<<"enter the birth date:"<<endl;
        cin>>DOB;
    }
    void putData()
    {
        cout<<"name:"<<name<<endl;
        cout<<"age:"<<age<<endl;
        cout<<"father name:"<<fname<<endl;
        cout<<"number:"<<no<<endl;
        cout<<"joining date:"<<jod<<endl;
        cout<<"year of joining:"<<year<<endl;
        cout<<"birth date:"<<DOB<<endl;
    }
};

class Student:public Admin
{
        protected:
        int marks;
        float per;
        string add;
        string ID;
        string course;
        public:
            void input()
            {
                cout<<"*******Student Detail*******"<<endl;
                cout<<"enter the student id:"<<endl;
                cin>>ID;

                cout<<"enter the address:"<<endl;
                cin>>add;

                cout<<"enter the marks of 3 subjects:"<<endl;
                cin>>marks;

                cout<<"enter the percentage:"<<endl;
                cin>>per;
            }

            void putData()
            {
                cout<<"ID:"<<ID<<endl;
                cout<<"address:"<<add<<endl;
                cout<<"marks:"<<marks<<endl;
                cout<<"percentage:"<<per<<endl;
            }
    };
        class Faculty : public Admin
        {
            protected:
             string ID;
             char sub;
             int sem;

            public:
                void input()
                {
                    cout<<"********Faculty details********"<<endl;
                    cout<<"enter the ID:"<<endl;
                    cin>>ID;

                    cout<<"enter the subject you teach:"<<endl;
                    cin>>sub;

                    cout<<"enter the semester:"<<endl;
                    cin>>sem;

                }
                void putData()
                {
                    cout<<"ID:"<<ID<<endl;
                    cout<<"Subject:"<<sub<<endl;
                    cout<<"Semester:"<<sem<<endl;
                }

            };

class file :public Student ,public Faculty
{
private:
	int roll;
	float age;
	char name[100];
public:
	void input();
	void show();
	char *getn()
	{
		return name;
	}
	void Create();
void Add();
void Display();
void DisplayP();
void Modify();
void Delete();
};file fileobj;

void file::input()
{
	cout<<"Enter the roll, Age and name :";
	cin>>roll>>age;
	cin>>name;
}

void file::show()
{
	cout<<"Roll==> "<<roll<<endl;
	cout<<"Age ==> "<<age<<endl;
	cout<<"Name==> "<<name<<endl;
}

fstream fil;
void pass_entry()
{
    string n;
    char temp[100];
    cout <<"\n Enter the Password: ";
    cin.getline(temp,100);          ///getline means it will take full line as a i/p
    n.insert(0,temp);

    if(n.find("1234")==-1 )
    {
        cout <<"\n Exception occurs ";
        cout << "\n";
        throw 1;
    }
    else if(n.find("abcd")==1)
    {

    }
    else
    {
        cout<<"\n Password is entered correctly \n";
    }
}

void file::Create()		//Function to Create Data File
{
    int n;
	char ch='y';
	fil.open("binary.txt",ios::out);
	while(ch=='y' || ch =='Y')
	{cout<<"Enter 1 for student ";
	cout<<"enter 2 for faculty  ";
	cin>>n;
	system("cls");
	if(n==1)
	{
		fileobj.Student::input();
		fileobj.input();
		fil.write((char*)&fileobj, sizeof(fileobj));
		cout<<"Want to Continue.....";
		cin>>ch;
	}fil.close();
if(n==2)
{

		fileobj.Faculty::input();
		Admin d;d.getData();

		fil.write((char*)&fileobj, sizeof(fileobj));
		cout<<"Want to Continue.....";
		cin>>ch;
	}fil.close();
}

}

void file::Add()              //Function to Add New Record in Data File
{int n;
	char ch='y';
	fil.open("binary.txt",ios::app);
	cout<<" for student press 1 and faculty press 2";
	cin>>n;
	if(n==1)
    {
	while(ch=='y' || ch =='Y')
	{
		fileobj.Student::input();
		fil.write((char*)&fileobj, sizeof(fileobj));
		cout<<"Want to Continue.....";
		cin>>ch;
	}
    }
	fil.close();
}

void file::Display()		//Function to Display All Record from Data File
{
    int n;
	fil.open("binary.txt",ios::in);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		    cout<<" For Student press 1 and for faculty press 2";
		    cin>>n;
		    if(n==1)
            { while(!fil.eof())
            {

            fileobj.Student::putData();
			cout<<"Press Any Key....For Next Record"<<endl;
			getch();
			fil.read((char*)&fileobj, sizeof(fileobj));
            }
            }
            else
            {
                while(!fil.eof())
            {

            fileobj.Faculty::putData();
            Admin d;d.putData();
			cout<<"Press Any Key....For Next Record"<<endl;
			getch();
			fil.read((char*)&fileobj, sizeof(fileobj));
            }
            }
	}
	fil.close();
}

void file::DisplayP()		//Function to Display particular Record from Data File
{
	char n[100];
	int x;
	system("cls");
	cout<<"enter 1 for Student and 2 for faculty";
	cin>>x;
	if(x==1)
    {
	cout<<"Enter Name that should be searched:";
	cin>>n;

	fil.open("binary.txt",ios::in);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(strcmp(n,fileobj.getn())==0)
			{
				fileobj.Student::putData();
				cout<<"Press Any Key...."<<endl;
				getch();
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
    }
	else{
cout<<"Enter Name that should be searched:";
	cin>>n;

	fil.open("binary.txt",ios::in);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(strcmp(n,fileobj.getn())==0)
			{
				fileobj.Faculty::putData();
				cout<<"Press Any Key...."<<endl;
				getch();
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
}
	fil.close();
}
void file::Modify()		//Function to Modify Particular Record from Data File
{
    int x;
	char n[100];
	cout<<"Enter Name that should be searched:";
	cin>>n;
	fil.open("binary.txt",ios::in| ios::out);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		cout<<"enter 1 for student and 2 for faculty ";
		if(x==1)
        {
		while(!fil.eof())
		{
			if(strcmp(n,fileobj.getn())==0)
			{
				fil.seekg(0,ios::cur);
				cout<<"Enter New Record.."<<endl;
				fileobj.Student::input();
				fil.seekp(fil.tellg() - sizeof(fileobj));
				fil.write((char*)&fileobj, sizeof(fileobj));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	else
    {
        while(!fil.eof())
		{
			if(strcmp(n,fileobj.getn())==0)
			{
				fil.seekg(0,ios::cur);
				cout<<"Enter New Record.."<<endl;
				fileobj.Faculty::input();
				fil.seekp(fil.tellg() - sizeof(fileobj));
				fil.write((char*)&fileobj, sizeof(fileobj));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
		}	fil.read((char*)&fileobj, sizeof(fileobj));
    }

	fil.close();
}
}
void file::Delete()		//Function to Delete Particular Record from Data File
{
	char n[100];
	cout<<"Enter Name that should be Deleted :";
	gets(n);
	ofstream o;
	o.open("new.txt",ios::out);
	fil.open("binary.txt",ios::in);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(strcmp(n,fileobj.getn())!=0)
			{
				o.write((char*)&fileobj, sizeof(fileobj));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	o.close();
	fil.close();
	remove("binary.txt");
	rename("new.txt", "binary.txt");
}
int main()
{
    Admin b;b.hello();
	int opt;
	void  pass_entry();
{
    char a[25];
    try
    {
        pass_entry();
    }
    catch(int b)
    {
        exit(0);
    }
}

	while(1)
	{
    system("cls");
		cout<<"1.Create Data File"<<endl;
		cout<<"2.Add New Record in Data File"<<endl;
		cout<<"3.Display Record From Data File"<<endl;
		cout<<"4.Display Particular Record From Data File"<<endl;
		cout<<"5.Modify Particular Record From Data File"<<endl;
		cout<<"6.Delete Particular Record From Data File"<<endl;
		cout<<"7.Exit From the Program"<<endl;
		cout<<"Enter your Option : "<<endl;
		cin>>opt;
		switch(opt)
		{
			case 1:
			{system("cls");
				file f;
    //            f.Faculty::input();
				f.Create();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;
			}
			case 2:
			{
			    file f;
				f.Add();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;
			}
			case 3:
			{file f;
				f.Display();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;
			}
			case 4:
			{file f;
				f.DisplayP();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;
			}
			case 5:
			{file f;
				f.Modify();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;
			}
			case 6:
			{file f;
				f.Delete();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;
			}
			case 7:
			{
				exit(0);
			}
			default:
			{
				cout<<"Wrong Choice....Press Key For View the Main Menu";
				getch();
system("cls");
			}
		}
	}
}
