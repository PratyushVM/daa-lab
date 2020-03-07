//4_4 tower of hanoi

#include<bits/stdc++.h>
using namespace std;

void tower_of_hanoi(int n, char from, char aux, char to);

int main()
{
    int n;
    cout<<"Enter the number of discs in rod A";
    cin>>n;

    cout<<"The moves that need to be performed are :"<<endl;
    tower_of_hanoi(n,'A','B','C');

    cout<<"The number of moves totally performed are "<<pow(2,n)-1;

    return 0;

}

void tower_of_hanoi(int n, char from, char aux, char to)
{
    if(n==1)
    {
        cout<<"Move disc 1 from "<<from<<" to "<<to<<endl;
        return;
    }
    else
    {
        tower_of_hanoi(n-1,from,to,aux);
        cout<<"Move disc "<<n<<" from "<<from<<" to "<<to<<endl;
        tower_of_hanoi(n-1,aux,from,to);
    }
}