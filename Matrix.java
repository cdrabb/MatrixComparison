import java.util.*;

public class Matrix 
{
    private double [][] matrix;
    private int n;
    private int m;
    
    public Matrix()
    {
    	matrix = new double [5][5];
    }
    public Matrix(int n, int m)
    {
    	this.n = n;
    	this.m = m;
    	matrix = new double[n][m];
    }
    public void autoPopulate()
    {
    	Random rand = new Random();
    	for(int i = 0; i < n; i++)
    		for(int j = 0; j < m; j++)
    			matrix[i][j] =  1 + rand.nextDouble() * 100;
    }
    public void populate()
    {
    	Scanner kb = new Scanner(System.in);
    	for(int i = 0; i < n; i++)
    		for(int j = 0; j < m; j++)
    		{
    			System.out.print( "What number will be in row " 
    		        + i + " column " + j + "?: ");
    			double temp = kb.nextDouble();
    			matrix[i][j] = temp;
    		}
    }
    public String toString()
    {
    	String str = "";
    	for (int i = 0; i < n; i++)
    	{
    		str += "|";
    		for (int j = 0; j < m; j++)
    		{
    			str +=" " + matrix[i][j] + " ";
    		}
    		str += "|\n";
    	}
    	return str;
    }
    public Matrix add(Matrix b)
    {
    	Matrix c = new Matrix(n,m);
    	
    	for (int i = 0; i < n; i++)
    	{
    		for (int j = 0; j < m; j++)
    		{
    			c.matrix[i][j] = this.matrix[i][j] + b.matrix[i][j];
    		}
    	}
    	return c;
    }
    public Matrix sub(Matrix b)
    {
    	Matrix c = new Matrix(n,m);
    	
    	for (int i = 0; i < n; i++)
    	{
    		for (int j = 0; j < m; j++)
    		{
    			c.matrix[i][j] = this.matrix[i][j] - b.matrix[i][j];
    		}
    	}
    	return c;
    }
    public Matrix mult(Matrix b)
    {
    	Matrix c = new Matrix(n,b.m);
    	
    	for (int i = 0; i < n; i++)
    	{
    		for (int j = 0; j < b.m; j++)
    		{
    			c.matrix[i][j] = 0; //Initializes the appropriate position
    			for (int k = 0; k < m; k++)
    			{
    				c.matrix[i][j] += this.matrix[i][k] * b.matrix[k][j]; //The sum of multiple products
    			}
    		}
    	}
    	return c;
    }
    public boolean basicCompatible(Matrix b)
    {
    	if(this.n == b.n && this.m == b.m)
    		return true;
    	return false;
    }
    public boolean multCompatible(Matrix b)
    {
    	if(this.m == b.n)
    		return true;
    	return false;
    }
    public int getN()
    {
    	return n;
    }
    public int getM()
    {
    	return m;
    }
    public static void main(String [] args)
    {
    	Scanner kb = new Scanner(System.in);
    	int n;
    	int m;
    	double start;
    	double duration;
    	
    	System.out.print("Enter the n dimension of the first matrix: ");
    	n = kb.nextInt();
    	System.out.print("Enter the m dimension of the first matrix: ");
    	m = kb.nextInt();
    	Matrix a = new Matrix(n,m);
    	
    	System.out.print("Enter the n dimension of the second matrix: ");
    	n = kb.nextInt();
    	System.out.print("Enter the m dimension of the second matrix: ");
    	m = kb.nextInt();
    	Matrix b = new Matrix(n,m);
    	
    	   	
    	
    	Matrix c = new Matrix();
    	Matrix d = new Matrix();
    	Matrix e = new Matrix();
    	
    	if(a.getN()*a.getM() < 25 && b.getN()*b.getM() < 25)
    	{
    		System.out.println("For Matrix A:");
    		a.populate();
    		
    		System.out.println("For Matrix B:");
    		b.populate();
    	}
    	else
    	{
    		a.autoPopulate();
    		b.autoPopulate();
    	}
    	
    	start = System.currentTimeMillis();
    	
    	if(a.basicCompatible(b))
    	{
    		c = a.add(b);
    		d = a.sub(b);
    	}
    	else
    		System.out.println("The matrices are not compatible for addition or subtraction.");
    	
    	if(a.multCompatible(b))
    		e = a.mult(b);
    	else
    		System.out.println("The matrices are not compatible for multiplication.");
    	
    	duration = ((System.currentTimeMillis() - start) / 1000.0);
    	
    	
    	System.out.println("M1\n" + a);
    	System.out.println("M2\n" + b);
    	System.out.println("M3\n" + c);
    	System.out.println("M4\n" + d);
    	System.out.println("M5\n" + e);
    	
    	
    	System.out.println("Evaluated in " + duration + " seconds.");
    	kb.close();
    }
}
