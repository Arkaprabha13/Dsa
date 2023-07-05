class solution
{
public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int n, int from, int to, int aux) {
        // Your code here
         if (n == 0) return 0;
        if (n == 1) 
    { 
        cout<<"move disk 1 from rod " <<  from << " to rod " << to << endl; 
        return 1; 
    } 
    long long c=1;//counter
    c+=toh(n-1, from, aux, to); 
    cout<<"move disk " << n << " from rod " <<  from << " to rod " << to << endl; 
    c+=toh(n-1, aux, to, from); 
    return c;
    }
};
