 #include<stdio.h>
  #include<stdlib.h>
  #include<graphics.h>
  #include<iostream.h>
  # include<conio.h>
  #include<iostream.h>
  #include<dos.h>
  #include<string.h>
  #include<fstream.h>
  # include"SATYAM15.H"
     int co;

    class shopping_mall
	  {    public:
		   char iname[20];
		   char brand[20];
		   float iprice;
		   int a;
		   void getdata();
		   void show();
	  }s5;

    int shopwork()
	{
		int frontview();
		system("cls");
		int a;
		char x;
		char ans;
		char iname[20];
		char brand[20];
		int noitems;
		fstream f,t;
	 z:
		co=frontview();
		int found=0;
	switch(co)               ///page4
	      { case 1: clrscr();
			shopping_mall temp;
			reenter:
			cout<<"\n\n\n ENTER DETAILS ABOUT";
			cout<<" ITEMS U WANT TO PURCHASE\n";
			temp.getdata();
		  f.open("shopping.txt",ios::in | ios::app| ios::binary);
			 while(f.read((char*)&s5,sizeof(s5)))
			      {
			       if(!strcmp(s5.iname,temp.iname))
				{
				 if(temp.a>s5.a)
				  {
				   cout<<"\n sorry we have only "<<s5.a<<"no of this item";
				   getch();
				   goto reenter;
				  }
				 else
				  {
				   s5.a=(s5.a)-(temp.a);
				   found=1;
				  }
				}
			       }
	      if(found==0)             //page5
	      {
	       cout<<"\n\n ITEM NOT FOUND ";
	       f.close();
	       f.open("shopping.txt",ios::in|ios::binary);
	       t.open("temp.txt",ios::out|ios::app|ios::binary);
	       while(f.read((char*)&s5,sizeof(s5)))
		{
		if(!strcmp(s5.iname,temp.iname))
		 continue;
		else
		 t.write((char*)&s5,sizeof(s5));
		}
	       f.close();
	       remove("shopping.txt");
	       rename("temp.txt","shopping.txt");
	       t.close();
	       ofstream n("shopping.txt",ios::out|ios::app|ios::binary);
	       n.write((char*)&s5,sizeof(s5));
	       n.close();
	       cout<<"THANK YOU";
	       }
	       else
	       cout<<"\n YOU HAVE SUCCESSFUL TO PURCHASING ITEMS";
	       cout<<"\n\n ****** DO YOU WANT TO CONTINUE (y/n)*****";
	       ans=getch();
	       if(ans=='y' || ans=='Y')
	       goto z;
	       else
	       break;
     /////////////////                  /////////////////////////////




   //////////////////////////////////////////

	  case 2:  clrscr();
		   cout<<"\n\n<<<<<**ENTER NEW RECORDS**>>>>>\n\n";
		   f.open("shopping.dat",ios::out|ios::app|ios::binary);
		   s5.getdata();
		   f.write((char*)&s5,sizeof(s5));
		   f.close();
		   cout<<"\n\n\n***********NEW RECORD ARE SAVED******";
		   cout<<"\n\n********DO YOU WANT TO CONTINUE*";
		   ans=getch();
		      if(ans=='Y'||ans=='y')
			goto z;
		      else
			break;

	    case 3: clrscr();
		    cout<<"\n\n";    clrscr();
		       f.open("shopping.dat",ios::in|ios::binary);
		       while(f.read((char*)&s5,sizeof(s5)))
		      { s5.show();}
		     getch();                                         //page7
		     f.close();
		     cout<<"\n\n\n***************DO YOY WANT TO CONTINUE(y/n)******";
		     ans=getch();
		     if(ans=='y'|| ans=='Y')
		     goto z;
		      else
		     break;



	     case 4:      clrscr();
		   f.open("shopping.txt",ios::in |ios::app |ios::binary);
		    cout<<"\n\n\n#########ENTER WHOSE RECORD TO BE SEEN *********";
		     cout<<"\n\n\n ITEM NAME ";
		    cin>>iname;
			 while(f.read((char*)&s5,sizeof(s5)))
				{
				  if(!strcmp(s5.iname,iname))
				     {
					s5.show();
					found=1;
				     }
				 }
			  if(found==0)
			     {
				  cout<<"\n\n\n ITEM NOT FOUND";
			     }
	     f.close();
	     cout<<"\n\n\n ********do you want to continue(y/n)**";
	     ans=getch();
	     if(ans=='y'|| ans=='Y')
	     goto z;
	     else
	     break;                      //page 8










	   case 5: clrscr();
	      ifstream to("shopping.txt",ios::in|ios::binary);

	      ofstream from("temp.txt",ios::app|ios::out|ios::binary);
		  cout<<"\n";
		  cout<<"@@@@@@@@@@@ENTER ITEM NAME WHOSE RECORD TO BE CHANGED @@@@@@@@@";
		  cout<<"\n\n\nITEM NAME \n\n";
		  gets(iname);
		      while(to.read((char*)&s5,sizeof(s5)))
			 { if(!strcmp(s5.iname,iname))
			   continue;
			   else
			   from.write((char*)&s5,sizeof(s5));
			 }                  ///page9
		 cout<<"\n\n\n ******** ENTER NEW RECORD*****"<<endl;
		 s5.getdata();
		 from.write((char*)&s5,sizeof(s5));
		 remove("shopping.dat");
		 rename("temp.dat","shopping.dat");
		 from.close();

		to.close();

	  cout<<"\n\n\n ********do you want to continue(y/n)**";
	  ans=getch();
	  if(ans=='y'|| ans=='Y')
	  goto z;
	  else
	  break;


       case 6: clrscr();
	      char iname[20];
	      f.open("shopping.dat",ios::in|ios::app|ios::binary);
	      t.open("temp.txt",ios::out|ios::app|ios::binary);
	      cout<<"\n\n\n\n%%%%%%%% DELETING%%%%%%%%%%%%%";
	      cout<<"\n\n\n\n ENTER THE SHOPPING NAME UWANT TO DELETE \t";
	      cin>>iname;
	      while(f.read((char*)&s5,sizeof(s5)))
		  {
		    if(!strcmp(s5.iname,iname))
		     continue;
		    else
		    t.write((char*)&s5,sizeof(s5));
		  }
	      f.close();
	      remove("shopping.dat");
	      rename("temp.dat","shopping.dat");
	      t.close();
		      cout<<"\n\n\n ********do you want to continue(y/n)**";
		      ans=getch();
		      if(ans=='y'|| ans=='Y')
		      goto z;
		      else
		      break;


	case 7: exit(0);
	case 8: return 12;
	default: goto z;
    }return 0;

      }


int frontview()
    {
       int  gdriver =DETECT,gmode,errorcode,a;
       initgraph(&gdriver,&gmode,"\\tc\\bgi");
       setbkcolor(YELLOW);
       setcolor(YELLOW) ;

       rectangle(600,370,100,100);
       floodfill(0,0,YELLOW);
       setcolor(GREEN);
       setfillstyle(11,WHITE);
       rectangle(600,370,100,100);
       floodfill(210,160,GREEN);



       setcolor(BLUE);


       settextstyle(1,0,2);
       outtextxy(100,130,"\n<<<<*****WHAT DO U WANT TO DO>>>>>>>>>>>\n" );
       settextstyle(1,0,1);
       {
	 outtextxy(130,165,"\n 1 .TO BUY");
	 outtextxy(130,180,"\n 2  .NEW RECORD" );
	 outtextxy(130,195,"\n 3  .TO SHOW ALL ITEMS");
	 outtextxy(130,210,"\n 4  .TO CHECK AVIALIBILITY");
	 outtextxy(130,225,"\n 5  .TO MODIFY");
	 outtextxy(130,240,"\n 6  .TO DELETE");
	 outtextxy(130,255,"\n 7  .TO EXIT");
	 outtextxy(130,270,"\n 8  .MAIN MENU");
	 outtextxy(130,285,"\n ************* ENTER YOUR CHOICE ***********\n");
       }

      gotoxy(30,40);
      cin>>a;
      return a;
}





	   //////////////////////  ///////////////////////////
      void shopping_mall::getdata()
		  { clrscr();

			cout<<" \n \n \t ENTER NAME OF ITEMS  ";
			gets(iname);

			cout<<" \n \n \t ENTER  THE BRAND OF THE ITEMS ";
			gets(brand);
			cout<<" \n \n \t ENTER  NO. OF ITEMS ";
			 cin>>a;
		   }

void shopping_mall::show()
{
	      cout<<" \n \n \t ITEMS NAME   "<<iname;
	      cout<<" \n \n \t BRAND  "<<brand;
	      cout<<" \n \n \t NO OF ITEMS  "<<a;
}

		////////////////////////////////////////////////////////////////////


	  void frontdisplay()
	  {  clrscr();
		int gdriver =DETECT,gmode,errorcode;
	initgraph(&gdriver,&gmode,"\\tc\\bgi");
	     for (int y=0;y<=360;y+=10)
		 {
		  delay(90);
		  setbkcolor(BLUE);
		  ellipse(350,250,0,y,250,150);
		    }

	     for(int i=0,j=0;i<10;i++,j++)
		{
		   setcolor(BLUE);
		   settextstyle(7,0,6);
		   outtextxy(235,150,"*SHOPING MALL*");
		   if(j<8)
		     {   setbkcolor(j);
		     }
		   else if(j==8)
			j=0;
		   settextstyle(7,0,4);
		   setcolor(WHITE);
		   outtextxy(150,220,"PREPARED BY");
		   settextstyle(10,0,2);
		   outtextxy(150,250,"SATYAM & SIDDHARTH");
		   delay(200);
		   } closegraph();

	  }
      void outlook()
       {
       background();
      textcolor(CYAN);
      gotoxy(4,5);
      cprintf(" ACCOUNT");
       gotoxy(10,10);
      cprintf("1  SIGN IN");
       gotoxy(10,12);
      cprintf("2 SIGN UP");
       gotoxy(10,14);
      cprintf("3  EXIT");
       gotoxy(10,16);
      cprintf("ENTER YOUR CHOICE");
      textcolor(YELLOW);
      gotoxy(15,17);
      cin>>co;
      }




void main()                                              ////page2
{ void frontdispay();
void outlook();
void loading();
clrscr(); int plus=0;
frontdisplay();
again:
system("cls");

outlook();
clrscr();
switch(co)
{
case 1:    plus=loginid();
	    system("cls");
	      plus=shopwork();
	      if(plus==12)
	      goto again;
	      goto again;

   case 2:    createid();
	      loading();
	      gotoxy(20,13);
	      cprintf("ID CREATED ");
	      getch();
	      goto again ;

   default: exit(0);
   }





 getch();
}


void loading()
{
clrscr();

int x,y;
randomize();
 int gdriver = DETECT, gmode, errorcode;
 initgraph(&gdriver, &gmode, "");
  int  c=20;
  outtextxy(300,50,"Loading");
for(int i=10,k=0;i<700&&k<=100;k++,i+=6)
 { int d=random(c);
 gotoxy(50,4);
 cout<<k<<"%";
 for(int j=10;j<40;j++)
 {
 putpixel(i,j,d);

 delay(2);   }      }

 system("cls");

 }
