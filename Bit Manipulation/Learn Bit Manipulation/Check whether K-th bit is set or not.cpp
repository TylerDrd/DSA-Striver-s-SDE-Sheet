bool isKthBitSet(int n, int k)
{
    // Write your code here.
    int mask = 1<<(k-1);
    return n&mask;
}
