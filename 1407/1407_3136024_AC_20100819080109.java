import java.io.*;
import java.math.*;
import java.util.*;
public class a{
static void go(String s,int l,BigInteger m){
if(l==110){
Scanner in = new Scanner(System.in);
PrintWriter out = new PrintWriter(System.out);
out.println(s);
out.flush();
System.exit(0);
}
m=m.multiply(new BigInteger("2"));
if((new BigInteger("1"+s)).mod(m).equals(BigInteger.ZERO))go("1"+s,l+1,m);
if((new BigInteger("2"+s)).mod(m).equals(BigInteger.ZERO))go("2"+s,l+1,m);
}
public static void main(String args[]){
go("",0,new BigInteger("1"));
}
}
