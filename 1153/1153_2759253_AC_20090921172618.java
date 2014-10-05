import java.io.*;
import java.util.*;
import java.math.*;
public class Sqr{
public static void main(String[] args){
Scanner in = new Scanner(System.in);
PrintWriter out = new PrintWriter(System.out);
BigInteger need,p1=new BigInteger("1"),p2,mid,two=new BigInteger("2"),n1=new BigInteger("-1");
char tc[]=new char[400];
tc[0]='1';
for(int i=1;i<400;i++)tc[i]='0';
p2=new BigInteger(new String(tc));
need=new BigInteger(in.next()).multiply(two);
while(p1.compareTo(p2)!=0){
mid=p1.add(p2).divide(two).add(BigInteger.ONE);
if(mid.multiply(mid).compareTo(need)<0)p1=mid;
else p2=mid.add(n1);
}
out.println(p1);
out.flush();
}
}
