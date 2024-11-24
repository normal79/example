#include<bits/stdc++.h>
using namespace std;

#define MAX_PAGES 100

int fifo(int pages[],int n, int frames){
    int total_faults = 0;
    int block[frames];
    int found;
    int index = 0;

    for(int i=0; i<frames; i++){
        block[i] = -1;
    }

    int i;
    for(i=0; i<n; i++){
        found = 0;

        for(int j=0; j<frames; j++){
            if(pages[i] == block[j]){
                found = 1;
                break;
            }
        }

        if(!found){
            block[index] = pages[i];
            index = (index + 1)%frames;
            total_faults++;
        }
    }

    return total_faults;
}

int lru(int pages[],int n, int frames){
    int total_faults = 0;
    int block[frames];
    int lru_time[frames] = {0};
    int found;
    int lru_index;
    int i;

    for(int i=0; i<frames; i++){
        block[i] = -1;
    }

    for(i=0; i<n; i++){
        found = 0;

        for(int j=0; j<frames; j++){
            if(block[j] == pages[i]){
                found = 1;
                lru_time[j] = i;
                break;
            }
        }

        if(!found){
            lru_index = 0;
            for(int j=1; j<frames; j++){
                if(lru_time[j] < lru_time[lru_index]){
                    lru_index = j;
                }
            }
            block[lru_index] = pages[i];
            lru_time[lru_index] = i;
            total_faults++;
        }
    }
    return total_faults;
}

int optimal(int pages[], int n, int frames){
    int total_faults = 0;
    int found;
    int block[frames];
    int index_to_replace;
    int farthest;
    int i,j,k;


    for(int i=0; i<frames; i++){
        block[i] = -1;
    }

    for(i=0; i<n; i++){
        found = 0;
        for(int j=0; j<frames; j++){
            if(block[j] == pages[i]){
                found = 1;
                break;
            }
        }

        if(!found){
            farthest = -1;
            index_to_replace = -1;

            for(j=0;j<frames; j++){ //j=>block frames
                for(k=i+1; k<n; k++){  //i=>pages n
                    if(block[j] == pages[k]){
                        if(k > farthest){
                            farthest = k;
                            index_to_replace = j;
                        }
                        break;
                    }
                }
                if(k == n){  //page never used in future
                    index_to_replace = j;
                    break;
                }
            }

            block[index_to_replace] = pages[i];
            total_faults++;
        }
    }
    return total_faults;
}

int main(){
    int pages[MAX_PAGES];
    int n,frames;

    cout<<"Enter number of pages: ";
    cin>>n;
    cout<<"Enter number of frames: ";
    cin>>frames;
    cout<<"Enter all the pages (Space separated): ";
    for(int i=0; i<n; i++){
        cin>>pages[i];
    }

    int fifo_faults = fifo(pages,n,frames);
    cout<<"Total Fifo faults: "<<fifo_faults<<endl;

    int lru_faults = lru(pages,n,frames);
    cout<<"Total LRU faults: "<<lru_faults<<endl;

    int optimal_faults = optimal(pages,n,frames);
    cout<<"Total LRU faults: "<<optimal_faults<<endl;

    return 0;
}
