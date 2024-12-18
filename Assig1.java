import java.util.*;

class ShellSort 
{
 void Sort(int arr[], int n) {
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
    int temp = arr[i];
    int j;
    for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
      arr[j] = arr[j - interval];
    }
    arr[j] = temp;
    }
  }
  }
 
 public static void main(String args[])
 {

     int i;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of array: ");
        int n=sc.nextInt();

        int arr[]=new int[50];
        System.out.println("Enter array element: ");
        for(i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        System.out.println("Array is: ");
        for(i=0;i<n;i++)
        {
            System.out.println(+arr[i]);
        }

        ShellSort obj = new ShellSort();
        obj.sort(arr);

        int n1 = arr.length;
         System.out.println("Array after sorting");
         for (i = 0; i < n1; i++)
         System.out.print(arr[i] + " ");
        System.out.println();

 }
}