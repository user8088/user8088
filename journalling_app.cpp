#include<iostream>
#include<fstream>
#include<string.h>
#include <iomanip>
#include <conio.h> 
#include <time.h> 
using namespace std;

ifstream get;
ofstream put;
ofstream create;
string filename;




struct listNodes
{
   
   listNodes * next=NULL;
   string to_do;
   
   
   
   void read_list()
   {
   	 	cin>>to_do;
   }
   
   void display_list()
   {
   	 cout<<to_do<<endl;
   }
};

struct Data_Base
{
	listNodes * front=NULL;
	listNodes * rear=NULL;
	

	listNodes * createlistNode()
	{
		listNodes * ptr=new listNodes;
		ptr->read_list();
		return ptr;
	}
	
    void insertTask() 
	{
		listNodes * newToDoNode=createlistNode();
		if(front==NULL)
		{
			front=newToDoNode;
			rear=newToDoNode;
		}
		else
		{
			rear->next=newToDoNode;
			rear=newToDoNode;
		}
	}
	
	void display_toDo()
	{
		listNodes * temp=front;
		cout<<"To do list: "<<endl;
		if(front==NULL)
		{
			cout<<"No list added"<<endl;
		}
		while(temp!=NULL)
		{
			temp->display_list();
	        temp=temp->next;
		}
	}
	
	void input_listInFile()
	{
		listNodes * temp=front;
		if(front==NULL)
		{
			cout<<"No list added"<<endl;
		}
		else
		{
		
			string s,filename;
	   		ofstream put;
	   		cout<<"Name your list: ";
	   		cin>>s;
	   		filename=s+".txt";
	   		put.open(filename.c_str());
	   		while(temp!=NULL)
	   		{
	   			put<<temp->to_do<<endl;
	   			temp=temp->next;
			}
			put.close();
		}	
	}
	
	void getdata()
	{
		string name,fname,list;
		cout<<"Input the name of your list: ";
		cin>>name;
		fname=name+".txt";
		get.open(fname.c_str());
		while(!get.eof())
		{
		  getline(get,list);
		  cout<<list<<endl;
		}
		get.close();
	}
};


class calendar
{
	public:
	void printCalendar(int year)
  {
	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
	int mDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
	string monthList[] = { "January", "February", "March", "April", "May", "June", 
                        "July", "August", "September", "October", "November", "December" }; 
                       
    
    cout<<"  --------------------------------"<<endl;
    cout<<"           Calendar     "<<year<<endl;
    cout<<"  --------------------------------"<<endl<<endl;
    int days; 
    int current; 
   
   	int y = year - 1;
    current = ( y + y/4 - y/100 + y/400 + t[0] + 1) % 7;
   
    for (int i = 0; i < 12; i++) 
    { 
    	if( i==1 )
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) 
				days = 29;
			else	
				days = mDays[i];
		else
			days = mDays[i];
     
  		cout<<endl<<"  ------------"<<monthList[i]<<"-------------"<<endl;   
  
        cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat"<<endl; 
  
        int k; 
        for (k = 0; k < current; k++) 
            cout<<"     "; 
  
        for (int j = 1; j <= days; j++) 
        {
        	k++;
            cout<<setw(5)<<j;
            if (k > 6) 
            { 
                k = 0; 
                cout<<endl; 
            } 
        } 
        
		if (k)
			cout<<endl; 

        current = k; 
    }
  
    return; 
}


 void viewCalendar()
 {
 		system("cls");

 	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	
	int year = 1900 + local_time->tm_year; 
	char option;
	
	do{
		system("cls");
		printCalendar(year);
		
		cout<<endl<<endl;
		cout<<"Press "<<endl;
		cout<<"- n for next year"<<endl;
		cout<<"- p for previous year"<<endl;
		cout<<"- e for exit"<<endl;
		option = getche();
		switch(option){
			case 'n':
				year++;
				break;
			case 'p':
				year--;
				break;
		}
			
	}
	while(option!='e' && option!='E');	 		
  }
 
};

class menu
{
	public:
	void show_menu()
	{
	 cout<<"\t\t::::::::::::::::::::<<<WELCOME>>>:::::::::::::::::::::"<<endl<<endl;
	 cout<<"Choose from the following options : "<<endl;
	 cout<<"> Write a journal ----A PROJECT BY-----------------------  press 1 to select"<<endl;
	 cout<<"> View your journals -----------Asim---------------------  press 2 to select"<<endl;
	 cout<<"> Update journals------------------Mehwish---------------  press 3 to select"<<endl;
	 cout<<"> View calendar-------------------------&----------------  press 4 to select"<<endl;
	 cout<<"> Add to do list for today----------------Hassan---------  press 5 to select"<<endl;
	 cout<<"> View to do list for today------------------------------  press 6 to select"<<endl;
	 cout<<"> SignOut------------------------------------------------  press 7 to select"<<endl;

	}

	
};
class accounts: public menu, calendar
{
	
	string usn,ans,psd,name,fname,usern,pw,line,nusn,cat,cat2,cat3,k,key;
	Data_Base a;
	string j;
	string journal;
	string category;
    int tm;
    int exe=1;
    public:

	
	void login_signup() 
	{
		int i=0;
		int choice,exit=0;
		int menu_choice;
	    ofstream fileo;
	    ifstream filei;
	    fstream myfile;
	    cout<<"----------------------------------------------Welcome to our system!------------------------------------------------------\n";
	    while(exit==0)
	    {
	    int	exe=1;
	        cout<<"\nChoose one option:\n1. SignIn/LogIn(press 1 to select this)\n2. SignUp/Register(press 2 to select this)\n\npress any key and enter to exit\n";
	        cin>>choice;
	        if(choice==1)
	        {
	        	usern="";
	        	line="";
	        	pw="";
	        	key="";
	        	
	            cout<<"Enter your username:";
	            cin>>usn;
	            cout<<"\nEnter your password:";
	            cin>>psd;
	            fname=usn+".txt";
	            filei.open(fname.c_str());
	            if(!filei.is_open())
	            {
	                cout<<"\nYou are not registered, please register before logging in.\n";
	                filei.close();
	                continue;
	            }
	            getline(filei,usern);
	            getline(filei,line);
	            getline(filei,pw);
	            getline(filei,key);
	            filei.close();
	            filei.clear();
	            if(usn==usern && psd==pw)
	            {
	                cout<<"\nYou are successfully logged in:)\nYOUR PROFILE DETAILS:\n";
	                cout<<"User-name:"<<usern<<endl;
	                cout<<"Name:"<<line<<endl;
	                while(exe==1)
	                {
	                show_menu();
	                cout<<"Input your choice here: ";
	                cin>>menu_choice;
	                if(menu_choice==5)
	                {
	                	int limit;
						Data_Base a;
					    cout<<"How many tasks do you want to add ? ";
					    cin>>limit;
					    for(int i=0;i<limit;i++)
					    {
					    	a.insertTask();
						}
						a.input_listInFile();
					}
					else if(menu_choice==6)
					{
						a.getdata();
					}
	                else if(menu_choice==1 || menu_choice==3)
	                {
	                	if(menu_choice==3)
	                	{
	                		int input;
	                	cout<<"Do you want to add to your journal or rewrite it? (ADD(1)/REWRITE(2))---> ";
	                	cin>>input;
	                	if(input==1)
	                	{
	                	cout<<"Input the category of your journal: ";
	                	cin>>category;
	                    cout<<"Now add to your journal: "<<endl;
	                	cat=category+".txt";
	                	fileo.open(cat.c_str(),ios::app);
	                	cin.ignore();
	                	getline(cin,j);
			            cout<<"\nJournal updated !"<<endl;
			            fileo<<j<<endl;
			            fileo.close();
			            fileo.clear();
						}
						else if(input==2)
						{
						cout<<"Input the category of your journal: ";
	                	cin>>category;
	                    cout<<"Now re-write your journal: "<<endl;
	                	cat=category+".txt";
	                	fileo.open(cat.c_str());
	                	cin.ignore();
	                	getline(cin,j);
			            cout<<"\nJournal updated !"<<endl;
			            fileo<<key<<endl<<j<<" ";
			            fileo.close();
			            fileo.clear();
						}
	                	
						}
						else
						{
						cout<<"Assign a category to your journal: ";
	                    cin>>category;
	                    cout<<"Now write your journal: "<<endl;
	                	cat=category+".txt";
	                	fileo.open(cat.c_str());
	                	cin.ignore();
	                	getline(cin,j);
			            cout<<"\nJournal created !"<<endl;
			            fileo<<key<<endl<<j<<" ";
			            fileo.close();
			            fileo.clear();
						}
	                	
					}
					else if(menu_choice==2)
					{
						string jr;
						string serial_k="";
						cout<<"Input your journal category(Without space): ";
						cin>>category;
						cat2=category+".txt";
						myfile.open(cat2.c_str());
						getline(myfile,serial_k);
						getline(myfile,jr);
						myfile.close();
						myfile.clear();
						if(serial_k==key)
						{
							cout<<"Category: "<<category<<endl;
							cout<<"Journal Entry: "<<jr<<endl;
						}
						else
						{
							cout<<"Serial keys do not match, the journal is inaccessable!"<<endl;
						}
					}
					
					else if(menu_choice==4)
					{
					   viewCalendar();
					}
					
					
					else if(menu_choice==7)
					{
						exe=0;
					}
	            }
					}
	                
	            else{
	                cout<<"\nWrong username or password!\nPlease try Again.\n";
	            }
	            cout<<endl;
	        }
	        else if(choice==2)
	        {
	            cout<<"\nEnter your name:";
	            cin.ignore();
	            getline(cin,name);
	            cout<<"\nCreate a username:";
	            cin>>usn;
	            cout<<"\nCreate a password:";
	            cin>>psd;
	            cout<<"\nCreate your serial key: ";
	            cin>>k;
	            fname=usn+".txt";
	            //cout<<fname;
	            fileo.open(fname.c_str());
	            fileo<<usn<<endl<<name<<endl<<psd<<endl<<k<<endl;
	            cout<<"\nYou are successfully registered:)";
	            fileo.close();
	            fileo.clear();
	        }
	        else
	        {
	            exit=1;
	        }
	        
	    }
	    cout<<"\n----------------------------------------------Thank you for visiting:)----------------------------------------------------\n";
	      
	}
};

    

int main()
{
   accounts a;
   a.login_signup();

   
}
