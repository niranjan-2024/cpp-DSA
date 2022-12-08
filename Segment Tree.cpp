/*Segment Tree:

Use case : Select high between the given two queries

brute force -> for N no. of elements and Q queries ----> complexity -> O(QN)

segment trees stores the result of a range at a given index in an array

root node contains all indexes  -> eg [1,9]

there child nodes indexes are 2*index + 1           ,                 2*index + 1
mid range = [0+9] / 2
so next ranges are [0-4]   and   [5-9]

start filling from bottom and choose root of two as max from both of them

we can store these value in an array 

maximum space allotes in array for segment tree of N indexes is                ------>  4N

there are three conditions for an range search in segment tree
1.Completely lie
2.Does Not lie
3.Overlap

not lie return INT_MIN while some ranges return their max value

Time need to build  -> O(N)
Time need for Query  -> O(log(N))

do not need to traverse full tree check only upper half

for small ranges it checks only in one direction */



#include <bits/stdc++.h>
using namespace std;

int a[100005] , seg[4*100005];

void build(int ind,int low,int high){
   
   if(low == high){
      seg[index] = a[low];
      return;
   }
   
   int mid = (low+high)/2;
   
   build(2*index + 1,low,mid);
   build(2*index + 2,mid,high);
   
   seg[ind] = max(seg[2*ind+1] , seg[2*ind+2]);
}

int query(int ind, int low, int high, int l, int r){
   //completely lie
   if(low>=l && high<=h){
      return seg[ind];
   }
   
   //does not lie
   if(high<l || low>r){
      return INT_MIN;
   }
   
   //overlaps
   int left = query(2*ind+1,low,mid,l,r);
   int right = query(2*ind+2,mid,high,l,r);
   
   return max(left,right);
}

int main()
{
   //Take array as input
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
      cin >> a[i];
   }
   
   build(0,0,n-1);
   
   //Take input queries
   int q;
   cin>>q;
   while(q--){
      int l,r;
      cin>>l>>r;
      cout<< query(0,0,n-1,l,r);
   }
   
    return 0;
}
