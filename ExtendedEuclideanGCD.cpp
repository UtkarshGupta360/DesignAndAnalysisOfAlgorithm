vector<int> ExtendedGCD(int a, int b)
{
    if(b == 0) return {1, 0};
    
    vector<int> result = ExtendedGCD(b, a%b);
    int x = result[0];
    int y = result[1];
    
    int SmallX = y;
    int SmallY = x - (a/b)*y;
    return {SmallX, SmallY};
    
}
