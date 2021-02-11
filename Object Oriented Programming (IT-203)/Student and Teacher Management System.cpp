#include <iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include <windows.h>

using namespace std;

class person{

protected:

string name;
string dob;
string phone_no;
string email_id;



};


class student :  public person
{

 private:
    int rollno;
    string adm_no;
     string stream;    
    int physics,chemistry,maths,english,computer,biology;
    float percentage; 
    char grade;


public: 
 
 friend class teacher;

void get_student_marks();
void show_student_marks();
void calculate_grade(); 
void show_tabular(int i);
void friend display_student_marks();
void friend class_result();
void get_student_data();
void show_student_data();


int ret_rollno(){
return rollno;

}

string ret_stream(){
    return stream;
}
};


class teacher:  public person{

private : string subject;

protected:

string ID;
string year_of_joining;
int salary;

public:

void show_teacher_data();
void get_teacher_data();
void Enter_Marks();
void modify_student_marks();
void delete_student();
void friend display_student_marks();
void friend class_result();
void Password(int p);
void sortper();
void sortmark();


string ret_id(){

    return ID;
}

};

class admin : public teacher{

public:

void add_teacher_record();
void add_student_record();
void show_all_student();
void show_all_teacher();
void delete_teacher_record();
void modify_teacher_record();
void friend class_result();

}; 



fstream fp1,fp2;
student st;
teacher t;
admin a;


void teacher_menu();
void student_menu();
void admin_menu();
void Main_menu();
void Welcome();

 void student::show_tabular(int i)
    {
        cout<<rollno<<setw(9)<<name<<setw(10)<<physics<<setw(3)<<chemistry<<setw(3)<<maths<<setw(3)<<english<<setw(3);
        if(i==1)
        cout<<computer;
      else cout<<biology;
      cout<<setw(6)<<setprecision(3)<<percentage<<"   "<<grade<<endl;
    }


void student::calculate_grade()
    {      if(stream=="C")
            percentage=(physics+chemistry+maths+english+computer)/5.0;
           else
            percentage=(physics+chemistry+maths+english+biology)/5.0;

        if(percentage>=90)
            grade='A';
        else if(percentage>=70 && percentage<90)
            grade='B';
        else if(percentage>=50 && percentage<70)
            grade='C';
        else if (percentage>=30 && percentage<50)
            grade='D';
        else grade='F';
}


void student::show_student_marks()
    {
         system("cls");

        cout<<"\n\n\n\n\t\t\t\tRoll number:  "<<rollno;
        cout<<"\n\n\t\t\t\tName:  "<<name;
        cout<<"\n\n\t\t\t\tStream:  "<<stream;
        cout<<"\n\n\n\n\t\t\t\t------------------------------------------\n";
           cout<<"\t\t\t\t\tACADEMIC PERFORMANCE\n";
           cout<<"\t\t\t\t------------------------------------------\n";
           cout<<"\n\n\n\t\t\t\t------------------------------------------\n";
           cout<<"\t\t\t\t\t\tMARKS\n";
           cout<<"\t\t\t\t------------------------------------------\n";
           
           
               cout<<"\n\n\n\t\t\t\t\t  PHYSICS:\t"<<physics;
               cout<<"\n\n\t\t\t\t\t  CHEMISTRY:\t"<<chemistry;
               cout<<"\n\n\t\t\t\t\t  MATHS:\t"<<maths;
               cout<<"\n\n\t\t\t\t\t  ENGLISH:\t"<<english;
               if(stream=="C")
               cout<<"\n\n\t\t\t\t\t  COMPUTER:\t"<<computer;
             else 
               cout<<"\n\n\t\t\t\t\t  BIOLOGY:\t"<<biology;

               cout<<"\n\n\n\t\t\t  GRADE:\t"<<grade;
               cout<<"\n\n\n\t\t\t  PERCENTAGE:\t"<<percentage;
           
    }


void student::get_student_marks()
    {      
             
            t:
            try{
              cout<<"\n\n\n\t\t\t\t  -----------------------------"<<"\n";
              cout<<"\n\t\t\t\t     ENTER THE SUBJECT MARKS"<<"\n";
              cout<<"\n\t\t\t\t  -----------------------------"<<"\n\n";
              cout<<"\n\n\t\t\t\t       PHYSICS    : ";
              cin>>physics;
              cout<<"\n\n\t\t\t\t       CHEMISTRY  : ";
              cin>>chemistry;
              cout<<"\n\n\t\t\t\t       MATHEMATICS: ";
              cin>>maths;
              if(stream=="C"){
              cout<<"\n\n\t\t\t\t       COMPUTER   : ";
              cin>>computer;
          }
          else {
           cout<<"\n\n\t\t\t\t       BIOLOGY   : ";
              cin>>biology;

          }
              cout<<"\n\n\t\t\t\t       ENGLISH    : ";
              cin>>english;
        st.calculate_grade();

if(physics > 100 or chemistry > 100 or maths >100 or computer > 100 or english >100 or biology > 100)
throw 1;        
}
catch(int i){

  cout<<"\n\n\n\t\t\tMarks Entered are invalid ! Enter again !!";
    Sleep(1000);

  goto t;
}



    }


void student::get_student_data(){

r:
system("cls");
try{
cout<<"\n\n\n\n\t\t\t\t  -------------------------------"<<"\n";
           cout<<"\n\t\t\t\t     ENTER THE STUDENT DETAILS"<<"\n";
           cout<<"\n\t\t\t\t  -------------------------------"<<"\n\n";
           cout<<"\n\n\t\t\t\tNAME OF THE STUDENT    : ";
           cin.ignore();
           getline(cin,name);
           cout<<"\n\n\t\t\t\tENTER STREAM (C/B)  : ";
          cin>>stream;           
           cout<<"\n\n\t\t\t\tDATE OF BIRTH            : ";
           cin>>dob;
           cin.ignore();
           cout<<"\n\n\t\t\t\tPHONE NO            : ";
           getline(cin,phone_no);
           cout<<"\n\n\t\t\t\tEMAIL ID            : ";
           getline(cin,email_id);
           
           cout<<"\n\n\t\t\t\tADMISSION NO            : ";
           getline(cin,adm_no);
            cout<<"\n\n\t\t\t\tROLL NO            : ";
           cin>>rollno;
           
      if(name=="" or phone_no=="" or email_id=="" or adm_no=="" ) throw 1;
      if(stream!="C" and stream!="B") throw 1;
     
     if(dob.size()>12)
       throw 'a';
      
      if(phone_no.size()!=10) throw 6.2;

      
    
}


catch(int i){
    cout<<"\n\n\n\t\t\tInfo Entered is Empty !! Enter again !!";
    Sleep(1000);

    goto r;
}

catch(char  c){
cout<<"\n\n\t\t\tAge is Invalid ! Enter again !!";
    Sleep(1000);

goto r;

}

catch(double i){
   cout<<"\n\n\n\t\t\t Phone No is Invalid ! Enter again !!";
    Sleep(1000);

   goto r;

}

}

void student::show_student_data(){


cout<<"\n\n\t\t\t\tName : "<<name;
cout<<"\n\n\t\t\t\tStream : "<<stream;
cout<<"\n\n\t\t\t\tRoll No : "<<rollno;
cout<<"\n\n\t\t\t\tDate of Birth : "<<dob;
cout<<"\n\n\t\t\t\tPhone no : "<<phone_no;
cout<<"\n\n\t\t\t\tEmail id : "<<email_id;
cout<<"\n\n\t\t\t\tAdmission No : "<<adm_no;

cout<<"\n\n\n\n\t\t\t\t------------------------------------------\n";
           cout<<"\t\t\t\t\tACADEMIC PERFORMANCE\n";
           cout<<"\t\t\t\t------------------------------------------\n";
           cout<<"\n\n\n\t\t\t\t------------------------------------------\n";
           cout<<"\t\t\t\t\t\tMARKS\n";
           cout<<"\t\t\t\t------------------------------------------\n";
           
           
               cout<<"\n\n\n\t\t\t\t\t  PHYSICS:\t"<<physics;
               cout<<"\n\n\t\t\t\t\t  CHEMISTRY:\t"<<chemistry;
               cout<<"\n\n\t\t\t\t\t  MATHS:\t"<<maths;
               cout<<"\n\n\t\t\t\t\t  ENGLISH:\t"<<english;
               if(stream=="C")
               cout<<"\n\n\t\t\t\t\t  COMPUTER:\t"<<computer;
           else 
               cout<<"\n\n\t\t\t\t\t  BIOLOGY:\t"<<biology;

               cout<<"\n\n\n\t\t\t  GRADE:\t"<<grade;
               cout<<"\n\n\n\t\t\t  PERCENTAGE:\t"<<percentage;
           







}





void teacher::Enter_Marks()
    {
        system("cls");
     fp1.open("student.dat",ios::in);
     int r,found=0; string stream;
          
          cout<<"\n\n\t\t\t\t ENTER STREAM (C/B)            : ";
             cin>>stream; 
          cout<<"\n\n\t\t\t\tENTER ROLL NUMBER            : ";
           cin>>r;

             while(fp1.read((char*)&st,sizeof(student)))
    {
        if(st.ret_rollno()==r and st.ret_stream()==stream){
        found=1;
        break;

        }
    }
     
     fp1.close();
     if(found==0) cout<<"\n\n\n\n\n\t\t\t\t NO STUDENT FOUND!!!! ";
     else{
      fp1.open("student.dat",ios::in|ios::out);
    while(fp1.read((char*)&st,sizeof(student)))
    {
        if(st.ret_rollno()==r and st.ret_stream()==stream)
        {
            st.get_student_marks();
            int pos=-1*sizeof(st);
            fp1.seekp(pos,ios::cur);
            fp1.write((char*)&st,sizeof(student));
           cout<<"\n\n\n\t\t\tSTUDENT MARKS ENTERED........";
            found=1;
        }
    }
    fp1.close();
        

    
   
}
    getch();

    teacher_menu();
        
    }







   

void teacher::modify_student_marks()
{
    int no,found=0;
    system("cls");
    cout<<"\n\n\n\n\t\t\t\tTo Modify ";
    string stream;
    cout<<"\n\n\t\t\t\t ENTER STREAM (C/B)           : ";
    cin>>stream; 

    cout<<"\n\n\t\t\t\t\t\tPlease Enter The roll number of student:   ";
    cin>>no;
    fp1.open("student.dat",ios::in|ios::out);
    while(fp1.read((char*)&st,sizeof(student)) && found==0)
    {
        if(st.ret_rollno()==no and st.ret_stream()==stream)
        {
            st.show_student_marks();
            cout<<"\n\n\n\n\n\t\t\t\tPlease Enter The New Marks of student!!!!!!!!!!!!!!"<<endl;
            st.get_student_marks();
            int pos=-1*sizeof(st);
            fp1.seekp(pos,ios::cur);
            fp1.write((char*)&st,sizeof(student));
            cout<<"\n\n\n\n\n\t\t\t Record Updated.........";
            found=1;
        }
    }
    fp1.close();
    if(found==0)
        cout<<"\n\n\n\n\t\t\t\t Record Not Found... ";
    getch();
    teacher_menu();
}

void teacher::delete_student()
{
    int no;
    system("cls");  student s;
    cout<<"\n\n\n\n\t\t\t\tDelete Record";
    string stream;
cout<<"\n\n\t\t\t\t ENTER STREAM  (C/B)          : ";
    cin>>stream; 
    cout<<"\n\n\t\t\t\t\tPlease Enter The roll number of student You Want To Delete :    ";
    cin>>no;
    fp1.open("student.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp1.seekg(0,ios::beg);
    while(fp1.read((char*)&st,sizeof(student)))
    {
        if(st.ret_rollno()!=no and st.ret_stream()!=stream)
        {
            fp2.write((char*)&st,sizeof(student));
        }

        else s=st;
    }
    fp2.close();
    fp1.close();
    remove("student.dat");
    rename("Temp.dat","student.dat");
    cout<<"\n\n\n\n\t\t\t\tRecord Deleted ............";
    st.show_student_marks();
    getch();
    teacher_menu();
}

void teacher::sortper()
{   system("cls");
      student t[100],temp;
      fp1.open("student.dat",ios::in);
     int n=0;

system("cls");
    int ch;
   
    
       cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t ================================================\n";
        cout<<"\t\t\t\t\t ########::ASCENDING ORDER PERCENTAGE ::#########\n";
        cout<<"\t\t\t\t\t ================================================\n\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t1. COMBINED \t\t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t2. COMPUTER STREAM \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t3. BIOLOGY STREAM \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
       
        cout<<"\n\t\t\t\t\tEnter your choice:-> ";


   int no;
    cin>>no;
    
    
    system("cls");

     if(!fp1)
     {
         cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
         cout<<"\n\n\n\n\n\n\n\n";
     }



     else
     {
         
             while(fp1.read((char*)&st,sizeof(st)))
             {    if(no==1)
                  t[n++]=st;
               if(no==2 and st.ret_stream()=="C")   
                 t[n++]=st;
                
                 if(no==3 and st.ret_stream()=="B")
                  t[n++]=st;

             }
         
         fp1.close();

         for(int i=0;i< n; i++)
         {
             for(int j=0;j<n-1;j++)
             {
                 if(t[j].percentage<t[j+1].percentage)
                 {
                     temp=t[j];
                     t[j]=t[j+1];
                     t[j+1]=temp;
                 }
             }
         }
            if(no==1){
         cout<<"\n\n\n\n\n\t\t\t\t\t\t\tTOP  STUDENTS RESULT (SORTED) \n\n";
    cout<<"\n\t\t\t\t\t=======================================================\n";
    cout<<"\t\t\t\t\tSNo  Roll No  Name          stream    %age  Grade\n";
    cout<<"\t\t\t\t\t=======================================================\n";
int j=1;
   
     for(int i=0;i<n;i++)
         {  cout<<"\t\t\t\t\t "<<j++<<"      ";
             cout<<t[i].rollno<<setw(9)<<t[i].name<<setw(14)<<t[i].stream<<setw(10)<<setprecision(3)<<t[i].percentage<<"   "<<t[i].grade<<endl;
             cout<<"\n";
         }
             cout<<"\n\n\n\t\t\t\t\t-------------------------------------------------------\n\n\n";
     }

     if(no==2){
     cout<<"\n\n\n\n\n\t\t\t\t\t\t\tTOP  STUDENTS RESULT (SORTED) \n\n";
    cout<<"\n\t\t\t\t\t=======================================================\n";
    cout<<"\t\t\t\t\tSNo  Roll No  Name        P  C  M  E  CS  %age  Grade\n";
    cout<<"\t\t\t\t\t=======================================================\n";
   

   int j=1;
   
     for(int i=0;i<n;i++)
         {  cout<<"\t\t\t\t\t "<<j++<<"      ";
             t[i].show_tabular(1);
             cout<<"\n";
         }
             cout<<"\n\n\n\t\t\t\t\t-------------------------------------------------------\n\n\n";

     }


if(no==3){

cout<<"\n\n\n\n\n\t\t\t\t\t\t\tTOP  STUDENTS RESULT (SORTED) \n\n";
    cout<<"\n\t\t\t\t\t=======================================================\n";
    cout<<"\t\t\t\t\tSNo  Roll No  Name         P  C  M  E  B  %age  Grade\n";
    cout<<"\t\t\t\t\t=======================================================\n";
   

   int j=1;
   
     for(int i=0;i<n;i++)
         {  cout<<"\t\t\t\t\t "<<j++<<"      ";
             t[i].show_tabular(2);
             cout<<"\n";
         }
             cout<<"\n\n\n\t\t\t\t\t-------------------------------------------------------\n\n\n";



}

 }
       fp1.close();
         getch();
     student_menu();
}



void teacher::sortmark()
{  system("cls");
     student t[100],temp;
    fp1.open("student.dat",ios::in);
     int y,n=0;
     char ch[25];
     if(!fp1)
     {
         cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
         cout<<"\n\n\n\n\n\n\n\n";
     }
     else
     {
         {
             while(fp1.read((char*)&st,sizeof(st)))
             {
                 t[n++]=st;
             }
         }
         fp1.close();

         cout<<"\n\n\n\n\n\n";
         cout<<"\t\t\t\t\t\t\t  ----------------------"<<"\n";
         cout<<"\n\t\t\t\t\t\t\t     SELECT A SUBJECT"<<"\n";
         cout<<"\n\t\t\t\t\t\t\t  ----------------------"<<"\n";
         cout<<"\n\n\t\t\t\t\t\t\t       1. PHYSICS"<<"\n";
         cout<<"\n\n\t\t\t\t\t\t\t       2. CHEMISTRY"<<"\n";
         cout<<"\n\n\t\t\t\t\t\t\t       3. MATHS"<<"\n";
         cout<<"\n\n\t\t\t\t\t\t\t       4. COMPUTER"<<"\n";
         cout<<"\n\n\t\t\t\t\t\t\t       5. ENGLISH"<<"\n\n";
         cout<<"\n\n\t\t\t\t\t\t\t       6. BIOLOGY"<<"\n\n";
         cout<<"\n\n\t\t\t\t\t\t\t     ENTER YOUR OPTION (1-6): ";
         cin>>y;
         system("cls");
         cout<<endl;
         if(y>6)
         {
             cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWRONG OPTION!";
             cout<<"\n\n\n\n\n\n\n\n";

         }

        
         
         
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n-1;j++)
             {     
                 if( (t[j].physics < t[j+1].physics  and y==1) or (t[j].chemistry < t[j+1].chemistry  and y==2) or 
                 (t[j].maths < t[j+1].maths  and y==3) or (t[j].chemistry < t[j+1].chemistry  and y==4)
                 or (t[j].english < t[j+1].english  and y==5) or (t[j].biology < t[j+1].biology  and y==6)  )

                 {
                     temp=t[j];
                     t[j]=t[j+1];
                     t[j+1]=temp;
                 }
             }
         }

         cout<<"\n\n\n\n\n\n";
         cout<<"\t\t\t\t\t\t\t"<<"---------------------------------------"<<"\n";
         cout<<"\n\t\t\t\t\t\t\t"<<"   SNO  "<<"\t"<<"MARKS"<<"\t "<<"NAME"<<"\t RollNo\n";
         cout<<"\n\t\t\t\t\t\t\t"<<"---------------------------------------"<<"\n\n";
         for(int i=0;i<5;++i)
         {
             cout<<"\t\t\t\t\t\t\t    ";
             cout<<i+1<<". "<<"\t\t";
             if(y==1)
             cout<<t[i].physics<<"\t"<<t[i].name<<"\t   "<<t[i].ret_rollno();
             else if(y==2)
             cout<<t[i].chemistry<<"\t"<<t[i].name<<"\t   "<<t[i].ret_rollno();
             else if(y==3)
             cout<<t[i].maths<<"\t"<<t[i].name<<"\t   "<<t[i].ret_rollno();
             else if(y==4 and t[i].stream=="C")
             cout<<t[i].chemistry<<"\t"<<t[i].name<<"\t   "<<t[i].ret_rollno();
             else  if(y==5)   
             cout<<t[i].english<<"\t"<<t[i].name<<"\t   "<<t[i].ret_rollno();
            else  if(y==6 and t[i].stream=="B")
             cout<<t[i].biology<<"\t"<<t[i].name<<"\t   "<<t[i].ret_rollno();


             cout<<"\n\n\n";
         }
         cout<<"\n\n\n";
     }
     getch();
     student_menu();
}

void teacher::get_teacher_data(){
r:

try{

         cout<<"\n\n\n\n\t\t\t\t  -------------------------------"<<"\n";
           cout<<"\n\t\t\t\t     ENTER THE TEACHER DETAILS"<<"\n";
           cout<<"\n\t\t\t\t  -------------------------------"<<"\n\n";
           cout<<"\n\n\t\t\t\tNAME OF THE TEACHER    : ";
           cin.ignore();
           getline(cin,name);
           cout<<"\n\n\t\t\t\tTEACHER ID   : ";
           cin>>ID;
           
           cout<<"\n\n\t\t\t\tDate of Birth            : ";
           cin>>dob;
           cin.ignore();
           cout<<"\n\n\t\t\t\tPHONE NO            : ";
           getline(cin,phone_no);
           cout<<"\n\n\t\t\t\tEMAIL ID            : ";
           getline(cin,email_id);
            cout<<"\n\n\t\t\t\tSUBJECT            : ";
           getline(cin,subject);
            cout<<"\n\n\t\t\t\tYEAR OF JOINING            : ";
           getline(cin,year_of_joining);
            cout<<"\n\n\t\t\t\tSALARY           : ";
           cin>>salary;
           
 if(name=="" or ID=="" or email_id=="" or subject=="") throw 1;
     
     if(dob.size()>12)
       throw 'a';
      
      if(phone_no.size()!=10 or salary < 0) throw 6.2;

      
    
}


catch(int i){
    cout<<"\n\n\n\t\t\tInfo Entered is Empty !! Enter again !!";
    Sleep(1000);
    goto r;
}

catch(char  c){
cout<<"\n\n\t\t\tAge is Invalid ! Enter again !!";
    Sleep(1000);

goto r;

}

catch(double i){
   cout<<"\n\n\n\t\t\t Phone No  is Invalid ! Enter again !!";
    Sleep(1000);
   
   goto r;

}


}

void teacher::show_teacher_data(){

cout<<"\n\n\t\t\t\tName : "<<name;
cout<<"\n\n\t\t\t\tDate of Birth : "<<dob;
cout<<"\n\n\t\t\t\tTeacher ID : "<<ID;
cout<<"\n\n\t\t\t\tPhone no : "<<phone_no;
cout<<"\n\n\t\t\t\tEmail id : "<<email_id;
cout<<"\n\n\t\t\t\tSubject : "<<subject;
cout<<"\n\n\t\t\t\tYear of joining : "<<year_of_joining;
cout<<"\n\n\t\t\t\tSalary :"<<salary;



}




void admin::add_teacher_record(){
 system("cls");
     fp2.open("teacher.dat",ios::out|ios::app);
     t.get_teacher_data();       
    fp2.write((char*)&t,sizeof(teacher));
    fp2.close();
    cout<<"\n\n\n\t\t\tTEACHER RECORD HAS BEEN CREATED........";
    getch();

 

}


void admin::show_all_teacher(){
system("cls");
    cout<<"\n\n\n\t\t\t\tDISPLAY ALL TEACHERS  RECORD !!!\n\n\n\n";
    fp2.open("teacher.dat",ios::in);
    while(fp2.read((char*)&t,sizeof(teacher)))
    {
        t.show_teacher_data();
        cout<<"\n\n\t\t\t\t===========================================\n\n";
    }
    fp2.close();
    getch();
 

        
} 


void admin::add_student_record(){
system("cls");
     fp1.open("student.dat",ios::out|ios::app);
     st.get_student_data();       
    fp1.write((char*)&st,sizeof(student));
    fp1.close();
    cout<<"\n\n\n\t\t\tSTUDENT RECORD HAS BEEN CREATED........";
    getch();





}


void admin::show_all_student(){

system("cls");
    cout<<"\n\n\n\t\t\t\tDISPLAY ALL STUDENTS  RECORD !!!\n\n\n\n";
    fp1.open("student.dat",ios::in);
    while(fp1.read((char*)&st,sizeof(student)))
    {
        st.show_student_data();
        cout<<"\n\n\t\t\t\t===========================================\n\n";
    }
    fp1.close();
    getch();
 




}
void teacher::Password(int p)
{
    system("cls");
     
     char pass[7];
     pass[6]='\0';
     int t=0;
     start:
     cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tENTER  THE   PASSWORD: ";
     for(int i=0;i<6;++i)
     {
             pass[i]=getch();
             cout<<"*";
     }
     cout<<"\n\n";
     
     if(strcmp(pass,"tttttt")==0 and p==1 )
     {
         cout<<"\t\t\t\t\t      ACCESS GRANTED";
         Sleep(3000);
         teacher_menu();
     }
else 
 if(strcmp(pass,"aaaaaa")==0 and p==2 )
     {
         cout<<"\t\t\t\t\t      ACCESS GRANTED";
         Sleep(3000);
         admin_menu();
     }
     else
     {
         if(t==2)
         {
             cout<<"\t\t\t\t\t      ACCESS DENIED"<<"\n\n\n\n\n\n\n\n";
             system("PAUSE");
             system("cls");
             Main_menu();
         }
         cout<<"\t\t\t\t\t      TRY AGAIN";
         ++t;
         Sleep(3000);
         system("cls");
         goto start;
     }
}

void admin::delete_teacher_record(){
    string no;
    system("cls");
    cout<<"\n\n\n\n\t\t\t\tDelete Teacher Record";
    cout<<"\n\n\t\t\t\t\tPlease Enter The ID  of teacher You Want To Delete :    ";
    cin>>no; teacher T;
    fp2.open("teacher.dat",ios::in|ios::out);
    fstream fp3;
    fp3.open("Temp.dat",ios::out);
    fp2.seekg(0,ios::beg);
    while(fp2.read((char*)&t,sizeof(teacher)))
    {
        if(t.ret_id()!=no)
        {
            fp3.write((char*)&t,sizeof(teacher));
        }
        else T=t;
    }
    fp3.close();
    fp2.close();
    remove("teacher.dat");
    rename("Temp.dat","teacher.dat");
    cout<<"\n\n\n\n\t\t\t\tRecord Deleted ............";
    T.show_teacher_data();
    getch();




}


void admin::modify_teacher_record(){
string no;
int found=0;
    system("cls");
    cout<<"\n\n\n\n\t\t\t\tTo Modify ";
    cout<<"\n\n\t\t\t\t\t\tPlease Enter The ID of teacher:   ";
    cin>>no;
    fp1.open("teacher.dat",ios::in|ios::out);
    while(fp1.read((char*)&t,sizeof(t)) && found==0)
    {
        if(t.ret_id()==no)
        {
            t.show_teacher_data();
            Sleep(1000);
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\tPlease Enter The New Details of Teacher!!!!!!!!!!!!!!"<<endl;
            t.get_teacher_data();
            int pos=-1*sizeof(t);
            fp1.seekp(pos,ios::cur);
            fp1.write((char*)&t,sizeof(teacher));
            cout<<"\n\n\n\n\n\t\t\t Record Updated.........";
            found=1;
        }
    }
    fp1.close();
    if(found==0)
        cout<<"\n\n\n\n\t\t\t\t Record Not Found... ";
    getch();
    admin_menu();

}


void class_result()
{
    student s[50],temp;
    int n=0;
    
    system("cls");
    fp1.open("student.dat",ios::in);
    if(!fp1)
    {
        cout<<"\n\n\n\n\n\t\t\t\tERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To MAIN Menu to create File";
        cout<<"\n\n\n\t\t\t\t Program is closing ....";
        getch();
        exit(0);         
    }

string stream;

 cout<<"\n\n\t\t\t\tEnter stream :  ";
cin>>stream;



 if(stream=="C"){
    cout<<"\n\n\n\n\n\t\t\t\t\t\t\tALL STUDENTS RESULT \n\n";
    cout<<"\n\t\t\t\t\t=======================================================\n";
    cout<<"\t\t\t\t\tSNo  Roll No  Name        P  C  M  E  CS  %age  Grade\n";
    cout<<"\t\t\t\t\t=======================================================\n";
  }
  else{
   cout<<"\n\n\n\n\n\t\t\t\t\t\t\tALL STUDENTS RESULT \n\n";
    cout<<"\n\t\t\t\t\t=======================================================\n";
    cout<<"\t\t\t\t\tSNo  Roll No  Name        P  C  M  E  B  %age  Grade\n";
    cout<<"\t\t\t\t\t=======================================================\n";

  }
int j=1;
    
     
         
             while(fp1.read((char*)&st,sizeof(st)))
             {    
                   if(stream=="C" and st.stream=="C")
                    s[n++]=st;
                  
                  if(stream=="B" and st.stream=="B")
                    s[n++]=st;

             }
         
         fp1.close();

         for(int i=0;i< n; i++)
         {
             for(int j=0;j<n-1;j++)
             {
                 if(s[j].rollno>s[j+1].rollno)
                 {
                     temp=s[j];
                     s[j]=s[j+1];
                     s[j+1]=temp;
                 }
             }
         }
            
      for(int i=0;i<n;i++)
         {  cout<<"\t\t\t\t\t "<<j++<<"      ";
             if(stream=="C" and s[i].stream=="C")
             s[i].show_tabular(1);
             if(stream=="B" and s[i].stream=="B")
             s[i].show_tabular(2);

             cout<<"\n";
         }
             cout<<"\n\n\n\t\t\t\t\t-------------------------------------------------------\n\n\n";
         
    
    getch();
}

 

 

void display_student_marks(){
int found=0,num;
 system("cls"); string stream;
 cout<<"\n\n\t\t\t\tEnter stream :  ";
cin>>stream; 
 cout<<"\n\n\t\t\t\tPlease Enter The roll number :  ";
  cin>>num;

fp1.open("student.dat",ios::in|ios::out);
    while(fp1.read((char*)&st,sizeof(student)) && found==0)
    {
        if(st.ret_rollno()==num and st.ret_stream()==stream)
        {
            st.show_student_marks();
            found=1;
        }
    }
    fp1.close();
    if(found==0)
        cout<<"\n\n\n\n\n\t\t\t\t  Record Not Found....... ";
    getch();


}





int main(){

system("cls");
system("COLOR F0");

// Welcome();

Main_menu();

return 0;   
}


void teacher_menu()
{
    system("cls");
    int ch;
    
    
   cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t ================================================\n";
        cout<<"\t\t\t\t\t #################::WELCOME TEACHERS!!!::##########\n";
        cout<<"\t\t\t\t\t ================================================\n\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t1. ENTER STUDENT MARKS \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t2. DISPLAY ALL STUDENTS MARKS \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t3.SEARCH STUDENT RECORD \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
         cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t4. MODIFY STUDENT MARKS \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
         cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t5. DELETE STUDENT RECORD \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t6.BACK TO MAIN MENU \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
         
 
 
         cout<<"\n\t\t\t\t\tEnter your choice:-> ";



    cin>>ch;
    switch(ch)
    {
    case 1:
        
        t.Enter_Marks();
        break;
    case 2:
        class_result();
        teacher_menu();
        break;
    case 3:
        
        display_student_marks();
        teacher_menu();
        break;
    case 4:
        t.modify_student_marks();
        break;
    case 5:
        a.delete_student();
        break;

    case 6:   Main_menu();
              break;
    default :
        cout<<"\a";
        Main_menu();
    }
}

void Intro()
{
     system("cls");
     for(int i=1;i<=10;++i)
     {
         Sleep(5);
         system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tLOADING "<<i*10<<"%";
         if(i==10)
         {
             Sleep(1000);
         }
     }
     system("cls");
     Sleep(3000);
     system("cls");
}

void Welcome()
{
    system("cls");

    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t ||                  WELCOME TO                ||\n";
    cout<<"\t\t\t\t\t ||                                            ||\n";
    cout<<"\t\t\t\t\t ||    STUDENT AND TEACHER MANAGEMENT SYSTEM    ||\n";
    cout<<"\t\t\t\t\t ||                                            ||\n";
    cout<<"\t\t\t\t\t ||                    PROJECT                 ||\n";
    cout<<"\t\t\t\t\t ================================================\n\n\n";

    cout<<"\t\t\t\t\t-------------------------------------------------\n";
    cout<<"\t\t\t\t\t\t\t Created By:-             \t\n";
    cout<<"\t\t\t\t\t\t\t                           \t\n";
    cout<<"\t\t\t\t\t\t\t  VARUN KUMAR             \t\n";
    cout<<"\t\t\t\t\t\t\t  YASHIT KUMAR        \t\n";
    cout<<"\t\t\t\t\t-------------------------------------------------\n\n";

    system("pause");
    Intro();
    Main_menu();
}






void student_menu(){

 system("cls");
    int ch;
   
    
       cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t ================================================\n";
        cout<<"\t\t\t\t\t #################::STUDENT ::##################\n";
        cout<<"\t\t\t\t\t ================================================\n\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t1. SEARCH FOR YOUR RECORD \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t2. CLASS RESULTS \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t3. VIEW ASCENDING ORDER OF PERCENTAGE \t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t4.VIEW TOP FIVE MARKS IN EACH SUBJECT  \t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t5.BACK TO MAIN MENU \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        

        cout<<"\n\t\t\t\t\tEnter your choice:-> ";



    cin>>ch;
    
    switch(ch)
    {
    case 1:
     display_student_marks();
     student_menu();
        break;
    case 2:
        class_result();
        student_menu();
        break;
    case 3:
        t.sortper();
        break;
    
    case 4 : t.sortmark();
             break;
     case 5: Main_menu();        
     default:
        Main_menu();
        break;
    }


}

void admin_menu(){

system("cls");
    int ch;
    
         cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t================================================\n";
        cout<<"\t\t\t\t\t#################::WELCOME ADMIN!!!::##############\n";
        cout<<"\t\t\t\t\t================================================\n\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t1. CLASS RESULTS \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t2. ADD TEACHER RECORD \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t3. ADD STUDENT RECORD \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
         cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t4. SHOW ALL TEACHERS RECORD \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
         cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t5. SHOW ALL STUDENTS RECORD \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t6.DELETE A  TEACHER RECORD \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
         cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t7.MODIFY TEACHER RECORD \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
         cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t8. BACK TO MAIN MENU \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
 
 
         cout<<"\n\t\t\t\t\tEnter your choice:-> ";

    cin>>ch;
    
    switch(ch)
    {
    case 1:
    class_result();
    admin_menu();
        break;
    case 2:
        a.add_teacher_record();
        admin_menu();
        break;
    case 3:
        a.add_student_record();
        admin_menu();
        break;
    
    case 4 : a.show_all_teacher();
             admin_menu(); 
             break;
     case 5: a.show_all_student();
              admin_menu();
               break;
    case  6: a.delete_teacher_record();
                 admin_menu();
                 break;
    case  7: a.modify_teacher_record();
                 admin_menu();
                 break;
                       
   
     case 8: Main_menu();
             break;                              
     default:
         Main_menu();
          break;
    }






}




void Main_menu()
{
     int n;
     start:
     system("cls");
     cout<<"\n\n\n\n\n";
     cout<<"\t\t\t\t\t\t      ---------------"<<"\n";
     cout<<"\t\t\t\t\t\t         MAIN MENU"<<"\n";
     cout<<"\t\t\t\t\t\t      ---------------"<<"\n\n\n";
     cout<<"\t\t\t\t\t\t     SELECT DESIGNATION"<<"\n\n";
     cout<<"\t\t\t\t\t-------------------------------------------"<<"\n";
     cout<<"\t\t\t\t\t  1. TEACHER\t2. STUDENT\t3. ADMIN"<<"\n";
     cout<<"\t\t\t\t\t-------------------------------------------"<<"\n\n";
     cout<<"\t\t\t\t\t             (PRESS 4 TO EXIT)"<<"\n\n\n";
     cout<<"\t\t\t\t\t       ENTER AN OPTION: ";
     cin>>n;
     system("cls");
     switch(n)
     {
              case 1:a.Password(1);
                      break;
              case 2: student_menu();
                      break;
              case 3: a.Password(2);
                      break;
              case 4: exit(0);
                      break;
              default:cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWRONG OPTION!";
                      cout<<"\n\n\n\n\n\n\n\n";
                      system("PAUSE");
     }
     goto start;
}




