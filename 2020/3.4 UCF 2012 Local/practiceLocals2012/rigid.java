/* ************************************************
 * Problem: Metallic Equipment Rigid
 **************************************************/
import java.util.*;
import java.io.*;

public class rigid {
		
		public static void main(String[] args) throws Exception
		{
			Scanner fin = new Scanner(new File("rigid.in"));
			int n = fin.nextInt();
			
			for(int set=1; set <= n; set++)
			{

				int c = fin.nextInt();
				int p = fin.nextInt();
				
				int camx[] = new int[c];
				int camy[] = new int[c];
				int camr[] = new int[c];
				
				int px[] = new int[p];
				int py[] = new int[p];
				
				for(int i=0;i<c;i++)
				{
					camx[i] = fin.nextInt();
					camy[i] = fin.nextInt();
					camr[i] = fin.nextInt();
				}
				for(int i=0;i<p;i++)
				{
					px[i] = fin.nextInt();
					py[i] = fin.nextInt();
				}
				
				boolean triggered = false;
				System.out.print("Compound #"+set+": ");
				
				// Loop through each camera
				for(int i=0;i < c;i++)
				{
					// Loop through each path point
					for(int j=0;j < p-1;j++)
					{
						if(pointSegDist(camx[i],camy[i], px[j],py[j],px[j+1],py[j+1]) <= camr[i] + 0.01)
						{
							if(!triggered)
							{
								triggered = true;
								System.out.print("Reptile triggered these cameras:");
							}
							System.out.print(" "+(i+1));
							break;
						}
					}
				}
				if(triggered)
					System.out.println();
				else
					System.out.println("Reptile was undetected");
				System.out.println();
	
			}
		}
		
		public static double pointSegDist(double cx, double cy, double px1, double py1, double px2, double py2)
		{
			// Translate
			cx -= px1;
			px2 -= px1;
			
			cy -= py1;
			py2 -= py1;
			
			// (px1, py1) is now the origin
			// Compute unit vector of p2
			double len = Math.sqrt(px2*px2 + py2*py2);
			double ux = px2/len;
			double uy = py2/len;
			
			// Rotate so that p2 is along the x-axis (len is p2's x coordinate)
			// (a + bi)*(c + di) = (ac - bd) +(ad + bc)i
			// cx  cy    ux  uy     cx ux
			uy = -uy;
			double nx = cx * ux - cy * uy;
			double ny = cx * uy + cy * ux;
			

			// if the camera point is directly above the segment
			if(nx>=0 && nx <= len)
				return Math.abs(ny);
			// if the camera point is off the right end
			if(nx > len)
				nx -= len;
			return Math.sqrt(nx*nx + ny*ny);
		}

}
