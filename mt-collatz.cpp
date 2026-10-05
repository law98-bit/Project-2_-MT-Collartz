#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <ctime>

const int MAX_STOP = 1000;

static long histogram[MAX_STOP + 1];
static long COUNTER = 1; 
static long N = 0;   

static bool useLock = true;

static mutex counterMutex;
static mutex histMutex;

static int stoppingTime(long n){
    unsigned long long x = n;             // 64-bit: 3n+1 can overflow 32 bits
    int steps = 0;
    while (x != 1) {
        x = (x % 2 == 0) ? x / 2 : 3 * x + 1;
        steps++;
    }
    return steps;
}

static void worker(){
    while (true){
        long n;
        {
        unique_lock<mutex> lk(counterMutex, defer_lock);
        if(useLock) lk.lock();
        n=COUNTER++;

        }

    
        if(n > N) break;
        int st= stoppingTime(n);

        {
        unique_lock<mutex> lk(histMutex, defer_lock);
        if(useLock) lk.lock();
        histogram[st]++;
        }
    }

}

static void elapsed(const timespec &start, const timespec &end, long &sec, long &nsec){
    sec = end.tv_sec-start.tv_sec;
    nsec = end.tv_nsec-start.tv_nsec;

    if(nsec <  0){
        sec -= 1;
        nsec+= 1000000000L;
    }
}

int main(int argc, char *argv[]){
//didnt have time to implement pls finish 
}