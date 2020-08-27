#include <iostream>
//#include <chrono>
using namespace std;




//Method resulting in O(m+n)
//Has an approximate worst case runtime of 0.001007 seconds (1007000 nanoseconds)
template <size_t n, size_t m>
int tallest1(int (&arr)[n][m])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j]==0)
                return j;
        }
    }
    return -1;
}

//Method resulting in O(mlog(n))
//Has an approximate worst case runtime of 0.000992 seconds (992000 nanoseconds)
template <size_t n, size_t m>
int tallest2(int row, int (&arr)[n][m])
{
    for(int i = 0; i < m; i++)
        if(arr[row][i]==0)
            return i;
    return tallest2(row+1, arr);
}


int main()
{
    //auto start = chrono::high_resolution_clock::now(); 
    int buildings[5][6] = {{1,1,1,0,1,1},{1,1,0,0,0,1},
    {0,1,0,0,0,1,},{0,1,0,0,0,1},{0,0,0,0,0,1}};
    cout<<"The tallest building using the first method is building at loc #"<<tallest1(buildings)<<endl;
    cout<<"The tallest building using the second method is building at loc #"<<tallest2(0,buildings)<<endl;
    //auto duration = chrono::high_resolution_clock::now(); 
    //auto runtime = chrono::duration_cast<std::chrono::nanoseconds>( duration - start ).count();
    //cout<<runtime;
    return 0;
}