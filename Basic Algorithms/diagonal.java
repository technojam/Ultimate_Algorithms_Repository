import java.util.*;
class diagonal
{public static void sum(int a[][],int n)
{int sr=0,sl=0,x=n-1;
    for(int i=0;i<n;i++)
    {sr=sr+a[i][i];sl=sl+a[x][i];x--;}
if(n%2==0)
{System.out.println(sr+sl);}
else
{int m=(n+1/2);
System.out.println(sr+sl-a[m][m]);} }   
public static void main(String[]args)
{int a[][];int n;
    Scanner sc=new Scanner(System.in);
    n=sc.nextInt();
    a=new int[n][n];
    for(int i=0;i<n;i++)
    {for(int j=0;j<n;j++)
    {a[i][j]=sc.nextInt();}}
    sum(a,n);


}}


