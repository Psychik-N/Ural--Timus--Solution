import java.io.*;
import java.util.*;
import java.math.*;
public class love2830{
public static void main(String args[]){
BigInteger a[]=new BigInteger[5000],f[]=new BigInteger[5000],tt;
int i,j,k,n,t;
Scanner in=new Scanner(System.in);
PrintWriter out=new PrintWriter(System.out);
f[1]=new BigInteger("1");
f[2]=new BigInteger("1");
for(i=3;i<=4500;i++){
f[i]=f[i-1].add(f[i-2]);
}
i=in.nextInt();
a[i+2500]=new BigInteger
(in.nextInt()+"");
j=in.nextInt();
a[j+2500]=new BigInteger(in.nextInt()+"");
n=in.nextInt();
if(i>j){t=i;i=j;j=t;}
if(j-i>1){
a[i+2501]=(a[j+2500].add(f[j-i-1].negate().multiply(a[i+2500]))).divide(f[j-i]);
}
if(n<i)for(k=i+2499;k>=n+2500;k--)
a[k]=a[k+2].add(a[k+1].negate());
if(n>i)for(k=i+2502;k<=n+2500;k++)
a[k]=a[k-2].add(a[k-1]);
out.println(a[n+2500]);
out.flush();
}
}
