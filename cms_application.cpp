/*-----------------------------------------------------------------------------
----------------------  @AuthorName: Akshay Jain  -----------------------------
-----------------------------------------------------------------------------*/
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

char un[20];

class Admin
{
private:
  char name[20];
  int totsub;
  char subject[10][10];
  char mobile[15],mail[50],fname[20];
  char passwd[20],rpasswd[20];
public:
  char rollno[15];

//this function is used to get the student data entry from the ADMIN portal. . . .
//all the entries are made by this method
  void getstdata()
  {
    cout<<"\n Enter the Student Name : ";
    fgets(name,20,stdin); //gets doesnot in C++ 14 so we use fgets()
    cout<<"\n Enter the Student ID/Roll Number : ";
    cin>>rollno;
    cout<<"\n Enter the Student Father's Name : ";
    fgets(fname,20,stdin);
    cout<<"\n Enter the Mobile Number : ";
    fgets(mobile,15,stdin);
    cout<<"\n Enter the Email ID : ";
    fgets(mail,50,stdin);
    cout<<"\n Enter the Total Subjects : ";
    cin>>totsub;
    int i;
    for(i=0;i<totsub;i++)
    {
      cout<<"\n Enter the Subject "<<i+1<<" Name : ";
      cin>>subject[i];
    }
    cout<<"\n Create Your Login Password : ";
    cin>>passwd;
    cout<<"\n Enter the Unique Keyword to Recover Password : ";
    cin>>rpasswd;
    cout<<"\n\n Please note your Username is your ID/Roll Number \n";
  }

//this function aunthenticates the login of both the students and faculties.
//With their refernece to their unique ID/PASSWORD login is provided
  int login()
  {
    if((strcmp(::un,rollno))==0)
    {
      cout<<"\n Enter the Login Password : ";
      int len=0;
      len=strlen(passwd);
      char inputpasswd[20];
      int i;
      for(i=0;i<len;i++)
      {
        inputpasswd[i]=getchar(); // getch doesnot work for linux so we can getchar()
        cout<<"#";
      }
      //inputpasswd[i]=NULL;
      cout<<"\n The Entered Password is "<<inputpasswd; //You can comment this if you don't want to show the password
      if((strcmp(::un,rollno)==0)&&(strcmp(passwd,inputpasswd)==0))
        return 1;
      else
        return 0;
    }
    else
      return 0;
  }

//this function help both the students and the faculties to recover the password
//with the help of unnique keyword provided by the Admin
  int recover()
  {
    cout<<"\n The Input Username is "<<::un;
    char key[20];
    if(strcmp(::un,rollno)==0)
    {
      cout<<"\n Enter the Unique Keyword (Provided by the Admin) : ";
      cin>>key;
      if((strcmp(key,rpasswd)==0))
      {
        cout<<"\n You are a Valid User.";
        cout<<"\n Your Password is "<<passwd;
        cout<<"\n Please Exit to Login Again ";
        return 1;
      }
      else
        return 0;
    }
    else
      return 0;
  }

//this function displays the faculty profile to the faculty at their respective portals
  int faprofile()
  {
    if((strcmp(::un,rollno)==0))
    {
      cout<<"\n Faculty Name          :"<<name;
      cout<<"\n Faculty Father's Name :"<<fname;
      cout<<"\n Faculty Mobile Number :"<<mobile;
      cout<<"\n Faculty Email ID      :"<<mail;
      return 1;
    }
    else
      return 0;
  }

//this function displays the different subjects of the faculty at their
//respectively portals
  int knowfasub()
  {
    if((strcmp(::un,rollno)==0))
    {
      cout<<"\n Faculty Total Subjects :- "<<totsub;
      int i;
      for(i=0;i<totsub;i++)
      {
        cout<<"\n\t Subject "<<i+1<<" : "<<subject[i];
      }
      return 1;
    }
    else
      return 0;
  }

//this function helps a faculty to add a subject in their module
  void addfasub()
  {
    if((strcmp(::un,rollno)==0))
    {
      cout<<"\n Enter the New Subject : ";
      cin>>subject[totsub];
      totsub++;
      cout<<"\n\n New Subject Added Successfully...";
    }
  }

//this function helps a faculty to delete a subject from their module
  void delfasub()
  {
    knowfasub();
    int de=0;
    if((strcmp(::un,rollno)==0))
    {
      if(totsub==0||totsub<0)
      {
        totsub=0;
        cout<<"\n None Subjects Exist...";
        getchar();
        exit(0);
      }
      cout<<"\n Enter the Subject No. to be Deleted : ";
      cin>>de;
      if(de==totsub)
      {
        totsub--;
        strcpy(subject[totsub]," ");
      }
      else if(totsub==1)
      {
        totsub=0;
        strcpy(subject[totsub]," ");
      }
      else
      {
        de--;
        strcpy(subject[totsub]," ");
        int p;
        for(p=de;p<totsub;p++)
        {
          strcpy(subject[p],subject[p+1]);
        }
        totsub--;
      }
      cout<<"\n Records Updated Successfully...";
    }
  }

//this function helps a faculty to modify his personal profile
  void modfaprofile()
  {
    if((strcmp(::un,rollno)==0))
    {
      cout<<"\n The Profile Details are : ";
      cout<<"\n 1. Faculty E-Mail : "<<mail;
      cout<<"\n 2. Faculty Mobile : "<<mobile;
      int g=-1;
      cout<<"\n\n Enter the Detail No. to be Modified : ";
      cin>>g;
      if(g==1)
      {
        char nmail[50];
        cout<<"\n Enter the New Mail Address : ";
        strcpy(mail,nmail);
        cout<<"\n Records Updated Successfully...";
      }
      else if (g==2)
      {
        char nmobile[15];
        cout<<"\n Enter the New Mobile No. : ";
        fgets(nmobile,15,stdin);
        strcpy(mobile,nmobile);
        cout<<"\n Records Updated Successfully...";
      }
      else
        cout<<"\n Invalid Input Provieded...";
    }
  }

//this function displays the student profile at the student portal
  int stprofile()
  {
    if((strcmp(::un,rollno)==0))
    {
      cout<<"\n Student Name          :"<<name;
      cout<<"\n Student Father's Name :"<<fname;
      cout<<"\n Student Mobile Number :"<<mobile;
      cout<<"\n Student E-Mail ID     :"<<mail;
      return 1;
    }
    else
      return 0;
  }

//this function displays the different enrolled subjects of the respective
//students... according to their profile.
  int knowstsub()
  {
    if((strcmp(::un,rollno)==0))
    {
      cout<<"\n Student Total Subjects :- "<<totsub;
      int i;
      for(i=0;i<totsub;i++)
      {
        cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
      }
      return 1;
    }
    else
      return 0;
  }

//this function allows the student to add a subject in total subjects of the
//student Profile
  void addstsub()
  {
    if((strcmp(::un,rollno)==0))
    {
      cout<<"\n Enter the New Subject :";
      cin>>subject[totsub];
      totsub++;
      cout<<"\n\n New Subject Added Successfully...";
    }
  }

//this fucntion allows the student to delete a subject in total subjects
//of the student profile
  void delstsub()
  {
    knowstsub();
    int de=0;
    if((strcmp(::un,rollno)==0))
    {
      if(totsub==0||totsub<0)
      {
        totsub=0;
        cout<<"\n None Subjects Exist...";
        getchar();
        exit(0);
      }
      cout<<"\n Enter the Subject No. to be Deleted : ";
      cin>>de;
      if(de==totsub)
      {
        totsub--;
        strcpy(subject[totsub]," ");
      }
      else if(totsub==1)
      {
        totsub=0;
        strcpy(subject[totsub]," ");
      }
      else
      {
        de--;
        strcpy(subject[totsub]," ");
        int p;
        for(p=de;p<totsub;p++)
        {
          strcpy(subject[p],subject[p+1]);
        }
        totsub--;
      }
      cout<<"\n Records Updated Succesfully...";
    }
  }

//this function allows the student to modify their personal profile details at
//the student portal
  void modstprofile()
  {
    if((strcmp(::un,rollno)==0))
    {
      cout<<"\n The Profile Details are : ";
      cout<<"\n 1. Student E-Mail ID : "<<mail;
      cout<<"\n 2. Student Mobile    : "<<mobile;
      int g=-1;
      cout<<"\n\n Enter the Detail no. to be modified : ";
      cin>>g;
      if(g==1)
      {
        char nmail[50];
        cout<<"\n Enter the New Mail Address : ";
        strcpy(mail,nmail);
        cout<<"\n Records Updated Successfully...";
      }
      else if (g==2)
      {
        char nmobile[15];
        cout<<"\n Enter the New Mobile No. : ";
        fgets(nmobile,15,stdin);
        strcpy(mobile,nmobile);
        cout<<"\n Records Updated Successfully...";
      }
      else
        cout<<"\n Invalid Input Provided...";
    }
  }

//this function allow the ADMIN to make a new record entry for the different
//new faculties...new faculty records are updated with the help of
//this function
 void getfadata()
 {
   cout<<"\nEnter the Faculty Name : ";
   fgets(name,20,stdin);
   cout<<"\nEnter the Faculty ID/Roll no. : ";
   cin>>rollno;
   cout<<"\nEnter the Faculty Father's Name : ";
   fgets(fname,20,stdin);
   cout<<"\nEnter the Mobile No. : ";
   fgets(mobile,15,stdin);
   cout<<"\nEnter the E-Mail ID : ";
   fgets(mail,50,stdin);
   cout<<"\n Enter the Total Subjects : ";
   cin>>totsub;
   cout<<"\n The Total Subjects chosen are : "<<totsub; //Optional
   int i;
   for(i=0;i<totsub;i++)
   {
     cout<<"\nEnter the Subject "<<i+1<<" Name : ";
     cin>>subject[i];
   }
   cout<<"\n Create Your Login Password : ";
   cin>>passwd;
   cout<<"\n Enter the Unique Keyword to Recover Password : ";
   cin>>rpasswd;
   cout<<"\n\n Please note your UserName is ID/Roll Number: \n";
 }

//this function displays all the relevant information to the admin related to
//the students at the ADMIN portals
  void stdisplay()
  {
    cout<<"\nStudent Name             :"<<name;
    cout<<"\nStudent ID/Roll Number   :"<<rollno;
    cout<<"\nStudent Father's Name    :"<<fname;
    cout<<"\nStudent Mobile Number    :"<<mobile;
    cout<<"\nStudent E-Mail ID        :"<<mail;
    cout<<"\nStudent Subjects         :"<<totsub;
    int i;
    for(i=0;i<totsub;i++)
    {
      cout<<"\n   Subject "<<i+1<<" : "<<subject[i];
    }
    if(totsub==0)
      cout<<"( None Subjects Specified... )";
  }

//this function displays all the relevant information to the admin related to
//the faculty at the ADMIN portals
  void fadisplay()
  {
    cout<<"\n Faculty Name            :"<<name;
    cout<<"\n Faculty ID/Roll Number  :"<<rollno;
    cout<<"\n Faculty Father's Name   :"<<fname;
    cout<<"\n Faculty Mobile No.      :"<<mobile;
    cout<<"\n Faculty E-Mail ID       :"<<mail;
    cout<<"\n Faculty Subjects        :"<<totsub;
    int i;
    for(i=0;i<totsub;i++)
    {
      cout<<"\n   SUbject "<<i+1<<" : "<<subject[i];
    }
    if(totsub==0)
      cout<<"None Subjects Specified...";
  }
}a;
Admin f; //a&f are objects of the class ADMIN

int main()
{
  int ch;
  //clrscr();
  cout<<"\n\n\n\t\t\t Welcome to IIIT DHARWAD Database Portal ";
  cout<<"\n\n\n\t\t\t\t Enter to Continue";
  getchar();
  //clrscr();
 cout<<"\n\n\n\t\t\tPress 1 for Admin Portal";
  cout<<"\n\t\t\t\t Press 2 for Faculty Portal";
  cout<<"\n\t\t\t\t Press 3 for Student Portal";
  cout<<"\n\n\t\t\tEnter Your Choice: ";
  cin>>ch;
  //clrscr();
  if(ch==1)
  {
    char adminuser[20],adminpass[20];
    cout<<"\n\t\t\tWelcome to Admin Login Portal ";
    cout<<"\n\nEnter the UserName : ";
    cin>>adminuser;
    cout<<"\nEnter the Password : ";
    int k;
    for(k=0;k<8;k++)
    {
      adminpass[k]=getchar();
      cout<<"*";
    }
    getchar();
    //adminpass[k]=NULL;
    if(strcmp(adminuser,"admin")==0&&(strcmp(adminpass,"password")==0))
    {
      //clrscr();
    }
    else
    {
      cout<<"\n\n\t\t\t  Invalid Access to Portal ";
      cout<<"\n\n\t\t\t\tThank You !!!";
      getchar();
      exit(0);
    }
    char opera='y';
    do
    {
        int tmp;
        cout<<"\n\t\t\t\tWelcome to Admin Panel";
        cout<<"\n\nPress 1 to Add a Faculty Record";
        cout<<"\nPress 2 to Add Multiply Records of Faculty ";
        cout<<"\nPress 3 to view All Records of Faculty";
        cout<<"\nPress 4 to Delete a faculty Record";
        cout<<"\nPress 5 to Add a Student Record ";
        cout<<"\nPress 6 to Add Multiple Records of Students ";
        cout<<"\nPress 7 to View All Records of Students ";
        cout<<"\nPress 8 to Delete a Student Record ";
        cout<<"\nPress 9 to Exit";
        cout<<"\n\n\tEnter Your Choice : ";
        cin>>tmp;
        //clrscr();
        if(tmp==1)//for inserting d single faculty records
        {
          cout<<"\nEnter the Details :- ";
          fstream fs;
          fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
          a.getfadata();
          fs.write((char*)&a,sizeof(Admin));
          fs.close();
          cout<<"\nRecord Entered Succesfully...";
        } //for inserting d multiple faculty records
        if(tmp==2) //for inserting d multiple faculty records
        {
          int m=0;
          fstream fs;
          fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
          do
          {
            cout<<"\nEnter the Details :- ";
            a.getfadata();
            fs.write((char*)&a,sizeof(Admin));
            cout<<"Press 0 if you want to Enter More Records : ";
            cin>>m;
          } while(m==0);
          fs.close();
          cout<<"\nRecord Entered Successfully...";
        }//for inserting d multiple faculty records
        if(tmp==3)//for view all faculty records
        {
          fstream fs;
          fs.open("fainfo,txt",ios::in);
          fs.seekg(0);
          while(!fs.eof())
          {
            fs.read((char*)&a,sizeof(Admin));
            a.fadisplay();
          }
          fs.close();
        }//for view all faculty records
        if(tmp==4)  //for deleting a faculty record
        {
            char tmpfaid[15];
            int de=0,result=-1;
            cout<<"\nEnter the Faculty ID/Rollno. :-";
            cin>>tmpfaid;
            fstream fs;
            fs.open("fainfo.txt",ios::in);
            fstream fs1;
            fs1.open("fanewinfo.txt",ios::out|ios::ate);
            while(!fs.eof())
            {
              fs.read((char*)&a,sizeof(Admin));
              result=strcmp(tmpfaid,a.rollno);
              if(result==0)
              {
                de=-1;
              }
              else
                fs1.write((char*)&a,sizeof(Admin));
            }
            if(de==1)
              cout<<"\nRecord Deleted Successfully...";
            else
              cout<<"\nRecord not found...";
            fs.close();
            fs1.close();
            remove("fainfo.txt");
            rename("fanewinfo.txt","fainfo.txt");
        }//for deleting a faculty records
        if(tmp==5)//for single student record input
        {
          cout<<"\nEnter the Details :- ";
          fstream fs;
          fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
          a.getstdata();
          fs.write((char*)&a,sizeof(Admin));
          fs.close();
          cout<<"\nRecord Entered Successfully...";
        }//for single student record input
        if(tmp==6)//for multiple student record imput
        {
          int m=0;
          fstream fs;
          fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
          do
          {
            cout<<"\nEnter the Details :- ";
            a.getstdata();
            fs.write((char*)&a,sizeof(Admin));
            cout<<"Press 0 if you want to Enter More Records : ";
            cin>>m;
          } while(m==0);
          fs.close();
          cout<<"\nRecord Entered Successfully...";
        }//for multiple student record input
        if(tmp==7)//for view of all student record
        {
          fstream fs;
          fs.open("stinfo.txt",ios::in);
          fs.seekg(0);
          while(!fs.eof())
          {
            fs.read((char*)&a,sizeof(Admin));
            a.stdisplay();
          }
          fs.close();
        }//for view of all student record
        if(tmp==8)//for deleting a student record
        {
          char tmpstid[15];
          int de=0,result=-1;
          cout<<"\nEnter the Student ID/Rollno. :- ";
          cin>>tmpstid;
          fstream fs;
          fs.open("stinfo.txt",ios::in);
          fstream fs1;
          fs1.open("stnewinfo.txt",ios::out|ios::ate);
          while(!fs.eof())
          {
            fs.read((char*)&a,sizeof(Admin));
            result=strcmp(tmpstid,a.rollno);
            if(result==0)
              de=1;
            else
              fs1.write((char*)&a,sizeof(Admin));
          }
          if(de==1)
            cout<<"\nRecord Deleted Successfully...";
          else
            cout<<"\nRecord not found...";
          fs.close();
          fs1.close();
          remove("stinfo.txt");
          rename("stnewinfo.txt","stinfo.txt");
        }//for deleting a student record
        if(tmp==9)
        {
          cout<<"\n\n\n\n\t\t\t\tThank You !!!";
          getchar();
          exit(0);
        }//for exit
        if(tmp<1||tmp>9)
        {
          //clrscr();
          cout<<"\n\n\n\t\t\t\tInvalid Input .....";
        }//for invalid input among choice of operation
        getchar();
        cout<<"\n\nPress y : For More Operations otherwise n : ";
        cin>>opera;
        if(opera!='y')
        {
          getchar();
          //clrscr();
          cout<<"\n\n\n\n\n\t\t\t\t\tThank You !!!";
          getchar();
        } //closing of thank you
    } while(opera=='Y'||opera=='y');
  }   //closing of admin login

  if(ch==2)   //begin of faculty view portal
  {
    //clrscr();
    char un[20];
    int val,s=0;
    cout<<"\n\t\t\tWelcome to Faculty Login Page";
    cout<<"\n\nEnter the UserName : ";
    cin>>::un;
    fstream fs;
    fs.open("fainfo.txt",ios::in|ios::binary);
    fs.seekg(0);
    while(!fs.eof())
    {
      val=-1;
      fs.read((char*)&f,sizeof(Admin));
      val=f.login();
      if(val==1)
      {
        s=1;
        break;
      }
    }
    fs.close();
    if(s==1)
    {
      //clrscr();
    }//if first login is valid
    if(s!=1)//if first login is invalid then
    {
      //clrscr
      int ho=0;
      cout<<"\n\n\t\tYour Login Credentials are In-Correct";
      cout<<"\nThe UserName is Your ID/Rollno.";
      cout<<"\nThe Password is Case-Sensitive.";
      cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attemp Login";
      cout<<"\nEnter the Choice : ";
      cin>>ho;
      if(ho==1)//recover password
      {
        cout<<"Enter the UserName :- ";
        cin>>::un;
        fstream fs;
        fs.open("fainfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        int re,su=-1;
        while(!fs.eof())
        {
          re=-1;
          fs.read((char*)&f,sizeof(Admin));
          re=f.recover();
          if(re==1)
          {
            su=1;
            break;
          }
        }
        fs.close();
        if(su==1)
        {
          getchar();
          //clrscr();
          cout<<"\n\n\n\n\t\t\tThank You !!!";
          getchar();
          exit(0);
        }
        else
        {
          cout<<"\nYou are a Invalid User.";
          getchar();
          exit(0);
        }
      }//recover password
      if(ho==2)//re-attempt of login
      {
        cout<<"\n\nEnter the UserName : ";
        cin>>::un;
        fstream fs;
        fs.open("fainfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        int suc=-1,valu; //valu for storing login() returned value suc for
                        //success login
        while(!fs.eof())
        {
          valu=-1;
          fs.read((char*)&f,sizeof(Admin));
          valu=f.login();
          if(valu==1)
          {
            suc=1;
            break;
          }
        }
        fs.close();
        if(suc==1)
        {
          //clrscr();
        }
        else
        {
          getchar();
          cout<<"\nYou are an Invalid User...";
          cout<<"\nThank You !!!";
          getchar();
          exit(0);
          exit(0);
        }
      }
      if(ho!=1&&ho!=2)
      {
        cout<<"\n\nInvalid Input Provided. ";
        cout<<"\n\n\t\t\tThank You !!!";
        getchar();
        exit(0);
      }
    }//CLOSING OF first invalid login(forget password and recover password)
    //getchar();

    //Begin of Faculty Panel
    char con='y';

    do
    {
      //clrscr();
      cout<<"\n\n\t\t\tWelcome to Faculty Panel  ";
      cout<<"\n\n\t\t\t\t\t\t    Your UserId is : "<<::un;
      cout<<"\n\nPress 1 to View your Profile";
      cout<<"\nPress 2 to know your Subjects";
      cout<<"\nPress 3 to Add a Subject";
      cout<<"\nPress 4 to Delete a Subject";
      cout<<"\nPress 5 to Modify Your Profile";
      int choice;
      cout<<"\n\nEnter Your Choice : ";
      cin>>choice;
      if(choice==1)
      {
        fstream fs;
        fs.open("fainfo.txt",ios::in);
        fs.seekg(0);
        int x;
        while(!fs.eof())
        {
          x=0;
          fs.read((char*)&f,sizeof(Admin));
          x=f.faprofile();
          if(x==1)
            break;
        }
        fs.close();
      }//closing choice = 1
      if(choice==2)
      {
        fstream fs;
        fs.open("fainfo.txt",ios::in);
        fs.seekg(0);
        int y;
        while(!fs.eof())
        {
          y=0;
          fs.read((char*)&f,sizeof(Admin));
          y=f.knowfasub();
          if(y==1)
            break;
        }
        fs.close();
      }//closing choice = 2
      if(choice==3)
      {
        fstream fs;
        fstream fs1;
        fs.open("fainfo.txt",ios::in|ios::binary);
        fs1.open("tmpfainfo.txt",ios::out|ios::ate);
        fs.seekg(0);
        while(!fs.eof())
        {
          fs.read((char*)&f,sizeof(Admin));
          f.addfasub();
          fs1.write((char*)&f,sizeof(Admin));
        }
        fs.close();
        fs1.close();
        remove("fainfo.txt");
        rename("tmpfainfo.txt","fainfo.txt");
      }//closing choice = 3
      if(choice==4)
      {
        fstream fs;
        fs.open("fainfo.txt",ios::in|ios::binary);
        fstream fs1;
        fs1.open("delfainfo.txt",ios::out|ios::ate);
        fs.seekg(0);
        while(!fs.eof())
        {
          fs.read((char*)&f,sizeof(Admin));
          f.delfasub();
          fs1.write((char*)&f,sizeof(Admin));
        }
        fs.close();
        fs1.close();
        remove("fainfo.txt");
        rename("delfainfo.txt","fainfo.txt");
      }//closing choice = 4
      if(choice==5)
      {
        fstream fs;
        fstream fs1;
        fs.open("fainfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        fs1.open("modfainfo.txt",ios::out|ios::ate);
        while(!fs.eof())
        {
          fs.read((char*)&f,sizeof(Admin));
          f.modfaprofile();
          fs1.write((char*)&f,sizeof(Admin));
        }
        fs.close();
        fs1.close();
        remove("fainfo.txt");
        rename("modfainfo.txt","fainfo.txt");
      }//closing choice = 5
      if(choice<1||choice>5)
        cout<<"\nInvalid Input Provided !!!";
      cout<<"\n\n\t\t\t\tEnter to Continue";
      getchar();
      cout<<"\n\nPress y to Continue ; otherwise n : ";
      cin>>con;
      if(con!='y' && con!='Y')
      {
        //clrscr();
        cout<<"\n\n\n\n\n\t\t\t\t Thank You !!!";
        getchar();
        exit(0);
      }
    } while(con=='y'||con=='Y');
  }//close of faculty View

  //begin of student View
  if(ch==3)   //begin of student view
  {
    //clrscr();
    //char un[20];
    int value,s1=0;
    cout<<"\n\t\t\tWelcome to Student Login Page";
    cout<<"\n\nEnter the UserName : ";
    cin>>::un;
    fstream fs;
    fs.open("stinfo.txt",ios::in|ios::binary);
    fs.seekg(0);
    while(!fs.eof())
    {
      value=-1;
      fs.read((char*)&f,sizeof(Admin));
      value=f.login();
      if(value==1)
      {
        s1=1;
        break;
      }
    }
    fs.close();
    if(s1==1)
    {
      //clrscr();
      //cout<<"\n\n\n\t\t\t\tWelcome to Student Page ";
    }//if first login is valid
    if(s1!=1)//if first login is invalid then
    {
      //clrscr();
      int sho=0;
      cout<<"\n\n\t\tYour Login Credentials are In-Correct";
      cout<<"\nThe UserName is Your ID/Rollno.";
      cout<<"\nThe Password is Case-Sensitive.";
      cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attemp Login";
      cout<<"\nEnter the Choice : ";
      cin>>sho;
      if(sho==1)//recover password
      {
        cout<<"Enter the UserName :- ";
        cin>>::un;
        fstream fs;
        fs.open("stinfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        int re,su=-1;
        while(!fs.eof())
        {
          re=-1;
          fs.read((char*)&f,sizeof(Admin));
          re=f.recover();
          if(re==1)
          {
            su=1;
            break;
          }
        }
        fs.close();
        if(su==1)
        {
          getchar();
          //clrscr();
          cout<<"\n\n\n\n\t\t\tThank You !!!";
          getchar();
          exit(0);
        }
        else
        {
          cout<<"\nYou are a Invalid User.";
          cout<<"\nThank You !!! ";
          getchar();
          exit(0);
        }
      }//recover password
      if(sho==2)//re-attempt of login
      {
        cout<<"\n\nEnter the UserName : ";
        cin>>::un;
        fstream fs;
        fs.open("stinfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        int suc=-1,valu; //valu for storing login() returned value suc for
                        //success login
        while(!fs.eof())
        {
          valu=-1;
          fs.read((char*)&f,sizeof(Admin));
          valu=f.login();
          if(valu==1)
          {
            suc=1;
            break;
          }
        }
        fs.close();
        if(suc==1)
        {
          //clrscr();
        }
        else
        {
          getchar();
          cout<<"\nYou are an Invalid User...";
          cout<<"\nThank You !!!";
          getchar();
          exit(0);
          exit(0);
        }
      }
      if(sho!=1 && sho!=2)
      {
        cout<<"\n\nInvalid Input Provided. ";
        cout<<"\n\n\t\t\tThank You !!!";
        getchar();
        exit(0);
      }
    }//CLOSING OF first invalid login(forget password and recover password)
    //getchar();

    //Begin of Student Panel
    char moreop='y';

    do
    {
      //clrscr();
      cout<<"\n\n\t\t\tWelcome to Student Panel  ";
      cout<<"\n\n\t\t\t\t\t\t    Your UserId is : "<<::un;
      cout<<"\n\nPress 1 to View your Profile";
      cout<<"\nPress 2 to know your Subjects";
      cout<<"\nPress 3 to Add a Subject";
      cout<<"\nPress 4 to Delete a Subject";
      cout<<"\nPress 5 to Modify Your Profile";
      int inchoice;
      cout<<"\n\nEnter Your Choice : ";
      cin>>inchoice;
      if(inchoice==1)
      {
        fstream fs;
        fs.open("stinfo.txt",ios::in);
        fs.seekg(0);
        int x;
        while(!fs.eof())
        {
          x=0;
          fs.read((char*)&f,sizeof(Admin));
          x=f.stprofile();
          if(x==1)
            break;
        }
        fs.close();
      }//closing of inchoice = 1
      if(inchoice==2)
      {
        fstream fs;
        fs.open("stinfo.txt",ios::in);
        fs.seekg(0);
        int y;
        while(!fs.eof())
        {
          y=0;
          fs.read((char*)&f,sizeof(Admin));
          y=f.knowstsub();
          if(y==1)
            break;
        }
        fs.close();
      }//closing of inchoice = 2
      if(inchoice==3)
      {
        fstream fs;
        fstream fs1;
        fs.open("stinfo.txt",ios::in|ios::binary);
        fs1.open("tmpstinfo.txt",ios::out|ios::ate);
        fs.seekg(0);
        while(!fs.eof())
        {
          fs.read((char*)&f,sizeof(Admin));
          f.addstsub();
          fs1.write((char*)&f,sizeof(Admin));
        }
        fs.close();
        fs1.close();
        remove("stinfo.txt");
        rename("tmpstinfo.txt","stinfo.txt");
      }//closing inchoice = 3
      if(inchoice==4)
      {
        fstream fs;
        fs.open("stinfo.txt",ios::in|ios::binary);
        fstream fs1;
        fs1.open("delstinfo.txt",ios::out|ios::ate);
        fs.seekg(0);
        while(!fs.eof())
        {
          fs.read((char*)&f,sizeof(Admin));
          f.delfasub();
          fs1.write((char*)&f,sizeof(Admin));
        }
        fs.close();
        fs1.close();
        remove("stinfo.txt");
        rename("delstinfo.txt","stinfo.txt");
      }//closing inchoice = 4
      if(inchoice==5)
      {
        fstream fs;
        fstream fs1;
        fs.open("stinfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        fs1.open("modstinfo.txt",ios::out|ios::ate);
        while(!fs.eof())
        {
          fs.read((char*)&f,sizeof(Admin));
          f.modstprofile();
          fs1.write((char*)&f,sizeof(Admin));
        }
        fs.close();
        fs1.close();
        remove("stinfo.txt");
        rename("modstinfo.txt","stinfo.txt");
      }//closing inchoice = 5
      if(inchoice<1||inchoice>5)
        cout<<"\nInvalid Input Provided !!!";
      cout<<"\n\n\t\t\t\tEnter to Continue";
      getchar();
      cout<<"\n\nPress y to Continue ; otherwise n to Perform More Operations : ";
      cin>>moreop;
      if(moreop!='y' && moreop!='Y')
      {
        //clrscr();
        cout<<"\n\n\n\n\n\t\t\t\t Thank You !!!";
        getchar();
        exit(0);
      }
    } while(moreop=='y'||moreop=='Y');
    getchar();
  }//close of student panel ch=3
  if(ch<1||ch>3)
  {
    cout<<"\nInvalid Input Provided";
    getchar();
    //clrscr();
    cout<<"\n\n\n\t\t\tThank You !!!";
  }
}
