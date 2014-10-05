import java.io.*;
import java.util.*;
import java.math.*;
public class P1640{
   public static void main(String[] args){      Scanner in = new Scanner(System.in);      
PrintWriter out = new PrintWriter(System.out);
int n,i,t,x,y,bv=-1;
BigDecimal l=new BigDecimal("0"),r=new BigDecimal("4000"),m,c=new BigDecimal("0.00000000000001"),d=new BigDecimal("2"),bbv;
n=in.nextInt();
for(i=0;i<n;i++){
x=in.nextInt();
y=in.nextInt();
t=x*x+y*y;
if(bv<t)bv=t;
}
bbv=new BigDecimal(bv+"");
while(r.add(l.negate()).compareTo(c)>0){
m=r.add(l).divide(d);
if(m.multiply(m).compareTo(bbv)<0)l=m;
else r=m;
}
out.println("0 0 "+l.doubleValue());
      out.flush();
   }
}
