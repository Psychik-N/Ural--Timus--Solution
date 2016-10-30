#include<iostream>

#include<string.h>

#include<fstream>

using namespace std;

struct ntype

{

    char name;

    ntype* next;

};

//ifstream fin("1.txt");

//ofstream fout("2.txt");

char b[60001]={0};

ntype* head;

int p=0;

int main()

{

int i;

memset(b,0,sizeof(char)*30001);

    cin.get(b,1000000,EOF);

    int lenb=strlen(b);

    ntype* now;

    now=new ntype();

    now->name=b[0];

    now->next=NULL;

    ntype* head=now;

    int rest=1;

    for(i=1;i<lenb;i++)

    {

        if(b[i]!='\n'&&b[i]!='\r')

        {

            ntype* temp;

            temp=new ntype();

            temp->name=b[i];

            now->next=temp;

            now=temp;

            rest++;

        }

    }

    now->next=head;

    now=head;

while(rest>1)

{

    for(i=1;i<=1997;i++)

    now=now->next;

ntype* t1=now->next;

ntype* t2=t1->next;

now->next=t2;

head=now->next;

delete t1;

rest--;

now=now->next;

}

    if(head->name==' ')

        cout<<"No"<<endl;

    else if(head->name=='?')

        cout<<"Yes"<<endl;

else

        cout<<"No comments"<<endl;

    system("pause");

}
