#include <iostream>
#include <fstream>

int main() {
    
    // File interactions are represented by fstream objects
    
    // fstream objects always access files "sequentially" as bytes
    // fstreams don't understand file formats
    
    // you can open, read, write and close
    // Open -> connects the fstream to the file
    // Read -> Data from the file is copied into the program's memory
    // Write -> Data is copied from the program's memory to the file
    // Close -> Disconnects the fstream from the file
    
    // For each of these operations, the fstream object will call a function in the operating system API
    // The program will stop and wait while the operation is performed 
    // When the operating system has completed the task, the API will return the file
    // The program then resumes the execution
    
    // When a C++ program terminates, the runtime will make close all open files
    // However, it's best practice to close the open files manually immediately after we finished to use them
    
    // As data passes between the program and the file, it may be temporarily stored in a memory buffer
    // This makes large data transfers more efficient but less timely
    // The reason is that interaction with physical devices is very time consuming 
    
    // Codelite generates the executable under debug or release folder, so the path of the files have to be checked keeping this in mind
    
    // ifstream in_file {"file_path/file_name"};
    // if (!in_file) ... -> in_file will return false if the file hasn't been opened
    
    // in early c++ versions, fstream's constructor could only take C-style strings for the file name. 
    // C++11 onwards, it can take std::string object
    
    // in_file can be used just like std::cin
    // while (in_file >> variable) -> reads one word at a time and remove all the whitespace from the file
    // the files sometimes have internal structure, so the code might be hard to get right
    
    // getline() function takes a whole line and returns it in a std::string object
    // std::string temp;
    // while (getline(in_file, temp)) {...} -> temp is the variable to hold the content one line at a time
    // temp will contain every content of the line except the newline character
    // getline() will return false at the end of the file
    
    // ofstream out_file{"file_path/file_name"};
    // insert stuff with operator<<
    
    
    // fstream destructor
    // when fstream destructor is called, the file is automatically closed
    // this will cause any unsaved data to be written to the file
    // if an fstream object goes out of scope after we're finished with it, we do not explicitly need to call close(), but it still is a good practice
    
    
    // buffering
    // during write operations, data is temporarily held in a memory buffer
    // when the buffer is full, the stream will remove the data from the buffer and send it to the operating system (known as flushing)
    // for ostream, flushing depends on the terminal configuration
    //      usually this is at the end of every line
    //      cout is always flushed before the program reads from cin
    // ofstream is only flushed when the buffer is full
    // there's no direct flushing for ifstream
    
    // std::flush allows us to control when the stream's buffer is flushed -> all the data is sent immediately to its destination
    // cout << i << flush -> i will appear immediately on the screen
    // this significantly affects performance (slows it down since hardware commands are called more), so use only when the data really needs to be up to date
    // ex: say you store logs in a file, and your program is terminated. if the log content is not flushed, it may get stuck on the buffer, and
    // the program cannot put the content in the log file due to being terminated
    
    // terminate() to force terminate the program
    
    
    // Unbuffered I/O Streams
    
    // there are some apps where stream buffering is not suitable.
    // ex: network apps
    //      data must be transmitted in packets of a specified size
    //      data may need to be transmitted at specific times
    
    // C++ supports lower level operations on streams that bypass the buffer and don't format the data
    // Mainly used when the programmer needs more control over how the data is transmitted
    // ex: networking apps
    // ex: communicating directly with hardware
    
    // get() and put() methods work on single chars, elevating the need for buffers
    
    // read() and write() methods to read/write many characters
    // these don't use a buffer that's managed by the stream, so we provide our own buffer
    // for read, the buffer must be large enough to store all the data we expect to receive
    // for write, our buffer will contain all the info to be transmitted 
    // a buffer is just a variable to hold the info
    
    // gcount() method will return the number of characters that were received
    // auto nread = in_file.gcount() -> return type is maybe special?
    
    
    // file modes
    
    // by default, files are opened in "text mode"
    // by default, output files are opened in "truncate mode", deleting all data in the file previously
    
    // to open an ofstream in append mode, we pass "fstream::app" or "ios::app" as the second argument to open()
    
    // other modes include "trunc", "in", "out", "ate"
    // we can combine different modes by putting | between them, with some restrictions on some combinations
    
    
    // i/o state methods
    // good() returns true if the input was read successfully 
    // fail() returns true if there was a recoverable error, eg. reading wrong kind of data 
    // bad() returns true if there was an unrecoverable error, eg. media corruption
    // clear() restores the stream's state to valid
    // eof() returns true after the end of file has been reached
    // works for cout and cin too
    
    // best practice example 
    /* #include <limits> (-> numeric_limits<streamsize>::max())
     * int x;
     * bool success{false};
     * while (!success) {
     *     if (cin.good()) {
     *         ...
     *         success = true;
     *     }
     *     else {
     *         cout << "Please try again and enter a number";
     *         cin.clear(); -> if this is not here, the invalid input will be stuck in cin, to be inserted into x again, creating an infinite loop
     *         cin.ignore(numeric_limits<streamsize>::max(),'\n');
     *         cin >> x;
     *     }
     * }
     * */
    
    // input streams don't support flush, but they have ignore().
    // ignore() takes two arguments. first one is the maximum number of characters to remove, and second one is a delimiter
    // ex: cin.ignore(20, "\n"); -> if you get a newline, remove everything before. else, remove 20 characters 
    // numeric_limits<streamsize>::max() returns the maximum number of chars the cin buffer can hold
    
    
    
    // Stream manipulators
    // flush and endl are main examples
    // we can push manipulators onto stream objects to affect their behaviour 
    // most are in <iostream>
    // manipulators that take in arguments are in <iomanip>
    
    // boolalpha converts 0 and 1 outputs of bool variables into true and false
    // noboolalpha for 0 and 1
    
    // setw() affects only the next item on the stream. this is the only non-sticky manipulator
    // insert "left" for left-justified outputs. affects the rest of the stream.
    // setfill() sets the filling character to be its argument
    
    // check out "fixed" manipulator for floats
    // "defaultfloat" to pull everything to its default for the rest of the stream
    // setprecision(n) to see n digits after decimal point


    // stream types
    // the basic C++ stream is represented by std::ios
    
    // iostream -> ostream (cout), istream (cin)
    
    // fstream -> ofstream (file stream for writing), ifstream (file stream for reading)
    
    // stringstream (<sstream>) -> ostringstream (string stream for writing), istringstream (string stream for reading)
    // just a wrapper around std::string, which makes it look like a stream object
    // ostreamstring has an empty std::string object, can store data by the same operations in other streams, str() will return the std::string object
    
    // istringstream objects use a copy of an existing string that's passed into the constructor
    // read the input into an std::string, validate it, bind it to an istringstream object, and read it from that object
    
    // ostreamstring is useful when interfacing to systems that expect strings in particular formats (GUI, Operating Systems, Third Party libraries)
    // istringstreams can be used with getline() to process strings easier compared to operator>>
    
    
    return 0;
}
