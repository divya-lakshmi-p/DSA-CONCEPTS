Insertion of the given element in the given index in array



C++


  #include<bits/stdc++.h>
using namespace std;

int main()
{

  int n;
  cin >> n;

  int arr[n];
  for(int i=0; i<n; i++)
  {
    cin>>arr[i];
  }

  int m = n;
  int index = 3;
  int value = 100;

  for(int i = n; i>index ; i--)
  {
    arr[i] = arr[i-1];
  }

  arr[index]=value;
  m++;



  for(int i=0;i<m; i++)
  {
    cout<<arr[i]<<" ";
  }
}





















Java 


import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int []arr = new int[n+1];

        for(int i=0;  i<n; i++)
        {
            arr[i] = sc.nextInt();
        }


        int m = n;
        int index = sc.nextInt();
        int value = sc.nextInt();

        for(int i=n; i>index ; i--)
        {
            arr[i]= arr[i-1];
        }

        arr[index] = value;
        m++;

        for(int i=0; i<m;i++)
        {
            System.out.print(arr[i]+" ");
        }

    }
}
