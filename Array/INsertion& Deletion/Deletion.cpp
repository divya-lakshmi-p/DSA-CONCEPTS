Deletion of an array element 


C++ code 


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
  int index = 3;
  for(int i = index; i<n-1 ; i++)
  {
    arr[i] = arr[i+1];
  }

  
  n--;



  for(int i=0;i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
}



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
        int index = sc.nextInt();

        for(int i=index; i<n-1; i++)
        {
            arr[i]= arr[i+1];
        }
        n--;

        for(int i=0; i<n;i++)
        {
            System.out.print(arr[i]+" ");
        }

    }
}

