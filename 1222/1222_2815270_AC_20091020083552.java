import java.io.*;
import java.util.*;
import java.math.*;
public class Greedy{
public static void main(String[] args){
Scanner in = new Scanner(System.in);
PrintWriter out = new PrintWriter(System.out);
int n=in.nextInt(),i;
BigInteger res=new BigInteger("1"),three=new BigInteger("3"),two=new BigInteger("2");
if(n==1);
else if(n==2)res=two;
else if(n==3)res=three;
else if(n%3==0)for(i=n/3;i>0;i--)res=res.multiply(three);
else if(n%3==1){
for(i=n/3;i>1;i--)res=res.multiply(three);
res=res.multiply(two).multiply(two);
}else{
for(i=n/3;i>0;i--)res=res.multiply(three);
res=res.multiply(two);
}
out.println(res);
out.flush();
}
}

