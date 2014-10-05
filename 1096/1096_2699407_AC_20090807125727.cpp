#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int maxn=65535;
int path[3001];
int a[3001],b[3001];
int dist[3001];
int r,s,k;
int output(int x){ 
    printf("%d\n",dist[x]); 
    while(x!=r) {  
                printf("%d\n",path[x]);  
                x=b[path[x]]; 
                }
                }
                int main(){ 
                    int n;  
                    bool bs; 
                    scanf("%d",&n); 
                    for(int i=1;i<=n;i++) {  
                            scanf("%d%d",&a[i],&b[i]);  
                            dist[a[i]]=maxn;
                            dist[b[i]]=maxn; 
                            }  
                            scanf("%d%d%d",&r,&s,&k); 
                            dist[r]=0; 
                            while(1) {  
                                     bs=true;  
                                     for(int i=1;i<=n;i++)  {   
                                             if(dist[a[i]]==maxn && dist[b[i]]<maxn)   {    
                                                                 bs=false;    
                                                                 dist[a[i]]=dist[b[i]]+1;   
                                                                  path[a[i]]=i;    
                                                                  if(a[i]==s||a[i]==k){
                                                                                       output(a[i]);
                                                                                       return 0;
                                                                                       }   
                                                                                       }  
                                                                                       }  
                                                                                       if(bs) break; 
                                                                                       } if(bs)  printf("IMPOSSIBLE\n"); 
                                                                                       return 0; 
                                                                                       }

