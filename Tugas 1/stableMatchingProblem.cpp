#include <iostream> 
#include <string.h> 
#include <stdio.h> 

using namespace std; 
  
#define N 5
  
string names[2*N] = {"Victor", "Wyatt", "Xavier", "Yancey", "Zeus", "Amy", "Bertha", "Clare", "Diane", "Erika"};

bool wPreferCurrentPartner(int preference[2*N][N], int w, int m, int m1) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        if (preference[w][i] == m1) 
            return true; 

        if (preference[w][i] == m) 
            return false; 
    }
} 
  

void matchingProblem(int preference[2*N][N]) 
{ 
    int wPartner[N];   
    bool mFree[N]; 

    for (int i = 0; i < N; i++){
        wPartner[i] = -1;
        mFree[i] = true;
    }
  

    int freeMan = N; 
  
    
    while (freeMan > 0) 
    { 
        
        int m; 
        for (m = 0; m < N; m++) 
            if (mFree[m] == true) 
                break; 
  
        
        for (int i = 0; i < N && mFree[m] == true; i++) 
        { 
            int w = preference[m][i]; 
  
            if (wPartner[w-N] == -1) 
            { 
                wPartner[w-N] = m; 
                mFree[m] = false; 
                freeMan--; 
            } 
  
            else 
            { 
                
                int m1 = wPartner[w-N]; 
  
                
                if (wPreferCurrentPartner(preference, w, m, m1) == false) 
                { 
                    wPartner[w-N] = m; 
                    mFree[m] = false; 
                    mFree[m1] = true; 
                } 
            } 
        } 
    } 
  
  
    cout << "Man\tWoman\n" << "-----------------" << endl; 
    for (int i = 0; i < N; i++) 
       cout << "" << names[wPartner[i]] << "\t" << names[i+N] << endl; 
} 
  

int main() 
{ 
    int preference[2*N][N] = { {6, 5, 8, 9, 7}, 
        {8, 6, 5, 7, 9}, 
        {6, 9, 7, 8, 5}, 
        {5, 8, 7, 6, 9}, 
        {6, 8, 5, 9, 7}, 
        {4, 0, 1, 3, 2}, 
        {2, 1, 3, 0, 4}, 
        {1, 2, 3, 4, 0}, 
        {0, 4, 3, 2, 1},
        {3, 1, 4, 2, 0},
    }; 

    matchingProblem(preference); 
  
    return 0; 
} 
