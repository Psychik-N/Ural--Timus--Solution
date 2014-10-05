import java.io.*;
import java.util.*;
import java.math.*;
public class Lucky{
public static void main(String[] args){
Scanner in = new Scanner(System.in);
PrintWriter out = new PrintWriter(System.out);
BigInteger f[][]=new BigInteger[51][501];
int n = in.nextInt();
int s = in.nextInt();
if(s%2==1)out.println(0);
else if(s==0)out.println(1);
else{
s/=2;
for(int i=0;i<10;i++)f[1][i]=new BigInteger("1");
for(int i=10;i<501;i++)f[1][i]=new BigInteger("0");
for(int i=2;i<51;i++)
for(int j=0;j<501;j++)
f[i][j]=new BigInteger("0");
for(int i=2;i<=n;i++)
for(int j=0;j<501;j++)
for(int k=0;k<10;k++)
if(j-k>=0)
f[i][j]=f[i][j].add(f[i-1][j-k]);
out.println(f[n][s].multiply(f[n][s]));
}
out.flush();
}
}
