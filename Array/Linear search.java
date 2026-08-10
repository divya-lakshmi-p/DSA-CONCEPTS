Linear search


#include<bits/stdc++.h>
using namespace std;

int linearsearch(int arr[] , int n , int target)
{
    for(int i=0; i<n; i++)
    {
      if(arr[i]== target)
      {
        return i;
      }
    }

    return -1;
}

int main()
{

  int n;
  cin >> n;

  int arr[n];
  for(int i=0; i<n; i++)
  {
    cin>>arr[i];
  }
  
   int target ;
   cin >> target;
  cout<<linearsearch(arr , n,  target);
  
}
Java 


import java.util.Scanner;

class Main
{

     static int linearsearch(int[]arr , int n , int target)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
    public static void main(String[] args)
    {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int []arr = new int[n+1];

        for(int i=0;  i<n; i++)
        {
            arr[i] = sc.nextInt();
        }
        int target = sc.nextInt();

    
            System.out.print(linearsearch(arr , n , target));
        
    }
}
