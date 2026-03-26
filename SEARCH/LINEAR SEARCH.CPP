Checking each element one by one until you find a target 

If structured is unsorted means fine. If it is sorted, then we can go with binary search 


ALgorithm:
1. Start from index 0;
2. compare current element with the target
3. If match - return whatever is asked 
4. Else -move to next element
5. If end reached - element not found




/.example code 

int linear search (vector<int> &v , int target)
{
   for(int i=0; i<v.size(); i++)
  {
    if(v[i]==target)
      return i;
  }
  return -1
}


TC:

Best(found at start) -  o(1)
worst and average = o(n)
