#include<stdio.h>
#include<conio.h>
void main(){
	int k,temp1,c,x;
	char s;
	FILE *fpe;
	FILE *fpd;
	clrscr();
	printf("Enter Key");
	scanf("%d",&k);
	printf("Encrption: 1\nDecryption: 2\n");
	scanf("%d",&c);
	switch(c)
	{
	  case 1:{    fpe=fopen("M.txt","r");
		      fpd=fopen("C.txt","w");
		      do{
		      s=fgetc(fpe);
		      if(s>='a' && s<='z'){
		      temp1=s-97;
		      x=97;}
		      else if(s>='A' && s<='Z'){
			temp1=s-65;
			x=65;}
		      else if(s=='\n'){
			fputc(s,fpd);
			continue;
			}
		      else{
			 fputc(' ',fpd);
			 continue; }
		      temp1=temp1+k;
		      temp1=temp1%26;
		      s=temp1+x;
		      fputc(s,fpd);
		      }while(!feof(fpe));
		      printf("done");
		      fpe=fopen("M.txt","w");
		      break;
		 }
	  case 2:{ fpe=fopen("M.txt","w");
		    fpd=fopen("C.txt","r");
		   do{
		   s=fgetc(fpd);
		   if(s>='a' && s<='z'){
		     temp1=s-97;
		     x=97; }
		   else if(s>='A' && s<='Z'){
		     temp1=s-65;
		     x=65; }
		   else if(s=='\n'){
			fputc(s,fpe);
			continue;
			}
		   else{
		     fputc(' ',fpe);
		     continue;   }
		   temp1=temp1+26;
		   temp1=temp1-k;
		   temp1=temp1%26;
		   s=temp1+x;
		   fputc(s,fpe);
		   }while(!feof(fpd));
		   fpd=fopen("C.txt","w");
		   printf("done");
		   break;
		}
	  default:printf("Invalid Input");
	}
   fclose(fpe);
   fclose(fpd);
   getch();
}
