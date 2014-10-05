import java.io.*;
import java.util.*;
import java.math.*;
public class Heritage{
public static void main(String[] args){
Scanner in = new Scanner(System.in);
PrintWriter out = new PrintWriter(System.out);
int i,n;
BigInteger a[]=new BigInteger[20];
n=in.nextInt();
a[1]=new BigInteger("2");
for(i=2;i<=n;i++)
a[i]=a[i-1].multiply(a[i-1]).add(a[i-1].negate()).add(BigInteger.ONE);
for(i=1;i<=n;i++)
out.println(a[i]);
out.flush();
}
}
