/*-------------------------------------------------Overall -----
      |  * @author Raghav Gupta  raghav.gupta@st.niituniversity.in
      |   Version 1.0
      |  Purpose:  This program lets you store important personal information
      |   that one may store safely.
      |  Limitations: This Program lacks encryption posibilites for safe file
      |  Storing.Should be Developed in later phases of development.
      *-------------------------------------------------------------------*/

#include<stdio.h>
int i,j,ec,fg,ec2,x,l;       //Variables used
char fn[20],e,c,k;           //Variables used
FILE *fp1,*fp2,*fp;          //Variables used
void Create();               //Functions made for file creation
void Append();               //Functions made for file append
void Delete();              //Functions made for file delete
void Display();            //Functions made for file Display
void admin();               //Functions made for admin access
void user();                //Functions made for user access
int main()
{

  printf("\n\t\t******** YOUR PRIVATE VAULT ********");  //Interface

  printf("\n\t\t\t***** WELCOME *****");                 //Interface

  printf("\n\t\tVERSION-1.0");                          //Interface

  printf("\n\t\t*");                                  //Interface


  printf("\n\t\t*");                                  //Interface

  printf("\n\t\t*");                                  //Interface

  printf("\n\t\tLOADING...." );                        //Interface

  printf("\n\t\t*");                                  //Interface

  printf("\n\t\t*");                                  //Interface

  printf("\n\t\t*");                                   //Interface

  printf("\n\n\t\tINTERFACE:\n\t\t-----\n ");           //Interface

  printf("\n\t\t1.LOGIN AS ADMIN\n\t\t2.USE AS GUEST\n\t\t3.SEE VERSION\n\t\t4.EXIT\n");

  printf("\n\t\tEnter your choice:");                    //User Enters Choice

  scanf("%d",&x);

  if(x==1){                                               //admin access

    printf("\n\t\tENTER USER NAME :");

    scanf("%s",&k);

    printf("\n\t\tENTER PASSWORD :" );

    scanf("%d",&l);

    if(l==1234){                                        //admin access by function call

      admin();                                         //Password hardcoded as 1234


    }
    else{

      printf("\n\t\tLOGIN UNSUCCESSFUL.");            //Interface

      printf("\n\t\t*");                               //Interface

      printf("\n\t\t*");

      printf("\n\t\t*");

      printf("\n\t\t*");

      printf("\n\t\tUSE AS GUEST");                  //Interface




    }

  }


  else if(x==2){

    printf("\n\t\t***YOU ARE LOGGED IN AS GUEST***" ); //Interface

    printf("\n\t\t****YOUR OPTIONS ARE LIMITED***" );   //Interface

    user();

  }
  else if(x==3){

    printf("\n\t\t***VERSION : 1.0 \n");

    printf("\n\t\t***AUTHOR : RAGHAV GUPTA **** \n");  //Interface

    printf("\n\t\t***DEVELOPED FOR : NIIT UNIVERSITY*** \n");

    printf("\n\t\t***DEVELOPED IN : OCTOBER 2018 \n");

    printf("\n\t\t***STATUS : UNDERDEVELOPMENT");  //Interface


  }
  else if(x==4){

    printf("\n\t\t***THANKYOU***" );      //Interface


  }


}
void   admin()                        //Admin Function defined
{

 do {

 	printf("\n\t\t***** TEXT EDITOR *****");        //Interface

  	printf("\n\n\tMENU:\n\t-----\n ");             //Interface

  	printf("\n\t1.CREATE\n\t2.DISPLAY\n\t3.APPEND\n\t4.DELETE\n\t5.EXIT\n");

  	printf("\n\tEnter your choice: ");       //Interface

  	scanf("%d",&ec);

  switch(ec)                         //switch case

  {
   case 1:
     Create();                             //create function call
     break;
   case 2:

     Display();                           //display function call
     break;
   case 3:
  	printf("\n\tUnder Development ");         //append function call

     break;
   case 4:
     Delete();                            //delete function call
     break;
   case 5:
     printf("THANK YOU" );




  }
}while(1);                                 //create Function defined
}
void Create()
{

 fp1=fopen("temp.txt","w");
 printf("\n\tEnter the text and press '.' to save\n\n\t");
 while(1)
 {
  c=getchar();
  fputc(c,fp1);
  if(c == '.')
  {
   fclose(fp1);
   printf("\n\tEnter then new filename: ");
   scanf("%s",fn);
   fp1=fopen("temp.txt","r");
   fp2=fopen(fn,"w");
   while(!feof(fp1))
   {
    c=getc(fp1);
    putc(c,fp2);
   }
   fclose(fp2);
   break;
  }}
}
void Display()                //delete Function defined
{
  printf("\n\tEnter the file name: ");
  scanf("%s",fn);
  fp1=fopen(fn,"r");
  if(fp1==NULL)
  {
   printf("\n\tFile not found!");
   goto end1;
  }
  while(!feof(fp1))
  {
   c=getc(fp1);
   printf("%c",c);
  }
end1:
  fclose(fp1);
  printf("\n\n\tPress any key to continue...");
}
void Delete()             //delete Function defined
{
  printf("\n\tEnter the file name: ");
  scanf("%s",fn);
  fp1=fopen(fn,"r");
  if(fp1==NULL)
  {
   printf("\n\tFile not found!");
   goto end2;
  }
  fclose(fp1);
  if(remove(fn)==0)
  {
   printf("\n\n\tFile has been deleted successfully!");
   goto end2;
  }
  else
   printf("\n\tError!\n");
end2: printf("\n\n\tPress any key to continue...");
}
void Append()
{
  printf("\n\tEnter the file name: ");
  scanf("%s",fn);
  fp1=fopen(fn,"r");
  if(fp1==NULL)
  {
   printf("\n\tFile not found!");
   goto end3;
  }
  while(!feof(fp1))
  {
   c=getc(fp1);
   printf("%c",c);
  }
  fclose(fp1);
  printf("\n\tType the text and press 'Ctrl+S' to append.\n");
  fp1=fopen(fn,"a");
  while(1)
  {

   if(c==19)
    goto end3;
   if(c==13)
   {
    c='\n';
    printf("\n\t");
    fputc(c,fp1);
   }
   else
   {
    printf("%c",c);
    fputc(c,fp1);
   }
  }
end3: fclose(fp1);

}


void  user()       //USER Function defined
{

 do {

 	printf("\n\t\t***** TEXT EDITOR *****");       // Interface

  	printf("\n\n\tMENU:\n\t-----\n ");            // Interface

  	printf("\n\t1.CREATE\n\t2.DISPLAY\n\t3.APPEND\n\t4.DELETE\n\t5.EXIT\n");

  	printf("\n\tEnter your choice: ");            // Interface

  	scanf("%d",&ec);                              // Interface

  switch(ec)

  {
   case 1:
     Create();
     break;
   case 2:

     Display();
     break;
   case 3:
   printf("ACCESS DENIED");
     break;
   case 4:
   printf("ACCESS DENIED");
     break;
   case 5:
   printf("THANK YOU" );


  }
 }while(1);

void Create()
{

 fp1=fopen("temp.txt","w");
 printf("\n\tEnter the text and press '.' to save\n\n\t");
 while(1)
 {
  c=getchar();
  fputc(c,fp1);
  if(c == '.')
  {
   fclose(fp1);
   printf("\n\tEnter then new filename: ");
   scanf("%s",fn);
   fp1=fopen("temp.txt","r");
   fp2=fopen(fn,"w");
   while(!feof(fp1))
   {
    c=getc(fp1);
    putc(c,fp2);
   }
   fclose(fp2);
   break;
  }}
}
void Display()
{
  printf("\n\tEnter the file name: ");
  scanf("%s",fn);
  fp1=fopen(fn,"r");
  if(fp1==NULL)
  {
   printf("\n\tFile not found!");
   goto end1;
  }
  while(!feof(fp1))
  {
   c=getc(fp1);
   printf("%c",c);
  }
end1:
  fclose(fp1);
  printf("\n\n\tPress any key to continue...");
}

}
