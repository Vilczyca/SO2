#include <iostream>
#include <thread>
#include <string>
class Philosopher;
class Fork;

using namespace std;

static bool finished = false;
Fork* forks;
Philosopher* philosophers;



class Fork {
private:
    bool id;
public:
    bool isBusy;
    // Constructors and Destructors
    Fork() : isBusy(false) {};
};



class Philosopher {
private:
    bool isHungry;
    thread myThread;

    // TODO: assign values
    int leftForkID,
        rightForkID,
        eatingTime,
        thinkingTime;

    void doWork() {
        if (isHungry) {
            // try to get forks (one at time)
            eat();
        } else {
            think();
        };
    };

    bool canGetFork(int forkID) {
        return false;
    };

    void getFork() {
        // TODO: fork disappearing, maybe animation?
    }

    void eat() {
        // TODO: eating animation
        cout << "Eating...";
        this_thread::sleep_for(3s);
    };

    void think() {
        // TODO: thinking animation
    };


public:
    // Constructors and Destructors
    Philosopher() : isHungry(false) {};
    ~Philosopher() {
        stop();
    }

    // Starts the thread
    void start() {
        myThread = std::thread(&Philosopher::doWork, this);
    }

    // Stops the thread by stopFlag
    void stop() {
        isHungry = false;
        myThread.join();
    }
};


// Raczkowanie
//void doWork() {
//    while (!finished) {
//        cout << "Working..." << endl;
//        this_thread::sleep_for(1s);
//    }
//}

int main(int argc, char* argv[]) {
    int n = 5;  // classic number

    if (argc > 1)
        n = stoi(argv[1]);

    philosophers = new Philosopher[n];
    forks = new Fork[n];

    // Raczkowanie
    /*cout << "Arguments: " << n << endl;

    thread worker(doWork);
    cin.get();
    worker.join();
    finished = true;

    system("pause");*/
}


// https://www.youtube.com/watch?v=FYUi-u7UWgw