#include<iostream>
#include<string.h> 
using namespace std;     
string str[300];   
int n;   
void readIn()   
{   
   int i=1;   
   while( getline(cin, str[i]) ) i++;   
   n=i - 1;   
}   
void work()   
{   
   int i, j;    
   int posx,posy;   
   bool inQ=false;   
   for( i=1; i <= n; i++ )   
   {   
      if(str[i].length()==0 || str[i]=="\\endinput"){   
         if(posx != -1&& posy != -1 )str[posx].erase(posy,1);   
         posx =posy=-1; inQ=false;   
      }   
      else for( j=0; j < str[i].length(); j++ )   
      {   
         if(str[i][j]=='\\' )   
         {   
            if( str[i].substr(j+1,3)=="par" ){   
               if(posx != -1&& posy != -1 && inQ){str[posx].erase(posy,1); j -= (posx==i? 1:0);}   
               posx=posy=-1; inQ=false;   
            }   
            else j++;   
         }   
         else if(str[i][j]=='\"' )   
         {   
            if(!inQ){posx=i,posy=j; inQ=true;}   
            else{   
               str[posx].replace(posy,1,"``");   
               j+=(posx==i? 1:0);   
               str[i].replace(j,1, "''");   
               j++;   
               posx=posy=-1; inQ=false;   
            }   
         }   
      }   
   }   
}   
void output()   
{   
   for(int i=1; i <= n; i++ )   
      cout << str[i] << endl;   
}   
int main()   
{      
   readIn();   
   work();   
   output();   
   return 0;   
} 