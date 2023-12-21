//time complexity - O(2^n)

vector<string> o;

void generate(int i,string &s,int n)
{
    if(i==n){
        o.push_back(s);
        return;
    }

    s.push_back('0');
    generate(i + 1, s, n);
    s.pop_back();
    if (i == 0 || s[i - 1] == '0') {
        s.push_back('1');
        generate(i + 1, s, n);
        s.pop_back();
    }

}

vector<string> generateString(int N) {
    // Write your code here.
    string s="";
    generate(0,s,N);
    return o;
}
