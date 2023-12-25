
int countSetBits(int N) {
  // Write your code here
  int x = N,ans=0,d=2;
  while(x)
  {
      ans+=((N+1)/d)*(d/2) + max(0,(N+1)%d - d/2);
      d=d<<1;
      x=x>>1;
  }
  return ans;
}
