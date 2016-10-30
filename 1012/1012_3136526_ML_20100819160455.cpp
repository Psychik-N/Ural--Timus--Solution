#include <iostream>
#include <deque>
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
using namespace std;
const int SZ = 5000;

class verylong
{
private:
char vlstr[5000]; 
int vlen; 
verylong multdigit(const int) const; 
verylong mult10(const verylong) const; 
public:
verylong() : vlen(0) 
{ vlstr[0]='\0'; }
verylong(const char s[SZ]) 
{ strcpy(vlstr, s); vlen=strlen(s); } 
verylong(const unsigned long n) 
{ 
sprintf(vlstr, "%lu", n); 
_strrev(vlstr); 
vlen=strlen(vlstr); 
}
void putvl() const; 
void getvl(); 
verylong operator + (const verylong&); 
verylong operator * (const verylong&);
verylong operator - (const verylong&);
};
//--------------------------------------------------------------

void verylong::putvl() const 
{
char temp[SZ],*temp2;
int p=0;
strcpy(temp,vlstr); 
temp2=_strrev(temp);
while(temp2[p]=='0')p++;
if(temp2[p]==0)cout<<"0";
else cout << temp2+p; 
} 
//--------------------------------------------------------------
void verylong::getvl() 
{
cin >> vlstr; 
vlen = strlen(vlstr); 
_strrev(vlstr);
}
//--------------------------------------------------------------
verylong verylong::operator + (const verylong &v) 
{
char temp[SZ];
int j;

int maxlen = (vlen > v.vlen) ? vlen : v.vlen;
int carry = 0; 
for(j = 0; j<maxlen; j++) 
{
int d1 = (j > vlen-1) ? 0 : vlstr[j]-'0'; 
int d2 = (j > v.vlen-1) ? 0 : v.vlstr[j]-'0'; 
int digitsum = d1 + d2 + carry; 
if( digitsum >= 10 ) 
{ digitsum -= 10; carry=1; } 
else 
carry = 0; 
temp[j] = digitsum+'0'; 
}
if(carry==1) 
temp[j++] = '1'; 
temp[j] = '\0'; 
return verylong(temp); 
}
//--------------------------------------------------------------
verylong verylong::operator - (const verylong &v)
{
char temp[SZ];
int j, p=0, r=0;

int maxlen = (vlen > v.vlen) ? vlen : v.vlen;
p = maxlen - 1;
int carry = 0;

for(j=0; j<maxlen; j++)
{
int d1 = (j > vlen-1) ? 0 : vlstr[j] - '0';
int d2 = (j > v.vlen - 1) ? 0 : v.vlstr[j] - '0';
int digitdif = d1 - d2 - carry;
if(digitdif < 0)
{ digitdif += 10; carry = 1; }
else carry = 0;
temp[j] = digitdif + '0';
}
temp[j] = '\0';

return verylong(temp);
}
//--------------------------------------------------------------
verylong verylong::operator * (const verylong &v) 
{ 
verylong pprod; 
verylong tempsum; 
for(int j=0; j<v.vlen; j++) 
{
int digit = v.vlstr[j]-'0'; 
pprod = multdigit(digit); 
for(int k=0; k<j; k++) 
pprod = mult10(pprod); 
tempsum = tempsum + pprod; 
}
return tempsum; 
}
//--------------------------------------------------------------
verylong verylong::mult10(const verylong v) const 
{ 
char temp[SZ];
for(int j=v.vlen-1; j>=0; j--) 
temp[j+1] = v.vlstr[j]; 
temp[0] = '0'; 
temp[v.vlen+1] = '\0'; 
return verylong(temp); 
}
//--------------------------------------------------------------
verylong verylong::multdigit(const int d2) const
{ 
char temp[SZ]; 
int j, carry = 0;
for(j = 0; j<vlen; j++) 
{ 
int d1 = vlstr[j]-'0'; 
int digitprod = d1 * d2; 
digitprod += carry; 
if( digitprod >= 10 ) 
{
carry = digitprod/10; 
digitprod -= carry*10; 
}
else
carry = 0; 
temp[j] = digitprod+'0'; 
}
if(carry != 0) 
temp[j++] = carry+'0'; 
temp[j] = '\0'; 
return verylong(temp); 
}


verylong a[1810], s[1810];
int main()
{
unsigned long n, i, k;
scanf("%d", &n);
scanf("%d", &k);

a[0] = (n-n);
s[0] = (k-1);


for(i=1; i<n; i++)
{
	s[i]=(unsigned long)0;
	for(unsigned int j=1;j<=k;j++)s[i]=s[i]+s[i-1];
s[i] = s[i] - a[i-1];
a[i] = s[i-1] - a[i-1];
}

s[n-1].putvl();
return 0;
}
 

