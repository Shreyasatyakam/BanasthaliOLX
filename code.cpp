#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
#include <windows.h>
#include <unistd.h>
using namespace std;

ifstream fin;
ofstream fout;
fstream fio;

void disp();

class olx
{
char name[20];
float price;
int quantity;
    public:
      void get();
      void show();
           int find(char nm[30]);    
           void withdraw(float qt);
}ob;
void olx::withdraw(float qt)
{
   system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
   cout<<"\n\t\t\t\t                      BV OLX";
   cout<<"\n\t\t\t\t   ----------------------------------------------";
cout<<"\n\n\n\n\n\t\t\t\t\tItem added to cart\n";
cout<<"\n\n\t\t\t\t\tTotal price to be paid : "<<(price*qt);
cout<<"\n\n\n\n\n\t\t\t\t   ----------------------------------------------";
   getch();
}
int olx::find(char nm[30])
{
if(strcmp(nm,name)==0)
  return 0;
else
  return 1;
}
void olx::get()
{
cout<<"\t\t\t\t   Name : ";
cin>>name;
cout<<"\t\t\t\t   Price : ";
cin>>price;
}
void olx::show()
{  
cout<<"\n\t\t\t\t   "<<name<<"\t\t\t  "<<price;;
}
void additem()
{
int i,n;
    system("cls");
    system("Color 80");
cout<<"\n\nRedirecting......................\n\nPress any key";
getch();
system("cls");
system("Color 70");
cout<<"\n\t\t\t\t   Enter the No. of Products that you wish to add: ";
    cin>>n;
    if (n!=0)
     {
 int j,l,sum=0;
 fout.open("shop.txt",ios::binary|ios::app);
 for(i=0;i<n;i++)
   {
 cout<<"\n\n\t\t\t\t   Input the name, price of item respectively\n\n";
     ob.get();
     fout.write((char*)&ob,sizeof(ob));
          cout<<"\n\n\t\t\t\t   New item added\n\n";
 cin.get();
        }
      fout.close();
      cin.get();
      system("cls");
      system("Color 70");
      disp();
     }
else
     {
 fout.close();
 cin.get();
 system("cls");
 system("Color 70");
 cout<<"\n\n\t\t\t\tNo items to be added\n\n";
 exit(0);
     }
     
}
void buy()
{
system("cls");
system("Color 70");
char temp[100];
float qty;
int i=0;
long pos=0;
disp();
cout<<"\n\n\t\t\t\t   Enter the product you wish to buy: ";
cin>>temp;
cout<<"\n\n\t\t\t\t   Enter quantity: ";
cin>>qty;
fio.open("shop.txt",ios::binary|ios::out|ios::in);
     while(fio)
     {
   pos=fio.tellp();
   fio.read((char*)&ob,sizeof(ob));
   if(ob.find(temp))
   {
 ob.withdraw(qty);
 fio.seekp(pos);
 fio.write((char*)&ob,sizeof(ob));
 i++;
 break;
   }
     }
     if(i!=1)
       cout<<"\n\n\t\t!!Record not found!!";
    fio.close();
    cin.get();
    system("cls");
    system("Color 70");
disp();
getch();
}
void disp()
{
int i=1;
cout<<"\t\t\t\t   ----------------------------------------------";
cout<<"\n\t\t\t\t                      BV OLX";
cout<<"\n\t\t\t\t   ----------------------------------------------";
cout<<"\n\n\t\t\t\t              ITEMS AVAILABLE TO BUY\n";
cout<<"\n\n\t\t\t\t\tNAME\t\t\tPRICE";
cout<<"\n\t\t\t\t   ----------------------------------------------";
fin.open("shop.txt",ios::binary);
    while(!fin.eof())
     {
 fin.read((char*)&ob,sizeof(ob));
 if(!fin.eof())
 {
    if(fin.tellg()<0)
    {
 i=0;
 break;
}
    ob.show();
 }
     }
     cout<<"\n\n\t\t\t\t   ----------------------------------------------";
     cout<<"\n\n\t\t\t\t   Back to Menu ? Press any key: ";
    if(i==0)
     {
   cout<<"\n\n\t\t\t!!!!";
   getch();
     }
    fin.close();  
}
void remove()
{
system("cls");
system("Color 70");
int i=0;
     char temp[30];
     cout<<"\t\t\t\t   ----------------------------------------------";
cout<<"\n\t\t\t\t                      BV OLX";
cout<<"\n\t\t\t\t   ----------------------------------------------";
     cout<<"\n\t\t\t\t\tDeleting Record";
     cout<<"\n\n\n\n\t\t\t\t   Enter the name of the product:";
     cin>>temp;
     fout.open("temp.txt",ios::binary);
     fin.open("shop.txt",ios::binary);
     while(!fin.eof())
     {
 fin.read((char*)&ob,sizeof(ob));
 if(!fin.eof())
   if(ob.find(temp)==0)
   {
 ob.show();
 cout<<"\n\n\n\n\t\tRecord deleted\n\n";
 i++;
   }
   else
 fout.write((char*)&ob,sizeof(ob));
     }
     if(i==0)
       cout<<"\n\n\n\n\t\t\t\t   !!Record not found!!";
     fin.close();
     fout.close();
     remove("shop.txt");
     rename("temp.txt","shop.txt");
}
int main()
{
char pass[10],pass2[10];
int i,j;
system("Color E0");
cout<<"\n\n\n\n\n\n\n\t\t\t\t\t|------------- WELCOME TO -------------|\n\n\n\n\n\n";
cout<<"\t\t\t\t000000 \t0           0\t\t0000000000  0         0      0\n";
cout<<"\t\t\t\t0     0\t 0         0 \t\t0        0  0          0    0 \n";
cout<<"\t\t\t\t0     0\t  0       0  \t\t0        0  0           0  0 \n";
cout<<"\t\t\t\t000000 \t   0     0   \t\t0        0  0            00  \n";
cout<<"\t\t\t\t0     0\t    0   0    \t\t0        0  0           0  0 \n";
cout<<"\t\t\t\t0     0\t     0 0     \t\t0        0  0          0    0 \n";
cout<<"\t\t\t\t000000 \t      0      \t\t0000000000  00000000  0      0\n\n\n\n\n";
getch();
system("cls");
system("Color 70");
cout<<"------------------------  **AN INITIATIVE FOR TRADING SECOND HAND ITEMS IN THE CAMPUS**  ------------------------";
cout<<"\n\n\n\n\n\n\t\t\t\t  -------------- YOU WANT TO --------------\n\n\n\n\t\t\t\t   SELL\t\t\t\tBUY\n\n";
cout<<"\t\t\t\t   press 0\t\t\tpress 1\n\n";
cout<<"\n\t\t\t\t  -----------------------------------------\n";
cout<<"\n\n\t\t\t\t     Enter your Choice :\t";
cin>>j;
if(j==0)
{
system("cls");
system("Color 70");
        system("cls");
        system("Color 70");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
   for(int z=0;z<6;z++)
    {
  pass[z]=getch();
  system("cls");
  system("Color 70");
  cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
  for(i=1;i<=(z+1);i++)
  {
cout<<"*";
  }
    }
 if(strcmp(pass,"seller")==0)
  {
        system("cls");
        system("Color 70");
   seller:
   system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
   cout<<"\n\t\t\t\t                      BV OLX";
   cout<<"\n\t\t\t\t   ----------------------------------------------";
   cout<<"\n\n\t\t\t\t\t           SELLER MENU\n\n\n\t\t\t\t   1. Display items listed \n\t\t\t\t   2. Add new product\n\t\t\t\t   3. Remove an item\n\t\t\t\t   4. Exit:";
   cout<<"\n\n\n\t\t\t\t   ----------------------------------------------";
   cout<<"\n\t\t\t\t   ----------------------------------------------";
   cout<<"\n\n\t\t\t\t     Enter your Choice :\t";
   cin>>i;
   if(i==1)
    {
    system("cls");
    system("Color 70");
   disp();
    getch();
       goto seller;
    }

   else if(i==2)
    {
   additem();
       getch();
   goto seller;
    }

   else if(i==3)
    {
   remove();
   getch();
   goto seller;
    }

   else
        {
   system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t                      BV OLX";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\n\n\n\n\n\n\n\n\n";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       sleep(1);
            system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t                      BV OLX";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\n\n\n\n\t\t\t\t\t\tTHANK \n\n\n\n\n";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       sleep(1);
       system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t                      BV OLX";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\n\n\n\n\t\t\t\t\t\tTHANK YOU\n\n\n\n\n";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       sleep(1);
       system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t                      BV OLX";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\n\n\n\n\t\t\t\t\t\tTHANK YOU FOR\n\n\n\n\n";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       sleep(1);
       system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t                      BV OLX";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\n\n\n\n\t\t\t\t\t\tTHANK YOU FOR COMING\n\n\n\n\n";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       sleep(1);
       getch();
       exit(0);
         }
         }
         else
         {
          cout<<"\n\n\n\t\t\t\tEntry for Authorised Persons Only\n\n";
       getch();
       exit(0);
}
    }
else if(j==1)
{
system("cls");
system("Color 70");
   cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
   for(int z=0;z<5;z++)
   {
   pass2[z]=getch();
   system("cls");
   cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
   for(i=1;i<=(z+1);i++)
    {
  cout<<"*";
     }
   }
 if(strcmp(pass2,"buyer")==0)
 {
buyer:
   system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
   cout<<"\n\t\t\t\t                      BV OLX";
   cout<<"\n\t\t\t\t   ----------------------------------------------";
   cout<<"\n\n\t\t\t\t\t           CUSTOMER MENU\n\t\t\t\t   1. Purchase\n\t\t\t\t   2. View available items\n\t\t\t\t   3. Exit:\n\n\n";
   cout<<"\n\t\t\t\t   ----------------------------------------------";
   cout<<"\n\t\t\t\t   ----------------------------------------------";
cout<<"\n\n\t\t\t\t     Enter your Choice :\t";
   cin>>i;
   if (i==1)
    {
      buy();
  getch();
  goto buyer;
    }
   else if(i==2)
    {
  system("cls");
  system("Color 70");
      disp();
  getch();
  goto buyer;
    }
   else
    {
   system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t                      BV OLX";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\n\n\n\n\n\n\n\n\n";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       sleep(1);
            system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t                      BV OLX";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\n\n\n\n\t\t\t\t\t\tTHANK \n\n\n\n\n";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       sleep(1);
       system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t                      BV OLX";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\n\n\n\n\t\t\t\t\t\tTHANK YOU\n\n\n\n\n";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       sleep(1);
       system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t                      BV OLX";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\n\n\n\n\t\t\t\t\t\tTHANK YOU FOR\n\n\n\n\n";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       sleep(1);
       system("cls");
   system("Color 70");
   cout<<"\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t                      BV OLX";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\n\n\n\n\t\t\t\t\t\tTHANK YOU FOR COMING\n\n\n\n\n";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       cout<<"\n\t\t\t\t   ----------------------------------------------";
       sleep(1);
       getch();
       exit(0);
         }
       }
       else
       {
        cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t\t     ***************\n";
        cout<<"\t\t\t\t\t\t    *               *\n";
        cout<<"\t\t\t\t\t\t   *                  *\n";
        cout<<"\t\t\t\t\t\t  *      |     |       *\n";
        cout<<"\t\t\t\t\t\t *                      *\n";
        cout<<"\t\t\t\t\t\t  *     _________      *\n";
        cout<<"\t\t\t\t\t\t   *                  *\n";
        cout<<"\t\t\t\t\t\t     *              *\n";
        cout<<"\t\t\t\t\t\t      **************\n";
        cout<<"\n\n\t\t\t\t\t\t  Sorry!! Access Denied..\n\n";
   getch();
   exit(0);
  }
   }
   else {
        system("cls");
        system("Color 70");
       cout<<"\n\n\t\t\t\t\tAccess denied !!!!!!!!";
   }
getch();
}
