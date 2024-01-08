#include<iostream>
#include<string.h>
using namespace std;

int count = 0;

class a{
	int roll_no[100];
	string name[100];
	float marks[100];
	protected://----------Data Show karane ke liye-------------
		int return_roll_no(int);ṁ
		string return_name(int);
		float return_marks(int);
	public://-------Data Input karne ke liye--------------
		void input_roll_no(int);
		void input_name(int);
		void input_marks(int);
};//------------------------INPUT FUNCTIONS--------------------------
void a :: input_roll_no(int val)
{
	cout<<"Enter roll no :"<<"\n";
	for(int i=0; i<val;i++)
	{
		cin>>roll_no[i];
	}
}
void a :: input_name(int val)
{
	cout<<"Enter Name :"<<"\n";
	for(int i=0; i<val;i++)
	{
		cin>>name[i];
	}
}
void a :: input_marks(int val)
{
	cout<<"Enter Marks :"<<"\n";
	for(int i=0; i<val;i++)
	{
		cin>>marks[i];
	}
}
//---------------------RETURN FUNCTIONS----------------------------
int a :: return_roll_no(int val)
{
	int x;
	 for(int i=0; i<val;i++)
	 {
		x = roll_no[i];
 	 }
	return (x);
}
string a :: return_name(int val)
{
	string x;
	for(int i=0; i<val;i++)
	{
		x = name[i];
	}
	return (x);
}
float a :: return_marks(int val)
{
	float x;
	for(int i=0; i<val;i++)
	{
		x = marks[i];
	}
	return (x);
}
//-----------------------INHERITED CLASS B------------------------------
class B : public a{
	int dept_id[100];
	string dept_name[100];
	/*Inherited Part
	protected:----------Data Show karane ke liye-------------
		int return_roll_no(void);
		string return_name(void);
		float return_marks(void); 
	*/
	public:
		void dept_id_input(int);
		void dept_name_input(int);	
		int show_dept_id(int);
		string show_dept_name(int);
		/* Inherited Part-------Data Input karne ke liye--------------
		input_roll_no(a);
	    input_name(a);
	    input_marks(a);*/			
};//------------------------INPUT FUNCTIONS OF CLASS B--------------------------
void B :: dept_id_input(int val)
{
	cout<<"Enter Department_ID :"<<"\n";
	for(int i=0; i<val;i++)
	{
		cin>>dept_id[i];
	}
}
void B :: dept_name_input(int val)
{
	cout<<"Enter Department_Name :"<<"\n";
	for(int i=0; i<val;i++)
	{
		cin>>dept_name[i];
	}
}
//---------------------RETURN FUNCTIONS OF CLASS B----------------------------
int B :: show_dept_id(int val)
{
	int x;
	for(int i=0; i<val;i++)
	{
		x = dept_id[i];
	}
	return (x);
}
string B :: show_dept_name(int val)
{
	string x;
	for(int i=0; i<val;i++)
	{
		x = dept_name[i];
	}
	return (x);
}
//-----------------------ANOTHER INHERITED CLASS C------------------------------
class C : private B
{
    /*Inherited Part
    -------Data Input karne ke liye--------------
	void dept_id_input(int);
	void dept_name_input(int);	
	void input_roll_no(int);
	void input_name(int);
	void input_marks(int);
	----------Data Show karane ke liye-------------
	int return_roll_no(int);
	string return_name(int);
	float return_marks(int);
	int show_dept_id(int);
	string show_dept_name(int);
	*/
	public:
		void Enter_details(int);
    	void display();
};
void C :: Enter_details(int a)
{
	input_name(a);
	input_roll_no(a);
	dept_name_input(a);
	dept_id_input(a);
	input_marks(a);
	//count++;
}
//---------------------DISPLAY FUNCTION OF CLASS C----------------------------
void C :: display()
{
	int roll;
	cout<<"Enter Roll Number\n";
	cin>>roll;
	//----------------------------------------------------------------
	cout<<"Roll number :"<<return_roll_no(roll)<<"\n";
	cout<<"Name :"<<return_name(roll)<<"\n";
	cout<<"Marks :"<<return_marks(roll)<<"\n";
	cout<<"Department ID :"<<show_dept_id(roll)<<"\n";
	cout<<"Department Name :"<<show_dept_name(roll)<<"\n";
}

int main()
{
	C obj;
	int num,choice,ch;
	do{
		cout<<"1.Enter Details\t2.Display\n";
		cin>>choice;
		switch(choice)
		{
			case 1: 
			 cout<<"How many students details you want to store :\n";
	         cin>>num;
	         obj.Enter_details(num);
			 break;
			case 2:  obj.display();
			 break;
			default: cout<<"ENTER YOUR CHOICE CORRECTLY !\n";	
		}
		cout<<"CONTINUE : 1 OR STOP : 2\n";
		cin>>ch;
	}while(ch == 1);
	
	return 0;
}














