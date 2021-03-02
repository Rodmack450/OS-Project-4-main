//
//  main.cpp
//  OS Project
//
//  Created by Rodolphe Nemr on 11/29/20.
//

#include <iostream>
using namespace std;

int main() {
   
    int pro;
    int res;
    
    
    cout<<"How many processes: ";
    cin>>pro;
    
    cout<<"How many resources: ";
    cin>>res;
    
    //initializing variables.
    int alloc[pro][res];
    int max[pro][res];
    int need[pro][res];
    int avail[res];
    bool banker[pro];
    int done[pro];
    int count = 0;
    int flag = 0;
    
    //index never made it banker[i] far
    for(int l=0;l<pro;l++){
        banker[l] = false;
    }

    cout<<"Enter available vector: ";
    for(int i=0;i<res;i++){
        cin>>avail[i];
    }
    cout<<endl;
   
    for(int i=0;i<pro;i++){
        cout<<"Enter allocation value to complete the vector for process "<<i+1<<" : "<<endl;

        for(int j=0;j<res;j++){
            
            cin>>alloc[i][j];
            
        }
    }

    cout<<endl;
    
    for(int i=0;i<pro;i++){
        cout<<"Enter maximum value to complete the vector for process "<< i+1 << " :"<<endl;

        for(int j=0;j<res;j++){
     
            cin>>max[i][j];
            
        }
    }
    cout<<endl;
    //calculating need by max - alloc
    for(int i=0;i<pro;i++){
        for(int j=0;j<res;j++){
            
            need[i][j] = max[i][j]-alloc[i][j];
            
        }
    }
    
    cout<<endl;
    for(int i=0;i<pro;i++){
        for(int j=0;j<res;j++){
           cout<<"Process "<<i+1<<"   Allocation:" <<alloc[i][j]<<"   Max:" <<max[i][j]<<"   Need:"<<need[i][j];
            cout<<"   Available vector: "<< avail[j]<<endl;

        }
    }
    
    while(count<pro){
       //Looping through
        for (int i = 0; i < pro; i++){
       
            flag = 0;
       
            for (int j = 0; j < res; j++){

                if (need[i][j] <= avail[j] && banker[i] == false)
       
                    flag++;
            }
            
//when our flag reaches all the resources we can add them to our done array, we have this process done.
       if (flag == res){
           done[count] = i;
           count++;
       
        
           for (int j = 0; j < res; j++){
           avail[j] += alloc[i][j];
        }
           
           //occupied
           banker[i] = true;
           cout<<"Process "<<i +1 <<" done"<<endl;
           
           //Printing new available resources
      for (int j = 0; j < res; j++){
          cout<<avail[j] << " ";
           
        }
        
       }
         
        }
             
    }
      
    cout<<"\nSequence is: "<<endl;
    for(int i=0 ;i<pro;i++){
        cout<<"Process" << done[i] << "->";
    }
    
    return 0;
}
