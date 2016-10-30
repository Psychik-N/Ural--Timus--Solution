import java.io.*;
import java.util.*;
import java.math.*;
public class P1206{
public static void main(String[] arg){
Scanner in=new Scanner(System.in);
PrintWriter out=new PrintWriter(System.out);
int k,i;
BigInteger j=new BigInteger("1"),s=new BigInteger("55");
k=in.nextInt();
for(i=1;i<k;i++)k=k.multiply(s);
out.println(j.multiply(new BigInteger("36")));
out.flush();
}
}
