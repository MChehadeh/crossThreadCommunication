#include <iostream>
#include <boost/thread.hpp>
#include "TimedBlock.hpp"
#include "thread_initial_unit.hpp"
#include "ReferenceMessage.hpp"
using namespace std;
using boost::thread;
using boost::mutex;

const int THREAD_COUNT = 10;

void worker(thread_initial_unit* timed_block) {
    timed_block->tickTimer();
    cout<<"hasLoopTimeElapsed:"<< timed_block->hasLoopTimeElapsed()<<endl;
    cout<<"getLoopRemainingMicroSec:"<< timed_block->getLoopRemainingMicroSec()<<endl;
    usleep(timed_block->getLoopRemainingMicroSec());

    cout<<"Check 11"<<endl;
    while(true){
        while(!timed_block->hasLoopTimeElapsed()){
        }
        //cout<<"hasLoopTimeElapsed:"<< timed_block->hasLoopTimeElapsed()<<endl;
        //cout<<"getLoopRemainingMicroSec:"<< timed_block->getLoopRemainingMicroSec()<<endl;
        timed_block->tickTimer();
        usleep(timed_block->getLoopRemainingMicroSec());
    }

}

int main(int argc, char** argv)
{
    thread *threads[THREAD_COUNT];
    cout<<"Hello"<<endl;
    ReferenceMessage* res1=new ReferenceMessage();
    res1->setReferenceMessage(12.);
    ReferenceMessage* res=new ReferenceMessage(*res1);
    cout<<res->getData()<<endl;
    // Creation
    for(int i = 0; i < THREAD_COUNT-1; i=i+2) {
        cout<<"Thread: "<<i<<endl;
        thread_initial_unit* initial_thread=new thread_initial_unit();
        ((TimedBlock*)initial_thread)->setLoopFrequency(block_frequency::hz100);
        cout<<"Check 0"<<endl;
        thread_terminal_unit* terminal_thr=new thread_terminal_unit();
        cout<<"Check 1"<<endl;
        ((msg_emitter*)initial_thread)->add_callback_msg_receiver(terminal_thr);
        cout<<"Check 2"<<endl;
        threads[i] = new thread(worker, (thread_initial_unit*)initial_thread);
        cout<<"Check 3"<<endl;
        TimedBlock* connecting_thread=new thread_initial_unit(terminal_thr);
        ((TimedBlock*)connecting_thread)->setLoopFrequency(block_frequency::hz100);
        cout<<"Check 4"<<endl;
        threads[i+1] = new thread(worker, (thread_initial_unit*)connecting_thread);
        cout<<"Check 5"<<endl;
    }

    sleep(55);
    cout<<"Check 6"<<endl;
    // Cleanup
    for(int i = 0; i < THREAD_COUNT; i++) {
        threads[i]->join();
        delete threads[i];
    }

    return 0;
}