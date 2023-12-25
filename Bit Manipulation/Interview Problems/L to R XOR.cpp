int Xorr(int n)
{
    if(n%4 == 1) return 1;
    if(n%4 == 2) return n+1;
    if(n%4 == 3) return 0;
    if(n%4 == 0) return n;
}

int findXOR(int L, int R){
    // Write your code here.
    int a = Xorr(R);
    int b = Xorr(L-1);
    return a^b;
}
