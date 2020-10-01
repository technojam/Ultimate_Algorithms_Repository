using namespace std; 
int main() 
{ 
    int inum,n;

    if (inum <= 1)
    {
        cout<<'Not a prime number';
    } 
    for (int i=2; i<n; i++){
        if(inum % i == 0)
        break;
    }
    if (inum==i)
    {
        cout<<'Prime Number';
    }
    else{
        cout<<'Not a prime number';
    }
    return 0; 
}