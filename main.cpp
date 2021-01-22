#include <iostream>
#include <fstream>
#include "ring_buffer/ring_buffer.hpp"
#include "ring_buffer/ring_buffer.cpp"
#include "queue/queue.hpp"
#include "queue/queue.cpp"
#include "stack/stack.hpp"
#include "stack/stack.cpp"

using namespace std;


void write(string filename,Stack<int> stack);

int main(int argc, char **argv)
{
    try
    {
        ifstream read_stream("./input.txt");
        int l_dot;
        int r_dot;
        if (!read_stream.is_open())
        {
            throw "error in open file";
        }
        int size;
        read_stream.seekg(0, ios::end);
        if (read_stream.tellg() == 0)
        {
            throw "empty file";
        }
        read_stream.seekg(0, ios::beg);

        read_stream >> size;
        read_stream >> l_dot;
        read_stream >> r_dot;

        int buff_elem;
        RingBuffer<int> r(size);
        for (int i = 0; i <= size; i++)
        {
            read_stream >> buff_elem;
            r.push(buff_elem);
        }
        read_stream.close();
        Queue<int> queue;
        int buff;

        for (auto it = r.begin(); it != r.end(); ++it)
        {
            queue.insert(*it);
        }

        Stack<int> inside;
        Stack<int> outside;

        for (auto it = queue.begin(); it != queue.end(); ++it)
        {
            buff = *it;
            if (l_dot<= buff && buff <= r_dot ){
                inside.push(buff);
            }
            else{
                outside.push(buff);
            }
        }

        write("output_inside.txt",inside);
        write("output_outside.txt",outside);
        
    }
    catch (string error)
    {
        cout << error;
    }
    catch (exception exception)
    {
        cout << exception.what();
    }
    return 0;
}


void write(string filename,Stack<int> stack){
    ofstream os;
    os.open(filename);
    os << stack.size() << endl;
    while(!stack.empty()){
        os<<stack.pop()<<" ";
    }
    os.close();
}
