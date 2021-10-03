import java.util.Scanner;

public class MatrixBoundaryElements
{
  public static void main(String[] args)
  {
   int row=0,column=0,i=0,j=0,k=0,t=0,count=0;
   int array[][],b[];

   Scanner inp =new Scanner(System.in);
   System.out.println("What is the number of Rows:");
   row=inp.nextInt();
   System.out.println("What is the number of Columns");
   column=inp.nextInt();

   array=new int[row][column];
   System.out.println("Enter matrix elements:");
   for(i=0;i< row;i++)
     {
       for(j=0;j< column;j++)
        {
          arr[i][j]=sc.nextInt();


// COUNTING OF BOUNDARY ELEMENTS             

           if(i==0||i==(row-1)||j==0||j==(column-1))
            {
             count++;
             }
           }
     }
     b=new int[count];
     System.out.println("Old matrix:");
     for(i=0;i< row;i++)
     {
      for(j=0;j< column;j++)
       {
         System.out.print(array[i][j]+" ");
         }
            System.out.println();
        }
        for(i=0;i< row;i++)
        {
          for(j=0;j< column;j++)
          {
           if(i==0 ||j==0||i==(row-1)||j==(column-1))
           {
              b[k]=array[i][j];
              k++;
           }
         }
       }
//SORTING OF BOUNDARY ELEMENTS

     for(i=0;i< b.length;i++)
     {
      for(j=0;j< b.length;j++)
       {
          if(b[i] < b[j])
           {
            t=b[i];
             b[i]=b[j];
              b[j]=t;
             }
         }
      }

//ARRANGING OF SORTED ELEMTNTS
   k=0;
   for(i=0;i< row;i++)
   {
    for(j=0;j< column;j++)
     {
      if(i==0 ||j==0||i==(row-1)||j==(column-1))
       {
        array[i][j]=b[k];
        k++;
        }
    }
 }

System.out.println("New Matrix:");
for(i=0;i< row;i++)
 {
  for(j=0;j< column;j++)
    {
     System.out.print(array[i][j]+" ");
     }
      System.out.println();
   }
  }
 }
