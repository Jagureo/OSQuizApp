#include <iostream>
#include <string>
#include <chrono>
#include <windows.h>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

struct Question
{
    std::string question = "";
    std::string correctans = "";
    std::string ans2 = "";
    std::string ans3 = "";
    std::string ans4 = "";
};
Question AllQuestions[] =
{
    // QUIZ 1
    {"What does the file vmlinuz contain?",
        "The Linux kernel", "The Master Boot Record (MBR)", "The Initial RAM disk", "The BIOS"},
    {"Apple's Rosetta is an example of a / an",
        "Emulator", "Container platform", "Virtual Machine Manager", "Resource Manager"},
    {"A program in memory is called a",
        "Process", "System", "Executable", "Device"},
    {"An operating system is using DMA to transfer a 512-byte block from a device to memory.\n How many interrupts are generated by this DMA transfer?",
        "1", "2", "512", "None of the others"},
    {"Which of the following statements is false regarding system calls?",
        "None of the others", "A number associated with each system call", "Typically written in a high-level language (C/C++) or in Assembly", "Usually accessed by user program via system call interface"},
    {"Which of the following components run in kernel mode for a microkernel design",
        "Interprocess communication", "None of the others", "Device driver", "Filesystem driver"},
    {"Hotmail and Outlook are examples of",
        "Software-as-a-service", "Information-as-a-service", "Platform-as-a-service", "Desktop-as-a-service"},
    {"Which of the following are false regarding hard disk drives?",
        "Movement of the arm is not done using motor, instead of a heat coil", "The head is connected to an arm, which is moved by an actuator", "Read/Write performed by a head on a platter", "Stores data on a rotating platter(s) within the disk body"},
    {"The act of moving a process in and out of main memory is called",
        "Swapping", "Caching", "Virtualizing", "Scheduling"},

    // QUIZ 2
    {"Consider the following set of processes P1, P2, P3 and P4.\n Assume that the processes arrive at the same time.\n"
     "  ------------------------\n"
     "  | Process | Burst Time |\n"
     "  ------------------------\n"
     "  | P1      | 7          |\n"
     "  | P2      | 12         |\n"
     "  | P3      | 5          |\n"
     "  | P4      | 16         |\n"
     "  ------------------------\n"
     " Under a round-robin (RR) scheduler with a time quantum of 4, which process will complete its burst time first?",
        "P1", "P2", "P3", "P4"},
    {"Consider the following set of processes arriving in the order P1 (first to arrive), P2, P3 and P4 (last to arrive)\n"
     "  ------------------------\n"
     "  | Process | Burst Time |\n"
     "  ------------------------\n"
     "  | P1      | 7          |\n"
     "  | P2      | 12         |\n"
     "  | P3      | 5          |\n"
     "  | P4      | 16         |\n"
     "  ------------------------\n"
     " Under a first-come, first-served (FCFS) scheduler, which process will start last?",
        "P4", "P2", "P3", "P1"},
    {"The following are correct about programs and processes except",
        "A program is an active entity", "A process is a program in execution", "One program can be several processes", "A process is an active entity"},
    {"Which of the following is not a process state?",
        "All of the others are valid process states", "New", "Terminated", "Running"},
    {"If a parent process terminates without invoking wait(), its child process shall become ____ process",
        "Orphaned", "Zombie", "Idle", "Redundant"},
    {"Of the following, which is not a section of a process in memory?",
        "Code", "Heap", "Text", "Stack"},
    {"Consider the following set of processes P1, P2, P3 and P4.\n Assume that the processes arrive at the same time.\n"
     "  ------------------------\n"
     "  | Process | Burst Time |\n"
     "  ------------------------\n"
     "  | P1      | 7          |\n"
     "  | P2      | 12         |\n"
     "  | P3      | 5          |\n"
     "  | P4      | 16         |\n"
     "  ------------------------\n"
     " Under a shortest-job-first (SJF) scheduler, which process will start last?",
        "P4", "P2", "P3", "P1"},
    {"CPU scheduling decisions may take place when a process\n\n"
     "  A. Switches from running to waiting state\n"
     "  B. Switches from running to ready state\n"
     "  C. Switches from waiting to ready\n"
     "  D. Terminates\n\n"
     " Of the above, a scheduling scheme is considered non-preemptive if scheduling takes place",
        "Only under A and D", "Only under A, B, and D", "Only under A, B, and C", "Under all A, B, C, and D"},
    {"The two main type of queues pertaining to process scheduling are",
        "Ready and wait queues", "Run and wait queues", "Ready and I/O queues", "Run and I/O queues"},
    {"A round-robin (RR) scheduling algorithm with a large time quantum shall tend towards the performance of which scheduling algorithm?",
        "First-come, first-served (FCFS)", "Priority scheduling", "Shortest-remaining-time-first (SRTF)", "Shortest-job-first (SJF)"},

    // QUIZ 3
    {"Of the following, which is not true regarding user-level threads?",
        "Schedulable by the kernel", "Supported above the kernel", "Typically managed using a thread library", "May impact performance depending on how threads are mapped"},
    {"Consider the following set of processes P1, P2, P3, P4 and P5.\n Assume that the processes arrive at the same time.\n"
     "  ------------------------\n"
     "  | Process | Burst Time |\n"
     "  ------------------------\n"
     "  | P1      | 3          |\n"
     "  | P2      | 6          |\n"
     "  | P3      | 5          |\n"
     "  | P4      | 2          |\n"
     "  | P5      | 3          |\n"
     "  ------------------------\n"
     " Under a shortest-job-first (SJF) scheduler, what is the turnaround time for process P3?",
        "13", "17", "19", "14"},
    {"Consider the following set of processes arriving in the order P1 (first), P2, P3, and P4 (last)\n"
     "  ------------------------\n"
     "  | Process | Burst Time |\n"
     "  ------------------------\n"
     "  | P1      | 3          |\n"
     "  | P2      | 4          |\n"
     "  | P3      | 5          |\n"
     "  | P4      | 7          |\n"
     "  ------------------------\n"
     " Under a round-robin (RR) scheduler with a time quantum of 2, what is the average waiting time across all the processes?",
        "9", "4", "5", "7"},
    {"Each thread has its own copy of the following, except",
        "A heap", "A program counter", "A thread identifier", "A stack"},
    { "Consider the following set of processes arriving in the order P1 (first), P2, P3, and P4 (last)\n"
     "  ------------------------\n"
     "  | Process | Burst Time |\n"
     "  ------------------------\n"
     "  | P1      | 3          |\n"
     "  | P2      | 6          |\n"
     "  | P3      | 2          |\n"
     "  | P4      | 1          |\n"
     "  ------------------------\n"
     " Under a first-come, first-served (FCFS) scheduler, what is the total waiting time for process P3?",
        "9", "3", "6", "5" },
    {"Which of the following statements is not true regarding real-time CPU scheduling and real-time tasks?",
        "Aperiodic real-time tasks have a processing time t, deadline d, and a period p",
        "Periodic real-time tasks are real-time tasks that are repeated after a certain time interval",
        "Examples of real-time scheduling algorithms include rate monotonic scheduling & earliest deadline first scheduling",
        "Aperiodic real-time tasks are real-time tasks that occur at any random time"},
    
    // QUIZ 4
    {"Which of the following is not an approach for signal handling in multithreaded programs?",
        "Deliver the signal to an arbitrary thread within the process",
        "Deliver the signal to certain threads in the process",
        "Assign a specific thread to receive all signals for the process",
        "Deliver the signal to the thread to which the signal applies"},
    {"Which of the following is not true regarding thread cancellation?",
        "If a thread disables cancellation, cancellation requests will be discarded",
        "Deferred cancellation allows the target thread to periodically check if it should be cancelled",
        "In asynchronous cancellation, the target thread is terminated immediately",
        "Thread cancellation is the act of terminating a thread before it has finished"},
    {"What parameters does the POSIX function pthread_kill takes in?",
        "The thread identifier and the signal",
        "The process identifier and the signal",
        "The thread identificer, the process identificer, and the signal",
        "Only the signal"},
    {"What value would you initialize a semaphore to, for a binary semaphore?",
        "1", "0", "2", "-1"},
    {"Of the following, which is not considered a form of hardware support for synchronization?",
        "Semaphores", "Support for instruction to disable/enable interrupt", "Compare-and-swap instruction support", "Test-and-set instruction support"},
    {"Which of the following best describes the concept of starvation?",
        "A process is stuck because it cannot obtain the resource(s) it needs to continue",
        "Multiple processes reading and writing shared data; result depends on relative timing of processes",
        "Multiple processes continuously change their states in response to changes in other processes without doing any useful work",
        "Multiple proceeses wait for each other, and none can proceed any further"},
    {"Which of the following function pairs are often associated with semaphores?",
        "V() and P()", "sleep() and wait()", "signal() and join()", "wakeup() and sleep()"},

    // Quiz 5
    {"Which of the following has the slowest access time?",
        "Main memory", "Cache", "Translation Look-Aside Buffer", "Registers"},
    {"Which of the following has the slowest access time?",
        "Secondary memory", "Cache", "Translation Look-Aside Buffer", "Registers"},
    {"A process not being able to allocate memory even when there is available cumulative free memory, it could be caused by",
         "External Fragmentation", "Internal Fragmentation", "Dynamic Loading", "Translation Look-Aside Buffer"},
    {"How many times will the word \"Malaysia\" get printed when you run the program?\n"
     "----------------------------\n"
     " | int pid;                 |\n"
     " | pid = fork();            |\n"
     " | printf(\"Malaysia\\n\");    |\n"
     " ----------------------------",
        "2", "1", "3", "4"},

    // Quiz 6
    {"Which of the following is NOT a file access method?",
        "Contiguous Access", "Direct Access", "Sequential Access", "Indexed Sequential Access"},
    {"In the 10-bit Unix access permission bits, what does the least significant bit represent? (bit 0)",
        "Execute permission for Public", "Execute permission for Group", "Execute permission for Owner", "If the file is a directory or not"},
    { "In the 10-bit Unix access permission bits, what does the most significant bit represent? (bit 9)",
        "If the file is a directory or not", "Execute permission for Public", "Execute permission for Group", "Execute permission for Owner" },
    {"Which of the following is NOT a file allocation method?",
        "FCFS", "Indexed", "Contiguous", "Linked"},
    {"In POSIX library semaphores, which function is called to create a semaphore?",
        "sem_init", "sem_get", "sem_attach", "sem_start"},
    {"In POSIX library semaphores, which function is called to close a semaphore after use?",
        "sem_destroy", "sem_detach", "sem_end", "sem_stop"},
    {"In System V library, what function is used to link a shared memory in kernel to a local variable in the user space?",
        "shmat", "ftok", "shmget", "shmdt"},
    { "How many times will the word \"Indonesia\" get printed when you run the program?\n"
     " --------------------------------\n"
     " | int pid;                     |\n"
     " | pid = fork();                |\n"
     " | pid = fork();                |\n"
     " | if (pid == 0)                |\n"
     " |   printf(\"Indonesia\\n\");     |\n"
     " --------------------------------",
        "2", "1", "3", "4" },

    // Quiz 7
    {"Which inequality for A represent accurate CPU check for memory access in user mode?\n"
     " --------------------------------------------------------\n"
     " |                   [base]    [base + limit]           |\n"
     " |                      |             |                 |\n"
     " |                      V             V                 |\n"
     " | [CPU] --(address)-> [A] --(yes)-> [B] ----> [memory] |\n"
     " |                      |             |                 |\n"
     " |                    (no)          (no)                |\n"
     " |                      |             |                 |\n"
     " |                      V             V                 |\n"
     " | [trap to operating system, illegal addressing error] |\n"
     " --------------------------------------------------------",
        ">=", "<", "==", "<="},
    {"Which inequality for B represent accurate CPU check for memory access in user mode?\n"
     " --------------------------------------------------------\n"
     " |                   [base]    [base + limit]           |\n"
     " |                      |             |                 |\n"
     " |                      V             V                 |\n"
     " | [CPU] --(address)-> [A] --(yes)-> [B] ----> [memory] |\n"
     " |                      |             |                 |\n"
     " |                    (no)          (no)                |\n"
     " |                      |             |                 |\n"
     " |                      V             V                 |\n"
     " | [trap to operating system, illegal addressing error] |\n"
     " --------------------------------------------------------",
        "<", ">=", "==", ">" },
    {"Hardware that maps a logical address in the program to physical address during runtime is",
        "Memory Management Unit", "Compiler", "Device Driver", "Hardware Acceleration Unit"},
    {"Disk Scheduling, where the head moves from one end of the disk to another and then circles back to the beginning is",
        "C-SCAN", "SCAN", "FCFS", "Linear Scheduling"},
    { "Consider the following two programs and assume fork() never fails.\n"
     " -------------------------------------------------\n"
     " | Program - P1           | Program - P2         |\n"
     " -------------------------------------------------\n"
     " |                        | fork();              |\n"
     " | fork();                | printf(\"Cake\\n\");    |\n"
     " | fork();                | fork();              |\n"
     " | fork();                | printf(\"Cake\\n\");    |\n"
     " | printf(\"Cake\\n\");      | fork();              |\n"
     " |                        | printf(\"Cake\\n\");    |\n"
     " ----------------------------------------------------\n"
     " Which of the following statements are true?",
        "P2 prints Cake 14 times", "P1 prints Cake 6 times", "P1 and P2 create different number of processes", "P1 prints Cake 3 times" },

    // Quiz 8
    {"Which of the following are maskable interrupt numbers",
        "88", "1", "11", "21"},
    {"Boot code can be found on",
        "MBR", "MSR", "NVR", "NVM"},
    {"Busy waiting for an I/O device is called",
        "Polling", "Wait and Signal", "Semaphores", "Interrupt driven process"},
    {"What is DMA?",
        "Direct Memory Access", "Direct Memory Available", "Disk Management Arbitrary", "Disk Memory Access"},
    {"Dining Philosophers problem is",
        "a synchronisation problem", "a storage problem", "a philosophical problem", "a memory management problem"},
    {"RAID-1 does",
        "mirrored disks", "interleaved parity", "multi-dimensional striping", "non-redundant stripping"}
};

std::chrono::time_point<std::chrono::system_clock> start;
std::chrono::duration<double> elapsed_seconds;
std::string input;
int QuestionChoices[] = { 1, 2, 3, 4 };
int AllQuestions_size = sizeof(AllQuestions) / sizeof(AllQuestions[0]);
int hours = 0, minutes = 0, seconds = 0, useranswer = 0, currentqn = 0, correctans = 0, score = 0;
int maxtime_min = AllQuestions_size % 60, maxtime_hour = AllQuestions_size / 60;
bool endQuiz = false, questionAnswered = false, shuffleQuestion = true;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// SetConsoleTextAttribute(hConsole, k); // 15 is white, 12 is red, 10 is green

void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

void DisplayClock()
{
    cout << " | TIMER : " << hours << " hrs | " << minutes << " min | " << seconds << " sec |" << endl;
}

void DisplayScore()
{
    cout << " | QUESTION #" << currentqn+1 << " / " << AllQuestions_size << " | SCORE : " << score << " |" << endl;
}

void StartTimer()
{
    start = std::chrono::system_clock::now();
}

void RecordTimer()
{
    elapsed_seconds = std::chrono::system_clock::now() - start;
    seconds = static_cast<int>(elapsed_seconds.count());
    minutes = seconds / 60; seconds %= 60;
    hours = minutes / 60; minutes %= 60;
}

void PrintQuestion()
{
    cout << endl;
    if (shuffleQuestion) { std::random_shuffle(QuestionChoices, QuestionChoices + 4); shuffleQuestion = false; }
    cout << " " << AllQuestions[currentqn].question << endl;
    for (int i = 0; i < 4; ++i)
    {
        switch (QuestionChoices[i])
        {
        case 1:
            cout << "  " << i+1 << ". " << AllQuestions[currentqn].correctans << endl;
            break;
        case 2:
            cout << "  " << i+1 << ". " << AllQuestions[currentqn].ans2 << endl;
            break;
        case 3:
            cout << "  " << i+1 << ". " << AllQuestions[currentqn].ans3 << endl;
            break;
        case 4:
            cout << "  " << i+1 << ". " << AllQuestions[currentqn].ans4 << endl;
            break;
        }
    }
    cout << endl;
}

void Intro()
{
    while (strcmp(input.c_str(), "ready"))
    {
        Clear();
        cout << " Hello! Welcome to Jagureo's Operating Systems Quiz Flash Cards Simulator Thingy V1!" << endl;
        cout << " This version compromises of (almost) ALL past quiz questions!" << endl;
        cout << " You have been assigned a minute to each question..." << endl;
        cout << " --------------------------------------------------------------------------------" << endl;
        cout << " To answer a question, simply type 1/2/3/4 and hit enter!" << endl;
        cout << " Type \"Ready\" and hit enter to start the timer and quiz!" << endl << endl << " ";
        cin >> input;
        std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return std::tolower(c); });
    }
    input = "";
    srand(static_cast<unsigned int>(time(NULL)));
}

void Quiz()
{
    StartTimer();
    std::random_shuffle(AllQuestions, AllQuestions + AllQuestions_size);
    while (!endQuiz || strcmp(input.c_str(), "exit"))
    {
        RecordTimer();
        Clear();
        DisplayClock();
        DisplayScore();
        PrintQuestion();
        if (!questionAnswered)
        {
            if (cin.fail() || useranswer > 4)
            {
                SetConsoleTextAttribute(hConsole, 12);
                std::cout << " | Bad input! Type only 1/2/3/4!" << endl;
                std::cin.clear();
                std::cin.ignore();
                useranswer = 0;
                SetConsoleTextAttribute(hConsole, 15);
            }
            cout << " Your answer : ";
            cin >> useranswer;
            if (!cin.fail() && useranswer < 5 && useranswer > 0)
            {
                if (QuestionChoices[useranswer - 1] == 1)
                { SetConsoleTextAttribute(hConsole, 10); cout << " Correct! "; }
                else
                { SetConsoleTextAttribute(hConsole, 12); cout << " Wrong! "; }
                cout << endl << " The answer is \"" << AllQuestions[currentqn].correctans << "\"" << endl;
                SetConsoleTextAttribute(hConsole, 15);
                cout << endl << " Type \"Ready\" to go to the next question!" << endl << " ";
                questionAnswered = true;
            }
        }
        else
        {
            cout << " Your answer : " << useranswer << endl;
            if (QuestionChoices[useranswer - 1] == 1)
            { SetConsoleTextAttribute(hConsole, 10); cout << " Correct! "; }
            else
            { SetConsoleTextAttribute(hConsole, 12); cout << " Wrong! "; }
            cout << endl << " The answer is \"" << AllQuestions[currentqn].correctans << "\"" << endl;
            SetConsoleTextAttribute(hConsole, 15);
            cout << endl << " Type \"Ready\" to go to the next question!" << endl << " ";
            cin >> input;
            std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return std::tolower(c); });
            if (!strcmp(input.c_str(), "ready"))
            {
                input = "";
                questionAnswered = false;
                shuffleQuestion = true;
                ++currentqn;
                if (QuestionChoices[useranswer - 1] == 1) { ++score; }
                if (currentqn >= AllQuestions_size) { endQuiz = true; break; }
            }
        }
    }
}

void Outro()
{
    while (strcmp(input.c_str(), "exit"))
    {
        Clear();
        if (hours > maxtime_hour || (hours == maxtime_hour && minutes > maxtime_min))
        {  SetConsoleTextAttribute(hConsole, 12); }
        else { SetConsoleTextAttribute(hConsole, 10); }
        DisplayClock();
        SetConsoleTextAttribute(hConsole, 15);
        cout << endl;
        cout << " That's all the questions I have right now! Thank you for practicing!" << endl;
        cout << " Your score is ";
        if (score < static_cast<int>(AllQuestions_size / 2))
        { SetConsoleTextAttribute(hConsole, 12); }
        else { SetConsoleTextAttribute(hConsole, 10); }
        cout << score << " / " << AllQuestions_size << endl << endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout << " Type \"Exit\" to leave this quiz!" << endl << " ";
        cin >> input;
        std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return std::tolower(c); });
    }
    input = "";
}

int main()
{
    Intro();
    Quiz();
    Outro();
    return 1;
}