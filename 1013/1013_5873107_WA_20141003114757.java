import java.io.*;
import java.util.*;
import java.math.*;
public class Lucky{
public static void main(String[] args){
Scanner in = new Scanner(System.in);
PrintWriter out = new PrintWriter(System.out);
BigInteger t,l1=new BigInteger("0"),l2=new BigInteger("1"),n,k,i;
n=new BigInteger(in.nextInt()+"");
k=new BigInteger((in.nextInt()-1)+"");
for(i=new BigInteger("1");i.compareTo(n)<=0;i=i.add(BigInteger.ONE)){
t=l1.add(l2).multiply(k);
l1=l2;
l2=t;
}
out.println(l2);
out.flush();
}
}