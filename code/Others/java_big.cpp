/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigDecimal;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
    public static void main (String[] args) throws java.lang.Exception
    {
/*
a=2*(x2-x1);
b=2*(y2-y1);
c=x2*x2+y2*y2-x1*x1-y1*y1;
d=2*(x3-x2);
e=2*(y3-y2);
f=x3*x3+y3*y3-x2*x2-y2*y2;
x=(b*f-e*c)/(b*d-e*a);
y=(d*c-a*f)/(b*d-e*a);
r=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
*/
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        BigDecimal two = BigDecimal.valueOf(2);
        for (int i = 0; i < T; i ++)
        {
            BigDecimal x1 = cin.nextBigDecimal();
            BigDecimal y1 = cin.nextBigDecimal();
            BigDecimal x2 = cin.nextBigDecimal();
            BigDecimal y2 = cin.nextBigDecimal();
            BigDecimal x3 = cin.nextBigDecimal();
            BigDecimal y3 = cin.nextBigDecimal();
            BigDecimal a = x2.subtract(x1).multiply(two);
            BigDecimal b = y2.subtract(y1).multiply(two);
            BigDecimal c = x2.pow(2).add(y2.pow(2)).subtract(x1.pow(2)).subtract(y1.pow(2));
            BigDecimal d = x3.subtract(x2).multiply(two);
            BigDecimal e = y3.subtract(y2).multiply(two);
            BigDecimal f = x3.pow(2).add(y3.pow(2)).subtract(x2.pow(2)).subtract(y2.pow(2));
            BigDecimal x = b.multiply(f).subtract(e.multiply(c)).divide(b.multiply(d).subtract(e.multiply(a)), 500, BigDecimal.ROUND_HALF_UP);
            BigDecimal y = d.multiply(c).subtract(a.multiply(f)).divide(b.multiply(d).subtract(e.multiply(a)), 500, BigDecimal.ROUND_HALF_UP);
            BigDecimal r2 = x.subtract(x1).pow(2).add(y.subtract(y1).pow(2));
            BigDecimal x0 = cin.nextBigDecimal();
            BigDecimal y0 = cin.nextBigDecimal();
            BigDecimal dis2 = x0.subtract(x).pow(2).add(y0.subtract(y).pow(2));
            if (dis2.compareTo(r2) <= 0)
                System.out.println("Rejected");
            else
                System.out.println("Accepted");
        }
        
    }
}
