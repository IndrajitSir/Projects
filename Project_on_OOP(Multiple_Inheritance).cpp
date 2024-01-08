#include<iostream>
#include<string.h>
using namespace std;
/* DESCRIPTION
 A small project with the help of multiple inheritance, where we get details the of students and display the details .
*/
//--------------------------FIRST CLASS------------------------------------
class class_one{
	string student_name[10];
	int roll_no[10];
	protected:
		void get_name(int);
		void get_roll_no(int);
	public:
		void display_class_one_data(int);
};
//---------------------INPUT FUNCTION----------------------------
void class_one :: get_name(int x)
{
	cout<<"Enter students name :"<<endl;
	for(int i=0;i<x;i++)
	{
		cin>>student_name[i];
	}
	cout<<"Students Name Entered\n";
}
void class_one :: get_roll_no(int x)
{
	cout<<"Enter students roll number :"<<endl;
	for(int i=0;i<x;i++)
	{
		cin>>roll_no[i];
	}
	cout<<"Students Roll Number Entered\n";
}
//---------------------DISPLAY FUNCTIONS-----------------------------
void class_one :: display_class_one_data(int y)
{
	string name;
	int roll;
	for(int i=0;i<y;i++)
	{
	    name = student_name[i];
	    roll = roll_no[i];
	}
	cout<<"Name : "<< name <<"\n"<<"Roll No : "<< roll <<"\n";
}
//--------------------------SECOND CLASS-----------------------------------
    int sub = 0;
	int count = 0;
	const int mark = 100;//this is array indexing value
class class_two{
	int tmarks;//per subjects ke marks ko jodkar aane wala total marks.
	string subjects_name[10];
	int per_subject_marks[10];
	float total_marks_percentage;
	int total_marks;//Total marks already given wala(all subjects * 100), means if 5 subjects hain to marks 500 hoga jo ki predecided hota hai university se.
	int subjects_marks[mark];
	public:
		void get_subjects_name();
		void get_subjects_marks(int);
		void get_Total_marks();
		
		void display_class_two_data(int);
};//----------------------INPUT FUNCTION------------------------------------
void class_two :: get_subjects_name()
{
	cout<<"How many subjets please specify ?"<<endl;
	cin>>sub;
	cout<<"Enter Subjects Name :"<<endl;
	for(int i=0;i<sub;i++)
	{
		cin>>subjects_name[i];
	}
	cout<<"Subjects Name Entered\n";
}
void class_two :: get_subjects_marks(int x)
{
	for(int i=0;i<sub;i++)
	{
		cout<<"Enter Marks of "<< subjects_name[i] <<" Subject :"<<endl;
		for(int j=0;j<x;j++)
		{
		  if(count < mark)
		  {
		  	cin>>subjects_marks[count];
		    count++;
		  }	
		  else{
		  	cout<<"Memory Overflow\n";
		  }
		}
		cout<< subjects_name[i] << " Marks Entered\n";
	}
	cout<<"All Subjects Marks Entered\n";
}
void class_two :: get_Total_marks()
{//Getting total marks of every student
for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            per_subject_marks[j] += subjects_marks[i + 10 * j];
        }
    }
}
//----------------------DISPLAY FUNCTION-----------------------------------
void class_two :: display_class_two_data(int stud)
{
	for(int i=0;i<sub;i++)
	{
		cout<< subjects_name[i] <<" : ";
		for(int j=0;j<=stud;j++)
		{
		  if((j == stud-1) && (stud < (sub*10)))//Ye jo 10 hai wo number of students hai.
		  {
		  	cout<< subjects_marks[j] << endl;
		  }	
		}
		cout<<"\n";
		stud = stud + 10;
	}
	// Printing the result array
    for(int i = 0; i < stud; i++)
    {
        if(i == stud-1)
        {
        	total_marks_percentage = ((per_subject_marks[i]/(sub*100)) *100);
        	cout << "Total Marks "<< ": " << result[i] << "\n";
        	cout<< "Total Marks (in percentage) "<<": "<< total_marks_percentage <<"\n";
		}	
    }
	/*----------TOTAL MARKS------------
	<<"Total Marks : "<< tmarks <<"\n";
	loat tmarks;
	for(int i=0;i<y;i++)
	{
	    name = student_name[i];
	    roll = roll_no[i];
	    //tmarks = total_marks[i];
	    //tmarks = total_marks[i];
	}*/
}//-------------------------INHERITED CLASS---------------------------------
class class_three : private class_one, private class_two{
	string school_name;
	/* INHERITED FROM CLASS ONE
		void get_name(int);
		void get_roll_no(int);
		void get_Total_marks(int);
		void display_class_one_data(int); 
   -----INHERITED FROM CLASS TWO-------
		void get_subjects_name(int);
		void get_subjects_marks(int);
		void display_class_two_data(int);
		void initialize_private_data(void);
	*/
	public:
		void setdata(int);
		void display_details_of_students();
		//void initialize();
};
void class_three :: setdata(int val)
{
	get_name(val);
	get_roll_no(val);
	get_subjects_name();
	get_subjects_marks(val);
	//get_Total_marks(val);
}
void class_three :: display_details_of_students()
{
	int num;
	cout<<"Which student details you want to see :\n";
	cin>>num;
	display_class_one_data(num);
	display_class_two_data(num);
}
/*void class_three :: initialize()
{
	initialize_private_data();
} */
int main()
{
	class_three obj;
	int choice, ch, num;
	do{	
	cout<<"1.Enter"<<"\t"<<"2.Display"<<"\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"How many student details you want to enter :\n";
	        cin>>num;
	        obj.setdata(num);
			break;
		case 2:	obj.display_details_of_students();
		break;
		default: cout<<"See Options and Enter Correctly !";
	}
	cout<<"1.CONTINUE"<<"\t"<<"2.STOP"<<"\n";
	cin>>ch;
	}while(ch==1);
	
	return 0;
}











