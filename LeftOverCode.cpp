/* cs351_assignment3_Omar_Ramirez
return;
ofstream fileWrite;
//fileWrite.open();

//ofstream * p = new ofstream;
cout << "BEfore RUN" ;
//ofstream *p2 = static_cast<ofstream*>(OutFile);
//p2->open("synch.txt");
for (int i = 0; i < 26; i++) {
    *p2 << twentySixLetters[i] << " ";
}
if (p2->is_open()) {
    cout << "I ran" << endl;
    for (int i = 0; i < 26; i++) {
        *p2 << twentySixLetters[i] << " ";
    }
}
//ofstream file = new ofstream;
//& file.open("synch.txt");
 //&OutFile.open("synch.txt"); // For Writing data to file.
for (int i = 0; i < 26; i++) {
    cout << "Print ";
}

    char* name = static_cast<char*>(OutFileName);
    int i = 0;
    while (name[i] != 'Ì Ì' || name[i] != 'ƒt') {
        cout << name[i];
        i++;
    }

*/
/* 
void acutalMainBackUp() {
    //Create Output File Stream 
    ofstream* OutFile = new ofstream("synch.txt");

    //char *filename = {}
    //Create HANDLERS AND THREAD IDS
    HANDLE ThreadHandlerA;
    HANDLE ThreadHandlerB;
    DWORD ThreadIDA;
    DWORD ThreadIDB;

    //Create Threads
    ThreadHandlerA = CreateThread(NULL, 0, ThreadPrint, &OutFile, 0, &ThreadIDA);
    ThreadHandlerB = CreateThread(NULL, 0, ThreadPrint, &OutFile, 0, &ThreadIDB);
    return;
}

void writeInputFile() {

    ofstream OutFile("synch.txt"); // For Writing data to file.
    for (int i = 0; i < 26; i++) {
        OutFile << twentySixLetters[i] << " ";
    }

    //Create Thread A

    OutFile.close();

    return;
}

void readInputFile() {
    cout << "Hello World!\n";
    char inputChar[100];
    string inputString = "Test";
    ifstream InputFile; // Read data from file.

    InputFile.open("synch.txt");
    if (InputFile.is_open()) {
        int i = 0;
        while (InputFile.good()) {
            if (InputFile.eof()) {
                cout << "End of File 1";
                return;
            }
            InputFile >> inputChar[i];
            cout << inputChar[i];
            if (InputFile.eof()) {
                cout << "End of File 2";
                cout << inputChar[i + 4];
                cout << NULL;
            }
            i++;
        }
    }

    int x;
    cin >> x;
    return;
}


void gCountFunction() {
    char str[20];

    std::cout << "Please, enter a word: ";
    std::cin.getline(str, 20);
    std::cout << std::cin.gcount() << " characters read: " << str << '\n';

    return;
}
*/