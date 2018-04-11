#include<iostream>
#include<fstream>
#include<cstdlib>
#include "welcome.h"
#include<cstring>
#include<vector>
#include<iomanip>

class Dest
{
	public:char place[50];
};

class Describe:private Dest
{
    private:
         char desp[2000];
    public:
	 void get_description(char*);
	 void write_description(char*);
};

class Lodging:private Dest
{
    private:
        char name[100];
        char rate[100];
        char phone[100];
        char addresss[100];
    public:
	void get_lodgingdetails(char*);
        void write_lodging(char*);
};


class Transportation:private Dest
{   
    private:
        char bus[500];
        char train[500];
        char flight[500];
    public:
	void get_transportdetails(char*);
	void write_transportation(char*);
};

class VisitingPlace:private Dest
{
    private:
        char desp[1000];
    public:
	void get_vplacedetails(char*);
	void write_vplace(char*);	
};

void Lodging::get_lodgingdetails(char *inp)
{
    std::ifstream f;
    f.open("Lodge.csv",ios::in);
    while(!f.eof())
    {
        f.getline(place,99,',');
        f.getline(name,99,',');
        f.getline(phone,99,',');
        f.getline(rate,99,',');
        f.getline(addresss,99,'"');
        if(strcasecmp(place,inp)==0)
        {
            cout<<"---->"<<endl;
            cout<<right<<"    Hotel name :"<<name<<endl;
            cout<<right<<"    Phone no:"<<phone<<endl;
            cout<<right<<"    Rent per day:"<<rate<<endl;
            cout<<right<<"    Address:"<<addresss<<endl;
            cout<<endl;
        }
        if(f.eof())
            break;
        f.ignore(1000,'\n');

    }
    f.close();
}

void Lodging::write_lodging(char *inp)
{
    std::fstream f;
    f.open("Lodge.csv",ios::app);
    cout<<"ENTER THE NO OF HOTELS YOU WANT TO GIVE DETAILS:"<<endl;
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        f<<inp;
        f<<',';
        cout<<"ENTER NAME OF THE HOTEL:"<<endl;
        cin>>name;
        f<<name;
        f<<',';
        cout<<"ENTER PHONE:"<<endl;
        cin>>phone;
        f<<phone;
        f<<',';
        cout<<"ENTER RATE:"<<endl;
        cin>>rate;
        f<<rate;
        f<<',';
        cout<<"ENTER ADDRESS:"<<endl;
        cin>>rate;
        f<<rate;
        f<<'"';
        f<<'\n';
    }
    
  f.close();

}

void Transportation::get_transportdetails(char *inp)
{
    std::ifstream f;
    f.open("Transport.csv",ios::in);
    while(!f.eof())
    {
        f.getline(place,49,',');
        f.getline(bus,499,'"');
        f.ignore();
        f.getline(train,499,'"');
        f.ignore();
        f.getline(flight,499,'"');
        if((strcasecmp(place,inp))==0)
        {
            cout<<"---->Bus service:"<<bus<<endl;
            cout<<"---->Train service:"<<train<<endl;
            cout<<"---->Flight service:"<<flight<<endl;
	    break;
        }
	if(f.eof())
            break;
        f.ignore(1000,'\n');
    }
    f.close();
}

void Transportation::write_transportation(char *inp)
{
    std::fstream f;
    f.open("Transport.csv",ios::app);
    f<<inp;
    f<<',';
    cout<<"ENTER BUS SERVICE:"<<endl;
    cin.getline(bus,499);
    f<<bus;
    f<<'"';
    f<<',';
    cout<<"ENTER TRAIN SERVICE:"<<endl;
    cin.getline(train,499);
    f<<train;
    f<<'"';
    f<<',';
    cout<<"ENTER FLIGHT SERVICE:"<<endl;
    cin.getline(flight,499);
    f<<flight;
    f<<'"';
    f<<'\n';
    f.close();
}

void VisitingPlace::get_vplacedetails(char *inp)
{
    std::ifstream f;
    f.open("Vplace.csv");
    while(!f.eof())
    {
        f.getline(place,49,',');
        f.getline(desp,999,'\n');
        if((strcasecmp(place,inp))==0)
        {
            int i=0;
            string s="";
            while(desp[i]!='\0')
            {
                if(desp[i]==',')
                {
                    cout<<s<<endl;
                    s="";
                    i++;
                    continue;
                }
                s=s+desp[i];
                i++;

           }
           cout<<s<<endl;
        }
        if(f.eof())
            break;
    }
    f.close();
}
void VisitingPlace::write_vplace(char *inp)
{
    std::fstream f;
    int fp=1;
    f.open("Vplace.csv",ios::app);
    f<<inp;
    f<<',';
    cout<<"ENTER TOURIST SPOTS:"<<endl;
    while(fp)
    {
        cin>>desp;
	f<<desp;
	cout<<"WANT TO ADD MORE PRESS Y  OR ELSE PRESS N?"<<endl;
	char c;
	cin>>c;
	if(c=='n'||c=='N')
	{
		fp=0;
		f<<'"';
		f<<'\n';
	}
	else
	{
			f<<',';
	}
    }
    f.close();
}

void Describe::get_description(char *inp)
{
    std::ifstream f;
    f.open("Description.csv");
    while(!f.eof())
    {
        f.getline(place,49,',');
        f.getline(desp,1999,'\n');
    	if((strcasecmp(place,inp))==0)
        {
            cout<<"PLACE:"<< place << endl;
            cout<<endl;
            cout<<"DESCRIPTION:"<<desp;
            cout<<endl;
            break;
        }
        if(f.eof())
            break;

    }
    f.close();
}
void Describe::write_description(char *inp)
{
    std::fstream f;
    f.open("Description.csv",ios::app);
    f<<inp;
    f<<',';
    cout<<"ENTER DESCRIPTION ABOUT THE PLACE:";
    cin.ignore();
    cin.getline(desp,1999);
    f<<desp;
    f<<'\n';
    f.close();
}



class Admin: virtual public Transportation ,virtual public Lodging, virtual public  VisitingPlace, virtual public Describe 
{
	public:
		void admin_login();
};

class User: virtual public Transportation ,virtual public Lodging, virtual public  VisitingPlace, virtual public Describe 
{
	public:
		void user_login();
		void place_list();
		int place_list(string );
		void user_choice();
		void getdetails(char *);
};


int main()
{
    system("clear");
    WELCOME();
    char c;
    Z:
	User obj1;
	Admin obj2;
        cout<<"PRESS 1 FOR USER LOGIN"<<endl;
        cout<<"PRESS 2 FOR ADMIN LOGIN"<<endl;
        cout<<"PRESS 0 TO EXIT"<<endl;
        cout<<"ENTER YOUR CHOICE:"<<endl;
	try
	{
		string s;
  		cin>>s;
		system("clear");
		if(s.length()!=1)
		{
			throw 10;
		}
		c=s[0];
	}
        catch(int i)
	{
		cout<<"WRONG CHOICE!!!!"<<endl;
                cout<<"PLEASE ENTER THE CORRECT CHOICE:"<<endl;
                goto Z;
	}
        switch(c)
        {
            case '1': obj1.user_login();
		      system("clear");
		      goto Z;
                      break;
            case '2': obj2.admin_login();
		      system("clear");
                      goto Z;
                      break;
            case '0': system("clear");
                      cout<<"THANK YOU FOR USING OUR SERVICES!!!!!"<<endl;
                      exit(0);
                      break;
            default : cout<<"WRONG CHOICE!!!!"<<endl;
                      cout<<"PLEASE ENTER THE CORRECT CHOICE:"<<endl;
		      goto Z;
                      break;
        }
 return 0;
}

void User::user_login()
{
    
    char c;
    A:
    	user_choice();
	Z:
    		cout<<"DO YOU WANT TO EXIT OUR SERVICE? IF YES PRESS Y OR ELSE PRESS N TO RETURN"<<endl;
    		try
    		{
			string s;
 	 		cin>>s;
			if(s.length()!=1)
			{
				throw 10;
			}
			c=s[0];
    		}
    		catch(int i)
    		{
			system("clear");
			cout<<"WRONG CHOICE!!!!"<<endl;
        		cout<<"PLEASE ENTER THE CORRECT CHOICE:"<<endl;
        		goto Z;
    		}
    		if(c=='N'||c=='n')
    		{
       	  	   cout<<"THANK YOU!!!!!"<<endl;
    		}
    		else
		{ 
			system("clear");
			goto A;
		}
}

void User::place_list()
{
    cout<<"THESE ARE THE POPULAR TOURIST PLACES IN ODISHA"<<endl;
    std::ifstream f;
    string place;
    string desp;
    f.open("Description.csv",ios::in);
    while(!f.eof())
    {
        getline(f,place,',');
        cout<< place << endl;
        getline(f,desp,'\n');
        if(f.eof())
            break;
    }
    f.close();
}

int User::place_list(string p)
{
    
	int j;
	char ace[100];
	memset(ace,0,100);

	for(j=0;j<=p.length();j++)
	{
		ace[j]=p[j];
	}
	ace[j]='\0';
	string place;
	vector<string> v_place;

	string description;
	vector<string> v_description;

	bool status=false;
	std::ifstream f;
	f.open("Description.csv",ios::in);

	string line;
	while(f)
	{
		getline(f,place,',');
		v_place.push_back(place);

		getline(f,description,'\n');
		v_description.push_back(description);
	}

	for(int i=0;i<v_place.size();i++)
	{
		char pc[100];
		memset(pc,0,100);
		string p1=v_place[i];
		for(j=0;j<=p1.length();j++)
		{
			pc[j]=p1[j];
		}
		pc[j]='\0';
		 if(strcasecmp(pc,ace)==0)
			{
				status=true;
				break;
			}
		else
			status=false;
	}
	if(status)
		return 1;
	else
		return 2;
}

void User::user_choice()
{
    char inp[50];
    int f=0;
    string input;
    int c;
    Z:
	if(f==1)
	{
		system("clear");
		cout<<"INCORRECT INPUT!!!!!!"<<endl;
	}
        place_list();
        cout<<"ENTER THE PLACE YOU WANT TO VISIT:"<<endl;
        cin>>inp;
	input=inp;
        c=place_list(input);
        if(c==1)
        {
            getdetails(inp);
        }
        else
        {
            system("clear");
	    f=1;
            goto Z;
        }

}

void Admin::admin_login()
{
    
    char ch;
    M:
	cout<<"ENTER 1 TO ADD DATA"<<endl;
   	cout<<"ENTER 0 TO EXIT"<<endl;
    	cout<<"ENTER YOUR CHOICE"<<endl;
	try
    	{
		string s;
 	 	cin>>s;
		if(s.length()!=1)
		{
			throw 10;
		}
		ch=s[0];
    	}
    	catch(int i)
    	{
		system("clear");
		cout<<"WRONG CHOICE!!!!"<<endl;
        	cout<<"PLEASE ENTER THE CORRECT CHOICE:"<<endl;
        	goto M;
    	}
   	switch(ch)
   	{
   	     case '1': char place[50];
   	               cout<<"ENTER THE PLACE NAME WHOSE DETAILS NEED TO BE ADDED"<<endl;
   	               cin>>place;
   	               write_description(place);
                       write_transportation(place);
                       write_vplace(place);
        	       write_lodging(place);
        	       break;

             case '0': system("clear");
             	       break;

             default: system("clear");
		      cout<<"INCORRECT CHOICE"<<endl;
                      goto M;

    	}
}

void User::getdetails(char * inp)
{
    char ch;
    cout<<"WHAT DETAILS YOU WANT TO KNOW ABOUT THE PLACE?"<<endl;
    C:

    	cout<<"1. ALL DETAILS"<<endl;
   	cout<<"2. DESCRIPTION"<<endl;
    	cout<<"3. VISITING PLACES"<<endl;
    	cout<<"4. TRANSPORTATION DETAILS:"<<endl;
   	cout<<"5. LODGING DETAILS:"<<endl;
   	cout<<"0 TO EXIT"<<endl;
   	cout<<"ENTER YOUR CHOICE?"<<endl;
	try
    	{
		string s;
 	 	cin>>s;
		if(s.length()!=1)
		{
			throw 10;
		}
		ch=s[0];
    	}
    	catch(int i)
    	{
		system("clear");
		cout<<"WRONG CHOICE!!!!"<<endl;
        	cout<<"PLEASE ENTER THE CORRECT CHOICE:"<<endl;
        	goto C;
    	}	
        switch(ch)
        {
            case '1':   cout<<"DESCRIPTION:"<<endl;
                        get_description(inp);
			cout<<endl;
                        cout<<"VISITING PLACES:"<<endl;
                        get_vplacedetails(inp);
			cout<<endl;
                        cout<<"TRANSPORTATION DETAILS:"<<endl;
                        get_transportdetails(inp);
			cout<<endl;
                        cout<<"LODGING DETAILS:"<<endl;
                        get_lodgingdetails(inp);
                        break;

            case '2':   cout<<"DESCRIPTION:"<<endl;
                        get_description(inp);
                        break;

            case '3':   cout<<"VISITING PLACES:"<<endl;
                        get_vplacedetails(inp);
                        break;

            case '4':   cout<<"TRANSPORTING DETAILS:"<<endl;
                        get_transportdetails(inp);
                        break;

            case '5':   cout<<"LODGING DETAILS:"<<endl;
                        get_lodgingdetails(inp);
                        break;

            case '0':   system("clear");
                        break;

            default: cout<<"INCORRECT CHOICE"<<endl;
                     goto C;
                     break;
        }

    D:
	cout<<endl;
	cout<<endl;
    	cout<<"WANT TO KNOW  MORE DETAILS PRESS Y ELSE N?"<<endl;
   	char  c;
    	try
    	{
		string s;
 	 	cin>>s;
		if(s.length()!=1)
		{
			throw 10;
		}
		c=s[0];
		if(c=='Y'||c=='y')
        	  goto C;
		else
		if(c=='N'||c=='n')
		{}
		else
		 throw 100;
    	}
    	catch(int i)
    	{
		system("clear");
		cout<<"WRONG CHOICE!!!!"<<endl;
        	cout<<"PLEASE ENTER THE CORRECT CHOICE:"<<endl;
        	goto D;
    	}
}



