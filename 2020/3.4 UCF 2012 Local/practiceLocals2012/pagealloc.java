import java.io.*;
import java.util.*;

public class pagealloc
{
	public PrintWriter out;
	public Scanner in;

	public void main()
	{
		try
		{
			PrintWriter out=new PrintWriter(new FileWriter("pagealloc.out"),true);
			Scanner in=new Scanner(new File("pagealloc.in"));

			int n,R,free,r,c;
			int i,hand,K;
			int[] v;
			boolean[] old;
			
			int cc=1;

			n=in.nextInt();
			while(n>0)
			{
				out.println("Program "+cc);
				cc++;

				R=in.nextInt();
				v=new int[n];
				old=new boolean[n];
				Arrays.fill(v,-1);
				
				hand=0;
				K=0;

				while(R>0)
				{
					R--;
					r=in.nextInt();

					c=-1;
					for(i=0;i<n;i++)
					if(v[i]==r)
					{
						c=i; break;
					}

					if(c>=0)
					{
						out.println("Access page "+r+" in cell "+(c+1)+"."); 
						old[c]=false;
						continue;
					}
					
					K++;

					free=-1;
					for(i=0;i<n;i++)
					if(v[i]<0)
					{
						free=i;	break;
					}

					if(free>=0)
					{
						out.println("Page "+r+" loaded into cell "+(free+1)+".");
						v[free]=r;
						old[free]=false;
						continue;
					}

					while(true)
					{
						if(old[hand])
						{
							out.println("Page "+r+" loaded into cell "+(hand+1)+".");
							v[hand]=r;
							old[hand]=false;
							hand=(hand+1)%n;
							break;
						}
						else
						{
							old[hand]=true;
							hand=(hand+1)%n;
						}
					}
				}//end while R>0
				
				out.println("There are a total of "+K+" page faults.");
				out.println();
				n=in.nextInt();
			}//end whle n>0
		}
		catch (IOException ioe)
		{
			ioe.printStackTrace();
		}
	}

	public static void main(String[] args) { (new pagealloc()).main(); }
}
