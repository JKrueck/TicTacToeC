#include<stdio.h>
char Reihe1[3]={'1','2','3'};
char Reihe2[3]={'4','5','6'};
char Reihe3[3]={'7','8','9'};
int Spielaktiv;
char Winner;
int spielfeldzeichnen(char WerDranIst, int Zug );
int Ergebnis();
void main()
{
  int Spielfeld;
  int Eingabe;
  Spielfeld=spielfeldzeichnen('X',11);
  char WerIstDran;
  WerIstDran='X';

  while (Spielaktiv==1)
  {
    if (WerIstDran == 'X')
    {
      printf("In welches Feld wollen Sie Ihr Kreuz platzieren?");
      scanf("%d",&Eingabe);
      if (Eingabe>=10 || Eingabe==0 )
      {
        printf("Unpassenden Eingabe! Geben Sie eine Zahl zwischen 1 und 9 an.\n");
      }
      else 
      {
        Spielfeld=spielfeldzeichnen('X',Eingabe);
        if (Spielfeld==0)
        {
          WerIstDran='X';
        }
        else
        {
          WerIstDran='O';
        }
        
      }
    }
    else
    {
      printf("In welches Feld wollen Sie Ihren Kreis platzieren?");
      scanf("%d",&Eingabe);
      if (Eingabe>=10 || Eingabe==0)
      {
        printf("Unpassenden Eingabe! Geben Sie eine Zahl zwischen 1 und 9 an.\n");
      }
      else 
      {
        Spielfeld=spielfeldzeichnen('O',Eingabe);
         if (Spielfeld==0)
        {
          WerIstDran='O';
        }
        else
        {
          WerIstDran='X';
        }
      }
    }
  }

  printf("Der Gewinner ist :%c",Winner);

}

int spielfeldzeichnen(char werdran, int welcherzug)
{
  if (welcherzug<=3)
  {
    if (Reihe1[welcherzug-1]!='X'&&Reihe1[welcherzug-1]!='O')
    {
      Reihe1[welcherzug-1]=werdran;
    }
    else
    {
      printf("Ihr gewähltes Feld ist bereits belegt!\n");
      return 0;
    }
  }
  else if (welcherzug<=6)
  {
    if (Reihe2[welcherzug-4]!='X'&&Reihe2[welcherzug-4]!='O')
    {
      Reihe2[welcherzug-4]=werdran;
    }
    else
    {
      printf("Ihr gewähltes Feld ist bereits belegt!\n");
      return 0;
    }
  }
    else
    {
      if (Reihe3[welcherzug-7]!='X'&&Reihe3[welcherzug-7]!='O')
      {
        Reihe3[welcherzug-7]=werdran;
      }
       else
    {
      printf("Ihr gewähltes Feld ist bereits belegt!\n");
      return 0;
    }
      
    }
  printf("%c|%c|%c \n",Reihe1[0],Reihe1[1],Reihe1[2]);
  printf("%c|%c|%c \n",Reihe2[0],Reihe2[1],Reihe2[2]);
  printf("%c|%c|%c \n",Reihe3[0],Reihe3[1],Reihe3[2]);
  Spielaktiv=Ergebnis();
  return 12;
}
int Ergebnis()
{
  if (Reihe1[0]==Reihe1[1] && Reihe1[1]==Reihe1[2])
  {
    Winner=Reihe1[0];
    return 0;
  }
  else if (Reihe2[0]==Reihe2[1] && Reihe2[1]==Reihe2[2])
    {
      Winner=Reihe2[0];
      return 0;
    }
    else if (Reihe3[0]==Reihe3[1] && Reihe3[1]==Reihe3[2])
      {
        Winner=Reihe3[0];
        return 0;
      }
  
  if (Reihe1[0]==Reihe2[0] && Reihe2[0]==Reihe3[0])
  {
    Winner=Reihe1[0];
    return 0;
  }
  else if(Reihe1[1]==Reihe2[1] && Reihe2[1]==Reihe3[1])
    {
      Winner=Reihe1[1];
      return 0;
    }
    else if (Reihe1[2]==Reihe2[2] && Reihe2[2]==Reihe3[2])
      {
        Winner=Reihe1[2];
        return 0;
      }

  if (Reihe1[0]==Reihe2[1] && Reihe2[1]==Reihe3[2])
  {
    Winner=Reihe1[0];
    return 0;
  }
  else if (Reihe1[2]==Reihe2[1] && Reihe2[1]==Reihe3[0])
    {
      Winner=Reihe1[2];
      return 0;
    }
    else 
    { 
      return 1;
    }
}