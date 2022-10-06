#include<iostream>
#include<vector>
using namespace std;

// MIN HEAP

class priorityQueue{
    vector<int> pq;
    int ni;

    public:
    

    priorityQueue(){
        ni=0;

    }

    int size(){
        return pq.size();
    }

    bool isEmpty(){
        return pq.size()==0;
    }

    int getmin(){
        if(!isEmpty())
            return pq[0];
        else 
            return 0;
    }

    private:

    void swap(int a, int b){
        int temp = pq[a];
        pq[a]=pq[b];
        pq[b]=temp;
    }

    public:

    void insertmin(int data){
        if(isEmpty()){
            pq.push_back(data);
            ni++;
            return;
        }
        pq.push_back(data);
        int cr=ni;
        while(pq[(cr-1)/2]>pq[cr] && cr>0){
            swap(cr, (cr-1)/2);
            // int temp = pq[cr];
            // pq[cr]= pq[(cr-1)/2];
            // pq[(cr-1)/2] = temp;
            cr=(cr-1)/2;  
        }
        ni++;
    }


    void removemin(){
        if(isEmpty()) return;
        swap(ni-1, 0);
        // int temp= pq[ni-1];
        // pq[ni-1]= pq[0];
        // pq[0]= temp;
        ni--;
        pq.pop_back();
        int cr=0;
        while((2*cr + 2)<ni){
            if(pq[cr]> min(pq[2*cr +1], pq[2*cr + 2])){
                if(pq[2*cr+1] == min(pq[2*cr +1], pq[2*cr + 2]) ){
                    swap(cr, 2*cr+1);
                    cr=2*cr +1;
                }else{ swap(cr, 2*cr+2); cr=2*cr +2;}
            }else break;
        }

        if(2*cr+1<ni){
            if(pq[cr]> pq[(2*cr + 1)]){
                swap(cr, 2*cr +1);
            }
        }


    } 


};
