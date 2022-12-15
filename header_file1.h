char pass[70];int count=0;
void background();
int loginid();
void enterid();
void createid();


void background()
    {  system("cls");
       for(int i=0;i<24;i++)
       {
	gotoxy(2,i);cprintf("#");
	gotoxy(50,i);cprintf("#");
       }
       for(int j=0;j<50;j++)
       {
	gotoxy(j,1);cprintf("#");
	gotoxy(j,24);cprintf("#");
       }
    }


 struct custerid
 {
     char ID[50];
     char password[50];
 }s;


 int  loginid()
  {
   system("cls");
   char ch[50];
   char pass[50];
   background();
   gotoxy(12,10);
   cout<<" ENTER ID";
   gotoxy(12,12);
   cin>>ch;
   gotoxy(12,14);
   cout<<"ENTER PASSWORD";
   for(int i=0;i<50;i++)
   {
    pass[i]=getch();
    cout<<"*";
    if(int(pass[i])==13)
    break;
   }
   ifstream fin("account.txt",ios::in);
   while(!fin.eof())
  { count=0;
   fin.read((char*)&s,sizeof(s));
    if(strcmp(s.ID,ch)==0)
     count=12;
     if(strcmp(s.password,pass)==0)
     {count++;
      break;}
     }
     fin.close();

  return count ;
 }

 void createid()
  {
   background();
   ofstream fout;
   fout.open("account.txt",ios::app);
   enterid();
   fout.write((char*)&s,sizeof(s));
   fout.close();
   clrscr();
  }



void enterid()
{    background();
     gotoxy(1,10);
     cprintf("ENTER ID");
     cin>>s.ID;
     cout<<"ENTER PASSWORD";
     gotoxy(15,12);
     for(int i=0;i<=100;i++)
	{
	 s.password[i]=getch();
	 cout<<"*";
	 if(int(s.password[i])==13)
	 break;
	}


}
